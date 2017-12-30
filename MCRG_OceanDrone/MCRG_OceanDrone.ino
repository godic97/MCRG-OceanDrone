#include"MCRG_OceanDrone.h"


void setup() {
  Serial.begin(9600);
  mainServo.attach(pinServo);
  mainBLDC.attach(pinBLDC, 1000, 2000);
  mainServo.write(setupServo);
  mainBLDC.write(setupBLDC);
 // lcd.init();   // initialize the lcd 
  //lcd.backlight();
}

void loop() {
  if(Serial.available()){
    readData();
    //lcd.clear();
    runServo();
    runBLDC();
   //printt();
    
  }
}
