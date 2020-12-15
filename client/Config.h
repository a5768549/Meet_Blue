#include <Ticker.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

#define RCLK   D0  //latchPin
#define SRCLK  D1  //clockPin
#define SER    D2  //dataPin
#define RCLK2  D7  //latchPin2
#define SRCLK2 D6  //clockPin2
#define SER2   D5  //dataPin2
#define A0     D3  //74139 A0
#define A1     D4  //74139 A1
#define Buzzer D8

//ESP AP Wifi Setting
const char* ssid = "*********";
const char* password = "*********";

//4 digit Seg7 PWM
Ticker segChange;
byte segChangeCount = 0;

//NTP
const long utcOffsetInSeconds = 28800;
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds);

byte timeData[4] = {0,0,0,0};

const byte _data[10] = // 0~9 encode
{
  B00000001,
  B01001111,
  B00010010,
  B00000110,
  B01001100,
  B00100100,
  B00100000,
  B00001111,
  B00000000,
  B00001100
};

void sendData1(int number)
{
  byte digits = number % 10;
  byte tens = int(number / 10);
  digitalWrite(RCLK, LOW);   //close gate
  shiftOut(SER, SRCLK, LSBFIRST, _data[digits]);
  shiftOut(SER, SRCLK, LSBFIRST, _data[tens]);
  digitalWrite(RCLK, HIGH);  //open gate
};

void _setData(String number)
{
  int hund = int(number.toInt() % 1000);
  int ten = hund % 100;
  int num = ten % 10;
  
  timeData[0] = int(number.toInt() / 1000);
  timeData[1] = int(hund / 100);
  timeData[2] = int(ten / 10);
  Serial.println(timeData[2]);
  timeData[3] = num;
}

void sendData2(byte gate)
{
  digitalWrite(RCLK2, LOW);   //close gate
  shiftOut(SER2, SRCLK2, LSBFIRST, _data[timeData[gate]]);
  digitalWrite(RCLK2, HIGH);  //open gate
};



void _init()
{
  pinMode(RCLK  ,OUTPUT);
  pinMode(SRCLK ,OUTPUT);
  pinMode(SER   ,OUTPUT);
  pinMode(RCLK2 ,OUTPUT);
  pinMode(SRCLK2,OUTPUT);
  pinMode(SER2  ,OUTPUT);
  pinMode(A0    ,OUTPUT);
  pinMode(A1    ,OUTPUT);
  pinMode(Buzzer,OUTPUT);
}
