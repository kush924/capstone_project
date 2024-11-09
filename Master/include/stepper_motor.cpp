
#include <variable_def.h>
#include <Wire.h>
#include <Adafruit_INA219.h>
#include <ESP32Servo.h>

int DIR_1 = dir_1;    // DIR- pin
int PUL_1 = pul_1;    // PUL- pin
int DIR_2 = dir_2;    // DIR- pin
int PUL_2 = pul_2;    // PUL- pin
unsigned long int ms = 50;
unsigned long int count = 0 , precount = 0 ;

void motor_setup() {
  pinMode (DIR_1, OUTPUT);
  pinMode (PUL_1, OUTPUT);
  pinMode (DIR_2, OUTPUT);
  pinMode (PUL_2, OUTPUT);
}

void moov_1(){
  if((micros()-count)>=ms){
    digitalWrite(PUL_1,HIGH);
    Serial.print("high");
  }//delay(t);
  if((micros()-count)>=(ms*2)){
    digitalWrite(PUL_1,LOW);
    Serial.print("low");
  count=micros();
  }//delay(t);  
}

void back_1(){
    digitalWrite(DIR_1,LOW);
    Serial.println("fow");
    moov_1();
}

void fow_1(){
    digitalWrite(DIR_1,HIGH);
    Serial.println("back");
    moov_1();

}



void moov_2(){
  if((micros()-count)>=ms){
    digitalWrite(PUL_2,HIGH);
    Serial.print("high");
  }//delay(t);
  if((micros()-count)>=(ms*2)){
    digitalWrite(PUL_2,LOW);
    Serial.print("low");
  count=micros();
  }//delay(t);  
}

void back_2(){
    digitalWrite(DIR_2,LOW);
    Serial.println("fow");
    moov_2();
}

void fow_2(){
    digitalWrite(DIR_2,HIGH);
    Serial.println("back");
    moov_2();

}
