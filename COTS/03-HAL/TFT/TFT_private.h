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
 * @defgroup TFT_ColorFormats TFT Display Color Formats
 * @brief Definitions for various color formats supported by the TFT display.
 *
 * These definitions specify the color formats that the TFT display supports.
 * Choose the appropriate format based on the display's capabilities.
 *
 * @{
 */

/**
 * @brief 3-bit per pixel RGB color format (RGB111).
 *
 * This format represents each pixel using 3 bits for red, green, and blue components,
 * allowing a total of 8 different colors.
 */
#define _3BIT_PER_PIXEL           0x11      /**< RGB111 */

/**
 * @brief 16-bit per pixel RGB color format (RGB565).
 *
 * This format represents each pixel using 16 bits, with 5 bits for red, 6 bits for green,
 * and 5 bits for blue components, providing a total of 65,536 different colors.
 */
#define _16BIT_PER_PIXEL          0x55      /**< RGB565 */

/**
 * @brief 18-bit per pixel RGB color format (RGB666).
 *
 * This format represents each pixel using 18 bits, with 6 bits for red, green, and blue components,
 * allowing a total of 262,144 different colors.
 */
#define _18BIT_PER_PIXEL          0x66      /**< RGB666 */

/** @} TFT_ColorFormats */

/**
 * @addtogroup TFT_Command_Private
 * @{
 */

/**
 * @brief Enumeration of TFT command codes.
 *
 * This enumeration defines the command codes used for communication with the TFT display.
 * Each command corresponds to a specific operation or configuration setting.
 */
typedef enum {
    TFT_NOP = 0x00,                   /**< No operation command. */
    TFT_SOFT_RESET = 0x01,            /**< Software reset command. */
    TFT_GET_RED_CHANNEL = 0x06,       /**< Get red channel command. */
    TFT_GET_GREEN_CHANNEL = 0x07,     /**< Get green channel command. */
    TFT_GET_BLUE_CHANNEL = 0x08,      /**< Get blue channel command. */
    TFT_GET_POWER_MODE = 0x0A,        /**< Get power mode command. */
    TFT_GET_ADDRESS_MODE = 0x0B,      /**< Get address mode command. */
    TFT_GET_PIXEL_FORMAT = 0x0C,      /**< Get pixel format command. */
    TFT_GET_DISPLAY_MODE = 0x0D,      /**< Get display mode command. */
    TFT_GET_SIGNAL_MODE = 0x0E,       /**< Get signal mode command. */
    TFT_GET_DIAGNOSTIC_RESULT = 0x0F, /**< Get diagnostic result command. */
    TFT_ENTER_SLEEP_MODE = 0x10,      /**< Enter sleep mode command. */
    TFT_EXIT_SLEEP_MODE = 0x11,       /**< Exit sleep mode command. */
    TFT_ENTER_PARTIAL_MODE = 0x12,    /**< Enter partial mode command. */
    TFT_ENTER_NORMAL_MODE = 0x13,     /**< Enter normal mode command. */
    TFT_EXIT_INVERT_MODE = 0x20,      /**< Exit invert mode command. */
    TFT_ENTER_INVERT_MODE = 0x21,     /**< Enter invert mode command. */
    TFT_SET_GAMMA_CURVE = 0x26,       /**< Set gamma curve command. */
    TFT_SET_DISPLAY_OFF = 0x28,       /**< Set display off command. */
    TFT_SET_DISPLAY_ON = 0x29,        /**< Set display on command. */
    TFT_SET_COLUMN_ADDRESS = 0x2A,    /**< Set column address command. */
    TFT_SET_PAGE_ADDRESS = 0x2B,      /**< Set page address command. */
    TFT_WRITE_MEMORY_START = 0x2C,    /**< Write memory start command. */
    TFT_WRITE_LUT = 0x2D,             /**< Write look-up table command. */
    TFT_READ_MEMORY_START = 0x2E,     /**< Read memory start command. */
    TFT_SET_PARTIAL_AREA = 0x30,      /**< Set partial area command. */
    TFT_SET_SCROLL_AREA = 0x33,       /**< Set scroll area command. */
    TFT_SET_TEAR_OFF = 0x34,          /**< Set tear off command. */
    TFT_SET_TEAR_ON = 0x35,           /**< Set tear on command. */
    TFT_SET_ADDRESS_MODE = 0x36,      /**< Set address mode command. */
    TFT_SET_SCROLL_START = 0x37,      /**< Set scroll start command. */
    TFT_EXIT_IDLE_MODE = 0x38,        /**< Exit idle mode command. */
    TFT_ENTER_IDLE_MODE = 0x39,       /**< Enter idle mode command. */
    TFT_SET_PIXEL_FORMAT = 0x3A,      /**< Set pixel format command. */
    TFT_WRITE_MEMORY_CONTINUE = 0x3C, /**< Write memory continue command. */
    TFT_READ_MEMORY_CONTINUE = 0x3E,  /**< Read memory continue command. */
    TFT_SET_TEAR_SCANLINE = 0x44,     /**< Set tear scanline command. */
    TFT_GET_SCANLINE = 0x45,          /**< Get scanline command. */
    TFT_READ_DDB_START = 0xA1,       /**< Read DDB start command. */
    TFT_READ_DDB_CONTINUE = 0xA8     /**< Read DDB continue command. */
} TFT_Command_t;

/** @} TFT_Command_and_Some_Macros_Private */

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
    TFT_CommInterface_t CommInterface; /**< Communication interface used for the TFT display */
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
static void TFT_SendCommand(const TFT_Config_t *Copy_psTftDisplay, u8 Copy_Command);

/**
 * @brief Send data to the TFT display using SPI communication.
 *
 * This function sends a single data byte to the TFT display using the specified SPI peripheral.
 * It sets the RS (Register Select) pin to high to indicate data mode, selects the TFT display by
 * setting the CS (Chip Select) pin low, performs an SPI data transfer to send the data byte, and
 * then releases the display by setting the CS pin high again.
 *
 * @param[in] Copy_Spi The SPI peripheral to be used for communication.
 * @param[in] Copy_psTftDisplay Pointer to the TFT display configuration structure.
 * @param[in] Copy_Data The data byte to be sent to the TFT display.
 *
 * @return None.
 *
 * @note Make sure to properly configure the TFT display and GPIO functions before calling this function.
 *
 * @note Example Usage:
 * @code
 * /**< Create a TFT display configuration structure
 * TFT_Config_t tftConfig = {
 *     .TFT_Port = PORTA_INDEX,
 *     .TFT_CsPin = GPIO_PIN0,
 *     .TFT_RsPin = GPIO_PIN1,
 *     /**< ... other configuration settings ...
 * };
 *
 * /**< Select the SPI peripheral (e.g., SPI_1)
 * SPI_Peripheral_t spiPeripheral = SPI_1;
 *
 * /**< Send data (e.g., 0x55) to the TFT display
 * TFT_SendData(spiPeripheral, &tftConfig, 0x55);
 * @endcode
 */
static void TFT_SendData(const TFT_Config_t *Copy_psTftDisplay, u8 Copy_Data);


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
//static void TFT_DrawCharacter(u16 x, u16 y, char character, const Font_t *font, u16 textColor, u16 backgroundColor);

/* Add more internal functions and private declarations as needed */

/** @} TFT_Private_Functions */

#endif /**< __TFT_DISPLAYS_PRIVATE_H__ */
