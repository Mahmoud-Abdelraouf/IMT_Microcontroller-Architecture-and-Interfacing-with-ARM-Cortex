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
#ifndef __EXTI_INTERFACE_H__
#define __EXTI_INTERFACE_H__

void MEXTI_voidInit();

u8 MEXTI_u8EnableEXTI(Copy_u8Line);


u8 MEXTI_u8DisableEXTI(Copy_u8Line);

u8 MEXTI_u8SwTrigger(u8 Copy_u8Line);

u8 MEXTI_u8SetSignalLatch(u8 Copy_u8Line, u8 Copy_u8Mode);



#endif /**< __EXTI_INTERFACE_H__ */
