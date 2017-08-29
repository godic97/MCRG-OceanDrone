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

long data = 0;
long speedBLDC = setupBLDC;
long angleServo = setupServo;
bool controlMode = passiveMode;

// Read Data(BLDC's Speed, Servo's Angle, Mode)
void readData(long &_speedBLDC,long &_angleServo,bool &_controlMode){
  if(Serial.available()) // if Serial is true.
    data = Serial.read();
    
  else // if serial is false
    data = false;

  _speedBLDC = data % 100; // Speed data is 0~99
  _angleServo = (data / 100) % 100; // Angle data is 0~99
  _controlMode = data / 10000; // Mode data is true or false(1 or 0)
}

