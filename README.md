# ComEVesc

Based on https://github.com/SolidGeek/VescUart

Arduino/Esp library for interfacing with a VESC over UART. 
This library is being updated to work with FW6.05 and we are trying to make all the VESC features available here.

# CAN BUS Support

CAN BUS is supported, such that you can communicate with multiple VESCs over a single UART port. All methods can be called with a CAN ID, and the main VESC will forward the command to the desired CAN Id.
**You can't use a CAN bus ID of 0 for this library, as this is used to refer to the local device.**

# FreeWheel

In one of of the examples we show how to implement a freewheel. We've noticed there are a lot of people asking for freewheel support in VESC forums so we decided to share our implementation on the examples. The concept is to input a current to the motor in order to surpass the motor friction. This current isnt enought to make the motor move but it's enough to make it slow down for a longer time. when the motor is fully stopped the current is no longer inputed.

# Usage

1. install pyserial
2. install the zip file
3. go to Sketch->Include Library->Add .ZIP Library and select this ZIP

# Contacts

Any question contact me on Discord: duz2002