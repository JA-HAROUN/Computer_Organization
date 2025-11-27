const int sensor = A5;
const int led = 3;
const int buzzer = 4;
const float MAX_HEAT = 30.0;

void setup()
{
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  float sensorValue = analogRead(sensor);

  float temperature = sensorValue * (5.0 / 1023.0) * 100.0;
  
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");
  
  if (temperature > MAX_HEAT)
  {
    digitalWrite(led, HIGH);
    tone(buzzer, 1000);
  }
  else
  {
    digitalWrite(led, LOW);
    noTone(buzzer);
  }
  delay(1000);
}