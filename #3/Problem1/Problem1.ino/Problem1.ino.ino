int x, y; // variables to store the numbers to be added
int idx;  // the index to navigate our input string
char inputstr[4]; // the input string (increased size for larger numbers)

// Function declarations
int getNumber();
void clearSerialBuffer();

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Serial.println();

  Serial.println("Enter the first number: ");
  x = getNumber();
  clearSerialBuffer();
  Serial.println(x);
  
  Serial.println("Enter the second number: ");
  y = getNumber();
  clearSerialBuffer();
  Serial.println(y);
  
  Serial.println("The result is: ");
  Serial.println(x + y);

  Serial.println("=================");

}

int getNumber(){
  idx = 0;
  while(true){
    if(Serial.available()){
      char ch = Serial.read();
      if(ch == '\n' || ch == '\r'){  // Stop at Enter/newline
        break;
      }
      if(ch >= '0' && ch <= '9'){  // Only accept digits
        if(idx < 4) {  // Keep one space for null terminator
          inputstr[idx++] = ch;
        }
      }
    }
  }
  inputstr[idx] = '\0';
  return atoi(inputstr);
}

void clearSerialBuffer() {
  while (Serial.available() > 0) {
    Serial.read();
  }
}