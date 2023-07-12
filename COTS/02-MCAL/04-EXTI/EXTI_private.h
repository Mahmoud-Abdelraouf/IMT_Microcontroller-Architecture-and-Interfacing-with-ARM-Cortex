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
#ifndef __EXTI_PRIVATE_H__
#define __EXTI_PRIVATE_H__



/*******************************< Register Definitions *******************************/
/**
 * @brief EXTI Base Address.
 *
 * This macro defines the base address of the External Interrupt (EXTI) peripheral.
 */
#define EXTI_BASE_ADDRESS			 0x40010400U

/**
 * @brief EXTI Register Map.
 *
 * This struct defines the register map of the EXTI peripheral, providing volatile access to the Interrupt Mask Register (IMR),
 * Event Mask Register (EMR), Rising Trigger Selection Register (RTSR), Falling Trigger Selection Register (FTSR),
 * Software Interrupt Event Register (SWIER), and Pending Register (PR).
 */
typedef struct EXTI_t{
	volatile u32 IMR;   /**< Interrupt Mask Register. */
	volatile u32 EMR;   /**< Event Mask Register. */
	volatile u32 RTSR;  /**< Rising Trigger Selection Register. */
	volatile u32 FTSR;  /**< Falling Trigger Selection Register. */
	volatile u32 SWIER; /**< Software Interrupt Event Register. */
	volatile u32 PR;    /**< Pending Register. */
}EXTI_t;

/**
 * @brief EXTI Register Access.
 *
 * This macro provides access to the EXTI peripheral using the register map defined in EXTI_t. It defines EXTI as a volatile
 * pointer to the base address of the EXTI peripheral.
 */
#define EXTI 		((EXTI_t *)EXTI_BASE_ADDRESS)





#endif /**< __EXTI_PRIVATE_H__ */
