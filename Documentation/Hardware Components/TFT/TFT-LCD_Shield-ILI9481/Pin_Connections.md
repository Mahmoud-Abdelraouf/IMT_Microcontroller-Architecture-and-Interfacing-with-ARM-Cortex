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

# TFT LCD Module Interface Using SPI with STM32F103C8

This guide outlines the steps to interface a TFT LCD module with the STM32F103C8 microcontroller using SPI (Serial Peripheral Interface). The TFT LCD module requires GPIO configuration, SPI peripheral initialization, and control pin management for effective communication.

## Steps to Interface TFT LCD Module with SPI

### Step 1: GPIO Configuration

Configure the microcontroller's GPIO pins to establish communication and control signals with the LCD module. You need to set up pins for the following functions:
- Chip Select (CSX)
- Serial Clock (SCL)
- Serial Data In/Out (SDA/DOUT)
- Data/Command control (D/CX)

### Step 2: SPI Peripheral Initialization

Initialize the SPI peripheral of the microcontroller with appropriate communication parameters, including data frame format, clock polarity, and clock phase. The SPI peripheral is responsible for data exchange with the LCD module.

### Step 3: Configure Control Pins

Configure the control pins (CSX and D/CX) as GPIO outputs. These pins are used to control the behavior of the LCD module, such as indicating whether you are sending a command or data.

### Step 4: Write Sequence Implementation

In this step, you'll implement the process of sending commands or data to the LCD module. This involves the following sub-steps:

a. Start Sequence: Lower the CSX pin to signal the start of a write sequence.
b. Command/Data Mode: Set the D/CX pin to the appropriate level based on whether you are sending a command or data.
c. Send Data: Utilize the SPI peripheral to send bytes of data to the LCD module. Each byte may consist of multiple write cycles, and the clock signal (SCL) synchronizes the transmission.
d. End Sequence: Raise the CSX pin to signal the end of the write sequence.

### step 5: Initialization of the ILI9481 TFT Microcontroller

