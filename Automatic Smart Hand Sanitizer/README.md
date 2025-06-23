# ✨ Automatic Smart Hand Sanitizer ✨

A simple, contactless, and hygienic solution to dispense hand sanitizer using an Arduino, an ultrasonic sensor, and a servo motor. Keep your hands clean without touching a thing!


_^(This is a sample GIF. Replace it with a GIF of your own project in action!)_

<p align="center">
  <img src="https://img.shields.io/badge/Arduino-UNO%2FNano-00979D?style=for-the-badge&logo=arduino" alt="Arduino Badge">
  <img src="https://img.shields.io/badge/Platform-Arduino_IDE-blue?style=for-the-badge" alt="Platform Badge">
  <img src="https://img.shields.io/badge/Status-Complete-brightgreen?style=for-the-badge" alt="Status Badge">
  <img src="https://img.shields.io/badge/License-MIT-yellow?style=for-the-badge" alt="License Badge">
</p>

## 🚀 Overview

This project provides a hands-free way to get hand sanitizer. When the ultrasonic sensor detects a hand placed under the nozzle, it signals the Arduino. The Arduino then activates a servo motor, which pushes down on the sanitizer bottle's pump, dispensing a set amount of liquid. It's a fun, practical, and highly relevant DIY project for homes, offices, and public spaces.

## 🌟 Features

-   **🙌 Contactless Operation:** Reduces germ transmission by eliminating the need to touch the bottle.
-   **🤖 Smart Detection:** Uses an HC-SR04 ultrasonic sensor for reliable hand detection.
-   **🔧 Adjustable:** Easily tweak the code to change the detection distance and amount of sanitizer dispensed.
-   **💸 Low-Cost & Accessible:** Built with common and affordable electronics components.
-   **🔌 Simple to Build:** Perfect for beginners and hobbyists familiar with the Arduino ecosystem.

## 🛠️ Bill of Materials (BOM)

Here are the components you'll need to build this project:

| Component | Quantity | Notes |
| :--- | :---: | :--- |
| Arduino Uno (or Nano) | 1 | The brains of the operation. |
| 🔌 Ultrasonic Sensor (HC-SR04) | 1 | The "eyes" that detect a hand. |
| ⚙️ Micro Servo Motor (SG90) | 1 | The "muscle" that presses the pump. |
|  sanitizer Bottle | 1 | One with a press-down pump mechanism. |
| 🍞 Breadboard | 1 | Optional, but highly recommended for prototyping. |
| ➰ Jumper Wires | ~10 | Male-to-Male and Male-to-Female. |
| 🔋 Power Source | 1 | 5V USB adapter, 9V battery, or a battery pack. |

## 🔌 Circuit Diagram & Wiring

Follow this wiring guide to connect your components. It's crucial to connect the Servo motor to a 5V pin, **not** the Vin pin.


_^(This is a sample diagram. You can create your own using Fritzing or draw.io and replace this image.)_

Here are the pin connections in detail:

| Component | Pin | Connect to Arduino |
| :--- | :---: | :---: |
| **HC-SR04 Sensor** | `VCC` | `5V` |
| | `Trig` | `Digital Pin 9` |
| | `Echo`| `Digital Pin 10`|
| | `GND` | `GND` |
| **SG90 Servo Motor**| `Power (Red)` | `5V` |
| | `Signal (Orange)`| `Digital Pin 11` |
| | `GND (Brown)`| `GND` |

**Important Note:** Powering the servo motor directly from the Arduino's 5V pin is fine for testing, but for long-term use, it's highly recommended to power the servo with a separate 5V, 1A power supply to avoid over-stressing the Arduino's voltage regulator.

## 💻 The Code

The Arduino code is straightforward. It measures the distance from the sensor, and if an object is detected within a set range, it activates the servo.

