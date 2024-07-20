/*
  Name:    getVescValues.ino
  Modified: 20-06-2024
  By:  DiogoValdrez
  Description:  This example is made using a esp32c3 dev M1.
*/

#include <ComEVesc.h>

// Create an instance of the ComEVesc class
ComEVesc UART;

// Initialize HardwareSerial object for the VESC communication
HardwareSerial VescSerial(1); // Use UART1 on ESP32-C3

void setup() {
  // Set up the Serial port for debugging
  Serial.begin(9600);

  // Set up the VESC UART port (e.g., UART1 on ESP32-C3)
  VescSerial.begin(115200, SERIAL_8N1, 9, 10); // 19200 baud, 8 data bits, no parity, 1 stop bit, pins 9 (RX) and 10 (TX)

  // Wait for the Serial port to be ready
  while (!Serial) {
    delay(10);
  }
  
  // Define which ports to use for UART communication with VESC
  UART.setSerialPort(&VescSerial);
}

void loop() {
  // Call the function getVescValues() to acquire data from VESC
  if (UART.getVescValues()) {
    Serial.println("Data received:");
    Serial.println(UART.data.rpm);
    Serial.println(UART.data.inpVoltage);
    Serial.println(UART.data.ampHours);
    Serial.println(UART.data.tachometerAbs);
  } else {
    Serial.println("Failed to get data!");
  }

  delay(50);
}