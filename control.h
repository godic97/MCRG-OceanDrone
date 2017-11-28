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
long data = 0;
long speedBLDC = setupBLDC;
long angleServo = setupServo;
bool controlMode = passiveMode;
int xData = 497;
int yData = 501;
bool switchData = true;

// Fuction of Sending Data
void sendData(long tmpSpeedBLDC, long tmpAngleServo, bool tmpControlMode){
  data = tmpSpeedBLDC + (tmpAngleServo * 100) + (tmpControlMode * 10000);
}

// Init Control Data
void initControl(){
  long data = 0;
  long speedBLDC = setupBLDC;
  long angleServo = setupServo;
  bool controlMode = passiveMode;
  int xData = 497;
  int yData = 501;
  bool switchData = true;  
}

// Fuction of Print String on LCD
void printString(char* str){
  for(int i = 0; i < strlen(str); i++){
    lcd.print(str[i]);
  }
}

// Read Joystick Data
void readJoystick(){
  xData = analogRead(xPin);
  xData = map(xData, 1023, 0, 999, 0); // 0 ~ 999
  yData = analogRead(yPin);
  yData = map(yData, 1023, 0, 999, 0); // 0 ~ 999
  switchData = digitalRead(switchPin);
}

// Change 10 ^ 4 number To String And Print
void printInt(int num){
  lcd.print(num/1000); // 1000
  lcd.print((num/100) % 10); //100
  lcd.print((num/10) % 10); // 10
  lcd.print(num % 10); // 1
}

// Print Joystick Data
void printJoystick(){
  printString("X: ");
  printInt(xData);
  lcd.setCursor(0,1); // Chang Line
  printString(" Y: ");
  printInt(yData);
}

#endif
