int led =13;
void setup() {
 pinMode(led,OUTPUT);
 Serial.begin(9600);
}
void loop() {
 if (Serial.available()){
  char letter=Serial.read();
  if(letter =='1'){
    digitalWrite(led,HIGH);
  }
  if(letter =='2'){
    digitalWrite(led,LOW);
  }
 }

}
