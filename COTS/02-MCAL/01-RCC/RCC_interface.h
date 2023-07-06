/**
 * @file RCC_interface.h
 * @brief This module contains functions for configuring the Reset and Clock Control (RCC) peripheral.
 *
 * @author Mahmoud Abdelraouf Mahmoud (mahmoud126125@gmail.com)
 * @date 25 Feb 2022
 * @version V01
 *
 * @copyright Copyright (c) 2023
 * 
 * This module provides functions for configuring the system clock source and frequency, as well as enabling and disabling
 * peripheral clocks. It also includes functions for resetting peripherals and reading the current clock frequency. It is
 * designed to be used with ARM Cortex-M processors, and may not be compatible with other architectures.
 *
 * @note This module is intended for use with the STM32F10x microcontroller series, but may be adapted for use with
 * other compatible processors.
 */
#ifndef __RCC_INTERFACE_H__
#define __RCC_INTERFACE_H__

/********************************< Bus Architecture options ********************************/
#define RCC_AHB 				0
#define RCC_APB1				1
#define RCC_APB2				2

/********************************< APB2 PERIPHERAL RESET REGISTER ********************************/
#define RCC_AFIO            	0
#define RCC_IOPA            	2
#define RCC_IOPB            	3
#define RCC_IOPC            	4
#define RCC_IOPD			 	5
#define RCC_IOPE			 	6
#define RCC_IOPF			 	7
#define RCC_IOPG			 	8


/********************************< FUNCTIONs PROTOTYPE ********************************/


/**
 * @brief Initializes the system clock according to the selected clock type and input.
 *
 * This function initializes the system clock according to the selected clock type and input.
 *
 * @note
 * The available options for RCC_CLOCK_TYPE are:
 * - RCC_HSE_CRYSTAL: External high-speed crystal oscillator
 * - RCC_HSE_RC: External high-speed RC oscillator with bypass
 * - RCC_HSI: Internal high-speed RC oscillator
 * - RCC_PLL: Phase-locked loop clock
 *
 * The available options for RCC_PLL_INPUT are:
 * - RCC_PLL_IN_HSI_DIV_2: HSI oscillator clock divided by 2
 * - RCC_PLL_IN_HSE_DIV_2: HSE oscillator clock divided by 2
 * - RCC_PLL_IN_HSE: HSE oscillator clock
 *
 * @retval None
 */
void RCC_voidInitSysClock(void);

/**
 * @brief Enables the clock for a specified peripheral on a specified bus.
 *
 * This function enables the clock for a specified peripheral on a specified bus.
 *
 * @param Copy_u8BusId The bus ID of the peripheral to enable.
 *        This parameter can be one of the following values:
 *        - RCC_AHB  : Advanced High-performance Bus
 *        - RCC_APB1 : Advanced Peripheral Bus 1
 *        - RCC_APB2 : Advanced Peripheral Bus 2
 *
 * @param Copy_u8PeriphId The peripheral ID of the peripheral to enable.
 *        This parameter can be one of the following values:
 *        - RCC_AFIO : Alternate Function I/O
 *        - RCC_IOPA : I/O port A
 *        - RCC_IOPB : I/O port B
 *        - RCC_IOPC : I/O port C
 *        - RCC_IOPD : I/O port D
 *        - RCC_IOPE : I/O port E
 *        - RCC_IOPF : I/O port F
 *        - RCC_IOPG : I/O port G
 *
 * @note
 * The AHB bus is used for high-performance devices and the two APB buses are used
 * for lower-speed devices. The maximum frequency of the APB1 bus is 36 MHz, while
 * the maximum frequency of the APB2 bus is 72 MHz.
 *
 * @retval None
 */
void RCC_voidEnableClock(u8 Copy_u8BusId,u8 Copy_u8PeriphId);

/**
 * @brief Disables the clock for a specified peripheral on a specified bus.
 *
 * This function enables the clock for a specified peripheral on a specified bus.
 *
 * @param Copy_u8BusId The bus ID of the peripheral to enable.
 *        This parameter can be one of the following values:
 *        - RCC_AHB  : Advanced High-performance Bus
 *        - RCC_APB1 : Advanced Peripheral Bus 1
 *        - RCC_APB2 : Advanced Peripheral Bus 2
 *
 * @param Copy_u8PeriphId The peripheral ID of the peripheral to enable.
 *        This parameter can be one of the following values:
 *        - RCC_AFIO : Alternate Function I/O
 *        - RCC_IOPA : I/O port A
 *        - RCC_IOPB : I/O port B
 *        - RCC_IOPC : I/O port C
 *        - RCC_IOPD : I/O port D
 *        - RCC_IOPE : I/O port E
 *        - RCC_IOPF : I/O port F
 *        - RCC_IOPG : I/O port G
 *
 * @note
 * The AHB bus is used for high-performance devices and the two APB buses are used
 * for lower-speed devices. The maximum frequency of the APB1 bus is 36 MHz, while
 * the maximum frequency of the APB2 bus is 72 MHz.
 *
 * @retval None
 */
void RCC_voidDisableClock(u8 Copy_u8BusId,u8 Copy_u8PeriphId);

/**
 * @brief Returns the system clock frequency.
 *
 * This function reads the RCC_CFGR_R register to determine the current system clock source and frequency. If the system clock is derived from the HSI oscillator, the frequency is fixed at 16 MHz. If it is derived from the HSE oscillator, the frequency is determined by the value of the RCC_HSE_VALUE constant. If it is derived from the PLL, the frequency is calculated based on the PLL input clock frequency and the PLL multiplication factor.
 *
 * @note
 * The constant RCC_HSE_VALUE should be defined in the header file and represents the frequency of the external crystal or oscillator used as the HSE clock source.
 *
 * @retval The system clock frequency in Hz.
 */
u32 RCC_GetSystemClockFreq(void);


#endif /**< __RCC_INTERFACE_H__ */
