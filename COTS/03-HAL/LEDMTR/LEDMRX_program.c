/**
 * @file LEDMATRIX_program.c
 * @brief This file contains the implementation of the functions for controlling an LED matrix.
 * 
 * The LED matrix can be controlled using the functions provided in this file.
 * 
 * @author Mahmoud Abdelraouf Mahmoud
 * @date 23 Jul 2023
 * @version V01
 */
/*********************< LIB *********************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*********************< MCAL *********************/
#include "GPIO_interface.h"
#include "STK_interface.h"
/*********************< HAL *********************/
#include "LEDMRX_private.h"
#include "LEDMRX_interface.h"
#include "LEDMRX_config.h"




void HLEDMTRX_voidTurnOn(u8 Copy_u8Row, u8 Copy_u8Col)
{
 
}

void HLEDMTRX_voidTurnOff(u8 Copy_u8Row, u8 Copy_u8Col)
{

}


void HLEDMTRX_voidInit(void)
{
  /**< Set Rows as output push-pull with 2MHZ */
  MGPIO_voidSetPinDirection(LEDMTRX_ROW0_PIN,MGPIO_OUTPUT_PP_2MHZ);
  MGPIO_voidSetPinDirection(LEDMTRX_ROW1_PIN,MGPIO_OUTPUT_PP_2MHZ);
  MGPIO_voidSetPinDirection(LEDMTRX_ROW2_PIN,MGPIO_OUTPUT_PP_2MHZ);
  MGPIO_voidSetPinDirection(LEDMTRX_ROW3_PIN,MGPIO_OUTPUT_PP_2MHZ);
  MGPIO_voidSetPinDirection(LEDMTRX_ROW4_PIN,MGPIO_OUTPUT_PP_2MHZ);
  MGPIO_voidSetPinDirection(LEDMTRX_ROW5_PIN,MGPIO_OUTPUT_PP_2MHZ);
  MGPIO_voidSetPinDirection(LEDMTRX_ROW6_PIN,MGPIO_OUTPUT_PP_2MHZ);
  MGPIO_voidSetPinDirection(LEDMTRX_ROW7_PIN,MGPIO_OUTPUT_PP_2MHZ);
  /**< Set columns as output push-pull with 2MHZ */
  MGPIO_voidSetPinDirection(LEDMTRX_COL0_PIN,MGPIO_OUTPUT_PP_2MHZ);
  MGPIO_voidSetPinDirection(LEDMTRX_COL1_PIN,MGPIO_OUTPUT_PP_2MHZ);
  MGPIO_voidSetPinDirection(LEDMTRX_COL2_PIN,MGPIO_OUTPUT_PP_2MHZ);
  MGPIO_voidSetPinDirection(LEDMTRX_COL3_PIN,MGPIO_OUTPUT_PP_2MHZ);
  MGPIO_voidSetPinDirection(LEDMTRX_COL4_PIN,MGPIO_OUTPUT_PP_2MHZ);
  MGPIO_voidSetPinDirection(LEDMTRX_COL5_PIN,MGPIO_OUTPUT_PP_2MHZ);
  MGPIO_voidSetPinDirection(LEDMTRX_COL6_PIN,MGPIO_OUTPUT_PP_2MHZ);
  MGPIO_voidSetPinDirection(LEDMTRX_COL7_PIN,MGPIO_OUTPUT_PP_2MHZ);
}

void HLEDMTRX_voidDisplay(u8 *Copy_pau8Data)
{
  /****************************< Column 0 ****************************/
  /**< Disable All Columns */
  HLEDMTRX_voidDisableAllCols();
  /**< Display Column 0 Date */
  HLEDMTRX_voidSetRowValues(Copy_pau8Data[0]);
  /**< Enable Column 0 */
  MGPIO_voidSetPinValue(LEDMTRX_COL0_PIN,MGPIO_LOW);
  /**< Delay for 2.5mse */
  MSTK_voidSetDelayMs(2.5);
  /****************************< Column 1 ****************************/
  /**< Disable All Columns */
  HLEDMTRX_voidDisableAllCols();
  /**< Display Column 1 Date */
  HLEDMTRX_voidSetRowValues(Copy_pau8Data[1]);
  /**< Enable Column 1 */
  MGPIO_voidSetPinValue(LEDMTRX_COL1_PIN,MGPIO_LOW);
  /**< Delay for 2.5mse */
  MSTK_voidSetDelayMs(2.5);
  /****************************< Column 2 ****************************/
  /**< Disable All Columns */
  HLEDMTRX_voidDisableAllCols();
  /**< Display Column 2 Date */
  HLEDMTRX_voidSetRowValues(Copy_pau8Data[2]);
  /**< Enable Column 2 */
  MGPIO_voidSetPinValue(LEDMTRX_COL2_PIN,MGPIO_LOW);
  /**< Delay for 2.5mse */
  MSTK_voidSetDelayMs(2.5);
  /****************************< Column 3 ****************************/
  /**< Disable All Columns */
  HLEDMTRX_voidDisableAllCols();
  /**< Display Column 1 Date */
  HLEDMTRX_voidSetRowValues(Copy_pau8Data[3]);
  /**< Enable Column 1 */
  MGPIO_voidSetPinValue(LEDMTRX_COL3_PIN,MGPIO_LOW);
  /**< Delay for 2.5mse */
  MSTK_voidSetDelayMs(2.5);
  /****************************< Column 4 ****************************/
  /**< Disable All Columns */
  HLEDMTRX_voidDisableAllCols();
  /**< Display Column 1 Date */
  HLEDMTRX_voidSetRowValues(Copy_pau8Data[4]);
  /**< Enable Column 1 */
  MGPIO_voidSetPinValue(LEDMTRX_COL4_PIN,MGPIO_LOW);
  /**< Delay for 2.5mse */
  MSTK_voidSetDelayMs(2.5);
  /****************************< Column 5 ****************************/
  /**< Disable All Columns */
  HLEDMTRX_voidDisableAllCols();
  /**< Display Column 1 Date */
  HLEDMTRX_voidSetRowValues(Copy_pau8Data[5]);
  /**< Enable Column 1 */
  MGPIO_voidSetPinValue(LEDMTRX_COL5_PIN,MGPIO_LOW);
  /**< Delay for 2.5mse */
  MSTK_voidSetDelayMs(2.5);
  /****************************< Column 6 ****************************/
  /**< Disable All Columns */
  HLEDMTRX_voidDisableAllCols();
  /**< Display Column 1 Date */
  HLEDMTRX_voidSetRowValues(Copy_pau8Data[6]);
  /**< Enable Column 1 */
  MGPIO_voidSetPinValue(LEDMTRX_COL6_PIN,MGPIO_LOW);
  /**< Delay for 2.5mse */
  MSTK_voidSetDelayMs(2.5);
  /****************************< Column 7 ****************************/
  /**< Disable All Columns */
  HLEDMTRX_voidDisableAllCols();
  /**< Display Column 1 Date */
  HLEDMTRX_voidSetRowValues(Copy_pau8Data[7]);
  /**< Enable Column 1 */
  MGPIO_voidSetPinValue(LEDMTRX_COL7_PIN,MGPIO_LOW);
  /**< Delay for 2.5mse */
  MSTK_voidSetDelayMs(2.5); 
  /****************************< Shift left the data ****************************/
  HLEDMTRX_voidShiftLeft(Copy_pau8Data);
  /****************************< Set Delay ****************************/
  MSTK_voidSetDelayMs(500);
}


