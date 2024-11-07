#include <LiquidCrystal.h>
const int rs=2,en=3,d4=4,d5=5,d6=6,d7=7;

LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
#include "DHT.h"
#define DHTPIN 8
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("DHT Practical...");
  dht.begin();
  lcd.begin(16,2);
  lcd.setCursor(0,0);

}

void loop() {
  // put your main code here, to run repeatedly:
    delay(200);
    float h = dht.readHumidity();
    float t = dht.readTemperature();
    float f = dht.readTemperature(true);

    if(isnan(h) || isnan(t) || isnan(f))
    {
      Serial.print(F("Failed To Read!"));
      return;
    }
    Serial.print(F("Humidity::"));
    Serial.println(h);
    lcd.print(h);
    Serial.print(F("Tempreture::"));
    Serial.println(t);

    Serial.print(F("Fahrenhit::  c"));
    Serial.println(f);
    
}
