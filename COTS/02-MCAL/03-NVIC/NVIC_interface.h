/**
 * @brief This module contains functions for configuring the Nested Vectored Interrupt Controller (NVIC).
 *
 * @author Mahmoud Abdelraouf Mahmoud
 * @date 27 Feb 2022
 * @version V01
 *
 * This module provides functions for enabling and disabling interrupts, setting interrupt priorities, and other
 * configuration options for the NVIC. It is designed to be used with ARM Cortex-M processors, and may not be
 * compatible with other architectures.
 *
 * @note This module is intended for use with the STM32F10x microcontroller series, but may be adapted for use with
 * other compatible processors.
 */
#ifndef __NVIC_INTERFACE_H__
#define __NVIC_INTERFACE_H__


/**
 * @brief NVIC priority group and subpriority configuration.
 *
 * This list defines the configuration values for the priority group and subpriority settings for the Nested Vector Interrupt
 * Controller (NVIC). These values are used to set the priority grouping and subpriority fields in the Interrupt Priority Register (IPR),
 * which determines how interrupts are prioritized and handled by the NVIC.
 *
 * @note These values should be passed to the NVIC_SetPriorityGrouping() function to configure the NVIC priority group and subpriority settings.
 *
 * @param MNVIC_GROUP4_SUB0 4 bits for group (IPR) and 0 bits for sub group. Group priorities: 16, Sub priorities: 0.
 * @param MNVIC_GROUP3_SUB1 3 bits for group (IPR) and 1 bit for sub group. Group priorities: 8, Sub priorities: 2.
 * @param MNVIC_GROUP2_SUB2 2 bits for group (IPR) and 2 bits for sub group. Group priorities: 4, Sub priorities: 4.
 * @param MNVIC_GROUP1_SUB3 1 bit for group (IPR) and 3 bits for sub group. Group priorities: 2, Sub priorities: 8.
 * @param MNVIC_GROUP0_SUB4 0 bits for group (IPR) and 4 bits for sub group. Group priorities: 0, Sub priorities: 16.
 */
#define MNVIC_GROUP4_SUB0			0x05FA0300	/**< 4 bit for groups  (IPR) and 0 bit for sub group & Group priorities : 16, Sub priorities : 0 */
#define MNVIC_GROUP3_SUB1		    0x05FA0400	/**< 3 bit for groups  (IPR) and 1 bit for sub group & Group priorities : 8 , Sub priorities : 2 */
#define MNVIC_GROUP2_SUB2			0x05FA0500	/**< 2 bit for groups  (IPR) and 2 bit for sub group & Group priorities : 4 , Sub priorities : 4 */
#define MNVIC_GROUP1_SUB3			0x05FA0600	/**< 1 bit for groups  (IPR) and 3 bit for sub group & Group priorities : 2 , Sub priorities : 8 */
#define MNVIC_GROUP0_SUB4			0x05FA0700	/**< 0 bits for groups (IPR) and 4 bit for sub group & Group priorities : 0 , Sub priorities : 16 */


/**********************************************< FUNCTIONS PROTOTYPES AND DESCRIPTION **********************************************/
        
