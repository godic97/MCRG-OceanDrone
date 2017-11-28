void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
}

void loop() {
  if(Serial.available()){
    char tmp = Serial.read();
    if(tmp == 'A'){
      digitalWrite(13,HIGH);
    }
    else if(tmp == 'B'){
      digitalWrite(13,LOW);
    }
  }
}
