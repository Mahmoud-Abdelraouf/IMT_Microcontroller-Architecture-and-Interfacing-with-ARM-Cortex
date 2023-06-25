/********************************************************************/
/************* Author    : Mahmoud Abdelraouf Mahmoud   *************/
/************* Date		 : 26 Feb 2022                  *************/
/************* Version   : V01                          *************/
/************* Module    : GPIO                         *************/
/********************************************************************/
#ifndef __GPIO_INTERFACE_H__
#define __GPIO_INTERFACE_H__

/***********************************< THE AVALIBLE VALUES FOR OUTPUT ***********************************/
#define MGPIO_HIGH						1
#define MGPIO_LOW						0

/***********************************< THE AVALIBLE PORTS IN STM32F103C8 ***********************************/
#define MGPIOA							0
#define MGPIOB							1
#define MGPIOC							2


/***********************************< THE AVALIBLE PINS IN STM32F103C8 ***********************************/
#define MGPIO_PIN0						0
#define MGPIO_PIN1        				1
#define MGPIO_PIN2        				2
#define MGPIO_PIN3        				3
#define MGPIO_PIN4        				4
#define MGPIO_PIN5        				5
#define MGPIO_PIN6        				6
#define MGPIO_PIN7        				7
#define MGPIO_PIN8        				8
#define MGPIO_PIN9        				9
#define MGPIO_PIN10       				10
#define MGPIO_PIN11       				11
#define MGPIO_PIN12       				12
#define MGPIO_PIN13       				13
#define MGPIO_PIN14       				14
#define MGPIO_PIN15       				15

/***********************************< PORT BIT CONFIGURATION OPTIONS ***********************************/
#define MGPIO_INPUT_ANALOG				0b0000		/**< INPUT_ANALOG */
#define MGPIO_INPUT_FLOATING			0b0100		/**< INPUT_FLOATING */
#define MGPIO_INPUT_PD					0b1000		/**< INPUT_PULL-DOWN */
#define MGPIO_INPUT_PU					0b1000		/**< INPUT_PULL-UP */
		
#define MGPIO_OUTPUT_PP_S10MHZ 			0b0001		/**< OUTPUT_PUSH-PULL, MAXIMUM OUTPUT SPEED 10 MHZ */
#define MGPIO_OUTPUT_OD_S10MHZ			0b0101		/**< OUTPUT_OPEN-DRAIN, MAXIMUM OUTPUT SPEED 10 MHZ */
#define MGPIO_OUTPUT_AFPP_S10MHZ		0b1001		/**< OUTPUT_ALTERNATE FUNCTION_PUSH-PULL, MAXIMUM OUTPUT SPEED 10 MHZ */
#define MGPIO_OUTPUT_AFOD_S10MHZ		0b1101		/**< OUTPUT_ALTERNATE FUNCTION_OPEN-DRAIN, MAXIMUM OUTPUT SPEED 10 MHZ */
		
#define MGPIO_OUTPUT_PP_S2MHZ 			0b0010		/**< OUTPUT_PUSH-PULL, MAXIMUM OUTPUT SPEED 2 MHZ */
#define MGPIO_OUTPUT_OD_S2MHZ			0b0110		/**< OUTPUT_OPEN-DRAIN, MAXIMUM OUTPUT SPEED 2 MHZ */
#define MGPIO_OUTPUT_AFPP_S2MHZ			0b1010		/**< OUTPUT_ALTERNATE FUNCTION_PUSH-PULL, MAXIMUM OUTPUT SPEED 2 MHZ */
#define MGPIO_OUTPUT_AFOD_S2MHZ			0b1110		/**< OUTPUT_ALTERNATE FUNCTION_OPEN-DRAIN, MAXIMUM OUTPUT SPEED 2 MHZ */

#define MGPIO_OUTPUT_PP_S50MHZ 			0b0011		/**< OUTPUT_PUSH-PULL, MAXIMUM OUTPUT SPEED 50 MHZ */
#define MGPIO_OUTPUT_OD_S50MHZ			0b0111		/**< OUTPUT_OPEN-DRAIN, MAXIMUM OUTPUT SPEED 50 MHZ*/
#define MGPIO_OUTPUT_AFPP_S50MHZ		0b1011		/**< OUTPUT_ALTERNATE FUNCTION_PUSH-PULL, MAXIMUM OUTPUT SPEED 50 MHZ*/
#define MGPIO_OUTPUT_AFOD_S50MHZ		0b1111		/**< OUTPUT_ALTERNATE FUNCTION_OPEN-DRAIN, MAXIMUM OUTPUT SPEED 50 MHZ */


/***********************************< FUNCTIONS PROTOTYPE ***********************************/
void MGPIO_voidSetPinDirection(u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8Mode);

void MGPIO_voidSetPinValue(u8 Copy_u8PORT,u8 Copy_u8PIN, u8 Copy_u8Value);

u8  MGPIO_u8GetPinValue(u8 Copy_u8PORT, u8 Copy_u8PIN);

#endif /**< __GPIO_INTERFACE_H__ */
