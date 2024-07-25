/*
  Name:    freeWheel.ino
  Modified: 25-07-2024
  By:  DiogoValdrez
  Description: This is a very simple example of a possible freewheel implementation in a esp32c3 dev M1. 
  To fine tune the frewheel you must run this example and tune the freecurrent variable. You should choose a value that lets the wheel run for a while after the motor is stopped.

*/

#include <ComEVesc.h>

/** Initiate VescUart class */
ComEVesc UART;

HardwareSerial VescSerial(1);

float maxcurrent = 5; /** initial current for ramp up */
float freecurrent = 0.6; /** The current in amps that enables the freewheel. This current must be fine tuned. */
int rampTime = 10000; /** Time to ramp up in milliseconds */
bool stopped = false;

void setup() {
  Serial.begin(9600);
  VescSerial.begin(115200, SERIAL_8N1, 9, 10); // 115200 baud, 8 data bits, no parity, 1 stop bit, pins 9 (RX) and 10 (TX)
  
  while (!Serial) {;}

  /** Define which ports to use as UART */
  UART.setSerialPort(&VescSerial);
}

void loop() {
  /** Call the function setCurrent() to set the motor current */
  Serial.println("Ramp up");
  stopped = false;

  
  unsigned long startTime = millis();

  while (millis() - startTime < rampTime) {
    UART.setCurrent(maxcurrent);
    delay(500); 
    UART.getVescValues();
    Serial.println(UART.data.rpm);
    delay(500); // Introduce a delay to prevent CPU overload
  }
  Serial.println("Free wheel Start");
  
  while(!stopped) {
    UART.getVescValues();
    delay(500);

    if(UART.data.rpm == 0) {
      stopped = true;
    } else {
      UART.setCurrent(freecurrent);
    }
    Serial.println(UART.data.rpm);
    delay(500); // Introduce a delay to prevent continuous high CPU load
  }

  Serial.println("Free wheel Stopped");
  delay(50000); // Add a delay before the loop restarts
}