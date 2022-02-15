//SERVO TEST

#define COUNT_LOW 1500
#define COUNT_HIGH 8500
#define TIMER_WIDTH 16
#include "esp32-hal-ledc.h"
#include <M5StickC.h>

void setup() {
  M5.begin(); // display initialization
  ledcSetup(1, 50, TIMER_WIDTH); // configuration of PWM channel; set (channel, frequency, resolution) 
  ledcAttachPin(26, 1); // set the Pin to the PWM channel 
  M5.Lcd.setCursor(25, 80, 4); 
  M5.Lcd.print("SERVO");
}

void loop() {
  for(int i = COUNT_LOW; i < COUNT_HIGH; i = i + 100){  
    ledcWrite(1, i); // specific the value of duty cicle 
    delay(50);
  }
}
