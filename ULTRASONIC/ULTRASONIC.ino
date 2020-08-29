
#include <Wire.h> 

const int trigPin=PB1;  //define the pin PBX
const int echoPin=PB0;  //define the pin PBX

long duration;
int distance;

void setup()
{
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 Serial.begin(9600);
 
}


void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;         //Calculates Distance
  
  Serial.print("Distance: ");
  Serial.println(distance);            //Check Serial Monitor
  delay(1000);
}
