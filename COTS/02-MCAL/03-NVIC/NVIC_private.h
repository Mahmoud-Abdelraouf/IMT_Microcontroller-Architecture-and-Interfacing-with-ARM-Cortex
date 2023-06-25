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
#define NVIC_ISER2				*((u32 *)(NVIC_BASE_ADDRESS + 0x008))	/**< INTERRUPT SET-ENABLE REGISTERS FROM 64 TO 95  */
#define NVIC_ICER0				*((u32 *)(NVIC_BASE_ADDRESS + 0x080))	/**< INTERRUPT CLEAR-ENABLE REGISTERS FROM 0 TO 31 */
#define NVIC_ICER1				*((u32 *)(NVIC_BASE_ADDRESS + 0x084))	/**< INTERRUPT CLEAR-ENABLE REGISTERS FROM 32 TO 63 */
#define NVIC_ICER2				*((u32 *)(NVIC_BASE_ADDRESS + 0x088))	/**< INTERRUPT CLEAR-ENABLE REGISTERS FROM 64 TO 95 */





#endif /**< __NVIC_PRIVATE_H__ */