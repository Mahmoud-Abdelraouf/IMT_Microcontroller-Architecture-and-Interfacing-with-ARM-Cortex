/********************************************************************/
/************* Author    : Mahmoud Abdelraouf Mahmoud   *************/
/************* Date		 : 26 Feb 2022                  *************/
/************* Version   : V01                          *************/
/************* Module    : GPIO                         *************/
/********************************************************************/
#ifndef __DIO_PRIVATE_H__
#define __DIO_PRIVATE_H__

#define GPIOA_BASE_ADDRESS	 0x40010800
#define GPIOB_BASE_ADDRESS	 0x40010C00
#define GPIOC_BASE_ADDRESS	 0x40011000

/*********************< REGISTERS ADDRESSES FOR PORT A *********************/
#define GPIOA_CRL_R			*((u32 *)(GPIOA_BASE_ADDRESS + 0x00))
#define GPIOA_CRH_R			*((u32 *)(GPIOA_BASE_ADDRESS + 0x04))
#define GPIOA_IDR_R			*((u32 *)(GPIOA_BASE_ADDRESS + 0x08))
#define GPIOA_ODR_R			*((u32 *)(GPIOA_BASE_ADDRESS + 0x0C))
#define GPIOA_BSR_R 		*((u32 *)(GPIOA_BASE_ADDRESS + 0x10))
#define GPIOA_BRR_R			*((u32 *)(GPIOA_BASE_ADDRESS + 0x14))
#define GPIOA_LCK_R	    	*((u32 *)(GPIOA_BASE_ADDRESS + 0x18))

/*********************< REGISTERS ADDRESSES FOR PORT B *********************/
#define GPIOB_CRL_R			*((u32 *)(GPIOB_BASE_ADDRESS + 0x00))
#define GPIOB_CRH_R			*((u32 *)(GPIOB_BASE_ADDRESS + 0x04))
#define GPIOB_IDR_R			*((u32 *)(GPIOB_BASE_ADDRESS + 0x08))
#define GPIOB_ODR_R			*((u32 *)(GPIOB_BASE_ADDRESS + 0x0C))
#define GPIOB_BSR_R 		*((u32 *)(GPIOB_BASE_ADDRESS + 0x10))
#define GPIOB_BRR_R			*((u32 *)(GPIOB_BASE_ADDRESS + 0x14))
#define GPIOB_LCK_R	    	*((u32 *)(GPIOB_BASE_ADDRESS + 0x18))

/*********************< REGISTERS ADDRESSES FOR PORT C *********************/
#define GPIOC_CRL_R			*((u32 *)(GPIOC_BASE_ADDRESS + 0x00))
#define GPIOC_CRH_R			*((u32 *)(GPIOC_BASE_ADDRESS + 0x04))
#define GPIOC_IDR_R			*((u32 *)(GPIOC_BASE_ADDRESS + 0x08))
#define GPIOC_ODR_R			*((u32 *)(GPIOC_BASE_ADDRESS + 0x0C))
#define GPIOC_BSR_R 		*((u32 *)(GPIOC_BASE_ADDRESS + 0x10))
#define GPIOC_BRR_R			*((u32 *)(GPIOC_BASE_ADDRESS + 0x14))
#define GPIOC_LCK_R	    	*((u32 *)(GPIOC_BASE_ADDRESS + 0x18))



#endif