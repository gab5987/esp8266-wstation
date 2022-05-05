#include <Arduino.h>
void read_humidity_temperature(float *hu, float *tempC, float *tempF, float *temp_index);
void send_thingspeak(String string_data);
void init_wifi(void);
void conect_wifi(void);
void verify_wifi(void);
void read_air_pressure();
int read_wind_speed();