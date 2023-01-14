int buttonstate =0;
void setup()
{
 pinMode(D0,OUTPUT);
 pinMode(D1,INPUT); 
}
int x=5;
void loop()
{
buttonstate=digitalRead(D1);
if(buttonstate==HIGH)
{
  digitalWrite(D0,HIGH);
  if(x)
  {
    x++
  }
}
else
{
  digitalWrite(D0,LOW);
}
}
