/**
 * @file TFT_Displays_config.h
 * @brief This file contains the configuration options for the TFT Displays module.
 *
 * @date 20 Jul 2023
 * @version V01
 * @author Mahmoud Abdelraouf Mahmoud
 *
 * @note Before using this module, make sure to configure the display controller
 * and the required GPIO pins for communication and control.
 *
 * @attention The configuration options in this file should be adjusted according to
 * the specific TFT display used and the microcontroller's capabilities.
 */

#ifndef __TFT_ST7735S_DISPLAYS_CONFIG_H__
#define __TFT_ST7735S_DISPLAYS_CONFIG_H__



/**
 * @addtogroup TFT_Configuration_Options TFT Configuration Options
 * @brief Configuration options for the TFT Displays module.
 * @{
 */

/**
 * @brief Defines the TFT display width in pixels.
 *
 * This option should be set to the width of the TFT display in pixels.
 * For example, if the display has a resolution of 240x320, WIDTH should be set to 240.
 */
#define TFT_DISPLAY_WIDTH           320

/**
 * @brief Defines the TFT display height in pixels.
 *
 * This option should be set to the height of the TFT display in pixels.
 * For example, if the display has a resolution of 240x320, HEIGHT should be set to 320.
 */
#define TFT_DISPLAY_HEIGHT          480

/**
 * @brief Defines the maximum number of colors supported by the TFT display.
 *
 * This option should be set to the number of colors supported by the TFT display.
 * For example, if the display supports 65,536 colors (16-bit RGB565), COLORS should be set to TFT_DISPLAY_COLORS_16BIT.
 *
 * Available options:
 * - @ref _3BIT_PER_PIXEL: Supports 8 colors (RGB111).
 * - @ref _16BIT_PER_PIXEL: Supports 65,536 colors (RGB565).
 * - @ref _18BIT_PER_PIXEL: Supports 262,144 colors (RGB666).
 */
#define TFT_DISPLAY_COLORS          _16BIT_PER_PIXEL

/**
 * @brief Defines the default background color for the TFT display.
 *
 * This option should be set to the default background color used when clearing the display.
 * The color is represented in 16-bit RGB565 format.
 * For example, BLACK can be represented as 0x0000 (RGB565 value).
 */
#define TFT_DEFAULT_BACKGROUND_COLOR    0x0000

///**
// * @brief Structure representing the font used for rendering text on the TFT display.
// *
// * This option should be set to the default font used for rendering text on the display.
// * The font is defined as a structure that includes the font data and size.
// * For example:
// *
// * @code{c}
// * typedef struct
// * {
// *   u8 width;              // Width of the font characters in pixels
// *   u8 height;             // Height of the font characters in pixels
// *   const u16 *charMap;    // Pointer to the array of character bitmaps in RGB565 format
// * } Font_t;
// * @endcode
// *
// * @see Font_t for more details on defining the font structure.
// */
//extern const Font_t TFT_DEFAULT_FONT;

/**
 * @brief Defines the communication interface used to communicate with the TFT display.
 *
 * This option should be set to the communication interface used to communicate with the TFT display.
 * For example, if the display uses SPI for communication, set TFT_COMM_INTERFACE to `TFT_COMM_INTERFACE_SPI`.
 * If the display uses I2C, set `TFT_COMM_INTERFACE` to TFT_COMM_INTERFACE_I2C.
 */
#define TFT_COMM_INTERFACE          TFT_COMM_INTERFACE_SPI

/** @} TFT_Configuration_Options */

#endif /**< __TFT_ST7735S_DISPLAYS_CONFIG_H__ */
