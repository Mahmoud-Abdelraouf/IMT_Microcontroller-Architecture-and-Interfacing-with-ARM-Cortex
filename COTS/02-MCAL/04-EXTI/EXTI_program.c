/**
 * @brief This module contains functions for configuring and controlling the External Interrupt (EXTI) peripheral.
 *
 * @author Mahmoud Abdelraouf Mahmoud
 * @date 02 Jul 2023
 * @version V01
 *
 * This module provides functions for configuring the interrupt source, trigger type, and enabling/disabling EXTI lines.
 * It also includes functions for clearing the EXTI pending flag and getting the interrupt status. It is designed to be
 * used with ARM Cortex-M processors, and may not be compatible with other architectures.
 *
 * @note This module is intended for use with the STM32F10x microcontroller series, but may be adapted for use with
 * other compatible processors.
 */
/**< LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/**< MCAL */
#include "EXTI_private.h"
#include "EXTI_interface.h"
#include "EXTI_config.h"

/**< FUNCTIONS IMPLEMENTATION */
void MEXTI_voidInit()
{
	/**< SELECT THE MODE */
    #if EXTI_MODE == RISING
        SET_BIT(EXTI -> RTSR, EXTI_LINE);
    #elif EXTI_MODE == FALLING
        SET_BIT(EXTI -> FTSR, EXTI_LINE);
    #elif EXTI_MODE == ON_CHANGE
        SET_BIT(EXTI -> RTSR, EXTI_LINE);
        SET_BIT(EXTI -> FTSR, EXTI_LINE);
    #else    
        #error "YOU CHOSE WRONG MODE"
    #endif
	/**< DISABLE INTERRUPT */
	CLR_BIT(EXTI -> IMR, EXTI_LINE);
}



u8 MEXTI_u8EnableEXTI(Copy_u8Line)
{
	u8 Local_u8ErrorStatus = 0;
	if(Copy_u8Line < 20)
	{
		SET_BIT(EXTI->IMR, Copy_u8Line);
	}
	else
	{
		Local_u8ErrorStatus = 1;
	}
	return Local_u8ErrorStatus;
}


u8 MEXTI_u8DisableEXTI(Copy_u8Line)
{
	u8 Local_u8ErrorStatus = 0;
	if(Copy_u8Line < 20)
	{
		CLR_BIT(EXTI -> IMR, Copy_u8Line);
	}
	else
	{
		Local_u8ErrorStatus = 1;
	}
	return Local_u8ErrorStatus;
}

u8 MEXTI_u8SwTrigger(u8 Copy_u8Line)
{
	u8 Local_u8ErrorStatus = 0;
	if(Copy_u8Line < 20)
	{
		CLR_BIT(EXTI -> SWIER, Copy_u8Line);
	}
	else
	{
		Local_u8ErrorStatus = 1;
	}
	return Local_u8ErrorStatus;
}

u8 MEXTI_u8SetSignalLatch(u8 Copy_u8Line, u8 Copy_u8Mode)
{
	u8 Local_u8ErrorStatus = 0;
	switch (Copy_u8Mode)
	{
		case RISING		: 
			SET_BIT(EXTI -> RTSR, EXTI_LINE);
		 break;
		case FALLING	: 
			SET_BIT(EXTI -> FTSR, EXTI_LINE);	
		break;
		case ON_CHANGE	: 
			SET_BIT(EXTI -> RTSR, EXTI_LINE);
			SET_BIT(EXTI -> FTSR, EXTI_LINE);			
		break;
		default:
			Local_u8ErrorStatus = 1;
		break;
	}
	return Local_u8ErrorStatus;
}
