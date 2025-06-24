// Thermometer Project with ATtiny85
// Author: Diganto (refactored for clarity)
// Department: Civil Engineering, KUET
// Description: This program reads temperature using an analog sensor,
// converts it to Fahrenheit, and controls an LED (on PB0) based on temperature ranges.

#define LED_PIN 0     // Output pin (PB0) to drive LED
#define SENSOR_PIN A1 // Analog input pin (PB2 / A1 on ATtiny85)

double temperatureF = 0.0; // Variable to store converted temperature in Fahrenheit

void setup() {
  pinMode(LED_PIN, OUTPUT);  // Set LED pin as output
}

void loop() {
  // Read the analog value from the temperature sensor
  int rawValue = analogRead(SENSOR_PIN);

  // Convert raw ADC value to voltage (assuming 5V reference)
  double voltage = (double) rawValue * 5.0 / 1024.0;

  // Convert voltage to Celsius (LM35-like sensor: 10mV per °C, minus 0.5V offset)
  double temperatureC = (voltage - 0.5) * 100.0;

  // Convert Celsius to Fahrenheit
  temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;

  // Control LED based on temperature range
  if (temperatureF >= 70 && temperatureF <= 116) {
    // Medium range temperature: blink LED every 500 ms
    blinkLED(500);
  }
  else if (temperatureF >= -40 && temperatureF <= 68) {
    // Low temperature: slow blink (1 second)
    blinkLED(1000);
  }
  else if (temperatureF >= 123 && temperatureF <= 238) {
    // High temperature: fast blink (100 ms)
    blinkLED(100);
  }
  else {
    // Out of range: keep LED on
    digitalWrite(LED_PIN, HIGH);
  }
}

// Helper function to blink LED with a given delay
void blinkLED(int delayTime) {
  digitalWrite(LED_PIN, HIGH);
  delay(delayTime);
  digitalWrite(LED_PIN, LOW);
  delay(delayTime);
}
