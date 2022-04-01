#include <Arduino.h>
#include "src/incs.h"
#include <ESP8266WiFi.h>

// Preparação do sensor DHT11
#include "lib/DHT_sensor_library/DHT.h"

#define test
// Preparação do sensor DHT11
#include "DHT.h"
#define DHTPIN 4 //pino digital conectado ao DHT11 (gpio4 - d2)
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

float hu = NULL;
float tempC = NULL;
float tempF = NULL;
float temp_index = NULL;

void setup(){
  Serial.begin(115200);
  init_wifi();
  delay(1000);
  dht.begin();
}

void loop() {
  delay(1000);
  read_humidity_temperature();
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