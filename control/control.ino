#include "control.h"
#include <LiquidCrystal_I2C.h>
#include <Wire.h>


void setup() {
  Serial.begin(9600);'
  pinMode(switchPin, INPUT);
  digitalWrite(switchPin, HIGH);
  lcd.init();
  lcd.backlight();
  printString("Start Control");
}

void loop() {
  //sendData(speedBLDC,angleServo,controlMode);
}
