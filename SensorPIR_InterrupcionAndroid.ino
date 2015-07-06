int pinLED = 13;
int pinSENSOR=3;
int interrupt=1;

void setup() {
  Serial.begin(9600);
  attachInterrupt(interrupt, IntFuncion, RISING  );
  pinMode(pinLED, OUTPUT);
  pinMode(pinSENSOR, INPUT);
  digitalWrite(pinLED, LOW);

}


void loop() {
  if(Serial.available()){
     while(Serial.available() > 0){
      char byteIn = Serial.read();
     
      cmdHandle(byteIn);
   Serial.println(byteIn);
  
    }
  }
}

void IntFuncion(){
  
 // digitalWrite(pinLED, HIGH);

   detachInterrupt(interrupt);
    
  Serial.write("2");
  attachInterrupt(interrupt, IntFuncion, RISING  );
 // digitalWrite(pinLED, LOW);
}


void cmdHandle(byte incomingByte){
  
  
  switch(incomingByte){
    case '1':
         digitalWrite(pinLED, HIGH);
          Serial.write("s");
        break;
    case '2':
         digitalWrite(pinLED, LOW);
        Serial.write("n");
        break;
    default: //Serial.println("E");
    break;
     }
  
}



