#include <Servo.h>

// Pin number
#define pinBLDC 9
#define pinServo 11

// Setup Data
#define setupBLDC 0
#define setupServo 0

// Mode
#define passiveMode false
#define autoMode true

Servo mainBLDC;
Servo mainServo;

long speedBLDC = setupBLDC;
long angleServo = setupServo;
bool controlMode = passiveMode;

// Read Data(BLDC's Speed, Servo's Angle, Mode)
void dataRead(&speedBLDC, &angleServo, &controlMode){
  if(Serial1.available()){
    long data = Serial1.read();
    speedBLDC = data % ; // Speed data is 
    angleServo = data % ;// Angle data is
    mode = data % ; // Mode data is true or false
  }
}

