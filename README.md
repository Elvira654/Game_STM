# Game STM

Game STM is a simple microcontroller-based game developed in C++ for the STM32F10x (ARM Cortex-M3) platform.
The game utilizes 7-segment displays and GPIO pins to show numbers, animations, and error codes directly on the hardware.

The project demonstrates low-level programming with STM32 microcontrollers, including controlling GPIO outputs, generating random numbers, and creating basic visual effects.

# Features
Control of 7-segment displays using GPIOA pins.

Random number generation for gameplay logic.

Display of numbers (0-9) and error codes.

Simple animation sequences triggered by gogogo() function.

Designed to run directly on STM32F10x microcontrollers.


# Technologies Used
Programming Language: C++

Microcontroller: STM32F10x (ARM Cortex-M3)

Libraries & Headers:

stm32f10x.h – STM32 device header for direct hardware access

<cstdlib> – Standard C++ library for random number generation


# How It Works
GPIO Control:
The application directly manipulates GPIOA pins (16–23) to light up specific segments of a 7-segment display.

Randomization:
Random numbers (0–9) are generated using std::rand() and displayed on the segments.

Error Handling:
Predefined arrays br and er store bit patterns for numbers and error messages, which are displayed when required.

Animation:
The gogogo() function repeatedly clears and updates the segments to create a simple blinking/animation effect.

# How to Run
Open the project in STM32CubeIDE, Keil uVision, or a similar ARM development environment.

Connect an STM32F10x microcontroller to a 7-segment display (pins 16–23 on GPIOA).

Compile and flash the code to the microcontroller.

The game will automatically start, showing random numbers and animations on the display.

# Future Improvements
Add input handling via buttons to make the game interactive.

Include scoring logic and game-over conditions.

Extend the animation and error display system for more dynamic visual feedback.
