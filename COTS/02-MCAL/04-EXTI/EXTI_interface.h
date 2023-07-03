/********************************************************************/
/************* Author    : Mahmoud Abdelraouf Mahmoud   *************/
/************* Date		 : 02 Jul 2023                  *************/
/************* Version   : V01                          *************/
/************* Module    : EXTI                         *************/
/********************************************************************/
#ifndef __EXTI_INTERFACE_H__
#define __EXTI_INTERFACE_H__

void MEXTI_voidInit();

u8 MEXTI_u8EnableEXTI(Copy_u8Line);


u8 MEXTI_u8DisableEXTI(Copy_u8Line);

u8 MEXTI_u8SwTrigger(u8 Copy_u8Line);

u8 MEXTI_u8SetSignalLatch(u8 Copy_u8Line, u8 Copy_u8Mode);



#endif /**< __EXTI_INTERFACE_H__ */
