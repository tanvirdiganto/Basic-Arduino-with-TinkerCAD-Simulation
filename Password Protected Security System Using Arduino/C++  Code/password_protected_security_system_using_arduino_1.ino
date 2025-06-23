// C++ code
// Owner: Diganto
// CE, KUET
// Title: Password Protected Security System Using Arduino

#include <Keypad.h>  // Include keypad library

// Constants
const byte ROWS = 4;
const byte COLS = 4;
const int RED = 12;       // Red LED pin
const int GREEN = 11;     // Green LED pin
const int PIEZO = 10;     // Buzzer pin

// Keypad layout
char numpad[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

// Keypad row and column pins
byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

// Password setup
String password = "12345";
String inputStr = "";  // Store user input

// Initialize keypad object
Keypad keyPad = Keypad(makeKeymap(numpad), rowPins, colPins, ROWS, COLS);

// Unlock tone frequencies (Hz)
const int frequency[] = {340, 623, 523, 440, 623};
// Tone duration (ms)
const int delayTime[] = {200, 200, 200, 250, 150};

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(PIEZO, OUTPUT);
  
  digitalWrite(RED, HIGH);      // RED LED ON initially
  digitalWrite(GREEN, LOW);     // GREEN LED OFF initially
  
  Serial.begin(9600);
  Serial.print("Enter Password: ");
}

void loop() {
  char key = keyPad.getKey();

  if (key) {
    // Beep for key press
    tone(PIEZO, 300);
    delay(50);
    noTone(PIEZO);

    // Only accept up to 5 digits
    if (inputStr.length() < 5) {
      Serial.print("*");        // Mask input with *
      inputStr += key;          // Append key to input string
    }
  }

  // Check password when 5 keys entered
  if (inputStr.length() == 5) {
    delay(1000);                // Small delay before checking
    if (inputStr == password) {
      // Correct password
      Serial.println("\nEnter");
      digitalWrite(RED, LOW);
      digitalWrite(GREEN, HIGH);
      unlockTone();
    } else {
      // Incorrect password
      Serial.println("\n\tWrong Password\n\tPlease Try Again!!");
      digitalWrite(RED, HIGH);
      digitalWrite(GREEN, LOW);

      // Error tone
      tone(PIEZO, 1000);
      delay(500);
      tone(PIEZO, 1000);
      delay(500);
      noTone(PIEZO);
    }

    // Reset for next input
    delay(1000);
    inputStr = "";
    Serial.println("---------------------------\nEnter Password: ");
    digitalWrite(RED, HIGH);
    digitalWrite(GREEN, LOW);
  }
}

void unlockTone() {
  for (int i = 0; i < 5; i++) {
    tone(PIEZO, frequency[i]);
    delay(delayTime[i]);
    noTone(PIEZO);
    delay(20);                  // Short pause between notes
  }
}

