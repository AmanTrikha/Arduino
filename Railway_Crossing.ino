int a = 2;  
int b = 3;  
int c = 4;  
int d = 5;  
int e = 6;  
int f = 8;  
int g = 9;

int redLED=0;
int yellowLED=1;
int greenLED=10;

int motorF=11;
int motorR=12;

void setup()
{               
  pinMode(a, OUTPUT); 
  pinMode(b, OUTPUT); 
  pinMode(c, OUTPUT); 
  pinMode(d, OUTPUT); 
  pinMode(e, OUTPUT); 
  pinMode(f, OUTPUT);  
  pinMode(g, OUTPUT);
  
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  
  pinMode(motorF, OUTPUT);
  pinMode(motorR, OUTPUT);  
}

void TrafficGO()
  {
  digitalWrite(greenLED,HIGH);
  delay(500);
  }
 void TrafficSTOP()
  {
  digitalWrite(redLED,HIGH);
  delay(500);
  }
  void motorF()
  {
    digitalWrite(motorF,HIGH);
    digitalWrite(motorR,LOW);
    delay(50);
  }
 void motorR()
  {
    digitalWrite(motorR,HIGH);
    digitalWrite(motorF,LOW);
    delay(50);
  }
void turnon()
{
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
}

void turnoff()
{
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
}


void loop ()
{
  
  while(x>0)
  
  turnon();
   digitalWrite(e,HIGH);
    delay(1000);
 turnon();
    delay(1000);
 turnoff();
    digitalWrite(f,LOW);
    digitalWrite(g,LOW);
    digitalWrite(c,LOW);
    delay(1000);
  turnon();
    digitalWrite(g,HIGH);
    delay(1000);
  turnon();
    digitalWrite(e,HIGH);
    digitalWrite(g,HIGH);
    delay(1000);
  turnon();
    digitalWrite(f,HIGH);
    digitalWrite(e,HIGH);
    digitalWrite(d,HIGH);
    delay(1000);
  turnon();
    digitalWrite(a,HIGH);
    digitalWrite(e,HIGH);
    delay(1000);
 turnon();
    digitalWrite(a,HIGH);
    digitalWrite(c,HIGH);
    delay(1000);
 turnoff();
    digitalWrite(g,LOW);
    digitalWrite(c,LOW);
    delay(1000);
 turnon();
  digitalWrite(b,HIGH);
  delay(1000);
    
  }
 
