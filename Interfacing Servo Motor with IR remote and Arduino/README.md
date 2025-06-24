# 📡 Arduino IR Remote Controlled Servo ⚙️

  <!-- It's highly recommended to replace this with a GIF of your own project! -->

A beginner-friendly Arduino project to control the position of a servo motor using a standard infrared (IR) remote control. This guide provides the circuit diagram, code, and step-by-step instructions.

## ✨ Features

*   ✅ **Wireless Control:** Position your servo motor from a distance.
*   ✅ **Easy to Assemble:** Simple wiring that's great for beginners.
*   ✅ **Customizable:** Easily map any button from your remote to a specific servo angle.
*   ✅ **Low Cost:** Uses common and inexpensive components.

## 🛠️ Required Components

| Component | Image | Description |
| :--- | :---: | :--- |
| **Arduino Board** | 🤖 | Any Arduino-compatible board (e.g., Uno, Nano, Mega). |
| **Servo Motor** | ⚙️ | A standard servo like SG90 (plastic gear) or MG995 (metal gear). |
| **IR Receiver** | ⚫ | A 3-pin IR receiver module like the TSOP1738. |
| **IR Remote** | 📺 | Almost any household IR remote will work (TV, DVD, etc.). |
| **Jumper Wires** | 🔌 | For connecting everything together on a breadboard. |
| **Breadboard** | 🔳 | Optional but highly recommended for easy prototyping. |

## 🔌 Wiring & Circuit Diagram

Follow this wiring guide to connect your components.

### Component Connections

| Component | Arduino Pin | Description |
| :--- | :---: | :--- |
| **IR Receiver (Vout/Signal)** | `Pin 11` | The pin that receives the IR signal data. |
| **IR Receiver (GND)** | `GND` | Ground connection. |
| **IR Receiver (Vcc)** | `5V` | 5V power supply. |
| **Servo Motor (Signal)** | `Pin 9` | The PWM pin that controls the servo position. |
| **Servo Motor (GND)** | `GND` | Ground connection (Brown/Black wire). |
| **Servo Motor (Vcc)** | `5V` | 5V power supply (Red/Orange wire). |

> **⚠️ Important Note:** Powering a servo directly from the Arduino's 5V pin can sometimes cause the Arduino to reset due to power spikes. For larger servos or more stable operation, it's recommended to power the servo from a separate 5V power source, making sure to connect the grounds together.

### Fritzing Diagram



## 🚀 Installation & Setup

### 1. Hardware Assembly

Connect all the components according to the wiring diagram above.

### 2. Software & Libraries

1.  **Download the Arduino IDE:** If you don't have it, [download it here](https://www.arduino.cc/en/software).
2.  **Install the Library:** This project requires the `IRremote` library. You can install it directly from the Arduino IDE:
    *   Go to `Sketch` -> `Include Library` -> `Manage Libraries...`
    *   Search for **`IRremote`** by `shirriff`.
    *   Click on the result and press the `Install` button.

    

## 👨‍💻 The Code

There are two parts to the code:
1.  **Finding Your Remote's Codes:** First, you need to find the unique hexadecimal codes for the buttons on your IR remote.
2.  **Controlling the Servo:** Use those codes in the main sketch to control the servo.

---

### Part 1: Finding Your IR Remote Codes

Upload this sketch to your Arduino. Point your IR remote at the receiver and press buttons. The corresponding HEX code for each button will be printed to the Serial Monitor.

**`IR_Code_Finder.ino`**
```cpp
#include <IRremote.h>

// Define the pin for the IR receiver
const int IR_RECEIVE_PIN = 11;

// Create an IR receiver object
IRrecv irrecv(IR_RECEIVE_PIN);
decode_results results;

void setup() {
  // Start the serial communication
  Serial.begin(9600);
  Serial.println("IR Receiver Booting Up...");

  // Start the IR receiver
  irrecv.enableIRIn();
}

void loop() {
  // Check if an IR signal has been received
  if (irrecv.decode(&results)) {
    // Print the received code in HEX format
    Serial.print("Received IR Code: 0x");
    Serial.println(results.value, HEX);

    // Resume listening for the next signal
    irrecv.resume();
  }
}
```

