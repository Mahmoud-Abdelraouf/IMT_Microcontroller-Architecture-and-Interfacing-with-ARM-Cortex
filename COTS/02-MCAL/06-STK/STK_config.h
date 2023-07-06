/**
 * @file   STK_config.h
 * @brief  Header file for the STK configuration module.
 *
 * @copyright Copyright (c) 2023
 * 
 * This file contains configuration options for the STK module.
 *
 * @attention
 * This file should not be modified by the user. Instead, the user should modify
 * the configuration options in the application code.
 *
 * @note
 * In order to use the STK module, the SysTick timer must be enabled in the
 * system configuration.
 *
 * @author Mahmoud Abdelraouf Mahmoud
 * @date   06 Jul 2023
 * @version V01
 */

#ifndef __STK_CONFIG_H__
#define __STK_CONFIG_H__


/**
 * @brief Specifies the clock source for the SysTick timer.
 *
 * This option determines whether the SysTick timer uses the processor clock or
 * an external clock source.
 *
 * @note
 * The external clock source must be connected to the STCLK pin on the microcontroller.
 *
 * @note
 * This option is only applicable if the SysTick timer is configured to use an
 * external clock source (STK_CLKSOURCE = STK_CLKSOURCE_EXT).
 *
 * @param STK_CTRL_CLKSOURCE_1 Clock source is the clock of STK.
 * @param STK_CTRL_CLKSOURCE_8 Clock source/8 is the clock of STK.
 *
 * @retval None
 */
#define STK_CTRL_CLKSOURCE     STK_CTRL_CLKSOURCE_8

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
#define STK_CTRL_TICKINT       STK_CTRL_TICKINT_ENABLE

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





#endif /**< __STK_CONFIG_H__ */


