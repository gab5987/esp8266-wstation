#define SSID_NET " " // Network name
#define PASSWORD " " // Network password
 
char api_thingspeak[] = "api.thingspeak.com";
String key_thingspeak = " ";  // channel key
WiFiClient client;
 
void send_thingspeak(String string_data){
    if (client.connect(api_thingspeak, 80))
    {
        client.print("POST /update HTTP/1.1\n");
        client.print("Host: api.thingspeak.com\n");
        client.print("Connection: close\n");
        client.print("X-THINGSPEAKAPIKEY: "+key_thingspeak+"\n");
        client.print("Content-Type: application/x-www-form-urlencoded\n");
        client.print("Content-Length: ");
        client.print(string_data.length());
        client.print("\n\n");
        client.print(string_data);
        #ifdef test
        Serial.println("- Data sent to ThingSpeak!");
        #endif
    }
}

void init_wifi(void){
    #ifdef test
    Serial.println("------WI-FI -----");
    Serial.println("Conecting to: ");
    Serial.println(SSID_NET);
    Serial.println("\nPlease wait...");
    #endif
 
    conect_wifi();
}
 

void conect_wifi(void){
    
    if (WiFi.status() == WL_CONNECTED)
    {
        return;
    }
     
    WiFi.begin(SSID_NET, PASSWORD);
     
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(100);
    }
    #ifdef test
    Serial.println("Connected succesfuly to \n");
    Serial.println(SSID_NET);
    #endif
}
 
void verify_wifi(void){
    conect_wifi();
}