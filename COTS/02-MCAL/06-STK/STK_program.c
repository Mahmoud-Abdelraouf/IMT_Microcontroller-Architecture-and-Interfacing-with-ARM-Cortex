/**
 * @file STK_program.c
 * @brief This file contains the implementation of the SysTick timer module functions.
 *
 * @copyright Copyright (c) 2023
 * 
 * This module provides functions for configuring and using the SysTick timer in the STM32F10xx microcontroller.
 *
 * @date 06 Jul 2023
 * @version V01
 * @author Mahmoud Abdelraouf Mahmoud
 */

/*********************< LIB *********************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*********************< MCAL *********************/
#include "STK_private.h"
#include "STK_interface.h"
#include "STK_config.h"

static void (*STK_pfCallback)(void) = NULL;

void MSTK_voidInit(u32 Copy_u32LoadValue)
{
    /**< Disable SysTick timer */
    STK->CTRL &= ~STK_CTRL_ENABLE_MASK;
    /**< Configure SysTick timer to use the processor clock and generate interrupt when it reaches zero */
    #if STK_CTRL_CLKSOURCE == STK_CTRL_CLKSOURCE_1
        STK -> CTRL |= STK_CTRL_CLKSOURCE_MASK;             /**< Set bit 2 to use the processor clock */
    #elif STK_CTRL_CLKSOURCE == STK_CTRL_CLKSOURCE_8
        STK->CTRL &= ~STK_CTRL_CLKSOURCE_MASK;             /**< Clear bit 2 to use the processor clock/8 */
    #else "WRONG CHOICE FOR SYSTICK CLOCK SOURCE"
    #endif
    #if STK_CTRL_TICKINT == STK_CTRL_TICKINT_ENABLE
        STK->CTRL |= STK_CTRL_TICKINT_MASK;      /**< Set bit 1 to enable interrupt when the counter reaches zero */
    #elif STK_CTRL_TICKINT == STK_CTRL_TICKINT_DISABLE
        STK->CTRL &= ~STK_CTRL_TICKINT_MASK;      /**< Clear bit 1 to enable interrupt when the counter reaches zero */
    #else
        #error "WRONG OPTION"
    #endif
    /**< Set the reload value for the SysTick timer */
    STK -> LOAD = Copy_u32LoadValue;
    
}

void MSTK_voidStart(void)
{
    /* Start the SysTick timer */
    STK->CTRL |= STK_CTRL_ENABLE_MASK;
}

void MSTK_voidStop(void)
{
    /* Stop the SysTick timer */
    STK->CTRL &= ~STK_CTRL_ENABLE_MASK;
}

void MSTK_voidReset(void)
{
    /**< Disable SysTick timer */
    STK->CTRL = 0;
    /**< Clear the current value */
    STK->VAL = 0;
    /**< Set the reload value to 0 */
    STK->LOAD = 0;
    /**< Clear the count flag */
    STK->CTRL &= ~STK_CTRL_COUNTFLAG_MASK;
}


u32 MSTK_u32GetCount(void)
{
    /* Get the current value of the SysTick timer */
    return STK->VAL;
}

void MSTK_voidSetBusyWait(u32 Copy_u32Microseconds)
{
    /**< Calculate the number of ticks required to wait for the specified number of microseconds */
    u32 ticks = (Copy_u32Microseconds * STK_AHB_CLK) / 1000000;

    /**< Wait for the specified number of ticks using the SysTick timer */
    STK->LOAD = ticks;
    STK->CTRL |= STK_CTRL_ENABLE_MASK;              /**< Enable SysTick timer */
    while (!(STK->CTRL & STK_CTRL_COUNTFLAG_MASK)); /**< Wait until the SysTick timer reach to zero */
    STK->CTRL &= ~STK_CTRL_ENABLE_MASK;             /**< Disable SysTick timer */
}

void MSTK_voidSetIntervalSingle(u32 Copy_u32Microseconds, void (*Copy_pfCallback)(void))
{
    /**< Save the callback function pointer */
    STK_pfCallback = Copy_pfCallback;

    /* Calculate the number of ticks required to wait for the specified number of microseconds */
    u32 ticks = (Copy_u32Microseconds * STK_AHB_CLK) / 1000000;

    /* Set the reload value for the SysTick timer */
    STK->LOAD = ticks;

    /* Start the SysTick timer and enable the interrupt */
    STK->CTRL |= STK_CTRL_ENABLE_MASK;
    STK->CTRL |= STK_CTRL_TICKINT_MASK;
}

void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Microseconds, void (*Copy_pfCallback)(void))
{
    /* Save the callback function pointer */
    STK_pfCallback = Copy_pfCallback;

    /* Calculate the number of ticks required to wait for the specified number of microseconds */
    u32 ticks = (Copy_u32Microseconds * STK_AHB_CLK) / 1000000;

    /* Set the reload value for the SysTick timer */
    STK->LOAD = ticks;

    /* Start the SysTick timer */
    STK->CTRL |= STK_CTRL_ENABLE_MASK;
    STK->CTRL |= STK_CTRL_TICKINT_MASK;
    #if STK_CTRL_CLKSOURCE == STK_CTRL_CLKSOURCE_1
    STK -> CTRL |= STK_CTRL_CLKSOURCE_MASK;             /**< Set bit 2 to use the processor clock */
    #elif STK_CTRL_CLKSOURCE == STK_CTRL_CLKSOURCE_8
        STK-> CTRL &= ~STK_CTRL_CLKSOURCE_MASK;             /**< Clear bit 2 to use the processor clock/8 */
    #else 
        #error "WRONG CHOICE FOR SYSTICK CLOCK SOURCE"
    #endif
}

void SysTick_Handler(void)
{
    /**< Call the callback function */
    if (STK_pfCallback != NULL)
    {
        STK_pfCallback();
    }
}






