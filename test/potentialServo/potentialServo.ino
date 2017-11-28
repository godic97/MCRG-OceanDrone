#include <Servo.h>

Servo bldc;

int value;

void setup() {
  bldc.attach(3);
  Serial.begin(9600);
  Serial.println("motor speed");
}

void loop() {

    value = analogRead(A5);
    
    value = map(value, 0, 1023, 980, 1400);
    Serial.println(value);
    bldc.write(value);
    delay(15);
}
