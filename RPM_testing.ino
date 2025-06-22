volatile unsigned int pulseCount = 0;
unsigned long lastMillis = 0;
float rpm = 0.0;

void countPulse() {
  pulseCount++;
}

void setup() {
  pinMode(2, INPUT_PULLUP);  // Signal from speed pin
  attachInterrupt(digitalPinToInterrupt(2), countPulse, RISING);
  Serial.begin(38400);
}

void loop() {
  unsigned long currentMillis = millis();

  // Calculate every 1 second
  if (currentMillis - lastMillis >= 1000) {
    noInterrupts(); // Stop interrupt while reading shared variable
    unsigned int count = pulseCount;
    pulseCount = 0;
    interrupts();

    rpm = count * 5.0;  // Since 12 pulses per mechanical revolution

    Serial.print("RPM: ");
    Serial.println(rpm);

    lastMillis = currentMillis;
  }
}