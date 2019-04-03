/* Moving the robocar on the track, making use of both IR and Ultrasonic sensors.
 IR sensor- to keep the buggy on the track
 Ultrasonic sensor- to stop the buggy in case an obstacle is encountered within a distance of 20 cm from the buggy.
 Here, the code is track specific and includes choosing of one path in case of ambiguity.
*/
#include <NewPing.h> 
NewPing Sonar(13,12,200);
int count=1;

void setup() {
pinMode(13,OUTPUT);
pinMode(12,INPUT);

pinMode(A0,INPUT);
pinMode(A1,INPUT);
pinMode(5,OUTPUT);
pinMode(8,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);

}

void forward()
{
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
  
  }
void backward()
{
digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(8,LOW);
  
}
void left()
{
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
  
}
void right()
{
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  
}
void clockwise()
{
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
  digitalWrite(8,LOW);
}
void anticlockwise()
{
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
  
}
 void sstop()
{
  digitalWrite(5,LOW);
  digitalWrite(8,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
}

void loop() {
 Serial.begin(9600);
 int d = Sonar.ping_cm();
  
  
 int b = digitalRead(A1); 
 int a = digitalRead(A0);
 if(d>0 && d<20){
   sstop();
  delay(2000); 
  }
 
if((a==1 && b==1)){
  forward(); 

}
else if(a==0 && b==0 && count==1)
{
backward();
}

else if(a==0 && b==0 && count==2 )
{
backward();
delay(500);
clockwise();
delay(500); 
}
   

else if(a==0 && b==1)
right();

else if (a==1 && b==0)
{
  left();
  count++;
}
}
