// Bronze challange

// Single buggy capable of following main track twice in a clockwise direction
// under full supervisory control and obeying the “Rules” of the track.

// Buggy must be capable of detecting an obstacle whilst following the track,
// coming to a temporary halt if it does.

// It proceeds automatically when the obstacle is removed. The buggy must
// safely park in the parking bay after the two loops. No external end-user
// manual control input is permitted once the initial start is signalled.

// Messages transmitted to control your buggy, and messages received from the
// buggy must be displayed onscreen for debug purposes.

// You must also display onscreen the state of the track and buggy at each gantry
// stop.




int t1=A0;
int t2=A2;
int pin5=5;
int pin6=6;
int pin7=8;
int pin8=7;
int irPin=4;
int flag=0;
unsigned long d=0;
static int gantryCounter=0;
static long StartTime=0;
static long CurrentTime = 0;
unsigned long ElapsedTime = 0; 
static long StartTimeG=millis();;
static long CurrentTimeG = 0;
unsigned long ElapsedTimeG = 0; 
long previousMillisU = millis(); 
long intervalU = 500;  
#include <NewPing.h>
#define TRIGGER_PIN 13
#define ECHO_PIN 12
#define MAX_DISTANCE 200
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
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
        case 'Y':
      {
        flag=1;
         }
}
}
}
unsigned long currentMillisU = millis();
 if(currentMillisU - previousMillisU > intervalU) 
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
     
     if(ElapsedTimeG<2000)
     {
      flag=3;
      leftBlind();
     }
     if(ElapsedTimeG>2000 && ElapsedTimeG<7500)
     {
      flag=3;
      normalLineFollow();
     }
     if(ElapsedTimeG>7500) 
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
if (digitalRead(irPin)==HIGH)
{
 StartTime = millis();
d = pulseIn(irPin,HIGH);
 if (d>500 and d<1500) //(d > 500 and d < 1500)
            {
                Serial.println(d); 
                Serial.println("Gantry: 1");
                stopBuggy();
                delay(1000);
            }
        else if (d>2000 and d< 3000) //(d> 1500 and d < 2500)
            {
                Serial.println(d); 
                  Serial.println("Gantry: 2");
                  stopBuggy();
                  gantryCounter=gantryCounter+1;
                Serial.print("The gantry Counter is: ");
                Serial.println(gantryCounter);
                stopBuggy();
                  delay(1000);
            }
        else if (d>3000 and d<4000) //(d > 2500 and d < 3500)
            {
               Serial.println(d); 
                
                Serial.println("Gantry: 3");
                
                delay(1000);
            }
         else {
             //Serial.println(d); 
             Serial.println("Gantry: Unknown");
             
         }
 
 if (gantryCounter>=2)
{
 StartTimeG = millis();
 flag=3; 
}
else
{
gantry();
}
}
 
}
void stopBuggy()
  {
  digitalWrite(pin5,LOW);
  digitalWrite(pin6,LOW);
  digitalWrite(pin7,LOW);
  digitalWrite(pin8,LOW);
  }
void normalLineFollow()
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
  
} if(r1==LOW&&r2==HIGH)
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
void leftBlind()
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
void detectObstacle()
{
delay(50);
unsigned int distanceCm;
distanceCm = sonar.ping_cm();
pinMode(ECHO_PIN,OUTPUT);
digitalWrite(ECHO_PIN,LOW);
pinMode(ECHO_PIN,INPUT);
//Serial.print("Ping: ");
//Serial.println(distanceCm);
//Serial.println("cm");
if((distanceCm<15) && (distanceCm>0))     
{
stopBuggy();
delay(1000);
}
}