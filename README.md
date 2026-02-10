\# Traffic Light Embedded System (Arduino Uno)



\## Overview



This project implements a traffic light control system using an \*\*Arduino Uno R3\*\*, designed as an educational embedded systems project and simulated using \*\*Tinkercad\*\*.



The system models a real-world traffic light with pedestrian crossing support, a service/maintenance mode, and an accessibility feature for visually impaired users through an audible signal.  

The control logic is implemented using a \*\*finite state machine (FSM)\*\* and an \*\*interrupt-driven service request\*\*.



---



\## Project Structure



traffic-light-embedded/

├── firmware/

├── hardware/

├── simulation/

├── docs/

└── README.md



This repository contains:

\- Embedded firmware source code

\- Simulation files

\- Hardware documentation

\- System architecture and state machine design



---



\## Demo



A short simulation demo is available in:

simulation/tinkercad/traffic\_light\_demo.mp4



Screenshots and diagrams are located in:

simulation/tinkercad/traffic\_light.png

diagrams/traffic\_light\_fsm.png

---



\## Simulation



The project is fully simulated using \*\*Tinkercad\*\*, allowing easy replication without physical hardware.



Simulation files and instructions can be found in:

simulation/



---



\## System Architecture



The system is built around an Arduino Uno R3 and follows a modular architecture:



\- \*\*Controller:\*\* Arduino Uno R3

\- \*\*Inputs:\*\* Push button (interrupt-driven)

\- \*\*Outputs:\*\*

&nbsp; - Traffic light LEDs

&nbsp; - Piezo buzzer

&nbsp; - LCD display



A high-level architecture diagram is provided below:

diagrams/traffic\_light\_system\_architecture.png



---



\## Traffic Light Logic



The system operates as a finite state machine with the following states:



1\. \*\*RED\*\* – Default and safe state

2\. \*\*GREEN\*\* – Pedestrian Crossing + Buzzer

3\. \*\*YELLOW\*\* – Transition state

4\. \*\*SERVICE MODE\*\* – Yellow blinking, system maintenance



Service mode is requested via a hardware interrupt and is entered only after the current traffic cycle completes and before the system returns to RED.



---



\## Hardware Components



| Component        | Description                              |

|------------------|------------------------------------------|

| Arduino Uno R3   | Main controller                          |

| Red LED          | Traffic stop signal                      |

| Yellow LED       | Transition / service indication          |

| Green LED        | Traffic go signal                        |

| Push Button      | Service mode request (interrupt)         |

| Piezo Buzzer     | Audible pedestrian alert                 |

| LCD Display      | System status visualization              |

| Resistors        | 1 kΩ (LEDs), 10 kΩ (button pull-down),   |

|                  | 10 kΩ (push button), 220 Ω (LCD)         |

|                  | 10 kΩ potentiometer (LCD contrast)       |



A schematic diagrm for the system is provided in:

hardware/schematics/traffic\_light\_schematic.pdf

The BOM can be found in:

hardware/bom.csv



---



\## Design Decisions \& Limitations



Detailed discussion available in:

docs/limitations\_and\_design\_decisions.md



---



\## License



This project is provided for educational and portfolio purposes.



---



\## Learning Outcomes



* Finite State Machine design
* Interrupt handling
* Embedded timing control
* Modular firmware architecture
* Hardware/software co-design
* Embedded system documentation













