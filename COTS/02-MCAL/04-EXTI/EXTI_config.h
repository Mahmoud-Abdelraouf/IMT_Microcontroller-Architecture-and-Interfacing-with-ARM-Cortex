/********************************************************************/
/************* Author    : Mahmoud Abdelraouf Mahmoud   *************/
/************* Date		 : 02 Jul 2023                  *************/
/************* Version   : V01                          *************/
/************* Module    : EXTI                         *************/
/********************************************************************/
#ifndef __EXTI_CONFIG_H__
#define __EXTI_CONFIG_H__

/**
 * @brief The external interrupt line number.
 * @note Your options: FROM LINE0 TO LINE15
 */
#define EXTI_LINE 		LINE0  /**< The line number for external interrupts. */



/**
 * @brief The mode for external interrupts.
 * @note Your options: RISING, FALLING, ON_CHANGE
 */
#define EXTI_MODE 		RISING /**< The mode for external interrupts. Can be RISING, FALLING, or ON_CHANGE. */




#endif /**< __EXTI_CONFIG_H__ */
