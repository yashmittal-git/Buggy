// Program to read the pulse width of gantry transmitter and trigger stop_buggy function by detecting individual gantry.

int t1=A0;
int t2=A2;
int pin5=5;
int pin6=6;
int pin7=8;

int pin8=7;
intirPin=4;
int flag=0;
unsigned long d=0;
staticintgantryCounter=0;
static long StartTime=0;
static long CurrentTime = 0;
unsigned long ElapsedTime = 0; 
static long StartTimeG=millis();;
static long CurrentTimeG = 0;
unsigned long ElapsedTimeG = 0; 
longpreviousMillisU = millis(); 
longintervalU = 500;  
#include <NewPing.h>
#define TRIGGER_PIN 13
#define ECHO_PIN 12
#define MAX_DISTANCE 200
NewPingsonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
void setup() {
pinMode(pin5,OUTPUT);  
pinMode(pin6,OUTPUT);  
pinMode(pin7,OUTPUT);
pinMode(pin8,OUTPUT);
pinMode(t1,INPUT);
pinMode(t2,INPUT);
Serial.begin(9600);
Serial.print("+++");  // Enter xbee AT command mode, NB no carriage return here
delay(1500);          // Guard time
Serial.println("ATID 3333, CH C, CN");
}

void loop() {
if(flag==0)
{
if (Serial.available() > 0)
{
char s = Serial.read();
switch (s) {
case 'G':
      {
flag=1;
         }
}
}
}
unsigned long currentMillisU = millis();

if(currentMillisU - previousMillisU>intervalU) 
       {

previousMillisU = currentMillisU;  
detectObstacle(); 
       }

if (flag==1)
{
gantry();


}

if (flag==3)
   {
     //gantryParking();
CurrentTimeG=millis();
ElapsedTimeG = CurrentTimeG-StartTimeG;

if(ElapsedTimeG<1500)
     {
flag=3;
leftBlind();
     }
if(ElapsedTimeG>1500 &&ElapsedTimeG<3500)
     {
flag=3;
normalLineFollow();
     }
if(ElapsedTimeG>35                                                                                                                                                               00) 
     {
stopBuggy();
Serial.print("Buggy:1 Parked");
Serial.println(ElapsedTimeG);
delay(2000);
flag=-1;
     }

    }
}

void gantry()
{
int r1=digitalRead(t1);
int r2=digitalRead(t2);
if(r1==LOW&&r2==LOW)
{
digitalWrite(pin5,HIGH);
digitalWrite(pin6,LOW);
digitalWrite(pin7,HIGH);
digitalWrite(pin8,LOW);

}
if(r1==LOW&&r2==HIGH)
{
digitalWrite(pin5,HIGH);
digitalWrite(pin6,LOW);
digitalWrite(pin7,LOW);
digitalWrite(pin8,LOW);

} if(r1==HIGH&&r2==LOW)
{
digitalWrite(pin5,LOW);
digitalWrite(pin6,LOW);
digitalWrite(pin7,HIGH);
digitalWrite(pin8,LOW);
 }
if(r1==HIGH&&r2==HIGH)
{
digitalWrite(pin5,HIGH);
digitalWrite(pin6,LOW);
digitalWrite(pin7,HIGH);
digitalWrite(pin8,LOW);
}
}
voidstopBuggy()
  {
digitalWrite(pin5,LOW);
digitalWrite(pin6,LOW);
digitalWrite(pin7,LOW);
digitalWrite(pin8,LOW);
  }
voidnormalLineFollow()
{
int r1=digitalRead(t1);
int r2=digitalRead(t2);
if(r1==LOW&&r2==LOW)
{
digitalWrite(pin5,HIGH);
digitalWrite(pin6,LOW);
digitalWrite(pin7,HIGH);
digitalWrite(pin8,LOW);

}
if(r1==HIGH&&r2==LOW)
{
digitalWrite(pin5,LOW);
digitalWrite(pin6,LOW);
digitalWrite(pin7,HIGH);
digitalWrite(pin8,LOW);

} 
if(r1==LOW&&r2==HIGH)
{
digitalWrite(pin5,HIGH);
digitalWrite(pin6,LOW);
digitalWrite(pin7,LOW);
digitalWrite(pin8,LOW);
}
if(r1==HIGH&&r2==HIGH)
{
digitalWrite(pin5,HIGH);
digitalWrite(pin6,LOW);
digitalWrite(pin7,HIGH);
digitalWrite(pin8,LOW);

}
}
voidleftBlind()
{

int r2=digitalRead(t2);

if(r2==LOW)
{
digitalWrite(pin5,LOW);
digitalWrite(pin6,LOW);
digitalWrite(pin7,HIGH);
digitalWrite(pin8,LOW);

} 
if(r2==HIGH)
{
digitalWrite(pin5,HIGH);
digitalWrite(pin6,LOW);
digitalWrite(pin7,HIGH);
digitalWrite(pin8,LOW);

}
}