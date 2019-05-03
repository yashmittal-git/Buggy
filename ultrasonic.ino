// To demonstrate the use of ultrasonic sensor by integrating line follower robocar with obstacle avoidance capability


#include <NewPing.h>
#define TRIGGER_PIN 13
#define ECHO_PIN 12
#define MAX_DISTANCE 200
NewPingsonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
void setup() {
Serial.begin(9600);
}
void loop() {
delay(50);
unsignedintuS = sonar.ping();
pinMode(ECHO_PIN,OUTPUT);
digitalWrite(ECHO_PIN,LOW);
pinMode(ECHO_PIN,INPUT);
Serial.print("Ping: ");
Serial.print(uS / US_ROUNDTRIP_CM);
Serial.println("cm");
Serial.print("uS: ");
Serial.println(uS);
Serial.print("US_ROUNDTRIP_CM: ");
Serial.println(US_ROUNDTRIP_CM);
}