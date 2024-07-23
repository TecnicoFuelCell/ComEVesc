/*
  Name:    setCurrent.ino
  Modified: 20-06-2024
  By:  DiogoValdrez
  Description: This is a very simple example of how to set the current for the motor in a esp32c3 dev M1.
*/

#include <ComEVesc.h>

/** Initiate VescUart class */
ComEVesc UART;

HardwareSerial VescSerial(1);

float current = 3; /** The current in amps */

void setup() {
  Serial.begin(9600);
  VescSerial.begin(115200, SERIAL_8N1, 9, 10); // 19200 baud, 8 data bits, no parity, 1 stop bit, pins 9 (RX) and 10 (TX)
  
  while (!Serial) {;}

  /** Define which ports to use as UART */
  UART.setSerialPort(&VescSerial);
}

void loop() {
  
  /** Call the function setCurrent() to set the motor current */
  UART.setCurrent(current);

  // UART.setBrakeCurrent(current);
  
}