//#include <ESP8266WiFi.h>
//#include <ESP8266HTTPClient.h>
// 
//const char* ssid = "NETGEAR98";
//const char* password = "helpfulsheep445";
// 
//void setup_wifi() {
//  WiFi.begin(ssid, password);
//  while (WiFi.status() != WL_CONNECTED)
//  {
//    delay(1000);
//    Serial.println("Connecting...");
//  }
// 
//  Serial.println("Connected successfully.");
//}
// 
//void setup() {
//  pinMode(2, OUTPUT);
//  Serial.begin(115200);
//  setup_wifi();
//}
// 
//void loop() {
//  float temperature = 0;
//  float humidity = 0;
// 
//
// 
// 
//  Serial.print("Sample OK: ");
//  Serial.print((float)temperature); Serial.print(" *C, ");
// 
//  if (WiFi.status() != WL_CONNECTED) {
//    setup_wifi();
//  } else {
//    HTTPClient http;
// 
//    http.begin("http://127.0.0.1:8090/");
//    http.addHeader("Content-Type", "text/plain");
//     
//    int httpCode = http.POST(String(temperature));
//    http.end();
//  }
//  delay(2500);
//}

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "NETGEAR98";
const char* password =  "helpfulsheep445";

void setup() {

  Serial.begin(115200);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }

  Serial.println("Connected to the WiFi network");

}

void loop() {
 int data = 20;
 if(WiFi.status()== WL_CONNECTED){   //Check WiFi connection status

   HTTPClient http;   

   http.begin("http://192.168.0.19:8090/post");
   http.addHeader("Content-Type", "text/plain");             

   int httpResponseCode = http.POST("20 deg c");   //Send the actual POST request

   if(httpResponseCode>0){
     

    Serial.println(httpResponseCode);    //Send the request

   }else{

    Serial.println("Error on sending POST");

   }

   http.end();  //Free resources

 }else{

    Serial.println("Error in WiFi connection");   

 }

  delay(10000);  //Send a request every 10 seconds

}
