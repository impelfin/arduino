#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <Arduino_JSON.h>

const char* ssid = "Amazing_WIFI"; 
const char* password = "12345678"; 
const char* serverName = "http://13.125.8.3:3000/post-sensor"; 

int sensor_number = 12; 
float value = 25.5; 

#define delay_ms 2000

WiFiClient client; 

void setup() { 
  Serial.begin(9600); 
  WiFi.begin(ssid, password); 
  
  while (WiFi.status() != WL_CONNECTED) { 
    delay(1000); 
    Serial.println("Connecting to WiFi.."); 
  } 
  Serial.println("Connected to the WiFi network"); 
}
    
void loop() { 
  if(WiFi.status()== WL_CONNECTED) { 
    HTTPClient http; 
    http.begin(client, serverName);  
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    String httpRequestData = "sensor_number="+String(sensor_number)+"&value="+String(value); 
    Serial.println(httpRequestData); 
    int httpResponseCode = http.POST(httpRequestData); 
    if(httpResponseCode>0) {  
      String response = http.getString(); 
      Serial.println(httpResponseCode); 
      Serial.println(response); 
    } else { 
        Serial.print("Error on sending POST: "); 
        Serial.println(httpResponseCode); 
    } 
    http.end(); 
  } else { 
    Serial.println("Error in WiFi connection"); 
  } 
  delay(delay_ms); 
}
