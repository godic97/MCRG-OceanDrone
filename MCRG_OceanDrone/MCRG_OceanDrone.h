#include <Servo.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
//LiquidCrystal_I2C lcd(0x3F,16,2);
// Pin number
#define pinBLDC 9
#define pinServo 11

// Setup Data
#define setupBLDC 0
#define setupServo 90


// Mode
#define passiveMode false
#define autoMode true

Servo mainBLDC;
Servo mainServo;

int data = 0;
int speedBLDC = setupBLDC;
int angleServo = setupServo;
bool controlMode = passiveMode;

int addr = 0x18;
byte buffer[2] = {0, 0};
int status = 0;
void Gamma_Mod_Read(int cmd);
void Print_Result(int cmd);
// Read Data(BLDC's Speed, Servo's Angle, Mode)
void readData(){
  if(Serial.available()){ // if Serial is true.
    data = Serial.read();
    if(data >= 200)
      speedBLDC = data - 200;
    else
      angleServo = data;
  }
}
void readServo(){
    if(Serial.available()){ // if Serial is true.
      data = Serial.parseInt();
      angleServo = data;
    }
    else  //if serial is false
      data = false;
}

void runServo(){
  mainServo.write(angleServo);
}

void runBLDC(){
  mainBLDC.write(speedBLDC * 10 + 10);
}

void Gamma_Mod_Read_Value() {
  Gamma_Mod_Read(0xB3); // Read Measuring Value (1min avg / 1min update)
}

void Gamma_Mod_Read(int cmd) {
  /* Begin Write Sequence */
  Wire.beginTransmission(addr);
  Wire.write(cmd);
  Wire.endTransmission();
  /* End Write Sequence */
  delay(10);
  /* Begin Read Sequence */
  Wire.requestFrom(addr, 2);
  byte i = 0;
  while (Wire.available())
  {
    buffer[i] = Wire.read();
    i++;
  }
  /* End Read Sequence */
  /* View Results */
  Print_Result(cmd);
}
/*
  Calculation Measuring Time
  Format :: 0d 00:00:00 ( (day)d (hour):(min):(sec) )
*/

void Print_Result(int cmd) {
  float value = 0.0f;
  value = buffer[0] + (float)buffer[1] / 100;
  int _value = (int)value * 10;
  Serial.write(_value);
}

/*void printInt(int num){
  lcd.print(num/1000); // 1000
  lcd.print((num/100) % 10); //100
  lcd.print((num/10) % 10); // 10
  lcd.print(num % 10); // 1
}

void printString(char* str){
  for(int i = 0; i < strlen(str); i++){
    lcd.print(str[i]);
  }
}

void printt(){
   printString("X: ");
  printInt(angleServo);
  lcd.setCursor(0,1); // Chang Line
  printString("Y: ");
  printInt(speedBLDC);
}*/

