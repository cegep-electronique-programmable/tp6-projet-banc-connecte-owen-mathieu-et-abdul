#include "affichage.h"

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);   // All Boards without Reset of the Display

void StartScreen() {
  u8g2.begin();
  u8g2.enableUTF8Print();
}

void SetFont(const uint8_t* Font){
  u8g2.setFont(Font);  // use chinese2 for all the glyphs of "你好世界"
  u8g2.setFontDirection(0);
}

void ClearScreen(){
  u8g2.clearBuffer();
}

void AfficherImage(int CordX, int CordY, int Width, int Height, const uint8_t *bitmap){
    u8g2.firstPage();
  do {
    u8g2.drawXBMP(CordX, CordY, Width, Height, bitmap);		// Chinese "Hello World" 
  } while ( u8g2.nextPage() );
}

void AfficherInfo(uint16_t nbrPresence, uint16_t nbrCharge){
  ClearScreen();
  char PresenceS[20] = {0};
  itoa(nbrPresence, PresenceS, 10);
  char ChargeS[20] = {0};
  itoa(nbrCharge, ChargeS, 10);
  SetFont(u8g2_font_unifont_t_chinese2);
  u8g2.firstPage();
  do {
    u8g2.setCursor(0, 14);
    u8g2.print("Nbr Personne: ");
    u8g2.setCursor(105, 14);
    u8g2.print(nbrPresence);
    u8g2.setCursor(0, 30);
    u8g2.print("Nbr Charge: ");
    u8g2.setCursor(90, 30);
    u8g2.print(nbrCharge);
  } while ( u8g2.nextPage() );
}