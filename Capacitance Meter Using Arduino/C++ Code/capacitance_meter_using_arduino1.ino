// C++ code
// Author: Diganto
// CE, KUET
// Title: Capacitance Meter Using Arduino

// --- Pin Configuration ---
const int ANALOG_PIN     = A0;  // Analog input pin to measure capacitor voltage
const int CHARGE_PIN     = 8;   // Pin to charge the capacitor
const int DISCHARGE_PIN  = 9;   // Pin to discharge the capacitor

// --- Resistor used in series with the capacitor (Ohms) ---
const int RESISTOR_OHMS  = 1000;

// --- Timing variables ---
unsigned long startTime = 0;
unsigned long chargeDuration = 0;

// --- Capacitance values ---
float capacitanceMicroF = 0.0;
float capacitanceNanoF  = 0.0;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Set charge pin to OUTPUT and LOW initially
  pinMode(CHARGE_PIN, OUTPUT);
  digitalWrite(CHARGE_PIN, LOW);
}

void loop() {
  // Step 1: Begin charging the capacitor
  digitalWrite(CHARGE_PIN, HIGH);
  startTime = millis();

  // Wait until capacitor voltage reaches 63% of supply voltage (~610 out of 1023)
  while (analogRead(ANALOG_PIN) < 610) {
    // Do nothing (wait for voltage to rise)
  }

  // Step 2: Stop charging and calculate time
  chargeDuration = millis() - startTime;

  // Step 3: Calculate capacitance in microfarads
  capacitanceMicroF = ((float)chargeDuration / RESISTOR_OHMS) * 1000.0;

  // Display timing result
  Serial.print(chargeDuration);
  Serial.println(" ms");

  // Step 4: Display result in appropriate unit
  if (capacitanceMicroF >= 1.0) {
    Serial.print((long)capacitanceMicroF);
    Serial.println(" microFarads");
  } else {
    capacitanceNanoF = capacitanceMicroF * 1000.0;
    Serial.print((long)capacitanceNanoF);
    Serial.println(" nanoFarads");
  }

  delay(500);  // Wait before discharging

  // Step 5: Discharge the capacitor fully before next reading
  dischargeCapacitor();
}

// --- Function to discharge capacitor safely ---
void dischargeCapacitor() {
  digitalWrite(CHARGE_PIN, LOW);        // Stop charging
  pinMode(DISCHARGE_PIN, OUTPUT);       // Enable discharge path
  digitalWrite(DISCHARGE_PIN, LOW);     // Discharge to GND

  // Wait until capacitor voltage drops near zero
  while (analogRead(ANALOG_PIN) > 0) {
    // Wait until fully discharged
  }

  pinMode(DISCHARGE_PIN, INPUT);        // Set back to high impedance
}
