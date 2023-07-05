/**
 * @brief This module contains functions for configuring the Reset and Clock Control (RCC) peripheral.
 *
 * @author Mahmoud Abdelraouf Mahmoud
 * @date 25 Feb 2022
 * @version V01
 *
 * This module provides functions for configuring the system clock source and frequency, as well as enabling and disabling
 * peripheral clocks. It also includes functions for resetting peripherals and reading the current clock frequency. It is
 * designed to be used with ARM Cortex-M processors, and may not be compatible with other architectures.
 *
 * @note This module is intended for use with the STM32F10x microcontroller series, but may be adapted for use with
 * other compatible processors.
 */
#ifndef __RCC_CONFIG_H__
#define __RCC_CONFIG_H__



/**	YOUR OPTIONS:
 *		RCC_HSE_CRYSTAL
 *		RCC_HSE_RC
 *		RCC_HSI
 *		RCC_PLL
 */
#define RCC_CLOCK_TYPE				RCC_HSE_CRYSTAL

/** YOUR OPTIONS:
 *		RCC_PLL_IN_HSI_DIV_2
 *		RCC_PLL_IN_HSE_DIV_2
 *		RCC_PLL_IN_HSE
 *	Note:
 *		Select value only if you have PLL as input clock
 */
#if RCC_CLOCK_TYPE == RCC_PLL
	#define RCC_PLL_INPUT			RCC_PLL_IN_HSI_DIV_2
#endif

/** YOUR OPTIONS:
 *		From 2 to 16
 *	Note:
 *		Select value only if you have PLL as input clock
 */
#if RCC_CLOCK_TYPE == RCC_PLL
	#define RCC_PLL_MUL_VAL			4
#endif



#endif/**< __RCC_CONFIG_H__ */
