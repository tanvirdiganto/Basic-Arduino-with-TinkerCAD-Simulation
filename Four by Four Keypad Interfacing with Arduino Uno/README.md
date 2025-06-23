# 4×4 Keypad Interfacing with Arduino Uno

This project demonstrates how to interface a 4×4 matrix keypad with an Arduino Uno. It detects key presses and displays them via the Serial Monitor. It's a perfect starter for learning matrix keypad scanning and character input handling using the Keypad library.

---

## 🔧 Required Components

- Arduino Uno (or compatible board)
- 4×4 Matrix Keypad
- Jumper wires

---

## ⚡️ Wiring Diagram

Connect the keypad pins to the Arduino digital pins as follows. The rows and columns are typically labeled on the keypad's connector.

| Keypad Pin | Arduino Pin |
| :--------- | :---------- |
| **Row 1**  | Pin 9       |
| **Row 2**  | Pin 8       |
| **Row 3**  | Pin 7       |
| **Row 4**  | Pin 6       |
| **Col 1**  | Pin 5       |
| **Col 2**  | Pin 4       |
| **Col 3**  | Pin 3       |
| **Col 4**  | Pin 2       |

---

## 💡 How It Works

### 🔌 Keypad Connection
- The 4×4 keypad consists of **4 rows and 4 columns** (8 pins in total).
- Pressing a key forms an electrical connection between a **specific row and column**.

### 🧠 Key Detection Process
- The Arduino uses the popular **Keypad library** to efficiently scan the keypad matrix.
- The `makeKeymap(keys)` function maps the physical keys on the pad to their logical character values (e.g., '1', '#', 'A').
- The `keypad.getKey()` function is called repeatedly in the main loop to check if any key is currently being pressed.

### 🖥️ Serial Output
- When a key is pressed, the **corresponding character** is printed on the **Serial Monitor**, allowing you to see the input in real-time.

---

## 💾 Code

Here is the complete Arduino sketch. You'll need to install the `Keypad` library by `Mark Stanley` and `Alexander Brevig` from the Arduino Library Manager.

```cpp
#include <Keypad.h>

const byte ROWS = 4; // Four rows
const byte COLS = 4; // Four columns

// Define the keymap
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

// Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.
byte rowPins[ROWS] = {9, 8, 7, 6};

// Connect keypad COL0, COL1, COL2 and COL3 to these Arduino pins.
byte colPins[COLS] = {5, 4, 3, 2};

// Create the Keypad
Keypad kypd = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600); // Start serial communication
  Serial.println("4x4 Keypad Test:");
}

void loop() {
  // Get the key that is pressed
  char key = kypd.getKey();

  // If a key is pressed, print it to the Serial Monitor
  if (key) {
    Serial.print("Key Pressed: ");
    Serial.println(key);
  }
}
```

---

## 🚀 How to Use

1.  **Assemble the Circuit:** Connect the components according to the wiring diagram above.
2.  **Install Library:** Open the Arduino IDE, go to **Sketch > Include Library > Manage Libraries...**, and search for and install the "Keypad" library.
3.  **Upload the Code:** Copy the code above into a new sketch in the Arduino IDE and upload it to your Arduino Uno.
4.  **Open Serial Monitor:** Click the magnifying glass icon in the top-right corner of the IDE (or go to **Tools > Serial Monitor**). Make sure the baud rate is set to **9600**.
5.  **Test:** Press the buttons on your keypad. The corresponding character for each pressed key will appear in the Serial Monitor.

---

## 📚 Applications

- User input for embedded systems
- Calculator interfaces
- Digital locks and password systems
- Menu navigation in custom hardware
- Device control and automation triggers

---

## 🏷️ Hashtags

#Arduino #Keypad #EmbeddedSystems #Electronics #DIY #KeypadInterface #MatrixKeypad #IoT #ArduinoProjects #Automation
