#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

//php server(Internet)
String host = "http://projectgroup.team:8080/meet_blue/";

int Get_date()
{
  HTTPClient http;

  http.begin(host + "get_date_api.php"); 

  int httpCode = http.GET();
  String payload = http.getString();
  //Serial.println(payload);
  http.end();
  return payload.toInt();
}

int Get_time()
{
  HTTPClient http;

  http.begin(host + "get_less_time_api.php"); 

  int httpCode = http.GET();
  String payload = http.getString();
  //Serial.println(payload);
  http.end();
  return payload.toInt();
}
