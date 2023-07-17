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

/**< LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/**< MCAL */
#include "SPI_config.h"
#include "SPI_private.h"
#include "SPI_interface.h"



/**
 * @addtogroup SPI_Functions
 * @{
 */

void SPI_voidInit(SPI_DataFrame_t Copy_DataFrame, SPI_ClockPolarity_t Copy_ClockPolarity,
                  SPI_ClockPhase_t Copy_ClockPhase, u32 Copy_u32ClockSpeed)
{
  /* Configure the SPI peripheral */
  /* Set the data frame format */
  if (Copy_DataFrame == SPI_DATA_FRAME_8BIT)
  {
    SET_BIT(SPI->CR1, SPI_CR1_DFF);
  }
  else
  {
    CLEAR_BIT(SPI->CR1, SPI_CR1_DFF);
  }

  /* Set the clock polarity */
  if (Copy_ClockPolarity == SPI_CLOCK_POLARITY_HIGH)
  {
    SET_BIT(SPI->CR1, SPI_CR1_CPOL);
  }
  else
  {
    CLEAR_BIT(SPI->CR1, SPI_CR1_CPOL);
  }

  /* Set the clock phase */
  if (Copy_ClockPhase == SPI_CLOCK_PHASE_SECOND_EDGE)
  {
    SET_BIT(SPI->CR1, SPI_CR1_CPHA);
  }
  else
  {
    CLEAR_BIT(SPI->CR1, SPI_CR1_CPHA);
  }

  /* Set the clock speed */
  SPI->CR1 &= ~SPI_CR1_BR_MSK;
  SPI->CR1 |= SPI_CR1_BR_DIV2;

  /* Set the master mode */
  SET_BIT(SPI->CR1, SPI_CR1_MSTR);

  /* Enable the SPI peripheral */
  SET_BIT(SPI->CR1, SPI_CR1_SPE);
}

void SPI_voidTransfer(u8* pTxData, u8* pRxData, u16 size)
{
  u16 i;

  /* Set the slave select pin */
  SPI_voidSetSlaveSelectPin(LOW);

  /* Send and receive the data */
  for (i = 0; i < size; i++)
  {
    /* Send the data */
    SPI_voidSendByte(pTxData[i]);

    /* Receive the data */
    pRxData[i] = SPI_u8ReceiveByte();
  }

  /* Wait for the transmission to complete */
  SPI_voidWaitForTransmissionComplete();

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

static void SPI_voidSendByte(u8 data)
{
  /* Wait for the transmit buffer to be empty */
  while (!(SPI->SR & SPI_SR_TXE));

  /* Send the data */
  *((u8*)&(SPI->DR)) = data;
}

static u8 SPI_u8ReceiveByte(void)
{
  /* Wait for the receive buffer to be full */
  while (!(SPI->SR & SPI_SR_RXNE));

  /* Return the received data */
  return *((u8*)&(SPI->DR));
}

static void SPI_voidWaitForTransmissionComplete(void)
{
  /* Wait for the transmission to complete */
  while (SPI->SR & SPI_SR_BSY);
}

static void SPI_voidSetSlaveSelectPin(u8 status)
{
  /* Set or clear the slave select pin */
  if (status == LOW)
  {
    SET_BIT(GPIOA->ODR, GPIO_ODR_ODR4);
  }
  else
  {
    CLEAR_BIT(GPIOA->ODR, GPIO_ODR_ODR4);
  }
}

/**
 * @}
 */

