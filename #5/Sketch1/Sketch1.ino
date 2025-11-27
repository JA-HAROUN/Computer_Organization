int x;
int buttonPin = 2;
bool previous = HIGH;
bool ledState = LOW;
void setup() {
    Serial.begin(115200);
    pinMode(buttonPin, INPUT_PULLUP);
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, ledState);
    x = 20;
}

boolean debounce(int pin) {
    boolean state;
    boolean previousState;
    previousState = digitalRead(pin);
    for (int i = 0; i < 10; i++) {
        delay(10);
        state = digitalRead(pin);
        if (state != previousState) {
            i = 0;
            previousState = state;
        }
    }
    return state;
}

void loop() {
    ledState = digitalRead(LED_BUILTIN);

    bool current = debounce(buttonPin);

    if (current != previous) {
        ledState = !ledState;
        digitalWrite(LED_BUILTIN, ledState);
        Serial.print("Led State: ");
        Serial.println(ledState);
    }

    x++;

    previous = current;

    Serial.print("Led State: ");
    Serial.println(ledState);

    delay(1000);
}
