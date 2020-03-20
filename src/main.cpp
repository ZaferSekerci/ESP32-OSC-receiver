#include <ArduinoOSC.h>
#include <Nokia_5110.h>
//5110 connections
#define RST 18
#define CE 5
#define DC 4
#define DIN 2
#define CLK 15

Nokia_5110 lcd = Nokia_5110(RST, CE, DC, DIN, CLK);
//wifi settings
const char *ssid = "Confectioner";
const char *pwd = "artemispardus*123";
//ip settings
const IPAddress ip(192, 168, 1, 201);
const IPAddress gateway(192, 168, 1, 1);
const IPAddress subnet(255, 255, 255, 0);
// for OSC
OscWiFi osc;
const char *host = "192.168.1.200";
//const char* host = "192.168.1.101";
const int recv_port = 10000;
const int send_port = 12000;

void onOscReceived(OscMessage &m)
{
  Serial.print("callback : ");
  Serial.print(m.ip());
  Serial.print(" ");
  Serial.print(m.port());
  Serial.print(" ");
  Serial.print(m.size());
  Serial.print(" ");
  Serial.print(m.address());
  Serial.print(" ");
  Serial.print(m.arg<int>(0));
  Serial.print(" ");
  Serial.print(m.arg<float>(1));
  Serial.print(" ");
  Serial.print(m.arg<String>(2));
  Serial.println();
}
void setupLcd()
{
}
void updateLcd(int row, int col, float val, const char *name)
{
  lcd.setCursor(col, row);
  lcd.clear(row, 0, 84);
  lcd.printf("%s %.1f", name, val);
}

void setup()
{
  lcd.setContrast(60);

  // WiFi stuff
  WiFi.begin(ssid, pwd);
  WiFi.config(ip, gateway, subnet);

  while (WiFi.status() != WL_CONNECTED)
  {
    //print dots when connecting
    lcd.print(".");
    delay(500);
  }
  lcd.clear();
  //show message when connection okey
  lcd.printf("wifi connected IP \n");
  lcd.println(WiFi.localIP());

  // ArduinoOSC
  osc.begin(recv_port);
  //every channel need to be subscribed
  osc.subscribe("/slider0", [](OscMessage &m) {
    updateLcd(0, 0, m.arg<float>(0), "slider0: ");
  });
  osc.subscribe("/slider1", [](OscMessage &m) {
    updateLcd(1, 0, m.arg<float>(0), "slider1: ");
  });
  osc.subscribe("/slider2", [](OscMessage &m) {
    updateLcd(2, 0, m.arg<float>(0), "slider2: ");
  });
  osc.subscribe("/slider3", [](OscMessage &m) {
    updateLcd(3, 0, m.arg<float>(0), "slider3: ");
  });
  osc.subscribe("/slider4", [](OscMessage &m) {
    updateLcd(4, 0, m.arg<float>(0), "slider4: ");
  });
  osc.subscribe("/slider5", [](OscMessage &m) {
    updateLcd(5, 0, m.arg<float>(0), "slider5: ");
  });
}

void loop()
{
  osc.parse(); // should be called
}