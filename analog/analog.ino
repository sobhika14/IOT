int sensordata=0;
void setup() {
  pinMode(A0,INPUT);
  Serial.begin(9600);
}

void loop() {
  sensordata =analogRead(A0);
  Serial.println(sensordata);
  delay(500);

}
