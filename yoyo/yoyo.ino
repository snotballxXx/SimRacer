int Motor1PositionInput = A0;
int Motor2PositionInput = A1;
int Motor3PositionInput = A2;

int Motor1Direction = 3;
int Motor2Direction = 5;
int Motor3Direction = 7;

int Motor1PWM = 9;
int Motor2PWM = 10;
int Motor3PWM = 11;

int Motor1CurrentDirection = 0;
int Motor2CurrentDirection = 0;
int Motor3CurrentDirection = 0;

int MotorSpeed = 30;
int MaxPosition = 850;
int MinPosition = 150;
int MaxHardStop = 900;
int MinHardStop = 100;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(Motor1Direction, OUTPUT);
  pinMode(Motor2Direction, OUTPUT);
  pinMode(Motor3Direction, OUTPUT);

  pinMode(Motor1PWM, OUTPUT);  
  pinMode(Motor2PWM, OUTPUT);  
  pinMode(Motor3PWM, OUTPUT);  
 
  digitalWrite(Motor1Direction, Motor1CurrentDirection);
  analogWrite(Motor1PWM, MotorSpeed);
 
  digitalWrite(Motor2Direction, Motor2CurrentDirection);  
  analogWrite(Motor2PWM, MotorSpeed);
  digitalWrite(Motor3Direction, Motor3CurrentDirection);
  analogWrite(Motor3PWM, MotorSpeed);
}



void loop() {
  // put your main code here, to run repeatedly:
  bool changeDirection = directionChangeRequired(Motor1CurrentDirection, readPosition(Motor1PositionInput, Motor1PWM));
  if (changeDirection) {    
    Motor1CurrentDirection = Motor1CurrentDirection == 1 ? 0 : 1;
    digitalWrite(Motor1Direction, Motor1CurrentDirection);
  }

  changeDirection = directionChangeRequired(Motor2CurrentDirection, readPosition(Motor2PositionInput, Motor2PWM));
  if (changeDirection) {    
    Motor2CurrentDirection = Motor2CurrentDirection == 1 ? 0 : 1;
    digitalWrite(Motor2Direction, Motor2CurrentDirection);
  }

  changeDirection = directionChangeRequired(Motor3CurrentDirection, readPosition(Motor3PositionInput, Motor3PWM));
  if (changeDirection) {    
    Motor3CurrentDirection = Motor3CurrentDirection == 1 ? 0 : 1;
    digitalWrite(Motor3Direction, Motor3CurrentDirection);
  }
}

int readPosition(int motor, int pwm) {

  int value = analogRead(motor);

  if (value > MaxHardStop || value < MinHardStop) {
    Serial.print("Stopped due to direction error for motor on pwm ");
    Serial.println(pwm);
    analogWrite(pwm, 0);
  }
 
  return value;
}

bool directionChangeRequired(bool current, int position) {

  if (current == 0 && position > MaxPosition)
    return true;

  if (current == 1 && position < MinPosition)
    return true;  
   
  return false;
}
