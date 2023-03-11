#include<ESP8266WiFi.h>
#include<ESP8266WebServer.h>
const char* ssid = "OnePlus 8 Pro";//hotspot name
const char* password = "hello1411";// hotspot passward
ESP8266WebServer server(80);
int LEDPIN=D0;
bool LEDstatus=LOW;
void setup(){
  Serial.begin(9600);
  delay(100);
  pinMode(LEDPIN,OUTPUT);
  Serial.println("connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid,password);
  while(WiFi.status()!=WL_CONNECTED){

    delay(1000);
    Serial.print(".");
  }
  Serial.println(" ");
   Serial.println(" WiFi connected..!");
   Serial.println("Got IP :");
   Serial.println(WiFi.localIP());
   server.on("/",handle_OnConnect);
   server.on("/ledon",handle_ledon);
   server.on("/ledoff",handle_ledoff);
   server.onNotFound(handle_NotFound);
   server.begin();
   Serial.println("HTTP server started");
}
void loop(){
  server.handleClient();
  if(LEDstatus)
  digitalWrite(LEDPIN,LOW);
  else
  digitalWrite(LEDPIN,HIGH);
}
void handle_OnConnect(){
  LEDstatus =LOW;
  server.send(200,"text/html",SendHTML(false));
}
void handle_ledon(){
  LEDstatus =HIGH;
  server.send(200,"text/html",SendHTML(true));
}
void handle_ledoff(){
  LEDstatus =LOW;
  server.send(200,"text/html",SendHTML(false));
}
void handle_NotFound(){
  server.send(404,"text/plain","Not Found");
}
String SendHTML (int led){
  String ptr="<!DOCTYPE html>\n";
  ptr+="<html>\n";
   ptr+="<head>\n";
   ptr+="<title> LED CONTROLLER </title>\n";
    ptr+="</head>\n";
    ptr+="<head>\n";
    ptr+="<h1> ipcs automation </h1> \n";
     ptr+="<h1> smart home </h1> \n";
      ptr+="<p> click to switch on or off.</p> \n";
      ptr+="<form method =\"get\">\n";
      if(led)
 ptr +="<input type =\"button\" value=\"LED OFF\"onclick =\"window.location.href='/ledoff'\">\n";
 else
 ptr +="<input type =\"button\"value=\"LED ON\"onclick =\"window.location.href='/ledon'\">\n";
 ptr +="</form>\n";
 ptr +="</body>\n";
 ptr +="</html>\n";
 return ptr;
}
