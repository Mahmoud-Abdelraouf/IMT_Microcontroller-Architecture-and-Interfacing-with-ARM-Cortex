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
#define AFIO_EXTI0					0     /**< The line number for interrupt line 0. */
#define AFIO_EXTI1					1     /**< The line number for interrupt line 1. */
#define AFIO_EXTI2					2     /**< The line number for interrupt line 2. */
#define AFIO_EXTI3					3     /**< The line number for interrupt line 3. */
#define AFIO_EXTI4					4     /**< The line number for interrupt line 4. */
#define AFIO_EXTI5					5     /**< The line number for interrupt line 5. */
#define AFIO_EXTI6					6     /**< The line number for interrupt line 6. */
#define AFIO_EXTI7					7     /**< The line number for interrupt line 7. */
#define AFIO_EXTI8					8     /**< The line number for interrupt line 8. */
#define AFIO_EXTI9					9     /**< The line number for interrupt line 9. */
#define AFIO_EXTI10 				10    /**< The line number for interrupt line 10. */
#define AFIO_EXTI11 				11    /**< The line number for interrupt line 11. */
#define AFIO_EXTI12 				12    /**< The line number for interrupt line 12. */
#define AFIO_EXTI13 				13    /**< The line number for interrupt line 13. */
#define AFIO_EXTI14 				14    /**< The line number for interrupt line 14. */
#define AFIO_EXTI15				15    /**< The line number for interrupt line 15. */

/**
 * @brief Defines the binary values for each port to be used with external interrupts.
 *
 * This section defines the binary values for each port that can be used with external interrupts. The binary values are used to configure the EXTI functionality. 'X' in the port names represents the pin number that should be used for each EXTI line.
 *
 * @note For EXTI0, the binary value 0000 should be used with Port A pin X=0, for EXTI1, the binary value 0001 should be used with Port B pin X=1, and so on.
 *
 * @param[in] AFIO_PORTA: The binary value for Port A pins (in).
 * @param[in] AFIO_PORTB: The binary value for Port B pins (in).
 * @param[in] AFIO_PORTC: The binary value for Port C pins (in).
 * @param[in] AFIO_PORTD: The binary value for Port D pins (in).
 * @param[in] AFIO_PORTE: The binary value for Port E pins (in).
 * @param[in] AFIO_PORTF: The binary value for Port F pins (in).
 * @param[in] AFIO_PORTG: The binary value for Port G pins (in).
 */ 
#define AFIO_PORTA                0b0000 /**< The binary value for Port A pins. */
#define AFIO_PORTB                0b0001 /**< The binary value for Port B pins. */
#define AFIO_PORTC                0b0010 /**< The binary value for Port C pins. */
#define AFIO_PORTD                0b0011 /**< The binary value for Port D pins. */
#define AFIO_PORTE                0b0100 /**< The binary value for Port E pins. */
#define AFIO_PORTF                0b0101 /**< The binary value for Port F pins. */
#define AFIO_PORTG                0b0110 /**< The binary value for Port G pins. */


/*********************************************< FunCTIONS IMPLEMENTATION *********************************************/
/**
 * @brief Configures the External Interrupt/Event Controller (EXTI) functionality for a specified line and port.
 *
 * This function configures the EXTI functionality for the specified EXTI line and port.
 *
 * @param[in] Copy_u8Line: The EXTI line to be configured. Available options are:
 *                          - AFIO_EXTI0
 *                          - AFIO_EXTI1
 *                          - AFIO_EXTI2
 *                          - AFIO_EXTI3
 *                          - AFIO_EXTI4
 *                          - AFIO_EXTI5
 *                          - AFIO_EXTI6
 *                          - AFIO_EXTI7
 *                          - AFIO_EXTI8
 *                          - AFIO_EXTI9
 *                          - AFIO_EXTI10
 *                          - AFIO_EXTI11
 *                          - AFIO_EXTI12
 *                          - AFIO_EXTI13
 *                          - AFIO_EXTI14
 *                          - AFIO_EXTI15
 * 
 * @param[in] Copy_u8PortMap: The binary value for the port to be mapped to the EXTI line. Available options are:
 *                          - AFIO_PORTA
 *                          - AFIO_PORTB
 *                          - AFIO_PORTC
 *                          - AFIO_PORTD
 *                          - AFIO_PORTE
 *                          - AFIO_PORTF
 *                          - AFIO_PORTG
 *
 * @retval None
 * 
 * @note The available options for "Copy_u8Line" are MAFIO_EXTI0 through MAFIO_EXTI15.
 * @note The available options for "Copy_u8PortMap" are MAFIO_PORTAX through MAFIO_PORTGX.
 */ 
void AFIO_SetEXTIPinConfiguration(u8 Copy_Line, u8 Copy_PortMap);






#endif /**< __AFIO_INTERFACE_H__ */