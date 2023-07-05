/********************************************************************/
/************* Author    : Mahmoud Abdelraouf Mahmoud   *************/
/************* Date		 : 03 Jul 2023                  *************/
/************* Version   : V01                          *************/
/************* Module    : AFIO                         *************/
/********************************************************************/
/**< LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/**< MCAL */
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

}
*/

void MAFIO_voidSetEXTIConfiguration(u8 Copy_u8Line, u8 Copy_u8PortMap)
{
    u8 Local_u8RegIndex = Copy_u8Line / 4;   /**< Calculate register index using integer division */
    Copy_u8Line %= 4;                        /**< Calculate line number using remainder division */ 

    AFIO -> EXTICR[Local_u8RegIndex] &=~ ((0b1111) << (Copy_u8Line * 4));
    AFIO -> EXTICR[Local_u8RegIndex] |=  ((Copy_u8PortMap) << (Copy_u8Line * 4));
}
