/**
 **********************************************************************************************************************************
 * @brief This module contains functions for configuring and controlling General Purpose Input/Output (GPIO) pins.
 *
 * @author Mahmoud Abdelraouf Mahmoud
 * @date 26 Feb 2022
 * @version V02
 ***********************************************************************************************************************************
 * This module provides functions for configuring the mode, speed, and pull-up/down resistors of GPIO pins,
 * as well as reading and writing their values. It is designed to be used with ARM Cortex-M processors, and may not be
 * compatible with other architectures.
 *
 * @note This module is intended for use with the STM32F10x microcontroller series, but may be adapted for use with
 * other compatible processors.
 **********************************************************************************************************************************
 */
#ifndef __GPIO_INTERFACE_H__
#define __GPIO_INTERFACE_H__

/***********************************< THE AVAILABLE VALUES FOR OUTPUT ***********************************/
#define MGPIO_HIGH						1
#define MGPIO_LOW						0
/***********************************< THE AVAILABLE PORTS IN STM32F103C8 ***********************************/
#define MGPIOA							0
#define MGPIOB							1
#define MGPIOC							2
/***********************************< THE AVAILABLE PINS IN STM32F103C8 ***********************************/
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
		
#define MGPIO_OUTPUT_PP_10MHZ 			0b0001		/**< OUTPUT_PUSH-PULL, MAXIMUM OUTPUT SPEED 10 MHZ */
#define MGPIO_OUTPUT_OD_10MHZ			0b0101		/**< OUTPUT_OPEN-DRAIN, MAXIMUM OUTPUT SPEED 10 MHZ */
#define MGPIO_OUTPUT_AFPP_10MHZ			0b1001		/**< OUTPUT_ALTERNATE FUNCTION_PUSH-PULL, MAXIMUM OUTPUT SPEED 10 MHZ */
#define MGPIO_OUTPUT_AFOD_10MHZ			0b1101		/**< OUTPUT_ALTERNATE FUNCTION_OPEN-DRAIN, MAXIMUM OUTPUT SPEED 10 MHZ */
		
#define MGPIO_OUTPUT_PP_2MHZ 			0b0010		/**< OUTPUT_PUSH-PULL, MAXIMUM OUTPUT SPEED 2 MHZ */
#define MGPIO_OUTPUT_OD_2MHZ			0b0110		/**< OUTPUT_OPEN-DRAIN, MAXIMUM OUTPUT SPEED 2 MHZ */
#define MGPIO_OUTPUT_AFPP_2MHZ			0b1010		/**< OUTPUT_ALTERNATE FUNCTION_PUSH-PULL, MAXIMUM OUTPUT SPEED 2 MHZ */
#define MGPIO_OUTPUT_AFOD_2MHZ			0b1110		/**< OUTPUT_ALTERNATE FUNCTION_OPEN-DRAIN, MAXIMUM OUTPUT SPEED 2 MHZ */

#define MGPIO_OUTPUT_PP_50MHZ 			0b0011		/**< OUTPUT_PUSH-PULL, MAXIMUM OUTPUT SPEED 50 MHZ */
#define MGPIO_OUTPUT_OD_50MHZ			0b0111		/**< OUTPUT_OPEN-DRAIN, MAXIMUM OUTPUT SPEED 50 MHZ*/
#define MGPIO_OUTPUT_AFPP_50MHZ			0b1011		/**< OUTPUT_ALTERNATE FUNCTION_PUSH-PULL, MAXIMUM OUTPUT SPEED 50 MHZ*/
#define MGPIO_OUTPUT_AFOD_50MHZ			0b1111		/**< OUTPUT_ALTERNATE FUNCTION_OPEN-DRAIN, MAXIMUM OUTPUT SPEED 50 MHZ */


typedef enum {
    PORTA_INDEX = 0,
    PORTB_INDEX,
    PORTC_INDEX,
    PORTD_INDEX,
    PORTE_INDEX,
    PORTF_INDEX,
    PORTG_INDEX
}GPIO_PortIndex_t;

