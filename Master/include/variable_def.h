#include <Wire.h>
#include <Adafruit_INA219.h>
#include <ESP32Servo.h>

#ifndef VARIABLE_H
#define VARIABLE_H

Servo myservo;  
Adafruit_INA219 ina219;

int pos = 0;



#define dir_1 32
#define pul_1 33
#define dir_2 25
#define pul_2 26
#define servoPin 18
// #define scl 22
// #define sda 21


#endif