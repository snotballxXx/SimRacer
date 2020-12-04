
int val = 0;  // variable to store the value read
int speed = 60;

int min1, max1;
int min2, max2;
int min3, max3;
void setup() {
  Serial.begin(9600);           //  setup serial

  min1 = min2 = min3 = 1024;
  max1 = max2 = max3 = 0;

pinMode(9, OUTPUT);
pinMode(10, OUTPUT);
pinMode(11, OUTPUT);
  analogWrite(9, speed);
  analogWrite(10, speed);
  analogWrite(11, speed);
}

void loop() {
  val = analogRead(A0);  // read the input pin

  min1 = min(min1, val);
  max1 = max(max1, val);
  Serial.print("M1 - ");
  Serial.print(min1);    
  Serial.print(" ");             
  Serial.print(max1);         


  val = analogRead(A1);  // read the input pin
  min2 = min(min2, val);
  max2 = max(max2, val);
  Serial.print(", M2 - ");
  Serial.print(min2);    
  Serial.print(" ");             
  Serial.print(max2);  


  val = analogRead(A2);  // read the input pin
  min3 = min(min3, val);
  max3 = max(max3, val);
  Serial.print(", M3 - ");
    Serial.print(min3);    
  Serial.print(" ");             
  Serial.println(max3);  
}
