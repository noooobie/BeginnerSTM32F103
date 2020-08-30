#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,16,2);  // set the LCD address as per LCD Test Code for  16 chars and 2 line display
const int trigPin=PB1; //set Trigger pin
const int echoPin=PB0; //set Echo pin


long duration;
int distanceCm;

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
 
  Serial.begin(9600);
  Wire.begin();
  lcd.begin();                        //Light Up LCD Screen
  lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("WELCOME");       
  lcd.setCursor(4,1);
  lcd.print("loading....");
  delay(3000);
  lcd.clear();
}

void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distanceCm = duration*0.034/2;          //Equation For Measuring Ultrasonic
  
  Serial.print("Distance: ");
  Serial.println(distanceCm);            //Display on Serial Monitor
  delay(3000);
  
  lcd.setCursor(0,0);
  lcd.print("DISTANCE:");
  lcd.print(distanceCm);
  lcd.print(" cm");                     //Display on LCD Screen
  delay(10);
}