**How to Use:**
1. Upload the code above.
2. Open the Serial Monitor (`Tools` -> `Serial Monitor`).
3. Set the baud rate to `9600`.
4. Press a button on your remote (e.g., 'Volume Up').
5. Note down the code from the Serial Monitor (e.g., `0xFFE01F`).
6. Repeat for all the buttons you want to use.

---

### Part 2: Main Servo Control Code

Now, replace the placeholder codes in this sketch with the ones you just found.

**`IR_Servo_Control.ino`**
```cpp
#include <IRremote.h>
#include <Servo.h>

// --- Pin Definitions ---
const int IR_RECEIVE_PIN = 11;
const int SERVO_PIN = 9;

// --- IR Remote Codes (REPLACE THESE WITH YOURS!) ---
#define BTN_0_DEG   0xFFA25D // Example: '1' button
#define BTN_90_DEG  0xFF629D // Example: '2' button
#define BTN_180_DEG 0xFFE21D // Example: '3' button

// --- Object Creation ---
IRrecv irrecv(IR_RECEIVE_PIN);
Servo myServo;
decode_results results;

void setup() {
  // Start Serial for debugging
  Serial.begin(9600);
  
  // Attach the servo on the defined pin
  myServo.attach(SERVO_PIN);
  
  // Start the IR receiver
  irrecv.enableIRIn();
  
  Serial.println("IR Servo Control Ready!");
  myServo.write(90); // Start servo at middle position
}

void loop() {
  // Check if an IR signal has been received
  if (irrecv.decode(&results)) {
    // Print the received code for debugging
    Serial.print("Received IR Code: 0x");
    Serial.println(results.value, HEX);

    // Use a switch statement to check the code
    switch (results.value) {
      case BTN_0_DEG:
        Serial.println("-> Moving to 0 degrees");
        myServo.write(0);
        break;
        
      case BTN_90_DEG:
        Serial.println("-> Moving to 90 degrees");
        myServo.write(90);
        break;
        
      case BTN_180_DEG:
        Serial.println("-> Moving to 180 degrees");
        myServo.write(180);
        break;
    }
    
    // Resume listening for the next signal
    irrecv.resume();
  }
}
```

## 🕹️ How to Use

1.  **Assemble** the circuit as shown in the diagram.
2.  **Upload** the `IR_Code_Finder.ino` sketch and find your remote's button codes.
3.  **Update** the `IR_Servo_Control.ino` sketch with your specific codes.
4.  **Upload** the final `IR_Servo_Control.ino` sketch to your Arduino.
5.  **Power up** the circuit and press the configured buttons on your remote. The servo should move to the corresponding positions!

## 🤔 Troubleshooting

*   **Servo is Jittery or Arduino Resets:** The servo is drawing too much current. Power the servo from a separate 5V 1A power supply, ensuring the grounds of the Arduino and power supply are connected.
*   **IR Receiver Not Working:**
    *   Double-check the `VCC`, `GND`, and `Signal` pins. They can vary between modules.
    *   Make sure you are not too far from the receiver or that there isn't bright sunlight interfering with it.
    *   Ensure the `IR_RECEIVE_PIN` in the code matches the pin you connected the receiver to.
*   **Wrong Codes or No Codes Detected:** Some remotes use different protocols. The `IRremote` library is very versatile, but in rare cases, a specific remote might not be supported. Try a different remote. Also, the code `0xFFFFFFFF` means a button is being held down; you need the unique code that appears first.

## 💡 Customization Ideas

*   **Incremental Movement:** Add buttons to slowly increase or decrease the servo angle.
*   **Speed Control:** Change how fast the servo moves from one position to another.
*   **Saved Positions:** Use buttons to "save" the current servo position and other buttons to "recall" it.
*   **Combine with other sensors:** Make the servo only respond when a light sensor detects darkness.

---


---
#Arduino #ServoMotor #IRRemote #Robotics #Automation #EmbeddedSystems #Electronics #IoT #MotorControl #ArduinoProjects

