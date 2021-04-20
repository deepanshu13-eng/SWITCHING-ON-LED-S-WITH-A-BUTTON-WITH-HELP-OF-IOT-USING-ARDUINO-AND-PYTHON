#include<ESP8266WiFi.h>                                                 // Importing ESP8266 library.

String apiKey = "WGSTB753UI1S08RM";                                     // Write Your Thingspeak apiKey here.                               

const char *ssid = "corona";                                            // Write your wifi name here.                                                                    
const char *pass = "covid2019";                                         // Write your wifi password here.
const char *server = "api.thingspeak.com";                              // server address from which we have to connect i.e. Thingspeak.                           

const int buttonPin1 = 16;                                              // Declaring pin 16 of Node mcu i.e D0 as a constant integer.
const int buttonPin2 = 5;                                               // Declaring pin 5 of Node mcu i.e D1 as a constant integer.
int led1 = 4;                                                           // Declaring pin 4 of Node mcu i.e D2 as a integer.

int buttonState1 = 0;                                                   // Declaring buttonState1 as a integer and Initialy declaring it value 0. 
int buttonState2 = 0;                                                   // Declaring buttonState2 as a integer and Initialy declaring it value 0. 
int button1 = 0;                                                        // Declaring button1 as a integer and Initialy declaring it value 0.
int button2 = 0;                                                        // Declaring button2 as a integer and Initialy declaring it value 0. 
WiFiClient client;                                                      // Making our WiFi to act as a client.

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);                                                     // Reading and Writing data at 9600hz.
delay(10);
Serial.println("CONNECTING TO ");                                       //Getting connected to wifi. 
Serial.println(ssid);

WiFi.begin(ssid, pass);

while (WiFi.status() != WL_CONNECTED)
{
  delay(500);
  Serial.print(".");
}
Serial.print("");
Serial.println("WiFi Connected");

pinMode(buttonPin1,INPUT);                                                 //Declaring buttonPin1 as INPUT.
pinMode(buttonPin2,INPUT);                                                //Declaring buttonPin2 as INPUT.
pinMode(led1, OUTPUT);                                                     //Declaring led1 as OUTPUT.
if (WiFi.status() == WL_CONNECTED)
{
digitalWrite(led1, HIGH);                                                  // Making led1 as high when our NodeMcu will get connected to our Wifi.
}
}

void loop() {
  // put your main code here, to run repeatedly:
buttonState1 = digitalRead(buttonPin1);                                    //Reading data of ButtonPin1.
Serial.print("\n Button 1 value : ");
Serial.print(buttonState1);                                                //Printing value of ButtonPin1 in Serial Monitor.
buttonState2 = digitalRead(buttonPin2);                                    //Reading data of ButtonPin2.
Serial.print("\n Button 2 value : ");                                 
Serial.print(buttonState2);                                                //Printing value of ButtonPin2 in Serial Monitor.
if (buttonState1 == 1)
{
  button1 = 1;                                                            // If buttonState1 is equal to one then it will asign button1 value as 1.
}
else{
  button1 = 0;                                                             // If buttonState1 is equal to zero then it will asign button1 value as 0.
}
if (buttonState2 == 1)
{
  button2 = 1;                                                             // If buttonState2 is equal to one then it will asign button1 value as 1.
}
else{
  button2 = 0;                                                             // If buttonState1 is equal to zero then it will asign button1 value as 0.
}

if (client.connect(server, 80))                                            // Sending data of button's to Thingspeak Server.
{
  String postStr = apiKey;
  postStr += "&field1=";
  postStr += String(button1);
   postStr += "&field2=";
  postStr += String(button2);
  postStr += "\r\n\r\n";

  client.print("POST /update HTTP/1.1\n");                                  // Some necessary task to send data to Thingspeak server. 
  client.print("Host: api.thingspeak.com\n");
  client.print("Connected: close\n");
  client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
  client.print("content-Type: application/x-www-form-urlencoded\n");
  client.print("content-Length: ");
  client.print(postStr.length());
  client.print("\n\n");
  client.print(postStr);
}

client.stop();                                                              // Making the client to stop.
delay(2);
}
