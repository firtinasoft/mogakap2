//EBT524-PROJE
#include "FirebaseESP8266.h"
#include <ESP8266WiFi.h>
#define FIREBASE_HOST "https://mogakap-aa4ee-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "AIzaSyAeEZ06WyjyhExpKnv--FPCJ6t-c3VTPX0"
#define WIFI_SSID "SATSOKAPI"
#define WIFI_PASSWORD "123456789"
FirebaseData mogakap;
void setup()
{
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
 pinMode(D1,OUTPUT);
 digitalWrite(D1,LOW);
}
void loop()
{
  if(Firebase.getString(mogakap, "/ac"))
  {
    if (mogakap.stringData()=="1")
    {
      digitalWrite(D1,HIGH);
      delay (500);
      digitalWrite(D1,LOW);
    }
    else {  digitalWrite(D1,LOW); }
  }
