/********************************************************************/
/************* Author    : Mahmoud Abdelraouf Mahmoud   *************/
/************* Date		 : 26 Feb 2022                  *************/
/************* Version   : V01                          *************/
/************* Module    : NVIC                         *************/
/********************************************************************/
#ifndef __NVIC_PRIVATE_H__
#define __NVIC_PRIVATE_H__


#define NVIC_ISER0				*((volatile u32 *)(0xE000E100))	/**< INTERRUPT SET-ENABLE REGISTERS FROM 0 TO 31  */
#define NVIC_ISER1				*((volatile u32 *)(0xE000E104))	/**< INTERRUPT SET-ENABLE REGISTERS FROM 32 TO 63  */
#define NVIC_ISER2				*((volatile u32 *)(0xE000E108))	/**< INTERRUPT SET-ENABLE REGISTERS FROM 64 TO 95  */
#define NVIC_ICER0				*((volatile u32 *)(0xE000E180))	/**< INTERRUPT CLEAR-ENABLE REGISTERS FROM 0 TO 31 */
#define NVIC_ICER1				*((volatile u32 *)(0xE000E184))	/**< INTERRUPT CLEAR-ENABLE REGISTERS FROM 32 TO 63 */
#define NVIC_ICER2				*((volatile u32 *)(0xE000E188))	/**< INTERRUPT CLEAR-ENABLE REGISTERS FROM 64 TO 95 */
#define NVIC_ISPR0				*((volatile u32 *)(0xE000E200))	/**< INTERRUPT SET-PENDING REGISTERS FROM 0 TO 31 */
#define NVIC_ISPR1				*((volatile u32 *)(0xE000E204))	/**< INTERRUPT SET-PENDING REGISTERS FROM 32 TO 63 */
#define NVIC_ISPR2				*((volatile u32 *)(0xE000E208))	/**< INTERRUPT SET-PENDING REGISTERS FROM 64 TO 95 */
#define NVIC_ICPR0				*((volatile u32 *)(0xE000E280))	/**< INTERRUPT CLEAR-PENDING REGISTERS FROM 0 TO 31 */
#define NVIC_ICPR1				*((volatile u32 *)(0xE000E284))	/**< INTERRUPT CLEAR-PENDING REGISTERS FROM 0 TO 31 */
#define NVIC_ICPR2				*((volatile u32 *)(0xE000E288))	/**< INTERRUPT CLEAR-PENDING REGISTERS FROM 0 TO 31 */
#define NVIC_IABR0				*((volatile u32 *)(0xE000E300))	/**< INTERRUPT ACTIVE BIT REGISTERS FROM 0 TO 31 */
#define NVIC_IABR1				*((volatile u32 *)(0xE000E304))	/**< INTERRUPT ACTIVE BIT REGISTERS FROM 0 TO 31 */
#define NVIC_IABR2				*((volatile u32 *)(0xE000E308))	/**< INTERRUPT ACTIVE BIT REGISTERS FROM 0 TO 31 */



#endif /**< __NVIC_PRIVATE_H__ */