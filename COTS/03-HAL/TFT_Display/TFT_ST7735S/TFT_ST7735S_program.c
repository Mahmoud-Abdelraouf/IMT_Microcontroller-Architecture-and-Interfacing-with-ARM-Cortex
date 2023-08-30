/**
 ********************************************************************************************
 * @file TFT_Displays_program.c
 * @brief This file contains the implementation of the TFT Displays module functions.
 * 
 * This module provides functions for interfacing with TFT (Thin-Film Transistor) displays
 * to control graphical user interfaces (GUIs), display images, and render text.
 ********************************************************************************************
 * @date 20 Jul 2023
 * @version V01
 * @author Mahmoud Abdelraouf Mahmoud
 *
 * @note Before using this module, make sure to configure the display controller
 * and the required GPIO pins for communication and control.
 *
 * @see TFT_Displays_interface.h for the public interface and function descriptions.
 ******************************************************************************************** 
 */
/**<========================================================================================*/
/*******************************************< LIB *******************************************/
/**<========================================================================================*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/**<=========================================================================================*/
/*******************************************< MCAL *******************************************/
/**<=========================================================================================*/
#include "GPIO_interface.h"
#include "SPI_interface.h"
#include "STK_interface.h"

/**<========================================================================================*/
/*******************************************< HAL *******************************************/
/**<========================================================================================*/
#include "TFT_ST7735S_config.h"
#include "TFT_ST7735S_interface.h"
#include "TFT_ST7735S_private.h"

/**<=============================================================================================================*/
/*******************************************< Functions Implementation *******************************************/
/**<=============================================================================================================*/

/**
 * @addtogroup TFT_Public_Functions
 * @{
 */

void TFT_voidInit(const TFT_Config_t *Copy_psTftDisplay, SPI_t Copy_psTheUsedSpi)
{
    /**< Set the Reset (RES) pin to high logic level to release reset signal */
    MGPIO_voidSetPinValue(Copy_psTftDisplay->TFT_RESPin.TFT_Port, Copy_psTftDisplay->TFT_RESPin.TFT_Pin, GPIO_HIGH);
    
    /**< Wait for a specified delay before proceeding */
    MSTK_voidSetDelay(5);
    
    /**< Set the Reset (RST) pin to low logic level to assert reset signal */
    MGPIO_voidSetPinValue(Copy_psTftDisplay->TFT_RESPin.TFT_Port, Copy_psTftDisplay->TFT_RESPin.TFT_Pin, GPIO_LOW);
    
    /**< Wait for a short delay */
    MSTK_voidSetDelay(15);
    
    /**< Set the Reset (RES) pin to high logic level to release reset signal */
    MGPIO_voidSetPinValue(Copy_psTftDisplay->TFT_RESPin.TFT_Port, Copy_psTftDisplay->TFT_RESPin.TFT_Pin, GPIO_HIGH);
    
    /**< Wait for a specified delay before proceeding */
    MSTK_voidSetDelay(15);
    
    TFT_InitController(Copy_psTftDisplay, Copy_psTheUsedSpi);
}

void TFT_voidClearScreen(void)
{
    /**< Implement the TFT display screen clearing */
    
}

void TFT_voidDrawPixel(u16 x, u16 y, u16 color)
{
    /* Implement the TFT pixel drawing function */
    
}

void TFT_voidDrawLine(u16 x1, u16 y1, u16 x2, u16 y2, u16 color)
{
    /*<* Implement the TFT line drawing function */
   
}

void TFT_voidDisplayImage(u16 x, u16 y, const u16* image, u16 width, u16 height)
{
    /**< Implement the TFT image display function */
    
}

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
//void TFT_voidDisplayText(u16 x, u16 y, const char* text, const Font_t* font, u16 color)
//{
//    /**< Implement the TFT text display function */
//
//}

/**
 * @} TFT_Public_Functions
 */

/**
 * @addtogroup TFT_Private_Functions
 * @{
 */

