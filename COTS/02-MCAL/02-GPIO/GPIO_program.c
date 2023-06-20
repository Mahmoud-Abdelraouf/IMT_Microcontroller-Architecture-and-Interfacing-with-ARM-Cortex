/********************************************************************/
/************* Author    : Mahmoud Abdelraouf Mahmoud   *************/
/************* Date		 : 26 Feb 2022                  *************/
/************* Version   : V01                          *************/
/************* Module    : GPIO                         *************/
/********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

void GPIO_voidSetPinDirection(u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8Mode)
{
	switch(Copy_u8PORT)
	{
		case GPIOA:
			if(Copy_u8PIN < 8)
			{
				GPIOA_CRL_R &=~ ((0b1111) << (Copy_u8PIN * 4));
				GPIOA_CRL_R |= ((Copy_u8Mode) << (Copy_u8PIN * 4));
			}
			else if(Copy_u8PIN < 16)
			{
				Copy_u8PIN-=8;
				GPIOA_CRH_R &=~ ((0b1111) << (Copy_u8PIN * 4));
			    GPIOA_CRH_R |= ((Copy_u8Mode) << (Copy_u8PIN * 4));
			}
			else
			{
				/**< RETURN ERROR STATUS */
			}
		break;
		case GPIOB:
			if(Copy_u8PIN < 8)
			{
				GPIOB_CRL_R &=~ ((0b1111) << (Copy_u8PIN * 4));
				GPIOB_CRL_R |= ((Copy_u8Mode) << (Copy_u8PIN * 4));
			}
			else if(Copy_u8PIN < 16)
			{
				Copy_u8PIN-=8;
				GPIOB_CRH_R &=~ ((0b1111) << (Copy_u8PIN * 4));
				GPIOB_CRH_R |= ((Copy_u8Mode) << (Copy_u8PIN * 4));
			}
			else
			{
				/**< RETURN ERROR STATUS */
			}
		break;
		case GPIOC:
			if(Copy_u8PIN < 8)
			{
				GPIOC_CRL_R &=~ ((0b1111) << (Copy_u8PIN * 4));
				GPIOC_CRL_R |= ((Copy_u8Mode) << (Copy_u8PIN * 4));
			}
			else if(Copy_u8PIN < 16)
			{
				Copy_u8PIN-=8;
				GPIOC_CRH_R &=~ ((0b1111) << (Copy_u8PIN * 4));
				GPIOC_CRH_R |= ((Copy_u8Mode) << (Copy_u8PIN * 4));
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

void GPIO_voidSetPinValue(u8 Copy_u8PORT,u8 Copy_u8PIN, u8 Copy_u8Value)
{
	if(Copy_u8PIN < 16)
	{
		switch(Copy_u8PORT)
		{
			case GPIOA:
				if(Copy_u8Value == GPIO_HIGH)
				{
					SET_BIT(GPIOA_ODR_R, Copy_u8PIN);
				}
				else if(Copy_u8Value == GPIO_LOW)
				{
					CLR_BIT(GPIOA_ODR_R, Copy_u8PIN);
				}
				else
				{
					/**< RETURN ERROR STATUS */
				}
			break;
			case GPIOB:
				if(Copy_u8Value == GPIO_HIGH)
				{
					SET_BIT(GPIOB_ODR_R, Copy_u8PIN);
				}
				else if(Copy_u8Value == GPIO_LOW)
				{
					CLR_BIT(GPIOB_ODR_R, Copy_u8PIN);
				}
				else
				{
					/**< RETURN ERROR STATUS */
				}
			break;
			case GPIOC:
				if(Copy_u8Value == GPIO_HIGH)
				{
					SET_BIT(GPIOC_ODR_R, Copy_u8PIN);
				}
				else if(Copy_u8Value == GPIO_LOW)
				{
					CLR_BIT(GPIOC_ODR_R, Copy_u8PIN);
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

u8  GPIO_u8GetPinValue(u8 Copy_u8PORT, u8 Copy_u8PIN)
{
	u8 Local_u8ReturnPinValue = 0;
	if(Copy_u8PIN < 16)
	{
		switch(Copy_u8PORT)
		{
			case GPIOA: Local_u8ReturnPinValue = GET_BIT(GPIOA_IDR_R, Copy_u8PIN); break;
			case GPIOB: Local_u8ReturnPinValue = GET_BIT(GPIOB_IDR_R, Copy_u8PIN); break;
			case GPIOC: Local_u8ReturnPinValue = GET_BIT(GPIOC_IDR_R, Copy_u8PIN); break;
		}
	}
	else
	{
		/**< RETURN ERROR STATUS */
	}
	return Local_u8ReturnPinValue;
}
