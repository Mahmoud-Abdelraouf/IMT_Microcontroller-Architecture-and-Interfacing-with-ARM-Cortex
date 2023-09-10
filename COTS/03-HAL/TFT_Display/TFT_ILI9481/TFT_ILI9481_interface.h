/**
 * @defgroup TFT_Displays_Module TFT Displays Module
 * @{
 */

/**
 * @file TFT_Displays_interface.h
 * @brief This file contains the interface of the TFT Displays module.
 * 
 * This module provides functions for interfacing with TFT (Thin-Film Transistor) displays
 * to control graphical user interfaces (GUIs), display images, and render text.
 *
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
 */

#ifndef __TFT_ILI9481_DISPLAYS_INTERFACE_H__
#define __TFT_ILI9481_DISPLAYS_INTERFACE_H__


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
    COLOR_BLACK         = 0x0000,   /**< Black color (0, 0, 0) */
    COLOR_WHITE         = 0xFFFF,   /**< White color (255, 255, 255) */
    COLOR_RED           = 0xF800,   /**< Red color (255, 0, 0) */
    COLOR_GREEN         = 0x07E0,   /**< Green color (0, 255, 0) */
    COLOR_BLUE          = 0x001F,   /**< Blue color (0, 0, 255) */
    COLOR_YELLOW        = 0xFFE0,   /**< Yellow color (255, 255, 0) */
    COLOR_MAGENTA       = 0xF81F,   /**< Magenta color (255, 0, 255) */
    COLOR_CYAN          = 0x07FF,   /**< Cyan color (0, 255, 255) */
    COLOR_GRAY          = 0x7BEF,   /**< Gray color (128, 128, 128) */
    COLOR_ORANGE        = 0xFD20,   /**< Orange color (255, 165, 0) */
    COLOR_PINK          = 0xFC18,   /**< Pink color (255, 192, 203) */
    COLOR_PURPLE        = 0x8010,   /**< Purple color (128, 0, 128) */
    COLOR_BROWN         = 0xA145,   /**< Brown color (165, 42, 42) */
    COLOR_GOLD          = 0xFEA0,   /**< Gold color (255, 215, 0) */
    COLOR_SILVER        = 0xC618    /**< Silver color (192, 192, 192) */
} TFT_Color_t;




/**
 * @struct TFT_Config_t
 * @brief TFT LCD Configuration Structure
 *
 * This structure defines the configuration parameters for the TFT LCD module.
 * It specifies the GPIO port and pins for various signals, the SPI peripheral,
 * and the SPI clock speed for communication.
 */
typedef struct {
    /**< u32 TFT_SpiClkSpeed;        /**< SPI clock speed */
    u8 TFT_Port  : 3;                /**< GPIO port index for TFT signals */
    u8 TFT_CsPin : 4;                /**< Chip Select (CS) pin number */
    u8 TFT_RsPin : 4;                /**< Register Select (RS) pin number */
    u8 TFT_WrPin : 4;                /**< Write Control (WR) pin number */
    u8 TFT_RstPin: 4;                /**< Reset (RST) pin number */
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
 * @param Copy_psTheSpiTftUsed Pointer to the SPI peripheral used for communication with the TFT.
 *
 * @note This function sends a series of commands to configure the TFT display.
 */
void TFT_Init(const TFT_Config_t *Copy_psTftDisplay, SPI_t Copy_psTheSpiTftUsed);

/**
 * @brief Clears the display screen.
 *
 * This function clears the entire display screen and sets all pixels to the background color.
 *
 * @param None
 * @retval None
 */
void TFT_ClearScreen(void);

/**
 * @brief Draws a pixel at the specified coordinates with the given color.
 *
 * This function draws a single pixel at the specified (x, y) coordinates with the specified color.
 *
 * @param[in] x The X-coordinate of the pixel.
 * @param[in] y The Y-coordinate of the pixel.
 * @param[in] color The color of the pixel in 16-bit RGB565 format.
 * @retval None
 */
void TFT_DrawPixel(u16 x, u16 y, u16 color);

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
void TFT_DrawLine(u16 x1, u16 y1, u16 x2, u16 y2, u16 color);

/**
 * @brief Displays an image on the TFT screen.
 *
 * This function displays an image stored in memory at the specified (x, y) coordinates.
 *
 * @param[in] x The X-coordinate where the image will be displayed.
 * @param[in] y The Y-coordinate where the image will be displayed.
 * @param[in] image Pointer to the image data in RGB565 format.
 * @param[in] width The width of the image in pixels.
 * @param[in] height The height of the image in pixels.
 * @retval None
 */
void TFT_DisplayImage(u16 x, u16 y, const u16* image, u16 width, u16 height);

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

/** @} TFT_Displays_Module */

#endif /**< __TFT_ILI9481_DISPLAYS_INTERFACE_H__ */
