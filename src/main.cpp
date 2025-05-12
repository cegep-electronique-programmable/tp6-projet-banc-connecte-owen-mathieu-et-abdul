#include <Arduino.h>
#include "affichage.h"
#include "DEL.h"
#include "Proximite.h"

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  StartScreen();
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  AfficherInfo(10, 15);
  delay(1000);                      // wait for 1second
  AfficherInfo(11, 14);
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  delay(100);                      // wait for 100ms
}