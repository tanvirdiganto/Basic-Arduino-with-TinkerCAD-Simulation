// C++ code
// Owner : Tanvir Hossain Diganto
// CE, KUET

/*
  Title: Light Intensity Measurement Using LDR Sensor
  Description: This program reads light intensity from an LDR sensor 
  and adjusts the brightness of an LED (or other PWM device) based on light level.
*/

// Variable to store the sensor reading
int sensorValue = 0;

void setup()
{
  // Set pin A0 (where LDR is connected) as input
  pinMode(A0, INPUT);

  // Start serial communication at 9600 baud rate for monitoring the sensor value
  Serial.begin(9600);

  // Set pin 9 as output (this could control an LED or similar device)
  pinMode(9, OUTPUT);
}

void loop()
{
  // Read the analog value from LDR sensor (0 to 1023)
  sensorValue = analogRead(A0);

  // Print the raw sensor value to Serial Monitor for debugging/monitoring
  Serial.println(sensorValue);

  // Map the sensor value (0-1023) to PWM range (0-255)
  // This allows the LED brightness to correspond to light level
  analogWrite(9, map(sensorValue, 0, 1023, 0, 255));

  // Small delay to make serial output readable and reduce flicker
  delay(100); 
}