```cpp
/*
 *  Automatic Smart Hand Sanitizer
 *
 *  Description: This code controls a contactless hand sanitizer dispenser.
 *               It uses an HC-SR04 ultrasonic sensor to detect a hand and
 *               a servo motor to press the sanitizer pump.
 *
 *  Author: Your Name
 *  Date:   YYYY-MM-DD
 *
 *  ----------------- PIN CONFIGURATION -----------------
 *  - HC-SR04 Trig Pin  -> Arduino Pin 9
 *  - HC-SR04 Echo Pin  -> Arduino Pin 10
 *  - SG90 Servo Signal -> Arduino Pin 11
 *  -----------------------------------------------------
 */

#include <Servo.h>

// --- Configuration ---
const int TRIGGER_PIN = 9;         // Pin connected to the HC-SR04 Trig pin
const int ECHO_PIN = 10;           // Pin connected to the HC-SR04 Echo pin
const int SERVO_PIN = 11;          // Pin connected to the Servo motor signal wire

const int SERVO_REST_ANGLE = 90;   // Angle of the servo when idle (not pressing)
const int SERVO_PRESS_ANGLE = 180;  // Angle of the servo when pressing the pump
const int ACTIVATION_DISTANCE = 10; // Distance in cm to activate the dispenser
const int DISPENSE_DELAY = 500;    // Time in ms the servo holds the press

// --- Global Variables ---
Servo myServo;      // Create a servo object to control a servo
long duration;      // Variable for the duration of the sound wave travel
int distance;       // Variable for the distance measurement

void setup() {
  // Initialize Serial Monitor for debugging
  Serial.begin(9600);
  
  // Initialize the servo motor
  myServo.attach(SERVO_PIN);
  myServo.write(SERVO_REST_ANGLE); // Set servo to its resting position
  
  // Initialize the ultrasonic sensor pins
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  Serial.println("✅ Smart Sanitizer Ready!");
}

void loop() {
  // --- Step 1: Trigger the sensor ---
  // Clear the trigger pin
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  
  // Sets the trigger pin on HIGH state for 10 micro seconds
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  // --- Step 2: Read the echo pin ---
  // Reads the echo pin, returns the sound wave travel time in microseconds
  duration = pulseIn(ECHO_PIN, HIGH);
  
  // --- Step 3: Calculate the distance ---
  // Speed of sound = 340 m/s or 0.034 cm/uS
  // Distance = (Time/2) * Speed of Sound
  distance = duration * 0.034 / 2;

  // Print the distance for debugging
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // --- Step 4: Check if a hand is detected ---
  if (distance > 0 && distance < ACTIVATION_DISTANCE) {
    Serial.println("Hand Detected! Dispensing...");
    
    // Dispense the sanitizer
    dispenseSanitizer();
    
    // Wait for 2 seconds to prevent immediate re-triggering
    delay(2000); 
  }

  // A small delay to make the loop more stable
  delay(100);
}

/**
 * @brief Activates the servo to press and release the pump.
 */
void dispenseSanitizer() {
  myServo.write(SERVO_PRESS_ANGLE);   // Move servo to press the pump
  delay(DISPENSE_DELAY);              // Hold the position
  myServo.write(SERVO_REST_ANGLE);    // Move servo back to resting position
}

```

### How to Upload the Code

1.  **[Download the Arduino IDE](https://www.arduino.cc/en/software)** if you don't have it.
2.  Install the `Servo` library (it comes pre-installed with the Arduino IDE).
3.  Connect your Arduino board to your computer.
4.  Copy the code above and paste it into a new sketch in the Arduino IDE.
5.  Go to **Tools > Board** and select your Arduino model (Uno/Nano).
6.  Go to **Tools > Port** and select the correct COM port.
7.  Click the **Upload** button.

## 🏗️ Assembly & Casing

This is where you get creative!

1.  **Mount the Servo:** The most critical part is positioning the servo motor so its arm can effectively press the sanitizer pump. You can design and 3D print a custom mount, use hot glue, or create a simple enclosure from cardboard or a project box.
2.  **Position the Sensor:** Place the HC-SR04 sensor near the nozzle, pointing downwards, where a hand would naturally be placed.
3.  **Secure the Electronics:** Place the Arduino and breadboard inside the casing to keep them safe and organized.

## 💡 Customization & Improvements

-   **Adjust Sensitivity:** Change the `ACTIVATION_DISTANCE` variable to make the sensor more or less sensitive.
-   **Control Dispense Amount:** Modify the `DISPENSE_DELAY` and `SERVO_PRESS_ANGLE` to control how much sanitizer is dispensed with each use.
-   **Add an LED:** Connect an LED to a digital pin to light up when the sanitizer is being dispensed.
-   **Low-Level Indicator:** Add a second sensor (like an IR sensor) at the bottom of the bottle to detect when sanitizer is low and light up a warning LED.
-   **3D Printed Case:** Design and print a sleek, custom-fit enclosure for a professional finish.

## 🤝 Contributing

Contributions are what make the open-source community such an amazing place to learn, inspire, and create. Any contributions you make are **greatly appreciated**.

1.  Fork the Project
2.  Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3.  Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4.  Push to the Branch (`git push origin feature/AmazingFeature`)
5.  Open a Pull Request

## 📜 License

This project is distributed under the MIT License. See `LICENSE.txt` for more information.

---

<p align="center">Made with ❤️ and a passion for clean hands.</p>
