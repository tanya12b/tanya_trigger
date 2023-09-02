// including WIFININA library...
#include <WiFiNINA.h>
// entering my sensitive data in the Secret tab
// char ssid[] = SECRET_SSID;
// char pass[] = SECRET_PASSWORD;
const char* ssid = "Galaxy M114971";
const char* password = "987654321";
const char* host = "maker.ifttt.com";
              
// setup
void setup() {
    Serial.begin(9600);

    Serial.println(".....email....... ");
    delay(1000);

    Serial.print("....Connecting..... ");
    Serial.println(ssid);
// initialize WiFi connection
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
      delay(1000);
      Serial.print(".");
    }

    Serial.println("");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());  



}
//loop
void loop() {  


           WiFiClient client; 
            // connect to web server on port 80:
           const int httpPort = 80;  
            if (!client.connect(host, httpPort)) {  
              // if not connected:
                  Serial.println("connection failed");  
            return;} 
          if(Serial.available()){

            
            // enter this lettter on serial monitor 
            if (Serial.read() =='S'){

// make a HTTP request:
    // send HTTP header
                    String url = "/trigger/tanya_trigger/with/key/c87FUd-L6Chd0hAnFZ8NYw"; 
                    // get this url by clicking on right side of documentation of webhooks..select the url and paste it here.
                    // our API is on top of documentation...

                    Serial.print(" ops requesting url!!!! ");
                    Serial.println(url);

                     client.print(String("GET ") + url + " HTTP/1.1\r\n" + 
                                    "Host: " + host + "\r\n" +   
                                           "Connection: close\r\n\r\n");    
                                    }  

          //enter the correct letter
          else{
            Serial.println("please enter correct letter!!!!");

          }
          }
           // giving some delay
          delay(5000);


}