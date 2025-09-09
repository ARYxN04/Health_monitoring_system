#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID "TMPL3Cugtyr2w"
#define BLYNK_TEMPLATE_NAME "IOT healthcare"
#define BLYNK_AUTH_TOKEN "vFSUtGOQRChFRKHzsMW6qXDEf41l4sXr"
#define DHTTYPE DHT22
#include <Wire.h> 
#include <WiFi.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#include <BlynkSimpleEsp32.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Wokwi-GUEST";
char pass[] = "";

const int led = 2;
const int pulsePin = 34;
#define DHTPIN 4
int celsius;
int valPulse;
BlynkTimer timer;
//const int buttonPin = ;
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup(){
  Serial.begin(9600);
  dht.begin();
  lcd.init();
  lcd.backlight();
  lcd.print("Connecting...");

  WiFi.begin(ssid, pass);

  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    lcd.setCursor(0,0);
    lcd.print("WiFi Connecting");
  }
  lcd.clear();
  lcd.print("WiFi connected");

  Blynk.begin(auth,ssid,pass);
  lcd.setCursor(0,1);
  lcd.print("Blynk Ready");
  lcd.clear();

  timer.setInterval(2000L, sendDataToBlink);
}


void sendDataToBlink(){
  celsius = dht.readTemperature();
  Serial.print("Temp is ");
  Serial.println(celsius);

  valPulse = analogRead(pulsePin);
  valPulse = map(valPulse, 0, 4095, 60, 100);


  if (isnan(celsius)){
    Serial.println("Failed to read from Temp sensor");
    lcd.setCursor(0,0);
    lcd.print("Sensor Error!");
    lcd.clear();
    return;
  }
  if (isnan(valPulse)){
    Serial.println("Failed to read from Pulse sensor");
    lcd.setCursor(0,0);
    lcd.print("Sensor Error!");
    lcd.clear();
    return;
  }
  lcd.setCursor(0,0);
  lcd.print("temp: ");
  lcd.print(celsius); 
  lcd.print("C");
  
  lcd.setCursor(0,1);
  lcd.print("Heart rate: ");
  lcd.print(valPulse);
  lcd.print("BPM");
  
  Blynk.virtualWrite(V1, celsius);
  Blynk.virtualWrite(V2, valPulse);
  
}

void loop() {
  Blynk.run();
  timer.run();

}