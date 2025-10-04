// Variables
const int redLED = 13;
const int greenLED = 7;
const int Button = 9;

bool ledState = HIGH;
bool lastButtonState = HIGH;

void setup()
{
  Serial.begin(9600);

  // pinModes
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(Button, INPUT_PULLUP);

  // initialState
  digitalWrite(redLED, HIGH);
  digitalWrite(greenLED,LOW);
}

void loop()
{
  bool currentState = debounce(Button);

  // Detect when button goes from HIGH → LOW (pressed)
  if (lastButtonState == HIGH && currentState == LOW) {
    toggleLeds();
  }

  lastButtonState = currentState;
  Serial.println(lastButtonState);
}

void toggleLeds() {
  if (ledState == HIGH) {
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, HIGH);
    ledState = LOW;
  }
  else {
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);
    ledState = HIGH;
  }
}

// Read the push button when it is HIGH
bool debounce(int pin) {
  boolean state;
  boolean previousState = digitalRead(pin);

  for (int i = 0; i < 10; i++) {
    delay(1);
    state = digitalRead(pin);
    if (state != previousState) {
      i = 0;
      previousState = state;
    }
  }
  return state;
}


