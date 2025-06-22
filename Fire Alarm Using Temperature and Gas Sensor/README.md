# Arduino Fire & Gas Alarm System

![Arduino](https://img.shields.io/badge/Arduino-00979D?style=for-the-badge&logo=arduino&logoColor=white) ![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white) ![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)

> An Arduino-based safety system that detects high temperatures and gas leaks, triggering distinct visual and audible alarms to ensure a quick response.

<br>

*(A photo of your completed project breadboard would be perfect here!)*

## 📜 Description

This project is a multi-sensor safety device designed to provide early warnings for two common household dangers: fire and gas leaks. It continuously monitors the environment using a temperature sensor (like the LM35) and a gas sensor (like the MQ-2).

- If the ambient temperature rises above a predefined threshold (indicating a potential fire), a bright **red LED** will turn on.
- If the concentration of combustible gas or smoke exceeds a safe level, a **loud buzzer** will sound.

This setup is ideal for students, hobbyists, and anyone interested in building practical, life-saving electronic circuits. It serves as a great foundation for more advanced smart home and IoT safety systems.

## 🛠️ Hardware & Software Requirements

### Hardware
*   **Arduino Uno** (or any other Arduino-compatible board)
*   **Temperature Sensor:** **LM35** (Analog Temperature Sensor)
*   **Gas Sensor:** **MQ-2** (Smoke, LPG, Butane, Hydrogen Gas Sensor)
*   **LED:** 1x Red (5mm)
*   **Resistor:** 1x 220Ω (for the LED)
*   **Buzzer:** 1x Active or Passive Piezo Buzzer
*   **Breadboard**
*   **Jumper Wires**

### Software
*   [**Arduino IDE**](https://www.arduino.cc/en/software)

## 🔌 Hardware Setup & Wiring

Carefully connect the components to the Arduino as shown in the pinout table below. It's recommended to build the circuit with the Arduino powered off.

| Component Pin       | Arduino Pin | Connection / Notes                          |
| :------------------ | :---------- | :------------------------------------------ |
| **MQ-2 Sensor VCC**   | **5V**      | Power for Gas Sensor                        |
| **MQ-2 Sensor GND**   | **GND**     | Ground for Gas Sensor                       |
| **MQ-2 Sensor A0**    | **A0**      | Analog Output to Arduino Analog Pin 0     |
| **LM35 Sensor Vs**    | **5V**      | Power for Temperature Sensor                |
| **LM35 Sensor GND**   | **GND**     | Ground for Temperature Sensor               |
| **LM35 Sensor Vout**  | **A1**      | Analog Output to Arduino Analog Pin 1     |
| **LED Anode (+)**     | **Pin 7**   | Via 220Ω Resistor                           |
| **LED Cathode (-)**   | **GND**     | Ground for LED                              |
| **Buzzer (+)**        | **Pin 8**   | Signal for Buzzer                           |
| **Buzzer (-)**        | **GND**     | Ground for Buzzer                           |

### Wiring Diagram
*(A Fritzing diagram is highly recommended for clarity. You can create one or use a placeholder.)*
![Wiring Diagram Placeholder](https://user-images.githubusercontent.com/11261624/151048483-37637841-d557-41a4-a953-dce3f6d7e0d3.png)
*This is an example image. Be sure to match the pin connections described above.*

> **❗ Important Note on the MQ-2 Sensor:** Gas sensors like the MQ-2 require a "pre-heat" or "burn-in" time to give stable readings. When you first power it on, allow it to run for several minutes to warm up before you rely on its measurements.

## 🚀 Getting Started

Follow these instructions to get the project running.

1.  **Clone the Repository**
    ```bash
    git clone https://github.com/your_username/your_repository.git
    ```
2.  **Assemble the Circuit**
    Wire up your components on the breadboard as detailed in the [wiring section](#-hardware-setup--wiring) above.

3.  **Setup Arduino IDE**
    *   Connect your Arduino board to your computer.
    *   Open the Arduino IDE.
    *   Select your Board (**Tools > Board > Arduino Uno**).
    *   Select your Port (**Tools > Port > COM...**).

4.  **Upload the Code**
    *   Open the `.ino` file from this repository.
    *   Verify the code by clicking the checkmark icon.
    *   Upload the code to your Arduino by clicking the arrow icon.

## 📈 Usage and Testing

Once the sketch is uploaded, the system is active.

1.  **Monitor Sensor Values:**
    *   Open the **Serial Monitor** (**Tools > Serial Monitor**).
    *   Set the baud rate to **9600**.
    *   You will see the real-time sensor readings for temperature and gas concentration.

2.  **Test the Alarms:**
    *   **Fire Alarm (LED):** Gently warm the LM35 sensor with your fingers or a covered heat source (do not use an open flame). When the temperature crosses the defined threshold in the code, the red LED will light up.
    *   **Gas Alarm (Buzzer):** Use a gas lighter (release the gas **without igniting the flame**) or a puff of smoke near the MQ-2 sensor. When the sensor detects a high concentration of gas/smoke, the buzzer will sound.

## 🧠 Code Logic Explained

The `loop()` function in the Arduino sketch performs the following steps continuously:

1.  **Read Sensors:**
    *   It reads the raw analog value from the MQ-2 Gas Sensor connected to pin `A0`.
    *   It reads the raw analog value from the LM35 Temperature Sensor on pin `A1` and converts it into Degrees Celsius.

2.  **Check Thresholds:**
    *   `if (temperatureC > FIRE_THRESHOLD)`: The code compares the current temperature against a pre-set `FIRE_THRESHOLD` (e.g., 50°C). If it's higher, it activates the fire alarm.
    *   `if (gasValue > GAS_THRESHOLD)`: The code compares the raw gas sensor reading against a `GAS_THRESHOLD` (e.g., 400). If it's higher, it triggers the gas leak alarm.

3.  **Control Actuators:**
    *   If the fire condition is met, it sends a `HIGH` signal to the LED pin (`Pin 7`) to turn it on. Otherwise, it sends a `LOW` signal.
    *   If the gas condition is met, it sends a `HIGH` signal (or a tone) to the Buzzer pin (`Pin 8`) to make it sound. Otherwise, it sends a `LOW` signal to keep it silent.

4.  **Serial Output:**
    *   It prints the current status and sensor readings to the Serial Monitor for debugging and real-time monitoring.

## 🤝 Contributing

Contributions are what make the open-source community such an amazing place to learn, inspire, and create. Any contributions you make are **greatly appreciated**. Fork the repo and create a pull request.

## 📜 License

Distributed under the MIT License. See `LICENSE` file for more information.

## 🙏 Acknowledgements

*   The [Arduino Community](https://www.arduino.cc/)
*   The creators of the MQ-series sensors and LM35
