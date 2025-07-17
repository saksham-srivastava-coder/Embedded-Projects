# 8051 Embedded Projects

Basic embedded C projects using 8051 microcontroller for learning hardware interfacing concepts.

## Projects

### 1. Digital Clock
- **File**: `DigitalClock.c`
- **Hardware**: 6x 7-segment displays
- **Function**: 24-hour digital clock (HH:MM:SS)
- **Concepts**: Display multiplexing, timing loops, counter logic

### 2. LCD Display
- **File**: `LCD.c` 
- **Hardware**: 16x2 character LCD
- **Function**: Typewriter-style text animation
- **Concepts**: LCD interfacing, character display, basic animations

## Hardware Used
- AT89C51 microcontroller
- 7-segment displays (common anode)
- 16x2 LCD display
- Basic connections via P1 and P2 ports

## What I Learned
- Basic 8051 programming in C
- Hardware interfacing without libraries
- Display control and multiplexing
- Simple timing and animation techniques
- Understanding microcontroller pin configurations

## Tools
- **IDE**: Keil µVision / Similar 8051 development environment
- **Simulation**: Proteus (circuit simulation and testing)
- **Language**: Embedded C with 8051 register programming

## Notes
These are learning projects to understand embedded systems basics. Both projects use simple polling-based approaches and basic delay functions for timing. The code focuses on getting things working rather than optimization.

**Circuit simulations included** - Shows the projects running in Proteus with actual hardware connections and outputs.

## Files Structure
```
├── DigitalClock.c          # 7-segment clock implementation
├── LCD.c                   # LCD text display with animation
├── circuit_images/         # Proteus simulation screenshots
└── README.md              # This file
```

Simple projects, but they work and helped me understand the fundamentals of embedded programming with 8051.
<br>
Author - Saksham Srivastava

