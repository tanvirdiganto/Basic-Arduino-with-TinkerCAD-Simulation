// C++ code
// Author: Diganto
// CE, KUET
// Title: Arduino Piano Using Push Buttons and Piezo Buzzer

// --- Pin and tone configuration ---
const int PIEZO_PIN = 13;  // Piezo buzzer pin

// Array of button pins (connected to digital pins 2 to 9)
const int BUTTON_PINS[8] = {2, 3, 4, 5, 6, 7, 8, 9};

// Corresponding musical note frequencies (Hz)
const int NOTE_FREQUENCIES[8] = {262, 294, 330, 349, 392, 440, 494, 523};

void setup() {
  // Initialize button pins as INPUT
  for (int index = 0; index < 8; index++) {
    pinMode(BUTTON_PINS[index], INPUT);
  }

  // Set piezo pin as OUTPUT
  pinMode(PIEZO_PIN, OUTPUT);

  // Initialize serial communication
  Serial.begin(9600);
  Serial.println("Arduino Piano Ready!");
}

void loop() {
  // Continuously check each button
  checkButtons();
}

// Function to check button presses and play corresponding note
void checkButtons() {
  for (int index = 0; index < 8; index++) {
    if (digitalRead(BUTTON_PINS[index]) == HIGH) {
      // Print which button was pressed
      Serial.print("Note Button Pressed: ");
      Serial.println(index + 1);

      // Play the tone for 100 ms
      tone(PIEZO_PIN, NOTE_FREQUENCIES[index], 100);

      // Small delay to avoid bouncing and repeated triggers
      delay(100);

      // Exit loop after detecting one button press
      break;
    }
  }
}

