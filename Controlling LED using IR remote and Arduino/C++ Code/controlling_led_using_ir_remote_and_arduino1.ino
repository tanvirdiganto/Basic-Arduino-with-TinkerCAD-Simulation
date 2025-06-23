
// C++ code
// Owner: Diganto
// CE, KUET
// Title: LED Control via IR Remote Using Arduino

#include <IRremote.h>

// Define pin numbers
const int IR_PIN = 12;       // IR receiver pin
const int LED_BLUE = 9;      // Blue LED pin
const int LED_ORANGE = 10;   // Orange LED pin
const int LED_GREEN = 11;    // Green LED pin

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);

  // Initialize IR receiver on specified pin
  IrReceiver.begin(IR_PIN);

  // Set LED pins as output
  pinMode(LED_BLUE, OUTPUT);
  pinMode(LED_ORANGE, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
}

void loop() {
  // Check if IR signal is received
  if (IrReceiver.decode()) {
    // Store decoded raw data from IR remote
    long receivedCode = IrReceiver.decodedIRData.decodedRawData;

    // Print the received code for monitoring
    Serial.println(receivedCode);

    // Determine action based on received IR code
    handleIRCode(receivedCode);

    // Prepare to receive the next IR signal
    IrReceiver.resume();
  }

  // Small delay to reduce processing load
  delay(10);
}

// Function to handle LED control based on IR code
void handleIRCode(long code) {
  switch (code) {
    case -284115200:
      // Button 1 pressed -> Turn on blue LED
      digitalWrite(LED_BLUE, HIGH);
      break;
    case -300826880:
      // Button 2 pressed -> Turn off blue LED
      digitalWrite(LED_BLUE, LOW);
      break;
    case -317538560:
      // Button 3 pressed -> Turn on orange LED
      digitalWrite(LED_ORANGE, HIGH);
      break;
    case -350961920:
      // Button 4 pressed -> Turn off orange LED
      digitalWrite(LED_ORANGE, LOW);
      break;
    case -367673600:
      // Button 5 pressed -> Turn on green LED
      digitalWrite(LED_GREEN, HIGH);
      break;
    case -384385280:
      // Button 6 pressed -> Turn off green LED
      digitalWrite(LED_GREEN, LOW);
      break;
    default:
      // Unrecognized code -> Do nothing
      break;
  }
}
