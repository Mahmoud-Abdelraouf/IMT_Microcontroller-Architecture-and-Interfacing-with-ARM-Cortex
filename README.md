# ARM Embedded Systems and IoT Course

Welcome to the ARM Embedded Systems and IoT Course! This repository contains the materials and code for a comprehensive course on embedded systems that covers ARM architecture basics, interrupts, real-time processing, audio processing, communications, IoT, and bootloader implementation.

## Course Overview

The course is designed for students and professionals in the field of embedded systems or IoT who want to learn about ARM architecture, real-time processing, audio processing, communications, and IoT. By the end of this course, you will be able to:

- Understand the basics of ARM architecture and peripherals.
- Implement interrupt handling techniques using the Nested Vectored Interrupt Controller (NVIC).
- Build a real-time scheduler using the SysTick and Operating Systems (OS) basics.
- Implement audio processing techniques using the Digital-to-Analog Converter (DAC).
- Implement communication protocols such as Serial, Infrared (IR), Universal Asynchronous Receiver-Transmitter (UART), and Serial Peripheral Interface (SPI).
- Build IoT applications using Wi-Fi modules and web development techniques.
- Implement a bootloader to update firmware in your microcontroller.

## Course Outline

The course is divided into 7 chapters, with a total of 22 lectures. Here is an overview of the course outline:

| Chapter                             | Lecture | Title                     | Outlines |
| ----------------------------------- | ------- | ------------------------- | -------- |
| Chapter 1 – ARM Architecture Basics | 1       | ARM Architecture          | - ARM History|
|                                     |         |                           | - Power Factors in ARM|
|                                     |         |                           | - ARM Processor Design|
|                                     |         |                           | - ARM Core Peripheral|
|                                     |         |                           | - AMBA Bus definition|
|                                     |         |                           | - Bus Matrix|
|                                     |         |                           | - Harvard To Von Neumann Conversion|
|                                     |         |                           | - Register Definition and Driver Setup|
|                                     | 2       | RCC Peripheral            | - IMT SDK for ARM Setup|
|                                     |         |                           | - Code Naming Convention|
|                                     |         |                           | - Microcontroller Clock Types|
|                                     |         |                           | - PLL and FLL|
|                                     |         |                           | - Different Reset Types|
|                                     |         |                           | - Reset and Clock Control Peripheral Driver|
|                                     | 3       | DIO Peripheral            | - Digital Input/Output peripheral Basics|
|                                     |         |                           | - Different Input and Output modes|
|                                     |         |                           | - Building DIO Driver for ST Microcontroller|
|                                     |         |                           | - Interfacing LEDs|
|                                     |         |                           | - Interfacing 7-Segment Displays|
|                                     |         |                           | - Interfacing Tactile Switches|
| Chapter 2 – ARM Interrupts          | 4       | NVIC                      | - Interrupts Basics|
|                                     |         |                           | - Interrupt Handling Techniques|
|                                     |         |                           | - The Nested Vectored Interrupt Controller|
|                                     |         |                           | - Interrupt Priority Grouping|
|                                     | 5       | NVIC Driver               | - NVIC Registers definition|
|                                     |         |                           | - Building NVIC Driver|
|                                     |         |                           | - Simulating Interrupts Feature|
|                                     | 6       | EXTI                      | - External Interrupt Basics|
|                                     |         |                           | - AFIO Peripheral|
|                                     |         |                           | - Building EXTI driver|
| Chapter 3 – Real Time               | 7       | SysTick                   | - Timer Basics|
|                                     |         |                           | - SysTick Core Peripheral|
|                                     |         |                           | - Interval Vs Busy Wait delay|
|                                     |         |                           | - Synchronous Vs Asynchronous Design|
|                                     |         |                           | - Callback Function|
|                                     |         |                           | - Building Systick Driver|
|                                     | 8       | OS Scheduler              | - Operating Systems Basics|
|                                     |         |                           | - Building Real Time Scheduler|
|                                     |         |                           | - Time Triggered Design Patter and Real Dynamic Design Aspects|
|                                     | 9       | LED Matrix                | - POV Concept|
|                                     |         |                           | - 7-Segment Displays in POV Pattern|
|                                     |         |                           | - Interfacing LED Matrix Display|
| Chapter 4 – Audio Processing        | 10      | DAC                       | - Digital To Analog Converter Basics|
|                                     |         |                           | - R2R DAC|
|                                     |         |                           | - Building DAC Driver|
|                                     | 11      | Audible Signals           | - Human Voice Characteristics|
|                                     |         |                           | - Sampling and Quantization|
|                                     |         |                           | - Dealing with audio files|
|                                     |         |                           | - Mono Vs Stereo| 
|                                     |         |                           | - Using PICAXE and AUX Speaker|
|                                     |         |                           | - Playing Sounds over DAC|
| Chapter 5 – Communications          | 12      | Serial To Parallel        | - Serial Vs Parallel Communication|
|                                     |         |                           | - Extending DIO Pins to unlimited number|
|                                     |         |                           | - Interfacing LED Matrix Serially|
|                                     | 13      | IR Communication          | - Communication Over light basics|
|                                     |         |                           | - NEC IR Protocol|
|                                     |         |                           | - Building IR Receiver Driver|
|                                     | 14      | UART                      | - Serial Communication Characteristics
|                                     |         |                           | - UART Basics
|                                     |         |                           | - Building UART Driver
|                                     |         |                           | - Interfacing USB TTL Module
|                                     | 15      | SPI and TFT               | - SPI Basics
|                                     |         |                           | - Building SPI Driver
|                                     |         |                           | - Pixel Color Modes
|                                     |         |                           | - Display Types and Comparison
|                                     |         |                           | - Interfacing TFT Displays
|                                     |         |                           | - Bit Map Images
|                                     |         |                           | - Playing Video Samples
|                                     | 16      | DMA                       | - Direct Memory Access Definitions and Basics
|                                     |         |                           | - DMA Authorities against processor
|                                     |         |                           | - DMA Driver Build
| Chapter 6 – IOT                     | 17      | WiFi Module               | - WiFi Basics
|                                     |         |                           | - WiFi Module Interfacing
|                                     |         |                           | - Networking
|                                     |         |                           | - Client and Server Model
|                                     | 18      | Web Development           | - HTML Basics
|                                     |         |                           | - PHP Basics
|                                     |         |                           | - HTTP Requests
|                                     |         |                           | - Building Simple Web Page
|                                     | 19      | IoT                       | - Building Free Server with a simple web page
|                                     |         |                           | - Connecting Microcontroller to web server
|                                     |         |                           | - Microcontroller Communication over HTTP
| Chapter 7 – Bootloader              | 20      | Story of Flashing         | - C Build Process
|                                     |         |                           | - Memory Sections
|                                     |         |                           | - Startup Code 
|                                     |         |                           | - Flashing Sequence and Burner types
|                                     |         |                           | - HEX File Format
|                                     | 21      | Hex Parser                | - Building HEX Parser Driver
|                                     |         |                           | - File Transfer over UART
|                                     | 22      | Bootloader Implementation | - Flash Driver Software
|                                     |         |                           | - Bootloader sequence

