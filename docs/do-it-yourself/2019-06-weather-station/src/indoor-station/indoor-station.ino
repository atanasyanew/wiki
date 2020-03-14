/*********************************************************************
  A.Y Weather station

*********************************************************************/

#include <SPI.h>
#include <Wire.h>
#include <ESP8266WiFi.h>
#include "DHT.h"
#include <Adafruit_BMP085.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"
#include <Adafruit_GFX.h>
// #include <Adafruit_SSD1306.h>
#include "src/Adafruit_SSD1306-esp8266-64x48/Adafruit_SSD1306.h"

// App settings
#define DISPLAY_CHANGE_INTERVAL 3000 // in ms, switch between oled frames
#define MQTT_PUBLISH_INTERVAL 10000  // in ms, mqtt publish interval

// WIFI settings
#define WLAN_SSID "sisi"
#define WLAN_PASS "sisi9511"

// MQTT broker settings
#define HOST "192.168.0.100"
#define PORT 1883
#define USERNAME ""
#define PASSWORD ""

// Project variables
#define DHTPIN 2           // D4
#define LIGHT_SENSOR_PIN 0 // A0
#define OLED_RESET 0       // GPIO0
#define I2C 0x3C           // OLED Shield

// comment the next line in if you like to publish battery voltage instead of light. It's an command line option.
//#define BAT_VOLTAGE

// Program
#ifdef BAT_VOLTAGE
ADC_MODE(ADC_VCC);
#endif

Adafruit_BMP085 bmp;
DHT dht(DHTPIN, DHT22);
Adafruit_SSD1306 display(OLED_RESET);
WiFiClient client;
unsigned long last_time_published = 0;

// MQTT topics
Adafruit_MQTT_Client mqtt(&client, HOST, PORT, USERNAME, PASSWORD);
Adafruit_MQTT_Publish temperature = Adafruit_MQTT_Publish(&mqtt, "indoorWeatherStation/temperature");
Adafruit_MQTT_Publish pressure = Adafruit_MQTT_Publish(&mqtt, "indoorWeatherStation/pressure");
Adafruit_MQTT_Publish humidity = Adafruit_MQTT_Publish(&mqtt, "indoorWeatherStation/humidity");
Adafruit_MQTT_Publish light = Adafruit_MQTT_Publish(&mqtt, "indoorWeatherStation/light");
Adafruit_MQTT_Publish voltage = Adafruit_MQTT_Publish(&mqtt, "indoorWeatherStation/battvoltage");
Adafruit_MQTT_Publish uptime = Adafruit_MQTT_Publish(&mqtt, "indoorWeatherStation/uptime");

void connectMQTT()
{
  int8_t ret;

  if (mqtt.connected())
  {
    return;
  }

  Serial.print("Connecting to MQTT... ");

  uint8_t retries = 10;

  while ((ret = mqtt.connect()) != 0)
  {
    // connect will return 0 for connected
    Serial.println(mqtt.connectErrorString(ret));
    Serial.println("Retrying MQTT connection in 1 second...");

    mqtt.disconnect();
    delay(1000);
    retries--;

    if (retries == 0)
    {
      Serial.println("MQTT could not connect!");
    }
  }

  Serial.println("MQTT Connected!");
}

void connectWIFI()
{
  Serial.print("Connecting to ");
  Serial.println(WLAN_SSID);

  WiFi.begin(WLAN_SSID, WLAN_PASS);
  
  uint8_t retries = 10;
  int i = 0;

  for (; i < retries; i++)
  {
    if (WiFi.status() == WL_CONNECTED)
      break;
    delay(100);
    Serial.print(".");
  }

  if (i == retries)
  {
    Serial.print("Could not connect to WIFI");
  }

  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void connectSetup()
{
  connectWIFI();
  delay(100);
  connectMQTT();
  delay(100);
}

void publishTopics()
{
  temperature.publish(bmp.readTemperature());
  pressure.publish(bmp.readPressure());
  humidity.publish(dht.readHumidity());
  int getUptime = millis();
  uptime.publish(getUptime);

#ifdef BAT_VOLTAGE
  voltage.publish(ESP.getVcc());
#else
  light.publish(analogRead(A0) / 1023.0f);
#endif
}

void drawTemperature(void)
{
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(1, 0);
  display.println("Temp.");
  display.println("");
  display.setTextSize(2);
  display.println(bmp.readTemperature());
  display.display();
}

void drawHumidity(void)
{
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(1, 0);
  display.println("Humidity");
  display.println("");
  display.setTextSize(2);
  display.println(dht.readHumidity());
  display.display();
}

void drawPressure(void)
{
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(1, 0);
  display.println("Pressure");
  display.println("");
  display.setTextSize(2);
  display.println(bmp.readPressure());
  display.display();
}

void drawLight(void)
{
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(1, 0);
  display.println("Light");
  display.println("");
  display.setTextSize(2);
  display.println(analogRead(LIGHT_SENSOR_PIN) / 1023.0f);
  display.display();
}

void drawStatus(void)
{
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(1, 0);
  display.println("Uptime:");
  display.println(millis());
  display.println("IP:");
  display.println(WiFi.localIP());
  display.display();
}

void sensorDebug()
{
  Serial.print("Temperature = ");
  Serial.print(bmp.readTemperature());
  Serial.println(" Celsius");

  Serial.print("Pressure = ");
  Serial.print(bmp.readPressure());
  Serial.println(" Pascal");

  Serial.print("Humidity = ");
  Serial.print(dht.readHumidity());
  Serial.println(" Humidity");

  Serial.print("Light = ");
  Serial.print(analogRead(LIGHT_SENSOR_PIN) / 1023.0f);
  Serial.println(" %");

  // Serial.print("Light voltage = ");
  // Serial.print(ESP.getVcc());
  // Serial.println(" V");

  Serial.print("Uptime = ");
  Serial.print(millis());
  Serial.println(" ms");

  Serial.println();
}

void printTime(unsigned long time_millis)
{
  Serial.print("Time: ");
  Serial.print(time_millis / 1000);
  Serial.print("s - ");
}

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  WiFi.mode(WIFI_STA);
  bmp.begin();
  dht.begin();
  display.begin(SSD1306_SWITCHCAPVCC, I2C); // initialize with the I2C addr 0x3C (for the 64x48);
  connectSetup();
}

void loop()
{
  // put your main code here, to run repeatedly:

  // Publishing
  if (millis() > last_time_published + MQTT_PUBLISH_INTERVAL)
  {
    connectSetup();
    last_time_published = millis();
    printTime(last_time_published);
    Serial.println("Publishing...");
    publishTopics();
  }

  delay(DISPLAY_CHANGE_INTERVAL);
  drawTemperature();

  delay(DISPLAY_CHANGE_INTERVAL);
  drawHumidity();

  delay(DISPLAY_CHANGE_INTERVAL);
  drawPressure();

  delay(DISPLAY_CHANGE_INTERVAL);
  drawLight();

  delay(DISPLAY_CHANGE_INTERVAL);
  drawStatus();
}
