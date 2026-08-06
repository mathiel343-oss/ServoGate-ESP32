#include <WiFi.h>
#include <WebServer.h>
#include <ESP32Servo.h>

const char* ssid     = "math_esp";
const char* password = "123456789";

WebServer server(80);
Servo myServo;

const int servoPin  = 5;
const int blueLED   = 21;
const int yellowLED = 17;

const int OPEN_ANGLE  = 90;
const int CLOSE_ANGLE = 0;

String htmlPage() {
  String html = "<!DOCTYPE html><html><head><meta charset='UTF-8'>";
  html += "<meta name='viewport' content='width=device-width, initial-scale=1'>";
  html += "<style>";
  html += "body{font-family:Arial;text-align:center;margin-top:60px;background:#f0f0f0;}";
  html += "h1{color:#333;margin-bottom:40px;}";
  html += "button{font-size:24px;padding:18px 45px;margin:12px;border:none;border-radius:12px;color:white;cursor:pointer;}";
  html += ".open{background-color:#2196F3;} .close{background-color:#FDD835;color:#333;}";
  html += "#status{margin-top:30px;font-size:20px;color:#555;}";
  html += "</style></head><body>";
  html += "<h1>التحكم بالسيرفو موتور</h1>";
  html += "<button class='open' onclick=\"send('/open')\">Open</button>";
  html += "<button class='close' onclick=\"send('/close')\">Close</button>";
  html += "<div id='status'>الحالة الحالية: --</div>";
  html += "<script>";
  html += "function send(path){fetch(path).then(r=>r.text()).then(t=>{document.getElementById('status').innerText='الحالة الحالية: '+t;});}";
  html += "</script></body></html>";
  return html;
}

void handleRoot() {
  server.send(200, "text/html", htmlPage());
}

void handleOpen() {
  myServo.write(OPEN_ANGLE);
  digitalWrite(blueLED, HIGH);
  digitalWrite(yellowLED, LOW);
  server.send(200, "text/plain", "Open");
}

void handleClose() {
  myServo.write(CLOSE_ANGLE);
  digitalWrite(yellowLED, HIGH);
  digitalWrite(blueLED, LOW);
  server.send(200, "text/plain", "Close");
}

void setup() {
  Serial.begin(115200);

  pinMode(blueLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  digitalWrite(yellowLED, HIGH);
  digitalWrite(blueLED, LOW);

  myServo.setPeriodHertz(50);
  myServo.attach(servoPin, 500, 2400);
  myServo.write(CLOSE_ANGLE);

  WiFi.softAP(ssid, password);
  Serial.print("AP IP address: ");
  Serial.println(WiFi.softAPIP());

  server.on("/", handleRoot);
  server.on("/open", handleOpen);
  server.on("/close", handleClose);
  server.begin();
}

void loop() {
  server.handleClient();
}
