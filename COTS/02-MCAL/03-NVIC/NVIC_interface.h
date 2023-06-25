/********************************************************************/
/************* Author    : Mahmoud Abdelraouf Mahmoud   *************/
/************* Date		 : 26 Feb 2022                  *************/
/************* Version   : V01                          *************/
/************* Module    : NVIC                         *************/
/********************************************************************/
#ifndef __NVIC_INTERFACE_H__
#define __NVIC_INTERFACE_H__


/**
 * @brief Enables a specific interrupt in the Nested Vectored Interrupt Controller (NVIC).
 *
 * This function enables a specific interrupt in the NVIC by setting the corresponding bit(s) in the NVIC_ISERx registers.
 *
 * @param[in] Copy_u8InterruptNumber The interrupt number (0-63) to be enabled.
 *
 * @retval 0 No error occurred.
 *
 * @retval 1 An error occurred (invalid interrupt number).
 */
u8 MNVIC_voidEnableInterrupt(u8 Copy_u8InterruptNumber);
/**
 * @brief Disables a specific interrupt in the Nested Vectored Interrupt Controller (NVIC).
 *
 * This function disables a specific interrupt in the NVIC by clearing the corresponding bit(s) in the NVIC_ICERx registers.
 *
 * @param[in] Copy_u8InterruptNumber The interrupt number (0-63) to be disabled.
 * 
 * @retval 0 No error occurred.
 *
 * @retval 1 An error occurred (invalid interrupt number).
 */
u8 MNVIC_voidDisableInterrupt(u8 Copy_u8InterruptNumber);




#endif /**< __NVIC_INTERFACE_H__ */