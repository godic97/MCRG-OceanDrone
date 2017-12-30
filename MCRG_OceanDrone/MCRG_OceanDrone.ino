#include"MCRG_OceanDrone.h"

void setup() {
  Serial.begin(9600);
  mainServo.attach(pinServo);
  mainBLDC.attach(pinBLDC);
  mainServo.write(setupServo);
  mainBLDC.write(setupBLDC);
}

void loop() {
  if(Serial.available()){
    readData();
    runServo();
    runBLDC();
  }
}
