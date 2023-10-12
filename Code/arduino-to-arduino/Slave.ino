#include <SoftwareSerial.h>

SoftwareSerial uart(2, 3); // RX (2) and TX (3) pins for software serial communication

void setup() {
  uart.begin(9600); // Initialize software serial
  Serial.begin(9600); // Initialize hardware serial for debugging

  pinMode(5, OUTPUT); // Define a pin as an output to control it
}

void loop() {
  if (uart.available() > 0) {
    char command = uart.read();
    
    if (command == 'C') {
      // Control GPIO command received
      char action = uart.read();
      if (action == '1') {
        int state = uart.parseInt();
        digitalWrite(5, state); // Control the GPIO based on received data
        Serial.println("GPIO state changed by Master.");
      }
    } else {
      // Data from Master
      while (uart.available()) {
        char dataChar = uart.read();
        Serial.print(dataChar);
      }
      Serial.println(); // Newline after receiving data
    }
  }
}
