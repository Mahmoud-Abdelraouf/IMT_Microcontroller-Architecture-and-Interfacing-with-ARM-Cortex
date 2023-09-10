/**
 * @file SPI_private.h
 * @brief Private file for the SPI driver.
 * 
 * This file contains the private function prototypes and definitions for the SPI driver.
 * These functions and definitions are not intended to be used outside of the driver.
 * 
 * @note Do not include this file directly in your application code.
 *       Instead, include the public interface file (SPI_interface.h).
 * 
 * @author Mahmoud Abdelraouf Mahmoud
 * @date 15 Jul 2023
 * @version V01
 */

#ifndef __SPI_PRIVATE_H__
#define __SPI_PRIVATE_H__

/**
 * @defgroup SPI_DEFAULT_OPTIONS 
 * @brief This group contains private macros used defined in the user region @ref SPI_config.h file.
 * @{
 */

/** 
 * @brief SPI Peripheral Options
 
 * Users can choose from the following SPI peripheral options:
 * - SPI1: SPI module 1
 * - SPI2: SPI module 2
 * - SPI3: SPI module 3
 * 
 * These options determine which SPI peripheral will be used for communication.
 */
#define SPI_1           ((SPI_t)SPI1_BASE_ADDRESS)
#define SPI_2           ((SPI_t)SPI2_BASE_ADDRESS)
#define SPI_3           ((SPI_t)SPI3_BASE_ADDRESS)

/**
 * @}
 */

/**
 * @defgroup SPI_Private_Macros Private Macros
 * @brief This group contains private macros used internally by the SPI driver.
 * @{
 */

/**
 * @brief SPI master mode selection.
 * 
 * This definition indicates whether the microcontroller operates as an SPI master.
 */
#define SPI_MASTER_MODE             1

/**
 * @brief SPI slave mode selection.
 * 
 * This definition indicates whether the microcontroller operates as an SPI slave.
 */
#define SPI_SLAVE_MODE              0

/**
 * @brief SPI_SR_RXNE bit position.
 */
#define SPI_SR_RXNE                 0

/**
 * @brief SPI_SR_TXE bit position.
 */
#define SPI_SR_TXE                  1

/**
 * @brief SPI_SR_BSY bit position.
 */
#define SPI_SR_BSY                  7

/**
 * @brief Mask to clear the baud rate control bits in the SPI_CR1 register.
 * 
 * This mask is used to clear the baud rate control bits in the SPI_CR1 register
 * so that they can be set to a new value without affecting other bits in the register.
 */
#define SPI_CR1_BR_MSK          (u32)0x0038 

/**
 * @brief Baud rate control value for a divider of 2.
 * @details This value sets the baud rate divider to 2.
 * @note This value should be used with the SPI_CR1_BR_MSK mask.
 */
#define SPI_CR1_BR_DIV2         (u32)0x0000   

/**
 * @brief Baud rate control value for a divider of 4.
 * @details This value sets the baud rate divider to 4.
 * @note This value should be used with the SPI_CR1_BR_MSK mask.
 */
#define SPI_CR1_BR_DIV4         (u32)0x0008 

/**
 * @brief Baud rate control value for a divider of 8.
 * @details This value sets the baud rate divider to 8.
 * @note This value should be used with the SPI_CR1_BR_MSK mask.
 */
#define SPI_CR1_BR_DIV8         (u32)0x0010

/**
 * @brief Baud rate control value for a divider of 16.
 * @details This value sets the baud rate divider to 16.
 * @note This value should be used with the SPI_CR1_BR_MSK mask.
 */
#define SPI_CR1_BR_DIV16        (u32)0x0018

/**
 * @brief Baud rate control value for a divider of 32.
 * @details This value sets the baud rate divider to 32.
 * @note This value should be used with the SPI_CR1_BR_MSK mask.
 */
#define SPI_CR1_BR_DIV32        (u32)0x0020

/**
 * @brief Baud rate control value for a divider of 64.
 * @details This value sets the baud rate divider to 64.
 * @note This value should be used with the SPI_CR1_BR_MSK mask.
 */
#define SPI_CR1_BR_DIV64        (u32)0x0028

/**
 * @brief Baud rate control value for a divider of 128.
 * @details This value sets the baud rate divider to 128.
 * @note This value should be used with the SPI_CR1_BR_MSK mask.
 */
#define SPI_CR1_BR_DIV128       (u32)0x0030

/**
 * @brief Baud rate control value for a divider of 256.
 * @details This value sets the baud rate divider to 256.
 * @note This value should be used with the SPI_CR1_BR_MSK mask.
 */
#define SPI_CR1_BR_DIV256       (u32)0x0038

/**
 * @}
 */


