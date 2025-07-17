# 8051 LCD Display

A simple program to display text on a 16x2 LCD using 8051 microcontroller with typewriter-style character animation.

## What It Does

This program displays a hardcoded string "GAJENDRA Saksham Aakarsh" on a 16x2 LCD display with a typing effect - each character appears one by one with a 300ms delay, creating a typewriter animation. After displaying the complete text, it clears and repeats.

## Hardware Setup

- **Microcontroller**: AT89C51 (8051 family)
- **Display**: 16x2 character LCD (LM016L in simulation)
- **Connections**:
  - P1.0 (RS): Register Select (Command/Data selection)
  - P1.1 (RW): Read/Write (always set to write)
  - P1.2 (EN): Enable pin for LCD operation
  - P2: 8-bit data bus to LCD

## How It Works

The program follows standard LCD interfacing protocol:
1. **Initialization**: Sets up LCD in 8-bit mode, 2-line display, cursor off
2. **Character Display**: Sends each character individually with delays
3. **Line Management**: Automatically moves to second line after 16 characters
4. **Animation**: 300ms delay between each character for typewriter effect
5. **Loop**: Clears display and repeats the whole process

## Code Structure

```c
// Main functions:
- lcd_cmd(): Sends commands to LCD (clear, cursor position, etc.)
- lcd_data(): Sends character data to display
- lcd_init(): Initializes LCD with required settings
- delay_ms(): Basic timing delays
```

## LCD Commands Used

- `0x38`: 8-bit interface, 2-line display, 5x7 font
- `0x0C`: Display on, cursor off
- `0x01`: Clear display
- `0x80`: Move cursor to first line
- `0xC0`: Move cursor to second line

## What I Learned

- **LCD interfacing**: How to communicate with character displays
- **Protocol timing**: Understanding setup/hold times for LCD operations
- **Display control**: Managing cursor position and display commands
- **Character animation**: Creating simple visual effects with delays

## Limitations

- Text is hardcoded (no user input)
- Basic delay-based timing (not very precise)
- No error checking or status reading from LCD
- Simple character-by-character display only

## Circuit Simulation

Tested in Proteus simulation software. Images show the typing animation in progress - you can see characters appearing one by one and the text wrapping to the second line.

## Files

- `LCD.c` - Main source code
- Circuit images showing the simulation at different stages

## Notes

This was a learning project to understand:
- Basic LCD interfacing with 8051
- How LCD commands and data transmission work
- Creating simple animations with delays
- Managing multi-line text display

Pretty straightforward implementation - just wanted to see how LCD displays work and get the basics down. The typewriter effect was added to make it a bit more interesting than just static text.