int led=23;
int i=0;
void setup() {
  pinMode(led,OUTPUT);
}
void loop() {
 for(i=0;i<=255;i++)
 {
  ledcWrite(led,128);
  delay(500);
 }
}
