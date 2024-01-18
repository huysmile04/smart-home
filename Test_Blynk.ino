#define BLYNK_TEMPLATE_ID "TMPL6NA5PEEfr"
#define BLYNK_TEMPLATE_NAME "Led"
#define BLYNK_AUTH_TOKEN "T3-4qRf7jnvsgK_AaaPMI-YjPncpL78K"
#define BLYNK_PRINT Serial
#include <ESP8266wifi.h>
#include <BlynkSimpleEsp8266.h>
#include "DHT.h"  
char ssid[] = "Tang 12";
char pass[] = "npka0202tang12";
const int DHTPIN = 2;
const int DHTTYPE = DHT11;
DHT dht(DHTPIN, DHTTYPE);
#define LED 16
#define button 0
boolean bt_state=HIGH;
BLYNK_WRITE(V0){
  int p = param.asInt();
  digitalWrite(LED, p);
}
void setup()
{
  // Debug console
  Serial.begin(115200);
  dht.begin(); 
  pinMode(LED,OUTPUT);
  digitalWrite(LED,LOW);
  pinMode(button, INPUT_PULLDOWN_16);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  Blynk.run();
    if (digitalRead(button)==LOW){
      if(bt_state==HIGH){
      
        digitalWrite(LED,HIGH);
        Blynk.virtualWrite(V0,digitalRead(LED));
        bt_state=LOW;
        delay(200);
      }
    }
    else{
      bt_state=HIGH;
    }
  Blynk.virtualWrite(V1,t);
  Blynk.virtualWrite(V2,h);  

}
