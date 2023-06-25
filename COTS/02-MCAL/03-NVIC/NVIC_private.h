/********************************************************************/
/************* Author    : Mahmoud Abdelraouf Mahmoud   *************/
/************* Date		 : 26 Feb 2022                  *************/
/************* Version   : V01                          *************/
/************* Module    : NVIC                         *************/
/********************************************************************/
#ifndef __NVIC_PRIVATE_H__
#define __NVIC_PRIVATE_H__

#define NVIC_BASE_ADDRESS		0xE000E100

#define NVIC_ISER0				*((u32 *)(NVIC_BASE_ADDRESS + 0x000))	/**< INTERRUPT SET-ENABLE REGISTERS FROM 0 TO 31  */
#define NVIC_ISER1				*((u32 *)(NVIC_BASE_ADDRESS + 0x004))	/**< INTERRUPT SET-ENABLE REGISTERS FROM 32 TO 63  */






#endif /**< __NVIC_PRIVATE_H__ */