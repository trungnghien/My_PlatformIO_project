/**
 * @file LEDTask.h
 * @brief this file declares class and function for button by basic state machine
*/
#pragma once
#include<stdint.h>
#include<LEDTask.h>
class ButtonTask {
    private:
        unsigned long t0,t1;
        int PIN_BUTTON;
        void (ButtonTask::*runningFunc)();
        
    public:
        void initButtonState(int);
        void reset();
        void checkButton();
        void checkLedStateFunc();
        void updateHoldTime();
        void turnOn_Led_2_Blink_Task();
        void checkHoldTime();
        void toggle_Led_1_Blink_Task();
        void toggleBoth2Led();
        void toggleLed(int);
        void run();

};