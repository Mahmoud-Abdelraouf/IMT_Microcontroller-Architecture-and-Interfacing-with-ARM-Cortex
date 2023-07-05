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
#ifndef __NVIC_PRIVATE_H__
#define __NVIC_PRIVATE_H__

//*****************************************************************************
//
// Vector table for STM32F10xxx devices
//
//*****************************************************************************
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



//*****************************************************************************
//
// NVIC registers (NVIC)
//
//*****************************************************************************
#define NVIC_ISER0			    (*((volatile u32 *)0xE000E100))	/**< INTERRUPT SET-ENABLE REGISTERS FROM 0 TO 31  */
#define NVIC_ISER1			    (*((volatile u32 *)0xE000E104))	/**< INTERRUPT SET-ENABLE REGISTERS FROM 32 TO 63  */
#define NVIC_ISER2			    (*((volatile u32 *)0xE000E108))	/**< INTERRUPT SET-ENABLE REGISTERS FROM 64 TO 95  */
    
#define NVIC_ICER0			    (*((volatile u32 *)0xE000E180))	/**< INTERRUPT CLEAR-ENABLE REGISTERS FROM 0 TO 31 */
#define NVIC_ICER1			    (*((volatile u32 *)0xE000E184))	/**< INTERRUPT CLEAR-ENABLE REGISTERS FROM 32 TO 63 */
#define NVIC_ICER2			    (*((volatile u32 *)0xE000E188))	/**< INTERRUPT CLEAR-ENABLE REGISTERS FROM 64 TO 95 */
    
#define NVIC_ISPR0			    (*((volatile u32 *)0xE000E200))	/**< INTERRUPT SET-PENDING REGISTERS FROM 0 TO 31 */
#define NVIC_ISPR1			    (*((volatile u32 *)0xE000E204))	/**< INTERRUPT SET-PENDING REGISTERS FROM 32 TO 63 */
#define NVIC_ISPR2			    (*((volatile u32 *)0xE000E208))	/**< INTERRUPT SET-PENDING REGISTERS FROM 64 TO 95 */
    
#define NVIC_ICPR0			    (*((volatile u32 *)0xE000E280))	/**< INTERRUPT CLEAR-PENDING REGISTERS FROM 0 TO 31 */
#define NVIC_ICPR1			    (*((volatile u32 *)0xE000E284))	/**< INTERRUPT CLEAR-PENDING REGISTERS FROM 32 TO 63 */
#define NVIC_ICPR2			    (*((volatile u32 *)0xE000E288))	/**< INTERRUPT CLEAR-PENDING REGISTERS FROM 64 TO 95 */
    
#define NVIC_IABR0			    (*((volatile u32 *)0xE000E300))	/**< INTERRUPT ACTIVE BIT REGISTERS FROM 0 TO 31 */
#define NVIC_IABR1			    (*((volatile u32 *)0xE000E304))	/**< INTERRUPT ACTIVE BIT REGISTERS FROM 32 TO 63 */
#define NVIC_IABR2			    (*((volatile u32 *)0xE000E308))	/**< INTERRUPT ACTIVE BIT REGISTERS FROM 32 TO 63 */
    
#define NVIC_IPR			    ( ((volatile u8  *)0xE000E400))	/**< INTERRUPT PRIORITY REGISTERS BASE ADDRESS */
#define NVIC_IPR0			    (*((volatile u32 *)0xE000E400)) /**< INTERRUPT PRIORITY REGISTERS FROM 0 TO 3 */
#define NVIC_IPR1			    (*((volatile u32 *)0xE000E404)) /**< INTERRUPT PRIORITY REGISTERS FROM 4 TO 7 */
#define NVIC_IPR2			    (*((volatile u32 *)0xE000E408)) /**< INTERRUPT PRIORITY REGISTERS FROM 8 TO 11 */
#define NVIC_IPR3			    (*((volatile u32 *)0xE000E40C)) /**< INTERRUPT PRIORITY REGISTERS FROM 12 TO 15 */
#define NVIC_IPR4			    (*((volatile u32 *)0xE000E410)) /**< INTERRUPT PRIORITY REGISTERS FROM 16 TO 19 */
#define NVIC_IPR5			    (*((volatile u32 *)0xE000E414)) /**< INTERRUPT PRIORITY REGISTERS FROM 20 TO 23 */
#define NVIC_IPR6			    (*((volatile u32 *)0xE000E418)) /**< INTERRUPT PRIORITY REGISTERS FROM 24 TO 27 */
#define NVIC_IPR7			    (*((volatile u32 *)0xE000E41C)) /**< INTERRUPT PRIORITY REGISTERS FROM 28 TO 31 */
#define NVIC_IPR8			    (*((volatile u32 *)0xE000E420)) /**< INTERRUPT PRIORITY REGISTERS FROM 32 TO 35 */
#define NVIC_IPR9			    (*((volatile u32 *)0xE000E424)) /**< INTERRUPT PRIORITY REGISTERS FROM 36 TO 39 */
#define NVIC_IPR10			    (*((volatile u32 *)0xE000E428)) /**< INTERRUPT PRIORITY REGISTERS FROM 40 TO 43 */
#define NVIC_IPR11			    (*((volatile u32 *)0xE000E42C)) /**< INTERRUPT PRIORITY REGISTERS FROM 44 TO 47 */
#define NVIC_IPR12			    (*((volatile u32 *)0xE000E430)) /**< INTERRUPT PRIORITY REGISTERS FROM 48 TO 51 */
#define NVIC_IPR13			    (*((volatile u32 *)0xE000E434)) /**< INTERRUPT PRIORITY REGISTERS FROM 52 TO 55 */
#define NVIC_IPR14			    (*((volatile u32 *)0xE000E438)) /**< INTERRUPT PRIORITY REGISTERS FROM 56 TO 59 */
#define NVIC_IPR15			    (*((volatile u32 *)0xE000E43C)) /**< INTERRUPT PRIORITY REGISTERS FROM 60 TO 63 */
#define NVIC_IPR16			    (*((volatile u32 *)0xE000E440)) /**< INTERRUPT PRIORITY REGISTERS FROM 64 TO 67 */
#define NVIC_IPR17			    (*((volatile u32 *)0xE000E444)) /**< INTERRUPT PRIORITY REGISTERS FROM 68 TO 71 */
#define NVIC_IPR18			    (*((volatile u32 *)0xE000E448)) /**< INTERRUPT PRIORITY REGISTERS FROM 72 TO 75 */
#define NVIC_IPR19			    (*((volatile u32 *)0xE000E44C)) /**< INTERRUPT PRIORITY REGISTERS FROM 76 TO 79 */
#define NVIC_IPR20			    (*((volatile u32 *)0xE000E450)) /**< INTERRUPT PRIORITY REGISTERS FROM 80 TO RESERVED */
    
#define SCB_AIRCR			    (*((volatile u32 *)0xE000ED0C)) /**< APPLICATION INTERRUPT AND RESET CONTROL REGISTER */





#endif /**< __NVIC_PRIVATE_H__ */