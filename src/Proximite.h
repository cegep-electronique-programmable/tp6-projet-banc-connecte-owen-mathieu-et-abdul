#include <Arduino.h>
#include <Wire.h>
#include <APDS9930.h>


//declaration de la methode qui initialise le capteur de proximite
void StartProx(APDS9930 apds, uint16_t proximity_data, int proximity_max);