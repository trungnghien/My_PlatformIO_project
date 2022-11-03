#include<BME280.h>
void BME280::init(){
    bool status = bme280.begin(BME280_I2C_ADDRESS);
    if(status==0){
        Serial.println("Could not find a valid BME280 sensor, check wiring!");
        while (true);
    }
    stateFunc = &resetFunc;
}
void BME280::resetFunc(){
    t0 = millis();
    if(true)
        stateFunc = &checkTimetoLogData;
}
void BME280::checkTimetoLogData(){
    t1 = millis();
    if(t1-t0> DELAY_TIME)
        stateFunc = &getData;
}
void BME280::getData(){
    this->Humidity      = this->bme280.readHumidity();
    this->Temperature   = this->bme280.readTemperature();
    this->Pressure      = this->bme280.readPressure();
    stateFunc = &logData;
}
void BME280::logData(){
    Serial.print("Temperature = ");
    Serial.print(Temperature);
    Serial.println("°C");

    Serial.print("Humidity = ");
    Serial.print(Humidity);
    Serial.println("%");

    Serial.print("Pressure  = ");
    Serial.print(Pressure);
    Serial.println("Pa");

    Serial.println();
    delay(DELAY_TIME);
    if(true)
        stateFunc = &resetFunc;
}
float BME280::getHumidity()
{
    return Humidity;
}
float BME280::getTemperature()
{
    return Temperature;
}
float BME280::getPressure()
{
    return Pressure;
}
void BME280::run(){
    (this->*stateFunc)();
}
