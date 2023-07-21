/**
 * @file TFT_Displays_private.h
 * @brief This file contains private definitions and declarations for the TFT Displays module.
 *
 * @date 20 Jul 2023
 * @version V01
 * @author Mahmoud Abdelraouf Mahmoud
 *
 * @attention This file contains internal/private functions, constants, and structures for
 * the TFT Displays module. Users of this module should not directly interact with these
 * definitions as they are intended for internal use only.
 */

#ifndef __TFT_DISPLAYS_PRIVATE_H__
#define __TFT_DISPLAYS_PRIVATE_H__


/**
 * @addtogroup TFT_Private_Functions TFT Private Functions
 * @brief Internal/private functions for the TFT Displays module.
 * @{
 */

/**
 * @brief Enumeration for communication interfaces used with the TFT display.
 *
 * This enumeration defines the possible communication interfaces that can be used
 * to communicate with the TFT display.
 */
typedef enum
{
    TFT_COMM_INTERFACE_SPI, /**< SPI communication interface */
    TFT_COMM_INTERFACE_I2C  /**< I2C communication interface */
} TFT_CommInterface_t;

/**
 * @brief Structure representing the TFT display controller.
 *
 * This structure defines the configuration settings and control variables for the TFT display controller.
 * It includes members for communication interface, GPIO pins, font, and other necessary settings.
 */
typedef struct
{
    TFT_CommInterface_t commInterface; /**< Communication interface used for the TFT display */
    /* Add other members for GPIO pins, font, etc. */
} TFT_DisplayController_t;

/**
 * @brief Internal function to send commands to the TFT display controller.
 *
 * This function is used internally to send commands to the TFT display controller
 * using the specified communication interface.
 *
 * @param command The command byte to be sent.
 */
static void TFT_SendCommand(u8 command);

/**
 * @brief Internal function to send data to the TFT display controller.
 *
 * This function is used internally to send data to the TFT display controller
 * using the specified communication interface.
 *
 * @param data The data byte to be sent.
 */
static void TFT_SendData(u8 data);

/**
 * @brief Internal function to initialize the TFT display controller.
 *
 * This function is used internally to initialize the TFT display controller
 * based on the configuration settings provided in the TFT_DisplayController_t structure.
 */
static void TFT_InitController(void);

/**
 * @brief Internal function to draw a pixel on the TFT display.
 *
 * This function is used internally to draw a pixel on the TFT display at the specified
 * coordinates using the specified color.
 *
 * @param x The x-coordinate of the pixel.
 * @param y The y-coordinate of the pixel.
 * @param color The color of the pixel in 16-bit RGB565 format.
 */
static void TFT_DrawPixel(u16 x, u16 y, u16 color);

/**
 * @brief Internal function to draw a character on the TFT display.
 *
 * This function is used internally to draw a character on the TFT display at the specified
 * coordinates using the specified font and color.
 *
 * @param x The x-coordinate of the character.
 * @param y The y-coordinate of the character.
 * @param character The character to be drawn.
 * @param font Pointer to the font data structure.
 * @param textColor The color of the character in 16-bit RGB565 format.
 * @param backgroundColor The background color of the character in 16-bit RGB565 format.
 */
static void TFT_DrawCharacter(u16 x, u16 y, char character, const Font_t *font, u16 textColor, u16 backgroundColor);

/* Add more internal functions and private declarations as needed */

/** @} TFT_Private_Functions */

#endif /**< __TFT_DISPLAYS_PRIVATE_H__ */
