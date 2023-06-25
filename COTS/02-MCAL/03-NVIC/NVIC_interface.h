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
u8 MNVIC_u8EnableInterrupt(u8 Copy_u8InterruptNumber);
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
u8 MNVIC_u8DisableInterrupt(u8 Copy_u8InterruptNumber);
/**
 * @brief Sets a pending flag for a specific interrupt in the Nested Vectored Interrupt Controller (NVIC).
 *
 * This function sets a pending flag for a specific interrupt in the NVIC by setting the corresponding bit(s) in the NVIC_ISPRx registers.
 *
 * @param[in] Copy_u8InterruptNumber The interrupt number (0-63) to set the pending flag for.
 * 
 * @retval 0 No error occurred.
 * 
 * @retval 1 An error occurred (invalid interrupt number).
 */
u8 MNVIC_u8SetPendingFlag(u8 Copy_u8InterruptNumber);
/**
 * @brief Clears a pending flag for a specific interrupt in the Nested Vectored Interrupt Controller (NVIC).
 * 
 * This function clears a pending flag for a specific interrupt in the NVIC by clearing the corresponding bit(s) in the NVIC_ICPRx registers.
 *
 * @param[in] Copy_u8InterruptNumber The interrupt number (0-63) to clear the pending flag for.
 * 
 * @retval 0 No error occurred.
 *
 * @retval 1 An error occurred (invalid interrupt number).
 */
u8 MNVIC_u8ClearPendingFlag(u8 Copy_u8InterruptNumber); 
/**
 * @brief Gets the active flag for a specific interrupt in the Nested Vectored Interrupt Controller (NVIC).
 * 
 * This function gets the active flag for a specific interrupt in the NVIC by reading the corresponding bit(s) in the NVIC_IABRx registers.
 *
 * @param[in] Copy_u8InterruptNumber The interrupt number (0-63) to get the active flag for.
 * 
 * @param[out] Copy_pu8ReturnValue Pointer to a variable to store the active flag value. 1 if active, 0 if not active.
 * 
 * @retval 0 No error occurred.
 *
 * @retval 1 An error occurred (invalid interrupt number).
 */
u8 MNVIC_u8GetActiveFlag(u8 Copy_u8InterruptNumber, u8 *Copy_pu8ReturnValue); 


#endif /**< __NVIC_INTERFACE_H__ */