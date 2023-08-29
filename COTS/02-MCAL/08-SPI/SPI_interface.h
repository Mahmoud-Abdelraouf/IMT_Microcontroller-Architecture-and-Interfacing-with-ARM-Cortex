/**
 * @file SPI_interface.h
 * @brief Interface file for the SPI driver.
 * 
 * This file contains the function prototypes and definitions for the SPI driver.
 * 
 * @author Mahmoud Abdelraouf Mahmoud
 * @date 15 Jul 2023
 * @version V01
 */

#ifndef __SPI_INTERFACE_H__
#define __SPI_INTERFACE_H__

#include "SPI_registers.h"

/**
 * @addtogroup SPI_Configuration_Options
 * @{
 */

/**
 * @brief Enumeration of available SPI module selections.
 *
 * This enumeration defines the available SPI module selections that can be used to identify different SPI modules.
 * Use these enum values to specify the desired SPI module when working with SPI peripheral functions.
 */
typedef enum
{
  SPI1,     /**< SPI module 1 */
  SPI2,     /**< SPI module 2 */
  SPI3      /**< SPI module 3 */
} SPI_Peripheral_t;

/**
 * @brief Enumeration for SPI status.
 * 
 * This enumeration defines the possible status values for the SPI driver, which are LOW and HIGH. 
 * LOW represents a logic low voltage level (0V) and HIGH represents a logic high voltage level (3.3V or 5V, depending on the system).
 */
typedef enum
{
  SPI_LOW,                            /**< Logic low voltage level (0V) */
  SPI_HIGH = !SPI_LOW                     /**< Logic high voltage level (3.3V or 5V, depending on the system) */
} SPI_Status_t;

/**
 * @enum SPI_FrameFormat_t
 * @brief Enumeration for SPI frame format.
 */
typedef enum
{
    SPI_MSB_FIRST, /**< Most Significant Bit (MSB) first frame format. */
    SPI_LSB_FIRST  /**< Least Significant Bit (LSB) first frame format. */
} SPI_FrameFormat_t;

/**
 * @brief Enumeration of valid SPI data frame formats.
 */
typedef enum
{
  SPI_DATA_FRAME_8BIT,            /**< 8-bit data frame */
  SPI_DATA_FRAME_16BIT            /**< 16-bit data frame */
} SPI_DataFrame_t;

/**
 * @brief Enumeration of valid SPI clock polarities.
 */
typedef enum
{
  SPI_CLOCK_POLARITY_LOW,         /**< clock is low when idle ==> The leading edge will be rising */
  SPI_CLOCK_POLARITY_HIGH         /**< clock is high when idle ==> The leading edge will be falling */
} SPI_ClockPolarity_t;

/**
 * @brief Enumeration of valid SPI clock phases.
 */
typedef enum
{
  SPI_READ_WRITE,       /**< data is captured on the first clock edge ==> Read then Write */
  SPI_WRITE_READ        /**< data is captured on the second clock edge ==> Write then Read */
} SPI_ClockPhase_t;

/**
 * @brief Enumeration of valid SPI baud rate control values.
 */
typedef enum
{
  SPI_BAUD_RATE_DIV2   = (u16)0x0000,    /**< baud rate divider of 2 */
  SPI_BAUD_RATE_DIV4   = (u16)0x0008,    /**< baud rate divider of 4 */
  SPI_BAUD_RATE_DIV8   = (u16)0x0010,    /**< baud rate divider of 8 */
  SPI_BAUD_RATE_DIV16  = (u16)0x0018,    /**< baud rate divider of 16 */
  SPI_BAUD_RATE_DIV32  = (u16)0x0020,    /**< baud rate divider of 32 */
  SPI_BAUD_RATE_DIV64  = (u16)0x0028,    /**< baud rate divider of 64 */
  SPI_BAUD_RATE_DIV128 = (u16)0x0030,    /**< baud rate divider of 128 */
  SPI_BAUD_RATE_DIV256 = (u16)0x0038     /**< baud rate divider of 256 */
} SPI_BaudRateControl_t;

/**
 * @brief SPI Configuration Structure.
 *
 * This structure holds the configuration options for the SPI peripheral.
 *
 * @note The structure's bit-field size and arrangement may vary depending on the hardware and specific SPI module used.
 *
 * @attention When using this structure, ensure that the bit-field sizes and arrangement match the hardware configuration.
 */

/**
 * @brief SPI Configuration Structure.
 *
 * This structure holds the configuration options for the SPI peripheral.
 *
 * @note The structure's bit-field size and arrangement may vary depending on the hardware and specific SPI module used.
 *
 * @attention When using this structure, ensure that the bit-field sizes and arrangement match the hardware configuration.
 */
