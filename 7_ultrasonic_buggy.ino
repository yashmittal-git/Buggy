/*
Ultrasonic Line follower
*/

#include<NewPing.h>
#define TRIGGER_PIN 13
#define ECHO_PIN 12
#define MAX_DISTANCE 200
NewPing sonar(TRIGGER_PIN,ECHO_PIN,MAX_DISTANCE);
void setup() {
  Serial.begin(9600);
}

void loop() {
  delay(50);
  unsigned int uS = sonar.ping();
  pinMode(ECHO_PIN,OUTPUT);
  digitalWrite(ECHO_PIN,0);
  pinMode(ECHO_PIN,INPUT);
  
  Serial.print("Ping:");
  Serial.print(uS/US_ROUNDTRIP_CM);
  Serial.println("cm");
  Serial.print("uS:");
  Serial.println(uS);
  Serial.print("US_ROUNDTRIP_CM:");
  Serial.println(US_ROUNDTRIP_CM);
}
