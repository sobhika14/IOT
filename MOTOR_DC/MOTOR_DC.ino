int dc=0;
int dc1=0;
void setup() {
  pinMode(D0,OUTPUT);
  pinMode(D1,OUTPUT);
}

void loop() {
  digitalWrite(D0,HIGH);
  digitalWrite(D0,LOW);
 delay(1000);
digitalWrite(D1,LOW);
  digitalWrite(D1,HIGH);
  delay(500);

}