static void TFT_SendCommand(const TFT_Config_t *Copy_psTftDisplay, const SPI_t Copy_psTheSpiTftUsed, u8 Copy_Command)
{
    /**< Temp variable to receive the data in */
    u8 Local_u8ReceivedData = 0;

    /**<  Set CS (Chip Select) pin low to select the TFT display for communication */
    MGPIO_voidSetPinValue(Copy_psTftDisplay->TFT_CSPin.TFT_Port, Copy_psTftDisplay->TFT_CSPin.TFT_Pin,MGPIO_LOW); 

    /**< Set DC (Data/Command Control) pin low to indicate command mode */ 
    MGPIO_voidSetPinValue(Copy_psTftDisplay->TFT_DCPin.TFT_Port, Copy_psTftDisplay->TFT_DCPin.TFT_Pin,MGPIO_LOW); 

    /**< Perform SPI data transfer to send the command byte */ 
    SPI_voidTransfer(Copy_psTheSpiTftUsed, &Copy_Command, &Local_u8ReceivedData, 1); 

    /**< Set CS pin high to release the TFT display */ 
    MGPIO_voidSetPinValue(Copy_psTftDisplay->TFT_CSPin.TFT_Port, Copy_psTftDisplay->TFT_CSPin.TFT_Pin,MGPIO_HIGH); 
}

static void TFT_SendData(const TFT_Config_t *Copy_psTftDisplay, const SPI_t Copy_psTheSpiTftUsed, u8 Copy_Data)
{
    /**< Temp variable to receive the data in */
    u8 Local_u8ReceivedData = 0;

    /**<  Set CS (Chip Select) pin low to select the TFT display for communication */
    MGPIO_voidSetPinValue(Copy_psTftDisplay->TFT_CSPin.TFT_Port, Copy_psTftDisplay->TFT_CSPin.TFT_Pin,MGPIO_LOW); 

    /**< Set DC (Data/Command Control) pin low to indicate command mode */ 
    MGPIO_voidSetPinValue(Copy_psTftDisplay->TFT_DCPin.TFT_Port, Copy_psTftDisplay->TFT_DCPin.TFT_Pin,MGPIO_HIGH); 

    /**< Perform SPI data transfer to send the command byte */ 
    SPI_voidTransfer(Copy_psTheSpiTftUsed, &Copy_Data, &Local_u8ReceivedData, 1); 

    /**< Set CS pin high to release the TFT display */ 
    MGPIO_voidSetPinValue(Copy_psTftDisplay->TFT_CSPin.TFT_Port, Copy_psTftDisplay->TFT_CSPin.TFT_Pin,MGPIO_HIGH); 
}

static void TFT_DrawPixel(u16 x, u16 y, u16 color)
{

}