```c
void TFT_voidInit(const TFT_Config_t *Copy_psTftDisplay, SPI_t *Copy_psTheSpiTftUsed)
{
    /**< Set the Reset (RST) pin to high logic level to release reset signal */
    MGPIO_voidSetPinValue(Copy_psTftDisplay->TFT_Port, Copy_psTftDisplay->TFT_RstPin, GPIO_HIGH);
    
    /**< Wait for a specified delay before proceeding */
    MSTK_voidSetDelay(5);
    
    /**< Set the Reset (RST) pin to low logic level to assert reset signal */
    MGPIO_voidSetPinValue(Copy_psTftDisplay->TFT_Port, Copy_psTftDisplay->TFT_RstPin, GPIO_LOW);
    
    /**< Wait for a short delay */
    MSTK_voidSetDelay(15);
    
    /**< Set the Reset (RST) pin to high logic level to release reset signal */
    MGPIO_voidSetPinValue(Copy_psTftDisplay->TFT_Port, Copy_psTftDisplay->TFT_RstPin, GPIO_HIGH);
    
    /**< Wait for a specified delay before proceeding */
    MSTK_voidSetDelay(15);
    
    TFT_InitController(Copy_psTftDisplay, Copy_psTheSpiTftUsed);
}

static void TFT_InitController(const TFT_Config_t *Copy_psTftDisplay, SPI_t *Copy_psTheSpiTftUsed)
{
    /**< Configure ILI9481 display */ 

    /**< Send command to exit sleep mode */
    TFT_SendCommand(Copy_psTftDisplay, Copy_psTheSpiTftUsed, 0x11);
    MSTK_voidSetDelay(20);

    /**< Send command to configure power setting */
    TFT_SendCommand(Copy_psTftDisplay, Copy_psTheSpiTftUsed, 0xD0);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheSpiTftUsed, 0x07);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheSpiTftUsed, 0x42);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheSpiTftUsed, 0x18);

    /**< Send command to configure address mode */
    TFT_SendCommand(Copy_psTftDisplay, Copy_psTheSpiTftUsed, 0xD1);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheSpiTftUsed, 0x00);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheSpiTftUsed, 0x07);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheSpiTftUsed, 0x10);

    /**< Send command to configure display mode */
    TFT_SendCommand(Copy_psTftDisplay, Copy_psTheSpiTftUsed, 0xD2);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheSpiTftUsed, 0x01);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheSpiTftUsed, 0x02);

    /**< Send command to configure gamma setting */
    TFT_SendCommand(Copy_psTftDisplay, Copy_psTheSpiTftUsed, 0xC0);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheSpiTftUsed, 0x10);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheSpiTftUsed, 0x3B);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheSpiTftUsed, 0x00);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheSpiTftUsed, 0x02);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheSpiTftUsed, 0x11);

    /**< Send command to configure frame rate and inversion control */
    TFT_SendCommand(Copy_psTftDisplay, Copy_psTheSpiTftUsed, 0xC5);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheSpiTftUsed, 0x03);

    /**< Send command to configure gamma settings */
    TFT_SendCommand(Copy_psTftDisplay, Copy_psTheSpiTftUsed, 0xC8);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheSpiTftUsed, 0x00);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheSpiTftUsed, 0x32);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheSpiTftUsed, 0x36);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheSpiTftUsed, 0x45);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheSpiTftUsed, 0x06);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheSpiTftUsed, 0x16);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheSpiTftUsed, 0x37);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheSpiTftUsed, 0x75);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheSpiTftUsed, 0x77);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheSpiTftUsed, 0x54);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheSpiTftUsed, 0x0C);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheSpiTftUsed, 0x00);

    /**< Send command to set scroll area */
    TFT_SendCommand(Copy_psTftDisplay, Copy_psTheSpiTftUsed, 0x36);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheSpiTftUsed, 0x0A);

    /**< Send command to set pixel format */
    TFT_SendCommand(Copy_psTftDisplay, Copy_psTheSpiTftUsed, 0x3A);
    #if (TFT_DISPLAY_COLORS == _3BIT_PER_PIXEL) || (TFT_DISPLAY_COLORS == _16BIT_PER_PIXEL) || (TFT_DISPLAY_COLORS == _18BIT_PER_PIXEL)
        TFT_SendData(Copy_psTftDisplay, Copy_psTheSpiTftUsed, TFT_DISPLAY_COLORS);
    #else
        TFT_SendCommand(Copy_psTftDisplay, 0x21);
    #endif

    /**< Send command to set column address */
    TFT_SendCommand(Copy_psTftDisplay, Copy_psTheSpiTftUsed, 0x2A);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheSpiTftUsed, 0x00);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheSpiTftUsed, 0x00);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheSpiTftUsed, 0x01);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheSpiTftUsed, 0x3F);

    /**< Send command to set page address */
    TFT_SendCommand(Copy_psTftDisplay, Copy_psTheSpiTftUsed, 0x2B);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheSpiTftUsed, 0x00);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheSpiTftUsed, 0x00);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheSpiTftUsed, 0x01);
    TFT_SendData(Copy_psTftDisplay, Copy_psTheSpiTftUsed, 0xE0);

    MSTK_voidSetDelay(120);
    /**< Send command to exit idle mode */
    TFT_SendCommand(Copy_psTftDisplay, Copy_psTheSpiTftUsed, 0x29);

    /**< End of ILI9481 display configuration */
}
```

### Step 6: Data and Command Handling

Manage the D/CX pin based on your LCD module's specifications to indicate whether you are sending a command or data. This step ensures that the LCD module correctly interprets the type of information being transmitted.

### Step 7: Example Code

Below is an example of how you can structure your C code for interfacing with the TFT LCD module:

```c
// Configure GPIO pins
Configure_CSX_Pin();
Configure_SCL_Pin();
Configure_SDA_Pin();
Configure_D_CX_Pin();

// Initialize SPI peripheral
SPI_Init();

// Write Sequence Implementation
void LCD_SendCommand(uint8_t command) {
    // Lower CSX to start write sequence
    CSX_LOW();

    // Set D/CX to indicate command mode
    D_CX_LOW();

    // Send command byte using SPI
    SPI_SendData(command);

    // Raise CSX to end write sequence
    CSX_HIGH();
}

// Define LCD_SendData() function similarly

int main() {
    // Initialize GPIO, SPI, and control pins

    // Send commands and data to the LCD module
    LCD_SendCommand(0x01); // Example command
    LCD_SendData(0xFF);    // Example data

    // Main application loop
    while (1) {
        // Your code logic
    }
}
```

