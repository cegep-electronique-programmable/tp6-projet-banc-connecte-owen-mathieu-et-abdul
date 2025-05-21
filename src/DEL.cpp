#include "DEL.h"


#define PIN         1 
#define NUMPIXELS   10 
#define BRIGHTNESS  50  

#define LIGHT_SENSOR_PIN 10


//Adafruit_NeoPixel strip(64, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 1


void run() {
  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
    clock_prescale_set(clock_div_1);
  #endif
    pixels.begin();
    //strip.show();
    //strip.setBrightness(BRIGHTNESS); 
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

float adjustBrightness(){
  float lightLevel = analogRead(LIGHT_SENSOR_PIN);
  float brightness = lightLevel;
  return brightness;
}

void setBrightness(float Light_Data) {
  //strip.setBrightness(Light_Data);
  pixels.setBrightness(Light_Data);
}