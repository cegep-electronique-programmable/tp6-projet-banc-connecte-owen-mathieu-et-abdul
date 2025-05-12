/*!
 * @file affichage.h
 *
 * @author À compléter
 * 
 * @date À compléter
 * 
 * @brief À compléter
 *
 */

 // Font utilisable: u8g2_font_unifont_t_chinese2

#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include <Arduino.h>
#include <U8g2lib.h>

void AfficherInfo(uint16_t nbrPresence, uint16_t nbrCharge);

void Imprime(const char* Message, int CordX, int CordY);

void SetFont(const uint8_t* Font);

void ClearScreen();

void StartScreen();


#endif