/**
 * @brief Enables a specific interrupt in the Nested Vector Interrupt Controller (NVIC).
 *
 * This function enables a specific interrupt in the NVIC by setting the corresponding bit in the Interrupt Set-Enable Registers (ISERx).
 *
 * @param[in] Copy_u8InterruptNumber An 8-bit unsigned integer that represents the number of the interrupt to be enabled. This parameter should be one of the following options: 
 *            - MNVIC_WWDG
 *            - MNVIC_PVD
 *            - MNVIC_TAMPER
 *            - MNVIC_RTC
 *            - MNVIC_FLASH
 *            - MNVIC_RCC
 *            - MNVIC_EXTI0
 *            - MNVIC_EXTI1
 *            - MNVIC_EXTI2
 *            - MNVIC_EXTI3
 *            - MNVIC_EXTI4
 *            - MNVIC_DMA1_CHANNEL1
 *            - MNVIC_DMA1_CHANNEL2
 *            - MNVIC_DMA1_CHANNEL3
 *            - MNVIC_DMA1_CHANNEL4
 *            - MNVIC_DMA1_CHANNEL5
 *            - MNVIC_DMA1_CHANNEL6
 *            - MNVIC_DMA1_CHANNEL7
 *            - MNVIC_ADC1
 *            - MNVIC_ADC2
 *            - MNVIC_USB_HP_CAN_TX
 *            - MNVIC_USB_LP_CAN_RX0
 *            - MNVIC_CAN_RX1
 *            - MNVIC_CAN_SCE
 *            - MNVIC_EXTI9_5
 *            - MNVIC_TIM1_BRK
 *            - MNVIC_TIM1_UP
 *            - MNVIC_TIM1_TRG_COM
 *            - MNVIC_TIM1_CC
 *            - MNVIC_TIM2
 *            - MNVIC_TIM3
 *            - MNVIC_TIM4
 *            - MNVIC_I2C1_EV
 *            - MNVIC_I2C1_ER
 *            - MNVIC_I2C2_EV
 *            - MNVIC_I2C2_ER
 *            - MNVIC_SPI1
 *            - MNVIC_SPI2
 *            - MNVIC_USART1
 *            - MNVIC_USART2
 *            - MNVIC_USART3
 *            - MNVIC_EXTI15_10
 *            - MNVIC_RTCALARM
 *            - MNVIC_USBWAKEUP
 *            - MNVIC_TIM8_BRK
 *            - MNVIC_TIM8_UP
 *            - MNVIC_TIM8_TRG_COM
 *            - MNVIC_TIM8_CC
 *            - MNVIC_ADC3
 *            - MNVIC_FSMC
 *            - MNVIC_SDIO
 *            - MNVIC_TIM5
 *            - MNVIC_SPI3
 *            - MNVIC_UART4
 *            - MNVIC_UART5
 *            - MNVIC_TIM6
 *            - MNVIC_TIM7
 *            - MNVIC_DMA2_CHANNEL1
 *            - MNVIC_DMA2_CHANNEL2
 *            - MNVIC_DMA2_CHANNEL3
 *            - MNVIC_DMA2_CHANNEL4
 *            - MNVIC_DMA2_CHANNEL5
 *
 * @retval An 8-bit unsigned integer that represents the error status of the function. This parameter should be one of the following options:
 *            - 0 to indicate no error
 *            - 1 to indicate an error (if the Copy_u8InterruptNumber parameter is out of range)
 *
 * @note This function uses the Interrupt Set-Enable Registers (ISERx) of the NVIC to enable interrupts. The ISERx registers are memory-mapped, and their addresses depend on the implementation of the microcontroller.
 *
 * @par Example:
 *      To enable the TIM2 global interrupt, the following code can be used:
 *      @code
 *      u8 ErrorStatus = MNVIC_u8EnableInterrupt(MNVIC_TIM2);
 *      @endcode
 */
u8 MNVIC_u8EnableInterrupt(u8 Copy_u8InterruptNumber);


