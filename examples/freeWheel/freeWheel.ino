/*
  Name:    freeWheel.ino
  Modified: 20-06-2024
  By:  DiogoValdrez
  Description: This is a very simple example of a possible freewheel implementarion in a esp32c3 dev M1.
*/

#include <ComEVesc.h>

/** Initiate VescUart class */
ComEVesc UART;

HardwareSerial VescSerial(1);

float maxcurrent = 5; /** initial current for ramp up */
float freecurrent = 0.6; /** The current in amps */
int rampTime = 10000; /** Time to ramp up in milliseconds */
bool stopped = false;

void setup() {
  Serial.begin(9600);
  VescSerial.begin(115200, SERIAL_8N1, 9, 10); // 19200 baud, 8 data bits, no parity, 1 stop bit, pins 9 (RX) and 10 (TX)
  
  while (!Serial) {;}

  /** Define which ports to use as UART */
  UART.setSerialPort(&VescSerial);
}

void loop() {
  /** Call the function setCurrent() to set the motor current */
  delay(1000);
  Serial.println("Ramp up");
  unsigned long startTime = millis();
  while (millis() - startTime < rampTime) {
    UART.setCurrent(maxcurrent);
  }
  Serial.println("Free wheel Start"); //TODO: check if speed is zero to stop spending energy, now bugging the esp and crashing it
  while(!stopped) {
    UART.getVescValues();
    if(UART.data.rpm == 0) {
      stopped = true;
    }
    Serial.println(UART.data.rpm);
    UART.setCurrent(freecurrent);
  }
  Serial.println("Free wheel Stoped");
}