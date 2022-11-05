#include<configs.h>
#include<Wire.h>
#include<BME280_SM.h>
void BME280_SM::init(){
    if(Wire.begin(PIN_SDA_GPIO, PIN_SCL_GPIO, I2C_CLOCK_SPEED))
    {
        Serial.println("I2C init success!");
    }
    else for(;;); // reset ESP
    
    bool status = bme280.begin(BME280_I2C_ADDRESS);
    if(status==0){
        Serial.println("Could not find a valid BME280 sensor, check wiring!");
        while (true);
    }
    stateFunc = &BME280_SM::resetFunc;
}
void BME280_SM::resetFunc(){
    t0 = millis();
    if(true)
        stateFunc = &BME280_SM::checkTimetoLogData;
}
void BME280_SM::checkTimetoLogData(){
    t1 = millis();
    if(t1-t0> DELAY_TIME)
        stateFunc = &BME280_SM::getData;
}
void BME280_SM::getData(){
    this->Humidity      = this->bme280.readHumidity();
    this->Temperature   = this->bme280.readTemperature();
    this->Pressure      = this->bme280.readPressure();
    stateFunc = &BME280_SM::logData;
}
void BME280_SM::logData(){
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
    //delay(DELAY_TIME);
    if(true)
        stateFunc = &BME280_SM::resetFunc;
}
float BME280_SM::getHumidity()
{
    return Humidity;
}
float BME280_SM::getTemperature()
{
    return Temperature;
}
float BME280_SM::getPressure()
{
    return Pressure;
}
void BME280_SM::run(){
    (this->*stateFunc)();
}
