/**
 * @file LEDMATRIX_config.h
 * @brief This file contains the configuration parameters for the LED matrix.
 * 
 * The LED matrix configuration can be customized by modifying the values in this file.
 * 
 * @note This file should be included by the user code.
 * 
 * @author Mahmoud Abdelraouf Mahmoud
 * @date 23 Jul 2023
 * @version V01
 */

#ifndef __LEDMATRIX_CONFIG_H__
#define __LEDMATRIX_CONFIG_H__

/**
 * @brief The number of rows in the LED matrix.
 * 
 * This parameter specifies the number of rows in the LED matrix.
 * 
 * @note This value must match the physical number of rows in the LED matrix.
 */
#define LEDMTRX_NUM_ROWS 8

/**
 * @brief The number of columns in the LED matrix.
 * 
 * This parameter specifies the number of columns in the LED matrix.
 * 
 * @note This value must match the physical number of columns in the LED matrix.
 */
#define LEDMTRX_NUM_COLS 8



/**
 * @brief Defines the pin pairs used for LED matrix row output.
 *
 * These pin definitions are used for writing the output pins for an LED matrix row.
 *
 * @note The available options for each LEDMRX_ROW0_PIN are:
 *       - MGPIOAX, Y, where X is the port letter (e.g., A, B, C, etc.) and Y is the pin number (0-15).
 */
#define LEDMTRX_ROW0_PIN                 MGPIOA, 0
#define LEDMTRX_ROW1_PIN                 MGPIOA, 1
#define LEDMTRX_ROW2_PIN                 MGPIOA, 2
#define LEDMTRX_ROW3_PIN                 MGPIOA, 3
#define LEDMTRX_ROW4_PIN                 MGPIOA, 4
#define LEDMTRX_ROW5_PIN                 MGPIOA, 5
#define LEDMTRX_ROW6_PIN                 MGPIOA, 6
#define LEDMTRX_ROW7_PIN                 MGPIOA, 7



/**
 * @brief Defines the pin pairs used for LED matrix column output.
 *
 * These pin definitions are used for writing the output pins for an LED matrix column.
 *
 * @note The available options for each LEDMRX_COL_PIN are:
 *       - MGPIOAX, Y, where X is the port letter (e.g., A, B, C, etc.) and Y is the pin number (0-15).
 */
#define LEDMTRX_COL0_PIN                 MGPIOB, 0
#define LEDMTRX_COL1_PIN                 MGPIOB, 1
#define LEDMTRX_COL2_PIN                 MGPIOB, 5
#define LEDMTRX_COL3_PIN                 MGPIOB, 6
#define LEDMTRX_COL4_PIN                 MGPIOB, 7
#define LEDMTRX_COL5_PIN                 MGPIOB, 8
#define LEDMTRX_COL6_PIN                 MGPIOB, 9
#define LEDMTRX_COL7_PIN                 MGPIOB, 10




#endif /**< __LEDMATRIX_CONFIG_H__ */ 


