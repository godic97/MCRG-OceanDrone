#include "control.h"
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
int b = 0;

void setup() {
  Serial.begin(9600);
  pinMode(switchPin, INPUT);
  digitalWrite(switchPin, HIGH);
  initControl();
  lcd.init();
  lcd.backlight();
  printString("Start Control");
  delay(1000);
}

void loop() {
  /*if(Serial.available()){
     char a = Serial.read();
     lcd.setCursor(0, (b++)%2);
     lcd.print(a);
  }*/
  lcd.clear();
  readJoystick();
  sendServo();
  delay(50);
  sendBLDC();
  printJoystick();
  delay(50);
}
