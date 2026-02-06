## Arduino Interactive Music Console

This project implements a multifunctional interactive music console built on the Arduino platform. The system combines elements of digital musical instruments, educational software and rhythm-based games into a single embedded application. Unlike a classic rhythm game, the project offers three distinct operating modes: Free Play, Learn Mode, and Gameplay Mode, each targeting a different user interaction style and learning objective.

The console is designed to be fully self-contained, with all logic executed locally on the Arduino microcontroller. User interaction is achieved through a combination of physical buttons, a joystick, LEDs, an LCD display and a buzzer used for audio output.

Bill of materials:

* Arduino Uno
* LEDs (Red, Green, Blue, Yellow - acting as "tiles")
* Push Buttons (Player input)
* Joystick
* Buzzer (for melody and audio feedback)
* 16×2 LCD Display
* Resistors (220Ω for LEDs, 10kΩ for buttons)
* Breadboard
* Jumper wires

### System Overview

The hardware interface consists of 4 push buttons, each associated with an LED and a musical note. The LEDs provide visual feedback, while the buzzer generates sound based on predefined frequencies. A joystick is used for navigation, octave selection and menu interaction. A 16×2 LCD display presents menus, real-time status information and instructional feedback.

The system is structured around a Finite State Machine (FSM) that manages transitions between the main operating modes:

* Menu
* Free Play
* Learn Mode
* Gameplay Mode
* End states (Win / Game Over)

Each mode is implemented as a separate software component, improving modularity  and extensibility.

### Operating Modes

1. Free Play Mode

Free Play mode turns the console into a small digital musical instrument. Each button corresponds to a note, and the user can freely improvise melodies in real time.

Key features:

* Multiple octaves selectable via joystick
* Different sound effects (Normal, Vibrato, Staccato)
* Sustain functionality
* Loop recording and playback
* Real-time feedback on the LCD display

This mode focuses on creative exploration, allowing the user to experiment with sound without any constraints or scoring logic.

2. Learn Mode

Learn Mode is an educational mode designed to help users learn simple melodies step by step. The system guides the player by illuminating the correct LED and displaying the required octave on the LCD.

Key features:

* Song selection menu
* Step-by-step melody progression
* Visual guidance using LEDs
* Octave matching using joystick control
* Audio feedback only when a note is played incorrectly
* Automatic progression when the correct note is played

This mode emphasizes musical learning and muscle memory, rather than speed or scoring.

3. Gameplay Mode

Gameplay Mode introduces a reflex-based rhythm game inspired by titles such as Piano Tiles. The player must react quickly to visual cues and press the correct button within a limited time window.

Key features:

* Song selection before gameplay
* Countdown timer (3…2…1) before the song starts
* LED-based visual cues synchronized with the melody
* Time-limited reaction window for each note
* Life-based failure system
* Win and Game Over states with dedicated LCD messages

Unlike traditional rhythm games, the melody is not played automatically in full; instead, the player’s correct input triggers the sound, reinforcing timing accuracy and active participation.

### Software Architecture
The project relies heavily on non-blocking programming techniques using millis() instead of delay(). This allows the system to: update leds, monitor button input, handle audio playback, update the LCD, all simultaneously and without freezing the game loop.

Melodies are stored in array-based data structures, and timing constraints are managed using timestamp comparisons. Each mode encapsulates its own logic, while the main game engine coordinates state transitions.

### Technical challenges
The primary challenge of the project lies in coordinating multiple asynchronous tasks on a resource-constrained microcontroller. Implementing accurate timing without blocking delays was essential for responsive gameplay and correct audio-visual synchronization.

### Project scope and educational value

This project goes beyond a simple Arduino demonstration by integrating sound synthesis, user interaction, real-time input handling and structured game logic into a cohesive system. The inclusion of multiple modes makes the console suitable for both entertainment and learning, demonstrating how embedded systems can support complex interactive applications.

Overall, the project illustrates how fundamental electronic components and efficient software design can be combined to create a complete, interactive embedded music platform with clear rules, feedback mechanisms and extensibility potential.
