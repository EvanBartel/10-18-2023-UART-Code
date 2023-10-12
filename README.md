# Arduino UART Communication - Master and Slave

## Overview

This project demonstrates how to establish communication between two Arduino boards using UART (Universal Asynchronous Receiver/Transmitter) in a master-slave configuration. The master Arduino can send commands to control GPIO pins on the slave Arduino or send data to be printed on the slave's serial monitor.

## Components

- 2 Arduino boards (e.g., Arduino Uno)
- Jumper wires
- Appropriate power source

## Wiring

Connect the two Arduino boards for UART communication using Software Serial:

- **Master Arduino:**
  - Pin 2 (TX) to Slave Arduino Pin 2 (RX)
  - Pin 3 (RX) to Slave Arduino Pin 3 (TX)

- **Slave Arduino:**
  - Connect a GPIO pin (e.g., Pin 5) to an LED or other output device, if controlling GPIO is required.

## Master Arduino Code

The `Master_Arduino.ino` file contains the code for the master Arduino. It allows you to send commands to control the slave Arduino's GPIO pin or send data to be displayed on the slave's serial monitor. Instructions for installation and usage are provided in the code comments.

## Slave Arduino Code

The `Slave_Arduino.ino` file contains the code for the slave Arduino. It listens for commands from the master Arduino. If a control command is received, it adjusts the GPIO pin's state accordingly. If data is received from the master, it prints the data on its serial monitor.

## Usage

4. Open the serial monitor and select the baud rate (9600 by default).
5. Follow the prompts on the master Arduino's serial monitor to send commands and control the slave or send data to the slave.

## Contributing

We welcome contributions! If you'd like to contribute to this project, please follow our [Contribution Guidelines](CONTRIBUTING.md).

## License

This project is licensed under the [MIT License](LICENSE).

## Contact

If you have any questions or need further assistance, you can contact us at [your-email@example.com].
