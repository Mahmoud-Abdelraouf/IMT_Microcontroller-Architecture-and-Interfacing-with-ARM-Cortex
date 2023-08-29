/**
 * @brief This module contains functions for configuring and controlling General Purpose Input/Output (GPIO) pins.
 *
 * @author Mahmoud Abdelraouf Mahmoud
 * @date 26 Feb 2022
 * @version V01
 *
 * This module provides functions for configuring the mode, speed, and pull-up/down resistors of GPIO pins,
 * as well as reading and writing their values. It is designed to be used with ARM Cortex-M processors, and may not be
 * compatible with other architectures.
 *
 * @note This module is intended for use with the STM32F10x microcontroller series, but may be adapted for use with
 * other compatible processors.
 */
#ifndef __GPIO_PRIVATE_H__
#define __GPIO_PRIVATE_H__

#define MGPIOA_BASE_ADDRESS	 0x40010800
#define MGPIOB_BASE_ADDRESS	 0x40010C00
#define MGPIOC_BASE_ADDRESS	 0x40011000

/******************************************< REGISTERS ADDRESSES FOR PORT A ******************************************/
#define MGPIOA_CRL_R			*((volatile u32 *)(MGPIOA_BASE_ADDRESS + 0x00)) 	/**< PORT A CONFIGURATION REGISTER LOW */
#define MGPIOA_CRH_R			*((volatile u32 *)(MGPIOA_BASE_ADDRESS + 0x04)) 	/**< PORT A CONFIGURATION REGISTER HIGH */
#define MGPIOA_IDR_R			*((volatile u32 *)(MGPIOA_BASE_ADDRESS + 0x08))		/**< PORT A INPUT DATA REGISTER */
#define MGPIOA_ODR_R			*((volatile u32 *)(MGPIOA_BASE_ADDRESS + 0x0C))		/**< PORT A OUTPUT DATA REGISTER */
#define MGPIOA_BSR_R 			*((volatile u32 *)(MGPIOA_BASE_ADDRESS + 0x10))		/**< PORT A BIT SET/RESET REGISTER */
#define MGPIOA_BRR_R			*((volatile u32 *)(MGPIOA_BASE_ADDRESS + 0x14)) 	/**< PORT A BIT RESET REGISTER */
#define MGPIOA_LCK_R	    	*((volatile u32 *)(MGPIOA_BASE_ADDRESS + 0x18)) 	/**< PORT A CONFIGURATION LOCK REGISTER */

/******************************************< REGISTERS ADDRESSES FOR PORT B ******************************************/
#define MGPIOB_CRL_R			*((volatile u32 *)(MGPIOB_BASE_ADDRESS + 0x00))		/**< PORT B CONFIGURATION REGISTER LOW */
#define MGPIOB_CRH_R			*((volatile u32 *)(MGPIOB_BASE_ADDRESS + 0x04))  	/**< PORT B CONFIGURATION REGISTER HIGH */
#define MGPIOB_IDR_R			*((volatile u32 *)(MGPIOB_BASE_ADDRESS + 0x08))  	/**< PORT B INPUT DATA REGISTER */
#define MGPIOB_ODR_R			*((volatile u32 *)(MGPIOB_BASE_ADDRESS + 0x0C))  	/**< PORT B OUTPUT DATA REGISTER */
#define MGPIOB_BSR_R 			*((volatile u32 *)(MGPIOB_BASE_ADDRESS + 0x10))		/**< PORT B BIT SET/RESET REGISTER */
#define MGPIOB_BRR_R			*((volatile u32 *)(MGPIOB_BASE_ADDRESS + 0x14))		/**< PORT B BIT RESET REGISTER */
#define MGPIOB_LCK_R	    	*((volatile u32 *)(MGPIOB_BASE_ADDRESS + 0x18))		/**< PORT B CONFIGURATION LOCK REGISTER */

/******************************************< REGISTERS ADDRESSES FOR PORT C ******************************************/
#define MGPIOC_CRL_R			*((volatile u32 *)(MGPIOC_BASE_ADDRESS + 0x00))		/**< PORT C CONFIGURATION REGISTER LOW */
#define MGPIOC_CRH_R			*((volatile u32 *)(MGPIOC_BASE_ADDRESS + 0x04))   	/**< PORT C CONFIGURATION REGISTER HIGH */
#define MGPIOC_IDR_R			*((volatile u32 *)(MGPIOC_BASE_ADDRESS + 0x08))   	/**< PORT C INPUT DATA REGISTER */
#define MGPIOC_ODR_R			*((volatile u32 *)(MGPIOC_BASE_ADDRESS + 0x0C))   	/**< PORT C OUTPUT DATA REGISTER */
#define MGPIOC_BSR_R 			*((volatile u32 *)(MGPIOC_BASE_ADDRESS + 0x10))		/**< PORT C BIT SET/RESET REGISTER */
#define MGPIOC_BRR_R			*((volatile u32 *)(MGPIOC_BASE_ADDRESS + 0x14))   	/**< PORT C BIT RESET REGISTER */
#define MGPIOC_LCK_R	    	*((volatile u32 *)(MGPIOC_BASE_ADDRESS + 0x18))  	/**< PORT C CONFIGURATION LOCK REGISTER */



#endif /**< __GPIO_PRIVATE_H__ */
