
int driverPUL = 27;    // PUL- pin
int driverDIR = 26;    // DIR- pin
unsigned long int ms = 500;
unsigned long int count = 0 , precount = 0 ;


#include <Arduino.h>

void moov(){
  if((micros()-count)>=ms){
    digitalWrite(driverPUL,HIGH);
    Serial.print("high");
  }//delay(t);
  if((micros()-count)>=(ms*2)){
    digitalWrite(driverPUL,LOW);
    Serial.print("low");
  count=micros();
  }//delay(t);  
}

void back(){
    digitalWrite(driverDIR,LOW);
    Serial.println("fow");
    moov();
}

void fow(){
    digitalWrite(driverDIR,HIGH);
    Serial.println("back");
    moov();

}



void setup() {
Serial.begin(115200);
 pinMode (driverPUL, OUTPUT);
  pinMode (driverDIR, OUTPUT);
}

void loop() {
  fow();
}



