// C++ code
// Owner: Diganto
// CSE, KUET
// Title: Light Intensity Measurement Using LDR Sensor

// Variable to store the analog reading from the LDR
// Include the IRremote library
#include <IRremote.h>

// --- Define Pin Numbers ---
int IR_RECEIVE_PIN = 12; // Pin where the IR receiver's signal is connected
int bluePin = 2;         // Pin for the Blue LED
int orangePin = 3;       // Pin for the Orange LED
int greenPin = 4;        // Pin for the Green LED

// --- Create IR Objects ---
// Create an IRrecv object to receive the IR signals
IRrecv irrecv(IR_RECEIVE_PIN); 

// Create a decode_results object to store the decoded data
decode_results results;

void setup() {
  // Start serial communication at 9600 baud rate (for debugging)
  Serial.begin(9600);
  
  // Start the IR receiver
  irrecv.enableIRIn();

  // Set the LED pins as OUTPUTs
  pinMode(bluePin, OUTPUT);
  pinMode(orangePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop() {
  // Check if an IR signal has been received and decoded
  if (irrecv.decode(&results)) {

    // Print the received code to the serial monitor (optional, good for debugging)
    Serial.println(results.value); 
    
    // Switch statement to perform actions based on the received remote code
    // IMPORTANT: Replace the case numbers with the ones from YOUR remote (see Step 2)
    switch (results.value) {
      
      // When you press the '1' button on the remote
      case 16582903: 
        digitalWrite(bluePin, HIGH); // Turn the Blue LED ON
        break;

      // When you press the '2' button
      case 16615543: 
        digitalWrite(bluePin, LOW); // Turn the Blue LED OFF
        break;

      // When you press the '3' button
      case 16599223: 
        digitalWrite(orangePin, HIGH); // Turn the Orange LED ON
        break;

      // When you press the '4' button
      case 16591063: 
        digitalWrite(orangePin, LOW); // Turn the Orange LED OFF
        break;

      // When you press the '5' button
      case 16623703: 
        digitalWrite(greenPin, HIGH); // Turn the Green LED ON
        break;
      
      // When you press the '6' button
      case 16607383: 
        digitalWrite(greenPin, LOW); // Turn the Green LED OFF
        break;
    }
    
    // Resume listening for the next IR signal. This is very important!
    irrecv.resume();
  }
  
  // A small delay to avoid reading the same press multiple times
  delay(10); 
}
