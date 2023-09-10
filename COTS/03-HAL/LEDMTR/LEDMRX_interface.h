/**
 * @file LEDMATRIX_interface.h
 * @brief This file contains the interface functions for controlling an LED matrix.
 * 
 * The LED matrix can be controlled using the functions provided in this file.
 * 
 * @author Mahmoud Abdelraouf Mahmoud
 * @date 23 Jul 2023
 * @version V01
 */
#ifndef __LEDMATRIX_INTERFACE_H__
#define __LEDMATRIX_INTERFACE_H__
/**
 * @brief Turn on an LED at a specific row and column in the LED matrix.
 * 
 * This function turns on the LED at the specified row and column in the LED matrix.
 * 
 * @param Copy_u8Row The row number of the LED to turn on (0-indexed).
 * @param Copy_u8Col The column number of the LED to turn on (0-indexed).
 * @return None.
 */
void HLEDMTRX_voidTurnOn(u8 Copy_u8Row, u8 Copy_u8Col);

/**
 * @brief Turn off an LED at a specific row and column in the LED matrix.
 * 
 * This function turns off the LED at the specified row and column in the LED matrix.
 * 
 * @param Copy_u8Row The row number of the LED to turn off (0-indexed).
 * @param Copy_u8Col The column number of the LED to turn off (0-indexed).
 * @return None.
 */
void LEDMTRX_TurnOff(u8 Copy_Row, u8 Copy_Col);

/**
 * @brief Clear all LEDs in the LED matrix.
 * 
 * This function turns off all LEDs in the LED matrix.
 * 
 * @return None.
 */
void LEDMTRX_Clear(void);

/**
 * @brief Initialize the LED matrix.
 * 
 * This function initializes the LED matrix with the default settings.
 * 
 * @return None.
 */
void LEDMTRX_Init(void);

/**
 * @brief Displays data on the LED Matrix.
 *
 * This function displays data on the LED Matrix by enabling one column at a time and setting
 * the values for the rows. It uses an array of 8 bytes to represent the data for each column.
 * The function shifts the data to the left after displaying all columns, creating a scrolling
 * effect.
 *
 * @param Copy_pau8Data Pointer to an array of 8 bytes representing the data for each column.
 *
 * @return void
 */
void LEDMTRX_Display(u8 *Copy_pau8Data);

/**
 * @brief Set the state of an LED at a specific row and column in the LED matrix.
 * 
 * This function sets the state of the LED at the specified row and column in the LED matrix.
 * 
 * @param row The row number of the LED (0-indexed).
 * @param col The column number of the LED (0-indexed).
 * @param state The state to set the LED to (0 for off, 1 for on).
 * @return None.
 */
void LEDMTRX_SetLedState(u8 row, u8 col, u8 state);

/**
 * @brief Shift the LED matrix display to the left by one column.
 * 
 * This function shifts the LED matrix display to the left by one column.
 * 
 * @return None.
 */
void LEDMTRX_ShiftLeft(u8 *Copy_pau8Data);

/**
 * @brief Set the state of a specific row in the LED matrix.
 * 
 * This function sets the state of all LEDs in a specific row of the LED matrix.
 * 
 * @param row The row number to set the state for (0-indexed).
 * @param state The state to set the row to (0 for off, 1 for on).
 * @return None.
 */
void LEDMTRX_SetRowState(u8 row, u8 state);

#endif /**< __LEDMATRIX_INTERFACE_H__ */
