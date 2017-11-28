void setup() {
  Serial.begin(9600); //시리얼 통신 초기화
}

void loop() {
  Serial.write('A');
  delay(500);
  Serial.write('B');
  delay(500);
}
