/********************************************************************/
/************* Author    : Mahmoud Abdelraouf Mahmoud   *************/
/************* Date		 : 26 Feb 2022                  *************/
/************* Version   : V01                          *************/
/************* Module    : NVIC                         *************/
/********************************************************************/
#ifndef __NVIC_PRIVATE_H__
#define __NVIC_PRIVATE_H__

//*****************************************************************************
//
// NVIC registers (NVIC)
//
//*****************************************************************************
#define NVIC_ISER0			(*((volatile u32 *)0xE000E100))	/**< INTERRUPT SET-ENABLE REGISTERS FROM 0 TO 31  */
#define NVIC_ISER1			(*((volatile u32 *)0xE000E104))	/**< INTERRUPT SET-ENABLE REGISTERS FROM 32 TO 63  */
#define NVIC_ISER2			(*((volatile u32 *)0xE000E108))	/**< INTERRUPT SET-ENABLE REGISTERS FROM 64 TO 95  */

#define NVIC_ICER0			(*((volatile u32 *)0xE000E180))	/**< INTERRUPT CLEAR-ENABLE REGISTERS FROM 0 TO 31 */
#define NVIC_ICER1			(*((volatile u32 *)0xE000E184))	/**< INTERRUPT CLEAR-ENABLE REGISTERS FROM 32 TO 63 */
#define NVIC_ICER2			(*((volatile u32 *)0xE000E188))	/**< INTERRUPT CLEAR-ENABLE REGISTERS FROM 64 TO 95 */

#define NVIC_ISPR0			(*((volatile u32 *)0xE000E200))	/**< INTERRUPT SET-PENDING REGISTERS FROM 0 TO 31 */
#define NVIC_ISPR1			(*((volatile u32 *)0xE000E204))	/**< INTERRUPT SET-PENDING REGISTERS FROM 32 TO 63 */
#define NVIC_ISPR2			(*((volatile u32 *)0xE000E208))	/**< INTERRUPT SET-PENDING REGISTERS FROM 64 TO 95 */

#define NVIC_ICPR0			(*((volatile u32 *)0xE000E280))	/**< INTERRUPT CLEAR-PENDING REGISTERS FROM 0 TO 31 */
#define NVIC_ICPR1			(*((volatile u32 *)0xE000E284))	/**< INTERRUPT CLEAR-PENDING REGISTERS FROM 32 TO 63 */
#define NVIC_ICPR2			(*((volatile u32 *)0xE000E288))	/**< INTERRUPT CLEAR-PENDING REGISTERS FROM 64 TO 95 */

#define NVIC_IABR0			(*((volatile u32 *)0xE000E300))	/**< INTERRUPT ACTIVE BIT REGISTERS FROM 0 TO 31 */
#define NVIC_IABR1			(*((volatile u32 *)0xE000E304))	/**< INTERRUPT ACTIVE BIT REGISTERS FROM 32 TO 63 */
#define NVIC_IABR2			(*((volatile u32 *)0xE000E308))	/**< INTERRUPT ACTIVE BIT REGISTERS FROM 32 TO 63 */

#define NVIC_IPR			( ((volatile u8  *)0xE000E400))	/**< INTERRUPT PRIORITY REGISTERS BASE ADDRESS */
#define NVIC_IPR0			(*((volatile u32 *)0xE000E400)) /**< INTERRUPT PRIORITY REGISTERS FROM 0 TO 3 */
#define NVIC_IPR1			(*((volatile u32 *)0xE000E404)) /**< INTERRUPT PRIORITY REGISTERS FROM 4 TO 7 */
#define NVIC_IPR2			(*((volatile u32 *)0xE000E408)) /**< INTERRUPT PRIORITY REGISTERS FROM 8 TO 11 */
#define NVIC_IPR3			(*((volatile u32 *)0xE000E40C)) /**< INTERRUPT PRIORITY REGISTERS FROM 12 TO 15 */
#define NVIC_IPR4			(*((volatile u32 *)0xE000E410)) /**< INTERRUPT PRIORITY REGISTERS FROM 16 TO 19 */
#define NVIC_IPR5			(*((volatile u32 *)0xE000E414)) /**< INTERRUPT PRIORITY REGISTERS FROM 20 TO 23 */
#define NVIC_IPR6			(*((volatile u32 *)0xE000E418)) /**< INTERRUPT PRIORITY REGISTERS FROM 24 TO 27 */
#define NVIC_IPR7			(*((volatile u32 *)0xE000E41C)) /**< INTERRUPT PRIORITY REGISTERS FROM 28 TO 31 */
#define NVIC_IPR8			(*((volatile u32 *)0xE000E420)) /**< INTERRUPT PRIORITY REGISTERS FROM 32 TO 35 */
#define NVIC_IPR9			(*((volatile u32 *)0xE000E424)) /**< INTERRUPT PRIORITY REGISTERS FROM 36 TO 39 */
#define NVIC_IPR10			(*((volatile u32 *)0xE000E428)) /**< INTERRUPT PRIORITY REGISTERS FROM 40 TO 43 */
#define NVIC_IPR11			(*((volatile u32 *)0xE000E42C)) /**< INTERRUPT PRIORITY REGISTERS FROM 44 TO 47 */
#define NVIC_IPR12			(*((volatile u32 *)0xE000E430)) /**< INTERRUPT PRIORITY REGISTERS FROM 48 TO 51 */
#define NVIC_IPR13			(*((volatile u32 *)0xE000E434)) /**< INTERRUPT PRIORITY REGISTERS FROM 52 TO 55 */
#define NVIC_IPR14			(*((volatile u32 *)0xE000E438)) /**< INTERRUPT PRIORITY REGISTERS FROM 56 TO 59 */
#define NVIC_IPR15			(*((volatile u32 *)0xE000E43C)) /**< INTERRUPT PRIORITY REGISTERS FROM 60 TO 63 */
#define NVIC_IPR16			(*((volatile u32 *)0xE000E440)) /**< INTERRUPT PRIORITY REGISTERS FROM 64 TO 67 */
#define NVIC_IPR17			(*((volatile u32 *)0xE000E444)) /**< INTERRUPT PRIORITY REGISTERS FROM 68 TO 71 */
#define NVIC_IPR18			(*((volatile u32 *)0xE000E448)) /**< INTERRUPT PRIORITY REGISTERS FROM 72 TO 75 */
#define NVIC_IPR19			(*((volatile u32 *)0xE000E44C)) /**< INTERRUPT PRIORITY REGISTERS FROM 76 TO 79 */
#define NVIC_IPR20			(*((volatile u32 *)0xE000E450)) /**< INTERRUPT PRIORITY REGISTERS FROM 80 TO RESERVED */

#define SCB_AIRCR			(*((volatile u32 *)0xE000ED0C)) /**< APPLICATION INTERRUPT AND RESET CONTROL REGISTER */





#endif /**< __NVIC_PRIVATE_H__ */