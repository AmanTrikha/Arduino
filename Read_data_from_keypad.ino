#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 12
int relay=1; 
OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);

 float Celcius=0;
 float Fahrenheit=0;
int choice,a,b,s;
void setup()
{
  Serial.begin(9600);
   Serial.println("1.Milking");
  Serial.println("2.Heating");
}
void loop()
{
 
   choice=random(int(3));
  switch(choice)
  {
     case0:
            sensors.requestTemperatures(); 
            Celcius=sensors.getTempCByIndex(0);
            Fahrenheit=sensors.toFahrenheit(Celcius);
            Serial.print(" temp in celcius  ");
            Serial.println(Celcius);
            break;
     case 1:
            sensors.requestTemperatures(); 
            Celcius=sensors.getTempCByIndex(0);
          //  fahrenheit=sensors.toFahrenheit(Celcius);
            Serial.print(" temp in celcius  ");
            Serial.println(Celcius);
          // int compare=(Serial.available());
    //        if( compare >27)
            digitalWrite(relay,LOW);
//            if( compare >22)
            digitalWrite(relay,HIGH);
            Serial.print(" temp in fareheit ");
            Serial.println(Fahrenheit);
            break; 
          //  default
        //    Serial.print("NA");      
           
  }//delay(2000));
}

