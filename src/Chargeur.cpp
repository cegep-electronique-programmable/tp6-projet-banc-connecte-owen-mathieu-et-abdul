#include "Chargeur.h"
#define CHARGE_PIN A0

int Charge(void)
{
    int enCharge = analogRead(CHARGE_PIN);
    return enCharge;
}