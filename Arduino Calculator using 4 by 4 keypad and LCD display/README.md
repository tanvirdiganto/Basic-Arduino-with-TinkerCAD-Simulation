# Arduino Calculator with 4x4 Keypad and 16x2 LCD

A simple, yet functional, calculator built using an Arduino Uno. It performs basic arithmetic operations (+, -, *, /) using a 4x4 keypad for input and displays the numbers and results on a 16x2 I2C LCD screen.

![Project Demo Placeholder](https://via.placeholder.com/600x400.png?text=Replace+this+with+a+photo+of+your+project!)
*(Replace the image above with a real photo or GIF of your working calculator!)*

---

## Features

- **Basic Arithmetic:** Supports Addition (+), Subtraction (-), Multiplication (*), and Division (/).
- **Multi-Digit Numbers:** Handles input of numbers with multiple digits.
- **Real-time Display:** Shows the numbers being typed and the final result on the LCD.
- **Clear Function:** A dedicated key (`*`) to clear the current calculation and start over.
- **Simple Interface:** Uses standard calculator logic: `Number1` -> `Operator` -> `Number2` -> `Equals`.

---

## Required Components

-   1 x Arduino Uno (or any compatible board)
-   1 x 16x2 I2C LCD Display
-   1 x 4x4 Matrix Keypad Module
-   1 x Breadboard
-   A set of Jumper Wires (Male-to-Male and Male-to-Female)

> **Note:** This project is designed for an **I2C LCD**. This type of LCD is highly recommended as it only requires 4 wires (VCC, GND, SDA, SCL), making the wiring much simpler. If you are using a parallel LCD, you will need to adjust both the wiring and the code significantly.

---

## Wiring Diagram

Connect the components as described in the tables below.

### 1. I2C LCD Display to Arduino

| LCD Pin | Arduino Pin | Description         |
| :------ | :---------- | :------------------ |
| `VCC`   | `5V`        | 5V Power            |
| `GND`   | `GND`       | Ground              |
| `SDA`   | `A4`        | I2C Data Line       |
| `SCL`   | `A5`        | I2C Clock Line      |

### 2. 4x4 Keypad to Arduino

The keypad has 8 pins. The first 4 are for rows and the next 4 are for columns.

| Keypad Pin (from left) | Function | Arduino Pin |
| :--------------------- | :------- | :---------- |
| Pin 1                  | Row 1    | `D9`        |
| Pin 2                  | Row 2    | `D8`        |
| Pin 3                  | Row 3    | `D7`        |
| Pin 4                  | Row 4    | `D6`        |
| Pin 5                  | Column 1 | `D5`        |
| Pin 6                  | Column 2 | `D4`        |
| Pin 7                  | Column 3 | `D3`        |
| Pin 8                  | Column 4 | `D2`        |

---

## Installation & Setup

### 1. Required Libraries

You need to install two libraries for this project to work. You can install them directly from the Arduino IDE.

1.  `LiquidCrystal_I2C` by Frank de Brabander
2.  `Keypad` by Mark Stanley, Alexander Brevig

**To install the libraries:**
-   Open the Arduino IDE.
-   Go to **Sketch** -> **Include Library** -> **Manage Libraries...**
-   Search for `LiquidCrystal I2C` and install the one by Frank de Brabander.
-   Search for `Keypad` and install the one by Mark Stanley, Alexander Brevig.

### 2. Find Your LCD's I2C Address

I2C devices have a unique address. Most 16x2 LCD modules use `0x27` or `0x3F`. If your screen doesn't work, run an "I2C Scanner" sketch (widely available online) to find the correct address for your specific module. Update the address in the `main.ino` file if necessary:
```cpp
// Update this address if your LCD uses a different one
LiquidCrystal_I2C lcd(0x27, 16, 2); 
```

### 3. Upload the Code

1.  Clone this repository or download the `main.ino` file.
2.  Open the `main.ino` file in the Arduino IDE.
3.  Connect your Arduino board to your computer.
4.  In the IDE, go to **Tools** -> **Board** and select your Arduino board (e.g., "Arduino Uno").
5.  Go to **Tools** -> **Port** and select the correct serial port.
6.  Click the **Upload** button.

---

## How to Use the Calculator

The keypad is mapped as follows:
-   `A` is used for **Addition (+)**
-   `B` is used for **Subtraction (-)**
-   `C` is used for **Multiplication (*)**
-   `D` is used for **Division (/)**
-   `*` is used to **Clear (AC)** the calculation.
-   `#` is used as the **Equals (=)** key.

**Operation Flow:**
1.  Turn on the Arduino. The LCD will display a "Welcome" message.
2.  Enter your first number (e.g., `123`). The number will appear on the LCD.
3.  Press an operator key (`A`, `B`, `C`, or `D`). The operator will be displayed.
4.  Enter your second number (e.g., `45`).
5.  Press the `#` (Equals) key.
6.  The result will be calculated and displayed on the bottom line of the LCD.
7.  Press the `*` (Clear) key to start a new calculation at any time.

---

## Future Improvements

This is a basic implementation and can be extended with more features:

-   [ ] **Decimal Point Support:** Add functionality for floating-point calculations.
-   [ ] **Error Handling:** Implement checks for errors like "Division by Zero".
-   [ ] **Order of Operations (PEMDAS/BODMAS):** A more advanced logic to handle complex expressions.
-   [ ] **Negative Numbers:** Support for entering and calculating with negative values.
-   [ ] **Memory Functions:** Add `M+`, `M-`, and `MR` capabilities.
-   [ ] **Custom 3D-Printed Case:** Design and print a case to house all the components neatly.

---

## License

This project is licensed under the MIT License. See the `LICENSE` file for more details.

Happy building! 🛠️
