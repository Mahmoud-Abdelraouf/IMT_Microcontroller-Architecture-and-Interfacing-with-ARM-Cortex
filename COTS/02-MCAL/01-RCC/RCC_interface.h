/*******************************************************/
/***** Author    : Mahmoud Abdelraouf Mahmoud   ********/
/***** Date		 : 25 Feb 2022                  ********/
/***** Version   : V01                          ********/
/*******************************************************/
#ifndef __RCC_INTERFACE_H__
#define __RCC_INTERFACE_H__

/********************************< Bus Architecture options ********************************/
#define RCC_AHB 				0
#define RCC_APB1				1
#define RCC_APB2				2



void RCC_voidInitSysClock(void);

/**
 * @brief Enables the clock for a specific peripheral on a specific bus.
 * @param Copy_BusId The bus ID to enable the clock on (RCC_BUS_AHB, RCC_BUS_APB1, RCC_BUS_APB2).
 * @param Copy_u8PeriphId The peripheral ID to enable the clock for (0-31).
 * @retval None
 */
void RCC_voidEnableClock(u8 Copy_u8BusId,Copy_u8PeriphId);




#endif