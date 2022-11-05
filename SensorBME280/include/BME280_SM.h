#pragma once
#ifndef _BME280_SM_H_
#define _BME280_SM_H_

#include<Arduino.h>
#include<stdint.h>
#include<Adafruit_Sensor.h>
#include<Adafruit_BME280.h>

#define BME280_I2C_ADDRESS  0x76
#define DELAY_TIME 1000
class BME280_SM {
private:
    Adafruit_BME280 bme280;
    float Temperature;
    float Humidity;
    float Pressure;
    unsigned long t0,t1;
    void (BME280_SM::*stateFunc)();
public:
    void init();
    void resetFunc();
    void checkTimetoLogData();
    void logData();
    void getData();
    float getHumidity();
    float getTemperature();
    float getPressure();
    void run();
    
};

#endif