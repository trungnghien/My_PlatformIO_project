#include <Arduino.h>
#include<LedBrightness_HS.h>
#include<Button_for_LedBrightness.h>
#define PIN_LED 5
#define PIN_BUTTON_OFF_PRESS 7
#define PIN_BUTTON_ON_PRESS 8

LedBrightness Led1;
Button buttonOffPress, buttonOnPress;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Led1.Led_init(PIN_LED);
  buttonOffPress.Button_init(PIN_BUTTON_OFF_PRESS, OFF_PRESS);
  buttonOnPress.Button_init(PIN_BUTTON_ON_PRESS, ON_PRESS);
}
void loop() {
  // put your main code here, to run repeatedly:
  buttonOffPress.run();
  buttonOnPress.run();
}
/*#include<LEDTask.h>
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
}*/
