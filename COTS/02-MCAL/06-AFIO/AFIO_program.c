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
/*************************************< LIB *************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*************************************< MCAL *************************************/
#include "AFIO_private.h"
#include "AFIO_interface.h"
#include "AFIO_config.h"
/*************************************< FUNCTIONS IMPLEMENTATION *************************************/
void AFIO_SetEXTIPinConfiguration(u8 Copy_Line, u8 Copy_PortMap)
{
    u8 Local_u8RegIndex = Copy_Line / 4;   /**< Calculate register index using integer division */
    Copy_Line %= 4;                        /**< Calculate line number using remainder division */ 

    AFIO->EXTICR[Local_u8RegIndex] &=~ ((0b1111) << (Copy_Line * 4));
    AFIO->EXTICR[Local_u8RegIndex] |=  ((Copy_PortMap) << (Copy_Line * 4));
}
