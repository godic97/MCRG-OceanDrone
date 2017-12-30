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
int data = 0;
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
  data = 0;
  speedBLDC = setupBLDC;
  angleServo = setupServo;
  controlMode = passiveMode;

  xData = 497;
  yData = 510;
  switchData = true;  
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
  xData = map(xData, 0, 1023, 0, 180); // 0 ~ 999
  yData = analogRead(yPin);
  if(yData <= 520)
    yData = 510;
  yData = map(yData, 510, 1023, 0, 5); // 0 ~ 99
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
  printString("Y: ");
  printInt(yData);
}

// Send Data
void sendData(){
  data = xData + yData * 1000;
  Serial.write(4090);
  //Serial.println(data);
  //Serial.println(data);
}

void sendServo(){
  Serial.write(xData);
}

void sendBLDC(){
  Serial.write(yData + 200);
}

#endif
