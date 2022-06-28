  #include <Servo.h>.
Servo MyRobotLeftHand;
Servo MyRobotLeftHandArm;
Servo MyRobotRightHand;
Servo MyRobotRightHandArm;

Servo Head;

const int LEFT_MOTOR_S1 = 7;
const int LEFT_MOTOR_S2 = 8;
const int RIGHT_MOTOR_S1 = 9;
const int RIGHT_MOTOR_S2 = 10;

const int trigPin = 12;
const int echoPin = 11;

long duration;
int distance;

void setup() {  
Serial.begin(9600);
Head.attach(2);
MyRobotLeftHand.attach(3);
MyRobotLeftHandArm.attach(4);
MyRobotRightHand.attach(5);
MyRobotRightHandArm.attach(6);

pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT);

 pinMode(LEFT_MOTOR_S1, OUTPUT);
  pinMode(LEFT_MOTOR_S2, OUTPUT);
   pinMode(RIGHT_MOTOR_S1, OUTPUT);
   pinMode(RIGHT_MOTOR_S2, OUTPUT);
}
void Automatic()
{
  //First activity
  for(int a=0;a<=180;a++)
  {
  MyRobotRightHand.write(a);
  MyRobotLeftHand.write(a);
  delay(30);
  }
  for(int a=180;a>0;a--)
  {
   MyRobotRightHand.write(a);
   MyRobotLeftHand.write(a);
   delay(30); 
  }
  //Second activity
   for(int a=0;a<=180;a++)
  {
  MyRobotRightHand.write(a);
  delay(30);
  }
  for(int a=180;a>0;a--)
  {
   MyRobotRightHand.write(a);
   delay(30); 
  }
  //Third activity
   for(int a=0;a<=180;a++)
  {
  MyRobotLeftHand.write(a);
  delay(30);
  }
  for(int a=180;a>0;a--)
  {
   MyRobotLeftHand.write(a);
   delay(30); 
  }
  //Fourth activity
   for(int a=80;a<=170;a++)
  {
  MyRobotRightHandArm.write(a);
  MyRobotLeftHandArm.write(a);
  delay(30);
  }
  for(int a=170;a>80;a--)
  {
   MyRobotRightHandArm.write(a);
   MyRobotLeftHandArm.write(a);
   delay(30); 
  }
  //Fouth activity
   for(int a=80;a<=170;a++)
  {
  MyRobotRightHandArm.write(a);
  
  delay(30);
  }
  for(int a=170;a>80;a--)
  {
   MyRobotRightHandArm.write(a);

   delay(30); 
  }
  //Fifth activity
   for(int a=80;a<=170;a++)
  {
  
  MyRobotLeftHandArm.write(a);
  delay(30);
  }
  for(int a=170;a>80;a--)
  {
  
   MyRobotLeftHandArm.write(a);
   delay(30); 
  }
}



void loop() {

Automatic();
 /*digitalWrite(trigPin, LOW);
delayMicroseconds(2);

digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);

distance= duration*0.034/2;
Serial.println(distance);

/*if (distance<=50)
{
   for(int a=0;a<=90;a++)
  {
  Head.write(a);
  delay(30);
  }
  if(distance<=50)
  {
     for(int a=0;a<=90;a++)
  {
  Head.write(a);
  delay(30);
  }
  }}
  else
 digitalWrite(LEFT_MOTOR_S1,HIGH);
 digitalWrite(RIGHT_MOTOR_S2,HIGH);
 delay(500);
*/

}

 
 
