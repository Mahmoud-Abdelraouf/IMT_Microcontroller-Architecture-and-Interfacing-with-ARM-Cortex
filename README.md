# ARM Embedded Systems and IoT Course

Welcome to the ARM Embedded Systems and IoT Course! This repository contains the materials and code for a comprehensive course on embedded systems that covers ARM architecture basics, interrupts, real-time processing, audio processing, communications, IoT, and bootloader implementation.

## Course Outline

The course is divided into 7 chapters, with a total of 22 lectures. Here is an overview of the course outline:

Sure, here's the course outline presented in a table format:

| Chapter | Lecture | Title          | Outlines |
| ------- | ------- | -------        | -------- |
| 1 | 1  | ARM Architecture          |- ARM History|
|   |    |                           | - Power Factors in ARM|
|   |    |                           | - ARM Processor Design|
|   |    |                           | - ARM Core Peripheral|
|   |    |                           | - AMBA Bus definition|
|   |    |                           | - Bus Matrix|
|   |    |                           | - Harvard To Von Neumann Conversion|
|   |    |                           | - Register Definition and Driver Setup|
|   | 2  | RCC Peripheral            | - IMT SDK for ARM Setup|
|   |    |                           | - Code Naming Convention|
|   |    |                           | - Microcontroller Clock Types|
|   |    |                           | - PLL and FLL|
|   |    |                           | - Different Reset Types|
|   |    |                           | - Reset and Clock Control Peripheral Driver|
|   | 3  | DIO Peripheral            | - Digital Input/Output peripheral Basics|
|   |    |                           | - Different Input and Output modes|
|   |    |                           | - Building DIO Driver for ST Microcontroller|
|   |    |                           | - Interfacing LEDs|
|   |    |                           | - Interfacing 7-Segment Displays|
|   |    |                           | - Interfacing Tactile Switches|
| 2 | 4  | NVIC                      | - Interrupts Basics|
|   |    |                           | - Interrupt Handling Techniques|
|   |    |                           | - The Nested Vectored Interrupt Controller|
|   |    |                           | - Interrupt Priority Grouping|
|   | 5  | NVIC Driver               | - NVIC Registers definition|
|   |    |                           | - Building NVIC Driver|
|   |    |                           | - Simulating Interrupts Feature|
|   | 6  | EXTI                      | - External Interrupt Basics|
|   |    |                           | - AFIO Peripheral|
|   |    |                           | - Building EXTI driver|
| 3 | 7  | SysTick                   | - Timer Basics|
|   |    |                           |- SysTick Core Peripheral|
|   |    |                           | - Interval Vs Busy Wait delay|
|   |    |                           | - Synchronous Vs Asynchronous Design|
|   |    |                           | - Callback Function|
|   |    |                           | - Building Systick Driver|
|   | 8  | OS Scheduler              | - Operating Systems Basics|
|   |    |                           | - Building Real Time Scheduler|
|   |    |                           | - Time Triggered Design Patter and Real Dynamic Design Aspects|
|   | 9  | LED Matrix                | - POV Concept|
|   |    |                           | - 7-Segment Displays in POV Pattern|
|   |    |                           |- Interfacing LED Matrix Display|
| 4 | 10 | DAC                       | - Digital To Analog Converter Basics|
|   |    |                           | - R2R DAC|
|   |    |                           | - Building DAC Driver|
|   | 11 | Audible Signals           | - Human Voice Characteristics|
|   |    |                           | - Sampling and Quantization|
|   |    |                           | - Dealing with audio files|
|   |    |                           | - Mono Vs Stereo| 
|   |    |                           | - Using PICAXE and AUX Speaker|
|   |    |                           | - Playing Sounds over DAC|
| 5 | 12 | Serial To Parallel        | - Serial Vs Parallel Communication|
|   |    |                           | - Extending DIO Pins to unlimited number|
|   |    |                           | - Interfacing LED Matrix Serially|
|   | 13 | IR Communication          | - Communication Over light basics|
|   |    |                           |- NEC IR Protocol|
|   |    |                           |- Building IR Receiver Driver|
|   | 14 | UART                      | - Serial Communication Characteristics
|   |    |                           | - UART Basics
|   |    |                           | - Building UART Driver
|   |    |                           | - Interfacing USB TTL Module
|   | 15 | SPI and TFT               | - SPI Basics
|   |    |                           |- Building SPI Driver
|   |    |                           |- Pixel Color Modes
|   |    |                           |- Display Types and Comparison
|   |    |                           |- Interfacing TFT Displays
|   |    |                           |- Bit Map Images
|   |    |                           |- Playing Video Samples
| 5 | 16 | DMA                       | - Direct Memory Access Definitions and Basics
|   |    |                           | - DMA Authorities against processor
|   |    |                           | - DMA Driver Build
| 6 | 17 | WiFi Module               | - WiFi Basics
|   |    |                           | - WiFi Module Interfacing
|   |    |                           | - Networking
|   |    |                           | - Client and Server Model
|   | 18 | Web Development           | - HTML Basics
|   |    |                           | - PHP Basics
|   |    |                           | - HTTP Requests
|   |    |                           | - Building Simple Web Page
|   | 19 | IoT                       | - Building Free Server with a simple web page
|   |    |                           |- Connecting Microcontroller to web server
|   |    |                           |- Microcontroller Communication over HTTP
| 7 | 20 | Story of Flashing         | - C Build Process
|   |    |                           | - Memory Sections
|   |    |                           | - Startup Code 
|   |    |                           | - Flashing Sequence and Burner types
|   |    |                           | - HEX File Format
|   | 21 | Hex Parser                | - Building HEX Parser Driver
|   |    |                           | - File Transfer over UART
|   | 22 | Bootloader Implementation | - Flash Driver Software
|   |    |                           |- Bootloader sequence

Each lecture is organized in a separate folder, containing the lecture slides, code examples, and exercises.

## Getting Started

To get started with the course, simply clone this repository to your local machine and navigate to the desired lecture folder. Each lecture folder contains a `README.md` file with instructions on how to run the code examples and complete the exercises.

## Prerequisites

To complete the exercises and run the code examples, you will need the following:

- STM32F103C8T6 microcontroller
- Keil uVision 5 IDE/STM32CubeIDE
- STLink V2 Debugger
- USB to TTL Serial Converter
- WiFi Module (ESP8266)

## Author

This course was created by Eng. Ahmed Assaf, at [IMT School].

## License

This project is licensed under the MIT License.