/**
 * @brief Disables a specific interrupt in the Nested Vector Interrupt Controller (NVIC).
 *
 * This function disables a specific interrupt in the NVIC by setting the corresponding bit in the Interrupt Clear-Enable Registers (ICERx).
 *
 * @param[in] Copy_u8InterruptNumber An 8-bit unsigned integer that represents the number of the interrupt to be disabled. This parameter should be one of the following options:
 *            - MNVIC_WWDG
 *            - MNVIC_PVD
 *            - MNVIC_TAMPER
 *            - MNVIC_RTC
 *            - MNVIC_FLASH
 *            - MNVIC_RCC
 *            - MNVIC_EXTI0
 *            - MNVIC_EXTI1
 *            - MNVIC_EXTI2
 *            - MNVIC_EXTI3
 *            - MNVIC_EXTI4
 *            - MNVIC_DMA1_CHANNEL1
 *            - MNVIC_DMA1_CHANNEL2
 *            - MNVIC_DMA1_CHANNEL3
 *            - MNVIC_DMA1_CHANNEL4
 *            - MNVIC_DMA1_CHANNEL5
 *            - MNVIC_DMA1_CHANNEL6
 *            - MNVIC_DMA1_CHANNEL7
 *            - MNVIC_ADC1
 *            - MNVIC_ADC2
 *            - MNVIC_USB_HP_CAN_TX
 *            - MNVIC_USB_LP_CAN_RX0
 *            - MNVIC_CAN_RX1
 *            - MNVIC_CAN_SCE
 *            - MNVIC_EXTI9_5
 *            - MNVIC_TIM1_BRK
 *            - MNVIC_TIM1_UP
 *            - MNVIC_TIM1_TRG_COM
 *            - MNVIC_TIM1_CC
 *            - MNVIC_TIM2
 *            - MNVIC_TIM3
 *            - MNVIC_TIM4
 *            - MNVIC_I2C1_EV
 *            - MNVIC_I2C1_ER
 *            - MNVIC_I2C2_EV
 *            - MNVIC_I2C2_ER
 *            - MNVIC_SPI1
 *            - MNVIC_SPI2
 *            - MNVIC_USART1
 *            - MNVIC_USART2
 *            - MNVIC_USART3
 *            - MNVIC_EXTI15_10
 *            - MNVIC_RTCALARM
 *            - MNVIC_USBWAKEUP
 *            - MNVIC_TIM8_BRK
 *            - MNVIC_TIM8_UP
 *            - MNVIC_TIM8_TRG_COM
 *            - MNVIC_TIM8_CC
 *            - MNVIC_ADC3
 *            - MNVIC_FSMC
 *            - MNVIC_SDIO
 *            - MNVIC_TIM5
 *            - MNVIC_SPI3
 *            - MNVIC_UART4
 *            - MNVIC_UART5
 *            - MNVIC_TIM6
 *            - MNVIC_TIM7
 *            - MNVIC_DMA2_CHANNEL1
 *            - MNVIC_DMA2_CHANNEL2
 *            - MNVIC_DMA2_CHANNEL3
 *            - MNVIC_DMA2_CHANNEL4
 *            - MNVIC_DMA2_CHANNEL5
 *
 * @retval An 8-bit unsigned integer that represents the error status of the function. This parameter should be one of the following options:
 *        - 0 to indicate no error
 *        - 1 to indicate an error (if the Copy_u8InterruptNumber parameter is out of range)
 *
 * @note This function uses the Interrupt Clear-Enable Registers (ICERx) of the NVIC to disable interrupts. The ICERx registers are memory-mapped, and their addresses depend on the implementation of the microcontroller.
 *
 * @par Example:
 *      To disable the TIM2 global interrupt, the following code can be used:
 *      @code
 *      u8 ErrorStatus = MNVIC_u8DisableInterrupt(MNVIC_TIM2);
 *      @endcode
 */
u8 MNVIC_u8DisableInterrupt(u8 Copy_u8InterruptNumber);