typedef struct 
{
  
  u8 BaudRateDIV:6;      /**< SPI Baud Rate Divider.
                             The value determines the SPI clock frequency based on the peripheral's clock source.
                             The Baud Rate Divider is represented by a 6-bit value, allowing a range of possible values.
                             The actual SPI clock frequency is calculated using the peripheral clock and this divider.
                             The BaudRateDIV values are used to divide the peripheral clock as follows:
                             - 000000: fPCLK/2
                             - 001000: fPCLK/4
                             - 010000: fPCLK/8
                             - 011000: fPCLK/16
                             - 100000: fPCLK/32
                             - 101000: fPCLK/64
                             - 110000: fPCLK/128
                             - 111000: fPCLK/256
                             Adjust the value accordingly to achieve the desired SPI clock frequency. */
  
  u8 DataFrame:1;        /**< Data Frame Format.
                             Set this bit to configure the data frame format used by the SPI peripheral.
                             - 0: The SPI peripheral operates in 8-bit data frame format.
                             - 1: The SPI peripheral operates in 16-bit data frame format.
                             The actual data frame format must match the configuration of the connected SPI devices. */

  u8 ClockPolarity:1;    /**< Clock Polarity.
                             Set this bit to define the idle state of the SPI clock.
                             - 0: The clock is low in the idle state (CPOL = 0).
                             - 1: The clock is high in the idle state (CPOL = 1).
                             The idle state of the clock should be chosen to meet the requirements of the connected devices. */
                             
  u8 ClockPhase:1;       /**< Clock Phase.
                             Set this bit to define the clock transition edge for data sampling.
                             - 0: Data is captured on the first clock edge and it is written on the second clock edge (CPHA = 0).
                             - 1: Data is written on the first clock edge and it is captured on the second clock edge (CPHA = 1).
                             The clock phase setting should match the requirements of the connected devices. */
  
  u8 FrameFormat:1;      /**< Frame Format.
                             Set this bit to define the frame format used by the SPI peripheral.
                             - 0: The SPI peripheral uses MSB (Most Significant Bit) first frame format.
                             - 1: The SPI peripheral uses LSB (Least Significant Bit) first frame format.
                             The frame format determines the order in which bits are transmitted and received. */
} SPI_config_t;

/**
 * @} SPI_Configuration_Options
 */

/**
 * @addtogroup SPI_Functions
 * @{
 */

/**
 * @brief Get the base address of the specified SPI peripheral.
 *
 * This function returns the base address of the specified SPI peripheral.
 *
 * @param[in] spi The SPI peripheral to get the base address for. Must be one of the following:
 *                - SPI1: SPI1 peripheral.
 *                - SPI2: SPI2 peripheral.
 *                - SPI3: SPI3 peripheral.
 *
 * @return The base address of the specified SPI peripheral as a pointer to the corresponding register structure.
 *         If an invalid SPI peripheral is provided, the function returns NULL.
 *
 * @note Example Usage:
 * @code
 * /// Choose the SPI peripheral you want to use (in this case, SPI1)
 * SPI_Peripheral_t spi_selected = SPI1;
 *
 * /// Get the base address of SPI1 using the SPI_GetBaseAddress function
 * SPI_RegDef_t *spi1_base_address = SPI_GetBaseAddress(spi_selected);
 *
 * /// Now you can access SPI1 registers and configure the SPI communication
 * /// For example, you can configure data frame format, clock polarity, etc.
 *
 * /// ... (add your SPI configuration code here)
 * @endcode
 */
SPI_t SPI_SelectSpiPeripheral(SPI_Peripheral_t spi);

