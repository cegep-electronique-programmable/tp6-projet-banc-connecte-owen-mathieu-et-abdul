#include "DEL.h"
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif
#include "DEL.h"

void setup() {
  // Initialiser les LEDs et les capteurs
  pinMode(LED_BUILTIN, OUTPUT);
  run();
  Serial.begin(9600); // Pour déboguer et afficher des informations
}

void loop() {
  setBrightness(); // Ajuster la luminosité selon l'environnement

  // Simuler l'état de charge
  bool isCharging = true; // Mettre à jour cette variable en fonction de l'état réel du chargeur

  // Si l'appareil est en charge, allumer les LEDs en rouge, sinon en jaune
  if (isCharging) {
    rouge(); // Charge active
  } else {
    jaune(); // Pas en charge
  }

  delay(1000); // Attendre 1 seconde avant la prochaine mise à jour
}