/**
 * @brief Sets the pending flag for a specific interrupt in the Nested Vector Interrupt Controller (NVIC).
 *
 * This function sets the pending flag for a specific interrupt in the NVIC by setting the corresponding bit in the Interrupt Set-Pending Registers (ISPRx).
 *
 * @param[in] Copy_u8InterruptNumber An 8-bit unsigned integer that represents the number of the interrupt to set the pending flag for. This parameter should be one of the following options: 
 *            - MNVIC_WWDG
 *            - MNVIC_PVD
 *            - MNVIC_TAMPER
 *            - MNVIC_RTC
 *            - MNVIC_FLASH
 *            - MNVIC_RCC
 *            - MNVIC_EXTI0
 *            - MNVIC_EXTI1
 *            - MNVIC_EXTI2
 *            - MNVIC_EXTI3
 *            - MNVIC_EXTI4
 *            - MNVIC_DMA1_CHANNEL1
 *            - MNVIC_DMA1_CHANNEL2
 *            - MNVIC_DMA1_CHANNEL3
 *            - MNVIC_DMA1_CHANNEL4
 *            - MNVIC_DMA1_CHANNEL5
 *            - MNVIC_DMA1_CHANNEL6
 *            - MNVIC_DMA1_CHANNEL7
 *            - MNVIC_ADC1
 *            - MNVIC_ADC2
 *            - MNVIC_USB_HP_CAN_TX
 *            - MNVIC_USB_LP_CAN_RX0
 *            - MNVIC_CAN_RX1
 *            - MNVIC_CAN_SCE
 *            - MNVIC_EXTI9_5
 *            - MNVIC_TIM1_BRK
 *            - MNVIC_TIM1_UP
 *            - MNVIC_TIM1_TRG_COM
 *            - MNVIC_TIM1_CC
 *            - MNVIC_TIM2
 *            - MNVIC_TIM3
 *            - MNVIC_TIM4
 *            - MNVIC_I2C1_EV
 *            - MNVIC_I2C1_ER
 *            - MNVIC_I2C2_EV
 *            - MNVIC_I2C2_ER
 *            - MNVIC_SPI1
 *            - MNVIC_SPI2
 *            - MNVIC_USART1
 *            - MNVIC_USART2
 *            - MNVIC_USART3
 *            - MNVIC_EXTI15_10
 *            - MNVIC_RTCALARM
 *            - MNVIC_USBWAKEUP
 *            - MNVIC_TIM8_BRK
 *            - MNVIC_TIM8_UP
 *            - MNVIC_TIM8_TRG_COM
 *            - MNVIC_TIM8_CC
 *            - MNVIC_ADC3
 *            - MNVIC_FSMC
 *            - MNVIC_SDIO
 *            - MNVIC_TIM5
 *            - MNVIC_SPI3
 *            - MNVIC_UART4
 *            - MNVIC_UART5
 *            - MNVIC_TIM6
 *            - MNVIC_TIM7
 *            - MNVIC_DMA2_CHANNEL1
 *            - MNVIC_DMA2_CHANNEL2
 *            - MNVIC_DMA2_CHANNEL3
 *            - MNVIC_DMA2_CHANNEL4
 *            - MNVIC_DMA2_CHANNEL5
 *
 * @return An 8-bit unsigned integer that represents the error status of the function. This parameter should be one of the following options:
 *            - 0 to indicate no error
 *            - 1 to indicate an error (if the Copy_u8InterruptNumber parameter is out of range)
 *
 * @note This function uses the Interrupt Set-Pending Registers (ISPRx) of the NVIC to set the pending flag for interrupts. The ISPRx registers are memory-mapped, and their addresses depend on the implementation of the microcontroller.
 *
 * @par Example:
 *      To set the pending flag for the TIM2 global interrupt, the following code can be used:
 *      @code
 *      u8 ErrorStatus = MNVIC_u8SetPendingFlag(MNVIC_TIM2);
 *      @endcode
 */
u8 MNVIC_u8SetPendingFlag(u8 Copy_u8InterruptNumber);


/**
 * @brief Clears the pending flag for a specific interrupt in the Nested Vector Interrupt Controller (NVIC).
 *
 * This function clears the pending flag for a specific interrupt in the NVIC by clearing the corresponding bit in the Interrupt Clear-Pending Registers (ICPRx).
 *
 * @param[in] Copy_u8InterruptNumber An 8-bit unsigned integer that represents the number of the interrupt to clear the pending flag for. This parameter should be one of the following options: 
 *            - MNVIC_WWDG
 *            - MNVIC_PVD
 *            - MNVIC_TAMPER
 *            - MNVIC_RTC
 *            - MNVIC_FLASH
 *            - MNVIC_RCC
 *            - MNVIC_EXTI0
 *            - MNVIC_EXTI1
 *            - MNVIC_EXTI2
 *            - MNVIC_EXTI3
 *            - MNVIC_EXTI4
 *            - MNVIC_DMA1_CHANNEL1
 *            - MNVIC_DMA1_CHANNEL2
 *            - MNVIC_DMA1_CHANNEL3
 *            - MNVIC_DMA1_CHANNEL4
 *            - MNVIC_DMA1_CHANNEL5
 *            - MNVIC_DMA1_CHANNEL6
 *            - MNVIC_DMA1_CHANNEL7
 *            - MNVIC_ADC1
 *            - MNVIC_ADC2
 *            - MNVIC_USB_HP_CAN_TX
 *            - MNVIC_USB_LP_CAN_RX0
 *            - MNVIC_CAN_RX1
 *            - MNVIC_CAN_SCE
 *            - MNVIC_EXTI9_5
 *            - MNVIC_TIM1_BRK
 *            - MNVIC_TIM1_UP
 *            - MNVIC_TIM1_TRG_COM
 *            - MNVIC_TIM1_CC
 *            - MNVIC_TIM2
 *            - MNVIC_TIM3
 *            - MNVIC_TIM4
 *            - MNVIC_I2C1_EV
 *            - MNVIC_I2C1_ER
 *            - MNVIC_I2C2_EV
 *            - MNVIC_I2C2_ER
 *            - MNVIC_SPI1
 *            - MNVIC_SPI2
 *            - MNVIC_USART1
 *            - MNVIC_USART2
 *            - MNVIC_USART3
 *            - MNVIC_EXTI15_10
 *            - MNVIC_RTCALARM
 *            - MNVIC_USBWAKEUP
 *            - MNVIC_TIM8_BRK
 *            - MNVIC_TIM8_UP
 *            - MNVIC_TIM8_TRG_COM
 *            - MNVIC_TIM8_CC
 *            - MNVIC_ADC3
 *            - MNVIC_FSMC
 *            - MNVIC_SDIO
 *            - MNVIC_TIM5
 *            - MNVIC_SPI3
 *            - MNVIC_UART4
 *            - MNVIC_UART5
 *            - MNVIC_TIM6
 *            - MNVIC_TIM7
 *            - MNVIC_DMA2_CHANNEL1
 *            - MNVIC_DMA2_CHANNEL2
 *            - MNVIC_DMA2_CHANNEL3
 *            - MNVIC_DMA2_CHANNEL4
 *            - MNVIC_DMA2_CHANNEL5
 *
 * @return An 8-bit unsigned integer that represents the error status of the function. This parameter should be one of the following options:
 *            - 0 to indicate no error
 *            - 1 to indicate an error (if the Copy_u8InterruptNumber parameter is out of range)
 *
 * @note This function uses the Interrupt Clear-Pending Registers (ICPRx) of the NVIC to clear the pending flag for interrupts. The ICPRx registers are memory-mapped, and their addresses depend on the implementation of the microcontroller.
 *
 * @par Example:
 *      To clear the pending flag for the EXTI1 global interrupt, the following code can be used:
 *      @code
 *      u8 ErrorStatus = MNVIC_u8ClearPendingFlag(MNVIC_EXTI1);
 *      @endcode
 */