# SPI Initialization Sequence for LCD Communication

## Introduction

This document outlines the sequence for initializing the Serial Peripheral Interface (SPI) communication to interface with an LCD module using the Type C interface. The provided information focuses on the write cycle and sequence during data transmission.

## SPI Initialization Steps

1. **Configure GPIO Pins**:

   - Configure CSX (Chip Select), SCL (Serial Clock), SDA (Serial Data) or DOUT (Data Out), and potentially D/CX (Data/Command) pins as GPIO outputs.

2. **Initialize SPI Peripheral**:

   - Initialize the SPI peripheral with appropriate settings:
     - Data Frame Format: (Insert desired data frame format, e.g., 8 bits)
     - Clock Polarity: Idle High (CPOL = 1)
     - Clock Phase: First clock transition is the first data write edge (CPHA = 1)
     - Clock Speed: Choose an appropriate clock speed.
     - MSB/LSB First: (Insert preferred data order, e.g., MSB first)
     - Enable SPI.

3. **Write Cycle and Sequence**:

   During the write sequence, the host processor writes one or more bytes of information to the display module via the interface. The sequence is as follows:

   - Initiate Write Sequence:
     - Lower CSX (Chip Select) from high to low to start the write sequence.
     - If applicable, drive D/CX (Data/Command) low to indicate command information.

   - Send Data Bits:
     - Iterate through each bit of the data byte to be sent.
     - For each bit:
       - Assert DOUT or SDA line when there is a falling edge of SCL (Serial Clock).
       - Display reads DOUT or SDA line when there is a rising edge of SCL.
       - After the SCL is high, the host negates DOUT or SDA line.

   - End Write Sequence:
     - Raise CSX from low to high to end the write sequence.
     - If applicable, pull D/CX high to indicate data presence.

## Example Pseudo Code

Below is an example pseudo code snippet demonstrating the SPI initialization and write sequence:

```c
// Configure GPIO pins for CSX, SCL, SDA/DOUT, and potentially D/CX
Configure_CSX_Pin();
Configure_SCL_Pin();
Configure_SDA_Pin();
Configure_D_CX_Pin(); // If applicable

// Initialize SPI peripheral with desired settings
SPI_Init();

// Initiate Write Sequence
CSX_LOW();
D_CX_LOW(); // If command information

// Send Data Bits
for (bit in data_byte) {
    SDA_HIGH(); // Assert DOUT or SDA line
    SCL_HIGH();
    SCL_LOW();  // Display reads DOUT or SDA line
    SDA_LOW();  // Negate DOUT or SDA line
    SCL_HIGH();
}

// End Write Sequence
CSX_HIGH();
D_CX_HIGH(); // If data information
```

## TFT LCD Module SPI Interface Pin Connections

- **SPI_MISO (Display Data In - from Display to Microcontroller):**
  Connect this pin from the TFT LCD module to the MISO (Master In Slave Out) pin of the STM32F103C8. This connection allows data to flow from the display to the microcontroller, such as touch input data or display status information.

- **SPI_MOSI (Display Data Out - from Microcontroller to Display):**
  Connect this pin from the TFT LCD module to the MOSI (Master Out Slave In) pin of the STM32F103C8. This connection allows data to flow from the microcontroller to the display, such as display commands and pixel data.

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
- 
Please remember to connect the necessary power supply pins (5V) and potentially the backlight control pin (LED), depending on the specific requirements of your TFT LCD module. This will ensure proper functionality and illumination.

Additionally, make sure to correctly configure and initialize the

 SPI interface and GPIO pins in our STM32F103C8 code. This step is crucial for establishing effective communication between the display and the microcontroller. Refer to the documentation provided for both the display module and the STM32F103C8 microcontroller to ensure accurate pin assignments, communication protocols, and initialization procedures.

By carefully following these steps, we can successfully interface the TFT LCD module using SPI with our STM32F103C8 microcontroller.
