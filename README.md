#ENVIROCLOCK MULTIFUNCTION-ALARAM-CLOCK-WITH-ROOM-TEMPERATURE-DISPLAY

🔹 Project Overview

A real-time embedded system built using LPC2148 ARM7 microcontroller, featuring live clock display, temperature monitoring, user-configurable alarm, and easy interaction through a keypad and LCD interface.

🚀 Key Features

⌚ Accurate Real-Time Clock (RTC)

Continuously displays current time, date, and weekday with precise timekeeping using the onboard RTC.

🌡️ Live Temperature Monitoring

Measures room temperature in real-time using LM35 sensor via ADC and updates the LCD instantly.

🔔 Smart Alarm System

1.User-configurable alarm using keypad input.

2.Alarm triggers a buzzer when time matches.

3.Auto-stop after 1 minute & manual stop supported.


🔢 Easy Keypad Interface

4×4 matrix keypad enables:

1.RTC editing.

2.Alarm setting.

3.Menu navigation.

Input values are validated for accuracy.


📟 User-Friendly LCD Display

1.Character LCD provides clear display of Time, date, temperature.

2.Menu options and user prompts.

3.Error messages for invalid inputs.

🚨 Interrupt-Driven Quick Access Menu

- External interrupt triggers a direct jump to the configuration menu without interrupting system performance.

✔️ RTC Editing with Input Validation

Ensures valid ranges for time/date including leap year handling before updating RTC registers.

🛠️Development Workflow

Keil µVision4 IDE

1.Full embedded C code development.

2.Error detection, step-wise debugging, peripheral simulation.

3.Generates HEX file for final flashing.

4.Ensures reliable and accurate firmware behavior.

Flash Magic for Programming.
1.Loads HEX file into LPC2148 via ISP and UART0.

2.Performs flash erase, write & verification.

3.Runs the embedded application in real hardware.

4.UART0 for Debugging.

🔌 Power Supply Integration

1.Provides regulated 3.3V and 5V DC.

2.3.3V for LPC2148 core and peripherals.

3.5V for LCD, keypad, LM35 & RTC modules.

4.Common ground ensures noise-free stable operation.

5.On-board regulator converts 5V → 3.3V for safe MCU usage.

📍 Project Highlights

✔ Real-time monitoring and standalone operation.

✔ Interrupt-based fast configuration.

✔ Fully validated user inputs for high accuracy.

✔ Embedded debugging support for system testing.

✔ Efficient communication using UART0.
