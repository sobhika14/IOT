int sensordata =0;
void setup() {
  pinMode(A0,INPUT);
  pinMode(D0,OUTPUT);
  Serial.begin(9600); 
}
void loop() {
  sensordata=analogRead(A0);
  Serial.println(sensordata);
  if(sensordata >100)
  {
    digitalWrite(D0,HIGH);
  }  
  else if(sensordata <100)
  {
    digitalWrite(D0,LOW);
    
  }
  }
  