static void TFT_InitController(const TFT_Config_t *Copy_psTftDisplay, const SPI_t Copy_psTheUsedSpi)
{
    /**< ======================================================================================================================= */
    /*******************************************< Configure ST7735S display *******************************************/ 
    /**< ======================================================================================================================= */
    /**< Send command for software reset */
    TFT_SendCommand(Copy_psTftDisplay, Copy_psTheUsedSpi, TFT_SWRESET);
    MSTK_voidSetDelay(150);

    /**< Send command to exit sleep mode */
    TFT_SendCommand(Copy_psTftDisplay, Copy_psTheUsedSpi, TFT_SLPOUT);
    MSTK_voidSetDelay(500);

    /**< Send command to configure frame rate control - normal mode */
    TFT_SendCommand(Copy_psTftDisplay, Copy_psTheUsedSpi, TFT_FRMCTR1);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheUsedSpi, 0x01);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheUsedSpi, 0x2C);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheUsedSpi, 0x2D);

    /**< Send command to configure frame rate control - idle mode */
    TFT_SendCommand(Copy_psTftDisplay, Copy_psTheUsedSpi, TFT_FRMCTR2);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheUsedSpi, 0x01);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheUsedSpi, 0x2C);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheUsedSpi, 0x2D);

    /**< Send command to configure frame rate control - partial mode */
    TFT_SendCommand(Copy_psTftDisplay, Copy_psTheUsedSpi, TFT_FRMCTR3);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheUsedSpi, 0x01);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheUsedSpi, 0x2C);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheUsedSpi, 0x2D);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheUsedSpi, 0x01);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheUsedSpi, 0x2C);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheUsedSpi, 0x2D);

    /**< Send command to configure display inversion control */
    TFT_SendCommand(Copy_psTftDisplay, Copy_psTheUsedSpi, TFT_INVCTR);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheUsedSpi, 0x07);

    /**< Send command to configure power control */
    TFT_SendCommand(Copy_psTftDisplay, Copy_psTheUsedSpi, TFT_PWCTR1);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheUsedSpi, 0xA2);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheUsedSpi, 0x02);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheUsedSpi, 0x84);

    /**< Send command to configure power control */
    TFT_SendCommand(Copy_psTftDisplay, Copy_psTheUsedSpi, TFT_PWCTR2);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheUsedSpi, 0xC5);

    /**< Send command to configure power control */
    TFT_SendCommand(Copy_psTftDisplay, Copy_psTheUsedSpi, TFT_PWCTR3);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheUsedSpi, 0x0A);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheUsedSpi, 0x00);

    /**< Send command to configure power control */
    TFT_SendCommand(Copy_psTftDisplay, Copy_psTheUsedSpi, TFT_PWCTR4);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheUsedSpi, 0x8A);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheUsedSpi, 0x2A);

    /**< Send command to configure power control */
    TFT_SendCommand(Copy_psTftDisplay, Copy_psTheUsedSpi, TFT_PWCTR5);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheUsedSpi, 0x8A);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheUsedSpi, 0xEE);

    /**< Send command to configure power control */
    TFT_SendCommand(Copy_psTftDisplay, Copy_psTheUsedSpi, TFT_VMCTR1);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheUsedSpi, 0x0E);

    /**< Send command to disable display inversion */
    TFT_SendCommand(Copy_psTftDisplay, Copy_psTheUsedSpi, TFT_INVOFF);

    /**< Send command to configure memory access control */
    TFT_SendCommand(Copy_psTftDisplay, Copy_psTheUsedSpi, TFT_MADCTL);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheUsedSpi, 0xC0);

    /**< Send command to set pixel format */
    TFT_SendCommand(Copy_psTftDisplay, Copy_psTheUsedSpi, TFT_COLMOD);
    #if (TFT_DISPLAY_COLORS == _3BIT_PER_PIXEL) || (TFT_DISPLAY_COLORS == _16BIT_PER_PIXEL) || (TFT_DISPLAY_COLORS == _18BIT_PER_PIXEL)
        TFT_SendData(Copy_psTftDisplay, Copy_psTheUsedSpi, TFT_DISPLAY_COLORS);
    #else
        TFT_SendCommand(Copy_psTftDisplay, TFT_INVON);
    #endif

    /**< Set column address */
    TFT_SendCommand(Copy_psTftDisplay, Copy_psTheUsedSpi, TFT_CASET);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheUsedSpi, 0x00);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheUsedSpi, 0x00);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheUsedSpi, 0x00);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheUsedSpi, 0x7F);

    /**< Set row address */
    TFT_SendCommand(Copy_psTftDisplay, Copy_psTheUsedSpi, TFT_RASET);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheUsedSpi, 0x00);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheUsedSpi, 0x00);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheUsedSpi, 0x00);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheUsedSpi, 0x7F);

    /**< Configure magical unicorn dust settings - Part 1 */
    TFT_SendCommand(Copy_psTftDisplay, Copy_psTheUsedSpi, TFT_GAMCTRP1);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheUsedSpi, 0x02);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheUsedSpi, 0x1C);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheUsedSpi, 0x07);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheUsedSpi, 0x12);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheUsedSpi, 0x37);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheUsedSpi, 0x32);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheUsedSpi, 0x29);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheUsedSpi, 0x2D);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheUsedSpi, 0x29);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheUsedSpi, 0x25);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheUsedSpi, 0x2B);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheUsedSpi, 0x39);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheUsedSpi, 0x00);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheUsedSpi, 0x01);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheUsedSpi, 0x03);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheUsedSpi, 0x10);

    /**< Configure sparkles and rainbows settings - Part 1 */
    TFT_SendCommand(Copy_psTftDisplay, Copy_psTheUsedSpi, TFT_GAMCTRN1);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheUsedSpi, 0x03);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheUsedSpi, 0x1D);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheUsedSpi, 0x07);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheUsedSpi, 0x06);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheUsedSpi, 0x2E);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheUsedSpi, 0x2C);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheUsedSpi, 0x29);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheUsedSpi, 0x2D);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheUsedSpi, 0x2E);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheUsedSpi, 0x2E);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheUsedSpi, 0x37);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheUsedSpi, 0x3F);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheUsedSpi, 0x00);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheUsedSpi, 0x00);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheUsedSpi, 0x02);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheUsedSpi, 0x10);

    /**< Turn off inversion */
    TFT_SendCommand(Copy_psTftDisplay, Copy_psTheUsedSpi, TFT_NORON);
    MSTK_voidSetDelay(10);

    /**< Turn on display */
    TFT_SendCommand(Copy_psTftDisplay, Copy_psTheUsedSpi, TFT_DISPON);
    MSTK_voidSetDelay(100);
    /**< ======================================================================================================================= */
    /*******************************************< End of ST7735S display configuration *******************************************/
    /**< ======================================================================================================================= */
}

/**
 * @} TFT_Private_Functions
 */

/**<=============================================================================================================*/
/*******************************************< End of Functions Implementation *******************************************/
/**<=============================================================================================================*/

/** @} */ // End of TFT_Displays_program.c module.
