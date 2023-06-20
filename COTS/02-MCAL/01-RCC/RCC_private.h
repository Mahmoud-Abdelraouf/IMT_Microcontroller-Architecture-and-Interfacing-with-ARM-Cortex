/********************************************************************/
/************* Author    : Mahmoud Abdelraouf Mahmoud   *************/
/************* Date		 : 25 Feb 2022                  *************/
/************* Version   : V01                          *************/
/********************************************************************/
#ifndef __RCC_PRIVATE_H__
#define __RCC_PRIVATE_H__

/********************************< Clock Types ********************************/
#define RCC_HSE_CRYSTAL	   			0 /**< High Speed External Crystal */
#define RCC_HSE_RC         			1 /**< High Speed External RC */
#define RCC_HSI            			2 /**< High Speed Internal */
#define RCC_PLL            			3 /**< Phase-locked loop */
/********************************< PLL Input ********************************/
#define RCC_PLL_IN_HSI_DIV_2		0 /**<  */
#define RCC_PLL_IN_HSE_DIV_2		1 /**<  */
#define RCC_PLL_IN_HSE				2 /**<  */




/********************************< Register Definitions ********************************/

/**< from the 10 registers there are 5 for the clock and 5 for the reset */
#define RCC_CR_R				*((volatile u32 *)0X40021000) /**< for clock, choose and enable the clock on the processor */

#define RCC_HSIRDY_BIT			1  /** 	Bit 1 HSIRDY: Internal high-speed clock ready flag
										Set by hardware to indicate that internal 8 MHz RC oscillator is stable. After the HSION bit is
										cleared, HSIRDY goes low after 6 internal 8 MHz RC oscillator clock cycles.
										0: internal 8 MHz RC oscillator not ready
										1: internal 8 MHz RC oscillator ready */
										
#define RCC_HSERDY_BIT			17 /** 	Bit 17 HSERDY: External high-speed clock ready flag
										Set by hardware to indicate that the HSE oscillator is stable. This bit needs 6 cycles of the
										HSE oscillator clock to fall down after HSEON reset.
										0: HSE oscillator not ready
										1: HSE oscillator ready */
										
#define RCC_PLLRDY_BIT			25 /** 	Bit 25 PLLRDY: PLL clock ready flag
										Set by hardware to indicate that the PLL is locked.
										0: PLL unlocked
										1: PLL locked */

#define RCC_CFGR_R				*((volatile u32 *)0X40021004) //for clock, choose and enable the clock on the processor
#define RCC_PLLSRC_BIT			16 /** 	PLL entry clock source
										Set and cleared by software to select PLL clock source. This bit can be written only when
										PLL is disabled.
										0: HSI oscillator clock / 2 selected as PLL input clock
										1: HSE oscillator clock selected as PLL input clock */
										
#define RCC_PLLXTPRE_BIT		17	/** HSE divider for PLL entry
										Set and cleared by software to divide HSE before PLL entry. This bit can be written only
										when PLL is disabled.
										0: HSE clock not divided
										1: HSE clock divided by 2 */
#define RCC_CIR_R				*((volatile u32 *)0X40021008)
#define RCC_APB2RSTR_R			*((volatile u32 *)0X4002100C)
#define RCC_APB1RSTR_R			*((volatile u32 *)0X40021010)
#define RCC_AHBENR_R			*((volatile u32 *)0X40021014) //for clock, enable and disable the clock on the different peripherals
#define RCC_APB1ENR_R			*((volatile u32 *)0X4002101C) //for clock, enable and disable the clock on the different peripherals
#define RCC_APB2ENR_R			*((volatile u32 *)0X40021018) //for clock, enable and disable the clock on the different peripherals
#define RCC_BDCR_R				*((volatile u32 *)0X40021020)
#define RCC_CSR_R				*((volatile u32 *)0X40021024)



#endif
