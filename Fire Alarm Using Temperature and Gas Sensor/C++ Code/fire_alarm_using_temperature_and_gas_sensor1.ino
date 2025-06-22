
// Owner : Tanvir Hossain Diganto
// CE, KUET

/* 
  Title: Fire Alarm Using Temperature and Gas Sensor
  Description: This program reads data from a temperature sensor and gas sensor.
  If temperature exceeds 80°C, it lights an LED. 
  If gas concentration exceeds threshold, it activates a buzzer.
*/

// Variables for temperature calculation
float temp;        // Calculated temperature in degree Celsius
float vout;        // Raw analog value from temperature sensor
float vout1;       // Converted voltage value from raw analog reading

// Pin assignments
int LED = 13;      // LED pin (indicator for high temperature)
int gassensor;     // Variable to store gas sensor analog value
int buzzer = 7;    // Buzzer pin (indicator for gas detection)

void setup()
{
  // Set sensor pins as input
  pinMode(A0, INPUT);       // Gas sensor analog pin
  pinMode(A1, INPUT);       // Temperature sensor analog pin
  
  // Set output devices
  pinMode(LED, OUTPUT);     // LED pin as output
  pinMode(buzzer, OUTPUT);  // Buzzer pin as output
  
  // Start serial communication for monitoring values
  Serial.begin(9600);
}

void loop()
{
  // Read analog value from temperature sensor (A1)
  vout = analogRead(A1);

  // Convert analog reading to voltage (in millivolts)
  // (vout / 1023) gives fraction of Vref (assumed 5V)
  // Multiply by 5000 to convert to millivolts
  vout1 = (vout / 1023.0) * 5000;  

  // Calculate temperature in Celsius
  // LM35 gives 10mV per degree Celsius with 500mV offset at 0°C
  temp = (vout1 - 500) / 10; 

  // Read analog value from gas sensor (A0)
  gassensor = analogRead(A0);

  // Check if temperature is greater than or equal to 80°C
  // If so, turn on LED; else turn off LED
  if (temp >= 80) {
    digitalWrite(LED, HIGH);
  } 
  else {
    digitalWrite(LED, LOW);
  }

  // Check if gas sensor value exceeds threshold (here 100)
  // If so, turn on buzzer; else turn off buzzer
  if (gassensor >= 100) {
    digitalWrite(buzzer, HIGH);
  } 
  else {
    digitalWrite(buzzer, LOW);
  }

  // Print temperature and gas sensor reading on Serial Monitor
  Serial.print("In Degree: ");  // Label for temperature
  Serial.print(temp);           // Print temperature value
  
  Serial.print("\t");           // Tab space
  
  Serial.print("Gas Sensor: "); // Label for gas sensor
  Serial.print(gassensor);      // Print gas sensor value
  
  Serial.println();             // Newline for next reading
  
  // Delay for readability (1 second between readings)
  delay(1000);
}
