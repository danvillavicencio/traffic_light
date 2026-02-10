# System Architecture

## Overview

This project implements a traffic light control system using an Arduino Uno R3 as the main controller.  
The system simulates a real-world traffic light with pedestrian crossing support, service mode operation, and accessibility features for visually impaired users.

The architecture is based on a finite state machine (FSM) that controls LEDs, a buzzer, and an LCD display. External interaction is handled through a push button connected via hardware interruption.

---

## High-Level Architecture

The system is composed of the following main blocks:

- **Controller:** Arduino Uno R3
- **Inputs:** Service push button (interrupt-driven)
- **Outputs:**
  - Traffic light LEDs (Red, Yellow, Green)
  - Piezo buzzer (audible pedestrian signal)
  - LCD display (system status feedback and pedestrian crossing)

---

## Execution Flow

1. System powers on and initializes
2. Traffic light FSM starts automatically
3. LEDs cycle through Red → Green (with pedestrian crossing) → Yellow
   - During Green, pedestrian crossing triggers buzzer output and LCD display
4. External interruption may request service mode through push button activation
5. Service mode is entered once the current traffic cycle completes (after Yellow signal)
   - During Service mode, Yellow light blinks a pre-defined number of times
6. Current execution ends and cycle restarts at 2.

---

## Design Characteristics

- Event-driven behavior using hardware interrupts
- Deterministic state transitions
- Separation between control logic and hardware access
- Designed for simulation-first validation


