/**
 * @file LEDTask.h
 * @brief this file declares class and function for Led by basic state machine
*/
#pragma once
#include<stdint.h>
class LedTask {
    private:
        uint32_t blinkTime;
        unsigned long t0,t1;
        bool LED_STATE;
        int PIN_LED;
        bool isTurnOn; // variable defines ON/OFF state of process
        void (LedTask::*runningFunc)();
    public:
        void resetFunc ();
        void checkTimesFunc();
        void checkLedStateFunc();
        void turnOnLedFunc();
        void turnOffLedFunc();
        void initLedState(int, uint32_t);
        void run();
        void toggle(bool);
        bool isTaskOn();
        int getPinLed();

};
extern LedTask led1,led2;