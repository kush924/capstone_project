
#include <variable_def.h>
#include <Wire.h>
#include <Adafruit_INA219.h>
#include <ESP32Servo.h>

void current_setup(){
    // INA219 Initilize
  if (! ina219.begin())
  {
    Serial.println("Failed to find INA219 chip");
  }
  ina219.setCalibration_32V_1A();
 
  Serial.println("Measuring voltage, current, and power with INA219 ...");
}

void print_current(){
    Serial.println(ina219.getCurrent_mA()); 
}