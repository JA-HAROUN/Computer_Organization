/*
@ x: the independant variable input for the function
@ y: the dependant variable output for the function
*/
int x = 0;
float y;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  y = sin(x * PI / 180.0) * 10;

  x += 1;
  x %= 360;

  Serial.println(y);

  delay(50);
}