typedef enum {
    GPIO_PIN0 = 0,
    GPIO_PIN1,
    GPIO_PIN2,
    GPIO_PIN3,
    GPIO_PIN4,
    GPIO_PIN5,
    GPIO_PIN6,
    GPIO_PIN7,
    GPIO_PIN8,
    GPIO_PIN9,
    GPIO_PIN10,
    GPIO_PIN11,
    GPIO_PIN12,
    GPIO_PIN13,
    GPIO_PIN14,
    GPIO_PIN15
}GPIO_PinIndex_t;

typedef enum {
    /**< INPUT Direction with different modes */
    GPIO_INPUT_ANALOG       = 0b0000,   /**< INPUT_ANALOG */                     	
    GPIO_INPUT_FLOATING     = 0b0100,   /**< INPUT_FLOATING */                     
    GPIO_INPUT_PD           = 0b1000,   /**< INPUT_PULL-DOWN */                    	
    GPIO_INPUT_PU           = 0b1000,   /**< INPUT_PULL-UP */                    	
    /**< OUTPUT Direction with different modes */
    GPIO_OUTPUT_PP_10MHZ    = 0b0001,  	/**< OUTPUT_PUSH-PULL, MAXIMUM OUTPUT SPEED 10 MHZ */
    GPIO_OUTPUT_OD_10MHZ	= 0b0101,   /**< OUTPUT_OPEN-DRAIN, MAXIMUM OUTPUT SPEED 10 MHZ */
    GPIO_OUTPUT_AFPP_10MHZ	= 0b1001,   /**< OUTPUT_ALTERNATE FUNCTION_PUSH-PULL, MAXIMUM OUTPUT SPEED 10 MHZ */
    GPIO_OUTPUT_AFOD_10MHZ	= 0b1101,   /**< OUTPUT_ALTERNATE FUNCTION_OPEN-DRAIN, MAXIMUM OUTPUT SPEED 10 MHZ */

    GPIO_OUTPUT_PP_2MHZ 	= 0b0010,   /**< OUTPUT_PUSH-PULL, MAXIMUM OUTPUT SPEED 2 MHZ */
    GPIO_OUTPUT_OD_2MHZ	    = 0b0110,   /**< OUTPUT_OPEN-DRAIN, MAXIMUM OUTPUT SPEED 2 MHZ */
    GPIO_OUTPUT_AFPP_2MHZ	= 0b1010,   /**< OUTPUT_ALTERNATE FUNCTION_PUSH-PULL, MAXIMUM OUTPUT SPEED 2 MHZ */
    GPIO_OUTPUT_AFOD_2MHZ	= 0b1110,   /**< OUTPUT_ALTERNATE FUNCTION_OPEN-DRAIN, MAXIMUM OUTPUT SPEED 2 MHZ */

    GPIO_OUTPUT_PP_50MHZ 	= 0b0011,   /**< OUTPUT_PUSH-PULL, MAXIMUM OUTPUT SPEED 50 MHZ */
    GPIO_OUTPUT_OD_50MHZ	= 0b0111,   /**< OUTPUT_OPEN-DRAIN, MAXIMUM OUTPUT SPEED 50 MHZ*/
    GPIO_OUTPUT_AFPP_50MHZ	= 0b1011,   /**< OUTPUT_ALTERNATE FUNCTION_PUSH-PULL, MAXIMUM OUTPUT SPEED 50 MHZ*/
    GPIO_OUTPUT_AFOD_50MHZ	= 0b1111    /**< OUTPUT_ALTERNATE FUNCTION_OPEN-DRAIN, MAXIMUM OUTPUT SPEED 50 MHZ */	
}GPIO_PinMode_t;


typedef enum {
    GPIO_LOW  = 0,
    GPIO_HIGH = !GPIO_LOW
}GPIO_Logic_t;

/**
 * @struct GPIO_PinConfig_t
 * @brief Structure representing the configuration settings for a GPIO pin.
 *
 * This structure encapsulates the configuration settings for a GPIO pin, including its pin index,
 * pin mode, port index, and pin logic (high or low).
 *
 * @var GPIO_PinConfig_t::PinIndex
 * The pin index (0 to 15) of the GPIO pin. Refer to @ref GPIO_PinIndex_t for valid values.
 *
 * @var GPIO_PinConfig_t::PinMode
 * The pin mode of the GPIO pin. Refer to @ref GPIO_PinMode_t for valid values.
 *
 * @var GPIO_PinConfig_t::PortIndex
 * The port index (0 to 7) of the GPIO port to which the pin belongs. Refer to @ref GPIO_PortIndex_t for valid values.
 *
 * @var GPIO_PinConfig_t::PinLogic
 * The pin logic level. Use @ref GPIO_Logic_t enumeration to specify whether the pin logic is high or low.
 */
