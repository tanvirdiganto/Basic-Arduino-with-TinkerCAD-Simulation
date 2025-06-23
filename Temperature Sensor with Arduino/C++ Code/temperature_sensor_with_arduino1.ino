// C++ code
// Owner: Diganto
// CE, KUET
// Title: Temperature Sensor with Arduino

// Analog pin where temperature sensor is connected
const int TMP_PIN = A0;

// Variables to store readings
float analogReading;
float voltage;
float tempCelsius;
float tempFahrenheit;

void setup() {
  // Set TMP_PIN as input (optional, as analogRead handles this)
  pinMode(TMP_PIN, INPUT);

  // Initialize serial communication for output
  Serial.begin(9600);
}

void loop() {
  // Read analog value from temperature sensor (0 - 1023)
  analogReading = analogRead(TMP_PIN);

  // Print raw analog value for reference
  Serial.print("\n\nAnalog reading: ");
  Serial.println(analogReading);

  // Convert analog value to voltage
  // Formula: voltage = (analogReading * 5V) / 1024
  // Arduino ADC gives 0-5V as 0-1023 values
  voltage = (analogReading * 5.0) / 1024.0;

  // Print calculated voltage
  Serial.print("Voltage reading: ");
  Serial.println(voltage);

  // Convert voltage to temperature in Celsius
  // Assuming LM35/ similar: 10mV per °C with 0.5V offset
  // Formula: (Vout - 0.5) * 100
  tempCelsius = 100.0 * (voltage - 0.5);

  // Print temperature in Celsius
  Serial.print("Celsius reading: ");
  Serial.print(tempCelsius);
  Serial.println(" C");

  // Convert Celsius to Fahrenheit
  // Formula: °F = (°C × 9/5) + 32
  tempFahrenheit = (tempCelsius * 9.0 / 5.0) + 32.0;

  // Print temperature in Fahrenheit
  Serial.print("Fahrenheit reading: ");
  Serial.print(tempFahrenheit);
  Serial.println(" F");

  // Wait for 3 seconds before next reading
  delay(3000);
}

