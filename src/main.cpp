#include <Arduino.h>
#include "affichage.h"
#include "DEL.h"
#include "Proximite.h"

void setup() {
  // Initialiser les LEDs et les capteurs
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600); // Pour déboguer et afficher des informations
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for 1second
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  delay(100);                      // wait for 100ms
}




/*
void setup() {
  // Initialiser les LEDs et les capteurs
  pinMode(LED_BUILTIN, OUTPUT);
  run();
  Serial.begin(9600); // Pour déboguer et afficher des informations
}

void loop() {
  setBrightness(int bri); // Ajuster la luminosité selon l'environnement

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
*/