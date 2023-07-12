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
#ifndef __AFIO_INTERFACE_H__
#define __AFIO_INTERFACE_H__


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


/*********************************************< FunCTIONS IMPLEMENTATION *********************************************/
/**
 * @brief Configures the External Interrupt/Event Controller (EXTI) functionality for a specified line and port.
 *
 * This function configures the EXTI functionality for the specified EXTI line and port.
 *
 * @param[in] Copy_u8Line: The EXTI line to be configured. Available options are:
 *                          - MAFIO_EXTI0
 *                          - MAFIO_EXTI1
 *                          - MAFIO_EXTI2
 *                          - MAFIO_EXTI3
 *                          - MAFIO_EXTI4
 *                          - MAFIO_EXTI5
 *                          - MAFIO_EXTI6
 *                          - MAFIO_EXTI7
 *                          - MAFIO_EXTI8
 *                          - MAFIO_EXTI9
 *                          - MAFIO_EXTI10
 *                          - MAFIO_EXTI11
 *                          - MAFIO_EXTI12
 *                          - MAFIO_EXTI13
 *                          - MAFIO_EXTI14
 *                          - MAFIO_EXTI15
 * 
 * @param[in] Copy_u8PortMap: The binary value for the port to be mapped to the EXTI line. Available options are:
 *                          - MAFIO_PORTA
 *                          - MAFIO_PORTB
 *                          - MAFIO_PORTC
 *                          - MAFIO_PORTD
 *                          - MAFIO_PORTE
 *                          - MAFIO_PORTF
 *                          - MAFIO_PORTG
 *
 * @retval None
 * 
 * @note The available options for "Copy_u8Line" are MAFIO_EXTI0 through MAFIO_EXTI15.
 * @note The available options for "Copy_u8PortMap" are MAFIO_PORTAX through MAFIO_PORTGX.
 */ 
void MAFIO_voidSetEXTIPinConfiguration(u8 Copy_u8Line, u8 Copy_u8PortMap);






#endif /**< __AFIO_INTERFACE_H__ */