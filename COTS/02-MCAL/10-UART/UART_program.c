/**
 ********************************************************************************************************************************** 
 * @file UART_program.c
 * @brief This file contains the implementation of the UART driver functions.
 * @date 20 Feb 2022
 * @version V01
 ********************************************************************************************************************************** 
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
 ********************************************************************************************************************************** 
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

void UART_Init(USART_RegDef_t *Copy_USART, UART_Config_t *config)
{
  /**< Configure UART word length (data bits) */
  if (config->WordLength == UART_WORD_LENGTH_8BIT)
  {
    /**< Configure 8-bit word length */
    Copy_USART->CR1 &= ~USART_CR1_M;  /**< Clear the M bit for 8-bit word length */ 
  }
  else if (config->WordLength == UART_WORD_LENGTH_9BIT)
  {
    /**< Configure 9-bit word length */
    Copy_USART->CR1 |= USART_CR1_M;  /**< Set the M bit for 8-bit word length */ 
  }

  /**< Configure UART stop bits */
  Copy_USART->CR2 &= ~USART_CR2_STOP;     /**< Clear the STOP bits */ 
  Copy_USART->CR2 |= config->StopBits;    /**< Set the specified stop bits */

  /**< Configure UART parity mode */
  if (config->ParityMode == UART_PARITY_NONE)
  {
    /**< Configure no parity */
    Copy_USART->CR1 &= ~(USART_CR1_PCE | USART_CR1_PS); /**< Clear the PCE and PS bits for no parity */
  }
  else if (config->ParityMode == UART_PARITY_EVEN)
  {
    /**< Configure even parity */
    Copy_USART->CR1 |= USART_CR1_PCE;   /**< Set the PCE bit for even parity */ 
    Copy_USART->CR1 &= ~USART_CR1_PS;   /**< Clear the PS bit for even parity */
  }
  else if (config->ParityMode == UART_PARITY_ODD)
  {
    /**< Configure odd parity */
    Copy_USART->CR1 |= USART_CR1_PCE;   /**< Set the PCE bit for odd parity */ 
    Copy_USART->CR1 |= USART_CR1_PS;    /**< Set the PS bit for odd parity */ 
  }

  /**< Configure UART hardware flow control */
  if (config->HwFlowControl == UART_HW_FLOW_CONTROL_NONE)
  {
    /**< Configure no hardware flow control */
    Copy_USART->CR3 &= ~(USART_CR3_RTSE | USART_CR3_CTSE); /**< Clear the RTSE and CTSE bits for no hardware flow control */ 
  }
  else if (config->HwFlowControl == UART_HW_FLOW_CONTROL_RTS)
  {
    /**< Configure RTS (Request to Send) hardware flow control */  
    Copy_USART->CR3 |= USART_CR3_RTSE;    /**< Set the RTSE bit for RTS hardware flow control */
    Copy_USART->CR3 &= ~USART_CR3_CTSE;   /**< Clear the CTSE bit */
  }
  else if (config->HwFlowControl == UART_HW_FLOW_CONTROL_CTS)
  {
    /**< Configure CTS (Clear to Send) hardware flow control */
    Copy_USART->CR3 |= USART_CR3_CTSE;      /**< Set the CTSE bit for CTS hardware flow control */
    Copy_USART->CR3 &= ~USART_CR3_RTSE;     /**< Clear the RTSE bit */
  }
  else if (config->HwFlowControl == UART_HW_FLOW_CONTROL_RTS_CTS)
  {
    /**< Configure RTS and CTS hardware flow control */
    Copy_USART->CR3 |= USART_CR3_RTSE | USART_CR3_CTSE; /**< Set both RTSE and CTSE bits for RTS and CTS hardware flow control */ 
  }

  /*********************< Configure UART baud rate *********************/
  /**< Calculate the value of the USARTDIV register based on the desired baud rate */
  f32 Local_f32USARTDIV = (f32)USART_CLK_SRC / (16 * config->BaudRate);

  /**< Calculate the integer (mantissa) and fractional parts of USARTDIV */
  u16 Local_u16DIV_Mantissa = (u16)Local_f32USARTDIV;
  u16 Local_u16DIV_Fraction = (u16)(((Local_f32USARTDIV - Local_u16DIV_Mantissa) * 16) + 0.5);

  /**< Check if the fractional part requires carrying */
  u8 Local_u8Carry = 0;
  if (Local_u16DIV_Fraction >= 16)
  {
    Local_u16DIV_Fraction -= 16;
    Local_u8Carry = 1;
  }

  /**< Adjust the mantissa if carry is required */
  if (Local_u8Carry == 1)
  {
    Local_u16DIV_Mantissa += 1;
  }

  /**< Configure the Baud Rate Register (BRR) with calculated values */
  Copy_USART->BRR = (Local_u16DIV_Mantissa << 4) | Local_u16DIV_Fraction;

  /**< Enable UART */
  Copy_USART->CR1 |= USART_CR1_UE;  /**< Set the UE bit to enable UART */ 
}


void UART_Transmit(USART_RegDef_t *Copy_USART, u8* data, u16 size)
{
  /**< Wait until the transmit buffer is empty */ 
  while (!(Copy_USART->SR & USART_SR_TXE));

  for (u16 i = 0; i < size; i++)
  {
    /**< Transmit one byte of data */ 
    Copy_USART->DR = data[i];

    /**< Wait until the transmission is complete */ 
    while (!(Copy_USART->SR & USART_SR_TC));
  }
}

void UART_Receive(USART_RegDef_t *Copy_USART, u8* data, u16 size)
{
  for (u16 i = 0; i < size; i++)
  {
    /**< Wait until data is available to receive */ 
    while (!(Copy_USART->SR & USART_SR_RXNE));

    /**< Receive one byte of data */ 
    data[i] = Copy_USART->DR;
  }
}

/**
 * @}
 */