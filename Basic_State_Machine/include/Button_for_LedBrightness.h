/**
 * @file Button_for_LedBrightness.h
 * @brief this file declares class and function for Button
*/
#pragma once
#ifndef _BUTTON_FOR_LEDBRIGHTNESS_H
#define _BUTTON_FOR_LEDBRIGHTNESS_H
#include<Arduino.h>

#define BUTTON_ON_STATE 0
#define BUTTON_OFF_STATE 1

enum{OFF_PRESS, ON_PRESS}; //type of button
class Button{
    private:
        int PIN_BUTTON;
        uint8_t TYPE_OF_BUTTON;
        unsigned long t0,t1;
        int buttonPressedCount = 0;
        void (Button::*runningFunc)();
    public:
        void Button_init(int, uint8_t);
        void resetFunc();
        void checkButtonState();
        void updateHoldTime();
        void Transiton();
        void run();
};
#endif