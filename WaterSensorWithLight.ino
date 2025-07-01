void setup() {
  Serial.begin(9600); // Initialize serial communication for debugging

  pinMode(lowOutput, OUTPUT);
  pinMode(mediumOutput, OUTPUT);
  pinMode(highOutput, OUTPUT);

  digitalWrite(lowOutput, LOW);
  digitalWrite(mediumOutput, LOW);
  digitalWrite(highOutput, LOW);

  Serial.println("Water Level Monitor Started.");
  Serial.println("----------------------------");
  Serial.println("Use Serial Monitor to calibrate your sensor.");
  Serial.println("Observe 'Current Sensor Value' for DRY, LOW, MEDIUM, HIGH water levels.");
  Serial.println("Then, update the 'YOUR_...' thresholds in the code accordingly.");
  Serial.println("----------------------------");
}

void loop() {
  int sensorValue = analogRead(sensorPin); // Read the analog value from the water sensor

  Serial.print("Current Sensor Value: ");
  Serial.print(sensorValue);
  Serial.print(" | Water Level: ");

  const int YOUR_LOW_THRESHOLD    = 250; 
  const int YOUR_MEDIUM_THRESHOLD = 400;
  const int YOUR_HIGH_THRESHOLD   = 600; 


  if (sensorValue >= YOUR_HIGH_THRESHOLD) {
    // Water is at a high level
    digitalWrite(highOutput, HIGH);   // Green LED ON
    digitalWrite(mediumOutput, LOW);  // Yellow LED OFF
    digitalWrite(lowOutput, LOW);     // Red LED OFF
    Serial.println("HIGH");
  }
  else if (sensorValue >= YOUR_MEDIUM_THRESHOLD) {
    // Water is at a medium level (but not high)
    digitalWrite(highOutput, LOW);    // Green LED OFF
    digitalWrite(mediumOutput, HIGH); // Yellow LED ON
    digitalWrite(lowOutput, LOW);     // Red LED OFF
    Serial.println("MEDIUM");
  }
  else if (sensorValue >= YOUR_LOW_THRESHOLD) {
    // Water is at a low level (but not medium or high)
    digitalWrite(highOutput, LOW);    // Green LED OFF
    digitalWrite(mediumOutput, LOW);  // Yellow LED OFF
    digitalWrite(lowOutput, HIGH);    // Red LED ON
    Serial.println("LOW");
  }
  else {
    // Water is very low or completely dry
    digitalWrite(highOutput, LOW);    // Green LED OFF
    digitalWrite(mediumOutput, LOW);  // Yellow LED OFF
    digitalWrite(lowOutput, LOW);     // Red LED OFF (all LEDs off)
    Serial.println("EMPTY / Very Low");
  }

  delay(200); // Small delay to stabilize readings and avoid flickering
}