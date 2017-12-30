#include <Servo.h>

// Pin number
#define pinBLDC 9
#define pinServo 11

// Setup Data
#define setupBLDC 0
#define setupServo 90


// Mode
#define passiveMode false
#define autoMode true

Servo mainBLDC;
Servo mainServo;

long data = 0;
int speedBLDC = setupBLDC;
int angleServo = setupServo;
bool controlMode = passiveMode;

// Read Data(BLDC's Speed, Servo's Angle, Mode)
void readData(){
  if(Serial.available()){ // if Serial is true.
    data = Serial.read();
    if(data < 200)
      angleServo = data;// Angle data is 0~180
    else if (data >= 200)
      speedBLDC = data - 200;
  }
//  else // if serial is false
   // data = 9000;

  
   
  //_controlMode = data / 10000; // Mode data is true or false(1 or 0)
}
void readServo(){
    if(Serial.available()){ // if Serial is true.
      data = Serial.read();
      angleServo = data;
    }
    else  //if serial is false
      data = false;
}
void runServo(){
  mainServo.write(angleServo);
}

void runBLDC(){
  mainBLDC.write(speedBLDC);
}

