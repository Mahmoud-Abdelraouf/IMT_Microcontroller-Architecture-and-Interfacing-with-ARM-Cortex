/**
 * @brief This module contains functions for configuring and controlling General Purpose Input/Output (GPIO) pins.
 *
 * @author Mahmoud Abdelraouf Mahmoud
 * @date 26 Feb 2022
 * @version V01
 *
 * This module provides functions for configuring the mode, speed, and pull-up/down resistors of GPIO pins,
 * as well as reading and writing their values. It is designed to be used with ARM Cortex-M processors, and may not be
 * compatible with other architectures.
 *
 * @note This module is intended for use with the STM32F10x microcontroller series, but may be adapted for use with
 * other compatible processors.
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

void MGPIO_voidSetPinDirection(u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8Mode)
{
	switch(Copy_u8PORT)
	{
		case MGPIOA:
			if(Copy_u8PIN < 8)
			{
				MGPIOA_CRL_R &= ~((0b1111) << (Copy_u8PIN * 4));
				MGPIOA_CRL_R |= ((Copy_u8Mode) << (Copy_u8PIN * 4));
			}
			else if(Copy_u8PIN < 16)
			{
				Copy_u8PIN-=8;
				MGPIOA_CRH_R &= ~((0b1111) << (Copy_u8PIN * 4));
			    MGPIOA_CRH_R |= ((Copy_u8Mode) << (Copy_u8PIN * 4));
			}
			else
			{
				/**< RETURN ERROR STATUS */
			}
		break;
		case MGPIOB:
			if(Copy_u8PIN < 8)
			{
				MGPIOB_CRL_R &= ~((0b1111) << (Copy_u8PIN * 4));
				MGPIOB_CRL_R |= ((Copy_u8Mode) << (Copy_u8PIN * 4));
			}
			else if(Copy_u8PIN < 16)
			{
				Copy_u8PIN-=8;
				MGPIOB_CRH_R &=~ ((0b1111) << (Copy_u8PIN * 4));
				MGPIOB_CRH_R |= ((Copy_u8Mode) << (Copy_u8PIN * 4));
			}
			else
			{
				/**< RETURN ERROR STATUS */
			}
		break;
		case MGPIOC:
			if(Copy_u8PIN < 8)
			{
				MGPIOC_CRL_R &=~ ((0b1111) << (Copy_u8PIN * 4));
				MGPIOC_CRL_R |= ((Copy_u8Mode) << (Copy_u8PIN * 4));
			}
			else if(Copy_u8PIN < 16)
			{
				Copy_u8PIN-=8;
				MGPIOC_CRH_R &=~ ((0b1111) << (Copy_u8PIN * 4));
				MGPIOC_CRH_R |= ((Copy_u8Mode) << (Copy_u8PIN * 4));
			}
			else
			{
				/**< RETURN ERROR STATUS */
			}
		break;
		default:
			/**< RETURN ERROR STATUS */
		break;
	}
	/**< RETURN ERRORSTATUS */
}

void MGPIO_voidSetPinValue(u8 Copy_u8PORT,u8 Copy_u8PIN, u8 Copy_u8Value)
{
	if(Copy_u8PIN < 16)
	{
		switch(Copy_u8PORT)
		{
			case MGPIOA:
				if(Copy_u8Value == MGPIO_HIGH)
				{
					SET_BIT(MGPIOA_ODR_R, Copy_u8PIN);
				}
				else if(Copy_u8Value == MGPIO_LOW)
				{
					CLR_BIT(MGPIOA_ODR_R, Copy_u8PIN);
				}
				else
				{
					/**< RETURN ERROR STATUS */
				}
			break;
			case MGPIOB:
				if(Copy_u8Value == MGPIO_HIGH)
				{
					SET_BIT(MGPIOB_ODR_R, Copy_u8PIN);
				}
				else if(Copy_u8Value == MGPIO_LOW)
				{
					CLR_BIT(MGPIOB_ODR_R, Copy_u8PIN);
				}
				else
				{
					/**< RETURN ERROR STATUS */
				}
			break;
			case MGPIOC:
				if(Copy_u8Value == MGPIO_HIGH)
				{
					SET_BIT(MGPIOC_ODR_R, Copy_u8PIN);
				}
				else if(Copy_u8Value == MGPIO_LOW)
				{
					CLR_BIT(MGPIOC_ODR_R, Copy_u8PIN);
				}
				else
				{
					/**< RETURN ERROR STATUS */
				}
			break;
			default:
				/**< RETURN ERROR STATUS */
			break;
		}
	}
	else
	{
		/**< RETURN ERROR STATUS */
	}
	/**< RETURN ERROR STATUS */
}

u8  MGPIO_u8GetPinValue(u8 Copy_u8PORT, u8 Copy_u8PIN)
{
	u8 Local_u8ReturnPinValue = 0;
	if(Copy_u8PIN < 16)
	{
		switch(Copy_u8PORT)
		{
			case MGPIOA: Local_u8ReturnPinValue = GET_BIT(MGPIOA_IDR_R, Copy_u8PIN); break;
			case MGPIOB: Local_u8ReturnPinValue = GET_BIT(MGPIOB_IDR_R, Copy_u8PIN); break;
			case MGPIOC: Local_u8ReturnPinValue = GET_BIT(MGPIOC_IDR_R, Copy_u8PIN); break;
		}
	}
	else
	{
		/**< RETURN ERROR STATUS */
	}
	return Local_u8ReturnPinValue;
}
