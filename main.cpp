#include <Arduino.h>
#include "src/incs.h"
//#define debug

// Preparação do sensor DHT11
#include "lib/DHT_sensor_library/DHT.h"
#define DHTPIN 4 //pino digital conectado ao DHT11 (gpio4 - d2)
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

float umidade = NULL;
float temperatura = NULL;
float sensacao_termica = NULL;

void le_umidade_temperatura();

void setup() {
  Serial.begin(115200);
  dht.begin();
}

void loop() {
  delay(1000);
  le_umidade_temperatura();

  #ifndef teste
  Serial.print(umidade);
  Serial.print(" ");
  Serial.print(temperatura);
  Serial.print(" ");
  Serial.print(sensacao_termica);
  Serial.println();
  #endif
}
