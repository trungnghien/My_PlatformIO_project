#include <Arduino.h>
#include<LEDTask.h>
#include<ButtonTask.h>
#define PIN_LED_1 12
#define PIN_LED_2 13
#define PIN_BUTTON 8
LedTask led1,led2;
ButtonTask button;
void setup() {
  // put your setup code here, to run once:
  led1.initLedState(PIN_LED_1,1000);
  led2.initLedState(PIN_LED_2,100);
  button.initButtonState(PIN_BUTTON);
}

void loop() {
  // put your main code here, to run repeatedly:
  button.run();
  led1.run();
  led2.run();
}
