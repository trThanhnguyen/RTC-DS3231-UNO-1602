/*
This project will:
  Read computer real time
  Output it to the LCD, and
  Control a RGB-LED to decorate
*/
#include <LiquidCrystal.h>
#include <Wire.h>
#include <RTClib.h>

DateTime now;
RTC_DS3231 rtc;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 
void displayDate();
void displayTime();

int   Contrast=100; 

void setup() {
  analogWrite(6,Contrast);    // Adjust contrast without potentiometer
  lcd.begin(16, 2);
  Serial.begin(9600);
   if (! rtc.begin())  {
    Serial.println(" RTC Module not Present");
    while (1);
  }
  if (rtc.lostPower()) {
    Serial.println("RTC power failure, reset the time!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
}
 
void loop() { 
  /*time display*/
  now = rtc.now();
  displayDate();
  displayTime();

void displayDate() {
  lcd.setCursor(0,0);
  lcd.print("Date: ");
  if (now.day() < 10) {
    lcd.print('0');
    lcd.print(now.day());
  }
  else {
    lcd.print(now.day());
  }
  lcd.print('/');
  if (now.month() <10) {
    lcd.print('0');
    lcd.print(now.month());
  }
  else {
    lcd.print(now.month());
  }
  lcd.print('/');
  lcd.print(now.year());
}
void displayTime() {
  lcd.setCursor(0,1);
  lcd.print("Time: ");
  if (now.hour() < 10)  {
    lcd.print('0');
    lcd.print(now.hour());
  }
  else {
    lcd.print(now.hour());
  }
  lcd.print(':');
  if (now.minute() < 10) {
    lcd.print('0');
    lcd.print(now.minute());
  }
  else {
    lcd.print(now.minute());
  }
  lcd.print(':');
  if (now.second() < 10) {
    lcd.print('0');
    lcd.print(now.second());
  }
  else {
    lcd.print(now.second());
  }  
  lcd.print("    ");
} 
