#include <SoftwareSerial.h>

SoftwareSerial uart(2, 3); // RX (2) and TX (3) pins for software serial communication

void setup() {
  uart.begin(9600); // Initialize software serial
  Serial.begin(9600); // Initialize hardware serial for debugging

  // Main program
  while (!Serial) {} // Wait for the serial monitor to open

  // User-selectable commands
  Serial.println("Select an option:");
  Serial.println("1 - Control Slave GPIO");
  Serial.println("2 - Send Data to Slave");
}

void loop() {
  if (Serial.available() > 0) {
    char option = Serial.read();

    switch (option) {
      case '1':
        // Send a command to control GPIO on the slave
        uart.print("C1"); // Command to control GPIO on slave
        // Send the GPIO state (1 for HIGH, 0 for LOW)
        uart.println(digitalRead(4)); // Assuming pin 4 controls the slave's GPIO
        break;

      case '2':
        // Send data to the slave
        uart.println("Hello, Slave! This is a message from the Master.");
        break;

      default:
        Serial.println("Invalid option. Select 1 or 2.");
    }
  }
}
