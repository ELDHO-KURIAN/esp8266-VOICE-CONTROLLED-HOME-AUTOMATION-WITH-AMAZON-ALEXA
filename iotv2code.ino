#ifdef ARDUINO_ARCH_ESP32
#include <WiFi.h>
#else
#include <ESP8266WiFi.h>
#endif
#include <Espalexa.h>
 #include <ESP8266WiFi.h>  
 #include <ESP8266WebServer.h>  
 #include<WiFiManager.h> 

#define R1 D1
#define R2 D2
#define R3 D8
#define R4 D3
int val;
int val2;
int val3;

//callback functions
void firstLightChanged(uint8_t brightness);
void secondLightChanged(uint8_t brightness);
void thirdLightChanged(uint8_t brightness);
void fourthLightChanged(uint8_t brightness);


// device names
String Device_1_Name = "Office light";
String Device_2_Name = "Studio light";
String Device_3_Name = "Yellow Bulb";
String Device_4_Name = "Red bulb";

boolean wifiConnected = false;

Espalexa espalexa;
unsigned long previousMillis = 0; 
unsigned long currentMillis = 0;
float average = 0;
int Delay= 1000;
void setup()
{
  Serial.begin(115200);

  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
  pinMode(R3, OUTPUT);
  pinMode(R4, OUTPUT);
  pinMode(D6,OUTPUT);
  pinMode(D0,OUTPUT);
  pinMode(D5,OUTPUT);
  pinMode(A0,INPUT);
  pinMode(D7,INPUT);

 currentMillis = millis();
 WiFiManager wifiManager;  
  wifiManager.autoConnect("ek");  
  Serial.println("Connected.....");  
  

    // Define your devices here.
    espalexa.addDevice(Device_1_Name, firstLightChanged); //simplest definition, default state off
    espalexa.addDevice(Device_2_Name, secondLightChanged);
    espalexa.addDevice(Device_3_Name, thirdLightChanged);
    espalexa.addDevice(Device_4_Name, fourthLightChanged);

    espalexa.begin();


}

void loop()
{
  digitalWrite(D0,HIGH);
    currentMillis = millis();
  if(currentMillis - previousMillis >= Delay){  
    previousMillis += Delay;
  val=digitalRead(D7);
  val2=analogRead(A0);
  Serial.println(val);
  Serial.println(val2);
}

  espalexa.loop();
  delay(1);
}

//our callback functions
void firstLightChanged(uint8_t brightness)
{
  //Control the device
  if (brightness)
  {
    if (brightness == 255)
    {
      digitalWrite(R1, HIGH);
      Serial.println("Device1 ON");
      digitalWrite(D6,HIGH);
      digitalWrite(D5,HIGH);
      delay(50);
      digitalWrite(D6,LOW);
      digitalWrite(D5,LOW);
    }
    //Serial.print("ON, brightness ");
    //Serial.println(brightness);
  }
  else
  {
    digitalWrite(R1, LOW);
    Serial.println("Device1 OFF");
    digitalWrite(D5,HIGH);
      digitalWrite(D6,HIGH);
      delay(50);
      digitalWrite(D6,LOW);
      digitalWrite(D5,LOW);
  }
}

void secondLightChanged(uint8_t brightness)
{

  //Control the device 
  if (brightness)
  {
    if (brightness == 255)
    {
      digitalWrite(R2, HIGH);
      Serial.println("Device2 ON");
        digitalWrite(D6,HIGH);
        digitalWrite(D5,HIGH);
      delay(50);
      digitalWrite(D6,LOW);
      digitalWrite(D5,LOW);
    }
    //Serial.print("ON, brightness ");
    //Serial.println(brightness);
  }
  else
  {
    digitalWrite(R2, LOW);
    Serial.println("Device2 OFF");
      digitalWrite(D6,HIGH);
      digitalWrite(D5,HIGH);
      delay(50);
      digitalWrite(D6,LOW);
      digitalWrite(D5,LOW);
  }
}

void thirdLightChanged(uint8_t brightness)
{

  //Control the device  
  if (brightness)
  {
    if (brightness == 255)
    {
      digitalWrite(R3, HIGH);
      Serial.println("Device3 ON");
      digitalWrite(D6,HIGH);
      digitalWrite(D5,HIGH);
      delay(50);
      digitalWrite(D6,LOW);
      digitalWrite(D5,LOW);
    }
    //Serial.print("ON, brightness ");
    //Serial.println(brightness);
  }
  else
  {
    digitalWrite(R3, LOW);
    Serial.println("Device3 OFF");
      digitalWrite(D6,HIGH);
      digitalWrite(D5,HIGH);
      delay(50);
      digitalWrite(D6,LOW);
      digitalWrite(D5,LOW);
  }
}

void fourthLightChanged(uint8_t brightness)
{

  //Control the device 
  if (brightness)
  {

    if (brightness == 255)
    {
      digitalWrite(R4, HIGH);
      Serial.println("Device4 ON");
      digitalWrite(D6,HIGH);
      digitalWrite(D5,HIGH);
      delay(50);
      digitalWrite(D6,LOW);
      digitalWrite(D5,LOW);
    }
    //Serial.print("ON, brightness ");
    //Serial.println(brightness);
  }
  else
  {
    digitalWrite(R4, LOW);
    Serial.println("Device4 OFF");
      digitalWrite(D6,HIGH);
      digitalWrite(D5,HIGH);
      delay(50);
      digitalWrite(D6,LOW);
      digitalWrite(D5,LOW);
  }
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
