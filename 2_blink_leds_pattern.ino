//blinking LEDs in pattern

void setup() {
  int i;
  for(i=1;i<=4;i++)
    pinMode(i,OUTPUT);  
}

void loop() {
  int i;
  for(i=1;i<=4;i++)
  { 
    digitalWrite(i,HIGH);
    delay(1000);
  }
  for(i=1;i<=4;i++)
  { 
    digitalWrite(i,LOW);
    delay(1000);
  }
}
