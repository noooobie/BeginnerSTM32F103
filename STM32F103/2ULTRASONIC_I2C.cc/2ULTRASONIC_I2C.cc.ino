#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,16,2);  // set the LCD address to 0xXX From the LCD Testing Code
const int trigPin1=PB1;   //Set Trigger pin of first ultrasonic Sensor
const int echoPin1=PB0;   //Set Echo pin of first ultrasonic Sensor
const int trigPin2=PB3;   //Set Trigger pin of Second ultrasonic Sensor
const int echoPin2=PB4;   //Set Echo pin of first ultrasonic Sensor
const int ledPin=PB11;    //Set the LED Pin

long duration;
int distanceCm1;
int distanceCm2;
int safetyDistance1;      //Safe Distance for the LED to light up
int safetyDistance2;
void setup()
{
  

  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(ledPin,OUTPUT);
  
  Serial.begin(9600);
  Wire.begin();
  lcd.begin();
  lcd.backlight();                  
  lcd.setCursor(1,0);
  lcd.print("WELCOME");    //Printing Message on to the LCD
  lcd.setCursor(4,1);
  lcd.print("loading...");
  delay(3000);
  lcd.clear();
}


void loop()
{
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration = pulseIn(echoPin1, HIGH);
  distanceCm1 = duration*0.034/2;            //Calculates the Distance of first sensor

  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration = pulseIn(echoPin2, HIGH);
  distanceCm2 = duration*0.034/2;           //Calculates the Distance of first sensor
  
  
  Serial.println(distanceCm1);
  Serial.println(distanceCm2);
  delay(100);
  
  safetyDistance1 = distanceCm1;
  safetyDistance2 = distanceCm2;
  
  if (safetyDistance1 <=5){                //Alerts the user when distance is less than 5cm from the first sensor
     digitalWrite(ledPin, HIGH);
     Serial.print("Change Direction!!!!!!!  - ");
  }
  
  else if(safetyDistance2 <=5){            //Alerts the user when distance is less than 5cm from the second sensor
     digitalWrite(ledPin, HIGH);
     Serial.print("Change Direction!!!!!!!  - ");             
  }

  else{
     digitalWrite(ledPin,LOW);
     Serial.print("On Route  - ");
  }
  
  lcd.setCursor(0,0);
  lcd.print("SENSOR 1:");
  lcd.print(distanceCm1);
  lcd.print("cm");
  lcd.setCursor(0,1);
  lcd.print("SENSOR 2:");
  lcd.print(distanceCm2);
  lcd.print("cm");                         //Prints the distance onto the Screen

}
