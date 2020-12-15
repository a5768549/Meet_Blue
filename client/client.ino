/*
 * meet_blue
 * Copyright 2020 a5768549
 *
 * GitHub Project：https://github.com/a5768549/meet_blue
 */
#include "Config.h"
#include "Network.h"
/* 簡單使用方法：
 * _setData("0000"); = 讓四位七段顯示器顯示0000
 * sendData1("00");  = 讓七段顯示器顯示00
 * Config.h內需設定Wifi帳號密碼，否則無法運作
 */
void changeState()
{
  switch(segChangeCount)
  {
    case 0:digitalWrite(A0,LOW);digitalWrite(A1,LOW);sendData2(0);break;
    case 1:digitalWrite(A0,LOW);digitalWrite(A1,HIGH);sendData2(1);break;
    case 2:digitalWrite(A0,HIGH);digitalWrite(A1,LOW);sendData2(2);break;
    case 3:digitalWrite(A0,HIGH);digitalWrite(A1,HIGH);sendData2(3);break;
  }
  segChangeCount += 1;
  if(segChangeCount == 4)segChangeCount = 0;
}

void setup() 
{
  _init();
  Serial.begin(9600);

  WiFi.begin(ssid,password);
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print(".");
  }
  timeClient.begin();
  
  segChange.attach(0.002, changeState);
}

void loop() 
{
  int seg_data = Get_date();
  sendData1(seg_data);
  int _time = Get_time();

  timeClient.update();
  //Serial.println(timeClient.getHours());
  int _hour = timeClient.getHours();
  int _min = timeClient.getMinutes();

  String _hour_string = String(_hour);
  String _min_string = String(_min);

  //have string format problem, so use switch change the string.
  switch(_min)
  {
    case 0:_min_string = "00";break;
    case 1:_min_string = "01";break;
    case 2:_min_string = "02";break;
    case 3:_min_string = "03";break;
    case 4:_min_string = "04";break;
    case 5:_min_string = "05";break;
    case 6:_min_string = "06";break;
    case 7:_min_string = "07";break;
    case 8:_min_string = "08";break;
    case 9:_min_string = "09";break;
  }
  switch(_hour)
  {
    case 0:_hour_string = "00";break;
    case 1:_hour_string = "01";break;
    case 2:_hour_string = "02";break;
    case 3:_hour_string = "03";break;
    case 4:_hour_string = "04";break;
    case 5:_hour_string = "05";break;
    case 6:_hour_string = "06";break;
    case 7:_hour_string = "07";break;
    case 8:_hour_string = "08";break;
    case 9:_hour_string = "09";break;
  }
  
  //Serial.println("time:" + _hour_string + _min_string); 

  _setData((_hour_string + _min_string));

  if(_time < 30)
  {
    tone(Buzzer, 659);
    delay (500);
    noTone(Buzzer);
    delay (250);
    tone(Buzzer, 659);
    delay (500);
    noTone(Buzzer);
  }
  
  delay(500);       // delay 0.5 second
}
