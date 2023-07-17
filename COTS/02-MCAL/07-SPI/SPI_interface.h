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

/**
 * @addtogroup SPI_Configuration_Options
 * @{
 */

/**
 * @brief Enumeration for SPI status.
 * 
 * This enumeration defines the possible status values for the SPI driver, which are LOW and HIGH. 
 * LOW represents a logic low voltage level (0V) and HIGH represents a logic high voltage level (3.3V or 5V, depending on the system).
 */
typedef enum
{
  LOW,            /**< Logic low voltage level (0V) */
  HIGH = !LOW     /**< Logic high voltage level (3.3V or 5V, depending on the system) */
} SPI_Status_t;

/**
 * @brief Enumeration of valid SPI data frame formats.
 */
typedef enum
{
  SPI_DATA_FRAME_8BIT,    /**< 8-bit data frame */
  SPI_DATA_FRAME_16BIT    /**< 16-bit data frame */
} SPI_DataFrame_t;

/**
 * @brief Enumeration of valid SPI clock polarities.
 */
typedef enum
{
  SPI_CLOCK_POLARITY_LOW,    /**< clock is low when idle ==> the leading edge will be rising */
  SPI_CLOCK_POLARITY_HIGH    /**< clock is high when idle ==> the leading edge will be falling */
} SPI_ClockPolarity_t;


typedef enum 
{
  SPI
}SPI_BaudRateControl_t;

/**
 * @brief Enumeration of valid SPI clock phases.
 */
typedef enum
{
  SPI_CLOCK_PHASE_FIRST_EDGE,    /**< data is captured on the first clock edge ==> Read then Write */
  SPI_CLOCK_PHASE_SECOND_EDGE    /**< data is captured on the second clock edge ==> Write then Read */
} SPI_ClockPhase_t;

/**
 * @}
 */

/**
 * @addtogroup SPI_Functions
 * @{
 */

/**
 * @brief Initialize the SPI peripheral.
 * 
 * This function initializes the SPI peripheral with the specified configuration.
 * 
 * @param[in] dataFrame The data frame format to use.
 * @param[in] clockPolarity The clock polarity to use.
 * @param[in] clockPhase The clock phase to use.
 * @param[in] clockSpeed The clock speed to use in Hz.
 */
void SPI_voidInit(SPI_DataFrame_t dataFrame, SPI_ClockPolarity_t clockPolarity,
                  SPI_ClockPhase_t clockPhase, u32 clockSpeed);

/**
 * @brief Send and receive data over SPI.
 * 
 * This function sends and receives data over SPI. The data is transmitted and received
 * in full duplex mode.
 * 
 * @param[in] pTxData Pointer to the data to transmit.
 * @param[out] pRxData Pointer to the buffer to receive the data.
 * @param[in] size The number of bytes to transmit and receive.
 */
void SPI_voidTransfer(u8* pTxData, u8* pRxData, u16 size);

/**
 * @}
 */

#endif /* __SPI_INTERFACE_H__ */

