// C++ code
// Title: Automatic Smart Hand Sanitizer
// Author:  Diganto]
// Department: CE, KUET

#include <Servo.h>

// --- Pin Definitions ---
const int TRIG_PIN = 2;    // Ultrasonic sensor trigger pin
const int ECHO_PIN = 3;    // Ultrasonic sensor echo pin
const int SERVO_PIN = 9;   // Servo motor control pin

// --- Objects ---
Servo sanitizerServo;

// --- Measurement Variables ---
float distanceCM = 0.0;
unsigned long durationUS = 0;

void setup() {
  // Initialize pins
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  // Attach servo to its pin
  sanitizerServo.attach(SERVO_PIN);
  sanitizerServo.write(90);  // Initial neutral position

  // Start serial communication
  Serial.begin(9600);
  Serial.println("Smart Hand Sanitizer Ready");
}

void loop() {
  // Measure distance
  distanceCM = getDistance();

  // Display distance reading
  Serial.print("Measured Distance: ");
  Serial.print(distanceCM);
  Serial.println(" cm");

  // Check if hand is detected within valid range
  if (distanceCM > 0 && distanceCM < 4) {
    activateSanitizer();
  } else {
    Serial.println("No hand detected / Out of range");
    sanitizerServo.detach();  // Power off servo to save energy
  }

  delay(500);
}

// --- Function to trigger ultrasonic sensor and calculate distance ---
float getDistance() {
  // Send ultrasonic pulse
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Measure the echo duration
  durationUS = pulseIn(ECHO_PIN, HIGH);

  // Convert duration to distance in cm
  float distance = (durationUS / 2.0) * 0.0349;
  return distance;
}

// --- Function to control sanitizer servo motion ---
void activateSanitizer() {
  sanitizerServo.attach(SERVO_PIN);

  // Dispensing sequence
  sanitizerServo.write(0);
  delay(1000);
  sanitizerServo.write(90);
  delay(1000);
  sanitizerServo.write(180);
  delay(1000);
  sanitizerServo.write(90);

  // Detach after operation
  sanitizerServo.detach();
}
