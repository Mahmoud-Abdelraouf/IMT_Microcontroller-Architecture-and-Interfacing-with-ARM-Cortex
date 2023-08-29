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

#ifndef __TFT_ILI9481_DISPLAYS_PRIVATE_H__
#define __TFT_ILI9481_DISPLAYS_PRIVATE_H__

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
 * @brief TFT Command Definitions.
 *
 * This set of "#define" statements defines command values for various operations on the TFT display.
 * Each command is represented by a corresponding "#define" constant with its associated hexadecimal value.
 * These constants can be used to send specific commands to the TFT display.
 */
#define TFT_NOP                         0x00         /**< No operation command. */
#define TFT_SOFT_RESET                  0x01         /**< Software reset command. */
#define TFT_GET_RED_CHANNEL             0x06         /**< Get red channel command. */
#define TFT_GET_GREEN_CHANNEL           0x07         /**< Get green channel command. */
#define TFT_GET_BLUE_CHANNEL            0x08         /**< Get blue channel command. */
#define TFT_GET_POWER_MODE              0x0A         /**< Get power mode command. */
#define TFT_GET_ADDRESS_MODE            0x0B         /**< Get address mode command. */
#define TFT_GET_PIXEL_FORMAT            0x0C         /**< Get pixel format command. */
#define TFT_GET_DISPLAY_MODE            0x0D         /**< Get display mode command. */
#define TFT_GET_SIGNAL_MODE             0x0E         /**< Get signal mode command. */
#define TFT_GET_DIAGNOSTIC_RESULT       0x0F         /**< Get diagnostic result command. */
#define TFT_ENTER_SLEEP_MODE            0x10         /**< Enter sleep mode command. */
#define TFT_EXIT_SLEEP_MODE             0x11         /**< Exit sleep mode command. */
#define TFT_ENTER_PARTIAL_MODE          0x12         /**< Enter partial mode command. */
#define TFT_ENTER_NORMAL_MODE           0x13         /**< Enter normal mode command. */
#define TFT_EXIT_INVERT_MODE            0x20         /**< Exit invert mode command. */
#define TFT_ENTER_INVERT_MODE           0x21         /**< Enter invert mode command. */
#define TFT_SET_GAMMA_CURVE             0x26         /**< Set gamma curve command. */
#define TFT_SET_DISPLAY_OFF             0x28         /**< Set display off command. */
#define TFT_SET_DISPLAY_ON              0x29         /**< Set display on command. */
#define TFT_SET_COLUMN_ADDRESS          0x2A         /**< Set column address command. */
#define TFT_SET_PAGE_ADDRESS            0x2B         /**< Set page address command. */
#define TFT_WRITE_MEMORY_START          0x2C         /**< Write memory start command. */
#define TFT_WRITE_LUT                   0x2D         /**< Write look-up table command. */
#define TFT_READ_MEMORY_START           0x2E         /**< Read memory start command. */
#define TFT_SET_PARTIAL_AREA            0x30         /**< Set partial area command. */
#define TFT_SET_SCROLL_AREA             0x33         /**< Set scroll area command. */
#define TFT_SET_TEAR_OFF                0x34         /**< Set tear off command. */
#define TFT_SET_TEAR_ON                 0x35         /**< Set tear on command. */
#define TFT_SET_ADDRESS_MODE            0x36         /**< Set address mode command. */
#define TFT_SET_SCROLL_START            0x37         /**< Set scroll start command. */
#define TFT_EXIT_IDLE_MODE              0x38         /**< Exit idle mode command. */
#define TFT_ENTER_IDLE_MODE             0x39         /**< Enter idle mode command. */
#define TFT_SET_PIXEL_FORMAT            0x3A         /**< Set pixel format command. */
#define TFT_WRITE_MEMORY_CONTINUE       0x3C         /**< Write memory continue command. */
#define TFT_READ_MEMORY_CONTINUE        0x3E         /**< Read memory continue command. */
#define TFT_SET_TEAR_SCANLINE           0x44         /**< Set tear scanline command. */
#define TFT_GET_SCANLINE                0x45         /**< Get scanline command. */
#define TFT_READ_DDB_START              0xA1         /**< Read DDB start command. */
#define TFT_READ_DDB_CONTINUE           0xA8         /**< Read DDB continue command. */
#define TFT_COMMAND_ACCESS_PROTECT      0xB0         /**< Command Access Protect command. */
#define TFT_LOW_POWER_MODE_CONTROL      0xB1         /**< Low Power Mode Control command. */
#define TFT_FRAME_MEMORY_ACCESS         0xB3         /**< Frame Memory Access and Interface setting command. */
#define TFT_DISPLAY_MODE_SETTING        0xB4         /**< Display Mode and Frame Memory Write Mode setting command. */
#define TFT_DEVICE_CODE_READ            0xBF         /**< Device code read command. */
#define TFT_PANEL_DRIVING_SETTING       0xC0         /**< Panel Driving Setting command. */
#define TFT_DISPLAY_TIMING_NORMAL       0xC1         /**< Display Timing Setting for Normal Mode command. */
#define TFT_DISPLAY_TIMING_PARTIAL      0xC2         /**< Display Timing Setting for Partial Mode command. */
#define TFT_DISPLAY_TIMING_IDLE         0xC3         /**< Display Timing Setting for Idle Mode command. */
#define TFT_FRAME_RATE_INVERSION        0xC5         /**< Frame rate and Inversion Control command. */
#define TFT_INTERFACE_CONTROL           0xC6         /**< Interface Control command. */
#define TFT_GAMMA_SETTING               0xC8         /**< Gamma Setting command. */
#define TFT_POWER_SETTING               0xD0         /**< Power Setting command. */
#define TFT_VCOM_CONTROL                0xD1         /**< VCOM Control command. */
#define TFT_POWER_SETTING_NORMAL        0xD2         /**< Power Setting for Normal Mode command. */
#define TFT_POWER_SETTING_PARTIAL       0xD3         /**< Power Setting for Partial Mode command. */
#define TFT_POWER_SETTING_IDLE          0xD4         /**< Power Setting for Idle Mode command. */
#define TFT_NV_MEMORY_WRITE             0xE0         /**< NV Memory Write command. */
#define TFT_NV_MEMORY_CONTROL           0xE1         /**< NV Memory Control command. */
#define TFT_NV_MEMORY_STATUS            0xE2         /**< NV Memory Status command. */
#define TFT_NV_MEMORY_PROTECTION        0xE3         /**< NV Memory Protection command. */

/** @} TFT_Command_and_Some_Macros_Private */

/**
 * @addtogroup TFT_Private_Functions TFT Private Functions
 * @brief Internal/private functions for the TFT Displays module.
 * @{
 */

/**
 * @brief Internal function to send commands to the TFT display controller.
 *
 * This function is used internally to send commands to the TFT display controller
 * using the specified communication interface.
 *
 * @param command The command byte to be sent.
 */
static void TFT_SendCommand(const TFT_Config_t *Copy_psTftDisplay, const SPI_t *Copy_psTheSpiTftUsed, u8 Copy_Command);

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
static void TFT_SendData(const TFT_Config_t *Copy_psTftDisplay, const SPI_t *Copy_psTheSpiTftUsed, u8 Copy_Data);

/**
 * @brief Internal function to initialize the TFT display controller.
 *
 * This function is used internally to initialize the TFT display controller
 * based on the configuration settings provided in the TFT_DisplayController_t structure.
 */
static void TFT_InitController(const TFT_Config_t *Copy_psTftDisplay, SPI_t *Copy_psTheSpiTftUsed);

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

#endif /**< __TFT_ILI9481_DISPLAYS_PRIVATE_H__ */
