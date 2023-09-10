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




void LEDMTRX_TurnOn(u8 Copy_u8Row, u8 Copy_u8Col)
{
 
}

void LEDMTRX_TurnOff(u8 Copy_u8Row, u8 Copy_u8Col)
{
  
}

void LEDMTRX_Clear(void)
{
  
}

void LEDMTRX_Init(void)
{
  /**< Set Rows as output push-pull with 2MHZ */
  GPIO_SetPinMode(LEDMTRX_ROW0_PIN, GPIO_OUTPUT_PP_2MHZ);
  GPIO_SetPinMode(LEDMTRX_ROW1_PIN, GPIO_OUTPUT_PP_2MHZ);
  GPIO_SetPinMode(LEDMTRX_ROW2_PIN, GPIO_OUTPUT_PP_2MHZ);
  GPIO_SetPinMode(LEDMTRX_ROW3_PIN, GPIO_OUTPUT_PP_2MHZ);
  GPIO_SetPinMode(LEDMTRX_ROW4_PIN, GPIO_OUTPUT_PP_2MHZ);
  GPIO_SetPinMode(LEDMTRX_ROW5_PIN, GPIO_OUTPUT_PP_2MHZ);
  GPIO_SetPinMode(LEDMTRX_ROW6_PIN, GPIO_OUTPUT_PP_2MHZ);
  GPIO_SetPinMode(LEDMTRX_ROW7_PIN, GPIO_OUTPUT_PP_2MHZ);

  /**< Set columns as output push-pull with 2MHZ */
  GPIO_SetPinMode(LEDMTRX_COL0_PIN, GPIO_OUTPUT_PP_2MHZ);
  GPIO_SetPinMode(LEDMTRX_COL1_PIN, GPIO_OUTPUT_PP_2MHZ);
  GPIO_SetPinMode(LEDMTRX_COL2_PIN, GPIO_OUTPUT_PP_2MHZ);
  GPIO_SetPinMode(LEDMTRX_COL3_PIN, GPIO_OUTPUT_PP_2MHZ);
  GPIO_SetPinMode(LEDMTRX_COL4_PIN, GPIO_OUTPUT_PP_2MHZ);
  GPIO_SetPinMode(LEDMTRX_COL5_PIN, GPIO_OUTPUT_PP_2MHZ);
  GPIO_SetPinMode(LEDMTRX_COL6_PIN, GPIO_OUTPUT_PP_2MHZ);
  GPIO_SetPinMode(LEDMTRX_COL7_PIN, GPIO_OUTPUT_PP_2MHZ);
}

void LEDMTRX_Display(u8 *Copy_Data)
{
  /****************************< Column 0 ****************************/
  /**< Disable All Columns */
  LEDMTRX_DisableAllCols();
  /**< Display Column 0 Date */
  LEDMTRX_SetRowValues(Copy_Data[0]);
  /**< Enable Column 0 */
  GPIO_SetPinValue(LEDMTRX_COL0_PIN, GPIO_LOW);
  /**< Delay for 2.5mse */
  STK_SetDelay(2.5);
  /****************************< Column 1 ****************************/
  /**< Disable All Columns */
  LEDMTRX_DisableAllCols();
  /**< Display Column 1 Date */
  HLEDMTRX_voidSetRowValues(Copy_Data[1]);
  /**< Enable Column 1 */
  GPIO_SetPinValue(LEDMTRX_COL1_PIN, GPIO_LOW);
  /**< Delay for 2.5mse */
  STK_SetDelay(2.5);
  /****************************< Column 2 ****************************/
  /**< Disable All Columns */
  LEDMTRX_DisableAllCols();
  /**< Display Column 2 Date */
  HLEDMTRX_voidSetRowValues(Copy_Data[2]);
  /**< Enable Column 2 */
  GPIO_SetPinValue(LEDMTRX_COL2_PIN, GPIO_LOW);
  /**< Delay for 2.5mse */
  STK_SetDelay(2.5);
  /****************************< Column 3 ****************************/
  /**< Disable All Columns */
  LEDMTRX_DisableAllCols();
  /**< Display Column 1 Date */
  HLEDMTRX_voidSetRowValues(Copy_Data[3]);
  /**< Enable Column 1 */
  GPIO_SetPinValue(LEDMTRX_COL3_PIN, GPIO_LOW);
  /**< Delay for 2.5mse */
  STK_SetDelay(2.5);
  /****************************< Column 4 ****************************/
  /**< Disable All Columns */
  LEDMTRX_DisableAllCols();
  /**< Display Column 1 Date */
  HLEDMTRX_voidSetRowValues(Copy_Data[4]);
  /**< Enable Column 1 */
  GPIO_SetPinValue(LEDMTRX_COL4_PIN, GPIO_LOW);
  /**< Delay for 2.5mse */
  STK_SetDelay(2.5);
  /****************************< Column 5 ****************************/
  /**< Disable All Columns */
  LEDMTRX_DisableAllCols();
  /**< Display Column 1 Date */
  HLEDMTRX_voidSetRowValues(Copy_Data[5]);
  /**< Enable Column 1 */
  GPIO_SetPinValue(LEDMTRX_COL5_PIN, GPIO_LOW);
  /**< Delay for 2.5mse */
  STK_SetDelay(2.5);
  /****************************< Column 6 ****************************/
  /**< Disable All Columns */
  LEDMTRX_DisableAllCols();
  /**< Display Column 1 Date */
  HLEDMTRX_voidSetRowValues(Copy_Data[6]);
  /**< Enable Column 1 */
  GPIO_SetPinValue(LEDMTRX_COL6_PIN, GPIO_LOW);
  /**< Delay for 2.5mse */
  STK_SetDelay(2.5);
  /****************************< Column 7 ****************************/
  /**< Disable All Columns */
  LEDMTRX_DisableAllCols();
  /**< Display Column 1 Date */
  HLEDMTRX_voidSetRowValues(Copy_Data[7]);
  /**< Enable Column 1 */
  GPIO_SetPinValue(LEDMTRX_COL7_PIN, GPIO_LOW);
  /**< Delay for 2.5mse */
  STK_SetDelay(2.5); 
  /****************************< Shift left the data ****************************/
  HLEDMTRX_voidShiftLeft(Copy_Data);
  /****************************< Set Delay ****************************/
  STK_SetDelay(500);
}


