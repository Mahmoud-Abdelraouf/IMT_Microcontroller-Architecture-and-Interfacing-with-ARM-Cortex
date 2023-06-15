/*******************************************************/
/***** Author    : Mahmoud Abdelraouf Mahmoud   ********/
/***** Date		 : 25 Feb 2022                  ********/
/***** Version   : V01                          ********/
/*******************************************************/
#ifndef __RCC_PRIVATE_H__
#define __RCC_PRIVATE_H__

/* Register Definitions */
// from the 10 registers there are 5 for the clock and 5 for the reset
#define RCC_CR				*((u32 *)0X40021000) //for clock, choose and enable the clock on the processor
#define RCC_CFGR			*((u32 *)0X40021004) //for clock, choose and enable the clock on the processor
#define RCC_CIR				*((u32 *)0X40021008)
#define RCC_APB2RSTR		*((u32 *)0X4002100C)
#define RCC_APB1RSTR		*((u32 *)0X40021010)
#define RCC_AHBENR			*((u32 *)0X40021014) //for clock, enable and disable the clock on the different peripherals
#define RCC_APB2ENR			*((u32 *)0X40021018) //for clock, enable and disable the clock on the different peripherals
#define RCC_APB1ENR			*((u32 *)0X4002101C) //for clock, enable and disable the clock on the different peripherals
#define RCC_BDCR			*((u32 *)0X40021020)
#define RCC_CSR				*((u32 *)0X40021024)

/* Clock Types */
#define RCC_HSE_CRYSTAL	   0
#define RCC_HSE_RC         1
#define RCC_HSI            2
#define RCC_PLL            3

#endif