/**
 * @brief This module contains functions for configuring and controlling the External Interrupt (EXTI) peripheral.
 *
 * @author Mahmoud Abdelraouf Mahmoud
 * @date 02 Jul 2023
 * @version V01
 *
 * This module provides functions for configuring the interrupt source, trigger type, and enabling/disabling EXTI lines.
 * It also includes functions for clearing the EXTI pending flag and getting the interrupt status. It is designed to be
 * used with ARM Cortex-M processors, and may not be compatible with other architectures.
 *
 * @note This module is intended for use with the STM32F10x microcontroller series, but may be adapted for use with
 * other compatible processors.
 */
#ifndef __EXTI_CONFIG_H__
#define __EXTI_CONFIG_H__

/**
 * @brief The external interrupt line number.
 * @note Your options: FROM MEXTI_LINE0 TO MEXTI_LINE15
 */
#define EXTI_LINE 		        MEXTI_LINE0  /**< The line number for external interrupts. */



/**
 * @brief The mode for external interrupts.
 * @note Your options: EXTI_RISING, EXTI_FALLING, EXTI_ON_CHANGE
 */
#define EXTI_SENSE_MODE 		MEXTI_RISING /**< The mode for external interrupts. Can be RISING, FALLING, or ON_CHANGE. */




#endif /**< __EXTI_CONFIG_H__ */