u8 MNVIC_u8ClearPendingFlag(u8 Copy_u8InterruptNumber);


/**
 * @brief Gets the active flag status for a specific interrupt in the Nested Vector Interrupt Controller (NVIC).
 *
 * This function gets the active flag status for a specific interrupt in the NVIC by reading the corresponding bit in the Interrupt Active Bit Registers (IABRx) and storing the result in the location pointed to by the Copy_pu8ReturnValue parameter.
 *
 * @param[in] Copy_u8InterruptNumber An 8-bit unsigned integer that represents the number of the interrupt to get the active flag status for. This parameter should be one of the following options: 
 *            - MNVIC_WWDG
 *            - MNVIC_PVD
 *            - MNVIC_TAMPER
 *            - MNVIC_RTC
 *            - MNVIC_FLASH
 *            - MNVIC_RCC
 *            - MNVIC_EXTI0
 *            - MNVIC_EXTI1
 *            - MNVIC_EXTI2
 *            - MNVIC_EXTI3
 *            - MNVIC_EXTI4
 *            - MNVIC_DMA1_CHANNEL1
 *            - MNVIC_DMA1_CHANNEL2
 *            - MNVIC_DMA1_CHANNEL3
 *            - MNVIC_DMA1_CHANNEL4
 *            - MNVIC_DMA1_CHANNEL5
 *            - MNVIC_DMA1_CHANNEL6
 *            - MNVIC_DMA1_CHANNEL7
 *            - MNVIC_ADC1
 *            - MNVIC_ADC2
 *            - MNVIC_USB_HP_CAN_TX
 *            - MNVIC_USB_LP_CAN_RX0
 *            - MNVIC_CAN_RX1
 *            - MNVIC_CAN_SCE
 *            - MNVIC_EXTI9_5
 *            - MNVIC_TIM1_BRK
 *            - MNVIC_TIM1_UP
 *            - MNVIC_TIM1_TRG_COM
 *            - MNVIC_TIM1_CC
 *            - MNVIC_TIM2
 *            - MNVIC_TIM3
 *            - MNVIC_TIM4
 *            - MNVIC_I2C1_EV
 *            - MNVIC_I2C1_ER
 *            - MNVIC_I2C2_EV
 *            - MNVIC_I2C2_ER
 *            - MNVIC_SPI1
 *            - MNVIC_SPI2
 *            - MNVIC_USART1
 *            - MNVIC_USART2
 *            - MNVIC_USART3
 *            - MNVIC_EXTI15_10
 *            - MNVIC_RTCALARM
 *            - MNVIC_USBWAKEUP
 *            - MNVIC_TIM8_BRK
 *            - MNVIC_TIM8_UP
 *            - MNVIC_TIM8_TRG_COM
 *            - MNVIC_TIM8_CC
 *            - MNVIC_ADC3
 *            - MNVIC_FSMC
 *            - MNVIC_SDIO
 *            - MNVIC_TIM5
 *            - MNVIC_SPI3
 *            - MNVIC_UART4
 *            - MNVIC_UART5
 *            - MNVIC_TIM6
 *            - MNVIC_TIM7
 *            - MNVIC_DMA2_CHANNEL1
 *            - MNVIC_DMA2_CHANNEL2
 *            - MNVIC_DMA2_CHANNEL3
 *            - MNVIC_DMA2_CHANNEL4
 *            - MNVIC_DMA2_CHANNEL5
 * @param[out] Copy_pu8ReturnValue A pointer to an 8-bit unsigned integer that will store the active flag status for the interrupt. This parameter should be one of the following options:
 *            - 0 to indicate that the interrupt is not active
 *            - 1 to indicate that the interrupt is active
 *
 * @return An 8-bit unsigned integer that represents the error status of the function. This parameter should be one of the following options:
 *            - 0 to indicate no error
 *            - 1 to indicate an error (if the Copy_u8InterruptNumber parameter is out of range)
 *
 * @note This function uses the Interrupt Active Bit Registers (IABRx) of the NVIC to get the active flag status for interrupts. The IABRx registers are memory-mapped, and their addresses depend on the implementation of the microcontroller.
 *
 * @par Example:
 *      To get the active flag status for the EXTI1 global interrupt, the following code can be used:
 *      @code
 *      u8 ActiveFlagStatus;
 *      u8 ErrorStatus = MNVIC_u8GetActiveFlag(MNVIC_EXTI1, &ActiveFlagStatus);
 *      @endcode
 */
