/*
 Name:		Sketch_test.ino
 Created:	5/15/2022 7:35:32 PM
 Author:	Ahmed
*/

const int buttonPin = 9;
const int ledPin = LED_BUILTIN;

int x;
bool buttonState = false;
bool lastButtonState = false;
bool ledState = false;

// the setup function runs once when you press reset or power the board
void setup() {
	x = 20;

	Serial.begin(115200);

	pinMode(ledPin, OUTPUT);
	pinMode(buttonPin, INPUT);
	
	lastButtonState = digitalRead(buttonPin);
	buttonState = lastButtonState;
	ledState = buttonState;
	digitalWrite(ledPin, buttonState);
}

// the loop function runs over and over again until power down or reset
void loop() {
	buttonState = digitalRead(buttonPin);

	if (buttonState != lastButtonState) {
		ledState = !ledState;
		lastButtonState = buttonState;
		digitalWrite(ledPin, ledState);
		Serial.print("Led state = ");
		Serial.println(ledState);
	}

	x++;
	delay(10000);
}
