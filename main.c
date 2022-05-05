#include <Arduino.h>
#include "src/incs.h"
#include <ESP8266WiFi.h>
#define test

// init DHT11 sensor lib
#include "lib/DHT_sensor_library/DHT.h"
#include "DHT.h"
#define DHTPIN 4 //pino digital conectado ao DHT11 (gpio4 - d2)
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

int main(void){
float hu = NULL;
float tempC = NULL;
float tempF = NULL;
float temp_index = NULL;

  Serial.begin(115200);
  init_wifi();
  delay(1000);
  dht.begin();

  while(1){
    delay(1000);
    read_humidity_temperature(&hu, &tempC, &tempF, &temp_index);
    read_air_pressure();
    read_wind_speed();

    #ifdef test
    Serial.print(hu);
    Serial.print(" ");
    Serial.print(tempC);
    Serial.print(" ");
    Serial.print(temp_index);
    Serial.println();
    #endif
  }
}