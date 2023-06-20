/********************************************************************/
/************* Author    : Mahmoud Abdelraouf Mahmoud   *************/
/************* Date		 : 26 Feb 2022                  *************/
/************* Version   : V01                          *************/
/************* Module    : GPIO                         *************/
/********************************************************************/
#ifndef __GPIO_INTERFACE_H__
#define __GPIO_INTERFACE_H__

/***********************************< THE AVALIBLE VALUES FOR OUTPUT ***********************************/
#define GPIO_HIGH						1
#define GPIO_LOW						0

/***********************************< THE AVALIBLE PORTS IN STM32F103C8 ***********************************/
#define GPIOA							0
#define GPIOB							1
#define GPIOC							2


/***********************************< THE AVALIBLE PINS IN STM32F103C8 ***********************************/
#define GPIO_PIN0						0
#define GPIO_PIN1        				1
#define GPIO_PIN2        				2
#define GPIO_PIN3        				3
#define GPIO_PIN4        				4
#define GPIO_PIN5        				5
#define GPIO_PIN6        				6
#define GPIO_PIN7        				7
#define GPIO_PIN8        				8
#define GPIO_PIN9        				9
#define GPIO_PIN10       				10
#define GPIO_PIN11       				11
#define GPIO_PIN12       				12
#define GPIO_PIN13       				13
#define GPIO_PIN14       				14
#define GPIO_PIN15       				15

/***********************************< PORT BIT CONFIGURATION OPTIONS ***********************************/
#define GPIO_INPUT_ANALOG			0b0000		/**< INPUT_ANALOG */
#define GPIO_INPUT_FLOATING			0b0100		/**< INPUT_FLOATING */
#define GPIO_INPUT_PD				0b1000		/**< INPUT_PULL-DOWN */
#define GPIO_INPUT_PU				0b1000		/**< INPUT_PULL-UP */
		
#define GPIO_OUTPUT_PP_S10MHZ 		0b0001		/**< OUTPUT_PUSH-PULL, MAXIMUM OUTPUT SPEED 10 MHZ */
#define GPIO_OUTPUT_OD_S10MHZ		0b0101		/**< OUTPUT_OPEN-DRAIN, MAXIMUM OUTPUT SPEED 10 MHZ */
#define GPIO_OUTPUT_AFPP_S10MHZ		0b1001		/**< OUTPUT_ALTERNATE FUNCTION_PUSH-PULL, MAXIMUM OUTPUT SPEED 10 MHZ */
#define GPIO_OUTPUT_AFOD_S10MHZ		0b1101		/**< OUTPUT_ALTERNATE FUNCTION_OPEN-DRAIN, MAXIMUM OUTPUT SPEED 10 MHZ */
		
#define GPIO_OUTPUT_PP_S2MHZ 		0b0010		/**< OUTPUT_PUSH-PULL, MAXIMUM OUTPUT SPEED 2 MHZ */
#define GPIO_OUTPUT_OD_S2MHZ		0b0110		/**< OUTPUT_OPEN-DRAIN, MAXIMUM OUTPUT SPEED 2 MHZ */
#define GPIO_OUTPUT_AFPP_S2MHZ		0b1010		/**< OUTPUT_ALTERNATE FUNCTION_PUSH-PULL, MAXIMUM OUTPUT SPEED 2 MHZ */
#define GPIO_OUTPUT_AFOD_S2MHZ		0b1110		/**< OUTPUT_ALTERNATE FUNCTION_OPEN-DRAIN, MAXIMUM OUTPUT SPEED 2 MHZ */
		
#define GPIO_OUTPUT_PP_S50MHZ 		0b0011		/**< OUTPUT_PUSH-PULL, MAXIMUM OUTPUT SPEED 50 MHZ */
#define GPIO_OUTPUT_OD_S50MHZ		0b0111		/**< OUTPUT_OPEN-DRAIN, MAXIMUM OUTPUT SPEED 50 MHZ*/
#define GPIO_OUTPUT_AFPP_S50MHZ		0b1011		/**< OUTPUT_ALTERNATE FUNCTION_PUSH-PULL, MAXIMUM OUTPUT SPEED 50 MHZ*/
#define GPIO_OUTPUT_AFOD_S50MHZ		0b1111		/**< OUTPUT_ALTERNATE FUNCTION_OPEN-DRAIN, MAXIMUM OUTPUT SPEED 50 MHZ */


/***********************************< FUNCTIONS PROTOTYPE ***********************************/
void GPIO_voidSetPinDirection(u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8Mode);

void GPIO_voidSetPinValue(u8 Copy_u8PORT,u8 Copy_u8PIN, u8 Copy_u8Value);

u8  GPIO_u8GetPinValue(u8 Copy_u8PORT, u8 Copy_u8PIN);

#endif /**< __GPIO_INTERFACE_H__ */
