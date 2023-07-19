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
 * @brief The SPI peripheral to use.
 * 
 * This option specifies which SPI peripheral to use. Valid options
 * are SPI1, SPI2, and SPI3.
 * 
 * @note This option must be defined in the project configuration file.
 */
#define SPI_PERIPHERAL     SPI1

/**
 * @brief The SPI clock speed in Hz.
 * 
 * This option specifies the clock speed for the SPI peripheral in Hz.
 * 
 * @note The actual clock speed may be lower than this value, depending on
 *       the clock configuration of the system.
 */
#define SPI_CLOCK_SPEED    1000000

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
 * - SPI_CLOCK_PHASE_FIRST_EDGE: data is captured on the first clock edge
 * - SPI_CLOCK_PHASE_SECOND_EDGE: data is captured on the second clock edge
 */
#define SPI_CLOCK_PHASE    SPI_CLOCK_PHASE_FIRST_EDGE

/**
 * @}
 */

#endif /**< __SPI_CONFIG_H__ */