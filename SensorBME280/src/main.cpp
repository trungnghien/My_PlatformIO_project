#include <Arduino.h>
#include<BME280.h>
BME280 bme;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  bme.init();
}

void loop() {
  // put your main code here, to run repeatedly:
  bme.run();
  /*bme.getData();
  bme.logData();*/
}
