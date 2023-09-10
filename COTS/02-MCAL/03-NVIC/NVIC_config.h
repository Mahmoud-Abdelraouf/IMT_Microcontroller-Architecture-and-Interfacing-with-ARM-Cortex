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
#ifndef __NVIC_CONFIG_H__
#define __NVIC_CONFIG_H__

/**
 * @addtogroup User_Configuration
 * @{
 */

/**
 * @brief Total Number of Interrupts
 *
 * This macro defines the total number of interrupt sources in the system.
 * It is a user-configurable setting and is used to dimension data structures
 * related to interrupt handling.
 */
#define NUMBER_OF_INTERRUPTS            67

/**
 * @brief Maximum NVIC Interrupt Priority
 *
 * This macro defines the highest priority level that can be assigned to an
 * interrupt in the Nested Vectored Interrupt Controller (NVIC). Interrupts
 * with higher priority values have lower actual priorities. It is a
 * user-configurable setting.
 *
 * @note This macro is intended for use with the MCAL_NVIC_xSetPriority function
 *       which sets both group and sub-group priorities. If you are using the
 *       MCAL_NVIC_vSetPriority function which sets group and sub-group priorities
 *       separately, consider using the PRIORITY_GROUPING macro instead.
 *
 * @note The valid range for NVIC interrupt priorities is from 0 to (NVIC_MAX_PRIORITY).
 *       The highest priority is 0, and the value specified by this macro represents
 *       the maximum numerical priority value achievable.
 *
 * @note The number of possible interrupts in the NVIC is (NVIC_MAX_PRIORITY + 1).
 */
#define NVIC_MAX_PRIORITY               15

/**
 * @brief Priority Grouping Options for NVIC (for MCAL_NVIC_vSetPriority)
 *
 * These macros define the available priority grouping options for the Nested
 * Vectored Interrupt Controller (NVIC) when using the MCAL_NVIC_vSetPriority function.
 * You can choose one of these options to configure how interrupt priorities are grouped.
 *
 * @attention These macros are intended for use with MCAL_NVIC_vSetPriority and should not
 * be used with MCAL_NVIC_xSetPriority.
 *
 * - NVIC_16GROUP_0SUB:  16 subgroups with 0 bits for sub-priority.
 *     - Group Priority Range: 0 to 15
 *     - Sub-Priority Range: NVIC_INVALID_PRIORITY
 * - NVIC_8GROUP_2SUB :  8 subgroups with 2 bits for sub-priority.
 *     - Group Priority Range: 0 to 7
 *     - Sub-Priority Range: 0 to 1
 * - NVIC_4GROUP_4SUB :  4 subgroups with 4 bits for sub-priority.
 *     - Group Priority Range: 0 to 3
 *     - Sub-Priority Range: 0 to 3
 * - NVIC_2GROUP_8SUB :  2 subgroups with 8 bits for sub-priority.
 *     - Group Priority Range: 0 to 1
 *     - Sub-Priority Range: 0 to 7
 * - NVIC_0GROUP_16SUB:  No grouping with 16 bits for sub-priority.
 *     - Group Priority Range: NVIC_INVALID_PRIORITY
 *     - Sub-Priority Range: 0 to 15
 */
#define PRIORITY_GROUPING   NVIC_4GROUP_4SUB

/**
 * @} User_Configuration
 */

#endif /**< NVIC_CONFIG_H_ */