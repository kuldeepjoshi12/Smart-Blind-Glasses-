# Smart Blind Glasses

> An assistive wearable device designed to help visually impaired people detect nearby obstacles using ultrasonic sensing, vibration, and audio alerts.

## Overview

Smart Blind Glasses is an assistive technology project that combines an ultrasonic sensor with an Arduino-based control system to detect obstacles in front of the user.

When an obstacle is detected within a certain distance, the system provides feedback through a vibration motor and buzzer. This allows the user to become aware of nearby obstacles without continuously looking around.

The project is designed as an educational and prototype-level solution for exploring embedded systems, sensors, automation, and assistive technology.

## Objectives

- Detect obstacles using an ultrasonic sensor.
- Provide immediate feedback when an obstacle is nearby.
- Use vibration and sound as alert mechanisms.
- Create a compact wearable assistive device.
- Explore Arduino-based embedded system development.
- Demonstrate how technology can support accessibility.

## How It Works

The system follows a simple process:

```text
Ultrasonic Sensor
       ↓
Measure Distance
       ↓
Arduino Processing
       ↓
Obstacle Detected?
    ↙         ↘
  YES          NO
   ↓            ↓
Buzzer +      Normal
Vibration     Monitoring

---

## Working Principle

1. The HC-SR04 ultrasonic sensor sends an ultrasonic pulse.


2. The pulse reflects from nearby objects.


3. The sensor calculates the distance using the returning echo.


4. Arduino processes the measured distance.


5. If an obstacle is within the configured range, the buzzer and vibration motor are activated.


6. As the obstacle becomes farther away, the alert can be reduced or stopped.

---

## Components

Component	Purpose

Arduino Nano	Main controller
HC-SR04 Ultrasonic Sensor	Obstacle detection
Piezo Buzzer	Audio alert
Vibration Motor	Physical alert
18650 Li-ion Battery	Power source
TP4056 Charging Module	Battery charging/protection
Slide Switch	Power control
Breadboard / PCB	Circuit assembly
Jumper Wires	Connections
Spectacle Frame	Wearable structure

---

## Pin Connections

Component	Arduino Pin

HC-SR04 VCC	5V
HC-SR04 GND	GND
HC-SR04 TRIG	D9
HC-SR04 ECHO	D10
Buzzer +	D6
Buzzer -	GND
Vibration Motor	Controlled through transistor/MOSFET
Motor Driver Ground	Common GND


> Note: A vibration motor should not normally be driven directly from an Arduino GPIO pin. Use an appropriate transistor or MOSFET and a protection diode.

--- 

## Features

Ultrasonic obstacle detection

Real-time distance measurement

Vibration feedback

Audio feedback

Portable wearable design

Arduino-based control

Rechargeable battery concept

Low-cost prototype design

---

## Applications

This project can be explored as an assistive technology prototype for:

Obstacle awareness

Indoor navigation assistance

Educational demonstrations

Embedded systems projects

Accessibility-focused technology research

---

## Advantages

Simple electronic design

Portable and wearable

Low-cost prototype

Real-time obstacle detection

Multiple feedback methods

Suitable for educational demonstrations

---

## Limitations

Ultrasonic sensing may be affected by certain surfaces and environmental conditions.

Detection is primarily based on the sensor's field of view.

The prototype does not replace a trained guide, mobility aid, or professional assistive device.

Battery life depends on the selected components and usage.

The prototype requires further testing for reliable real-world use.

---

## Future Improvements

Possible future improvements include:

Multiple ultrasonic sensors

Improved obstacle direction detection

Voice-based alerts

Bluetooth connectivity

GPS integration

Mobile application support

Rechargeable battery optimization

Smaller custom PCB

Improved wearable enclosure

AI-based object detection

---

## Safety Note

This is an educational prototype and should not be considered a certified mobility or safety device.

Users should not rely on the prototype as their only method of navigation or obstacle avoidance. Proper testing and engineering validation would be required before any real-world assistive deployment.

---

## Technology Used

Arduino

Embedded Systems

Ultrasonic Sensing

Electronics

Distance Measurement

Wearable Technology

Assistive Technology

---

## Project Information

Project: Smart Blind Glasses
Category: Assistive Technology
Type: Educational Prototype
Controller: Arduino Nano
Primary Sensor: HC-SR04 Ultrasonic Sensor

---

## License

This project is licensed under the MIT License.

---

## Author

Kuldeep Joshi

Built as an educational project exploring electronics, embedded systems, and assistive technology.
