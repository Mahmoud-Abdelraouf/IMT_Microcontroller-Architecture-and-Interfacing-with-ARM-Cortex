/********************************************************************/
/************* Author    : Mahmoud Abdelraouf Mahmoud   *************/
/************* Date		 : 25 Feb 2022                  *************/
/************* Version   : V01                          *************/
/********************************************************************/
#ifndef __RCC_CONFIG_H__
#define __RCC_CONFIG_H__



/**	YOUR OPTIONS:
 *		RCC_HSE_CRYSTAL
 *		RCC_HSE_RC
 *		RCC_HSI
 *		RCC_PLL
 */
#define RCC_CLOCK_TYPE				RCC_HSE_CRYSTAL

/** YOUR OPTIONS:
 *		RCC_PLL_IN_HSI_DIV_2
 *		RCC_PLL_IN_HSE_DIV_2
 *		RCC_PLL_IN_HSE
 *	Note:
 *		Select value only if you have PLL as input clock
 */
#if RCC_CLOCK_TYPE == RCC_PLL
	#define RCC_PLL_INPUT			RCC_PLL_IN_HSI_DIV_2
#endif

/** YOUR OPTIONS:
 *		From 2 to 16
 *	Note:
 *		Select value only if you have PLL as input clock
 */
#if RCC_CLOCK_TYPE == RCC_PLL
	#define RCC_PLL_MUL_VAL			4
#endif



#endif/**< __RCC_CONFIG_H__ */
