#include <LEDTask.h>
#include<Arduino.h>
void LedTask :: resetFunc(){
    t0 = millis();
    if(isTurnOn){
        runningFunc = &checkTimesFunc;
    }
}
void LedTask::checkTimesFunc(){
    t1 = millis();
    if(t1-t0 > blinkTime){
        runningFunc = &checkLedStateFunc;
    }
}
void LedTask::checkLedStateFunc(){
    LED_STATE = digitalRead(PIN_LED);
    if(LED_STATE == HIGH) {
        runningFunc = &turnOffLedFunc;
    }
    else{
        runningFunc = &turnOnLedFunc;
    }
}
void LedTask::turnOffLedFunc(){
    digitalWrite(PIN_LED,LOW);
    if(true){
        runningFunc = &resetFunc;
    }
}
void LedTask::turnOnLedFunc(){
    digitalWrite(PIN_LED,HIGH);
    if(true){
        runningFunc = &resetFunc;
    }
}
void LedTask::initLedState(int PIN_LED, uint32_t blinkTime){
    this->PIN_LED = PIN_LED;
    this->blinkTime = blinkTime;
    isTurnOn = false;
    pinMode(PIN_LED, OUTPUT);
    runningFunc = &resetFunc;
}
void LedTask::run(){
    (this->*runningFunc)();
}

void LedTask::toggle(bool toggleState) {
      isTurnOn = toggleState;
      // Nếu tắt task thì tắt luôn cả led và chuyển về trạng thái reset
      if (toggleState == false) {
        runningFunc = &resetFunc;
        digitalWrite(PIN_LED, 0);
      }
    }
 
bool LedTask::isTaskOn() {
      return isTurnOn;
}
int LedTask::getPinLed(){
    return this->PIN_LED;
}