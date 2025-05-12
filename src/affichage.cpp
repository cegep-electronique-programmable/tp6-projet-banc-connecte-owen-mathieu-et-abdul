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

void Imprime(const char* Message, int CordX, int CordY) {
  u8g2.setCursor(CordX, CordY);
  u8g2.print(Message);
  u8g2.sendBuffer();
}

void ClearScreen(){
  u8g2.clearBuffer();
  Imprime("", 0, 0);
}

void AfficherInfo(uint16_t nbrPresence, uint16_t nbrCharge){
  ClearScreen();
  char PresenceS[20] = {0};
  itoa(nbrPresence, PresenceS, 10);
  char ChargeS[20] = {0};
  itoa(nbrCharge, ChargeS, 10);
  SetFont(u8g2_font_unifont_t_chinese2);
  Imprime(PresenceS, 0, 14);
  Imprime(ChargeS, 0, 30);
}