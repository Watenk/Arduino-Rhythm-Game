#include <Adafruit_BusIO_Register.h>
#include <Adafruit_I2CDevice.h>
#include <Adafruit_I2CRegister.h>
#include <Adafruit_SPIDevice.h>

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "Display.h"
#include "Vector2Int.h"

#define SCREEN_WIDTH 128 // OLED display width,  in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// declare an SSD1306 display object connected to I2C
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

Display::display(){

}

void Display::initialize(){
  // initialize OLED display with address 0x3C for 128x64
  if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    while (true);
  }                                                             

  updateDisplay();
}

void Display::draw(Object* object){
  if (!object->isCircle){
    oled.fillRect(object->pos.x, object->pos.y, object->width, object->height, WHITE);
  }
  else{
    oled.fillCircle(object->pos.x, object->pos.y, (object->width + object->height) / 2, WHITE);
  }
}

void Display::drawNumber(int number, Vector2Int pos){
  oled.setTextSize(1);         
  oled.setTextColor(WHITE);
  oled.setCursor(pos.x, pos.y);
  oled.println(number);
}

void Display::clearDisplay(){
  oled.clearDisplay();
}

void Display::updateDisplay(){
  oled.display();
}