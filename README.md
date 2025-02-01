# ESP-NOW-Protocol
A simple ESP-NOW-based communication setup with ESP32/ESP8266 devices. The repo includes code for both sender and receiver, with circuit diagrams and step-by-step instructions to wirelessly control devices, such as an LED, using ESP-NOW. Ideal for IoT applications requiring low power, low-latency communication.

## Features
- Use **ESP-NOW** to send signals from one ESP8266 (sender) to control LEDs on another ESP8266 (receiver).
- Control 2 LEDs with 2 push buttons.
- Push buttons on ESP8266 send commands to the LEDs on a second ESP8266.

## Hardware Required
- 2 x **ESP8266** development boards (e.g., NodeMCU, Wemos D1 Mini)
- 2 x **Push buttons** (for the sender ESP8266)
- 2 x **LEDs** (for the receiver ESP8266)
- 2 x **Resistors** (220Ω for LEDs and 10kΩ for pull-down resistors on buttons)
