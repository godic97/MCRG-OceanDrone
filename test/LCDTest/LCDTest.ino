#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
 
LiquidCrystal_I2C lcd(0x3F,16,2);  // set the LCD address to 0x20 for a 16 chars and 2 line display
 
void setup()
{
  lcd.init();   // initialize the lcd 
  lcd.backlight();
  lcd.print("eunji");
}
 
void loop()
{
}
