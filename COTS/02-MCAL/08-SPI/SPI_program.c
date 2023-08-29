/**
 * @file SPI_program.c
 * @brief Implementation file for the SPI driver.
 * 
 * This file contains the implementation of the functions for the SPI driver.
 * 
 * @author Mahmoud Abdelraouf Mahmoud
 * @date 15 Jul 2023
 * @version V01
 */

/*****************************< LIB *****************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*****************************< MCAL *****************************/
/**< GPIO */
#include "GPIO_interface.h"
/**< MCAL_SPI */
#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"

/**
 * @addtogroup SPI_Functions
 * @{
 */

SPI_t SPI_SelectSpiPeripheral(SPI_Peripheral_t spi)
{
    switch (spi)
    {
      case SPI1:
        return ((SPI_t)SPI1_BASE_ADDRESS);
      case SPI2:
        return ((SPI_t)SPI2_BASE_ADDRESS);
      case SPI3:
        return ((SPI_t)SPI3_BASE_ADDRESS);
      default:
        return NULL;
    }
}

void SPI_voidInit(SPI_t Copy_psfSelectedSpi, const SPI_config_t *Copy_psSPIConfig)
{
  /********************************< Configure the SPI peripheral ********************************/
  if(Copy_psfSelectedSpi == NULL && Copy_psSPIConfig == NULL)
  {
    SPI_DefaultInitiation();
  }
  else
  {
    /* Set the data frame format */
    if (Copy_psSPIConfig->DataFrame == SPI_DATA_FRAME_8BIT)
    {
      CLR_BIT(Copy_psfSelectedSpi->CR1, SPI_CR1_DFF);
    }
    else
    {
	    SET_BIT(Copy_psfSelectedSpi->CR1, SPI_CR1_DFF);
    }

    /* Set the frame format */
    if(Copy_psSPIConfig->FrameFormat == SPI_LSB_FIRST)
    {
      SET_BIT(Copy_psfSelectedSpi->CR1,SPI_CR1_LSBFIRST);
    }
    else
    {
      CLR_BIT(Copy_psfSelectedSpi->CR1,SPI_CR1_LSBFIRST);
    }

    /* Set the clock polarity */
    if (Copy_psSPIConfig->ClockPolarity == SPI_CLOCK_POLARITY_HIGH)
    {
      SET_BIT(Copy_psfSelectedSpi->CR1, SPI_CR1_CPOL);
    }
    else
    {
	    CLR_BIT(Copy_psfSelectedSpi->CR1, SPI_CR1_CPOL);
    }

    /* Set the clock phase */
    if (Copy_psSPIConfig->ClockPhase == SPI_WRITE_READ)
    {
      SET_BIT(Copy_psfSelectedSpi->CR1, SPI_CR1_CPHA);
    }
    else
    {
      CLR_BIT(Copy_psfSelectedSpi->CR1, SPI_CR1_CPHA);
    }

    /* Set the clock speed */
    Copy_psfSelectedSpi->CR1 &= ~SPI_CR1_BR_MSK;
    Copy_psfSelectedSpi->CR1 |= Copy_psSPIConfig->BaudRateDIV;

    #if SPI_MODE == SPI_MASTER_MODE
      /* Config the SPI to mater mode */
      SET_BIT(Copy_psfSelectedSpi->CR1, SPI_CR1_SSM);   /* Set the SSM to manage the slave bit by software */
      SET_BIT(Copy_psfSelectedSpi->CR1, SPI_CR1_SSI);   /* Set the SSI to work in the Master mode */

      /* Set the master mode */
      SET_BIT(Copy_psfSelectedSpi->CR1, SPI_CR1_MSTR);

      #elif SPI_MODE == SPI_SLAVE_MODE
        /* Config the SPI to slave mode */
        CLR_BIT(Copy_psfSelectedSpi->CR1, SPI_CR1_SSM);   /* Clear the SSM to manage the slave bit by hardware */

        /* Set the slave mode */
        CLR_BIT(Copy_psfSelectedSpi->CR1, SPI_CR1_MSTR);  /* Clear the MSTR to select the spi to work in slave mode */
      #else
        #error "ERROR!! Wrong choice"
    #endif

    /* Enable the SPI peripheral */
    SET_BIT(Copy_psfSelectedSpi->CR1, SPI_CR1_SPE);

  }
}

