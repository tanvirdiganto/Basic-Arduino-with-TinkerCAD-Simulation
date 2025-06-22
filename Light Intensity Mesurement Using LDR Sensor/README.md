# Arduino LDR Light Intensity Meter

![Arduino](https://img.shields.io/badge/Arduino-00979D?style=for-the-badge&logo=arduino&logoColor=white) ![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white) ![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)

> A simple Arduino project to measure ambient light levels using an LDR (Light Dependent Resistor) and control an LED's brightness accordingly.

<br>

*(A GIF or photo of your working project would be a great addition here!)*

## 📜 Description

This project demonstrates how to use a Light Dependent Resistor (LDR) to measure the intensity of light in the surrounding environment. An LDR is a special type of resistor whose resistance decreases as the intensity of light falling on it increases.

By creating a voltage divider circuit with the LDR and a fixed resistor, we can read the changing voltage levels using one of the Arduino's analog pins. This reading is then used for two purposes:
1.  Displaying the raw light intensity value on the Serial Monitor.
2.  Controlling the brightness of an LED in real-time—brighter light on the sensor results in a brighter LED, and darkness makes the LED dim.

This is a fundamental concept used in many real-world applications like automatic streetlights, smartphone auto-brightness, and camera exposure controls.

## 🛠️ Hardware & Software Requirements

### Hardware
*   **Arduino Uno** (or any other Arduino-compatible board)
*   **LDR Sensor** (Light Dependent Resistor)
*   **10kΩ Resistor** (for the voltage divider)
*   **220Ω Resistor** (to limit current for the LED)
*   **LED** (any color, 5mm)
*   **Breadboard**
*   **Jumper Wires**

### Software
*   [**Arduino IDE**](https://www.arduino.cc/en/software)

## 🔌 Hardware Setup & Wiring

The core of this circuit is a **voltage divider**, which allows the Arduino to read the LDR's changing resistance as a change in voltage.

1.  Place the LDR and LED on the breadboard.
2.  Connect the components according to the pinout table below:

| Component Pin        | Connection Point                      | Purpose                                 |
| :------------------- | :------------------------------------ | :-------------------------------------- |
| **5V Pin (Arduino)** | One leg of the **10kΩ Resistor**      | Power source for the voltage divider    |
| **GND Pin (Arduino)**| One leg of the **LDR**                | Ground connection for the LDR           |
| **A0 Pin (Arduino)** | Between 10kΩ Resistor and LDR         | Reads the analog voltage from the middle|
| **Pin ~9 (Arduino)** | **220Ω Resistor** -> **LED Anode (+)** | Controls LED brightness via PWM         |
| **GND Pin (Arduino)**| **LED Cathode (-)**                   | Ground connection for the LED           |

### Wiring Diagram
*(A Fritzing diagram provides excellent visual guidance for learners.)*
![Wiring Diagram](https://fritzing.org/media/fritzing-repo/projects/a/arduino-ldr-led/images/arduino_ldr_led_bb.png)
*Credit: This is a standard Fritzing diagram illustrating the setup.*

## 🚀 Getting Started

Follow these steps to get the project up and running.

1.  **Clone the Repository**
    ```bash
    git clone https://github.com/your_username/your_repository.git
    ```
2.  **Assemble the Circuit**
    Wire up your components on the breadboard as shown in the [wiring diagram](#-hardware-setup--wiring).

3.  **Setup Arduino IDE**
    *   Connect your Arduino to your computer via USB.
    *   Open the Arduino IDE and select your Board (**Tools > Board**) and Port (**Tools > Port**).

4.  **Upload the Code**
    *   Open the `.ino` file from this repository.
    *   Click the **Upload** button (the right-pointing arrow) to send the sketch to your Arduino.

## 📈 Usage and Testing

Once the sketch is uploaded, the sensor is active.

1.  **Monitor the Light Level:**
    *   Open the **Serial Monitor** (**Tools > Serial Monitor**).
    *   Make sure the baud rate is set to **9600**.
    *   You will see the raw sensor values printed.

2.  **Test the Response:**
    *   **Cover the LDR** with your hand. You should see the sensor values in the Serial Monitor increase and the LED become very dim or turn off.
    *   **Shine a bright light** (like your phone's flashlight) onto the LDR. The sensor values should drop significantly, and the LED will become much brighter.

## 🧠 How It Works

1.  **The LDR and Voltage Divider:**
    The LDR's resistance changes with light. We've placed it in a voltage divider circuit with a fixed 10kΩ resistor. The formula for the voltage at Pin A0 is:
    `Voltage_A0 = 5V * (R_LDR / (R_10k + R_LDR))`
    *   In **darkness**, the LDR's resistance (`R_LDR`) is very high, so the voltage at A0 will be high (closer to 5V).
    *   In **bright light**, the LDR's resistance is very low, so the voltage at A0 will be low (closer to 0V).

2.  **Analog Reading:**
    The `analogRead(A0)` function reads this voltage and converts it into an integer value between **0** (for 0V) and **1023** (for 5V). So, we get low values for bright light and high values for darkness.

3.  **Mapping Values for the LED:**
    The `analogWrite()` function, used to control LED brightness, accepts a value from **0** (off) to **255** (full brightness). To make the LED brighter in bright light, we need to **invert and scale** the LDR reading.
    The `map()` function is perfect for this: `map(ldrValue, LDR_LOW, LDR_HIGH, 255, 0);`
    *   This maps low `ldrValue` readings (bright light) to high brightness values (255).
    *   It maps high `ldrValue` readings (darkness) to low brightness values (0).

4.  **PWM Output:**
    The Arduino uses **Pulse Width Modulation (PWM)** on pin ~9 to simulate an analog voltage, which effectively controls how bright the LED appears.

## 🤝 Contributing

Contributions are always welcome! Feel free to fork this repository, make your improvements, and submit a pull request.

## 📜 License

This project is licensed under the MIT License - see the `LICENSE` file for details.

## 🙏 Acknowledgements

*   [Arduino Community](https://www.arduino.cc/) for creating an accessible platform for electronics.
*   [Fritzing](https://fritzing.org/) for the fantastic circuit diagramming tool.
