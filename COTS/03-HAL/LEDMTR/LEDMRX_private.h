/**
 * @file LEDMATRIX_private.h
 * @brief This file contains the private functions and definitions for controlling an LED matrix.
 * 
 * The LED matrix can be controlled using the functions provided in the interface file.
 * 
 * @note This file should not be included or used directly by user code.
 * 
 * @author Mahmoud Abdelraouf Mahmoud
 * @date 23 Jul 2023
 * @version V01
 */
#ifndef __LEDMATRIX_PRIVATE_H__
#define __LEDMATRIX_PRIVATE_H__


static void HLEDMTRX_voidDisableAllCols(void);

static void HLEDMTRX_voidSetRowValues(u8 Copy_u8Value);

/*****************************< Concatenate function *****************************/
#define Conc(NUM)			Conc_Help(NUM)
#define Conc_Help(NUM)		LEDMTRX_COL##NUM##_PIN
/***************************< End Concatenate function ***************************/

#endif /**< __LEDMATRIX_PRIVATE_H__ */ 


