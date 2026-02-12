# Finite State Machine (FSM)

## Overview

The traffic light system is implemented as a finite state machine (FSM) that ensures deterministic behavior and safe transitions between traffic states.

---

## States Definition

### 1. RED
- Red LED ON
- Entry point after power-up and service mode (Default safe state)

### 2. GREEN / PEDESTRIAN CROSSING
- Green LED ON
- Buzzer ON
- Pedestrians crossing sign ON (in LCD)

### 3. YELLOW
- Yellow LED ON
- Prepares system to return to RED or SERVICE MODE if interrupt was detected

### 4. SERVICE MODE
- Yellow LED blinking
- Normal traffic operation disabled
- LCD indicates service mode
- Triggered via external interrupt
- Entered only after finishing YELLOW state

---

## State Transition Diagram

RED → GREEN → YELLOW → int=0/int=1 → RED/S.M. → RED

---

## Interrupt Handling Logic

- A hardware interrupt is triggered by the service button
- The interrupt does not immediately change state
- A service request flag is set
- The FSM transitions to SERVICE MODE only after completing the current cycle and before returning to RED

---

## Timing Behavior

- Each state has a fixed or predefined duration
- Service mode duration is currently implemented as a random time interval
- Timing logic is centralized to avoid blocking operations


