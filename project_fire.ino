#include <dht.h>
int temperature_sensr = 2;
int water_sprinkler=3;
dht DHT;
 
void setup()
{
  Serial.begin(9600);
  Serial.print("Serail communication initialized");
}
 
void loop()
{  
    DHT.read11(2); 
    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(DHT.temperature); 
    Serial.println("C  ");
    if(DHT.temperature>50)
    digitalWrite(water_sprinkler,HIGH);
    else if(water_sprinkler<50)
    digitalWrite(water_sprinkler,LOW);
    delay(500);
 
}
