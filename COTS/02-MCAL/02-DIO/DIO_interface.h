/********************************************************************/
/************* Author    : Mahmoud Abdelraouf Mahmoud   *************/
/************* Date		 : 26 Feb 2022                  *************/
/************* Version   : V01                          *************/
/************* Module    : GPIO                         *************/
/********************************************************************/
#ifndef __DIO_INTERFACE_H__
#define __DIO_INTERFACE_H__

/*********************< THE AVALIBLE PORTS IN STM32F103C8 *********************/
#define GPIOA		0
#define GPIOB		1
#define GPIOC		2


/*********************< THE AVALIBLE PINS IN STM32F103C8 *********************/
#define PIN0		0
#define PIN1        1
#define PIN2        2
#define PIN3        3
#define PIN4        4
#define PIN5        5
#define PIN6        6
#define PIN7        7
#define PIN8        8
#define PIN9        9
#define PIN10       10
#define PIN11       11
#define PIN12       12
#define PIN13       13
#define PIN14       14
#define PIN15       15

void MGPIO_voidSetPinDirection(u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8Mode);

void MGPIO_voidSetPinValue(u8 Copy_u8PORT, Copy_u8PIN, u8 Copy_u8Value);

u8  MGPIO_u8GetPinValue(u8 Copy_u8PORT, u8 Copy_u8PIN);

#endif