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

void GPIO_SetPinMode(u8 Copy_PORT, u8 Copy_PIN, u8 Copy_Mode)
{
	switch(Copy_PORT)
	{
		case GPIO_PORTA:
			if(Copy_PIN < 8)
			{
				GPIOA_CRL_R &= ~((0b1111) << (Copy_PIN * 4));
				GPIOA_CRL_R |= ((Copy_Mode) << (Copy_PIN * 4));
			}
			else if(Copy_PIN < 16)
			{
				Copy_PIN-=8;
				GPIOA_CRH_R &= ~((0b1111) << (Copy_PIN * 4));
			    GPIOA_CRH_R |= ((Copy_Mode) << (Copy_PIN * 4));
			}
			else
			{
				/**< RETURN ERROR STATUS */
			}
		break;
		case GPIO_PORTB:
			if(Copy_PIN < 8)
			{
				GPIOB_CRL_R &= ~((0b1111) << (Copy_PIN * 4));
				GPIOB_CRL_R |= ((Copy_Mode) << (Copy_PIN * 4));
			}
			else if(Copy_PIN < 16)
			{
				Copy_PIN-=8;
				GPIOB_CRH_R &=~ ((0b1111) << (Copy_PIN * 4));
				GPIOB_CRH_R |= ((Copy_Mode) << (Copy_PIN * 4));
			}
			else
			{
				/**< RETURN ERROR STATUS */
			}
		break;
		case GPIO_PORTC:
			if(Copy_PIN < 8)
			{
				GPIOC_CRL_R &=~ ((0b1111) << (Copy_PIN * 4));
				GPIOC_CRL_R |= ((Copy_Mode) << (Copy_PIN * 4));
			}
			else if(Copy_PIN < 16)
			{
				Copy_PIN-=8;
				GPIOC_CRH_R &=~ ((0b1111) << (Copy_PIN * 4));
				GPIOC_CRH_R |= ((Copy_Mode) << (Copy_PIN * 4));
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

void GPIO_SetPinValue(u8 Copy_PORT,u8 Copy_PIN, u8 Copy_Value)
{
	if(Copy_PIN < 16)
	{
		switch(Copy_PORT)
		{
			case GPIO_PORTA:
				if(Copy_Value == GPIO_HIGH)
				{
					SET_BIT(GPIOA_ODR_R, Copy_PIN);
				}
				else if(Copy_Value == GPIO_LOW)
				{
					CLR_BIT(GPIOA_ODR_R, Copy_PIN);
				}
				else
				{
					/**< RETURN ERROR STATUS */
				}
			break;
			case GPIO_PORTB:
				if(Copy_Value == GPIO_HIGH)
				{
					SET_BIT(GPIOB_ODR_R, Copy_PIN);
				}
				else if(Copy_Value == GPIO_LOW)
				{
					CLR_BIT(GPIOB_ODR_R, Copy_PIN);
				}
				else
				{
					/**< RETURN ERROR STATUS */
				}
			break;
			case GPIO_PORTC:
				if(Copy_Value == GPIO_HIGH)
				{
					SET_BIT(GPIOC_ODR_R, Copy_PIN);
				}
				else if(Copy_Value == GPIO_LOW)
				{
					CLR_BIT(GPIOC_ODR_R, Copy_PIN);
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

u8  MGPIO_u8GetPinValue(u8 Copy_PORT, u8 Copy_PIN)
{
	u8 Local_u8ReturnPinValue = 0;
	if(Copy_PIN < 16)
	{
		switch(Copy_PORT)
		{
			case GPIO_PORTA: Local_u8ReturnPinValue = GET_BIT(GPIOA_IDR_R, Copy_PIN); break;
			case GPIO_PORTB: Local_u8ReturnPinValue = GET_BIT(GPIOB_IDR_R, Copy_PIN); break;
			case GPIO_PORTC: Local_u8ReturnPinValue = GET_BIT(GPIOC_IDR_R, Copy_PIN); break;
		}
	}
	else
	{
		/**< RETURN ERROR STATUS */
	}
	return Local_u8ReturnPinValue;
}
