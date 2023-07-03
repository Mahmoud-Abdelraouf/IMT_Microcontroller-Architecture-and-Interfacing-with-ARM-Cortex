/********************************************************************/
/************* Author    : Mahmoud Abdelraouf Mahmoud   *************/
/************* Date		 : 02 Jul 2023                  *************/
/************* Version   : V01                          *************/
/************* Module    : EXTI                         *************/
/********************************************************************/
#ifndef __EXTI_INTERFACE_H__
#define __EXTI_INTERFACE_H__

void MEXTI_voidInit();

void MEXTI_voidEnableEXTI(Copy_u8Line);


void MEXTI_voidDisableEXTI(Copy_u8Line);

void MEXTI_voidSwTrigger(u8 Copy_u8Line);



#endif /**< __EXTI_INTERFACE_H__ */
