
void setup() {
  pinMode(27,OUTPUT);
  pinMode(26,OUTPUT);
}

void loop() {
  digitalWrite(27,HIGH);
  digitalWrite(26,LOW);
 delay(1000);
digitalWrite(26,HIGH);
  digitalWrite(27,LOW);
  delay(500);

}
