/********************************************************************/
/************* Author    : Mahmoud Abdelraouf Mahmoud   *************/
/************* Date		 : 03 Jul 2023                  *************/
/************* Version   : V01                          *************/
/************* Module    : AFIO                         *************/
/********************************************************************/
#ifndef __AFIO_PRIVATE_H__
#define __AFIO_PRIVATE_H__
//*****************************************************************************
//
// AFIO registers (AFIO)
//
//*****************************************************************************
#define AFIO_BASE_ADDRESS       0x40010000

typedef struct AFIO_t{
    volatile u32 EVCR;
    volatile u32 MAPR;
    volatile u32 EXTICR[4]; 
    volatile u32 MAPR2;
}AFIO_t;

#define AFIO    ((volatile AFIO_t *)AFIO_BASE_ADDRESS)



#endif /**< __AFIO_PRIVATE_H__ */