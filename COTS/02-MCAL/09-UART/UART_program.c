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

void UART_voidInit(UART_Config_t *config)
{
  /* Configure UART word length */
  if (config->wordLength == UART_WORD_LENGTH_8BIT)
  {
    /* Configure 8-bit word length */
  }
  else if (config->wordLength == UART_WORD_LENGTH_9BIT)
  {
    /* Configure 9-bit word length */
  }

  /* Configure UART stop bits */
  if (config->stopBits == UART_STOP_BITS_1)
  {
    /* Configure 1 stop bit */
  }
  else if (config->stopBits == UART_STOP_BITS_0_5)
  {
    /* Configure 0.5 stop bit */
  }
  else if (config->stopBits == UART_STOP_BITS_2)
  {
    /* Configure 2 stop bits */
  }
  else if (config->stopBits == UART_STOP_BITS_1_5)
  {
    /* Configure 1.5 stop bits */
  }

  /* Configure UART parity mode */
  if (config->parityMode == UART_PARITY_NONE)
  {
    /* Configure no parity */
  }
  else if (config->parityMode == UART_PARITY_EVEN)
  {
    /* Configure even parity */
  }
  else if (config->parityMode == UART_PARITY_ODD)
  {
    /* Configure odd parity */
  }

  /* Configure UART hardware flow control */
  if (config->hwFlowControl == UART_HW_FLOW_CONTROL_NONE)
  {
    /* Configure no hardware flow control */
  }
  else if (config->hwFlowControl == UART_HW_FLOW_CONTROL_RTS)
  {
    /* Configure RTS (Request to Send) hardware flow control */
  }
  else if (config->hwFlowControl == UART_HW_FLOW_CONTROL_CTS)
  {
    /* Configure CTS (Clear to Send) hardware flow control */
  }
  else if (config->hwFlowControl == UART_HW_FLOW_CONTROL_RTS_CTS)
  {
    /* Configure RTS and CTS hardware flow control */
  }

  /* Configure UART baud rate */
  /* ... */

  /* Enable UART */
  /* ... */
}

void UART_voidTransmit(u8* data, u16 size)
{
  /* Transmit data over UART */
  /* ... */
}

void UART_voidReceive(u8* data, u16 size)
{
  /* Receive data from UART */
  /* ... */
}

/**
 * @}
 */