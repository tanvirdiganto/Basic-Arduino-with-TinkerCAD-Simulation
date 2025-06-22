

/*Title : Interfacing Ultrasonic Sensor with Arduino */


/* 
  Title : Interfacing Ultrasonic Sensor with Arduino
  Description: This program measures distance using an HC-SR04 ultrasonic sensor
  and displays it on the Serial Monitor.
*/

// Define pins for trigger and echo
int trigpin = 10;   // Pin connected to the Trigger pin of the ultrasonic sensor
int echopin = 9;    // Pin connected to the Echo pin of the ultrasonic sensor

// Variables to store time and distance
long time;          // Duration of the pulse (in microseconds)
int distance;       // Calculated distance (in centimeters)

void setup()
{
  // Set pin modes
  pinMode(trigpin, OUTPUT);   // Set trigger pin as output
  pinMode(echopin, INPUT);    // Set echo pin as input

  // Initialize serial communication at 9600 baud rate
  Serial.begin(9600); 
}

void loop()
{
  // Ensure trigger pin is LOW initially to start clean pulse
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2); // Small delay to stabilize sensor

  // Send a 10 microsecond HIGH pulse to trigger ultrasonic burst
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigpin, LOW);

  // Measure the duration of the pulse received back at the echo pin
  time = pulseIn(echopin, HIGH);

  // Calculate distance:
  // - Sound speed in air is approximately 0.034 cm/us
  // - Divide by 2 because the pulse travels to the object and back
  distance = time * 0.034 / 2;

  // Output distance to Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Optional small delay before next reading (can adjust as needed)
  delay(100); 
}

