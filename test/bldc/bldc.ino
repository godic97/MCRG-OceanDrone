#include <Servo.h>

Servo bldc;

int i = 90;


void setup(){
  Serial.begin(9600);
  bldc.attach(9);
  bldc.write(i);
}

void loop(){
  if(Serial.available()){
    char a = Serial.read();
    if(a == 'A')
      i += 10;
    else if(a =='S')
      i -= 10;
    bldc.write(i);
    Serial.println(i);
  }
}
