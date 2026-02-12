# Hardware Design

## Main Controller
- **Board:** Arduino Uno R3
- **Microcontroller:** ATmega328P
- **Operating Voltage:** 5V
- The Arduino Uno R3 was selected due to its availability, simplicity, and compatibility with educational simulation tools such as Tinkercad.

## Traffic Light LEDs (Connected in parallel)
- Red LED
- Yellow LED
- Green LED
- Current-limiting resistor: **1 kΩ**
- Only one LED is active at any given time to simulate a real traffic light sequence, therefore the use of one shared resistor.

## Push Button (Service Mode)
- Pull-up resistor: **10 kΩ**
- Requests service mode operation. Configured to trigger a hardware interrupt when a FALLING transition is detected.

## Buzzer (Audible Signal)
- Piezo buzzer
- Assists visually impaired pedestrians during crossing. Activated during pedestrian crossing phase (Green light).

## LCD Display
- Character LCD
- Displays system status. Indicates pedestrian crossing. Uses SPI communication in Arduino Uno R3, pins 11 and 12.

---

## Hardware Connections Summary

| Component     | Function                  |
|---------------|---------------------------|
| LEDs          | Traffic light simulation  |
| Push Button   | Interrupt-based input     |
| Buzzer        | Pedestrian alert          |
| LCD Display   | Status visualization      |

---

## Simulation Environment

The hardware is designed using components available in **Tinkercad**, ensuring that the project is easily reproducible for students and reviewers without requiring physical hardware.
