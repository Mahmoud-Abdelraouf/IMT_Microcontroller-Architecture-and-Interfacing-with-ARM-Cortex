/*******************************************************/
/***** Author    : Mahmoud Abdelraouf Mahmoud   ********/
/***** Date		 : 20 Feb 2022                  ********/
/***** Version   : V01                          ********/
/***** Module    : OS_interface.h               ********/
/*******************************************************/
#ifndef __OS_INTERFACE_H__
#define __OS_INTERFACE_H__


u8 SOS_u8CreateTask(u8 Copy_u8TaskPriority, u16 Copy_u16TaskPeriodicity, void (*Copy_pfTask)(void));
void SOS_voidStart(void);






#endif /**< __OS_INTERFACE_H__ */