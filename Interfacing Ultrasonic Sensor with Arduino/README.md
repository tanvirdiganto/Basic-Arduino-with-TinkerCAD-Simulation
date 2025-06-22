# Arduino HC-SR04 Ultrasonic Sensor Project

![Arduino](https://img.shields.io/badge/Arduino-00979D?style=for-the-badge&logo=arduino&logoColor=white) ![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white) ![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)

A simple and well-commented project to measure distance using an HC-SR04 ultrasonic sensor and an Arduino board. The distance is then displayed on the Serial Monitor.


*(Replace the image link above with a photo of your actual project!)*

## 📜 Description

This project serves as a great introduction to interfacing sensors with microcontrollers. An ultrasonic sensor measures distance by sending out a sound wave at a specific frequency and listening for that sound wave to bounce back. By recording the time between the sound wave being generated and the sound wave bouncing back, it is possible to calculate the distance to an object.

This code provides a straightforward way to read data from the sensor and display it, making it an excellent starting point for more complex projects like a robotics collision avoidance system, a parking assistant, or a water level monitor.

## 🛠️ Hardware & Software Requirements

### Hardware
*   **Arduino Uno** (or any other Arduino-compatible board)
*   **HC-SR04 Ultrasonic Sensor**
*   **Breadboard**
*   **Jumper Wires** (at least 4)
*   **Arduino USB Cable**

### Software
*   [**Arduino IDE**](https://www.arduino.cc/en/software)

## 🔌 Hardware Setup & Wiring

Follow these steps to connect the HC-SR04 sensor to your Arduino board.

1.  Place the HC-SR04 sensor on the breadboard.
2.  Connect the pins as follows:

| HC-SR04 Pin | Arduino Pin | Connection      |
| :---------- | :---------- | :-------------- |
| **VCC**     | **5V**      | Power           |
| **Trig**    | **Pin 9**   | Trigger Pulse   |
| **Echo**    | **Pin 10**  | Echo Listener   |
| **GND**     | **GND**     | Ground          |

### Wiring Diagram
(A Fritzing diagram is perfect for this section)
![Wiring Diagram](https://fritzing.org/media/fritzing-repo/projects/h/hc-sr04-ultrasound-range-finder/images/HC-SR04-Ultrasound-range-finder_bb.png)
*(Feel free to create your own Fritzing diagram or use this one)*

## 🚀 Getting Started

Follow these instructions to get the project running.

1.  **Clone the Repository**
    ```bash
    git clone https://github.com/your_username/your_repository.git
    ```
2.  **Connect Your Hardware**
    Wire up your components as shown in the [wiring diagram](#-hardware-setup--wiring) above.

3.  **Setup Arduino IDE**
    *   Connect your Arduino board to your computer via the USB cable.
    *   Open the Arduino IDE.
    *   Go to **Tools > Board** and select "Arduino Uno" (or your specific board).
    *   Go to **Tools > Port** and select the COM port your Arduino is connected to.

4.  **Upload the Code**
    *   Open the `.ino` file from this repository in the Arduino IDE.
    *   Click the **Upload** button (the right-pointing arrow icon) to upload the sketch to your Arduino.

## 📈 Usage

After successfully uploading the sketch:

1.  Open the **Serial Monitor** in the Arduino IDE (click the magnifying glass icon in the top-right corner or go to **Tools > Serial Monitor**).

2.  In the Serial Monitor window, make sure the baud rate is set to **9600 baud** (bottom-right dropdown).

3.  You should now see the distance readings from the sensor appearing every second. Place your hand or an object in front of the sensor to see the distance change!
4.  
## 🧠 How It Works

The principle of ultrasonic distance measurement is based on sound waves:
1.  The Arduino sends a short 10-microsecond pulse to the **`Trig`** (Trigger) pin on the HC-SR04 sensor.
2.  The sensor transmits a burst of 8 ultrasonic sound waves at 40 kHz.
3.  These sound waves travel through the air, hit an object, and bounce back to the sensor.
4.  The **`Echo`** pin on the sensor receives the reflected sound waves. Its output stays HIGH for the duration the sound wave was in the air.
5.  The Arduino measures this duration using the `pulseIn()` function.
6.  The distance is calculated using the formula:
    **Distance = (Duration of Echo Pulse * Speed of Sound) / 2**
    We divide by 2 because the duration measured is for the round trip (to the object and back).

## 🤝 Contributing

Contributions are what make the open-source community such an amazing place to learn, inspire, and create. Any contributions you make are **greatly appreciated**.

1.  Fork the Project
2.  Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3.  Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4.  Push to the Branch (`git push origin feature/AmazingFeature`)
5.  Open a Pull Request

## 📜 License

Distributed under the MIT License. See `LICENSE` file for more information.

## 🙏 Acknowledgements

*   The [Arduino Community](https://www.arduino.cc/) for their amazing platform and resources.
*   The creators of the [Fritzing](https://fritzing.org/) tool for making circuit diagrams accessible.
