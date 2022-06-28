int sensorPin = A0;
int sensorlimit=448; 
int led_pin=8;  
      
int sensorValue;

void setup() { 
  pinMode(led_pin,OUTPUT);
Serial.begin(9600);
}

void loop() {
 
  sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  if(sensorValue<sensorlimit)
  digitalWrite(led_pin,HIGH);
    
}
