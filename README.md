## Arduino Rhythm Game

This project implements an interactive embedded gaming console inspired by rhythm-based games such as Piano Tiles and Guitar Hero. The goal of the system is to test the user’s reflexes and synchronization skills using a combination of visual and audio feedback.

The console is built around a linear array of LEDs, each associated with a push button. During gameplay, the system generates a sequence of visual cues by lighting up the LEDs in synchronization with a musical melody played through a buzzer. The player must press the correct button within a predefined time window in order to score points. If the input is incorrect or too late, the player loses a life.

The software architecture is based on a Finite State Machine, which manages the main game states: Menu, Gameplay and Game Over. In the Menu state, the user selects the desired difficulty level: Easy, Medium or Hard. Each difficulty level corresponds to a different set of melodies and gameplay parameters.

The difficulty affects the speed of the LED sequence, the allowed reaction time, and the complexity of the melody. Easy mode uses slower tempos and simpler patterns, while Medium and Hard modes progressively increase the speed and reduce the time window for user input. The selected difficulty and song are displayed on a 16×2 LCD, which also shows real-time information such as the current score and remaining lives during gameplay.

From a software perspective, the project focuses on core embedded systems concepts such as non-blocking timing using millis(), array-based data structures for storing melodies and patterns and real-time user input handling.

Bill of materials:

* Arduino Uno
* LEDs (Red, Green, Blue, Yellow - acting as "tiles")
* Push Buttons (Player input)
* Joystick
* Buzzer (for melody and audio feedback)
* LCD Display 16×2
* Resistors (220Ω for LEDs, 10kΩ for buttons)
* Breadboard
* Jumper wires

### System Description

The system consists of the hardware console (Arduino, LEDs, buttons, LCD display, and buzzer) and the embedded software running on the microcontroller. The user (player) and the external power source (USB or battery) are considered outside the system boundary. Interaction with the user is achieved through visual and audio outputs, while input is received through buttons and the joystick.

All intelligence is implemented locally on the Arduino microcontroller. The system does not depend on a PC or any cloud connection. The Arduino handles the entire game loop, including melody playback, pattern generation (random or predefined), reaction time measurement using internal timers, and real-time updates of score and difficulty.

### Technical Challenges and Demo

The main technical challenge of the project is implementing non-blocking, asynchronous logic. Unlike simple projects that rely on the delay() function, this game must perform several tasks simultaneously: playing musical notes, controlling LED timing and continuously scanning button inputs. This is achieved using millis()-based timing logic, which ensures responsive gameplay and smooth audio output.

The minimum functional demo includes selecting a song from the menu, correctly synchronizing the LED patterns with the buzzer melody and accurately detecting a “Hit” (score increase) or a “Miss” (life lost) based on the user’s input.

### Project scope

This project is more complex than a basic tutorial because it combines several hardware and software components into one functional game. Unlike simple examples that only turn on an LED or play a sound, this project includes a menu system, multiple difficulty levels and different melodies. The game logic is organized using a Finite State Machine, which controls the flow of the game. 

Overall, the project shows how simple electronic components can be used together to create a complete interactive embedded game with clear rules for winning and losing.