## Intended Audience

This course is intended for students and professionals with a basic understanding of microcontroller programming and electronics. Some experience with C programming is recommended but not required.

## Recommended Reading

Here are some recommended books and resources for further reading:

- "ARM System Developer's Guide: Designing and Optimizing System Software" by Andrew N. Sloss, Dominic Symes, and Chris Wright
- "Embedded Systems: Real-Time Operating Systems for ARM Cortex-M Microcontrollers" by Jonathan Valvano
- "The Definitive Guide to ARM Cortex-M3 and Cortex-M4 Processors" by Joseph Yiu
- "Programming with STM32: Getting Started with the Nucleo Board and C/C++" by Donald Norris

## Frequently Asked Questions (FAQs)

- **What programming language is used in this course?** This course primarily uses C programming language.
- **What microcontroller is used in this course?** This course uses STMicroelectronics' STM32 microcontroller.
- **Do I need to have any prior knowledge of ARM architecture?** No, this course covers the basics of ARM architecture and peripherals.
- **Is there any software required for this course?** Yes, you will need the Integrated Development Environment (IDE) Keil uVision5 and the STM32CubeMX software.
- **Can I get help if I have questions or get stuck during the course?** Yes, you can ask questions and get help through the course forums or by email.

## Getting Started

To get started with this course, follow these steps:

1. Clone or download this repository to your local machine.
2. Install the Integrated Development Environment (IDE) Keil uVision5 or the STM32CubeMX software.
3. Follow the instructions provided in each lecture to set up your development environment and complete the exercises.

That's it! We hope you enjoy this course and find it useful in your embedded systems and IoT projects.
