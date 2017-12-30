#include <Servo.h>
#include <LiquidCrystal_I2C.h>
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

