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
  SPI_CLOCK_POLARITY_LOW,    /**< clock is low when idle ==> The leading edge will be rising */
  SPI_CLOCK_POLARITY_HIGH    /**< clock is high when idle ==> The leading edge will be falling */
} SPI_ClockPolarity_t;

/**
 * @brief Enumeration of valid SPI clock phases.
 */
typedef enum
{
  SPI_CLOCK_PHASE_FIRST_EDGE,    /**< data is captured on the first clock edge ==> Read then Write */
  SPI_CLOCK_PHASE_SECOND_EDGE    /**< data is captured on the second clock edge ==> Write then Read */
} SPI_ClockPhase_t;

/**
 * @brief Enumeration of valid SPI baud rate control values.
 */
typedef enum
{
  SPI_BAUD_RATE_DIV2   = (u32)0x0000,    /**< baud rate divider of 2 */
  SPI_BAUD_RATE_DIV4   = (u32)0x0008,    /**< baud rate divider of 4 */
  SPI_BAUD_RATE_DIV8   = (u32)0x0010,    /**< baud rate divider of 8 */
  SPI_BAUD_RATE_DIV16  = (u32)0x0018,    /**< baud rate divider of 16 */
  SPI_BAUD_RATE_DIV32  = (u32)0x0020,    /**< baud rate divider of 32 */
  SPI_BAUD_RATE_DIV64  = (u32)0x0028,    /**< baud rate divider of 64 */
  SPI_BAUD_RATE_DIV128 = (u32)0x0030,    /**< baud rate divider of 128 */
  SPI_BAUD_RATE_DIV256 = (u32)0x0038     /**< baud rate divider of 256 */
} SPI_BaudRateControl_t;


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
 * @param[in] dataFrame The data frame format to use. Must be one of the following:
 *                      - SPI_DATA_FRAME_8BIT
 *                      - SPI_DATA_FRAME_16BIT
 * @param[in] clockPolarity The clock polarity to use. Must be one of the following:
 *                      - SPI_CLOCK_POLARITY_LOW
 *                      - SPI_CLOCK_POLARITY_HIGH
 * @param[in] clockPhase The clock phase to use. Must be one of the following:
 *                      - SPI_CLOCK_PHASE_FIRST_EDGE
 *                      - SPI_CLOCK_PHASE_SECOND_EDGE
 * @param[in] Copy_BaudRateControl The clock speed to use in Hz. Must be one of the following:
 *                      - SPI_BAUD_RATE_DIV2
 *                      - SPI_BAUD_RATE_DIV4
 *                      - SPI_BAUD_RATE_DIV8
 *                      - SPI_BAUD_RATE_DIV16
 *                      - SPI_BAUD_RATE_DIV32
 *                      - SPI_BAUD_RATE_DIV64
 *                      - SPI_BAUD_RATE_DIV128
 *                      - SPI_BAUD_RATE_DIV256
 */
void SPI_voidInit(SPI_DataFrame_t dataFrame, SPI_ClockPolarity_t clockPolarity,
                  SPI_ClockPhase_t clockPhase, SPI_BaudRateControl_t Copy_BaudRateControl);
       
/**
 * @brief Send and receive data over SPI.
 * 
 * This function sends and receives data over SPI. The data is transmitted and received
 * in full duplex mode.
 * 
 * @param[in] Copy_u8pTxData Pointer to the data to transmit.
 * @param[out] Copy_u8pRxData Pointer to the buffer to receive the data.
 * @param[in] Copy_u16size The number of bytes to transmit and receive.
 */
void SPI_voidTransfer(u8* Copy_u8pTxData, u8* Copy_u8pRxData, u16 Copy_u16size);

/**
 * @}
 */

#endif /* __SPI_INTERFACE_H__ */

