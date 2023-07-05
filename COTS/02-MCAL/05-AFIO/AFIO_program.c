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

/**
void MAFIO_voidSetEXTIConfiguration(u8 Copy_u8Line, u8 Copy_u8PortMap)
{
    u8 Local_u8RegIndex = 0;
    if(Copy_u8Line < 4)
    {
        Local_u8RegIndex = 0;
    }
    else if(Copy_u8Line < 8)
    {
        Local_u8RegIndex = 1;
        Copy_u8Line -= 4;
    }
    else if(Copy_u8Line < 12)
    {
        Local_u8RegIndex = 2;
        Copy_u8Line -= 8;
    }
    else if(Copy_u8Line < 16)
    {
        Local_u8RegIndex = 3;
        Copy_u8Line -= 12;
    }
    AFIO -> EXTICR[Local_u8RegIndex] &=~ ((0b1111) << (Copy_u8Line * 4));
    AFIO -> EXTICR[Local_u8RegIndex] |=  ((Copy_u8PortMap) << (Copy_u8Line * 4));

}*/

void MAFIO_voidSetEXTIConfiguration(u8 Copy_u8Line, u8 Copy_u8PortMap)
{
    u8 Local_u8RegIndex = Copy_u8Line / 4;   /**< Calculate register index using integer division */
    Copy_u8Line %= 4;                        /**< Calculate line number using remainder division */ 

    AFIO -> EXTICR[Local_u8RegIndex] &=~ ((0b1111) << (Copy_u8Line * 4));
    AFIO -> EXTICR[Local_u8RegIndex] |=  ((Copy_u8PortMap) << (Copy_u8Line * 4));
}
