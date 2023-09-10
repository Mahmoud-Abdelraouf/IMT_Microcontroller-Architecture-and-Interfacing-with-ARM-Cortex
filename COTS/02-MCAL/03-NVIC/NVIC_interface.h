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
 * @defgroup NVIC_Types NVIC Type Definitions
 * @brief Type definitions related to NVIC (Nested Vectored Interrupt Controller).
 * @{
 */

/**
 * @brief Type definition for Cortex-M microcontroller interrupt numbers.
 *
 * This typedef defines the data type for representing interrupt numbers in Cortex-M
 * microcontroller architectures. Each interrupt is identified by a unique number,
 * which is used when configuring interrupt priorities and enabling/disabling interrupts.
 *
 * The specific range and mapping of interrupt numbers can vary depending on the
 * microcontroller model and vendor.
 *
 * @note The actual implementation may vary depending on the microcontroller architecture.
 *       This typedef is often defined by the microcontroller's CMSIS (Cortex Microcontroller
 *       Software Interface Standard) header file.
 */
typedef u8 IRQn_Type;

/**
 * @brief Placeholder Value for Priority Group and Sub-Group
 *
 * This macro defines a placeholder value to be used as the "Copy_GroupPriority" 
 * and "Copy_SubPriority" parameters in the "MCAL_NVIC_vSetPriority" function.
 * 
 * When the "PRIORITY_GROUPING" is set to "_0GROUP_16SUB", the "NONE" macro can be 
 * used as the "Copy_GroupPriority" parameter to indicate that no group priority is 
 * assigned.
 * 
 * When the "PRIORITY_GROUPING" is set to "_16GROUP_0SUB", the "NONE" macro can be 
 * used as the "Copy_SubPriority" parameter to indicate that no sub-priority is assigned.
 * 
 * Example Usage:
 * @code
 * /// Using NONE as Copy_GroupPriority when PRIORITY_GROUPING is _0GROUP_16SUB
 * MCAL_NVIC_vSetPriority(MyIRQ, NONE, 5);
 *
 * /// Using NONE as Copy_SubPriority when PRIORITY_GROUPING is _16GROUP_0SUB
 * MCAL_NVIC_vSetPriority(MyIRQ, 10, NONE);
 * @endcode
 */
#define NONE            ((INVALID_VALUE)-1) 

/**
 * @} (end of NVIC_Types NVIC Type Definitions)
 */

/**
 * @defgroup NVIC_Interrupts NVIC Interrupt Numbers
 * @brief Macros for NVIC interrupt numbers.
 * @{
 */

/**
 * @name Group 1 Interrupts
 * @{
 */
#define NVIC_WWDG_IRQn               0   /**< WWDG Window Watchdog interrupt */
#define NVIC_PVD_IRQn                1   /**< PVD PVD through EXTI Line detection interrupt */
#define NVIC_TAMPER_IRQn             2   /**< TAMPER Tamper interrupt */
#define NVIC_RTC_IRQn                3   /**< RTC RTC global interrupt */
#define NVIC_FLASH_IRQn              4   /**< FLASH Flash global interrupt */
#define NVIC_RCC_IRQn                5   /**< RCC RCC global interrupt */
#define NVIC_EXTI0_IRQn              6   /**< EXTI0 EXTI Line0 interrupt */
#define NVIC_EXTI1_IRQn              7   /**< EXTI1 EXTI Line1 interrupt */
#define NVIC_EXTI2_IRQn              8   /**< EXTI2 EXTI Line2 interrupt */
#define NVIC_EXTI3_IRQn              9   /**< EXTI3 EXTI Line3 interrupt */
#define NVIC_EXTI4_IRQn              10  /**< EXTI4 EXTI Line4 interrupt */
#define NVIC_DMA1_Channel1_IRQn      11  /**< DMA1_Channel1 DMA1 Channel1 global interrupt */
#define NVIC_DMA1_Channel2_IRQn      12  /**< DMA1_Channel2 DMA1 Channel2 global interrupt */
#define NVIC_DMA1_Channel3_IRQn      13  /**< DMA1_Channel3 DMA1 Channel3 global interrupt */
#define NVIC_DMA1_Channel4_IRQn      14  /**< DMA1_Channel4 DMA1 Channel4 global interrupt */
#define NVIC_DMA1_Channel5_IRQn      15  /**< DMA1_Channel5 DMA1 Channel5 global interrupt */
#define NVIC_DMA1_Channel6_IRQn      16  /**< DMA1_Channel6 DMA1 Channel6 global interrupt */
#define NVIC_DMA1_Channel7_IRQn      17  /**< DMA1_Channel7 DMA1 Channel7 global interrupt */
#define NVIC_ADC1_2_IRQn             18  /**< ADC1_2 ADC1 and ADC2 global interrupt */
#define NVIC_CAN1_TX_IRQn            19  /**< CAN1_TX CAN1 TX interrupts */
#define NVIC_CAN1_RX0_IRQn           20  /**< CAN1_RX0 CAN1 RX0 interrupts */
#define NVIC_CAN1_RX1_IRQn           21  /**< CAN1_RX1 CAN1 RX1 interrupt */
#define NVIC_CAN1_SCE_IRQn           22  /**< CAN1_SCE CAN1 SCE interrupt */
#define NVIC_EXTI9_5_IRQn            23  /**< EXTI9_5 EXTI Line[9:5] interrupts */
#define NVIC_TIM1_BRK_IRQn           24  /**< TIM1_BRK TIM1 Break interrupt */
#define NVIC_TIM1_UP_IRQn            25  /**< TIM1_UP TIM1 Update interrupt */
#define NVIC_TIM1_TRG_COM_IRQn       26  /**< TIM1_TRG_COM TIM1 Trigger and Commutation interrupts */
#define NVIC_TIM1_CC_IRQn            27  /**< TIM1_CC TIM1 Capture Compare interrupt */
/** @} */

/**
 * @name Group 2 Interrupts
 * @{
 */
#define NVIC_TIM2_IRQn               28  /**< TIM2 TIM2 global interrupt */
#define NVIC_TIM3_IRQn               29  /**< TIM3 TIM3 global interrupt */
#define NVIC_TIM4_IRQn               30  /**< TIM4 TIM4 global interrupt */
#define NVIC_I2C1_EV_IRQn            31  /**< I2C1_EV I2C1 event interrupt */
#define NVIC_I2C1_ER_IRQn            32  /**< I2C1_ER I2C1 error interrupt */
#define NVIC_I2C2_EV_IRQn            33  /**< I2C2_EV I2C2 event interrupt */
#define NVIC_I2C2_ER_IRQn            34  /**< I2C2_ER I2C2 error interrupt */
#define NVIC_SPI1_IRQn               35  /**< SPI1 SPI1 global interrupt */
#define NVIC_SPI2_IRQn               36  /**< SPI2 SPI2 global interrupt */
#define NVIC_USART1_IRQn             37  /**< USART1 USART1 global interrupt */
#define NVIC_USART2_IRQn             38  /**< USART2 USART2 global interrupt */
#define NVIC_USART3_IRQn             39  /**< USART3 USART3 global interrupt */
#define NVIC_EXTI15_10_IRQn          40  /**< EXTI15_10 EXTI Line[15:10] interrupts */
#define NVIC_RTCAlarm_IRQn           41  /**< RTCAlarm RTC alarm through EXTI line interrupt */
#define NVIC_OTG_FS_WKUP_IRQn        42  /**< OTG_FS_WKUP USB On-The-Go FS Wakeup through EXTI line interrupt */
#define NVIC_Reserved_IRQn           43  /**< Reserved interrupt */
#define NVIC_Reserved_IRQn           44  /**< Reserved interrupt */
#define NVIC_Reserved_IRQn           45  /**< Reserved interrupt */
#define NVIC_Reserved_IRQn           46  /**< Reserved interrupt */
#define NVIC_TIM5_IRQn               47  /**< TIM5 TIM5 global interrupt */
#define NVIC_SPI3_IRQn               48  /**< SPI3 SPI3 global interrupt */
#define NVIC_UART4_IRQn              49  /**< UART4 UART4 global interrupt */
#define NVIC_UART5_IRQn              50  /**< UART5 UART5 global interrupt */
#define NVIC_TIM6_IRQn               51  /**< TIM6 TIM6 global interrupt */
#define NVIC_TIM7_IRQn               52  /**< TIM7 TIM7 global interrupt */
#define NVIC_DMA2_Channel1_IRQn      53  /**< DMA2_Channel1 DMA2 Channel1 global interrupt */
#define NVIC_DMA2_Channel2_IRQn      54  /**< DMA2_Channel2 DMA2 Channel2 global interrupt */
#define NVIC_DMA2_Channel3_IRQn      55  /**< DMA2_Channel3 DMA2 Channel3 global interrupt */
#define NVIC_DMA2_Channel4_IRQn      56  /**< DMA2_Channel4 DMA2 Channel4 global interrupt */
#define NVIC_DMA2_Channel5_IRQn      57  /**< DMA2_Channel5 DMA2 Channel5 global interrupt */
#define NVIC_ETH_IRQn                58  /**< ETH Ethernet global interrupt */
#define NVIC_ETH_WKUP_IRQn           59  /**< ETH_WKUP Ethernet Wakeup through EXTI line interrupt */
#define NVIC_CAN2_TX_IRQn            60  /**< CAN2_TX CAN2 TX interrupts */
#define NVIC_CAN2_RX0_IRQn           61  /**< CAN2_RX0 CAN2 RX0 interrupts */
#define NVIC_CAN2_RX1_IRQn           62  /**< CAN2_RX1 CAN2 RX1 interrupt */
#define NVIC_CAN2_SCE_IRQn           63  /**< CAN2_SCE CAN2 SCE interrupt */
#define NVIC_OTG_FS_IRQn             64  /**< OTG_FS USB On The Go FS global interrupt */
/** @} */

/**
 * @} (end of NVIC_Interrupts NVIC Interrupt Numbers)
 */
         
/**
 * @defgroup NVIC_Control NVIC Control Functions
 * @brief Functions to control the Nested Vectored Interrupt Controller (NVIC).
 * @{
 */

/**
 * @brief Enable a specific interrupt in the NVIC.
 *
 * This function enables the specified interrupt in the NVIC.
 *
 * @param[in] Copy_IRQn The interrupt number (IRQn_Type) to enable.
 *
 * @return Std_ReturnType
 *   - E_OK     : Interrupt enabled successfully.
 *   - E_NOT_OK : An error occurred (invalid interrupt number).
 */
Std_ReturnType NVIC_EnableIRQ(IRQn_Type Copy_IRQn);

/**
 * @brief Disable a specific interrupt in the NVIC.
 *
 * This function disables the specified interrupt in the NVIC.
 *
 * @param[in] Copy_IRQn The interrupt number (IRQn_Type) to disable.
 *
 * @return Std_ReturnType
 *   - E_OK     : Interrupt disabled successfully.
 *   - E_NOT_OK : An error occurred (invalid interrupt number).
 */
Std_ReturnType NVIC_DisableIRQ(IRQn_Type Copy_IRQn);

/**
 * @brief Set a specific interrupt as pending in the NVIC.
 *
 * This function sets the specified interrupt as pending in the NVIC.
 *
 * @param[in] Copy_IRQn The interrupt number (IRQn_Type) to set as pending.
 *
 * @return Std_ReturnType
 *   - E_OK     : Interrupt set as pending successfully.
 *   - E_NOT_OK : An error occurred (invalid interrupt number).
 */
Std_ReturnType NVIC_SetPendingIRQ(IRQn_Type Copy_IRQn);

/**
 * @brief Clear the pending status of a specific interrupt in the NVIC.
 *
 * This function clears the pending status of the specified interrupt in the NVIC.
 *
 * @param[in] Copy_IRQn The interrupt number (IRQn_Type) to clear as pending.
 *
 * @return Std_ReturnType
 *   - E_OK     : Pending status cleared successfully.
 *   - E_NOT_OK : An error occurred (invalid interrupt number).
 */
Std_ReturnType NVIC_ClearPendingIRQ(IRQn_Type Copy_IRQn);

/**
 * @brief Get the pending status of a specific interrupt in the NVIC.
 *
 * This function checks if the specified interrupt is pending in the NVIC.
 *
 * @param[in]  Copy_IRQn            The interrupt number (IRQn_Type) to check.
 * @param[out] Copy_ReturnPendingFlag Pointer to a variable where the pending status will be stored.
 *                                  This will be set to 1 if the interrupt is pending, or 0 if it's not.
 *
 * @return Std_ReturnType
 *   - E_OK     : Interrupt is pending, and the pending status is returned in 'Copy_ReturnPendingFlag'.
 *   - E_NOT_OK : An error occurred (invalid interrupt number), and 'Copy_ReturnPendingFlag' is not modified.
 */
Std_ReturnType NVIC_GetPendingIRQ(IRQn_Type Copy_IRQn, u8 *Copy_ReturnPendingFlag);

/**
 * @brief Set the priority of a specific interrupt in the NVIC.
 *
 * This function sets the priority of the specified interrupt in the NVIC.
 *
 * @param[in] Copy_IRQn     The interrupt number (IRQn_Type) to set the priority for.
 * @param[in] Copy_Priority The priority level to set (0 to 255, with 0 being the highest).
 *
 * @return Std_ReturnType
 *   - E_OK     : Priority set successfully.
 *   - E_NOT_OK : An error occurred (invalid interrupt number or priority level).
 */
Std_ReturnType NVIC_xSetPriority(IRQn_Type Copy_IRQn, u8 Copy_Priority);

/**
 * @brief Set the priority of a specific interrupt in the NVIC.
 *
 * This function sets the priority of the specified interrupt in the NVIC.
 *
 * @param[in] Copy_IRQn         The interrupt number (IRQn_Type) to set the priority for.
 * @param[in] Copy_GroupPriority The group priority level (0 to 7, with 0 being the highest).
 * @param[in] Copy_SubPriority  The sub-priority level within the group (0 to 1, 2, or 3, depending on the chosen PRIORITY_GROUPING).
 *
 * @return Std_ReturnType
 *   - E_OK     : Priority set successfully.
 *   - E_NOT_OK : An error occurred (invalid interrupt number or priority levels).
 *
 * @details
 * This function allows you to set the priority of a specific interrupt in the Nested Vectored Interrupt Controller (NVIC).
 * The priority levels must be within the valid range for your system and should respect the selected PRIORITY_GROUPING.
 *
 * @note When using PRIORITY_GROUPING equal to NVIC_16GROUP_0SUB or NVIC_0GROUP_16SUB:
 *   - Copy_SubPriority should be 0.
 *   - Copy_GroupPriority should be in the range [0, 15] for NVIC_16GROUP_0SUB and NONE for NVIC_0GROUP_16SUB.
 *
 * @note When using other PRIORITY_GROUPING options (NVIC_8GROUP_2SUB, NVIC_4GROUP_4SUB, or NVIC_2GROUP_8SUB):
 *   - Copy_SubPriority can be in the range [0, 3].
 *   - Copy_GroupPriority can be in the range [0, 7].
 *
 * @see NVIC_config.h for details on PRIORITY_GROUPING.
 */
Std_ReturnType NVIC_vSetPriority(IRQn_Type Copy_IRQn, u8 Copy_GroupPriority, u8 Copy_SubPriority);

/**
 * @brief Get the priority of a specific interrupt in the NVIC.
 *
 * This function retrieves the priority of the specified interrupt in the NVIC.
 *
 * @param[in]  IRQn            The interrupt number (IRQn_Type) to get the priority for.
 * @param[out] Copy_Priority   A pointer to a variable that will store the retrieved priority.
 *
 * @return Std_ReturnType
 *   - E_OK     : Priority retrieved successfully, and the value is stored in Copy_Priority.
 *   - E_NOT_OK : An error occurred (invalid interrupt number or Copy_Priority pointer is NULL).
 */
Std_ReturnType NVIC_xGetPriority(IRQn_Type IRQn, u8 *Copy_Priority);

/**
 * @} (end of group NVIC_Control)
 */


#endif /**< NVIC_INTERFACE_H_ */
