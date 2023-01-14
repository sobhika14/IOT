int pwmChannel = 0; 
int frequence = 1000; 
int resolution = 8; 
int pwmPin = 23;

void setup(){
    ledcSetup(pwmChannel, frequence, resolution);
    ledcAttachPin(pwmPin, pwmChannel);
    ledcWrite(pwmChannel, 20);
}

void loop(){
}
