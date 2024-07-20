# ComEVesc

Based on https://github.com/SolidGeek/VescUart

Arduino library for interfacing with a VESC over UART. 
This library is being updated to work with FW6.05 and we are trying to make all the VESC features available here.

# CAN BUS Support

CAN BUS is supported, such that you can communicate with multiple VESCs over a single UART port. All methods can be called with a CAN ID, and the main VESC will forward the command to the desired CAN Id.
**You can't use a CAN bus ID of 0 for this library, as this is used to refer to the local device.**

# Usage

1. install pyserial
2. install the zip file
3. go to Sketch->Include Library->Add .ZIP Library and select this ZIP