typedef struct {
    u8 PinIndex  : 4; /**< @ref GPIO_PinIndex_t */
    u8 PinMode   : 4; /**< @ref GPIO_PinMode_t */
    u8 PortIndex : 3; /**< @ref GPIO_PortIndex_t */
    u8 PinLogic  : 1; /**< @ref GPIO_Logic_t */
} GPIO_PinConfig_t;


Std_ReturnType M_GPIO_SetPinDirectionInitialize(const GPIO_PinConfig_t *Copy_psPinConfig);


/***********************************< FUNCTIONS PROTOTYPES AND DESCRIPTION ***********************************/
/**
 * @brief Configures the direction (input or output) and mode of a specific pin of a specific port in a microcontroller.
 *
 * This function sets the direction (input or output) and mode of a specific pin of a specific port in a microcontroller by configuring the corresponding pin configuration register.
 *
 * @param[in] Copy_u8PORT An 8-bit unsigned integer that represents the port that the pin belongs to. This parameter should be one of the following options: MGPIOA, MGPIOB, or MGPIOC.
 * @param[in] Copy_u8PIN An 8-bit unsigned integer that represents the pin number that the function will configure. This parameter should be one of the following options: MGPIO_PIN0, MGPIO_PIN1, MGPIO_PIN2, MGPIO_PIN3, MGPIO_PIN4, MGPIO_PIN5, MGPIO_PIN6, MGPIO_PIN7, MGPIO_PIN8, MGPIO_PIN9, MGPIO_PIN10, MGPIO_PIN11, MGPIO_PIN12, MGPIO_PIN13, MGPIO_PIN14, or MGPIO_PIN15.
 * @param[in] Copy_u8Mode An 8-bit unsigned integer that represents the mode of the pin that the function will configure. This parameter should be one of the following options:
 *            - MGPIO_INPUT_ANALOG for analog input mode
 *            - MGPIO_INPUT_FLOATING for floating input mode
 *            - MGPIO_INPUT_PD for input mode with pull-down configuration
 *            - MGPIO_INPUT_PU for input mode with pull-up configuration
 *            - MGPIO_OUTPUT_PP_10MHZ for output mode with push-pull configuration and maximum output speed of 10 MHz
 *            - MGPIO_OUTPUT_OD_10MHZ for output mode with open-drain configuration and maximum output speed of 10 MHz
 *            - MGPIO_OUTPUT_AFPP_10MHZ for alternative function mode with push-pull configuration and maximum output speed of 10 MHz
 *            - MGPIO_OUTPUT_AFOD_10MHZ for alternative function mode with open-drain configuration and maximum output speed of 10 MHz
 *            - MGPIO_OUTPUT_PP_2MHZ for output mode with push-pull configuration and maximum output speed of 2 MHz
 *            - MGPIO_OUTPUT_OD_2MHZ for output mode with open-drain configuration and maximum output speed of 2 MHz
 *            - MGPIO_OUTPUT_AFPP_2MHZ for alternative function mode with push-pull configuration and maximum output speed of 2 MHz
 *            - MGPIO_OUTPUT_AFOD_2MHZ for alternative function mode with open-drain configuration and maximum output speed of 2 MHz
 *            - MGPIO_OUTPUT_PP_50MHZ for output mode with push-pull configuration and maximum output speed of 50 MHz
 *            - MGPIO_OUTPUT_OD_50MHZ for output mode with open-drain configuration and maximum output speed of 50 MHz
 *            - MGPIO_OUTPUT_AFPP_50MHZ for alternative function mode with push-pull configuration and maximum output speed of 50 MHz
 *            - MGPIO_OUTPUT_AFOD_50MHZ for alternative function mode with open-drain configuration and maximum output speed of 50 MHz
 *
 * @retval None
 *
 * @note This function assumes that the microcontroller has 16 pins per port, and the pin configuration registers of each port are named MGPIOx_CRL_R (for pins 0 to 7) and MGPIOx_CRH_R (for pins 8 to 15) where x is the port letter (A, B, or C).
 *
 * @par Example:
 *      To configure pin 5 of port A as an output pin with push-pull configuration and maximum output speed of 50 MHz, the following code can be used:
 *      @code
 *      MGPIO_voidSetPinDirection(MGPIOA, MGPIO_PIN5, MGPIO_OUTPUT_PP_50MHZ);
 *      @endcode
 */
