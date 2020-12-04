//Motor 1 = 1
//Motor 2 = 2
//Motor 3 = 3
//change this value to change axis
const int MotorNumber = 1; //1, 2 or 3

const int MotorPositionInput = MotorNumber - 1;
const int MotorPWM = MotorNumber + 8;

const int MotorSpeed = 80;

const int homePosition = 600;
const int homeRangePlusMinus = 4;
const int Max = homePosition + homeRangePlusMinus;
const int Min = homePosition - homeRangePlusMinus;

void setup() {
  Serial.begin(9600);

  pinMode(MotorPWM, OUTPUT);  
 
  analogWrite(MotorPWM, MotorSpeed);

  delay(250);
}

void loop() {
  int value = analogRead(MotorPositionInput);
  if (value > Min && value < Max) {
    Serial.print("Homed on axis ");
    Serial.println(MotorNumber);
    analogWrite(MotorPWM, 0);
  }
}
