#ifndef CONTROL_H
#define CONTROL_H

// Include Header File
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

// Setup Data
#define setupBLDC 0
#define setupServo 0
LiquidCrystal_I2C lcd(0x3F,16,2); // A-> A4 L->A5

// Mode
#define passiveMode false
#define autoMode true

long data;
long speedBLDC = setupBLDC;
long angleServo = setupServo;
bool controlMode = passiveMode;

// Fuction of Sending Data
void sendData(long _speedBLDC, long _angleServo, bool _controlMode){
  data = _speedBLDC + (_angleServo * 100) + (_controlMode * 10000);
}

// Fuction of Print String on LCD
void printString(char* str){
  for(int i = 0; i < strlen(str); i++){
    lcd.print(str[i]);
  }
}
#endif
