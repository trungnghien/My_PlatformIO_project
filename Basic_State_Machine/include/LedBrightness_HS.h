/**
 * @file LedBrightness_HS.h
 * @brief this file declares class and function for Led by Harel state machine
*/
#pragma once
#ifndef _LEDBRIGHTNESS_SH_
#define _LEDBRIGHTNESS_SH_
#include<Arduino.h>
#define BRIGHTNESS_OFF_VALUE 0
#define BRIGHTNESS_LOW_VALUE 64
#define BRIGHTNESS_MEDIUM_VALUE 127
#define BRIGHTNESS_HIGH_VALUE 255

enum{BRIGHTNESS_OFF,BRIGHTNESS_LOW, BRIGHTNESS_MEDIUM, BRIGHTNESS_HIGH};//Brightness level

class LedBrightness{
    private:
        int PIN_LED;
        uint8_t birghtnessLevel;
    public:
        void Led_init(int);
        void Led_onState();
        void Led_offState();
        void setBrightnessLevel(uint8_t);

};
extern LedBrightness Led1;
#endif