/**
 * @brief SPI Control Register 1 Bits
 *
 * This section defines the bit positions of the SPI Control Register 1 (CR1) and their corresponding bit names.
 *
 * @param SPI_CR1_CPHA: The Clock Phase bit.
 * @param SPI_CR1_CPOL: The Clock Polarity bit.
 * @param SPI_CR1_MSTR: The Master Selection bit.
 * @param SPI_CR1_SPE: The SPI Enable bit.
 * @param SPI_CR1_DFF: The Data Frame Format bit.
 */
#define SPI_CR1_CPHA            0   /**< The Clock Phase bit. */
#define SPI_CR1_CPOL            1   /**< The Clock Polarity bit. */
#define SPI_CR1_MSTR            2   /**< The Master Selection bit. */
#define SPI_CR1_SPE             6   /**< The SPI Enable bit. */
#define SPI_CR1_LSBFIRST        7   /**< The Frame format bit */
#define SPI_CR1_SSI             8   /**< The Internal slave select bit */
#define SPI_CR1_SSM             9   /**< The Software slave management bit */
#define SPI_CR1_DFF             11  /**< The Data Frame Format bit. */

/**
 * @}
 */

/**
 * @addtogroup SPI_Private_Functions
 * @{
 */

/**
 * @brief Send a single byte of data through the SPI peripheral.
 *
 * This function waits until the transmit buffer of the SPI peripheral is empty,
 * then sends the provided byte of data through the SPI Data Register (DR).
 *
 * @param[in] Copy_SPI Pointer to the SPI peripheral structure through which to send data.
 * @param[in] Copy_Data The byte of data to send.
 *
 * @return None.
 *
 * @note This function blocks until the transmit buffer is empty and data is sent.
 *       Ensure that the SPI peripheral and appropriate communication settings are configured
 *       before calling this function.
 *
 * @note Example Usage:
 * @code
 * /// Select the SPI peripheral (e.g., SPI3)
 * SPI_RegDef_t *spi_selected = SPI_SelectSpiPeripheral(SPI3);
 *
 * /// Send a byte of data through the SPI peripheral
 * u8 data_to_send = 0xAB;
 * SPI_voidSendByte(spi_selected, data_to_send);
 * @endcode
 */
static void SPI_SendByte(SPI_RegDef_t *Copy_SPI, u8 Copy_Data);

/**
 * @brief Receive a single byte of data from the SPI peripheral.
 *
 * This function waits until the receive buffer of the SPI peripheral is full,
 * then returns the received byte of data.
 *
 * @param[in] Copy_SPI Pointer to the SPI peripheral structure from which to receive data.
 *
 * @return The received byte of data.
 *
 * @note This function blocks until the receive buffer is full and data is available for reading.
 *       Ensure that the SPI peripheral and appropriate communication settings are configured
 *       before calling this function.
 *
 * @note Example Usage:
 * @code
 * /// Select the SPI peripheral (e.g., SPI1)
 * SPI_RegDef_t *spi_selected = SPI_GetBaseAddress(SPI1);
 *
 * /// Receive a byte of data from the SPI peripheral
 * u8 received_data = SPI_u8ReceiveByte(spi_selected);
 * @endcode
 */
static u8 SPI_ReceiveByte(SPI_RegDef_t *Copy_SPI);

/**
 * @brief Wait for the SPI transmission to complete.
 *
 * This function blocks until the SPI transmission is complete, indicated by the BSY (busy) flag
 * in the status register being cleared.
 *
 * @param[in] Copy_SPI Pointer to the SPI peripheral structure to monitor for transmission completion.
 *
 * @return None.
 *
 * @note This function blocks until the SPI transmission is complete.
 *       Ensure that the SPI peripheral and appropriate communication settings are configured
 *       before calling this function.
 *
 * @note Example Usage:
 * @code
 * /// Select the SPI peripheral (e.g., SPI2)
 * SPI_RegDef_t *spi_selected = SPI_GetBaseAddress(SPI2);
 *
 * /// Perform SPI transmission and wait for completion
 * SPI_voidTransmit(spi_selected, data_buffer, data_size);
 * SPI_voidWaitForTransmissionComplete(spi_selected);
 * @endcode
 */
static void SPI_WaitForTransmissionComplete(SPI_RegDef_t *Copy_SPI);

/**
 * @brief Initializes the SPI peripheral with default settings.
 * 
 * This function configures the SPI peripheral with the following default settings:
 * - 8-bit data frame format
 * - LSB first frame format
 * - Clock polarity high at idle state
 * - Clock phase set for write then read
 * - Clock speed divided by two
 * - Master mode enabled/Slave mode enable
 * - Software slave management enabled
 * - Master mode selected
 * - SPI peripheral enabled
 * 
 * @note This function assumes that the SPI_Default pointer points to the base address of the SPI peripheral.
 * 
 * @param None
 * @return None
 */
static void SPI_DefaultInitiation(void);

/**
 * @}
 */

#endif /**< __SPI_PRIVATE_H__ */

