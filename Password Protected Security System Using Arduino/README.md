# Arduino Password Protected Security System

![Arduino](https://img.shields.io/badge/Arduino-00979D?style=for-the-badge&logo=arduino&logoColor=white)
![Platform](https://img.shields.io/badge/Platform-Arduino%20Uno-blue?style=for-the-badge)

A simple yet effective security system built with an Arduino Uno, a 4x4 keypad, LEDs, and a piezo buzzer. Enter the correct password to grant access, or enter the wrong one to trigger an alarm. This project is a fantastic introduction to reading user input, managing states, and controlling multiple outputs with an Arduino.

![Project-Demo-Placeholder](https://user-images.githubusercontent.com/1018826/160359858-29b535f2-9844-4228-8687-17eb1268cb32.png)
*A GIF demonstrating the system in action would be perfect here! Show a failed attempt (red LED) followed by a successful one (green LED).*

## 📋 Features

-   **Password Entry:** Secure access using a 4x4 membrane keypad.
-   **Visual Feedback:**
    -   **Green LED:** Indicates "Access Granted" when the correct password is entered.
    -   **Red LED:** Indicates "Access Denied" for incorrect attempts.
-   **Audible Feedback:**
    -   A short beep for each key press.
    -   A happy tune for successful entry.
    -   An error buzz for failed attempts.
-   **Easy to Customize:** The password and pin configurations can be easily changed in the code.
-   **Reset Functionality:** Clear your current input with the '#' key.
-   **Auto-Reset:** The system automatically resets after a successful or failed attempt, ready for the next entry.

## 🛠️ Hardware Requirements

| Component | Quantity | Notes |
| :--- | :--- | :--- |
| Arduino Board | 1 | e.g., Arduino Uno, Nano |
| 4x4 Keypad | 1 | Standard membrane keypad |
| Green LED | 1 | 5mm or 3mm |
| Red LED | 1 | 5mm or 3mm |
| Piezo Buzzer | 1 | Active or passive |
| 220Ω Resistors | 2 | For current limiting the LEDs |
| Breadboard | 1 | Standard size |
| Jumper Wires | - | Assorted male-male wires |

## 🔌 Wiring Diagram

Assemble the circuit according to the connections below. The keypad pins are connected from left to right.

| Component | Arduino Pin |
| :--- | :--- |
| **4x4 Keypad** | |
| Row 1 | Digital Pin 9 |
| Row 2 | Digital Pin 8 |
| Row 3 | Digital Pin 7 |
| Row 4 | Digital Pin 6 |
| Column 1 | Digital Pin 5 |
| Column 2 | Digital Pin 4 |
| Column 3 | Digital Pin 3 |
| Column 4 | Digital Pin 2 |
| | |
| **Green LED (Anode)** | Digital Pin 11 |
| **Red LED (Anode)** | Digital Pin 10 |
| **Piezo Buzzer (+)** | Digital Pin 12 |

**Important Notes:**
-   Connect the **cathode** (shorter leg) of each LED to a **220Ω resistor**.
-   Connect the other end of the resistors to the **GND** rail on the breadboard.
-   Connect the negative lead of the piezo buzzer to **GND**.
-   Connect a jumper wire from the Arduino's **GND** pin to the GND rail on the breadboard.

![Schematic Placeholder](https://user-images.githubusercontent.com/1018826/160359864-1e8c15b1-4d51-460d-8551-a20d58a8a4f6.png)
*A Fritzing diagram or a clear photo of the wired breadboard would be a great addition here.*

## 💻 Software & Libraries

1.  **[Arduino IDE](https://www.arduino.cc/en/software):** You'll need the Arduino IDE to upload the code to your board.
2.  **`Keypad.h` Library:** This project relies on the Keypad library by Mark Stanley and Alexander Brevig. You can install it directly from the Arduino IDE:
    -   Go to `Sketch` > `Include Library` > `Manage Libraries...`
    -   Search for "**Keypad**".
    -   Find the one by **Mark Stanley, Alexander Brevig** and click `Install`.

## 🚀 Installation & Usage

1.  **Clone the Repository:**
    ```bash
    git clone https://github.com/your-username/arduino-password-security-system.git
    ```
2.  **Assemble the Hardware:** Build the circuit as described in the [Wiring Diagram](#-wiring-diagram) section.
3.  **Open the Code:** Open the `.ino` file from the repository in your Arduino IDE.
4.  **Configure Board & Port:**
    -   Connect your Arduino to your computer.
    -   In the IDE, go to `Tools` > `Board` and select your Arduino model (e.g., "Arduino Uno").
    -   Go to `Tools` > `Port` and select the COM port your Arduino is connected to.
5.  **Upload the Code:** Click the `Upload` button (the right-arrow icon) in the Arduino IDE.

### How to Use the System

-   **Enter Password:** Type your password using the keypad. Each keypress will generate a short beep.
-   **Submit:** Press the `*` key to submit the entered password.
-   **Clear Input:** If you make a mistake, press the `#` key to clear the current entry and start over.

## 🔧 Customization

It's easy to change the default settings. Open the `.ino` file and modify the following lines at the top of the script.

### Changing the Password

To change the master password, simply edit the `masterPassword` array. The default is `"1234"`.

```cpp
char masterPassword[5] = "1234"; // The master password
// Define the pins for LEDs and Buzzer
const int redLedPin = 10;
const int greenLedPin = 11;
const int buzzerPin = 12;

// Define the keypad connections
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad
// Define the pins for LEDs and Buzzer
const int redLedPin = 10;
const int greenLedPin = 11;
const int buzzerPin = 12;

// Define the keypad connections
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad
