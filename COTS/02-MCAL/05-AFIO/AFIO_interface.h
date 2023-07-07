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
 *                          - MAFIO_PORTAX
 *                          - MAFIO_PORTBX
 *                          - MAFIO_PORTCX
 *                          - MAFIO_PORTDX
 *                          - MAFIO_PORTEX
 *                          - MAFIO_PORTFX
 *                          - MAFIO_PORTGX
 *
 * @retval None
 * 
 * @note The available options for "Copy_u8Line" are MAFIO_EXTI0 through MAFIO_EXTI15.
 * @note The available options for "Copy_u8PortMap" are MAFIO_PORTAX through MAFIO_PORTGX.
 */ 
void MAFIO_voidSetEXTIConfiguration(u8 Copy_u8Line, u8 Copy_u8PortMap);






#endif /**< __AFIO_INTERFACE_H__ */