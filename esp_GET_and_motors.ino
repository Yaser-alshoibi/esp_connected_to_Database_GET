#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266HTTPClient.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>     

#define power 2  //--> Defining an On Board LED (GPIO2 = D4), used for indicators when the process of connecting to a wifi router

//----------------------------------------Web Server address / IPv4
// If using IPv4, press Windows key + R then type cmd, then type ipconfig (If using Windows OS).
const char *host = "http://TYPE-YOUR-IP-HERE";
//----------------------------------------

void setup() {
  
    Serial.begin(9600); 
    pinMode(power,OUTPUT);  
    digitalWrite(power,HIGH);
    WiFiManager wifiManager;
    wifiManager.resetSettings();
    wifiManager.autoConnect("ESP YASER WiFi Manager");
    Serial.println("connected :)");
    Serial.println();
}
 

void loop() {

  
  if (WiFi.status() == WL_CONNECTED){
    
          digitalWrite(power,LOW);
          
          while(WiFi.status() == WL_CONNECTED){           
            
// Operating code after connecting successfully:

  HTTPClient http; //--> Declare object of class HTTPClient
 
  String GetAddress, LinkGet, getData;
  int id = 0; //--> ID in Database
  
  GetAddress = "/t3/GetDataForw.php";
  LinkGet = host + GetAddress; //--> Make a Specify request destination
  getData = "ID=" + String(id);
  
  http.begin(LinkGet); //--> Specify request destination
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");    //Specify content-type header
  int httpCodeGet = http.POST(getData); //--> Send the request
  String payloadGet = http.getString(); //--> Get the response payload from server
  
// After recieveing the value and storing it in 'payloadGet':

  if (payloadGet == "1") {
    Serial.print("Move Forward");
  }
  //----------------------------------------
  
  GetAddress = "/t3/GetDataBackw.php";
  LinkGet = host + GetAddress;
  getData = "ID=" + String(id);

  http.begin(LinkGet);
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  httpCodeGet = http.POST(getData);
  payloadGet = http.getString();
  

  if (payloadGet == "1") {
    Serial.print("Move Backward");
  }

  //----------------------------------------
  
  GetAddress = "/t3/GetDataRight.php";
  LinkGet = host + GetAddress;
  getData = "ID=" + String(id);
  
  http.begin(LinkGet);
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  httpCodeGet = http.POST(getData);
  payloadGet = http.getString();
  
  if (payloadGet == "1") {
    Serial.print("Move Right");
  }

//----------------------------------------

  GetAddress = "/t3/GetDataLeft.php";
  LinkGet = host + GetAddress;
  getData = "ID=" + String(id);
  
  http.begin(LinkGet);
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  httpCodeGet = http.POST(getData);
  payloadGet = http.getString();
    
  if (payloadGet == "1") {
    Serial.print("Move Left");
  }
  
//----------------------------------------

  GetAddress = "/t3/GetDataStop.php";
  LinkGet = host + GetAddress;
  getData = "ID=" + String(id);
  
  http.begin(LinkGet);
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  httpCodeGet = http.POST(getData);
  payloadGet = http.getString();
  
  if (payloadGet == "1") {
    Serial.print("Stop");
  }

 //----------------------------------------

  Serial.println();
  Serial.println("----------------Closing Connection----------------");
  http.end(); //--> Close connection
  Serial.println();
  Serial.println("Please wait 5 seconds for the next connection.");
  Serial.println();
  delay(5000); //--> GET Data at every 5 second
}
        }              
        }
