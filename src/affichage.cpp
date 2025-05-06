#include "affichage.h"

U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ 13, /* data=*/ 11, /* reset=*/ 8);

void StartScreen() {
    u8g2.begin();
}

void afficherInfo(uint16_t nbrPresence, uint16_t nbrCharge){
  
}

void Imprime(const char* Message, int CordX, int CordY) {
    u8g2.firstPage();
  do {
    u8g2.setFont(u8g2_font_ncenB14_tr);
    u8g2.drawStr(CordX, CordY, Message);
  } while ( u8g2.nextPage() );
}
