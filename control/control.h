#ifndef CONTROL_H
#define CONTROL_H

// Include Header File
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

// Setup Pin
// Motor
#define setupBLDC 0
#define setupServo 0

// Joystick
#define switchPin 2 // Digital Pin 2, Switch Output
#define xPin 0 // Analog Pin 0, X Output
#define yPin 1 // Analog Pin 1, Y Output

// LCD
LiquidCrystal_I2C lcd(0x3F,16,2); // A-> A4 L->A5

// Mode
#define passiveMode false
#define autoMode true

// Setup Data
long data;
long speedBLDC = setupBLDC;
long angleServo = setupServo;
bool controlMode = passiveMode;
int xData = 527;
int yData = 14;
bool switchData = true;

// Fuction of Sending Data
void sendData(long tmpSpeedBLDC, long tmpAngleServo, bool tmpControlMode){
  data = tmpSpeedBLDC + (tmpAngleServo * 100) + (tmpControlMode * 10000);
}

// Fuction of Print String on LCD
void printString(char* str){
  for(int i = 0; i < strlen(str); i++){
    lcd.print(str[i]);
  }
}
void readJoystick(){
  xData = analogRead(xPin);
  yData = analogRead(yPin);
  switchData = digitalRead(switchPin);
}

#endif
