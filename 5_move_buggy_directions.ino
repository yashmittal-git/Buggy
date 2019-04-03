/*
Move Nvis 3302ARD Robo car in front, right, lest, back, clockwise and anticlockwise direction.
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
void clockwise()
{
  digitalWrite(5,0);
  digitalWrite(6,1);
  digitalWrite(7,0);
  digitalWrite(8,1);
}
void anticlockwise()
{
  digitalWrite(5,1);
  digitalWrite(6,0);
  digitalWrite(7,1);
  digitalWrite(8,0);
}
void setup() {
  int i;
  for(i=5;i<=8;i++)
  pinMode(i,OUTPUT);
}

void loop() {
  forward();
  delay(2000);
  back();
  delay(2000);
  right();
  delay(2000);
  left();
  delay(2000);
  clockwise();
  delay(2000);
  anticlockwise();
  delay(2000);
}
