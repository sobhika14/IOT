#include <ESP8266WiFi.h>
WiFiClient client;
WiFiServer server(80);
const char* ssid = "OnePlus 8 Pro";
const char* password = "hello1411";
String data1 =" ";
void setup ()
{
  Serial.begin (115200);
  connectWiFi();
  server.begin();
  
}
void connectWiFi()
{
  Serial.println("connecting to wifi");
  WiFi.begin(ssid,password);
  while ((!(WiFi.status() == WL_CONNECTED)))
  {
    delay(300);
    Serial.println ("..");
  }
  Serial.println(" ");
  Serial.println("WiFi connected ");
  Serial.println(" nodemcu local ip is :");
  Serial.print ((WiFi.localIP()));
}
void loop()
{
  client = server.available();
  if (!client) return;
  data1 = checkClient ();
  Serial.println(data1); // prints on or off in serial
  
}
String checkClient(void)
{
  while (!client.available ())
  delay(2);
  String request = client.readStringUntil('\r');
  request.remove(0,5);
  request.remove(request.length()-9,9);
  return request;
}
