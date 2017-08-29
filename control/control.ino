#include "control.h"

void setup() {
  Serial.begin(9600);
}

void loop() {
  sendData(speedBLDC,angleServo,controlMode);
}
