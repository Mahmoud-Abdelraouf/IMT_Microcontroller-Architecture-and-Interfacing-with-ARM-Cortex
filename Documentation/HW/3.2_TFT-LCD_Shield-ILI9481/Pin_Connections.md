# TFT LCD Module Interface Using SPI with STM32F103C8

## Product Parameters

| Name                  | Parameter                          |
|-----------------------|------------------------------------|
| Display Color         | RGB 65K color                      |
| SKU                   | MAR3201                            |
| Screen Size           | 3.2 (inch)                         |
| Type                  | TFT                                |
| Driver IC             | ILI9481                            |
| Resolution            | 480x320 (Pixel)                    |
| Module Interface      | 16-bit parallel interface          |
| Active Area           | 45.12x67.68 (mm)                   |
| Module PCB Size       | 54.25x89.92 (mm)                   |
| Backlight             | 6 chip HighLight white LEDs        |
| Operating Temperature | -20℃~60℃                         |
| Storage Temperature   | -30℃~70℃                         |
| Operating Voltage     | 5V/3.3V                            |
| Power Consumption     | TBD                                |
| Product Weight        | About 42 g (Package containing)    |

## Interface Definition

![Interface Diagram](https://github.com/AndreAhmed/MicroPhysics/raw/6f3fcbc07e52ccadd7311f0a9be394e4498d1c5b/Picture/1200px-3.2-2560_MAR3201_Module_PinMap.jpg)

| Number | Module Pin | Pin Description                      | Number | Module Pin | Pin Description |
|--------|------------|--------------------------------------|--------|------------|-----------------|
| 1      | 5V         | Positive power supply                | 2      | 5V         | Positive power supply |
| 3      | DB8        | 8th bit of data bus                  | 4      | DB9        | 9th bit of data bus |
| 5      | DB10       | 10th bit of data bus                 | 6      | DB11       | 11th bit of data bus |
| 7      | DB12       | 12th bit of data bus                 | 8      | DB13       | 13th bit of data bus |
| 9      | DB14       | 14th bit of data bus                 | 10     | DB15       | 15th bit of data bus |
| 11     | DB7        | 7th bit of data bus                  | 12     | DB6        | 6th bit of data bus |
| 13     | DB5        | 5th bit of data bus                  | 14     | DB4        | 4th bit of data bus |
| 15     | DB3        | Third bit of data bus                | 16     | DB2        | 2nd bit of data bus |
| 17     | DB1        | 1st bit of data bus                  | 18     | DB0        | 0 bit of data bus |
| 19     | LCD_RS     | LCD register / data selection signal | 20     | LCD_WR     | LCD write control signal|
| 21     | LCD_CS     | LCD screen select control signal, low level enable | 22     | LCD_RST    | LCD reset control signal, low reset |
| 23     | NC         | Undefined, reserved                  | 24     | NC         | Undefined, reserved |
| 25     | NC         | Undefined, reserved                  | 26     | FLASH_CS   | SPI flash chip select control signal |
| 27     | NC         | Undefined, reserved                  | 28     | NC         | Undefined, reserved |
| 29     | NC         | Undefined, reserved                  | 30     | NC         | Undefined, reserved |
| 31     | SPI_MISO   | SPI bus input signal                 | 32     | SPI_MOSI   | SPI bus output signal |
| 33     | SPI_CLK    | SPI bus clock signal                 | 34     | SD_CS      | SD card select control signal, low level enable |
| 35     | GND        | Power ground                         | 36     | GND        | Power ground |

## TFT LCD Module SPI Interface Pin Connections

- **SPI_MISO (Display Data In - from Display to Microcontroller):**
  Connect this pin from the TFT LCD module to the MOSI (Master Out Slave In) pin of the STM32F103C8. This connection allows data to flow from the display to the microcontroller, such as touch input data or display status information.

- **SPI_MOSI (Display Data Out - from Microcontroller to Display):**
  Connect this pin from the TFT LCD module to the MISO (Master In Slave Out) pin of the STM32F103C8. This connection allows data to flow from the microcontroller to the display, such as display commands and pixel data.

- **SPI_CLK (Clock Signal):**
  Connect this pin from the TFT LCD module to the SPI clock (SCK) pin of the STM32F103C8. The SPI clock signal synchronizes the data transmission between the microcontroller and the display.

- **LCD_CS (Chip Select - Active Low):**
  Connect this pin from the TFT LCD module to a digital output pin on the STM32F103C8 that you will use as the chip select (CS) signal. This signal is used to enable communication with the display. When this pin is low, the display is selected for communication.

- **LCD_RS (Data/Command - Register Select):**
  Connect this pin from the TFT LCD module to a digital output pin on the STM32F103C8 that you will use to control the Data/Command (DC/RS) signal. This signal indicates whether the data being sent is a command (configuration data) or display data.

- **LCD_WR (Write Control - Active Low):**
  Connect this pin from the TFT LCD module to a digital output pin on the STM32F103C8. This pin controls the write operation for the display. When this pin is low, the microcontroller is writing data to the display.

- **LCD_RST (Reset - Active Low):**
  Connect this pin from the TFT LCD module to a digital output pin on the STM32F103C8. This pin is used to reset the display.

- **GND (Ground):**
  Connect both GND pins from the TFT LCD module to the ground (GND) of the STM32F103C8 to provide a common ground reference.

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

Please remember to connect the necessary power supply pins (5V) and potentially the backlight control pin (LED), depending on the specific requirements of your TFT LCD module. This will ensure proper functionality and illumination.

Additionally, make sure to correctly configure and initialize the

 SPI interface and GPIO pins in our STM32F103C8 code. This step is crucial for establishing effective communication between the display and the microcontroller. Refer to the documentation provided for both the display module and the STM32F103C8 microcontroller to ensure accurate pin assignments, communication protocols, and initialization procedures.

By carefully following these steps, we can successfully interface the TFT LCD module using SPI with our STM32F103C8 microcontroller.