static void LEDMTRX_DisableAllCols(void)
{
  GPIO_SetPinValue(LEDMTRX_COL0_PIN, GPIO_HIGH);
  GPIO_SetPinValue(LEDMTRX_COL1_PIN, GPIO_HIGH);
  GPIO_SetPinValue(LEDMTRX_COL2_PIN, GPIO_HIGH);
  GPIO_SetPinValue(LEDMTRX_COL3_PIN, GPIO_HIGH);
  GPIO_SetPinValue(LEDMTRX_COL4_PIN, GPIO_HIGH);
  GPIO_SetPinValue(LEDMTRX_COL5_PIN, GPIO_HIGH);
  GPIO_SetPinValue(LEDMTRX_COL6_PIN, GPIO_HIGH);
  GPIO_SetPinValue(LEDMTRX_COL7_PIN, GPIO_HIGH);
}


static void LEDMTRX_SetRowValues(u8 Copy_Value)
{
  u8 Local_BitValue = 0;

  Local_BitValue = GET_BIT(Copy_Value,0);
  GPIO_SetPinValue(LEDMTRX_ROW0_PIN, Local_BitValue);
  Local_BitValue = GET_BIT(Copy_Value,1);
  GPIO_SetPinValue(LEDMTRX_ROW1_PIN, Local_BitValue);
  Local_BitValue = GET_BIT(Copy_Value,2);
  GPIO_SetPinValue(LEDMTRX_ROW2_PIN, Local_BitValue);
  Local_BitValue = GET_BIT(Copy_Value,3);
  GPIO_SetPinValue(LEDMTRX_ROW3_PIN, Local_BitValue);
  Local_BitValue = GET_BIT(Copy_Value,4);
  GPIO_SetPinValue(LEDMTRX_ROW4_PIN, Local_BitValue);
  Local_BitValue = GET_BIT(Copy_Value,5);
  GPIO_SetPinValue(LEDMTRX_ROW5_PIN, Local_BitValue);
  Local_BitValue = GET_BIT(Copy_Value,6);
  GPIO_SetPinValue(LEDMTRX_ROW6_PIN, Local_BitValue);
  Local_BitValue = GET_BIT(Copy_Value,7);
  GPIO_SetPinValue(LEDMTRX_ROW7_PIN, Local_BitValue);
}


void LEDMTRX_ShiftLeft(u8 *Copy_Data)
{
  u8 Local_Temp= 0;

  /**< Save the fist element in of the Data in temp variable */
  Local_Temp = Copy_Data[0];

  /**< Shift data left */ 
  for (u8 Local_u8ColsIterator = 0; Local_u8ColsIterator < LEDMTRX_NUM_COLS; Local_u8ColsIterator++)
  {
    Copy_Data[Local_u8ColsIterator] = Copy_Data[Local_u8ColsIterator+1];
  }

  /**< Set the last column data by the fist one */
  Copy_Data[LEDMTRX_NUM_COLS-1] = Local_Temp;

}


void LEDMTRX_DisplayWithShift(u8 *Copy_Data, u16 Copy_DelayMs)
{
  for(u8 i = 0; i < LEDMTRX_NUM_COLS; i++)
  {
    LEDMTRX_SetRowValues(Copy_Data[i]);
    GPIO_SetPinValue(LEDMTRX_COL0_PIN + i, GPIO_LOW);
    STK_SetDelay(Copy_DelayMs);
    LEDMTRX_DisableAllCols();
    LEDMTRX_ShiftLeft(Copy_Data);
  }
}

