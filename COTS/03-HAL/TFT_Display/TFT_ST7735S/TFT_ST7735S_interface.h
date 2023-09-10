/**
 ********************************************************************************************
 * @file TFT_Displays_interface.h
 * @brief This file contains the interface of the TFT Displays module.
 * 
 * This module provides functions for interfacing with TFT (Thin-Film Transistor) displays
 * to control graphical user interfaces (GUIs), display images, and render text.
 ********************************************************************************************
 * @date 20 Jul 2023
 * @version V01
 * @author Mahmoud Abdelraouf Mahmoud
 *
 * @note This module is designed to work with various TFT display controllers.
 * @attention Before using this module, make sure to configure the display controller
 * and the required GPIO pins for communication and control.
 *
 * @see TFT_Configuration_Options for configuration options.
 * @see TFT_Functions for available functions.
 ********************************************************************************************
 */

#ifndef __TFT_ST7735S_DISPLAYS_INTERFACE_H__
#define __TFT_ST7735S_DISPLAYS_INTERFACE_H__


/**
 * @addtogroup TFT_Displays_Module
 * @{
 */

/**
 * @defgroup TFT_Configuration_Options TFT Configuration Options
 * @brief Configuration options for the TFT Displays module.
 * @{
 */

/**
 * @brief Enumeration of common colors in 16-bit RGB565 format.
 */
typedef enum
{
    TFT_COLOR_BLACK         = 0x0000,   /**< Black color (0, 0, 0) */
    TFT_COLOR_WHITE         = 0xFFFF,   /**< White color (255, 255, 255) */
    TFT_COLOR_RED           = 0xF800,   /**< Red color (255, 0, 0) */
    TFT_COLOR_GREEN         = 0x07E0,   /**< Green color (0, 255, 0) */
    TFT_COLOR_BLUE          = 0x001F,   /**< Blue color (0, 0, 255) */
    TFT_COLOR_YELLOW        = 0xFFE0,   /**< Yellow color (255, 255, 0) */
    TFT_COLOR_MAGENTA       = 0xF81F,   /**< Magenta color (255, 0, 255) */
    TFT_COLOR_CYAN          = 0x07FF,   /**< Cyan color (0, 255, 255) */
    TFT_COLOR_GRAY          = 0x7BEF,   /**< Gray color (128, 128, 128) */
    TFT_COLOR_ORANGE        = 0xFD20,   /**< Orange color (255, 165, 0) */
    TFT_COLOR_PINK          = 0xFC18,   /**< Pink color (255, 192, 203) */
    TFT_COLOR_PURPLE        = 0x8010,   /**< Purple color (128, 0, 128) */
    TFT_COLOR_BROWN         = 0xA145,   /**< Brown color (165, 42, 42) */
    TFT_COLOR_GOLD          = 0xFEA0,   /**< Gold color (255, 215, 0) */
    TFT_COLOR_SILVER        = 0xC618    /**< Silver color (192, 192, 192) */
} TFT_Color_t;

/**
 * @struct TFT_PinPairs
 * @brief Structure to represent GPIO port and pin pairs for TFT signals.
 *
 * This structure defines pairs of GPIO port index and pin number that are used to represent TFT signals.
 * It is designed to be used in configurations for interfacing with TFT modules.
 */
typedef struct {
    u8 TFT_Port : 4; /**< GPIO port index for TFT signals (3 bits). */
    u8 TFT_Pin  : 4; /**< Pin number for TFT signals (4 bits). */
} TFT_PinPairs;

/**
 * @struct TFT_Config_t
 * @brief TFT LCD Configuration Structure
 *
 * This structure defines the configuration parameters for the TFT LCD module.
 * It specifies the GPIO port and pin pairs for various signals, the SPI peripheral,
 * and the SPI clock speed for communication.
 */
typedef struct {
    TFT_PinPairs TFT_CSPin;     /**< Chip Select (CS) pin configuration. */
    TFT_PinPairs TFT_DCPin;     /**< Data/Command Control (DC) pin configuration. */
    TFT_PinPairs TFT_SDAPin;    /**< Serial Data Input (SDA) pin configuration. */
    TFT_PinPairs TFT_RESPin;    /**< LCM Reset (RES) pin configuration. */
} TFT_Config_t;

