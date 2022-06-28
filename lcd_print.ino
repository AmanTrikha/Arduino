#include <LiquidCrystal.h>

const int rs = 10, en = 11, d4 = 8, d5 = 9, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int motorF=6;
int motorR=7;

void setup()

{

 pinMode(motorF,OUTPUT);
 pinMode(motorR,OUTPUT);

lcd.begin(16, 2);

}

 

void loop()

{
lcd.print("HELLO AMAN");

lcd.setCursor(0, 1); 
lcd.print("HOW ARE YOU?");

delay(500);

lcd.scrollDisplayRight();
lcd.noDisplay();
delay(500);
lcd.display();
lcd.setCursor(0, 0);// 

}


