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
}AFIO_t;

/**
 * @brief AFIO Register Access.
 *
 * This macro provides access to the AFIO peripheral using the register map defined in AFIO_t. It defines AFIO as a volatile
 * pointer to the base address of the AFIO peripheral.
 */
#define AFIO    ((volatile AFIO_t *)AFIO_BASE_ADDRESS)


#endif /**< __AFIO_PRIVATE_H__ */