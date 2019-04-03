//Print ASCII values

void setup() {
    Serial.begin(9600);
    while(!Serial)
    { ;}
    Serial.println("ASCII Table || Character Map");
}

    int b = 33;
void loop() {
    Serial.write(b);
    
    Serial.print(", dec: ");
    Serial.print(b);
    
    Serial.print(", hex: ");
    Serial.print(b,HEX);
    
    Serial.print(", oct: ");
    Serial.print(b,OCT);
    
    Serial.print(", bin: ");
    Serial.println(b,BIN);
    
    if(b==126)
    {
      while(true)
        continue;
    }
    
    b++;
}
