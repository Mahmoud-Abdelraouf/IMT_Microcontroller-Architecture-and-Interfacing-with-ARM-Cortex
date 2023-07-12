/**
 * @brief This module contains functions for configuring the Nested Vectored Interrupt Controller (NVIC).
 *
 * @author Mahmoud Abdelraouf Mahmoud
 * @date 26 Feb 2022
 * @version V01
 *
 * This module provides functions for enabling and disabling interrupts, setting interrupt priorities, and other
 * configuration options for the NVIC. It is designed to be used with ARM Cortex-M processors, and may not be
 * compatible with other architectures.
 *
 * @note This module is intended for use with the STM32F10x microcontroller series, but may be adapted for use with
 * other compatible processors.
 */
/**********************************************< LIB **********************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/**********************************************< MCAL **********************************************/
#include "NVIC_private.h"
#include "NVIC_interface.h"
#include "NVIC_config.h"
/**********************************************< FUNCTIONS IMPLEMENTATION **********************************************/
u8 MNVIC_u8EnableInterrupt(u8 Copy_u8InterruptNumber) 
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
		Local_u8ErrorStatus = 1;		
	}
	return Local_u8ErrorStatus;
}


u8 MNVIC_u8DisableInterrupt(u8 Copy_u8InterruptNumber) 
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
		Local_u8ErrorStatus = 1;		
	}
	return Local_u8ErrorStatus;
}

u8 MNVIC_u8SetPendingFlag(u8 Copy_u8InterruptNumber) 
{
	u8 Local_u8ErrorStatus = 0;
	if(Copy_u8InterruptNumber < 32)
	{
		NVIC_ISPR0 = (1 << Copy_u8InterruptNumber);
	}
	else if(Copy_u8InterruptNumber < 64)
	{
		Copy_u8InterruptNumber -= 32;
		NVIC_ISPR1 = (1 << Copy_u8InterruptNumber);
	}
	else
	{
		Local_u8ErrorStatus = 1;		
	}
	return Local_u8ErrorStatus;
}

u8 MNVIC_u8ClearPendingFlag(u8 Copy_u8InterruptNumber) 
{
	u8 Local_u8ErrorStatus = 0;
	if(Copy_u8InterruptNumber < 32)
	{
		NVIC_ICPR0 = (1 << Copy_u8InterruptNumber);
	}
	else if(Copy_u8InterruptNumber < 64)
	{
		Copy_u8InterruptNumber -= 32;
		NVIC_ICPR1 = (1 << Copy_u8InterruptNumber);
	}
	else
	{
		Local_u8ErrorStatus = 1;		
	}
	return Local_u8ErrorStatus;
}

u8 MNVIC_u8GetActiveFlag(u8 Copy_u8InterruptNumber, u8 *Copy_pu8ReturnValue) 
{
	u8 Local_u8ErrorStatus = 0;
	if(Copy_u8InterruptNumber < 32)
	{
		*Copy_pu8ReturnValue = GET_BIT(NVIC_IABR0, Copy_u8InterruptNumber);
	}
	else if(Copy_u8InterruptNumber < 64)
	{
		Copy_u8InterruptNumber -= 32;
		*Copy_pu8ReturnValue = GET_BIT(NVIC_IABR1, Copy_u8InterruptNumber);
	}
	else
	{
		Local_u8ErrorStatus = 1;		
	}
	return Local_u8ErrorStatus;
}

u8 MNVIC_u8SetPriority(s8 Copy_s8InterruptNumber,u8 Copy_u8GroupPriority, u8 Copy_u8SubGroupPriority, u32 Copy_u32GROUP)
{
	u8 Local_u8ErrorStatus = 0;
	if(Copy_s8InterruptNumber < 60)
	{
		u8 Local_u8Priority =  Copy_u8SubGroupPriority | Copy_u8GroupPriority << ((Copy_u32GROUP - MNVIC_GROUP4_SUB0)/0x100);

		switch (Copy_u32GROUP)
		{
			case MNVIC_GROUP4_SUB0:
				if(Copy_u8GroupPriority < 16 && Copy_u8SubGroupPriority == 0)
				{
					/**< Core Peripheral */
					if(Copy_s8InterruptNumber < 0)
					{
						
					}
					/**< External Peripheral */
					else
					{
						NVIC_IPR[Copy_s8InterruptNumber] = (Local_u8Priority << 4);
						SCB_AIRCR = Copy_u32GROUP;
					}
				}
				else
				{
					Local_u8ErrorStatus = 1;
				}
			break;
			case MNVIC_GROUP3_SUB1:
				if(Copy_u8GroupPriority < 8 && Copy_u8SubGroupPriority < 2)
				{
					/**< Core Peripheral */
					if(Copy_s8InterruptNumber < 0)
					{
						
					}
					/**< External Peripheral */
					else
					{
						NVIC_IPR[Copy_s8InterruptNumber] = (Local_u8Priority << 4);
						SCB_AIRCR = Copy_u32GROUP;
					}
				}
				else
				{
					Local_u8ErrorStatus = 1;
				}
			break;
			case MNVIC_GROUP2_SUB2:
				if(Copy_u8GroupPriority < 4 && Copy_u8SubGroupPriority < 4)
				{
					/**< Core Peripheral */
					if(Copy_s8InterruptNumber < 0)
					{
						
					}
					/**< External Peripheral */
					else
					{
						NVIC_IPR[Copy_s8InterruptNumber] = (Local_u8Priority << 4);
						SCB_AIRCR = Copy_u32GROUP;
					}
				}
				else
				{
					Local_u8ErrorStatus = 1;
				}
			break;
			case MNVIC_GROUP1_SUB3:
				if(Copy_u8GroupPriority < 2 && Copy_u8SubGroupPriority < 8)
				{
					/**< Core Peripheral */
					if(Copy_s8InterruptNumber < 0)
					{
						
					}
					/**< External Peripheral */
					else
					{
						NVIC_IPR[Copy_s8InterruptNumber] = (Local_u8Priority << 4);
						SCB_AIRCR = Copy_u32GROUP;
					}
				}
				else
				{
					Local_u8ErrorStatus = 1;
				}
			break;
			case MNVIC_GROUP0_SUB4:
				if(Copy_u8GroupPriority == 0 && Copy_u8SubGroupPriority < 16)
				{
					/**< Core Peripheral */
					if(Copy_s8InterruptNumber < 0)
					{
						
					}
					/**< External Peripheral */
					else
					{
						NVIC_IPR[Copy_s8InterruptNumber] = (Local_u8Priority << 4);
						SCB_AIRCR = Copy_u32GROUP;
					}
				}
				else
				{
					Local_u8ErrorStatus = 1;
				}
			break;
			default:
				Local_u8ErrorStatus = 1;
			break;
		}
	}
	else
	{
		Local_u8ErrorStatus = 1;
	}
	return Local_u8ErrorStatus;
}