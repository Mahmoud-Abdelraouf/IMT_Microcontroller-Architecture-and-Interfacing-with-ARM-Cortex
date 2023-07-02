/********************************************************************/
/************* Author    : Mahmoud Abdelraouf Mahmoud   *************/
/************* Date		 : 26 Feb 2022                  *************/
/************* Version   : V01                          *************/
/************* Module    : NVIC                         *************/
/********************************************************************/
#ifndef __NVIC_INTERFACE_H__
#define __NVIC_INTERFACE_H__


#define MNVIC_GROUP3			0x05FA0300	/**< 4 bit for groups     (IPR) and NONE bit for sub group & Group priorities : 16   , Sub priorities : NONE */
#define MNVIC_GROUP4			0x05FA0400	/**< 3 bit for groups     (IPR) and 1    bit for sub group & Group priorities : 8    , Sub priorities : 2 */
#define MNVIC_GROUP5			0x05FA0500	/**< 2 bit for groups     (IPR) and 2    bit for sub group & Group priorities : 4    , Sub priorities : 4 */
#define MNVIC_GROUP6			0x05FA0600	/**< 1 bit for groups     (IPR) and 3    bit for sub group & Group priorities : 2    , Sub priorities : 8 */
#define MNVIC_GROUP7			0x05FA0700	/**< NONE bits for groups (IPR) and 4    bit for sub group & Group priorities : NONE , Sub priorities : 16 */


#define MNVIC_WWDG				0	/**< Window watchdog interrupt */
#define MNVIC_PVD				1	/**< PVD through EXTI Line detection interrupt */
#define MNVIC_TAMPER			2	/**< Tamper interrupt */
#define MNVIC_RTC				3	/**< RTC global interrupt */
#define MNVIC_FLASH				4   /**< Flash global interrupt */
#define MNVIC_RCC				5   /**< RCC global interrupt */
#define MNVIC_EXTI0				6   /**< EXTI Line0 interrupt */
#define MNVIC_EXTI1				7   /**< EXTI Line1 interrupt */
#define MNVIC_EXTI2				8   /**< EXTI Line2 interrupt */
#define MNVIC_EXTI3				9   /**< EXTI Line3 interrupt */
#define MNVIC_EXTI4				10  /**< EXTI Line4 interrupt */
#define MNVIC_DMA1_CHANNEL1		11  /**< DMA1 Channel1 global interrupt */
#define MNVIC_DMA1_CHANNEL2		12	/**< DMA1 Channel2 global interrupt */
#define MNVIC_DMA1_CHANNEL3		13  /**< DMA1 Channel3 global interrupt */
#define MNVIC_DMA1_CHANNEL4		14	/**< DMA1 Channel4 global interrupt */
#define MNVIC_DMA1_CHANNEL5		15	/**< DMA1 Channel5 global interrupt */
#define MNVIC_DMA1_CHANNEL6		16	/**< DMA1 Channel6 global interrupt */
#define MNVIC_DMA1_CHANNEL7		17	/**< DMA1 Channel7 global interrupt */
#define MNVIC_ADC1				18  /**< ADC1 global interrupt */
#define MNVIC_ADC2				18  /**< ADC2 global interrupt */
#define MNVIC_USB_HP_CAN_TX		19	/**< USB High Priority or CAN TX interrupts */
#define MNVIC_USB_LP_CAN_RX0	20	/**< USB Low Priority or CAN RX0 interrupts */	
#define MNVIC_CAN_RX1			21	/**< CAN RX1 interrupt */
#define MNVIC_CAN_SCE			22	/**< CAN SCE interrupt */
#define MNVIC_EXTI9_5			23	/**< EXTI Line[9:5] interrupts */
#define MNVIC_TIM1_BRK			24	/**< TIM1 Break interrupt */
#define MNVIC_TIM1_UP			25	/**< TIM1 Update interrupt */
#define MNVIC_TIM1_TRG_COM		26	/**< TIM1 Trigger and Commutation interrupts */
#define MNVIC_TIM1_CC			27	/**< TIM1 Capture Compare interrupt */
#define MNVIC_TIM2				28  /**< TIM2 global interrupt */
#define MNVIC_TIM3				29	/**< TIM3 global interrupt */
#define MNVIC_TIM4				30	/**< TIM4 global interrupt */
#define MNVIC_I2C1_EV			31	/**< I2C1 event interrupt */
#define MNVIC_I2C1_ER			32  /**< I2C1 error interrupt */
#define MNVIC_I2C2_EV			33  /**< I2C2 event interrupt */
#define MNVIC_I2C2_ER			34  /**< I2C2 error interrupt */
#define MNVIC_SPI1				35  /**< SPI1 global interrupt */
#define MNVIC_SPI2				36  /**< SPI2 global interrupt */
#define MNVIC_USART1			37	/**< USART1 global interrupt */
#define MNVIC_USART2			38  /**< USART2 global interrupt */
#define MNVIC_USART3            39  /**< USART3 global interrupt */
#define MNVIC_EXTI15_10         40  /**< EXTI Line[15:10] interrupts */
#define MNVIC_RTCALARM          41  /**< RTC alarm through EXTI line interrupt */
#define MNVIC_USBWAKEUP         42  /**< USB wakeup from suspend through EXTI line interrupt */
#define MNVIC_TIM8_BRK          43  /**< TIM8 Break interrupt */
#define MNVIC_TIM8_UP           44  /**< TIM8 Update interrupt */
#define MNVIC_TIM8_TRG_COM      45  /**< TIM8 Trigger and Commutation interrupts */
#define MNVIC_TIM8_CC           46  /**< TIM8 Capture Compare interrupt  */
#define MNVIC_ADC3              47  /**< ADC3 global interrupt */
#define MNVIC_FSMC              48  /**< FSMC global interrupt */
#define MNVIC_SDIO              49  /**< SDIO global interrupt */
#define MNVIC_TIM5              50  /**< TIM5 global interrupt */
#define MNVIC_SPI3              51  /**< SPI3 global interrupt */
#define MNVIC_UART4             52  /**< UART4 global interrupt */
#define MNVIC_UART5             53  /**< UART5 global interrupt */
#define MNVIC_TIM6              54  /**< TIM6 global interrupt */
#define MNVIC_TIM7              55  /**< TIM7 global interrupt */
#define MNVIC_DMA2_CHANNEL1     56  /**< DMA2 Channel1 global interrupt */
#define MNVIC_DMA2_CHANNEL2     57  /**< DMA2 Channel2 global interrupt */
#define MNVIC_DMA2_CHANNEL3     58  /**< DMA2 Channel3 global interrupt */
#define MNVIC_DMA2_CHANNEL4		59  /**< DMA2 Channel4 global interrupt */
#define MNVIC_DMA2_CHANNEL5		59  /**< DMA2 Channel5 global interrupt */


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

u8 MNVIC_u8SetPriority(s8 Copy_s8InterruptNumber,u8 Copy_u8GroupPriority, u8 Copy_u8SubGroupPriority, u32 Copy_u32GROUP);

#endif /**< __NVIC_INTERFACE_H__ */