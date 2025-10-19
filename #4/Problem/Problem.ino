const int LED = 13;
const int buzzerPin = 3;
bool LedMode = false;

bool exceedThree(float voltageValue) {
  if (voltageValue > 3) { return true; }
  return false;
}

bool belowLimit(float voltageValue) {
  if (voltageValue < 2.5) { return true; }
  return false;
}

void turnOff() {
  digitalWrite(buzzerPin, LOW);
  digitalWrite(LED, LOW);
}

void turnOn() {
  digitalWrite(buzzerPin, HIGH);
  digitalWrite(LED, HIGH);
}

void switchMode(float voltageValue) {
  if (LedMode && belowLimit(voltageValue)) {
    LedMode = false;
    turnOff();
  }
  else if (!LedMode && exceedThree(voltageValue)) {
    LedMode = true;
    turnOn();
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(A0, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  float voltageValue = analogRead(A0);

  Serial.println(voltageValue);

  switchMode(voltageValue);

}