/**
 * @brief Initialize the SPI peripheral.
 *
 * This function initializes the SPI peripheral with the specified configuration.
 *
 * @param[in] Copy_psSPIConfig Pointer to the SPI configuration structure that holds the configuration options.
 *                            The structure must contain the following fields:
 *                            - SpiPeripheral : The spi peripheral selected to use. Must be one of the following:
 *                                          - SPI_1: SPI module 1
 *                                          - SPI_2: SPI module 2
 *                                          - SPI_3: SPI module 3
 *                            - DataFrame: The data frame format to use. Must be one of the following:
 *                                          - SPI_DATA_FRAME_8BIT: 8-bit data frame.
 *                                          - SPI_DATA_FRAME_16BIT: 16-bit data frame.
 *                            - ClockPolarity: The clock polarity to use. Must be one of the following:
 *                                          - SPI_CLOCK_POLARITY_LOW: Clock is low when idle (leading edge is rising).
 *                                          - SPI_CLOCK_POLARITY_HIGH: Clock is high when idle (leading edge is falling).
 *                            - ClockPhase: The clock phase to use. Must be one of the following:
 *                                          - SPI_READ_WRITE: Data is captured on the first clock edge (read then write).
 *                                          - SPI_WRITE_READ: Data is captured on the second clock edge (write then read).
 *                            - BaudRateDIV: The clock speed to use. Must be one of the following:
 *                                          - SPI_BAUD_RATE_DIV2: Baud rate divider of 2.
 *                                          - SPI_BAUD_RATE_DIV4: Baud rate divider of 4.
 *                                          - SPI_BAUD_RATE_DIV8: Baud rate divider of 8.
 *                                          - SPI_BAUD_RATE_DIV16: Baud rate divider of 16.
 *                                          - SPI_BAUD_RATE_DIV32: Baud rate divider of 32.
 *                                          - SPI_BAUD_RATE_DIV64: Baud rate divider of 64.
 *                                          - SPI_BAUD_RATE_DIV128: Baud rate divider of 128.
 *                                          - SPI_BAUD_RATE_DIV256: Baud rate divider of 256.
 *                            - FrameFormat: The frame format to use. Must be one of the following:
 *                                          - SPI_MSB_FIRST: Most Significant Bit (MSB) first frame format. 
 *                                          - SPI_LSB_FIRST: Least Significant Bit (LSB) first frame format. 
 *
 * @retval None
 *
 * @note Example Usage:
 * @code
 * /// Choose the SPI peripheral you want to use (in this case, SPI1)
 * SPI_t SPI_1 = SPI_SelectSpiPeripheral(SPI1);
 * 
 * /// Create an SPI configuration structure and set the desired options
 * SPI_config_t spi_config;
 * spi_config.DataFrame = SPI_DATA_FRAME_8BIT;
 * spi_config.ClockPolarity = SPI_CLOCK_POLARITY_LOW;
 * spi_config.ClockPhase = SPI_WRITE_READ;
 * spi_config.BaudRateDIV = SPI_BAUD_RATE_DIV32;
 * 
 * OR
 * 
 * /// Select the SPI peripheral (e.g., SPI_1)
 * 	SPI_config_t Local_Spi1 = { .BaudRateDIV = SPI_BAUD_RATE_DIV2, .SpiPeripheral = SPI_1,
 *							                .DataFrame = SPI_DATA_FRAME_8BIT, .ClockPolarity = SPI_CLOCK_POLARITY_HIGH,
 *							                .ClockPhase = SPI_CLOCK_PHASE_SECOND_EDGE,.FrameFormat = SPI_MSB_FIRST};
 *
 * /// Initialize the SPI peripheral using the SPI_voidInit function
 * SPI_voidInit(SPI_1,&Local_Spi1);
 *
 * /// Now the SPI peripheral is initialized and ready to use for communication.
 * @endcode
 */
void SPI_voidInit(SPI_t Copy_psfSelectedSpi, const SPI_config_t *Copy_psSPIConfig);
      
/**
 * @brief Perform a full-duplex SPI data transfer.
 *
 * This function sends and receives an array of data bytes using the SPI peripheral in full-duplex mode.
 * It sends the data in `Copy_u8pTxData` and simultaneously receives the data in `Copy_u8pRxData`.
 *
 * @param[in] Copy_SPI The SPI peripheral to perform the transfer.
 * @param[in] Copy_u8pTxData Pointer to the array of data bytes to be transmitted.
 * @param[out] Copy_u8pRxData Pointer to the array where received data bytes will be stored.
 * @param[in] Copy_u16size The number of data bytes to be transmitted and received.
 *
 * @return None.
 *
 * @note This function blocks until the full transfer is complete.
 *       Ensure that the SPI peripheral and appropriate communication settings are configured
 *       before calling this function.
 *
 * @note Example Usage:
 * @code
 * /// Select the SPI peripheral (e.g., SPI2)
 * SPI_t spi_selected = SPI_SelectSpiPeripheral(SPI_2);
 *
 * /// Data arrays for transmission and reception
 * u8 tx_data[] = {0x01, 0x02, 0x03, 0x04};
 * u8 rx_data[4];
 *
 * /// Perform the SPI data transfer
 * SPI_voidTransfer(spi_selected, tx_data, rx_data, sizeof(tx_data));
 * @endcode
 */
void SPI_voidTransfer(SPI_t Copy_SPI, u8 *Copy_u8pTxData, u8 *Copy_u8pRxData, u16 Copy_u16size);

/**
 * @} SPI_Functions
 */

#endif /* __SPI_INTERFACE_H__ */

