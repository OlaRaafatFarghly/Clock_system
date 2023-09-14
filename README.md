# Clock system <br />
This project aims to develop a PC login system using UART communication with the Nucleo board. The system allows users to select between displaying/setting the time and date or setting up to 5 alarms. Additionally, the project establishes connectivity between the Nucleo and Bluepill boards using SPI and connects the Bluepill board to an LCD using parallel communication. <br />

## Features
•The project includes the following features: <br />
•Displaying and setting the time and date <br />
•Setting up to 5 alarms <br />
•UART communication between the PC and Nucleo board <br />
•SPI communication between the Nucleo and Bluepill boards <br />
•Parallel communication between the Bluepill board and LCD <br />
•Custom drivers for various components: <br />
> •GPIO <br />
> •RCC <br />
> •NVIC <br />
> •SCB <br />
> •EXTI <br />
> •SYSCFG <br />
> •DMA <br />
> •UART <br />
> •SPI <br />
> •I2C <br />
> •DS10307 RTC <br />
> •LCD <br />
> •LED <br />
> •Buzzer <br />
> •SysTick <br />

## Dependencies
To use this project, you will need the following dependencies: <br />
•Nucleo board <br />
•Bluepill board <br />
•LCD module <br />
•DS10307 RTC module <br />
•Other components mentioned in the driver section <br />
•Development environment compatible with the Nucleo board <br />
## Usage
•Connect the Nucleo board to the PC using UART communication. <br />
•Connect the Nucleo and Bluepill boards using SPI communication. <br />
•Connect the Bluepill board to the LCD module using parallel communication. <br />
•Ensure that all the required drivers and dependencies are properly installed. <br />
•Build and upload the project to the Nucleo board using the compatible development environment. <br />
•Run the PC login system application on your computer. The system will prompt you to select between displaying/setting the time and date or setting up alarms. <br />
•Follow the on-screen instructions to interact with the system. <br />
