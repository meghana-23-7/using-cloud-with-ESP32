#ifdef __cplusplus
extern "C" {
#endif
uint8_t temprature_sens_read();
#ifdef __cplusplus
}
#endif
uint8_t temprature_sens_read();
#include <WiFi.h>
#include <HTTPClient.h>

// Set our wifi name and password
const char* ssid = "Marvel-Guest";
const char* password = "";

// Your thingspeak channel url with api_key query
String serverName = "https://api.thingspeak.com/update?api_key=your_api_key";

// Assign some variables to allow us read and send data every minute
unsigned long lastTime = 0;
unsigned long timerDelay = 60000;


void setup() {
  Serial.begin(9600); 


  WiFi.begin(ssid, password); 
  Serial.println("Connecting"); // Print our status to the serial monitor
  // Wait for wifi to connect
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
}


void loop() {

  if ((millis() - lastTime) > timerDelay) { // Check if its been a minute
    if(WiFi.status()== WL_CONNECTED){ // Check to make sure wifi is still connected
      sendData(1, 2, 3, 4); // Call the sendData function defined below
    }
    else {
      Serial.println("WiFi Disconnected");
    }
    lastTime = millis();
  }
}


void sendData(double temp, double pres, double alt, double hum){
    int h = 0;
float t =0;

h = hallRead();
t = ((temprature_sens_read()-32)/1.8); 
  HTTPClient http; // Initialize our HTTP client


  String url = serverName + "&field1=" + String(h) + "&field2=" + String(t) + "&field3=" + alt + "&field4=" + hum; // Define our entire url
      
  http.begin(url.c_str()); // Initialize our HTTP request
      
  int httpResponseCode = http.GET(); // Send HTTP request
      
  if (httpResponseCode > 0){ // Check for good HTTP status code
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
  }else{
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }
  http.end();
}
