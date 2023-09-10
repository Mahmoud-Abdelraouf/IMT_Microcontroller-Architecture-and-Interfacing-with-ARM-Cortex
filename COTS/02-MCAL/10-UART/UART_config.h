/**
 * @file UART_config.h
 * @brief Configuration file for the UART driver.
 * @date 19 Jul 2023
 * @version V01
 * 
 * @details This file contains the configuration options for the UART driver.
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
 * @defgroup UART_Configuration UART Driver Configuration
 * @{
 */

#ifndef __UART_CONFIG_H__
#define __UART_CONFIG_H__

/**
 * @addtogroup UART_Configuration_Options
 * @{
 */

/**
 * @brief Enumeration for UART parity modes.
 *
 * This enumeration defines the possible parity modes for the UART driver.
 * PARITY_NONE: No parity bit is used.
 * PARITY_EVEN: Even parity is used.
 * PARITY_ODD: Odd parity is used.
 */
typedef enum
{
  PARITY_NONE,  /**< No parity bit is used */
  PARITY_EVEN,  /**< Even parity is used */
  PARITY_ODD    /**< Odd parity is used */
} UART_Parity_t;

/**
 * @brief Enumeration for UART stop bit modes.
 *
 * This enumeration defines the possible stop bit modes for the UART driver.
 * STOP_BITS_1: 1 stop bit is used.
 * STOP_BITS_2: 2 stop bits are used.
 */
typedef enum
{
  STOP_BITS_1,  /**< 1 stop bit is used */
  STOP_BITS_2   /**< 2 stop bits are used */
} UART_StopBits_t;

/**
 * @brief Enumeration for UART data word lengths.
 *
 * This enumeration defines the possible data word lengths for the UART driver.
 * DATA_BITS_8: 8 data bits are used.
 * DATA_BITS_9: 9 data bits are used.
 */
typedef enum
{
  DATA_BITS_8,  /**< 8 data bits are used */
  DATA_BITS_9   /**< 9 data bits are used */
} UART_DataBits_t;

/**
 * @brief Enumeration for UART baud rate options.
 *
 * This enumeration defines the possible baud rate options for the UART driver.
 * BAUD_RATE_9600: Baud rate of 9600.
 * BAUD_RATE_115200: Baud rate of 115200.
 * BAUD_RATE_57600: Baud rate of 57600.
 * BAUD_RATE_38400: Baud rate of 38400.
 */
typedef enum
{
  BAUD_RATE_9600,     /**< Baud rate of 9600 */
  BAUD_RATE_115200,   /**< Baud rate of 115200 */
  BAUD_RATE_57600,    /**< Baud rate of 57600 */
  BAUD_RATE_38400     /**< Baud rate of 38400 */
} UART_BaudRate_t;

/**
 * @}
 */

/**
 * @addtogroup UART_Functions
 * @{
 */

/**
 * @brief Configure the UART peripheral.
 *
 * This function configures the UART peripheral with the specified options.
 *
 * @param[in] parity The parity mode to use. Must be one of the following:
 *                   - PARITY_NONE
 *                   - PARITY_EVEN
 *                   - PARITY_ODD
 * @param[in] stopBits The stop bit mode to use. Must be one of the following:
 *                     - STOP_BITS_1
 *                     - STOP_BITS_2
 * @param[in] dataBits The data word length to use. Must be one of the following:
 *                     - DATA_BITS_8
 *                     - DATA_BITS_9
 * @param[in] baudRate The baud rate option to use. Must be one of the following:
 *                     - BAUD_RATE_9600
 *                     - BAUD_RATE_115200
 *                     - BAUD_RATE_57600
 *                     - BAUD_RATE_38400
 *
 * @retval None
 */
void UART_voidConfigure(UART_Parity_t parity, UART_StopBits_t stopBits, UART_DataBits_t dataBits, UART_BaudRate_t baudRate);

/**
 * @brief Send data over UART.
 *
 * This function sends data over UART.
 *
 * @param[in] data The data to send.
 *
 * @retval None
 */
void UART_voidSendData(u8 data);

/**
 * @brief Receive data over UART.
 *
 * This function receives data over UART.
 *
 * @return The received data.
 */
u8 UART_u8ReceiveData(void);

/**
 * @}
 */

#endif /* __UART_CONFIG_H__ */

/**
 * @}
 */