#include<Button_for_LedBrightness.h>
#include<LedBrightness_HS.h>
void Button::Button_init(int PIN_BUTTON, uint8_t TYPE_OF_BUTTON){
    this->PIN_BUTTON = PIN_BUTTON;
    this->TYPE_OF_BUTTON = TYPE_OF_BUTTON;
    pinMode(PIN_BUTTON, INPUT_PULLUP);
    runningFunc = &Button::resetFunc;
}
void Button::resetFunc(){
    t0=millis();
    t1=t0;
    if(true)
        runningFunc = &Button::checkButtonState;
}
void Button::checkButtonState(){
    bool BUTTON_STATE = digitalRead(PIN_BUTTON);
    if (BUTTON_STATE == BUTTON_ON_STATE){ // button is pressed
        runningFunc = &Button::updateHoldTime;
    }
    else
        runningFunc = &Button::resetFunc;
}
void Button::updateHoldTime(){
    t1 = millis();
    unsigned long delta_time = t1-t0;
    if(delta_time > 100){
        buttonPressedCount = (buttonPressedCount%3)+1;
        runningFunc = &Button::Transiton;
    }
    else 
        runningFunc = &Button::checkButtonState;
}
void Button::Transiton(){
    if(this->TYPE_OF_BUTTON == ON_PRESS){
        Led1.setBrightnessLevel(buttonPressedCount);
        Led1.Led_onState();
    }
    else{
        buttonPressedCount = 0;
        Led1.setBrightnessLevel(BRIGHTNESS_OFF);
        Led1.Led_offState();
    }
    //debug
    Serial.print("Brightness level: ");
    Serial.println(buttonPressedCount);
    runningFunc=&Button::resetFunc;
}
void Button::run(){
    (this->*runningFunc)();
}