void SPI_voidTransfer(SPI_t Copy_SPI, u8 *Copy_u8pTxData, u8 *Copy_u8pRxData, u16 Copy_u16size)
{

  /* Iterator to loop on the data */
  u16 Local_u16Iterator;

  #if SPI_MODE == SPI_MASTER_MODE
    /* Clear the slave select pin -> Enable the slave select pin */
    MGPIO_voidSetPinValue(MGPIOA,GPIO_PIN4,MGPIO_LOW);
  #endif

  /* Send and receive the data */
  for (Local_u16Iterator = 0; Local_u16Iterator < Copy_u16size; Local_u16Iterator++)
  {
    /* Send the data */
    SPI_voidSendByte(Copy_SPI,Copy_u8pTxData[Local_u16Iterator]);

    /* Receive the data */
    Copy_u8pRxData[Local_u16Iterator] = SPI_u8ReceiveByte(Copy_SPI);
  }

  /* Wait for the transmission to complete */
  SPI_voidWaitForTransmissionComplete(Copy_SPI);

  #if SPI_MODE == SPI_MASTER_MODE
    /* Set the slave select pin -> Disable the slave select pin */
    MGPIO_voidSetPinValue(MGPIOA,GPIO_PIN4,MGPIO_LOW);
  #endif

}

/**
 * @} SPI_Functions
 */

/**
 * @addtogroup SPI_Private_Functions
 * @{
 */

static void SPI_voidSendByte(SPI_RegDef_t *Copy_psSPI, u8 Copy_u8Data)
{
  /* Wait for the transmit buffer to be empty */
  while (!GET_BIT(Copy_psSPI->SR,SPI_SR_TXE));

  /* Send the data */
  *((u8*)&(Copy_psSPI->DR)) = Copy_u8Data;
}

static u8 SPI_u8ReceiveByte(SPI_RegDef_t *Copy_psSPI)
{
  /* Wait for the receive buffer to be full */
  while (!GET_BIT(Copy_psSPI->SR,SPI_SR_RXNE));

  /* Return the received data */
  return *((u8*)&(Copy_psSPI->DR));
}

static void SPI_voidWaitForTransmissionComplete(SPI_RegDef_t *Copy_psSPI)
{
  /* Wait for the transmission to complete */
  while (GET_BIT(Copy_psSPI->SR,SPI_SR_BSY));
}

static void SPI_DefaultInitiation(void)
{ 
  /**< Set the data frame format to be 8-bit data frame */
  CLR_BIT(SPI_Default->CR1, SPI_CR1_DFF);

  /**< Set the frame format to be the LSB first */
  SET_BIT(SPI_Default->CR1,SPI_CR1_LSBFIRST);

  /**< Set the clock polarity to be clock polarity high at idle state */
  SET_BIT(SPI_Default->CR1, SPI_CR1_CPOL);

  /* Set the clock phase to be write the read */
  SET_BIT(SPI_Default->CR1, SPI_CR1_CPHA);

  /* Set the clock speed to be divided by two */
  SPI_Default->CR1 &= ~SPI_CR1_BR_MSK;
  SPI_Default->CR1 |= SPI_BAUD_RATE_DIV2;

  #if SPI_MODE == SPI_MASTER_MODE
    /* Config the SPI to mater mode */
    SET_BIT(SPI_Default->CR1, SPI_CR1_SSM);   /* Set the SSM to manage the slave bit by software */
    SET_BIT(SPI_Default->CR1, SPI_CR1_SSI);   /* Set the SSI to work in the Master mode */

    /* Set the master mode */
    SET_BIT(SPI_Default->CR1, SPI_CR1_MSTR);

    #elif SPI_MODE == SPI_SLAVE_MODE
      /* Config the SPI to slave mode */
      CLR_BIT(SPI_Default->CR1, SPI_CR1_SSM);   /* Clear the SSM to manage the slave bit by hardware */

      /* Set the slave mode */
      CLR_BIT(SPI_Default->CR1, SPI_CR1_MSTR);  /* Clear the MSTR to select the spi to work in slave mode */
    #else
      #error "ERROR!! Wrong choice"  
  #endif

  /* Enable the SPI peripheral */
  SET_BIT(SPI_Default->CR1, SPI_CR1_SPE);
}

/**
 * @}
 */

