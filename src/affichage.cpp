#include "affichage.h"

U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ 13, /* data=*/ 11, /* reset=*/ 8);

void setup() {
    u8g2.begin();
}

void afficherInfo(uint16_t nbrPresence, uint16_t nbrCharge){
  
}
