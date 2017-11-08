// Arduino pin numbers
const int SW_pin = 2; // digital pin connected to switch output 
const int X_pin = 0; // analog pin connected to X output 
const int Y_pin = 1; // analog pin connected to Y output 
 
void setup() {
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(9600);
}
 
void loop() {
  Serial.print("Switch:  ");
  Serial.print(digitalRead(SW_pin));// default 1 ,click it - 0
  Serial.print("\n");
  Serial.print("X-axis: ");
  Serial.print(analogRead(X_pin));// default 526 or 535
  Serial.print("\n");
  Serial.print("Y-axis: ");
  Serial.println(analogRead(Y_pin));// default 14 of 15
  Serial.print("\n\n");
  delay(500);
}
