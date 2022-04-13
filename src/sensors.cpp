#include <Arduino.h>
void read_humidity_temperature(){ //Readings of humidity and temperature may take up to 2s and the post data processing takes aaround 250ms (pretty slow sensor)
  hu = dht.readHumidity(); //Reads humidity values, raw alrd in map
  tempC = dht.readTemperature(); //Reads temperature in celcius
  tempF = dht.readTemperature(true); //Reads temperature in celcius

  //Runs a data sanity check
  #ifdef test
  if (isnan(hu) || isnan(tempC)) {
    Serial.println(F("Sensor failure!"));
    return;
  }
  #endif
  //Calculate temperature index using celcius
  temp_index = dht.computeHeatIndex(tempC, hu, false);
}

void read_air_pressure(){
  
}

int read_wind_speed(){
  return 0;
}