u8 MNVIC_u8GetActiveFlag(u8 Copy_u8InterruptNumber, u8 *Copy_pu8ReturnValue); 


/**
 * @brief Sets the priority and subpriority of an interrupt in the Nested Vector Interrupt Controller (NVIC).
 *
 * This function sets the priority and subpriority of a specified interrupt in the Nested Vector Interrupt Controller (NVIC).
 * The priority and subpriority are determined by the values of the Copy_u8GroupPriority and Copy_u8SubGroupPriority parameters,
 * respectively, and are combined to form a priority value that is stored in the Interrupt Priority Register (IPR).
 *
 * @param[in] Copy_s8InterruptNumber The interrupt number to set the priority for. This parameter can be one of the following values:
 *                - MNVIC_WWDG
 *                - MNVIC_PVD
 *                - MNVIC_TAMPER
 *                - MNVIC_RTC
 *                - MNVIC_FLASH
 *                - MNVIC_RCC
 *                - MNVIC_EXTI0
 *                - MNVIC_EXTI1
 *                - MNVIC_EXTI2
 *                - MNVIC_EXTI3
 *                - MNVIC_EXTI4
 *                - MNVIC_DMA1_CHANNEL1
 *                - MNVIC_DMA1_CHANNEL2
 *                - MNVIC_DMA1_CHANNEL3
 *                - MNVIC_DMA1_CHANNEL4
 *                - MNVIC_DMA1_CHANNEL5
 *                - MNVIC_DMA1_CHANNEL6
 *                - MNVIC_DMA1_CHANNEL7
 *                - MNVIC_ADC1
 *                - MNVIC_ADC2
 *                - MNVIC_USB_HP_CAN_TX
 *                - MNVIC_USB_LP_CAN_RX
 *                - MNVIC_CAN_RX1
 *                - MNVIC_CAN_SCE
 *                - MNVIC_EXTI9_5
 *                - MNVIC_TIM1_BRK
 *                - MNVIC_TIM1_UP
 *                - MNVIC_TIM1_TRG_COM
 *                - MNVIC_TIM1_CC
 *                - MNVIC_TIM2
 *                - MNVIC_TIM3
 *                - MNVIC_TIM4
 *                - MNVIC_I2C1_EV
 *                - MNVIC_I2C1_ER
 *                - MNVIC_I2C2_EV
 *                - MNVIC_I2C2_ER
 *                - MNVIC_SPI1
 *                - MNVIC_SPI2
 *                - MNVIC_USART1
 *                - MNVIC_USART2
 *                - MNVIC_USART3
 *                - MNVIC_EXTI15_10
 *                - MNVIC_RTCALARM
 *                - MNVIC_USBWAKEUP
 *                - MNVIC_TIM8_BRK
 *                - MNVIC_TIM8_UP
 *                - MNVIC_TIM8_TRG_COM
 *                - MNVIC_TIM8_CC
 *                - MNVIC_ADC3
 *                - MNVIC_FSMC
 *                - MNVIC_SDIO
 *                - MNVIC_TIM5
 *                - MNVIC_SPI3
 *                - MNVIC_UART4
 *                - MNVIC_UART5
 *                - MNVIC_TIM6
 *                - MNVIC_TIM7
 *                - MNVIC_DMA2_CHANNEL1
 *                - MNVIC_DMA2_CHANNEL2
 *                - MNVIC_DMA2_CHANNEL3
 *                - MNVIC_DMA2_CHANNEL4
 *                - MNVIC_DMA2_CHANNEL5
 * @param[in] Copy_u8GroupPriority The group priority value, which determines the number of priority bits assigned to the group of interrupts.
 *                 This parameter can be a value from 0 to a maximum value that depends on the value of the Copy_u32GROUP parameter.
 *                 - If Copy_u32GROUP is MNVIC_GROUP4_SUB0, the max value of Copy_u8GroupPriority is 15.
 *                 - If Copy_u32GROUP is MNVIC_GROUP3_SUB1, the max value of Copy_u8GroupPriority is 7.
 *                 - If Copy_u32GROUP is MNVIC_GROUP2_SUB2, the max value of Copy_u8GroupPriority is 3.
 *                 - If Copy_u32GROUP is MNVIC_GROUP1_SUB3, the max value of Copy_u8GroupPriority is 1.
 *                 - If Copy_u32GROUP is MNVIC_GROUP0_SUB4, the max value of Copy_u8GroupPriority is 0.
 * @param[in] Copy_u8SubGroupPriority The subpriority value, which determines the number of priority bits assigned to each individual
 *                 interrupt within a group. This parameter can be a value from 0 to a maximum value that depends on the value of the Copy_u32GROUP parameter.
 *                 - If Copy_u32GROUP is MNVIC_GROUP4_SUB0, the max value of Copy_u8SubGroupPriority is 0.
 *                 - If Copy_u32GROUP is MNVIC_GROUP3_SUB1, the max value of Copy_u8SubGroupPriority is 1.
 *                 - If Copy_u32GROUP is MNVIC_GROUP2_SUB2, the max value of Copy_u8SubGroupPriority is 3.
 *                 - If Copy_u32GROUP is MNVIC_GROUP1_SUB3, the max value of Copy_u8SubGroupPriority is 7.
 *                 - If Copy_u32GROUP is MNVIC_GROUP0_SUB4, the max value of Copy_u8SubGroupPriority is 15.
 * @param[in] Copy_u32GROUP The priority grouping configuration value. This parameter can be one of the following values:
 *                 - MNVIC_GROUP4_SUB0
 *                 - MNVIC_GROUP3_SUB1
 *                 - MNVIC_GROUP2_SUB2
 *                 - MNVIC_GROUP1_SUB3
 *                 - MNVIC_GROUP0_SUB4
 *
 * @return The error status of the operation, which is 0 if successful or 1 if an error occurred.
 *
 * @note The function sets the priority and subpriority of a specified interrupt in the NVIC. The priority and subpriority are determined
 * by the values of the Copy_u8GroupPriority and Copy_u8SubGroupPriority parameters, respectively, and are combined to form a priority value that is
 * stored in the Interrupt Priority Register (IPR).
 * @note If the interrupt number is negative, the function sets the priority and subpriority of a core peripheral interrupt.
 * Otherwise, it sets the priority and subpriority of an external peripheral interrupt.
 * @note It is important to note that the function implementation assumes that the `NVIC_IPR` and `SCB_AIRCR` registers used in the function are correctly defined and mapped to the appropriate memory addresses. If these registers are not defined or mapped correctly, the function may not work as intended.
 */
u8 MNVIC_u8SetPriority(s8 Copy_s8InterruptNumber,u8 Copy_u8GroupPriority, u8 Copy_u8SubGroupPriority, u32 Copy_u32GROUP);

#endif /**< __NVIC_INTERFACE_H__ */




