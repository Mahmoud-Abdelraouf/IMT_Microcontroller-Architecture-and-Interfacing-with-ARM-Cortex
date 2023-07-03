/********************************************************************/
/************* Author    : Mahmoud Abdelraouf Mahmoud   *************/
/************* Date		 : 02 Jul 2023                  *************/
/************* Version   : V01                          *************/
/************* Module    : EXTI                         *************/
/********************************************************************/
#ifndef __EXTI_PRIVATE_H__
#define __EXTI_PRIVATE_H__


/**
 * @brief Defines the line numbers for external interrupts.
 * @note Your options: FROM LINE0 TO LINE15
 */
#define LINE0 			0      /**< The line number for interrupt line 0. */
#define LINE1 			1      /**< The line number for interrupt line 1. */
#define LINE2 			2      /**< The line number for interrupt line 2. */
#define LINE3 			3      /**< The line number for interrupt line 3. */
#define LINE4 			4      /**< The line number for interrupt line 4. */
#define LINE5 			5      /**< The line number for interrupt line 5. */
#define LINE6 			6      /**< The line number for interrupt line 6. */
#define LINE7 			7      /**< The line number for interrupt line 7. */
#define LINE8 			8      /**< The line number for interrupt line 8. */
#define LINE9 			9      /**< The line number for interrupt line 9. */
#define LINE10 			10     /**< The line number for interrupt line 10. */
#define LINE11 			11     /**< The line number for interrupt line 11. */
#define LINE12 			12     /**< The line number for interrupt line 12. */
#define LINE13 			13     /**< The line number for interrupt line 13. */
#define LINE14 			14     /**< The line number for interrupt line 14. */
#define LINE15 			15     /**< The line number for interrupt line 15. */



/**
 * @brief The mode for external interrupts.
 * @note Your options: RISING, FALLING, ON_CHANGE
 */
#define RISING 			0    /**< The rising edge mode for external interrupts. */
#define FALLING 		1    /**< The falling edge mode for external interrupts. */
#define ON_CHANGE 		2    /**< The on-change mode for external interrupts. */


//*****************************************************************************
//
// EXTI registers (EXTI)
//
//*****************************************************************************
#define EXTI_BASE_ADDRESS			 0x40010400U

typedef struct EXTI_t{
	volatile u32 IMR;
	volatile u32 EMR;
	volatile u32 RTSR;
	volatile u32 FTSR;
	volatile u32 SWIER;
	volatile u32 PR;
}EXTI_t;

#define EXTI 		((volatile EXTI_t *)EXTI_BASE_ADDRESS)






#endif /**< __EXTI_PRIVATE_H__ */
