### Speed monitoring system for an autonomous line-follower robot

This project implements a simple robotic system that simulates a traffic speed monitoring scenario. The system consists of an autonomous mobile robot and a fixed monitoring station. The robot follows a predefined road using infrared sensors and DC motors, while its speed is adjusted manually through an analog input.

The monitoring station detects the robot as it passes through a defined section of the road and calculates its speed based on the time measured between two infrared sensors placed at a known distance. If the calculated speed exceeds a user-defined limit, the system provides immediate visual and sound feedback.

The project focuses on basic robotics concepts such as sensor usage, motor control, timing, and real-time feedback, and is designed to be clear, reliable, and suitable for an introductory robotics course.

### Bill of materials

Car:

* Arduino Uno
* Robot chassis
* 2 × DC motors
* 2 × wheels
* Ball caster
* Motor driver (L293D)
* Infrared reflectance sensors (line detection)
* Breadboard
* Battery pack
* Potentiometer
* Jumper wires, zip ties

Speed Monitoring Station

* Arduino Uno
* 2 × IR sensors (used as passage detectors)
* LCD display (16×2 or similar)
* Joystick module
* Red LED
* Green LED
* Buzzer
* Resistors and jumper wires

Q1 – What is the system boundary?

The system consists of the mobile robot and the fixed monitoring station with their sensors and controllers, while the user and the environment are outside the system boundary.

Q2 – Where does intelligence live?

Intelligence lives on the device, specifically on the Arduino microcontroller embedded in each unit. The robot and the monitoring station function independently. Each one processes its own sensor data locally to execute real-time decisions, without relying on an external computer or cloud processing.

Q3 – What is the hardest technical problem?

The hardest technical problem is timing. Accurate speed calculation relies on the precise detection of the robot passing the IR sensors. Since the measurement distance is short, even a few milliseconds of delay in sensor response or code execution can result in significant errors in the final speed readout.

Q4 – What is the minimum demo?

The minimum demo is the robot passing the monitored section and the system correctly detecting the speed and triggering an alert when the limit is exceeded.

Q5 – Why is this not just a tutorial?

This project is not a tutorial because it involves combining and adapting distinct systems. While the standard laboratory guide was used for the robot’s chassis, the software was adapted to include manual analog throttle control, a feature not present in the original design. Additionally, the project introduces a custom speed monitoring system with its own sensing logic and user interface, moving beyond simple component wiring to create an interactive simulation.


