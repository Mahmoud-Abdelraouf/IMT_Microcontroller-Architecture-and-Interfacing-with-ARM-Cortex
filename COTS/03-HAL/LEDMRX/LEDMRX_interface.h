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
 * @param row The row number of the LED to turn on (0-indexed).
 * @param col The column number of the LED to turn on (0-indexed).
 * @return None.
 */
void LEDMRX_voidTurnOn(u8 row, u8 col);

/**
 * @brief Turn off an LED at a specific row and column in the LED matrix.
 * 
 * This function turns off the LED at the specified row and column in the LED matrix.
 * 
 * @param row The row number of the LED to turn off (0-indexed).
 * @param col The column number of the LED to turn off (0-indexed).
 * @return None.
 */
void LEDMRX_voidTurnOff(u8 row, u8 col);

/**
 * @brief Clear all LEDs in the LED matrix.
 * 
 * This function turns off all LEDs in the LED matrix.
 * 
 * @return None.
 */
void LEDMRX_voidClear(void);

/**
 * @brief Initialize the LED matrix.
 * 
 * This function initializes the LED matrix with the default settings.
 * 
 * @return None.
 */
void LEDMRX_voidInit(void);

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
void LEDMRX_voidSetLedState(u8 row, u8 col, u8 state);

/**
 * @brief Shift the LED matrix display to the left by one column.
 * 
 * This function shifts the LED matrix display to the left by one column.
 * 
 * @return None.
 */
void LEDMRX_voidShiftLeft(void);

/**
 * @brief Set the state of a specific row in the LED matrix.
 * 
 * This function sets the state of all LEDs in a specific row of the LED matrix.
 * 
 * @param row The row number to set the state for (0-indexed).
 * @param state The state to set the row to (0 for off, 1 for on).
 * @return None.
 */
void LEDMRX_voidSetRowState(u8 row, u8 state);

#endif /**< __LEDMATRIX_INTERFACE_H__ */
