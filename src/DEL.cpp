#include "DEL.h"

#define PIN         1 
#define NUMPIXELS   10 
#define BRIGHTNESS  50 

#define LIGHT_SENSOR_PIN A0


Adafruit_NeoPixel strip(64, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 500


void run() {
  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
    clock_prescale_set(clock_div_1);
  #endif
    pixels.begin();
    strip.show();
    strip.setBrightness(BRIGHTNESS); 
}

void verte() {
  pixels.clear(); 
  for (int i = 0; i < NUMPIXELS; i++) { 
    pixels.setPixelColor(i, pixels.Color(0, 150, 0));
    pixels.show();  
    delay(DELAYVAL); 
  }  
}

void rouge() {
  pixels.clear(); 
  for (int i = 0; i < NUMPIXELS; i++) { 
    pixels.setPixelColor(i, pixels.Color(255, 0, 0));
    pixels.show();  
    delay(DELAYVAL); 
  }  
}
void jaune() {
  pixels.clear(); 
  for (int i = 0; i < NUMPIXELS; i++) { 
    pixels.setPixelColor(i, pixels.Color(255, 255, 0));
    pixels.show();  
    delay(DELAYVAL); 
  }  
}
int adjustBrightness() {
  int lightLevel = analogRead(LIGHT_SENSOR_PIN);
  int brightness = map(lightLevel, 0, 1023, 255, 50);
  return brightness;
}

void setBrightness(int brightness) {
  brightness = adjustBrightness();
  strip.setBrightness(brightness);
  pixels.setBrightness(brightness);
}