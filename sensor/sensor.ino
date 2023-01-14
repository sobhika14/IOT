int sensor =0;
void setup() {
  pinMode(D0,OUTPUT);
  pinMode(D1,INPUT);
  pinMode(D2,OUTPUT);
  pinMode(D3,INPUT);
}

void loop() {
  sensor =digitalRead(D1);
  sensor=digitalRead(D3);
  if (sensor==HIGH)
  {
    digitalWrite(D0,HIGH);
    digitalWrite(D2,HIGH);
  }
  else
  {
    digitalWrite(D0,LOW);
    digitalWrite(D2,LOW);
  }

}
