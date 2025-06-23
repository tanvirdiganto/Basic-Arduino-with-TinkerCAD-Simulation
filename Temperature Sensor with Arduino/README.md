# Arduino Temperature Sensor with LM35

![Arduino](https://img.shields.io/badge/Arduino-00979D?style=for-the-badge&logo=arduino&logoColor=white)
![Platform](https://img.shields.io/badge/Platform-Arduino%20Uno-blue?style=for-the-badge)

A simple and straightforward project to measure ambient temperature using an Arduino and an LM35 analog temperature sensor. The temperature readings are sent to the computer and can be viewed using the Arduino IDE's Serial Monitor.

This project is an excellent starting point for anyone learning to work with analog sensors, data conversion, and real-time data monitoring.

![Project-Demo-Placeholder](https://user-images.githubusercontent.com/1018826/160359858-29b535f2-9844-4228-8687-17eb1268cb32.png)
*A picture of the circuit with the Serial Monitor showing temperature readings would be great here.*

## 📋 Features

-   **Real-time Temperature Reading:** Measures temperature using the LM35 sensor.
-   **Analog to Digital Conversion:** Demonstrates how the Arduino reads analog values.
-   **Data Conversion:** Includes the formulas to convert the sensor's voltage output to Celsius and Fahrenheit.
-   **Serial Monitoring:** Displays the final temperature readings on the Serial Monitor for easy viewing.
-   **Minimalist Setup:** Requires very few components and is easy to assemble.

## 🛠️ Hardware Requirements

| Component | Quantity | Notes |
| :--- | :--- | :--- |
| Arduino Board | 1 | e.g., Arduino Uno, Nano |
| Analog Temperature Sensor | 1 | LM35 (this guide uses LM35) |
| Breadboard | 1 | Standard size |
| Jumper Wires | 3+ | Male-male wires |

## 🔌 Wiring Diagram

The LM35 sensor has three pins. When looking at the **flat face** of the sensor, the pins are (from left to right):
1.  **VCC** (+5V)
2.  **Vout** (Analog Signal Output)
3.  **GND** (Ground)

Connect the components as follows:

| LM35 Pin | Arduino Pin |
| :--- | :--- |
| **Pin 1 (VCC)** | 5V |
| **Pin 2 (Vout)** | A0 (Analog In) |
| **Pin 3 (GND)** | GND |

![Schematic Placeholder](https://user-images.githubusercontent.com/1018826/160359864-1e8c15b1-4d51-460d-8551-a20d58a8a4f6.png)
*A Fritzing diagram or a clear photo of the wired breadboard is highly recommended here.*

## 💻 Software & Installation

1.  **[Arduino IDE](https://www.arduino.cc/en/software):** You'll need the Arduino IDE to upload the code.
2.  **No External Libraries:** This project uses only the built-in functions of the Arduino IDE.

## 🚀 Installation & Usage

1.  **Clone the Repository:**
    ```bash
    git clone https://github.com/your-username/arduino-temperature-sensor.git
    ```
2.  **Assemble the Hardware:** Build the circuit as described in the [Wiring Diagram](#-wiring-diagram) section.
3.  **Open and Upload:** Open the `.ino` file in the Arduino IDE and upload it to your board.
4.  **View the Readings:**
    -   Keep your Arduino connected to the computer.
    -   In the Arduino IDE, go to `Tools` > `Serial Monitor` (or click the magnifying glass icon in the top right).
    -   Make sure the baud rate in the Serial Monitor is set to **9600 baud**.
    -   You will now see the temperature readings printed in both Celsius and Fahrenheit.

## 🔬 How the Code Works

The logic behind converting the sensor's reading into a human-readable temperature is the core of this project.

1.  **Read the Analog Value:**
    The Arduino reads the voltage from the sensor's `Vout` pin. The `analogRead()` function maps the input voltage (0-5V) to a digital value between 0 and 1023.
    ```cpp
    int rawValue = analogRead(sensorPin); // Reads a value from 0-1023
    ```

2.  **Convert to Voltage:**
    We convert the digital value back into voltage. We use `5.0` and `1023.0` to ensure the calculation is done using floating-point math for better precision.
    ```cpp
    float voltage = (rawValue / 1023.0) * 5.0; // Converts the reading to voltage (0-5V)
    ```

3.  **Convert Voltage to Celsius:**
    The LM35 datasheet states that its output voltage is linearly proportional to the temperature in Celsius, with a scale factor of **10mV per °C**. To convert voltage to temperature, we simply multiply by 100.
    ```cpp
    float tempC = voltage * 100.0; // Converts voltage to degrees Celsius (10mV/°C)
    ```

4.  **Convert Celsius to Fahrenheit:**
    Finally, we use the standard formula to convert Celsius to Fahrenheit for display.
    ```cpp
    float tempF = (tempC * 9.0 / 5.0) + 32.0; // Converts Celsius to Fahrenheit
    ```

## 🤝 Contributing

Contributions, issues, and feature requests are welcome! Feel free to check the [issues page](https://github.com/your-username/arduino-temperature-sensor/issues).

1.  Fork the Project
2.  Create your Feature Branch (`git checkout -b feature/NewReading`)
3.  Commit your Changes (`git commit -m 'Add a new feature'`)
4.  Push to the Branch (`git push origin feature/NewReading`)
5.  Open a Pull Request

## 📄 License

This project is distributed under the MIT License. See `LICENSE` for more information.

---
**Happy Sensing!**
