/*******************************************************/
/***** Author    : Mahmoud Abdelraouf Mahmoud   ********/
/***** Date		 : 25 Feb 2022                  ********/
/***** Version   : V01                          ********/
/*******************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void RCC_voidInitSysClock()
{
	#if 	RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
		RCC_CR = 0x00010000; /*Enable HSI with no bypass*/
	#elif	RCC_CLOCK_TYPE == RCC_HSE_RC
		RCC_CR = 0x00050000; /*Enable HSI with bypass*/
	#elif	RCC_CLOCK_TYPE == RCC_HSI
		RCC_CR = 0x00000101; /* Enable HSI + Trimming = 0 */
	#elif	RCC_CLOCK_TYPE == RCC_PLL
		
	#else
		#error("You chosed Wrong Clock type!!")
	#endif
	
	
}


void RCC_voidEnableClock(u8 Copy_u8BusId,Copy_u8PeriphId)
{
	if(Copy_u8PeriphId <=31)
	{
		switch(Copy_u8BusId)
		{
			case RCC_AHB  : SET_BIT(RCC_AHBENR,Copy_u8PeriphId);  break;
			case RCC_APB1 : SET_BIT(RCC_APB1ENR,Copy_u8PeriphId); break;
			case RCC_APB2 : SET_BIT(RCC_APB2ENR,Copy_u8PeriphId); break;
			//default       : /* Return Error */                  break;
		}
	}
	else
	{
		//Return Error
	}
}


void RCC_voidDisableClock(u8 Copy_u8BusId,Copy_u8PeriphId)
{
	if(Copy_u8PeriphId <=31)
	{
		switch(Copy_u8BusId)
		{
			case RCC_AHB  : CLR_BIT(RCC_AHBENR,Copy_u8PeriphId);  break;
			case RCC_APB1 : CLR_BIT(RCC_APB1ENR,Copy_u8PeriphId); break;
			case RCC_APB2 : CLR_BIT(RCC_APB2ENR,Copy_u8PeriphId); break;
			//default       : /* Return Error */                    break;
		}
	}
	else
	{
		//Return Error
	}
}