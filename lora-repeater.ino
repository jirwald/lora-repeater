#include <SPI.h>
#include <LoRa.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define MEASURING_INTERVAL 1000
#define ss PA8
#define rst PA10
#define dio0 PA9

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire);

long lastMeasured = 0;
int receivedPacketNr = 0;
int test = 0;

//===============================================================================
//  Initialization
//===============================================================================
void setup()
{
  LoRa.setPins(ss, rst, dio0);
  int loraBegin = LoRa.begin(433E6);
  LoRa.onReceive(onReceive);
  LoRa.receive();
}
//===============================================================================
//  Main
//===============================================================================
void loop()
{
  //Measurement();
}