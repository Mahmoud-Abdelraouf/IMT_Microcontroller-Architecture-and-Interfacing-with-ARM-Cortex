/**
 * @file SPI_config.h
 * @brief Configuration file for the SPI driver.
 * 
 * This file contains the configuration options for the SPI driver.
 * 
 * @author Mahmoud Abdelraouf Mahmoud
 * @date 15 Jul 2023
 * @version V01
 */

#ifndef __SPI_CONFIG_H__
#define __SPI_CONFIG_H__

/**
 * @defgroup SPI_Configuration_Options SPI Configuration Options
 * @{
 */

/**
 * @brief The default SPI peripheral.
 * 
 * This macro defines the default SPI peripheral to be used.
 * Users can choose from the following options:
 * - SPI_1: SPI module 1
 * - SPI_2: SPI module 2
 * - SPI_3: SPI module 3
 * 
 * The selected default SPI peripheral will be used in cases where the user does not explicitly
 * specify a different SPI peripheral.
 * 
 * @note It's recommended to choose the appropriate default SPI peripheral based on the hardware configuration.
 */
#define SPI_Default             SPI_1

/**
 * @brief The SPI mode.
 * 
 * This option selects whether the microcontroller will operate in master or slave mode.
 *
 * Available options:
 * - SPI_MASTER_MODE
 * - SPI_SLAVE_MODE
 */
#define SPI_MODE         SPI_MASTER_MODE


/** ======================== This future not been suppurated yet as configurable option but suppurated in run time  ======================== */
/**
 * @brief The SPI data frame format.
 * 
 * This option specifies the data frame format for the SPI peripheral.
 * Valid options are:
 * - SPI_DATA_FRAME_8BIT: 8-bit data frame
 * - SPI_DATA_FRAME_16BIT: 16-bit data frame
 */
#define SPI_DATA_FRAME     SPI_DATA_FRAME_8BIT

/**
 * @brief The SPI clock polarity.
 * 
 * This option specifies the clock polarity for the SPI peripheral.
 * Valid options are:
 * - SPI_CLOCK_POLARITY_LOW: clock is low when idle
 * - SPI_CLOCK_POLARITY_HIGH: clock is high when idle
 */
#define SPI_CLOCK_POLARITY SPI_CLOCK_POLARITY_LOW

/**
 * @brief The SPI clock phase.
 * 
 * This option specifies the clock phase for the SPI peripheral.
 * Valid options are:
 * - SPI_CLOCK_PHASE_FIRST_EDGE: data is captured on the first clock edge -> Read, Write
 * - SPI_CLOCK_PHASE_SECOND_EDGE: data is captured on the second clock edge -> Write, Read
 */
#define SPI_CLOCK_PHASE    SPI_CLOCK_PHASE_FIRST_EDGE

/**
 * @} SPI_Configuration_Options SPI Configuration Options
 */

#endif /**< __SPI_CONFIG_H__ */