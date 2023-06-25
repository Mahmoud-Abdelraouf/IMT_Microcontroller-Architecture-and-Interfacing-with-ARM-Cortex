/********************************************************************/
/************* Author    : Mahmoud Abdelraouf Mahmoud   *************/
/************* Date		 : 26 Feb 2022                  *************/
/************* Version   : V01                          *************/
/************* Module    : NVIC                         *************/
/********************************************************************/
/**< LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/**< MCAL */
#include "NVIC_private.h"
#include "NVIC_interface.h"
#include "NVIC_config.h"

u8 MNVIC_voidEnableInterrupt(u8 Copy_u8InterruptNumber) 
{
	u8 Local_u8ErrorStatus = 0;
	if(Copy_u8InterruptNumber < 32)
	{
		NVIC_ISER0 = (1 << Copy_u8InterruptNumber);
	}
	else if(Copy_u8InterruptNumber < 64)
	{
		Copy_u8InterruptNumber -= 32;
		NVIC_ISER1 = (1 << Copy_u8InterruptNumber);
	}
	else
	{
		Local_u8ErrorStatus = 1;		/**< RETURN ERROR STATUS */
	}
	return Local_u8ErrorStatus;
}


u8 MNVIC_voidDisableInterrupt(u8 Copy_u8InterruptNumber) 
{
	u8 Local_u8ErrorStatus = 0;
	if(Copy_u8InterruptNumber < 32)
	{
		NVIC_ICER0 = (1 << Copy_u8InterruptNumber);
	}
	else if(Copy_u8InterruptNumber < 64)
	{
		Copy_u8InterruptNumber -= 32;
		NVIC_ICER1 = (1 << Copy_u8InterruptNumber);
	}
	else
	{
		Local_u8ErrorStatus = 1;		/**< RETURN ERROR STATUS */
	}
	return Local_u8ErrorStatus;
}