void MGPIO_voidSetPinDirection(u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8Mode);
/**
 * @brief Sets the value of a specific pin of a specific port in a microcontroller.
 *
 * This function sets the value (high or low) of a specific pin of a specific port in a microcontroller by writing to the corresponding output data register.
 *
 * @param[in] Copy_u8PORT An 8-bit unsigned integer that represents the port that the pin belongs to. This parameter should be one of the following options: MGPIOA, MGPIOB, or MGPIOC.
 * @param[in] Copy_u8PIN An 8-bit unsigned integer that represents the pin number that the function will set the value of. This parameter should be one of the following options: MGPIO_PIN0, MGPIO_PIN1, MGPIO_PIN2, MGPIO_PIN3, MGPIO_PIN4, MGPIO_PIN5, MGPIO_PIN6, MGPIO_PIN7, MGPIO_PIN8, MGPIO_PIN9, MGPIO_PIN10, MGPIO_PIN11, MGPIO_PIN12, MGPIO_PIN13, MGPIO_PIN14, or MGPIO_PIN15.
 * @param[in] Copy_u8Value An 8-bit unsigned integer that represents the value that the function will set the pin to. This parameter should be one of the following options:
 *            - MGPIO_HIGH to set the pin to high voltage level (logic 1)
 *            - MGPIO_LOW to set the pin to low voltage level (logic 0)
 *
 * @retval None
 *
 * @note This function assumes that the microcontroller has 16 pins per port, and the output data registers of each port are named MGPIOx_ODR_R where x is the port letter (A, B, or C).
 *
 * @par Example:
 *      To set pin 5 of port B to high voltage level, the following code can be used:
 *      @code
 *      GPIO_voidSetPinValue(MGPIOB, MGPIO_PIN5, MGPIO_HIGH);
 *      @endcode
 */
void MGPIO_voidSetPinValue(u8 Copy_u8PORT,u8 Copy_u8PIN, u8 Copy_u8Value);

/**
 * @brief Gets the value of a specific pin of a specific port in a microcontroller.
 *
 * This function gets the value (high or low) of a specific pin of a specific port in a microcontroller by reading from the corresponding input data register.
 *
 * @param[in] Copy_u8PORT An 8-bit unsigned integer that represents the port that the pin belongs to. This parameter should be one of the following options: MGPIOA, MGPIOB, or MGPIOC.
 * @param[in] Copy_u8PIN An 8-bit unsigned integer that represents the pin number that the function will get the value of. This parameter should be one of the following options: MGPIO_PIN0, MGPIO_PIN1, MGPIO_PIN2, MGPIO_PIN3, MGPIO_PIN4, MGPIO_PIN5, MGPIO_PIN6, MGPIO_PIN7, MGPIO_PIN8, MGPIO_PIN9, MGPIO_PIN10, MGPIO_PIN11, MGPIO_PIN12, MGPIO_PIN13, MGPIO_PIN14, or MGPIO_PIN15.
 *
 * @retval An 8-bit unsigned integer that represents the value of the specified pin. This parameter should be one of the following options:
 *            - 1 to indicate that the pin is at high voltage level (logic 1)
 *            - 0 to indicate that the pin is at low voltage level (logic 0)
 *
 * @note This function assumes that the microcontroller has 16 pins per port, and the input data registers of each port are named MGPIOx_IDR_R where x is the port letter (A, B, or C).
 *
 * @par Example:
 *      To get the value of pin 3 of port A, the following code can be used:
 *      @code
 *      u8 PinValue = GPIO_u8GetPinValue(MGPIOA, MGPIO_PIN3);
 *      @endcode
 */
u8  MGPIO_u8GetPinValue(u8 Copy_u8PORT, u8 Copy_u8PIN);

#endif /**< __GPIO_INTERFACE_H__ */
