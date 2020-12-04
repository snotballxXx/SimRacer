int analogPin = A0; // potentiometer wiper (middle terminal) connected to analog pin 0
                    // outside leads to ground and +5V
int val = 0;  // variable to store the value read
int ledPin = 9;    // LED connected to digital pin 9
int speed = 40;
void setup() {
  Serial.begin(9600);           //  setup serial
}

void loop() {
  val = analogRead(A0);  // read the input pin
  Serial.print("M1 - ");
  Serial.print(val);          // debug value


  val = analogRead(A1);  // read the input pin
  Serial.print(", M2 - ");
  Serial.print(val);  


  val = analogRead(A2);  // read the input pin
  //
  Serial.print(", M3 - ");
  Serial.println(val);  
  delay(500);
}
