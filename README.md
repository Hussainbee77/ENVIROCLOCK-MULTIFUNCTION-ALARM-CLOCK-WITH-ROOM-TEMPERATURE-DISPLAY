# EnviroClock – Multifunction Alarm Clock Using LPC2148

A multifunction digital alarm clock developed using the **LPC2148 ARM7 microcontroller**, featuring RTC-based timekeeping, LM35 temperature sensing via ADC, keypad input for configuration, external interrupt–driven menu navigation, and buzzer-based alarm notification.  
This project is fully modular, hardware-tested, and implemented using **Keil uVision**.


## 🚀 Features

- **Real-Time Clock (RTC)**
  - Displays Hour:Minute:Second
  - Supports editing of time & date via keypad
  - Day of the week support

- **Temperature Monitoring**
  - LM35 sensor connected through ADC
  - Displays real-time room temperature in °C

- **Alarm Functionality**
  - Set alarm (HH:MM) using keypad
  - Buzzer rings when time matches
  - Stop alarm using physical button (P0.22)
  - Bell symbol displayed only during ringing

- **User Input via Keypad**
  - 4x4 matrix keypad
  - Supports numeric input, delete (C), operators ignored
  - Custom ReadNum function for validated input

- **LCD Interface**
  - 16x2 LCD in 8-bit mode
  - Displays:
    - Time + Day
    - Date (DD/MM/YYYY)
    - Temperature (T:X.X°C)

- **External Interrupt Menu (EINT0)**
  - Press button → Menu appears:
      1. Edit RTC  
      2. Set Alarm  
      3. Exit
         

##  Hardware Requirements

- **ARM LPC2148 Development Board**
- **LM35 Temperature Sensor**
- **16x2 Character LCD (HD44780 compatible)**
- **4x4 Matrix Keypad**
- **Buzzer (Active/Passive)**
- **Push Button (for EINT0 menu)**
- **Push Button for Alarm Stop (P0.2)**
- **Connecting Wires / Breadboard**
- **5V Power Supply**
