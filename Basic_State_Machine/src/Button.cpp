#include<ButtonTask.h>
#include<Arduino.h>
void ButtonTask::initButtonState(int PIN_BUTTON){
    this->PIN_BUTTON = PIN_BUTTON;
    pinMode(PIN_BUTTON,INPUT_PULLUP);
    runningFunc = &reset;
}
void ButtonTask::reset(){
    t0=millis();
    t1=t0;
    if(true)
        runningFunc = &checkButton;
}
void ButtonTask::checkButton(){
    bool BUTTON_STATE = digitalRead(PIN_BUTTON);
 
    if (BUTTON_STATE == LOW) // button is pressed
        runningFunc = &udateHoldTime;
    else
        runningFunc = &checkHoldTime;
}
void ButtonTask::udateHoldTime(){
    t1 = millis();
    unsigned long delta_time = t1-t0;
    if(delta_time > 1000)
        runningFunc = &turnOn_Led_2_Blink_Task;
    else 
        runningFunc = &checkButton;
}
void ButtonTask::turnOn_Led_2_Blink_Task(){
    led2.toggle(true);
    if(true)
        runningFunc = &checkButton;
}
void ButtonTask::checkHoldTime(){
    if(led2.isTaskOn())
        led2.toggle(false);
    unsigned long delta_time = t1-t0;
    if(delta_time > 1000)
        runningFunc = &toggle_Led_1_Blink_Task;
    else if(delta_time > 10)
        runningFunc = &toggleBoth2Led;
    else
        runningFunc = &reset;
}
void ButtonTask::toggle_Led_1_Blink_Task(){
    led1.toggle(!led1.isTaskOn());
    if(true)
        runningFunc = &reset;
}
void ButtonTask::toggleBoth2Led(){
    if(led1.isTaskOn())
        led1.toggle(false);
    toggleLed(led1.getPinLed());
    toggleLed(led2.getPinLed());
    if(true)
        runningFunc = &reset;
}
void ButtonTask::toggleLed(int pin){
    bool last_state = digitalRead(pin);
    digitalWrite(pin,!last_state);
}
void ButtonTask::run(){
    (this->*runningFunc)();
}
