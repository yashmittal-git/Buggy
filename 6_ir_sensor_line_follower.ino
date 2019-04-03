/*
Move Nvis 3302ARD Robo car on the path(black line) sketched, using IR sensors.
*/
void forward()
{
  digitalWrite(5,1);
  digitalWrite(6,0);
  digitalWrite(7,0);
  digitalWrite(8,1);
}
void back()
{
  digitalWrite(5,0);
  digitalWrite(6,1);
  digitalWrite(7,1);
  digitalWrite(8,0);
}
void left()
{
  digitalWrite(5,1);
  digitalWrite(6,0);
  digitalWrite(7,0);
  digitalWrite(8,0);
}
void right()
{
  digitalWrite(5,0);
  digitalWrite(6,0);
  digitalWrite(7,0);
  digitalWrite(8,1);
}
void stopit()
{
  digitalWrite(5,0);
  digitalWrite(6,0);
  digitalWrite(7,0);
  digitalWrite(8,0);
}

int r1,r2;

void setup() {
  int i;
  
  for(i=5;i<=8;i++)
  pinMode(i,OUTPUT);  

  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
}

void loop() {
  r1=digitalRead(A0);
  r2=digitalRead(A1);  

  if(r1==1 && r2==1)
  forward();
  else if(r1=0 && r2==1)
  left();
  else if(r1=1 && r2==0)
  right();
  else if(r1==0 && r2==0)
  stopit();
}
