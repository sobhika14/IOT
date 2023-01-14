 int button = 0;
 int button1=0;
void setup() {
  Serial.begin(9600);
  pinMode(2,INPUT);
  pinMode(3,INPUT);
}

void loop() {
  button =digitalRead(2);
   button1 =digitalRead(3);
  if(button==HIGH){
    Serial.println('1');
  }
   if(button1==HIGH){
    Serial.println('2'); 
  }
  
}
