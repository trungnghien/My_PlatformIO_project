#include <Arduino.h>
#include<BME280_SM.h>

BME280_SM SM_bme280;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  SM_bme280.init();
  
}

void loop() {
  // put your main code here, to run repeatedly:
  SM_bme280.run();
}
