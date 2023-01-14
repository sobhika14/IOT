int sensor =0;
void setup() {
  pinMode(13,OUTPUT);
  pinMode(2,INPUT);
  Serial.begin(9600);
}
void loop() {
  sensor = analogRead(2);
  Serial.println(sensor);
  if (sensor >100)
  {
    digitalWrite(13,HIGH);
  }
  else if (sensor <100)
  {
    digitalWrite(13,LOW);
  }
}
