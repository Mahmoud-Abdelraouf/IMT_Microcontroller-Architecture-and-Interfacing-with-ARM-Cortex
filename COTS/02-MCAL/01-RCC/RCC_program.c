/**
 * @brief This module contains functions for configuring the Reset and Clock Control (RCC) peripheral.
 *
 * @author Mahmoud Abdelraouf Mahmoud
 * @date 25 Feb 2022
 * @version V01
 *
 * This module provides functions for configuring the system clock source and frequency, as well as enabling and disabling
 * peripheral clocks. It also includes functions for resetting peripherals and reading the current clock frequency. It is
 * designed to be used with ARM Cortex-M processors, and may not be compatible with other architectures.
 *
 * @note This module is intended for use with the STM32F10x microcontroller series, but may be adapted for use with
 * other compatible processors.
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void RCC_InitSysClock(void)
{
	#if 	RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
		RCC_CR_R   = 0x00010000; 						/**< Enable HSE with no bypass */
		while(!GET_BIT(RCC_CR_R, RCC_HSERDY_BIT)); 		/**< wait for the External clock be stable */
		RCC_CFGR_R = 0x00000001; 						/**< HSE selected as system clock */
	#elif	RCC_CLOCK_TYPE == RCC_HSE_RC
		RCC_CR_R = 0x00050000; 							/**< Enable HSE with bypass */
		while(!GET_BIT(RCC_CR_R, RCC_HSERDY_BIT)); 		/**< wait for the External clock be stable */
		RCC_CFGR_R = 0x00000001; 						/**< HSE selected as system clock */
	#elif	RCC_CLOCK_TYPE == RCC_HSI				
		RCC_CR_R = 0x00000081; 							/**< Enable HSI + Trimming = 0 */
		while(!GET_BIT(RCC_CR_R, RCC_HSIRDY_BIT));		/**< wait for the Internal clock be stable */	
		RCC_CFGR_R = 0x00000000;						/**< HSI selected as system clock */
	#elif	RCC_CLOCK_TYPE == RCC_PLL
		#if RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2
			CLR_BIT(RCC_CFGR_R, RCC_PLLSRC_BIT);		/**< 0: HSI OSCILLATOR CLOCK / 2 SELECTED AS PLL INPUT CLOCK */
		#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_DIV_2
			SET_BIT(RCC_CFGR_R, RCC_PLLSRC_BIT);		/**< 1: HSE OSCILLATOR CLOCK SELECTED AS PLL INPUT CLOCK */
			SET_BIT(RCC_CFGR_R, RCC_PLLXTPRE_BIT);		/**< 1: HSE CLOCK DIVIDED BY 2 */
		#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE
			SET_BIT(RCC_CFGR_R, RCC_PLLSRC_BIT);		/**< 1: HSE OSCILLATOR CLOCK SELECTED AS PLL INPUT CLOCK */
			CLR_BIT(RCC_CFGR_R, RCC_PLLXTPRE_BIT);    	/**< 0: HSE CLOCK NOT DIVIDED */
		#else
			#error("YOU CHOSE WRONG CLOCK INPUT FOR PLL!!")
		#endif
	#else
		#error("YOU CHOSE WRONG CLOCK TYPE!!")
	#endif
}


void MRCC_voidEnableClock(u8 Copy_BusId,u8 Copy_PeriphId)
{
	if(Copy_PeriphId <=31)
	{
		switch(Copy_BusId)
		{
			case RCC_AHB  : SET_BIT(RCC_AHBENR_R , Copy_PeriphId); break;
			case RCC_APB1 : SET_BIT(RCC_APB1ENR_R, Copy_PeriphId); break;
			case RCC_APB2 : SET_BIT(RCC_APB2ENR_R, Copy_PeriphId); break;
			//default       : /* Return Error */                  break;
		}
	}
	else
	{
		//Return Error
	}
}


void MRCC_voidDisableClock(u8 Copy_BusId,u8 Copy_PeriphId)
{
	if(Copy_PeriphId <=31)
	{
		switch(Copy_BusId)
		{
			case RCC_AHB  : CLR_BIT(RCC_AHBENR_R , Copy_PeriphId); break;
			case RCC_APB1 : CLR_BIT(RCC_APB1ENR_R, Copy_PeriphId); break;
			case RCC_APB2 : CLR_BIT(RCC_APB2ENR_R, Copy_PeriphId); break;
			//default       : /* Return Error */                    break;
		}
	}
	else
	{
		//Return Error
	}
}




// u32 MRCC_GetSystemClockFreq(void)
// {
//     u32 Local_u32Freq = 0;
//     u8 clk_src = (RCC_CFGR_R >> 2) & 0x3;

//     switch (clk_src)
//     {
//         case 0x00: // HSI oscillator used as system clock
//             Local_u32Freq = 16000000; // HSI frequency is fixed at 16 MHz
//         break;
        
//         case 0x01: // HSE oscillator used as system clock
//             Local_u32Freq = RCC_HSE_VALUE; // HSE_VALUE should be defined properly
//         break;
        
//         case 0x02: // PLL used as system clock
//             u8 pll_src = (RCC_CFGR_R >> 16) & 0x3;
//             u32 pll_input_freq = 0;

//             switch (pll_src)
//             {
//                 case 0x00: // HSI oscillator divided by 2 used as PLL input clock
//                     pll_input_freq = 8000000; // HSI frequency divided by 2 is fixed at 8 MHz
//                 break;
//                 case 0x01: // HSE oscillator divided by 2 used as PLL input clock
//                     pll_input_freq = RCC_HSE_VALUE / 2;
//                 break;
//                 case 0x02: // HSE oscillator not divided used as PLL input clock
//                     pll_input_freq = RCC_HSE_VALUE;
//                 break;
//             }
//             u8 pll_mul = (RCC_CFGR_R >> 18) & 0xF;
//             freq = pll_input_freq * pll_mul;
//         break;
//     }

//     return Local_u32Freq;
// }
