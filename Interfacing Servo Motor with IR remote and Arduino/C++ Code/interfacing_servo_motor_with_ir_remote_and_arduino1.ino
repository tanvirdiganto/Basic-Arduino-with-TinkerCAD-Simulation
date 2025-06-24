// C++ code
/*Diganto
CE, KUET*/

/*TITLE: Interfacing Servo Motor  with IR remote and Arduino*/

/*
  Project: Control a Servo Motor with an IR Remote and Arduino
  Description: This code moves a servo motor to different angles based on which
               button is pressed on an IR remote. After moving, it waits for a
               second and returns to the initial position (0 degrees).
  
  Libraries needed:
  - IRremote.h (by shirriff, v2.x)
  - Servo.h (built-in)
*/

#include <IRremote.h> // Include the IR Remote library
#include <Servo.h>    // Include the Servo library

// ---------- PIN DEFINITIONS ----------
const int RECV_PIN = 5; // The Arduino pin connected to the IR receiver's signal pin
const int SERVO_PIN = 3;  // The Arduino pin connected to the servo's signal pin (must be PWM ~)

// ---------- GLOBAL OBJECTS AND VARIABLES ----------
IRrecv irrecv(RECV_PIN);     // Create an IRrecv object to receive IR signals
decode_results results;    // Create a decode_results object to store the decoded data
Servo myservo;             // Create a servo object to control a servo

// ---------- SETUP FUNCTION - RUNS ONCE ----------
void setup() {
  // Start serial communication at 9600 baud rate for debugging
  Serial.begin(9600); 

  // Start the IR receiver
  irrecv.enableIRIn(); 
  Serial.println("IR Receiver is enabled.");

  // Attach the servo object to its pin
  myservo.attach(SERVO_PIN);
  
  // Move the servo to its initial position (0 degrees) at the start
  myservo.write(0);
  Serial.println("Servo is at initial position (0 degrees).");
}

// ---------- LOOP FUNCTION - RUNS REPEATEDLY ----------
void loop() {
  // Check if an IR signal has been received and decoded
  if (irrecv.decode(&results)) {

    // Print the received HEX code to the Serial Monitor. This is useful
    // for finding the codes for your own remote's buttons.
    Serial.print("Received IR Code (HEX): ");
    Serial.println(results.value, HEX);

    // Use a switch statement to check which button was pressed
    switch(results.value) {
      // These are the HEX codes for the remote used in the video.
      // 0xFF30CF corresponds to button '1' (or 16582903 in decimal)
      case 0xFF30CF: 
        Serial.println("Button 1 Pressed - Moving to 45 degrees");
        myservo.write(45);  // Move servo to 45 degrees
        delay(1000);        // Wait for 1 second
        myservo.write(0);   // Return to the initial position
        break;

      // 0xFF18E7 corresponds to button '2' (or 16615543 in decimal)
      case 0xFF18E7: 
        Serial.println("Button 2 Pressed - Moving to 90 degrees");
        myservo.write(90);  // Move servo to 90 degrees
        delay(1000);        // Wait for 1 second
        myservo.write(0);   // Return to the initial position
        break;

      // 0xFF7A85 corresponds to button '3' (or 16599223 in decimal)
      case 0xFF7A85:
        Serial.println("Button 3 Pressed - Moving to 135 degrees");
        myservo.write(135); // Move servo to 135 degrees
        delay(1000);        // Wait for 1 second
        myservo.write(0);   // Return to the initial position
        break;

      // 0xFF10EF corresponds to button '4' (or 16591063 in decimal)
      case 0xFF10EF: 
        Serial.println("Button 4 Pressed - Moving to 180 degrees");
        myservo.write(180); // Move servo to 180 degrees
        delay(1000);        // Wait for 1 second
        myservo.write(0);   // Return to the initial position
        break;
    }

    // Resume listening for the next IR signal
    irrecv.resume(); 
  }
}
