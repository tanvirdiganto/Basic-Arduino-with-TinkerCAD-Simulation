
💡 Arduino Capacitance Meter

![alt text](https://img.shields.io/badge/Arduino-00979D?style=for-the-badge&logo=Arduino&logoColor=white)


![alt text](https://img.shields.io/badge/Platform-Uno%20%7C%20Nano%20%7C%20Mega-blue?style=for-the-badge)


![alt text](https://img.shields.io/badge/License-MIT-green?style=for-the-badge)

A simple yet effective project to measure capacitance using an Arduino, a known resistor, and the principle of an RC charging circuit.

📋 Table of Contents

🤔 How It Works

🧱 Required Components

🔌 Circuit Diagram

🔧 Setup Instructions

💻 Arduino Code

▶️ How to Use

⚠️ Accuracy and Limitations

📜 License

🤔 How It Works

This project leverages the fundamental property of a Resistor-Capacitor (RC) circuit: the time it takes to charge a capacitor. This time is defined by the time constant, represented by the Greek letter tau (τ).

τ = R × C

Where:

τ is the time constant in seconds.

R is the resistance in Ohms.

C is the capacitance in Farads.

The Arduino measures the time (T) it takes for the capacitor's voltage to reach 63.2% of its charging voltage. It does this by:

Discharging the capacitor to 0V.

Charging the capacitor through a digital pin connected to the RC circuit.

Timing how long it takes for the voltage (read by an analog pin A0) to cross the 63.2% threshold (an analog reading of ~647).

Calculating the unknown capacitance (C) using the formula: C = T / R

🧱 Required Components

1️⃣ x Arduino Board (e.g., Uno, Nano, Mega)

1️⃣ x 1kΩ Resistor (1% tolerance recommended)

1️⃣ x Capacitor to be measured

1️⃣ x Breadboard

➖ Jumper Wires

🔌 Circuit Diagram

Connect the components as shown below.

Pin 8 (Charge Pin) → 1kΩ Resistor

Resistor → Capacitor (+) AND Pin A0 (Sense Pin)

Capacitor (-) → GND

Generated ascii
+5V (from Arduino Pin 8 when HIGH)
                │
              ┌─┴─┐
              │1kΩ│  (R_known)
              └─┬─┘
                │
       ┌────────┼────────┐
       │        │        │
       │        │        └─────────> Arduino Pin A0 (Analog Sense)
       │        │
      -┥ C?     │
   (Capacitor)  │
       │        │
      GND      GND

🔧 Setup Instructions

Assemble Circuit: Place components on the breadboard as per the diagram.

Connect Arduino: Plug your Arduino into your computer via USB.

Open Arduino IDE: Launch the IDE and paste in the code.

Upload Sketch: Select your board/port and upload the code.

Open Serial Monitor: Go to Tools -> Serial Monitor (or Ctrl+Shift+M) and set the baud rate to 9600.

💻 Arduino Code
Generated cpp
/*
 * 💡 Arduino Capacitance Meter
 * Measures capacitance by timing the charge of an RC circuit.
 */

// Define the pins used
const int chargePin = 8;
const int sensePin = A0;

// The known resistance value in Ohms.
const float R_known = 1000.0;

// The analog threshold representing 63.2% of 5V (0.632 * 1023 ≈ 647).
const int analogThreshold = 647;

void setup() {
  Serial.begin(9600);
  Serial.println("--- Capacitance Meter ---");
  pinMode(chargePin, OUTPUT);
  digitalWrite(chargePin, LOW);
}

void loop() {
  // 1. Discharge the capacitor
  digitalWrite(chargePin, LOW);
  delay(50);

  // 2. Start charging and timing
  long startTime = micros();
  digitalWrite(chargePin, HIGH);

  // 3. Wait for the capacitor to reach the threshold voltage
  while (analogRead(sensePin) < analogThreshold) { }
  long elapsedTime = micros() - startTime;

  // 4. Calculate capacitance (T in microseconds / R in Ohms = C in microFarads)
  float capacitance_uF = (float)elapsedTime / R_known;

  // 5. Display results
  Serial.print("Elapsed Time: ");
  Serial.print(elapsedTime);
  Serial.println(" us");

  if (capacitance_uF < 1) {
    Serial.print("Capacitance: ");
    Serial.print(capacitance_uF * 1000.0, 2); // Show 2 decimal places for nF
    Serial.println(" nF");
  } else {
    Serial.print("Capacitance: ");
    Serial.print(capacitance_uF, 2); // Show 2 decimal places for uF
    Serial.println(" uF");
  }

  Serial.println("-------------------------");
  delay(2000); 
}
IGNORE_WHEN_COPYING_START
content_copy
download
Use code with caution.
C++
IGNORE_WHEN_COPYING_END
▶️ How to Use

After uploading the code, insert the capacitor you want to measure into the circuit.

Open the Serial Monitor.

The measured capacitance value will be displayed every 2 seconds.

⚠️ Accuracy and Limitations

Component Tolerance: Accuracy is tied to the resistor's precision.

Stray Capacitance: The breadboard and wires introduce a small error (~20-50 pF), affecting measurements of very small capacitors.

Measurement Range: Best for capacitors from ~1nF to 1000µF.

📜 License

This project is licensed under the MIT License.

🎨 Colorful Readme for: Arduino Piano
🎹 Arduino Piano

![alt text](https://img.shields.io/badge/Arduino-00979D?style=for-the-badge&logo=Arduino&logoColor=white)


![alt text](https://img.shields.io/badge/Platform-Uno%20%7C%20Nano%20%7C%20Mega-blue?style=for-the-badge)


![alt text](https://img.shields.io/badge/License-MIT-green?style=for-the-badge)

A fun, simple electronic piano built with an Arduino, push buttons, and a piezo buzzer. Press each button to play a different musical note! 🎵

📋 Table of Contents

🤔 How It Works

🛒 Required Components

🔌 Circuit Diagram

🔧 Setup Instructions

💻 Arduino Code

🎶 How to Play

✨ Customization

📜 License

🤔 How It Works

The magic lies in detecting button presses and generating sound.

Input Detection: The Arduino monitors 8 digital pins for a HIGH signal.

Pull-Down Resistors: A 10kΩ resistor connects each button pin to Ground (GND).

This ensures the pin reads a stable LOW when a button is not pressed, preventing false "floating" signals.

Button Press: Pressing a button connects its pin to 5V, causing the Arduino to read it as HIGH.

Tone Generation: The code maps each button to a musical note frequency. When a button is pressed, the tone() function creates a sound wave on the buzzer's pin.

🛒 Required Components

1️⃣ x Arduino Board (e.g., Uno, Nano)

8️⃣ x Push buttons

1️⃣ x Piezo Buzzer

8️⃣ x 10kΩ Resistors (for pull-down)

1️⃣ x Breadboard

➖ Jumper Wires

🔌 Circuit Diagram

Connect the buzzer and one button as shown. Repeat the button circuit for all 8 buttons, connecting each to its own digital pin (2 through 9).

Buzzer: (+) leg to Pin 12, (-) leg to GND.

Button: One leg to 5V. The opposite leg connects to a digital pin (e.g., Pin 2) AND a 10kΩ resistor. The other end of the resistor goes to GND.

Generated ascii
Arduino                       Breadboard
             +-------+
             |       |
 5V O--------|-------+----------------( + rail )
GND O--------|-------+----------------( - rail )
             |       |
PIN 12 O-----|-------+-----------> Piezo (+) -> Piezo (-) -> ( - rail )
             |       |
             |       |                           10kΩ
PIN 2 O------|-------+----O----------.------------/\/\/\--------.
                          |      Push Button                  GND rail
                          |          |                         |
                          '----------'-------------------------'
                                     |
                                   5V rail
-- Repeat button circuit for Pins 3, 4, 5, 6, 7, 8, 9 --
IGNORE_WHEN_COPYING_START
content_copy
download
Use code with caution.
Ascii
IGNORE_WHEN_COPYING_END
🔧 Setup Instructions

Assemble Circuit: Build the circuit on the breadboard.

Connect Arduino: Plug your Arduino into your computer.

Open Arduino IDE: Launch the IDE and paste the code below.

Upload Sketch: Select your board/port from the Tools menu and upload.

💻 Arduino Code
Generated cpp
/*
 * 🎹 Arduino Piano
 * Plays a C Major scale using 8 push buttons and a piezo buzzer.
 */

// Define the output pin for the buzzer
const int buzzerPin = 12;

// Array of pins for the 8 buttons
const int buttonPins[] = {2, 3, 4, 5, 6, 7, 8, 9};
const int numButtons = 8
IGNORE_WHEN_COPYING_START
content_copy
download
Use code with caution.
C++
