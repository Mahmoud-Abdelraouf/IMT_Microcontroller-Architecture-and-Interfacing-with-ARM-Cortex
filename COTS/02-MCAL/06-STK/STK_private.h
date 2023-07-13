/**
 * @file STK_private.h
 * @brief This file contains the private interface for the SysTick module.
 *
 * @copyright Copyright (c) 2023
 * 
 * This module provides low-level functions for configuring and controlling the SysTick timer in the ARM Cortex-M processor.
 * The SysTick timer can be used for various timing and synchronization purposes in embedded systems.
 *
 * @note This module is designed to be used with ARM Cortex-M processors, and may not be compatible with other architectures.
 *
 * @date 06 Jul 2023
 * @version V01
 * @author Mahmoud Abdelraouf Mahmoud
 */

#ifndef __STK_PRIVATE_H__
#define __STK_PRIVATE_H__

/*********************< Register Definitions **********************/
#define STK_BASE_ADDRESS          0xE000E010U
typedef struct STK_RegDef_t{
  volatile u32 CTRL;
  volatile u32 LOAD;
  volatile u32 VAL;
  volatile u32 CALIB;
} STK_RegDef_t;

#define STK                     ((STK_RegDef_t *)STK_BASE_ADDRESS)

/*********************< The following are defines for the bit fields in the STK_CTRL register. **********************/
#define STK_CTRL_ENABLE_MASK               0x00000001      /**< Bit 0 : Counter Enable */
#define STK_CTRL_TICKINT_MASK              0x00000002      /**< Bit 1 : Interrupt Enable */
#define STK_CTRL_CLKSOURCE_MASK            0x00000004      /**< Bit 2 : Clock Source */
#define STK_CTRL_COUNTFLAG_MASK            0x00010000      /**< Bit 16: Count Flag */


/**
 * @brief Specifies the clock source for the SysTick timer.
 *
 * This option determines whether the SysTick timer uses the processor clock or
 * an external clock source.
 *
 * @param STK_CTRL_CLKSOURCE_1 Clock source is the processor clock.
 * @param STK_CTRL_CLKSOURCE_8 Clock source is the processor clock divided by 8.
 *
 * @retval None
 */
#define STK_CTRL_CLKSOURCE_1              1
#define STK_CTRL_CLKSOURCE_8              0

/**
 * @brief Specifies whether the SysTick timer exception request is enabled.
 *
 * This option determines whether the SysTick timer asserts an exception request
 * when the counter reaches zero.
 *
 * @param STK_CTRL_TICKINT_ENABLE Counting down to zero asserts the SysTick exception request.
 * @param STK_CTRL_TICKINT_DISABLE Counting down to zero does not assert the SysTick exception request.
 *
 * @retval None
 */
#define STK_CTRL_TICKINT_ENABLE           1
#define STK_CTRL_TICKINT_DISABLE          0


#define MSTK_SINGLE_INTERVAL              0
#define MSTK_PERIOD_INTERVAL              1


/**
 * @brief Sets the system clock frequency for the SysTick peripheral.
 *
 * This function sets the system clock frequency for the SysTick peripheral. It does not allow changes to the values defined by the STK_CTRL_CLKSOURCE constant.
 *
 * @note
 * The available options for STK_CTRL_CLKSOURCE are:
 * - STK_CTRL_CLKSOURCE_1: Processor clock (AHB clock) divided by 1
 * - STK_CTRL_CLKSOURCE_8: Processor clock (AHB clock) divided by 8
 *
 * @retval None
 */
#if STK_CTRL_CLKSOURCE == STK_CTRL_CLKSOURCE_1
    #define STK_AHB_CLK       8000000   /**< Processor clock (AHB clock) divided by 1 */
#elif STK_CTRL_CLKSOURCE == STK_CTRL_CLKSOURCE_8
    #define STK_AHB_CLK       1000000   /**< Processor clock (AHB clock) divided by 8 */
#else
    #error "You chose a wrong clock source for the SysTick"
#endif


#endif /**< __STK_PRIVATE_H__ */


