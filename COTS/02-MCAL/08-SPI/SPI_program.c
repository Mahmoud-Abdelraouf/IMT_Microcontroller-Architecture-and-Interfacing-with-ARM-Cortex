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
/**< SPI */
#include "SPI_config.h"
#include "SPI_private.h"
#include "SPI_interface.h"

 

/**
 * @addtogroup SPI_Functions
 * @{
 */

void SPI_voidInit(SPI_RegDef_t *Copy_psSPI,SPI_config_t *Copy_psSPIConfig)
{
  /* Configure the SPI peripheral */
  /* Set the data frame format */
  if (Copy_psSPIConfig->DataFrame == SPI_DATA_FRAME_8BIT)
  {
    SET_BIT(Copy_psSPI->CR1, SPI_CR1_DFF);
  }
  else
  {
    CLEAR_BIT(Copy_psSPI->CR1, SPI_CR1_DFF);
  }

  /* Set the clock polarity */
  if (Copy_psSPIConfig->ClockPolarity == SPI_CLOCK_POLARITY_HIGH)
  {
    SET_BIT(Copy_psSPI->CR1, SPI_CR1_CPOL);
  }
  else
  {
    CLEAR_BIT(Copy_psSPI->CR1, SPI_CR1_CPOL);
  }

  /* Set the clock phase */
  if (Copy_psSPIConfig->ClockPhase == SPI_CLOCK_PHASE_SECOND_EDGE)
  {
    SET_BIT(Copy_psSPI->CR1, SPI_CR1_CPHA);
  }
  else
  {
    CLEAR_BIT(Copy_psSPI->CR1, SPI_CR1_CPHA);
  }

  /* Set the clock speed */
  Copy_psSPI->CR1 &= ~SPI_CR1_BR_MSK;
  Copy_psSPI->CR1 |= Copy_psSPIConfig->BaudRateDIV;

  /* Set the master mode */
  SET_BIT(Copy_psSPI->CR1, SPI_CR1_MSTR);

  /* Enable the SPI peripheral */
  SET_BIT(Copy_psSPI->CR1, SPI_CR1_SPE);
}

void SPI_voidTransfer(SPI_RegDef_t *Copy_psSPI, u8 *Copy_u8pTxData, u8 *Copy_u8pRxData, u16 Copy_u16size)
{
  u16 Local_u16Iterator;

  /* Set the slave select pin */
  SPI_voidSetSlaveSelectPin(LOW);

  /* Send and receive the data */
  for (Local_u16Iterator = 0; Local_u16Iterator < Copy_u16size; Local_u16Iterator++)
  {
    /* Send the data */
    SPI_voidSendByte(Copy_psSPI,Copy_u8pTxData[Local_u16Iterator]);

    /* Receive the data */
    Copy_u8pRxData[Local_u16Iterator] = SPI_u8ReceiveByte(Copy_psSPI);
  }

  /* Wait for the transmission to complete */
  SPI_voidWaitForTransmissionComplete(Copy_psSPI);

  /* Clear the slave select pin */
  SPI_voidSetSlaveSelectPin(HIGH);
}

/**
 * @}
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

  /**
   *  Write a single byte of data (Copy_u8Data) to the SPI Data Register (DR)
   *  of the given SPI peripheral (Copy_psSPI).
   * 
   *  Explanation:
   *    1. Access the DR (Data Register) field of the SPI peripheral structure (Copy_psSPI)
   *       using the arrow operator (->). The DR is where data is written for SPI communication.
   *   
   *    2. Cast the address of the DR field to a pointer of type u8* (8-bit unsigned integer pointer).
   *
   *    3. Use the address-of operator (&) to get the address of the DR field.
   *
   *    4. The combination of casting and dereferencing (*(u8*)...) treats the DR field's
   *       address as an 8-bit variable, allowing us to write a single byte of data directly
   *       into the SPI Data Register.
   *   
   *    5. Assign the value of Copy_u8Data to the location pointed to by the expression.
   *       This effectively writes the value of Copy_u8Data into the SPI Data Register.
   */
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

static void SPI_voidSetSlaveSelectPin(SPI_Status_t Copy_Status)
{
  
  /* Set or clear the slave select pin */
  if (Copy_Status == LOW)
  {
    MGPIO_voidSetPinValue(MGPIOA,GPIO_PIN4,MGPIO_HIGH);
  }
  else
  {
    MGPIO_voidSetPinValue(MGPIOA,GPIO_PIN4,MGPIO_LOW);
  }
}

/**
 * @}
 */

