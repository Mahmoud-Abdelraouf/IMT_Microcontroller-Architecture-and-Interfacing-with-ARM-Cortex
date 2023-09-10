/**
 ******************************************************************************************** 
 * @file TFT_Displays_config.h
 * @brief This file contains the configuration options for the TFT Displays module.
 ********************************************************************************************
 * @date 3 Sep 2023
 * @version V01
 * @author Mahmoud Abdelraouf Mahmoud
 *
 * @note Before using this module, make sure to configure the display controller
 * and the required GPIO pins for communication and control.
 *
 * @attention The configuration options in this file should be adjusted according to
 * the specific TFT display used and the microcontroller's capabilities.
 ********************************************************************************************
 */

#ifndef __TFT_HX8357B_DISPLAYS_CONFIG_H__
#define __TFT_HX8357B_DISPLAYS_CONFIG_H__



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
 *
 * User options for this macro include:
 * - COLOR_BLACK       0x0000   Black Color (RGB565)
 * - COLOR_WHITE       0xFFFF   White Color (RGB565)
 * - COLOR_RED         0xF800   Red Color (RGB565)
 * - COLOR_GREEN       0x07E0   Green Color (RGB565)
 * - COLOR_BLUE        0x001F   Blue Color (RGB565)
 * - COLOR_CYAN        0x07FF   Cyan Color (RGB565)
 * - COLOR_MAGENTA     0xF81F   Magenta Color (RGB565)
 * - COLOR_YELLOW      0xFFE0   Yellow Color (RGB565)
 * - COLOR_ORANGE      0xFD20   Orange Color (RGB565)
 * - COLOR_PURPLE      0x8010   Purple Color (RGB565)
 * - COLOR_PINK        0xF81F   Pink Color (RGB565)
 * - COLOR_LIME        0x07E0   Lime Color (RGB565)
 * - COLOR_TEAL        0x0410   Teal Color (RGB565)
 * - COLOR_VIOLET      0x801F   Violet Color (RGB565)
 * - COLOR_BROWN       0xA145   Brown Color (RGB565)
 */
#define TFT_DEFAULT_BACKGROUND_COLOR    COLOR_BLACK

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

#endif /**< __TFT_HX8357B_DISPLAYS_CONFIG_H__ */
