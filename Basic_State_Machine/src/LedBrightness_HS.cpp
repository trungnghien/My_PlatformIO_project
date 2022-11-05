#include<LedBrightness_HS.h>
void LedBrightness :: Led_init(int PIN_LED){
    this->PIN_LED = PIN_LED;
    pinMode(PIN_LED, OUTPUT);
    this->birghtnessLevel = BRIGHTNESS_OFF;
}
void LedBrightness::setBrightnessLevel(uint8_t brightnessLevel){
    this->birghtnessLevel = brightnessLevel;
}
void LedBrightness::Led_offState(){
    analogWrite(PIN_LED, BRIGHTNESS_OFF_VALUE);
}
void LedBrightness::Led_onState(){
    switch (this->birghtnessLevel)
    {
    case BRIGHTNESS_LOW:
        analogWrite(PIN_LED, BRIGHTNESS_LOW_VALUE);
        break;
    case BRIGHTNESS_MEDIUM:
        analogWrite(PIN_LED, BRIGHTNESS_MEDIUM_VALUE);
        break;
    case BRIGHTNESS_HIGH:
        analogWrite(PIN_LED, BRIGHTNESS_HIGH_VALUE);
        break;
    }
}
