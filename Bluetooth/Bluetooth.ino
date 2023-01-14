String b;
String c;
void setup() {
 pinMode(D0,OUTPUT);
 pinMode(D1,OUTPUT);
 pinMode(D2,OUTPUT);
 pinMode(D3,OUTPUT);
 Serial.begin(9600);
}
void loop() 
{
  if (Serial.available())
  {
    b=Serial.readString();
    Serial.println(b);
    if( b=="yes")
    {
      digitalWrite(D0,HIGH);
      digitalWrite(D2,HIGH);
      //digitalWrite(D2,HIGH);
      //digitalWrite(D3,LOW);
      delay(1000);
    }
  
    if ( b=="no")
    {
    //  digitalWrite(D1,HIGH);
      //digitalWrite (D0,LOW);
      digitalWrite(D3,HIGH);
      digitalWrite(D1,HIGH);
      delay(1000);
  }
  }
}
