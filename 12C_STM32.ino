#include <Wire.h> 
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x3F, 16, 2); //Set the LCD address after testing the address code given in the repositary
                                    // Set the LCD address to (0xXX,16,2) for a 16 chars and 2 line display

void setup()
{
  
  lcd.begin();  // initialize the LCD
  lcd.backlight();  // Turn on the blacklight and print a message.
  lcd.print("Hello, world!");
}

void loop()
{
  // Do nothing here...
}
