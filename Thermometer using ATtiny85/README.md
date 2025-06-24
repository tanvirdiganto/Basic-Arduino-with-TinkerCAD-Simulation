# 🌡️ ATtiny85 Thermometer Project

  <!-- Replace with a GIF of your own project! -->

A simple, low-cost, and fun-to-build thermometer using the ATtiny85 microcontroller. The project reads the ambient temperature from an LM35 sensor and provides visual feedback by blinking an LED. The warmer it gets, the faster the LED blinks!

[![Microcontroller](https://img.shields.io/badge/Microcontroller-ATtiny85-orange.svg)](https://www.microchip.com/wwwproducts/en/ATtiny85)
[![Sensor](https://img.shields.io/badge/Sensor-LM35-red.svg)](https://www.ti.com/lit/ds/symlink/lm35.pdf)
[![Language](https://img.shields.io/badge/Language-Arduino%20(C++)-0078D4.svg)](https://www.arduino.cc/)
[![License](https://img.shields.io/badge/License-MIT-green.svg)](https://opensource.org/licenses/MIT)

---

## ✨ Features

-   **Minimalist Design:** Built with very few components.
-   **Low Power:** The ATtiny85 is perfect for low-power applications.
-   **Visual Feedback:** No need for an LCD screen; an LED's blink rate indicates the temperature.
-   **Analog Sensing:** Uses the popular and easy-to-use LM35 analog temperature sensor.
-   **Great for Beginners:** An excellent introduction to programming standalone microcontrollers.

---

## 🛠️ Components Required

| Component | Quantity | Notes |
| :--- | :---: | :--- |
| **ATtiny85 Microcontroller** | 1 | The brain of the project. |
| **LM35 Temperature Sensor** | 1 | Or another compatible analog sensor. |
| **LED (any color)** | 1 | For visual feedback. |
| **220Ω Resistor** | 1 | Current-limiting resistor for the LED. |
| **Breadboard** | 1 | For prototyping the circuit. |
| **Jumper Wires** | Several | To connect everything. |
| **USBasp Programmer** | 1 | Or similar ICSP programmer. |

---

## 🔌 Circuit Diagram & Wiring

Here is how you connect the components. The ATtiny85 pinout is shown below for reference.



### Wiring Instructions:

| From | To |
| :--- | :--- |
| **ATtiny85 VCC (Pin 8)** | `+` Rail (5V) |
| **ATtiny85 GND (Pin 4)** | `-` Rail (GND) |
| **LM35 VCC (Pin 1)** | `+` Rail (5V) |
| **LM35 GND (Pin 3)** | `-` Rail (GND) |
| **LM35 Vout (Pin 2)** | **ATtiny85 Pin 3 (PB4/ADC2)** |
| **LED Anode (+)** | One end of the 220Ω Resistor |
| Other end of Resistor | **ATtiny85 Pin 6 (PB1)** |
| **LED Cathode (-)** | `-` Rail (GND) |

### Breadboard Layout:

 <!-- Replace with a photo of your own circuit! -->

---

## ⚙️ Setup & Installation

To upload the code to the ATtiny85, you'll need to configure your Arduino IDE and use an external programmer like a USBasp.

### 1. Configure Arduino IDE for ATtiny85

-   Open Arduino IDE and go to `File > Preferences`.
-   In the "Additional Boards Manager URLs" field, add the following URL:
    ```
    http://drazzy.com/package_drazzy.com_index.json
    ```
-   Go to `Tools > Board > Boards Manager...`.
-   Search for "attinycore" and install the one by Spence Konde.
-   Once installed, close the Boards Manager.

### 2. Connect the USBasp Programmer

Connect your USBasp to the ATtiny85 on the breadboard using the ICSP (In-Circuit Serial Programming) pins.

| USBasp Pin | ATtiny85 Pin |
| :--- | :--- |
| **VCC** | Pin 8 (VCC) |
| **GND** | Pin 4 (GND) |
| **MOSI** | Pin 5 (PB0) |
| **MISO** | Pin 6 (PB1) |
| **SCK** | Pin 7 (PB2) |
| **RESET** | Pin 1 (PB5) |

### 3. Upload the Code

-   Open the `attiny85_thermometer.ino` file in the Arduino IDE.
-   Go to `Tools` and select the following settings:
    -   **Board:** "ATtiny25/45/85"
    -   **Processor:** "ATtiny85"
    -   **Clock:** "8 MHz (internal)"
    -   **Programmer:** "USBasp"
-   First, burn the bootloader to set the fuses correctly. Go to `Tools > Burn Bootloader`. (You only need to do this once for a new chip).
-   Finally, upload the sketch by clicking the **Upload** button or going to `Sketch > Upload Using Programmer`.

---

## 💻 The Code

The code is simple. It reads the analog voltage from the LM35, converts it to Celsius, and then maps that temperature to a blink delay for the LED.

```cpp
// Define the pins we are using
const int SENSOR_PIN = A2; // ATtiny85 Pin 3 (PB4)
const int LED_PIN = 1;      // ATtiny85 Pin 6 (PB1)

// Temperature range for mapping the blink delay (in Celsius)
const int TEMP_MIN = 20; // At this temp, blink is slowest
const int TEMP_MAX = 35; // At this temp, blink is fastest

// Blink delay range (in milliseconds)
const int DELAY_MAX = 1000; // Slowest blink (1 second)
const int DELAY_MIN = 100;  // Fastest blink (0.1 seconds)

void setup() {
  // Set the LED pin as an output
  pinMode(LED_PIN, OUTPUT);
  
  // Use the internal 1.1V reference for more stable ADC readings
  analogReference(INTERNAL);
}

void loop() {
  // 1. Read the raw analog value from the sensor
  int sensorValue = analogRead(SENSOR_PIN);
  
  // 2. Convert the analog value to voltage.
  // The ADC is 10-bit (0-1023) and we are using the 1.1V internal reference.
  float voltage = (sensorValue / 1023.0) * 1.1;

  // 3. Convert voltage to temperature in Celsius.
  // The LM35 has a scale factor of 10mV/°C.
  // Temperature = (Voltage in mV) / 10
  float temperatureC = (voltage * 1000) / 10;
  
  // 4. Map the temperature to a blink delay.
  // The map() function translates one range of numbers to another.
  long blinkDelay = map(temperatureC, TEMP_MIN, TEMP_MAX, DELAY_MAX, DELAY_MIN);
  
  // 5. Constrain the delay to our defined min/max to avoid weird values
  blinkDelay = constrain(blinkDelay, DELAY_MIN, DELAY_MAX);

  // 6. Blink the LED with the calculated delay
  digitalWrite(LED_PIN, HIGH);
  delay(blinkDelay);
  digitalWrite(LED_PIN, LOW);
  delay(blinkDelay);
}
```

---

## 📈 How It Works

1.  **Power On**: The ATtiny85 and LM35 are powered up.
2.  **Sensing**: The LM35 sensor outputs a voltage that is directly proportional to the temperature in Celsius (10mV per °C).
3.  **Reading**: The ATtiny85's Analog-to-Digital Converter (ADC) reads this voltage on pin `A2`. We use the stable internal 1.1V reference for an accurate reading.
4.  **Calculation**: The code converts the raw ADC value (0-1023) back into a voltage, and then into a temperature value in Celsius.
5.  **Mapping**: This temperature value is then mapped to a `delay` value. A lower temperature (e.g., 20°C) results in a long delay (e.g., 1000ms), while a higher temperature (e.g., 35°C) results in a short delay (e.g., 100ms).
6.  **Blinking**: The LED is flashed on and off using this calculated delay, giving a clear visual representation of the current temperature.

---

## 🖼️ Project Gallery

*(Add your own photos here!)*

| Breadboard Setup | Final Circuit | In Action! |
| :---: | :---: | :---: |
| ![Your Breadboard](https://via.placeholder.com/300x300.png?text=Your+Breadboard) | ![Your Circuit](https://via.placeholder.com/300x300.png?text=Your+Circuit) | ![Demo GIF](https://via.placeholder.com/300x300.png?text=Project+GIF) |


---

## 🤝 Contributing

Contributions, issues, and feature requests are welcome! Feel free to check the [issues page](https://github.com/YOUR_USERNAME/YOUR_REPOSITORY/issues).

## 📜 License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details.
```
