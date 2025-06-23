
Arduino Capacitance Meter

A simple yet effective project to measure the capacitance of capacitors using an Arduino board, a known resistor, and the principle of an RC (Resistor-Capacitor) charging circuit.

<!-- You can replace this with your own GIF or image -->

Table of Contents

How It Works

Required Components

Circuit Diagram

Setup Instructions

Arduino Code

How to Use

Accuracy and Limitations

License

How It Works

This project leverages the fundamental property of a Resistor-Capacitor (RC) circuit: the time it takes to charge a capacitor. This time is defined by the time constant, represented by the Greek letter tau (τ).

τ = R × C

Where:

τ is the time constant in seconds.

R is the resistance in Ohms.

C is the capacitance in Farads.

The time constant represents the time it takes for the capacitor's voltage to reach approximately 63.2% of the charging voltage.

The Arduino facilitates this process by:

Discharging the capacitor: Ensuring it starts at 0 volts.

Charging the capacitor: Applying 5V through a digital output pin connected to the RC circuit.

Timing: Using its internal clock (micros()), the Arduino measures the time it takes for the voltage across the capacitor to reach 63.2% of 5V.

Reading the Voltage: An analog input pin continuously monitors the capacitor's voltage. Since the Arduino's ADC (Analog-to-Digital Converter) maps 0-5V to a 0-1023 range, the 63.2% threshold corresponds to an analog reading of 1023 * 0.632 ≈ 647.

Calculating Capacitance: Once the time (T) and the known resistance (R) are known, the Arduino rearranges the time constant formula to calculate the unknown capacitance (C).

C = T / R

The result is then displayed on the Serial Monitor.

Required Components

1 x Arduino Board (e.g., Uno, Nano, Mega)

1 x 1kΩ Resistor (a resistor with 1% tolerance is recommended for better accuracy)

1 x Capacitor to be measured (works well for values from ~1nF to 1000µF)

1 x Breadboard

Jumper Wires

Circuit Diagram

Connect the components as shown in the diagram below.

Pin 8 (Charge Pin): This pin will be used to charge and discharge the capacitor. It connects to one end of the 1kΩ resistor.

Pin A0 (Sense Pin): This analog pin reads the voltage across the capacitor. It connects to the junction between the resistor and the capacitor.

GND: The ground pin connects to the other leg of the capacitor.

Generated ascii
+5V (from Arduino Pin 8 when HIGH)
                │
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
   (Capacitor   │
 to be measured)│
       │        │
      GND      GND

Setup Instructions

Gather Components: Collect all the required parts listed above.

Assemble the Circuit: Place the components on the breadboard and connect them according to the circuit diagram.

Connect Arduino: Connect your Arduino board to your computer via USB.

Open Arduino IDE: Launch the Arduino IDE on your computer.

Copy the Code: Copy the code from the Arduino Code section below and paste it into a new sketch.

Upload the Sketch: Select your board and port from the Tools menu and click the upload button.

Open Serial Monitor: Once the upload is complete, open the Serial Monitor (Tools -> Serial Monitor or Ctrl+Shift+M) and set the baud rate to 9600.

Arduino Code
Generated cpp
/*
 * Capacitance Meter
 * 
 * Measures the capacitance of a capacitor by timing how long it takes to charge
 * through a known resistor in an RC circuit.
 * 
 * Circuit:
 * - Digital Pin 8 (chargePin) -> 1k Ohm Resistor
 * - 1k Ohm Resistor -> Capacitor (+) and Analog Pin A0 (sensePin)
 * - Capacitor (-) -> GND
 * - Arduino GND -> Circuit GND
 */

// Define the pins used
const int chargePin = 8;
const int sensePin = A0;

// The known resistance value in Ohms.
// For higher accuracy, measure your resistor with a multimeter and update this value.
const float R_known = 1000.0;

// The analog threshold that represents 63.2% of the charging voltage (5V).
// (5V / 1023) * x = 0.632 * 5V => x = 0.632 * 1023 = 646.7
const int analogThreshold = 647;

void setup() {
  // Initialize Serial communication at 9600 bps
  Serial.begin(9600);
  Serial.println("Capacitance Meter");
  Serial.println("-----------------");

  // Set the charge pin as an output to control charging/discharging
  pinMode(chargePin, OUTPUT);
  digitalWrite(chargePin, LOW); // Start with the pin LOW to keep capacitor discharged
}

void loop() {
  // --- Step 1: Discharge the capacitor fully ---
  // Ensure the capacitor is discharged by holding the charge pin LOW
  digitalWrite(chargePin, LOW);
  delay(50); // Wait for a moment to ensure it's fully discharged

  // --- Step 2: Start charging and timing ---
  // Start timing using the Arduino's micros() function for high resolution
  long startTime = micros();

  // Set the charge pin HIGH to start charging the capacitor through the resistor
  digitalWrite(chargePin, HIGH);

  // --- Step 3: Wait until the capacitor reaches the 63.2% voltage threshold ---
  // The loop will break once the analog read value exceeds the threshold
  while (analogRead(sensePin) < analogThreshold) {
    // Do nothing but wait
  }

  // --- Step 4: Calculate the elapsed time ---
  long elapsedTime = micros() - startTime;

  // --- Step 5: Calculate the capacitance ---
  // Formula: C = T / R
  // T is time in microseconds (elapsedTime)
  // R is resistance in Ohms (R_known)
  // Resulting capacitance will be in microFarads (uF) because (microseconds / Ohms) = microFarads.
  float capacitance_uF = (float)elapsedTime / R_known;

  // --- Step 6: Display the results ---
  Serial.print("Elapsed Time: ");
  Serial.print(elapsedTime);
  Serial.println(" µs");

  // Display capacitance in different units for convenience
  if (capacitance_uF < 1) {
    // If less than 1 uF, show in nanoFarads (nF)
    Serial.print("Capacitance: ");
    Serial.print(capacitance_uF * 1000.0);
    Serial.println(" nF");
  } else {
    // Otherwise, show in microFarads (uF)
    Serial.print("Capacitance: ");
    Serial.print(capacitance_uF);
    Serial.println(" µF");
  }

  Serial.println("-----------------");
  
  // Wait before the next measurement cycle
  delay(2000); 
}
IGNORE_WHEN_COPYING_START
content_copy
download
Use code with caution.
C++
IGNORE_WHEN_COPYING_END
How to Use

After uploading the code and opening the Serial Monitor, insert the capacitor you wish to measure into the breadboard circuit.

The Arduino will automatically begin the measurement process.

The results, including the elapsed charging time and the calculated capacitance (in nF or µF), will be printed to the Serial Monitor every 2 seconds.

Accuracy and Limitations

This method provides a good estimation but has some limitations:

Component Tolerance: The accuracy of the measurement is highly dependent on the tolerance of the known resistor. A 1% tolerance resistor is recommended.

Arduino Clock: The precision of the micros() function can affect timing, though it is generally very reliable.

ADC Speed: The analogRead() function takes about 100 microseconds, which can introduce a small error, especially when measuring small capacitors that charge very quickly.

Stray Capacitance: The breadboard, jumper wires, and the Arduino pins themselves have a small amount of stray capacitance, which can affect the readings for very small capacitors (in the pF range). The setup will likely report a small non-zero capacitance even with no capacitor connected.

Measurement Range: This setup works best for capacitors in the range of approximately 1 nF to 1000 µF.

Below 1nF: The charging time is too fast to be accurately measured.

Above 1000µF: The charging time may become very long.

License

This project is open-source and available under the MIT License. See the LICENSE file for more details.
