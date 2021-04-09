#include<Tello.h>
#include <ESP8266WiFi.h>

// tello settings
const char* DEFAULT_SSID = "deadgost";
const char* DEFAULT_PW = "karan123";

// creating tello object

Tello tello;

void setup() {
  Serial.begin(9600);
  
  //connecting to Wifi 
  Serial.println("Connecting to ");
 Serial.println(DEFAULT_SSID);
  WiFi.begin(DEFAULT_SSID, DEFAULT_PW);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  
  // init tello 
  tello.init();
}

void loop(){
  // take off the drone
  Serial.println("Take Off ");
  tello.takeoff();
  // wait 5 sec
  delay(5000);
  // land the drone
  Serial.println("Land : ");
  tello.land();
  // wait for 10 sec
  delay(10000);
  // then again repaeat
}
