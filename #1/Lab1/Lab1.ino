// Define Variables
const int timeUnit = 500;
const int dotDuration = timeUnit, interElementGap = timeUnit;
const int dashDuration = 3*timeUnit, shortGap = 3*timeUnit;
const int mediumGap = 7*timeUnit;

void setup() {
  // put your setup code here, to run once:
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  // Ground
  digitalWrite(8, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:

  /*
    S = ...
    O = ---
  */

  // S character
  for(int i=0; i<3; i++) {
    digitalWrite(7, HIGH);
    delay(dotDuration);
    digitalWrite(7, LOW);

    if (i != 2) {
      delay(interElementGap);
    }
  }

  // Gap Between Letters
  delay(shortGap);

  // O character
  for(int j=0; j<3; j++) {
    digitalWrite(7, HIGH);
    delay(dashDuration);
    digitalWrite(7, LOW);

    if (j != 2) {
      delay(interElementGap);
    }
  }

  // Gap Between Letters
  delay(shortGap);

  // S character
  for(int i=0; i<3; i++) {
    digitalWrite(7, HIGH);
    delay(dotDuration);
    digitalWrite(7, LOW);

    if (i != 2) {
      delay(interElementGap);
    }
  }

  // Gap Between Words
  delay(mediumGap);

}
