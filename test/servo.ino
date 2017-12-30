#include <Servo.h>

Servo servo;

int i = 0;

void setup(){
  Serial.begin(9600);
  servo.attach(4);
}

void loop(){
  char a = Serial.read();
  if(a == 'A')
    i += 5;
  else if(a =="S")
    i -= 5;
  servo.write(i);
  delay(15);
}
