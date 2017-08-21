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
void dataRead(long &_speedBLDC,long &_angleServo,bool &_controlMode){
  if(Serial.available()){
    long data = Serial.read();
    _speedBLDC = data ; // Speed data is 
    _angleServo = data ; // Angle data is
    _controlMode = data ; // Mode data is true or false
  }
}

