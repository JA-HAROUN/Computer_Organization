/*
@ x: the independant variable input for the function
@ y: the dependant variable output for the function
*/
float x = 0;
float y;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  y = sin(x * PI / 180.0) * 5;

  x += 0.5;
  if (x == 360.0) {x = 0.0;}

  Serial.println(y);

  delay(25);
}