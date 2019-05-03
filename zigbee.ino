//Program to control buggy into full supervisory mode using serial communication.

void setup()
{
Serial.begin(9600); 
pinMode(5, OUTPUT); 
pinMode(6, OUTPUT); 
pinMode (7, OUTPUT); 
pinMode(8, OUTPUT); 
}
void forward()
{
digitalWrite(5,HIGH); 
digitalWrite(6,LOW); 
digitalWrite(7,LOW); 
digitalWrite(8,HIGH);
 }
void Backward()
{
digitalWrite(5,LOW); 
digitalWrite(6,HIGH); 
digitalWrite(7,HIGH); 
digitalWrite(8,LOW);
}
void Anti_Rotation()
{
digitalWrite(5,HIGH); 
digitalWrite(6,LOW); 
digitalWrite(7,HIGH); 
digitalWrite(8,LOW); 
}
void Clock_Rotation()
{
digitalWrite(5,LOW); 
digitalWrite(6,HIGH); 
digitalWrite(7,LOW); 
digitalWrite(8,HIGH); 
}
void stops()
{
digitalWrite(5,LOW); 
digitalWrite(6,LOW); 
digitalWrite(7,LOW); 
digitalWrite(8,LOW); 
}
void loop()
{
if(Serial.available()>0) 
{
s=Serialread();
if(s=='F') 
{ forward();
}
else if(s=='B')
{ Backward();
}
else if(s=='R')
{
Clock_Rotation();
}
else if(s=='L')
{
Anti_Rotation();
} 
}
}
