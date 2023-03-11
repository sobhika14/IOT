#include <ESP8266WiFi.h>// lib
WiFiClient client; // ip address getting
WiFiServer server(80);// ip server address getting
const char* ssid = "OnePlus 8 Pro";//hotspot name
const char* password = "hello1411";// hotspot passward

String  data =""; // string data from user

void setup()
{ 
  pinMode (D0,OUTPUT);
  Serial.begin(115200);//baudrate
  connectWiFi();
  server.begin();
}
void connectWiFi()
{
  Serial.println("Connecting to WIFI");
  WiFi.begin(ssid, password);
  while ((!(WiFi.status() == WL_CONNECTED)))// connecting with ip address
 {
    delay(300);
    Serial.print("..");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("NodeMCU Local IP is : ");
  Serial.print((WiFi.localIP()));// printing ip address
}
void loop()
{
   
    client = server.available();
    if (!client) return; 
    data = checkClient ();
    Serial.println(data);//prints "on" or "off" in Serial
    if ( data=="on")
  {
     digitalWrite (D0,HIGH);
  delay(100);
    
  }
  if (data=="off")
  {
    digitalWrite(D0,LOW);
  delay(100);
  }
} 

/***RECEIVE DATA FROM the APP ***/
String checkClient (void)
{
  while(!client.available()) 
  delay(1); 
  String request = client.readStringUntil('\r');//reciving string data from user
  //Serial.println(request);
  request.remove(0, 5);
  request.remove(request.length()-9,9);
  return request;
}
