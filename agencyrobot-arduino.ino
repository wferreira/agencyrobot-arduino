
int motor1_enablePin = 11; //pwm
int motor1_in1Pin = 13;
int motor1_in2Pin = 12;
 
int motor2_enablePin = 10; //pwm
int motor2_in1Pin = 8;
int motor2_in2Pin = 7;
 
void setup()
{
  //on initialise les pins du moteur 1
  pinMode(motor1_in1Pin, OUTPUT);
  pinMode(motor1_in2Pin, OUTPUT);
  pinMode(motor1_enablePin, OUTPUT);
 
  //on initialise les pins du moteur 2
  pinMode(motor2_in1Pin, OUTPUT);
  pinMode(motor2_in2Pin, OUTPUT);
  pinMode(motor2_enablePin, OUTPUT);

  Serial.begin(9600); 
  delay(2000);
 
  Serial.println("Robot car is ready !");
    
}

char command;

void loop()
{

  if(Serial.available()){
      char newCommand = Serial.read();
      Serial.print("You typed: " );
      Serial.println(command);
      
      if (newCommand != command){
        command = newCommand;
        Stop();
        delay(500);
      }
  }

  switch (command) {
    case 'F':
      Forward(255);
      break;
    case 'B':
      Backward(255);
      break;
    case 'R':
      TurnRight(255);
      break;
    case 'L':
      TurnLeft(255);
      break;
    case 'S':
      Stop();
      break;
  }
  
}

void Stop(){
  SetMotorsRight(0, true);
  SetMotorsLeft(0, false);
}

void Forward(int speed){
  SetMotorsRight(speed, true);
  SetMotorsLeft(speed, false);
}

void Backward(int speed){
  SetMotorsRight(speed, false);
  SetMotorsLeft(speed, true);
}

void TurnRight(int speed){
  SetMotorsRight(speed, false);
  SetMotorsLeft(speed, false);
}

void TurnLeft(int speed){
  SetMotorsRight(speed, true);
  SetMotorsLeft(speed, true);
}
 
void SetMotorsRight(int speed, boolean reverse)
{
  analogWrite(motor1_enablePin, speed);
  digitalWrite(motor1_in1Pin, ! reverse);
  digitalWrite(motor1_in2Pin, reverse);
}
 
void SetMotorsLeft(int speed, boolean reverse)
{
  analogWrite(motor2_enablePin, speed);
  digitalWrite(motor2_in1Pin, ! reverse);
  digitalWrite(motor2_in2Pin, reverse);
}
