// C++ code
// Owner: Diganto
// CE, KUET
// Title: 4x4 Keypad Interface with Arduino Uno

#include <Keypad.h>

// --- Keypad configuration ---
const byte NUM_ROWS = 4;
const byte NUM_COLS = 4;

// Key layout on the keypad
char keypadLayout[NUM_ROWS][NUM_COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

// Arduino pin connections
byte rowPins[NUM_ROWS] = {9, 8, 7, 6};
byte colPins[NUM_COLS] = {5, 4, 3, 2};

// Create Keypad object
Keypad myKeypad = Keypad(makeKeymap(keypadLayout), rowPins, colPins, NUM_ROWS, NUM_COLS);

void setup() {
  // Initialize serial monitor
  Serial.begin(9600);
  Serial.println("System Initialized: Waiting for key press...");
}

void loop() {
  // Fetch key press
  char pressedKey = myKeypad.getKey();

  if (pressedKey != NO_KEY) {
    // Display the pressed key
    displayKey(pressedKey);
  }
}

// Function to print key to Serial Monitor
void displayKey(char key) {
  Serial.print("Detected Key: ");
  Serial.println(key);
}
