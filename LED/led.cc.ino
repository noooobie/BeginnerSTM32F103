int ledpin=PB0;

void setup() {
 pinMode(PB0,OUTPUT);
}

void loop() {
 digitalWrite(PB0, HIGH);
 delay(100);
 digitalWrite(PB0,LOW);
 delay(100);

}
