int Motor1PositionInput = A0;
int Motor2PositionInput = A1;
int Motor3PositionInput = A2;

int Motor1PWM = 9;
int Motor2PWM = 10;
int Motor3PWM = 11;

int MotorSpeed = 60;

int homePosition = 600;
int homeRangePlusMinus = 4;
int Max = homePosition + homeRangePlusMinus;
int Min = homePosition - homeRangePlusMinus;

void setup() {
  Serial.begin(9600);

  pinMode(Motor1PWM, OUTPUT);  
  pinMode(Motor2PWM, OUTPUT);  
  pinMode(Motor3PWM, OUTPUT);  
 
  analogWrite(Motor1PWM, MotorSpeed);
  analogWrite(Motor2PWM, MotorSpeed);
  analogWrite(Motor3PWM, MotorSpeed);
}



void loop() {
  // put your main code here, to run repeatedly:
  readPosition(Motor1PositionInput, Motor1PWM);
  readPosition(Motor2PositionInput, Motor2PWM);
  readPosition(Motor3PositionInput, Motor3PWM);
}

int readPosition(int motor, int pwm) {

  int value = analogRead(motor);

  if (value > Min && value < Max) {
    Serial.print("Homed on ");
    Serial.println(pwm);
    analogWrite(pwm, 0);
  }
 
  return value;
}
