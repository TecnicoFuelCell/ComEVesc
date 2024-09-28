/*
  Name:    HandBrake.ino
  Modified: 25-09-2024
  By:  DanielBurke
  Description: Example on how to set handbrake current for VESC controller.
*/

#include <ComEVesc.h>

/** Initiate VescUart class */
ComEVesc UART;

HardwareSerial VescSerial(1);

float handbrake_current = 3;

void setup() {
  Serial.begin(9600);
  VescSerial.begin(115200, SERIAL_8N1, 9, 10); // 115200 baud, 8 data bits, no parity, 1 stop bit, pins 9 (RX) and 10 (TX)
  
  while (!Serial) {;}

  /** Define which ports to use as UART */
  UART.setSerialPort(&VescSerial);
}

void loop() {
    
/** Call the function setHandBrake() to set the handbrake */
  UART.setHandBrake(handbrake_current);

}