# TFT LCD Module Interface Using SPI with STM32F103C8

## Pin Connections

| Pin        | Connection                                  | Description                                                                                   |
|------------|---------------------------------------------|-----------------------------------------------------------------------------------------------|
| SPI_MISO   | STM32F103C8 MOSI (Master Out Slave In)      | Data line from the display to the microcontroller for sending data.                           |
| SPI_MOSI   | STM32F103C8 MISO (Master In Slave Out)      | Data line from the microcontroller to the display for sending data.                           |
| SPI_CLK    | STM32F103C8 SPI Clock (SCK)                 | Clock signal for synchronizing data transmission.                                             |
| LCD_CS     | Digital Output on STM32F103C8               | Chip select signal for the display. Drive low to select the display for communication.        |
| LCD_RS     | Digital Output on STM32F103C8               | Control signal for Data/Command (DC/RS) on the display. Indicates command or display data.    |
| LCD_WR     | Digital Output on STM32F103C8               | Controls the write operation for the display.                                                 |
| LCD_RST    | Digital Output on STM32F103C8               | Reset control signal for the display.                                                         |
| GND        | Ground (GND) of STM32F103C8                 | Connect both GND pins of the display to the microcontroller's ground.                         |

## Notes

- **SPI_MISO:** Data line from display to microcontroller for sending data.
- **SPI_MOSI:** Data line from microcontroller to display for sending data.
- **SPI_CLK:** Clock signal for synchronizing data transmission.
- **LCD_CS:** Chip select signal for display communication.
- **LCD_RS:** Control signal for Data/Command (DC/RS) on display.
- **LCD_WR:** Controls write operation for display.
- **LCD_RST:** Reset control signal for display.
- **GND:** Ground connection between display and microcontroller.

Remember to also connect power supply pins (5V) and potentially the backlight control pin (LED) as needed based on your specific TFT LCD module. Ensure proper configuration and initialization of the SPI interface and GPIO pins in your STM32F103C8 code according to the documentation of both the display and the microcontroller.
