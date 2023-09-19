#include <Arduino.h>
#include <WiFi.h>
#include <math.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>

AsyncWebServer server(80);

const char* ssid = "Redmi Note 7S";
const char* password = "12345678";

const char* input_parameter1 = "input_side1";
const char* input_parameter2 = "input_side2";
const char* input_parameter3 = "input_angle1";
const char* input_parameter4 = "input_angle2";

int s1,s11,s2,s22,a1,a11,a2,a22;

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML>
<html>
<head>
  <title>ESP32</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <style>
    html {font-family: Times New Roman; display: inline-block; text-align: center;}
    h2 {font-size: 3.0rem; color: #FF0000;}
  </style>
</head>
<body>
  <h2>INPUT TO ESP32</h2> 
  <form action="/get">
    S1: <input type="number" name="input_side1"><br>
    S2: <input type="number" name="input_side2"><br>
    A1: <input type="number" name="input_angle1"><br>
    A2: <input type="number" name="input_angle2"><br>
    <input type="submit" value="Submit">
  </form>
</body>
</html>
)rawliteral";

void notFound(AsyncWebServerRequest *request) {
  request->send(404, "text/plain", "Not found");
}

void logic() {
  a11 = 90 - a1;
  a22 = 90 - a2;
  s11 = s1*cos(a11)/sin(a11);
  s22 = s2*cos(a22)/sin(a22);
}
  
void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html);
  });

  server.on("/get", HTTP_GET, [] (AsyncWebServerRequest *request) {

    if (request->hasParam(input_parameter1)) {
      s1 = request->getParam(input_parameter1)->value().toInt();
    }
    if (request->hasParam(input_parameter2)) {
      s2 = request->getParam(input_parameter2)->value().toInt();
    }
    if (request->hasParam(input_parameter3)) {
      a1 = request->getParam(input_parameter3)->value().toInt();
    }
    if (request->hasParam(input_parameter4)) {
      a2 = request->getParam(input_parameter4)->value().toInt();
    }
    logic();
    if(s11==s22) {
        request->send(200, "text/html", "CD bisects AB <br><a href=\"/\">Return to Home Page</a>");
    }
    else {
        request->send(200, "text/html", "CD does not bisect AB <br><a href=\"/\">Return to Home Page</a>");
    }
  });
  server.onNotFound(notFound);
  server.begin();
}

void loop() {
  
}

