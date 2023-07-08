/**
 * @brief This module contains functions for configuring the Alternative Function Input/Output (AFIO) peripheral.
 *
 * @author Mahmoud Abdelraouf Mahmoud
 * @date 03 Jul 2023
 * @version V01
 *
 * This module provides functions for configuring the remap and event output options of certain GPIO pins using the AFIO
 * peripheral. It is designed to be used with ARM Cortex-M processors, and may not be compatible with other architectures.
 *
 * @note This module is intended for use with the STM32F10x microcontroller series, but may be adapted for use with
 * other compatible processors.
 */
#ifndef __AFIO_PRIVATE_H__
#define __AFIO_PRIVATE_H__



/*******************************< Macros for configuration *******************************/
/**
 * @brief Defines the line numbers for external interrupts.
 * @note Your options: FROM LINE0 TO LINE15
 */
#define MAFIO_EXTI0					0     /**< The line number for interrupt line 0. */
#define MAFIO_EXTI1					1     /**< The line number for interrupt line 1. */
#define MAFIO_EXTI2					2     /**< The line number for interrupt line 2. */
#define MAFIO_EXTI3					3     /**< The line number for interrupt line 3. */
#define MAFIO_EXTI4					4     /**< The line number for interrupt line 4. */
#define MAFIO_EXTI5					5     /**< The line number for interrupt line 5. */
#define MAFIO_EXTI6					6     /**< The line number for interrupt line 6. */
#define MAFIO_EXTI7					7     /**< The line number for interrupt line 7. */
#define MAFIO_EXTI8					8     /**< The line number for interrupt line 8. */
#define MAFIO_EXTI9					9     /**< The line number for interrupt line 9. */
#define MAFIO_EXTI10 				10    /**< The line number for interrupt line 10. */
#define MAFIO_EXTI11 				11    /**< The line number for interrupt line 11. */
#define MAFIO_EXTI12 				12    /**< The line number for interrupt line 12. */
#define MAFIO_EXTI13 				13    /**< The line number for interrupt line 13. */
#define MAFIO_EXTI14 				14    /**< The line number for interrupt line 14. */
#define MAFIO_EXTI15				15    /**< The line number for interrupt line 15. */

/**
 * @brief Defines the binary values for each port to be used with external interrupts.
 *
 * This section defines the binary values for each port that can be used with external interrupts. The binary values are used to configure the EXTI functionality. 'X' in the port names represents the pin number that should be used for each EXTI line.
 *
 * @note For EXTI0, the binary value 0000 should be used with Port A pin X=0, for EXTI1, the binary value 0001 should be used with Port B pin X=1, and so on.
 *
 * @param[in] MAFIO_PORTA: The binary value for Port A pins (in).
 * @param[in] MAFIO_PORTB: The binary value for Port B pins (in).
 * @param[in] MAFIO_PORTC: The binary value for Port C pins (in).
 * @param[in] MAFIO_PORTD: The binary value for Port D pins (in).
 * @param[in] MAFIO_PORTE: The binary value for Port E pins (in).
 * @param[in] MAFIO_PORTF: The binary value for Port F pins (in).
 * @param[in] MAFIO_PORTG: The binary value for Port G pins (in).
 */ 
#define MAFIO_PORTA                0b0000 /**< The binary value for Port A pins. */
#define MAFIO_PORTB                0b0001 /**< The binary value for Port B pins. */
#define MAFIO_PORTC                0b0010 /**< The binary value for Port C pins. */
#define MAFIO_PORTD                0b0011 /**< The binary value for Port D pins. */
#define MAFIO_PORTE                0b0100 /**< The binary value for Port E pins. */
#define MAFIO_PORTF                0b0101 /**< The binary value for Port F pins. */
#define MAFIO_PORTG                0b0110 /**< The binary value for Port G pins. */

/*******************************************< Register Definitions *******************************************/
/**
 * @brief AFIO Base Address.
 *
 * This macro defines the base address of the Alternative Function Input/Output (AFIO) peripheral.
 */
#define AFIO_BASE_ADDRESS       0x40010000

/**
 * @brief AFIO Register Map.
 *
 * This struct defines the register map of the AFIO peripheral, providing volatile access to the Event Control Register (EVCR),
 * Multiplexed Pin Assignments Register (MAPR), External Interrupt Configuration Registers (EXTICR0-3),
 * and Multiplexed Pin Assignments Register 2 (MAPR2).
 */
typedef struct AFIO_t{
    volatile u32 EVCR;        /**< Event Control Register. */
    volatile u32 MAPR;        /**< Multiplexed Pin Assignments Register. */
    volatile u32 EXTICR[4];   /**< External Interrupt Configuration Registers. */
    volatile u32 MAPR2;       /**< Multiplexed Pin Assignments Register 2. */
}AFIO_RegDef_t;

/**
 * @brief AFIO Register Access.
 *
 * This macro provides access to the AFIO peripheral using the register map defined in AFIO_t. It defines AFIO as a volatile
 * pointer to the base address of the AFIO peripheral.
 */
#define AFIO    ((AFIO_RegDef_t *)AFIO_BASE_ADDRESS)




#endif /**< __AFIO_PRIVATE_H__ */