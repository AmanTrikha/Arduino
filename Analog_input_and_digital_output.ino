int analogInPin = A0;
int out = 13;
int sensorValue=0;

void setup()
{
   Serial.begin(9600);
   pinMode(out,OUTPUT);
}
 void loop()
 {
 sensorValue = analogRead(analogInPin);
 Serial.print("sensor=");
 Serial.println(sensorValue);
 delay(500);

 if(sensorValue>700)
 {
    digitalWrite(out,1);
 }
    else
    {
    digitalWrite(out,0);
    }
}
    
