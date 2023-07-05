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
#ifndef __RCC_INTERFACE_H__
#define __RCC_INTERFACE_H__

/********************************< Bus Architecture options ********************************/
#define RCC_AHB 				0
#define RCC_APB1				1
#define RCC_APB2				2

/********************************< APB2 PERIPHERAL RESET REGISTER ********************************/
#define RCC_AFIO            	0
#define RCC_IOPA            	2
#define RCC_IOPB            	3
#define RCC_IOPC            	4
#define RCC_IOPD			 	5
#define RCC_IOPE			 	6
#define RCC_IOPF			 	7
#define RCC_IOPG			 	8


/********************************< FUNCTIONs IMPLEMENTATION ********************************/
/**
 * @brief 
 * @param 
 * @retval None
*/
void RCC_voidInitSysClock(void);

/**
 * @brief Enables the clock for a specific peripheral on a specific bus.
 * @param Copy_BusId The bus ID to enable the clock on (RCC_BUS_AHB, RCC_BUS_APB1, RCC_BUS_APB2).
 *		YOUR_OPTIONS:
 *					1) RCC_AHB
 *					2) RCC_APB1
 *					3) RCC_APB2
 * @param Copy_u8PeriphId The peripheral ID to enable the clock for (0-31). 
 *		YOUR_OPTIONS:
 *					1) RCC_AFIO
 *					2) RCC_IOPA
 *					3) RCC_IOPB
 *					4) RCC_IOPC
 *					5) RCC_IOPD
 *					6) RCC_IOPE
 *					7) RCC_IOPF
 *					8) RCC_IOPG
 * @retval None
 * 
 */
void RCC_voidEnableClock(u8 Copy_u8BusId,u8 Copy_u8PeriphId);




#endif /**< __RCC_INTERFACE_H__ */
