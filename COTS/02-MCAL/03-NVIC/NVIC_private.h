/**
 * @brief This module contains functions for configuring the Nested Vectored Interrupt Controller (NVIC).
 *
 * @author Mahmoud Abdelraouf Mahmoud
 * @date 26 Feb 2022
 * @version V01
 *
 * This module provides functions for enabling and disabling interrupts, setting interrupt priorities, and other
 * configuration options for the NVIC. It is designed to be used with ARM Cortex-M processors, and may not be
 * compatible with other architectures.
 *
 * @note This module is intended for use with the STM32F10x microcontroller series, but may be adapted for use with
 * other compatible processors.
 */
#ifndef __NVIC_PRIVATE_H__
#define __NVIC_PRIVATE_H__


/**
 * @defgroup NVIC_Registers NVIC Registers
 * @brief NVIC (Nested Vectored Interrupt Controller) Registers.
 * @{
 */

/**
 * @brief NVIC ISER Registers.
 * @{
 */
#define NVIC_ISER0     (*((volatile u32 *)0xE000E100)) /**< INTERRUPT SET-ENABLE REGISTERS 0 to 31 */
#define NVIC_ISER1     (*((volatile u32 *)0xE000E104)) /**< INTERRUPT SET-ENABLE REGISTERS 32 to 63 */
#define NVIC_ISER2     (*((volatile u32 *)0xE000E108)) /**< INTERRUPT SET-ENABLE REGISTERS 64 to 95 */
/** @} */

/**
 * @brief NVIC ICER Registers.
 * @{
 */
#define NVIC_ICER0     (*((volatile u32 *)0xE000E180)) /**< INTERRUPT CLEAR-ENABLE REGISTERS 0 to 31 */
#define NVIC_ICER1     (*((volatile u32 *)0xE000E184)) /**< INTERRUPT CLEAR-ENABLE REGISTERS 32 to 63 */
#define NVIC_ICER2     (*((volatile u32 *)0xE000E188)) /**< INTERRUPT CLEAR-ENABLE REGISTERS 64 to 95 */
/** @} */

/**
 * @brief NVIC ISPR Registers.
 * @{
 */
#define NVIC_ISPR0     (*((volatile u32 *)0xE000E200)) /**< INTERRUPT SET-PENDING REGISTERS 0 to 31 */
#define NVIC_ISPR1     (*((volatile u32 *)0xE000E204)) /**< INTERRUPT SET-PENDING REGISTERS 32 to 63 */
#define NVIC_ISPR2     (*((volatile u32 *)0xE000E208)) /**< INTERRUPT SET-PENDING REGISTERS 64 to 95 */
/** @} */

/**
 * @brief NVIC ICPR Registers.
 * @{
 */
#define NVIC_ICPR0     (*((volatile u32 *)0xE000E280)) /**< INTERRUPT CLEAR-PENDING REGISTERS 0 to 31 */
#define NVIC_ICPR1     (*((volatile u32 *)0xE000E284)) /**< INTERRUPT CLEAR-PENDING REGISTERS 32 to 63 */
#define NVIC_ICPR2     (*((volatile u32 *)0xE000E288)) /**< INTERRUPT CLEAR-PENDING REGISTERS 64 to 95 */
/** @} */

/**
 * @brief NVIC IABR Registers.
 * @{
 */
#define NVIC_IABR0     (*((volatile u32 *)0xE000E300)) /**< INTERRUPT ACTIVE BIT REGISTERS 0 to 31 */
#define NVIC_IABR1     (*((volatile u32 *)0xE000E304)) /**< INTERRUPT ACTIVE BIT REGISTERS 32 to 63 */
#define NVIC_IABR2     (*((volatile u32 *)0xE000E308)) /**< INTERRUPT ACTIVE BIT REGISTERS 64 to 95 */
/** @} */

/**
 * @brief NVIC IPR Base Address
 */                                                 
#define NVIC_IPR_BASE_ADDRESS    (((volatile u32 *)0xE000E400)) /**< INTERRUPT PRIORITY REGISTERS BASE ADDRESS */

/**
 * @brief Priority Grouping Values
 * @{
 */
#define NVIC_16GROUP_0SUB   0x05FA0300U /**< 16 Priority Levels, No Sub-priority */
#define NVIC_8GROUP_2SUB    0x05FA0400U /**< 8 Priority Levels, 2 Sub-priority Levels */
#define NVIC_4GROUP_4SUB    0x05FA0500U /**< 4 Priority Levels, 4 Sub-priority Levels */
#define NVIC_2GROUP_8SUB    0x05FA0600U /**< 2 Priority Levels, 8 Sub-priority Levels */
#define NVIC_0GROUP_16SUB   0x05FA0700U /**< No Grouping, 16 Sub-priority Levels */
/** @} */


/**
 * @} (end of group NVIC_Registers)
 */

#endif /**< NVIC_PRIVATE_H_ */