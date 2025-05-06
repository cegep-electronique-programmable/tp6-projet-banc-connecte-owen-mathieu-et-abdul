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

#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include <Arduino.h>
#include <U8g2lib.h>

void afficherInfo(uint16_t nbrPresence, uint16_t nbrCharge);

void Imprime(const char* Message, int CordX, int CordY);




#endif // AFFICHAGE_H