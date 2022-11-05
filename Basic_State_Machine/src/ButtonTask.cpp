#include<ButtonTask.h>
#include<Arduino.h>
void ButtonTask::initButtonState(int PIN_BUTTON){
    this->PIN_BUTTON = PIN_BUTTON;
    pinMode(PIN_BUTTON,INPUT_PULLUP);
    runningFunc = &ButtonTask::reset;
}
void ButtonTask::reset(){
    t0=millis();
    t1=t0;
    if(true)
        runningFunc = &ButtonTask::checkButton;
}
void ButtonTask::checkButton(){
    bool BUTTON_STATE = digitalRead(PIN_BUTTON);
 
    if (BUTTON_STATE == LOW) // button is pressed
        runningFunc = &ButtonTask::updateHoldTime;
    else
        runningFunc = &ButtonTask::checkHoldTime;
}
void ButtonTask::updateHoldTime(){
    t1 = millis();
    unsigned long delta_time = t1-t0;
    if(delta_time > 1000)
        runningFunc = &ButtonTask::turnOn_Led_2_Blink_Task;
    else 
        runningFunc = &ButtonTask::checkButton;
}
void ButtonTask::turnOn_Led_2_Blink_Task(){
    led2.toggle(true);
    if(true)
        runningFunc = &ButtonTask::checkButton;
}
void ButtonTask::checkHoldTime(){
    if(led2.isTaskOn())
        led2.toggle(false);
    unsigned long delta_time = t1-t0;
    if(delta_time > 1000)
        runningFunc = &ButtonTask::toggle_Led_1_Blink_Task;
    else if(delta_time > 10)
        runningFunc = &ButtonTask::toggleBoth2Led;
    else
        runningFunc = &ButtonTask::reset;
}
void ButtonTask::toggle_Led_1_Blink_Task(){
    led1.toggle(!led1.isTaskOn());
    if(true)
        runningFunc = &ButtonTask::reset;
}
void ButtonTask::toggleBoth2Led(){
    if(led1.isTaskOn())
        led1.toggle(false);
    toggleLed(led1.getPinLed());
    toggleLed(led2.getPinLed());
    if(true)
        runningFunc = &ButtonTask::reset;
}
void ButtonTask::toggleLed(int pin){
    bool last_state = digitalRead(pin);
    digitalWrite(pin,!last_state);
}
void ButtonTask::run(){
    (this->*runningFunc)();
}
