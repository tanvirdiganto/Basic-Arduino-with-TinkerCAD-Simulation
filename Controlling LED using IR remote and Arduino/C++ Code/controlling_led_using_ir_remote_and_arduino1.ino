// C++ code
// Owner: Diganto
// CSE, KUET
// Title: Light Intensity Measurement Using LDR Sensor

// Variable to store the analog reading from the LDR
int sensorValue = 0;

void setup() {
  // Set A0 as input (LDR sensor connected here)
  pinMode(A0, INPUT);

  // Set pin 9 as output (for controlling LED brightness or similar)
  pinMode(9, OUTPUT);

  // Initialize serial communication at 9600 bps
  Serial.begin(9600);
}

void loop() {
  // Read analog value from LDR (0 to 1023)
  sensorValue = analogRead(A0);

  // Print the sensor reading to the Serial Monitor
  Serial.println(sensorValue);

  // Map the sensor value (0-1023) to PWM value (0-255)
  // This controls brightness of an LED or motor speed etc.
  int pwmValue = map(sensorValue, 0, 1023, 0, 255);

  // Output the mapped PWM value to pin 9
  analogWrite(9, pwmValue);

  // Short delay before next reading (100 ms)
  delay(100);
}

