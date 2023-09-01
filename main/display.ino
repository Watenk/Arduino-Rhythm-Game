//Library's
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width,  in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// declare an SSD1306 display object connected to I2C
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void initializeDisplay(){
  // initialize OLED display with address 0x3C for 128x64
  if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    while (true);
  }

  oled.clearDisplay();
  addRect(10, 10, 20, 30);
  draw();
}

void addRect(int xPos, int yPos, int width, int height){
  oled.fillRect(xPos, yPos, width, height, WHITE);
}

//void addCircle(){
//  oled.fillCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color)
//}

void draw(){
  oled.display();
}