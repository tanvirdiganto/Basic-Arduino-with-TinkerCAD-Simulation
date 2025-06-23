
# Controlling LEDs with an IR Remote and Arduino

![Arduino](https://img.shields.io/badge/Arduino-00979D?style=for-the-badge&logo=arduino&logoColor=white)
![Platform](https://img.shields.io/badge/Platform-Arduino%20Uno-blue?style=for-the-badge)

This project demonstrates how to decode signals from a standard IR remote control to toggle multiple LEDs connected to an Arduino. It's a fun and practical way to learn about IR communication, handling external libraries, and controlling digital outputs based on user input.

![Project-Demo-Placeholder](https://user-images.githubusercontent.com/1018826/160359858-29b535f2-9844-4228-8687-17eb1268cb32.png)
*A GIF showing the LEDs being toggled on and off with the remote would be perfect here!*

## 📋 Features

-   **IR Signal Decoding:** Captures and interprets signals from virtually any infrared remote control.
-   **Multi-LED Control:** Independently control three different LEDs.
-   **Customizable Button Mapping:** Easily assign any button on your remote to control a specific LED.
-   **State Toggling:** Press a button once to turn an LED on, and press it again to turn it off.
-   **Uses a popular and robust IR library** for reliable signal detection.

## 🛠️ Hardware Requirements

| Component | Quantity | Notes |
| :--- | :--- | :--- |
| Arduino Board | 1 | e.g., Arduino Uno, Nano |
| IR Remote Control | 1 | Almost any household remote will work |
| IR Receiver Module | 1 | e.g., TSOP1738, VS1838B |
| Blue LED | 1 | 5mm or 3mm |
| Orange LED | 1 | 5mm or 3mm |
| Green LED | 1 | 5mm or 3mm |
| 220Ω Resistors | 3 | One for each LED |
| Breadboard | 1 | Standard size |
| Jumper Wires | - | Assorted male-male wires |

## 🔌 Wiring Diagram

Connect the components according to the pin assignments below.

| Component | Arduino Pin |
| :--- | :--- |
| **IR Receiver** | |
| Signal Pin | Digital Pin 11 |
| VCC Pin (+) | 5V |
| GND Pin (-) | GND |
| | |
| **Blue LED (Anode)** | Digital Pin 5 |
| **Orange LED (Anode)** | Digital Pin 4 |
| **Green LED (Anode)** | Digital Pin 3 |

**Important Notes:**
-   **IR Receiver Pins:** Pinouts can vary. Check your receiver's datasheet. For a TSOP1738, looking at the dome, the pins are typically: Pin 1 (Signal), Pin 2 (GND), Pin 3 (VCC). The wiring above is by function, not pin number.
-   Connect the **cathode** (shorter leg) of each LED to a **220Ω resistor**.
-   Connect the other end of the resistors to the **GND** rail on the breadboard.
-   Connect a jumper wire from the Arduino's **GND** pin to the GND rail on the breadboard.

![Schematic Placeholder](https://user-images.githubusercontent.com/1018826/160359864-1e8c15b1-4d51-460d-8551-a20d58a8a4f6.png)
*A Fritzing diagram or a clear photo of the wired breadboard is highly recommended here.*

## 💻 Software & Libraries

1.  **[Arduino IDE](https://www.arduino.cc/en/software):** You'll need the Arduino IDE to upload code to your board.
2.  **`IRremote` Library:** This project depends on a powerful IR library. Install it from the Arduino IDE:
    -   Go to `Sketch` > `Include Library` > `Manage Libraries...`
    -   Search for "**IRremote**".
    -   Find the one by **Shiriff, z3t0, ArminJo** (and others) and click `Install`.

## 🚀 Installation & Usage

### Step 1: Find Your Remote's IR Codes

Every button on every remote sends a unique code. You need to find these codes first.

1.  Open the Arduino IDE and paste in the simple decoder sketch provided in the repository (`Find_IR_Codes.ino` or the code below).
2.  Upload this sketch to your Arduino.
3.  Open the **Serial Monitor** (`Tools > Serial Monitor`) and set the baud rate to **9600**.
4.  Point your remote at the IR receiver and press a button (e.g., the '1' button).
5.  You will see a hexadecimal code appear in the Serial Monitor (e.g., `0xFF30CF`). This is the code for that button.
6.  Press the buttons you want to use for the blue, orange, and green LEDs and **write down their codes**.

```cpp
// --- Simple IR Decoder Sketch ---
#include <IRremote.h>

const int RECV_PIN = 11; // The pin where the IR receiver is connected
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Ready to decode IR signals...");
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX); // Print the code in hexadecimal
    irrecv.resume(); // Receive the next value
  }
}

Step 2: Upload and Run the Main Project

Now, open the main project file (IR_LED_Control.ino).

In the code, find the lines where the button codes are defined:

Generated cpp
#define KEY_1 0xYOUR_CODE_HERE_1 // Replace with the code for your first button
#define KEY_2 0xYOUR_CODE_HERE_2 // Replace with the code for your second button
#define KEY_3 0xYOUR_CODE_HERE_3 // Replace with the code for your third button
IGNORE_WHEN_COPYING_START
content_copy
download
Use code with caution.
C++
IGNORE_WHEN_COPYING_END

Replace the placeholder codes (0xYOUR_CODE_HERE...) with the actual codes you found in Step 1.

Upload this final sketch to your Arduino.

Point your remote at the receiver and press your chosen buttons. The corresponding LEDs should toggle on and off!

🔧 How It Works

The main sketch continuously listens for an incoming IR signal. When a signal is decoded, its value is compared against the pre-defined codes in a switch statement.

Generated cpp
// In the main loop...
if (irrecv.decode(&results)) {
  switch(results.value) {
    case KEY_1: // If the code matches button 1
      // Toggle the blue LED's state
      digitalWrite(blueLedPin, !digitalRead(blueLedPin));
      break;
    case KEY_2: // If the code matches button 2
      // Toggle the orange LED's state
      digitalWrite(orangeLedPin, !digitalRead(orangeLedPin));
      break;
    // ... and so on for the other keys
  }
  irrecv.resume(); // Get ready for the next signal
}
IGNORE_WHEN_COPYING_START
content_copy
download
Use code with caution.
C++
IGNORE_WHEN_COPYING_END

The !digitalRead(pin) logic is a clever trick to toggle the state. It reads the current state (HIGH or LOW) and writes the opposite state back to the pin.

🤝 Contributing

Contributions, issues, and feature requests are welcome!

Fork the Project

Create your Feature Branch (git checkout -b feature/NewControl)

Commit your Changes (git commit -m 'Add a new control feature')

Push to the Branch (git push origin feature/NewControl)

Open a Pull Request

📄 License

This project is distributed under the MIT License. See LICENSE for more information.
