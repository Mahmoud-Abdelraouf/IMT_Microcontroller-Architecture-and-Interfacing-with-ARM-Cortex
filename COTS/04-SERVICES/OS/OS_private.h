/*******************************************************/
/***** Author    : Mahmoud Abdelraouf Mahmoud   ********/
/***** Date		 : 20 Feb 2022                  ********/
/***** Version   : V01                          ********/
/***** Module    : OS_private.h                 ********/
/*******************************************************/
#ifndef __OS_PRIVATE_H__
#define __OS_PRIVATE_H__


typedef struct {
    u16 Periodicity;
    void (*OS_pfSetTask)(void);
}OS_Task_t;







#endif /**< __OS_PRIVATE_H__ */