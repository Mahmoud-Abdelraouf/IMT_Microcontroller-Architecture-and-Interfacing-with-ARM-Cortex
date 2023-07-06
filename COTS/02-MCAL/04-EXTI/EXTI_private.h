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


/**
 * @brief Defines the line numbers for external interrupts.
 * @note Your options: FROM LINE0 TO LINE15
 */
#define LINE0 			0      /**< The line number for interrupt line 0. */
#define LINE1 			1      /**< The line number for interrupt line 1. */
#define LINE2 			2      /**< The line number for interrupt line 2. */
#define LINE3 			3      /**< The line number for interrupt line 3. */
#define LINE4 			4      /**< The line number for interrupt line 4. */
#define LINE5 			5      /**< The line number for interrupt line 5. */
#define LINE6 			6      /**< The line number for interrupt line 6. */
#define LINE7 			7      /**< The line number for interrupt line 7. */
#define LINE8 			8      /**< The line number for interrupt line 8. */
#define LINE9 			9      /**< The line number for interrupt line 9. */
#define LINE10 			10     /**< The line number for interrupt line 10. */
#define LINE11 			11     /**< The line number for interrupt line 11. */
#define LINE12 			12     /**< The line number for interrupt line 12. */
#define LINE13 			13     /**< The line number for interrupt line 13. */
#define LINE14 			14     /**< The line number for interrupt line 14. */
#define LINE15 			15     /**< The line number for interrupt line 15. */



/**
 * @brief The mode for external interrupts.
 * @note Your options: RISING, FALLING, ON_CHANGE
 */
#define RISING 			0    /**< The rising edge mode for external interrupts. */
#define FALLING 		1    /**< The falling edge mode for external interrupts. */
#define ON_CHANGE 		2    /**< The on-change mode for external interrupts. */



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