static void HLEDMTRX_voidDisableAllCols(void)
{
  MGPIO_voidSetPinValue(LEDMTRX_COL0_PIN,MGPIO_HIGH);
  MGPIO_voidSetPinValue(LEDMTRX_COL1_PIN,MGPIO_HIGH);
  MGPIO_voidSetPinValue(LEDMTRX_COL2_PIN,MGPIO_HIGH);
  MGPIO_voidSetPinValue(LEDMTRX_COL3_PIN,MGPIO_HIGH);
  MGPIO_voidSetPinValue(LEDMTRX_COL4_PIN,MGPIO_HIGH);
  MGPIO_voidSetPinValue(LEDMTRX_COL5_PIN,MGPIO_HIGH);
  MGPIO_voidSetPinValue(LEDMTRX_COL6_PIN,MGPIO_HIGH);
  MGPIO_voidSetPinValue(LEDMTRX_COL7_PIN,MGPIO_HIGH);
}


static void HLEDMTRX_voidSetRowValues(u8 Copy_u8Value)
{
  u8 Local_u8BitValue = 0;

  Local_u8BitValue = GET_BIT(Copy_u8Value,0);
  MGPIO_voidSetPinValue(LEDMTRX_ROW0_PIN,Local_u8BitValue);
  Local_u8BitValue = GET_BIT(Copy_u8Value,1);
  MGPIO_voidSetPinValue(LEDMTRX_ROW1_PIN,Local_u8BitValue);
  Local_u8BitValue = GET_BIT(Copy_u8Value,2);
  MGPIO_voidSetPinValue(LEDMTRX_ROW2_PIN,Local_u8BitValue);
  Local_u8BitValue = GET_BIT(Copy_u8Value,3);
  MGPIO_voidSetPinValue(LEDMTRX_ROW3_PIN,Local_u8BitValue);
  Local_u8BitValue = GET_BIT(Copy_u8Value,4);
  MGPIO_voidSetPinValue(LEDMTRX_ROW4_PIN,Local_u8BitValue);
  Local_u8BitValue = GET_BIT(Copy_u8Value,5);
  MGPIO_voidSetPinValue(LEDMTRX_ROW5_PIN,Local_u8BitValue);
  Local_u8BitValue = GET_BIT(Copy_u8Value,6);
  MGPIO_voidSetPinValue(LEDMTRX_ROW6_PIN,Local_u8BitValue);
  Local_u8BitValue = GET_BIT(Copy_u8Value,7);
  MGPIO_voidSetPinValue(LEDMTRX_ROW7_PIN,Local_u8BitValue);
}


void HLEDMTRX_voidShiftLeft(u8 *Copy_pau8Data)
{
  u8 Local_u8Temp= 0;

  /**< Save the fist element in of the Data in temp variable */
  Local_u8Temp = Copy_pau8Data[0];

  /**< Shift data left */ 
  for (u8 Local_u8ColsIterator = 0; Local_u8ColsIterator < LEDMTRX_NUM_COLS; Local_u8ColsIterator++)
  {
    Copy_pau8Data[Local_u8ColsIterator] = Copy_pau8Data[Local_u8ColsIterator+1];
  }

  /**< Set the last column data by the fist one */
  Copy_pau8Data[LEDMTRX_NUM_COLS-1] = Local_u8Temp;

}


void HLEDMTRX_voidDisplayWithShift(u8 *Copy_pau8Data, u16 Copy_u16DelayMs)
{
  for(u8 i = 0; i < LEDMTRX_NUM_COLS; i++)
  {
    HLEDMTRX_voidSetRowValues(Copy_pau8Data[i]);
    MGPIO_voidSetPinValue(LEDMTRX_COL0_PIN + i, MGPIO_LOW);
    MSTK_voidSetDelayMs(Copy_u16DelayMs);
    HLEDMTRX_voidDisableAllCols();
    HLEDMTRX_voidShiftLeft(Copy_pau8Data);
  }
}

