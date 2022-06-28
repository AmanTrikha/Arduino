#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "----------------------------"; //You will get this Auth Token in Gmail if you signin Blynk app with your Gmail ID

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "--------"; //Enter your WIFI Name
char pass[] = "--------";//Enter your WIFI Password

void setup()
{
  // Debug console
  Serial.begin(9600);
  pinMode(D2,OUTPUT);
  digitalWrite(D2,HIGH);
  
  Blynk.begin(auth, ssid, pass);

void loop()
{
  Blynk.run();
}
