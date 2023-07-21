/**
 * @file UART_program.c
 * @brief This file contains the implementation of the UART driver functions.
 * @date 20 Feb 2022
 * @version V01
 * 
 * @details This file implements the UART driver functions for initializing and controlling the UART module.
 * 
 * @author Mahmoud Abdelraouf Mahmoud
 * 
 * @see Some_Reference_to_Other_Code
 * 
 * @note This module requires the STM32Fxx microcontroller.
 * 
 * @attention Pay attention to some specific details.
 * 
 * @bug Known bug: The function XYZ does not handle edge cases properly.
 * 
 * @warning Be cautious when using this module.
 * 
 * @todo Implement the additional functionality.
 * 
 * @deprecated This module is deprecated and will be replaced in future versions.
 * 
 * @remarks Some additional remarks.
 * 
 * @addtogroup UART_Driver
 * @{
 */

/*********************< LIB *********************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*********************< MCAL *********************/
#include "UART_config.h"
#include "UART_private.h"
#include "UART_interface.h"

void UART_voidInit(USART_RegDef_t *Copy_psUSART, UART_Config_t *config)
{
  /* Configure UART word length */
  if (config->WordLength == UART_WORD_LENGTH_8BIT)
  {
    /* Configure 8-bit word length */
  }
  else if (config->WordLength == UART_WORD_LENGTH_9BIT)
  {
    /* Configure 9-bit word length */
  }

  /* Configure UART stop bits */
  if (config->StopBits == UART_STOP_BITS_1)
  {
    /* Configure 1 stop bit */
  }
  else if (config->StopBits == UART_STOP_BITS_0_5)
  {
    /* Configure 0.5 stop bit */
  }
  else if (config->StopBits == UART_STOP_BITS_2)
  {
    /* Configure 2 stop bits */
  }
  else if (config->StopBits == UART_STOP_BITS_1_5)
  {
    /* Configure 1.5 stop bits */
  }

  /* Configure UART parity mode */
  if (config->ParityMode == UART_PARITY_NONE)
  {
    /* Configure no parity */
  }
  else if (config->ParityMode == UART_PARITY_EVEN)
  {
    /* Configure even parity */
  }
  else if (config->ParityMode == UART_PARITY_ODD)
  {
    /* Configure odd parity */
  }

  /* Configure UART hardware flow control */
  if (config->HwFlowControl == UART_HW_FLOW_CONTROL_NONE)
  {
    /* Configure no hardware flow control */
  }
  else if (config->HwFlowControl == UART_HW_FLOW_CONTROL_RTS)
  {
    /* Configure RTS (Request to Send) hardware flow control */
  }
  else if (config->HwFlowControl == UART_HW_FLOW_CONTROL_CTS)
  {
    /* Configure CTS (Clear to Send) hardware flow control */
  }
  else if (config->HwFlowControl == UART_HW_FLOW_CONTROL_RTS_CTS)
  {
    /* Configure RTS and CTS hardware flow control */
  }

  /* Configure UART baud rate */
  /* ... */

  /* Enable UART */
  /* ... */
}


void UART_voidTransmit(USART_RegDef_t *Copy_psUSART, u8* data, u16 size)
{
  // Wait until the transmit buffer is empty
  while (!(Copy_psUSART->SR & USART_SR_TXE));

  for (u16 i = 0; i < size; i++)
  {
    // Transmit one byte of data
    Copy_psUSART->DR = data[i];

    // Wait until the transmission is complete
    while (!(Copy_psUSART->SR & USART_SR_TC));
  }
}

void UART_voidReceive(USART_RegDef_t *Copy_psUSART, u8* data, u16 size)
{
  for (u16 i = 0; i < size; i++)
  {
    // Wait until data is available to receive
    while (!(Copy_psUSART->SR & USART_SR_RXNE));

    // Receive one byte of data
    data[i] = Copy_psUSART->DR;
  }
}

/**
 * @}
 */