 // Chage These Credentials with your Blynk Template credentials
// Chage These Credentials with your Blynk Template credentials 
#define BLYNK_TEMPLATE_ID "TMPLhDois7Lo"
#define BLYNK_DEVICE_NAME "servo"
#define BLYNK_AUTH_TOKEN "BVqvc6KDigzVXR75KaLotFAnaQ5TcMFY"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#include<Servo.h>
Servo servo5;

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "tselhome-906B"; // Change your Wifi/ Hotspot Name
char pass[] = "Ayambakar12345"; // Change your Wifi/ Hotspot Password

BLYNK_WRITE(V4)
{
  int s4 = param.asInt(); 
  servo5.write(s4);
  Blynk.virtualWrite(V9, s4);
}

BLYNK_WRITE(V0) {
  int pb = param.asInt();
  digitalWrite(D4, param.asInt());
}

void setup()
{
  servo5.attach(D7);
  pinMode(D4, OUTPUT);
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
}

void loop() 
{
  Blynk.run();
}
