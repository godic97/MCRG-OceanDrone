#include <Servo.h>

Servo bldc;

int i = 0;

void setup(){
  Serial.begin(9600);
  bldc.attach(5);
}

void loop(){
  char a = Serial.read();
  if(a == 'A')
    i += 5;
  else
    i -= 5;
  bldc.write(i);
}
