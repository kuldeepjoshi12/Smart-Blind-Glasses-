/*
  Smart Blind Glasses
  -------------------
  Educational Assistive Technology Prototype

  Components:
  - Arduino Nano
  - HC-SR04 Ultrasonic Sensor
  - Piezo Buzzer
  - Vibration Motor
  - Transistor/MOSFET for motor control

  Ultrasonic Sensor:
  TRIG -> D9
  ECHO -> D10

  Buzzer:
  + -> D6
  - -> GND

  Vibration Motor:
  Control -> D5 through transistor/MOSFET
*/

#define TRIG_PIN 9
#define ECHO_PIN 10

#define BUZZER_PIN 6
#define VIBRATION_PIN 5

// Distance thresholds in centimeters
#define VERY_CLOSE 50
#define CLOSE_DISTANCE 100
#define WARNING_DISTANCE 150

long duration;
float distance;

// --------------------------------------------------
// Setup
// --------------------------------------------------

void setup() {

  Serial.begin(9600);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(VIBRATION_PIN, OUTPUT);

  digitalWrite(TRIG_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);
  digitalWrite(VIBRATION_PIN, LOW);

  Serial.println("================================");
  Serial.println("      SMART BLIND GLASSES");
  Serial.println("================================");
  Serial.println("System Ready");
}


// --------------------------------------------------
// Main Loop
// --------------------------------------------------

void loop() {

  distance = getDistance();

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Very close obstacle
  if (distance > 0 && distance <= VERY_CLOSE) {

    digitalWrite(VIBRATION_PIN, HIGH);

    // Fast warning beep
    tone(BUZZER_PIN, 2000);
    delay(100);

    noTone(BUZZER_PIN);
    delay(100);
  }

  // Close obstacle
  else if (distance > VERY_CLOSE && distance <= CLOSE_DISTANCE) {

    digitalWrite(VIBRATION_PIN, HIGH);

    tone(BUZZER_PIN, 1500);
    delay(150);

    noTone(BUZZER_PIN);
    delay(300);
  }

  // Warning distance
  else if (distance > CLOSE_DISTANCE && distance <= WARNING_DISTANCE) {

    digitalWrite(VIBRATION_PIN, LOW);

    tone(BUZZER_PIN, 1000);
    delay(100);

    noTone(BUZZER_PIN);
    delay(600);
  }

  // No nearby obstacle
  else {

    digitalWrite(VIBRATION_PIN, LOW);
    noTone(BUZZER_PIN);

    delay(100);
  }
}


// --------------------------------------------------
// Measure Distance Using HC-SR04
// --------------------------------------------------

float getDistance() {

  // Send ultrasonic pulse
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  // Read echo
  duration = pulseIn(ECHO_PIN, HIGH, 30000);

  // No echo received
  if (duration == 0) {
    return -1;
  }

  // Convert time to distance
  float calculatedDistance =
    (duration * 0.0343) / 2;

  return calculatedDistance;
}
