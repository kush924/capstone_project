#include <Arduino.h>

#include <variable_def.h>
#include <Wire.h>
#include <Adafruit_INA219.h>
#include <ESP32Servo.h>

#include <current_ina.cpp>
#include <stepper_motor.cpp>
#include <servo.cpp>
 
unsigned long last_time = 0;
unsigned long up_time = 1000;
unsigned long moov_time1 = 1000;
unsigned long wait_time = 4000;
unsigned long moov_time2 = 1000;
unsigned long down_time = 1000;
void setup(void)
{
  Serial.begin(115200);
  while (!Serial) 
  {
    delay(1);
  }
  millis();
 current_setup();
 motor_setup();
 servo_setup();

}
 
void loop(void){
print_current();
// ina219.getCurrent_mA()

last_time = millis();
while (millis()-last_time<=1000)
{
print_current();  
}


servo_close();
last_time = millis();
while (millis()-last_time<=up_time)
{
  fow_2();
}
last_time = millis();
while (millis()-last_time<=moov_time1)
{
  fow_1();
}

// delay(2000);

last_time = millis();
while (millis()-last_time<=wait_time)
{
  float a = ina219.getCurrent_mA();
  Serial.println(a);
  if (a>=10000)
  {
    while(1){
      print_current();
    }
  }
  
}


last_time = millis();
while (millis()-last_time<=moov_time2)
{
  fow_1();
}
last_time = millis();
while (millis()-last_time<=down_time)
{
  back_2();
}
servo_open();

while(1){
print_current();
}

}
