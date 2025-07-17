# 8051 Digital Clock

A simple digital clock implementation using 8051 microcontroller and six 7-segment displays.

## What It Does

This is a basic 24-hour digital clock that displays time in HH:MM:SS format on six 7-segment displays. The clock counts seconds, minutes, and hours, rolling over appropriately (60 seconds → 1 minute, 60 minutes → 1 hour, 24 hours → 0 hours).

## Hardware Setup

- **Microcontroller**: AT89C51 (8051 family)
- **Display**: 6x common anode 7-segment displays
- **Connections**:
  - P1.0 to P1.5: Control pins for selecting which display is active
  - P2: Data lines for 7-segment patterns
  - Each display shows one digit (hours, minutes, seconds)

## How It Works

The code uses **multiplexing** to control all six displays with limited pins:
1. Quickly cycles through each display (83 times per second)
2. Turns on one display at a time, shows the correct digit
3. Moves to next display, repeats
4. This happens so fast it looks like all displays are on simultaneously

## Code Structure

```c
// Main components:
- seg_val[]: Array with 7-segment patterns for digits 0-9
- display_digit(): Shows one digit on selected display
- refresh_display(): Cycles through all 6 displays
- Time keeping: Simple counters for hours, minutes, seconds
```

## What I Learned

- **Multiplexing**: How to control multiple displays with few pins
- **Timing**: Creating delays and managing refresh rates
- **7-segment encoding**: Converting numbers to display patterns
- **Basic embedded C**: Working with microcontroller registers

## Limitations

- No real-time clock (resets to 00:00:00 on power cycle)
- Timing isn't super accurate (depends on loop timing)
- No time setting functionality
- Basic implementation without interrupts

## Circuit Simulation

The project was tested in Proteus simulation software. The images show the clock running and displaying different times as it counts up.

## Files

- `DigitalClock.c` - Main source code
- Circuit images showing the simulation running

## Notes

This was a learning project to understand:
- How 7-segment displays work
- Basic timing in embedded systems  
- Multiplexing concepts
- 8051 microcontroller programming

It's a straightforward implementation - nothing fancy, but it works and helped me understand the basics of display control and timing in embedded systems.