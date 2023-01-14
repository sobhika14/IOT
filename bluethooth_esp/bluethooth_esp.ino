String  c;
void setup() {
  pinMode (13,OUTPUT);
  Serial.begin(9600);
}
void loop() {
  if (Serial.available())
  {
    c=Serial.readString();
    Serial.println(c);
    if (c=="yes")
    {
      digitalWrite(13,HIGH);
      delay(500);
    }
    if ( c=="no")
    {
      digitalWrite(13,LOW);
      delay(500);
    }
    
  }
  

}
