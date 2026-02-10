# Limitations and Design Decisions

## Platform Limitations

### Arduino Uno R3 Constraints
- Limited GPIO availability
- Limited memory resources
- LCD pin assignment constrained by SPI communication requirements
  - LCD control pins (E / RS) restricted to Arduino pins 11 and 12

---

### Interrupt Handling Constraints
- Service mode cannot preempt an active traffic cycle
- The current cycle must complete before entering service mode
- This avoids concurrent execution and ensures predictable behavior

---

## Design Decisions

### Educational and Simulation-Oriented Design
- All components were selected based on availability in Tinkercad
- Enables easy replication without physical hardware
- Prioritizes accessibility and learning over industrial realism

---

### Component Abstractions
- LEDs are used instead of real traffic lights
- Push button replaces industrial-grade pedestrian request systems
- Piezo buzzer simulates acoustic crossing signals
- LCD has a limited pixel grid for custom characters

---

### Controller Choice
- Arduino board chosen instead of a bare microcontroller
- Reduces setup complexity
- Improves accessibility for students and reviewers

---

## Known Limitations

- No real-time clock synchronization
- Service mode duration is not deterministic
- Not suitable for real-world traffic control systems

---

## Future Improvements

- Add time counter in LCD
- Replace Arduino with bare-metal microcontroller
- Implement real-time scheduling
- Add non-blocking timing using hardware timers, instead of delays
- Expand FSM with fault detection