///**
// * @brief Structure representing the font used for rendering text on the TFT display.
// *
// * This structure defines the font size and style used for rendering text on the TFT display.
// * It includes members for the font width, height, and the array of character bitmaps.
// */
//typedef struct
//{
//    u8 width;           /**< Width of the font characters in pixels */
//    u8 height;          /**< Height of the font characters in pixels */
//    const u16 *charMap; /**< Pointer to the array of character bitmaps in RGB565 format */
//} Font_t;

/** @} TFT_Configuration_Options */

/**
 * @defgroup TFT_Functions TFT Functions
 * @brief Functions for controlling the TFT display.
 * @{
 */

/**
 * @brief Initialize the TFT display using ILI9481 commands.
 *
 * This function initializes the TFT display using ILI9481 commands. It configures various parameters
 * and settings to properly initialize the display.
 *
 * @param Copy_psTftDisplay Pointer to the TFT configuration structure.
 * @param Copy_psSpiPeripheral Pointer to the SPI peripheral used for communication with the TFT.
 *
 * @note This function sends a series of commands to configure the TFT display.
 */
void TFT_Init(const TFT_Config_t *Copy_TftDisplay, SPI_t Copy_SpiPeripheral);

/**
 * @brief Clears the TFT screen by filling it with the default background color.
 *
 * This function clears the entire TFT screen by filling it with the default background color.
 *
 * @param[in] Copy_TftDisplay Pointer to the TFT display configuration structure.
 * @param[in] Copy_SpiPeripheral The SPI peripheral to be used for communication.
 * @retval None
 */
void TFT_ClearScreen(const TFT_Config_t *Copy_TftDisplay, const SPI_t Copy_SpiPeripheral);

/**
 * @brief Draws a line between two points with the given color.
 *
 * This function draws a line between the specified starting point (x1, y1) and
 * the ending point (x2, y2) with the specified color.
 *
 * @param[in] x1 The X-coordinate of the starting point.
 * @param[in] y1 The Y-coordinate of the starting point.
 * @param[in] x2 The X-coordinate of the ending point.
 * @param[in] y2 The Y-coordinate of the ending point.
 * @param[in] color The color of the line in 16-bit RGB565 format.
 * @retval None
 */
void TFT_DrawLine(const TFT_Config_t *Copy_TftDisplay, const SPI_t Copy_SpiPeripheral, u16 x1, u16 y1, u16 x2, u16 y2, u16 color);

/**
 * @brief Displays an image on the TFT screen.
 *
 * This function displays an image stored in memory at the specified (x, y) coordinates.
 *
 * @param[in] Copy_psTftDisplay Pointer to the TFT display configuration structure.
 * @param[in] Copy_psSpiPeripheral The SPI peripheral to be used for communication.
 * @param[in] Copy_XPosition The X-coordinate where the image will be displayed.
 * @param[in] Copy_YPosition The Y-coordinate where the image will be displayed.
 * @param[in] image Pointer to the image data in RGB565 format.
 * @retval None
 */
void TFT_DisplayImage(const TFT_Config_t *Copy_TftDisplay, const SPI_t Copy_SpiPeripheral, const u16 *Copy_Image);

/**
 * @brief Displays text on the TFT screen.
 *
 * This function displays text at the specified (x, y) coordinates with the given color.
 *
 * @param[in] x The X-coordinate where the text will be displayed.
 * @param[in] y The Y-coordinate where the text will be displayed.
 * @param[in] text Pointer to the text string to be displayed.
 * @param[in] font The font size and style to use for rendering the text.
 * @param[in] color The color of the text in 16-bit RGB565 format.
 * @retval None
 */
//void TFT_voidDisplayText(u16 x, u16 y, const char* text, const Font_t* font, u16 color);

/** @} TFT_Functions */


#endif /**< __TFT_ST7735S_DISPLAYS_INTERFACE_H__ */
