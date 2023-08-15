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
#define MRCC_AHB 				    0
#define MRCC_APB1				    1
#define MRCC_APB2				    2
/********************************< AHB PERIPHERAL CLOCK ENABLE REGISTER  ********************************/
#define MRCC_AHB_DMA1_EN            0
#define MRCC_AHB_DMA2_EN            1
#define MRCC_AHB_SRAM_EN            2   
#define MRCC_AHB_FLITF_EN           4
#define MRCC_AHB_CRCE_EN            6
#define MRCC_AHB_FSMC_EN            8
#define MRCC_AHB_SDIO_EN            10
/********************************< APB1 PERIPHERAL CLOCK ENABLE REGISTER ********************************/
#define MRCC_APP1_TIM2_EN           0                      
#define MRCC_APP1_TIM3_EN           1
#define MRCC_APP1_TIM4_EN           2
#define MRCC_APP1_TIM5_EN           3
#define MRCC_APP1_TIM6_EN           4
#define MRCC_APP1_TIM7_EN           5
#define MRCC_APP1_TIM12_EN          6
#define MRCC_APP1_TIM13_EN          7
#define MRCC_APP1_TIM14_EN          8
#define MRCC_APP1_WWDG_EN           11
#define MRCC_APP1_SPI2_EN           14
#define MRCC_APP1_SPI3_EN           15
#define MRCC_APP1_USART2_EN         17
#define MRCC_APP1_USART3_EN         18
#define MRCC_APP1_UART4_EN          19
#define MRCC_APP1_UART5_EN          20
#define MRCC_APP1_I2C1_EN           21
#define MRCC_APP1_I2C2_EN           22
#define MRCC_APP1_USB_EN            23
#define MRCC_APP1_CAN_EN            25
#define MRCC_APP1_BKP_EN            27
#define MRCC_APP1_PWR_EN            28
#define MRCC_APP1_DAC_EN            29
/********************************< APB2 PERIPHERAL CLOCK ENABLE REGISTER ********************************/
#define MRCC_APP2_AFIO_EN           0
#define MRCC_APP2_IOPA_EN           2
#define MRCC_APP2_IOPB_EN           3
#define MRCC_APP2_IOPC_EN           4
#define MRCC_APP2_IOPD_EN			5
#define MRCC_APP2_IOPE_EN			6
#define MRCC_APP2_IOPF_EN			7
#define MRCC_APP2_IOPG_EN			8
#define MRCC_APP2_ADC1_EN           9
#define MRCC_APP2_ADC2_EN           10
#define MRCC_APP2_TIM1_EN           11
#define MRCC_APP2_SPI1_EN           12
#define MRCC_APP2_TIM8_EN           13
#define MRCC_APP2_USART1_EN         14
#define MRCC_APP2_ADC3_EN           15
#define MRCC_APP2_TIM9_EN           19
#define MRCC_APP2_TIM10_EN          20
#define MRCC_APP2_TIM11_EN          21
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
void MRCC_voidInitSysClock(void);

/**
 * @brief Enables the clock for a specified peripheral on a specified bus.
 *
 * This function enables the clock for a specified peripheral on a specified bus.
 *
 * @param Copy_u8BusId The bus ID of the peripheral to enable.
 *        This parameter can be one of the following values:
 *        - MRCC_AHB  : Advanced High-performance Bus
 *        - MRCC_APB1 : Advanced Peripheral Bus 1
 *        - MRCC_APB2 : Advanced Peripheral Bus 2
 *
 * @param Copy_u8PeriphId The peripheral ID of the peripheral to enable.
 *        This parameter can be one of the following values:
 *        - MRCC_AFIO : Alternate Function I/O
 *        - MRCC_IOPA : I/O port A
 *        - MRCC_IOPB : I/O port B
 *        - MRCC_IOPC : I/O port C
 *        - MRCC_IOPD : I/O port D
 *        - MRCC_IOPE : I/O port E
 *        - MRCC_IOPF : I/O port F
 *        - MRCC_IOPG : I/O port G
 *
 * @note
 * The AHB bus is used for high-performance devices and the two APB buses are used
 * for lower-speed devices. The maximum frequency of the APB1 bus is 36 MHz, while
 * the maximum frequency of the APB2 bus is 72 MHz.
 *
 * @retval None
 */
void MRCC_voidEnableClock(u8 Copy_u8BusId,u8 Copy_u8PeriphId);

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
void MRCC_voidDisableClock(u8 Copy_u8BusId,u8 Copy_u8PeriphId);

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
u32 MRCC_GetSystemClockFreq(void);


#endif /**< __RCC_INTERFACE_H__ */
