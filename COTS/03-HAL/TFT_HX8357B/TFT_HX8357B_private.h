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

#ifndef __TFT_HX8357B_DISPLAYS_PRIVATE_H__
#define __TFT_HX8357B_DISPLAYS_PRIVATE_H__

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
#define TFT_NOP             0x00   /**< No operation command. */
#define TFT_SOFT_RESET      0x01   /**< Software reset command. */
#define TFT_RD_RED          0x06   /**< Read red channel command. */
#define TFT_RD_GREEN        0x07   /**< Read green channel command. */
#define TFT_RD_BLUE         0x08   /**< Read blue channel command. */
#define TFT_RD_DPM          0x0A   /**< Read display power mode command. */
#define TFT_RD_DMADCTL      0x0B   /**< Read display MADCTL command. */
#define TFT_RD_DCOLMOD      0x0C   /**< Read display pixel format command. */
#define TFT_RD_DIM          0x0D   /**< Read display image mode command. */
#define TFT_RD_DSM          0x0E   /**< Read display signal mode command. */
#define TFT_RD_DSDR         0x0F   /**< Read display self-diagnostic result command. */
#define TFT_SLPIN           0x10   /**< Sleep in and charge-pump off command. */
#define TFT_SLPOUT          0x11   /**< Sleep out and charge-pump on command. */
#define TFT_PTLON           0x12   /**< Partial Mode On command. */
#define TFT_NORON           0x13   /**< Normal Display Mode On command. */
#define TFT_INVOFF          0x20   /**< Display inversion off command. */
#define TFT_INVON           0x21   /**< Display inversion on command. */
#define TFT_DISPOFF         0x28   /**< Display off command. */
#define TFT_DISPON          0x29   /**< Display on command. */
#define TFT_CASET           0x2A   /**< Column address set command. */
#define TFT_PASET           0x2B   /**< Page address set command. */
#define TFT_RAMWR           0x2C   /**< Memory write command. */
#define TFT_RAMRD           0x2E   /**< Memory read command. */
#define TFT_PTLAR           0x30   /**< Partial area command. */
#define TFT_VSCRDEF         0x33   /**< Vertical scrolling definition command. */
#define TFT_TEOFF           0x34   /**< Tearing effect line off command. */
#define TFT_TEON            0x35   /**< Tearing effect line on command. */
#define TFT_MADCTL          0x36   /**< Memory Access Control command. */
#define TFT_VSCSAD          0x37   /**< Vertical scrolling start address command. */
#define TFT_IDMOFF          0x38   /**< Idle mode off command. */
#define TFT_IDMON           0x39   /**< Idle mode on command. */
#define TFT_COLMOD          0x3A   /**< Interface Pixel Format command. */
#define TFT_RAMWRCON        0x3C   /**< Memory write continue command. */
#define TFT_RAMRDCON        0x3E   /**< Memory read continue command. */
#define TFT_WRCABCMB        0x55   /**< Write CABC minimum brightness command. */
#define TFT_RDCABCMB        0x56   /**< Read CABC minimum brightness command. */
#define TFT_RDABCSDR        0x68   /**< Read automatic brightness control self-diagnostic result command. */
#define TFT_SETEXTC         0xB0   /**< Set extended command. */
#define TFT_SETDPSTB        0xB1   /**< Set deep standby mode command. */
#define TFT_SETGRAM         0xB2   /**< Set GRAM command. */
#define TFT_SETDISPMODE     0xB4   /**< Set display mode and GRAM write command. */
#define TFT_RDID1           0xDA   /**< Read ID1 command. */
#define TFT_RDID2           0xDB   /**< Read ID2 command. */
#define TFT_RDID3           0xDC   /**< Read ID3 command. */
#define TFT_RDID4           0xDD   /**< Read ID4 command. */
#define TFT_GMCTRP1         0xE0   /**< Gamma correction characteristics setting command. */
#define TFT_GMCTRN1         0xE1   /**< Gamma correction characteristics setting command. */
#define TFT_SETEQ           0xE2   /**< Set EQ function command. */
#define TFT_SETPANEL        0xE9   /**< Set panel register command. */
#define TFT_SETEQ           0xEE   /**< Set EQ function command. */

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

#endif /**< __TFT_HX8357B_DISPLAYS_PRIVATE_H__ */
