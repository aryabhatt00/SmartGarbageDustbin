/**************************************************************
 * Blynk is a platform with iOS and Android apps to control
 * Arduino, Raspberry Pi and the likes over the Internet.
 * You can easily build graphic interfaces for all your
 * projects by simply dragging and dropping widgets.
 *
 *   Downloads, docs, tutorials: http://www.blynk.cc
 *   Blynk community:            http://community.blynk.cc
 *   Social networks:            http://www.fb.com/blynkapp
 *                               http://twitter.com/blynk_app
 *
 * Blynk library is licensed under MIT license
 * This example code is in public domain.
 *
 **************************************************************
 * This example runs directly on ESP8266 chip.
 *
 * You need to install this for ESP8266 development:
 *   https://github.com/esp8266/Arduino
 *
 * Please be sure to select the right ESP8266 module
 * in the Tools -> Board menu!
 *
 * Change WiFi ssid, pass, and Blynk auth token to run :)
 *
 **************************************************************/
  // Comment this out to disable prints and save space
  #define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "4xGds4XQVfCnzPn6WBT0QvUQwoe70M5g";//Enter the token you got from the blynk project from the app
const int trigP = 2;  //D4 Or GPIO-2 of nodemcu
const int echoP = 0;  //D3 Or GPIO-0 of nodemcu

long duration;
int distance;
void setup()
{  Serial.print("hello"); 
  Serial.begin(115200);
  Blynk.begin("4xGds4XQVfCnzPn6WBT0QvUQwoe70M5g", "Arya", "arya0078");// Enter your Wifi SSID and password, both inside the double quotation
  pinMode(trigP, OUTPUT);  // Sets the trigPin as an Output
  pinMode(echoP, INPUT);   // Sets the echoPin as an Input
  digitalWrite(trigP,LOW);
  
  
}

void loop()
{
  digitalWrite(trigP, HIGH);  // tigPin high
  delayMicroseconds(10);      // trigPin high for 10 micro seconds
  digitalWrite(trigP, LOW);   // trigPin low
  duration = pulseIn(echoP, HIGH);   //Read echo pin, time in microseconds
  delay(1000);
  distance= duration*0.034/2;        //Calculating actual/real distance

  Serial.print("Distance = ");        //Output distance on arduino serial monitor 
  Serial.println(distance);
  if(distance<40)
  {
    Blynk.email("raghavendraraghu6699@gmail.com","Full","exceeded");
    Blynk.notify("FUll Exceded wew");
                        //Pause for 3 seconds and start measuring distance again
  Blynk.virtualWrite(V3,255);
  Blynk.notify("ayyyyyy raghuuu");
}delay(2000);
}
