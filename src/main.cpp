#include <Arduino.h>
#include "affichage.h"
#include "DEL.h"
#include "Proximite.h"

#define DUMP_REGS
#define PWM_LED_PIN       10

// Global Variables
APDS9930 apds = APDS9930();
uint16_t proximity_data = 0;
int proximity_max = 0;
bool isCharging = false;

#define MasterPiece_width 128
#define MasterPiece_height 64

// the setup function runs once when you press reset or power the board
void setup() {
  // Initialiser les LEDs et les capteurs
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600); // Pour déboguer et afficher des informations
  
  //Proximite
  StartProx(apds, proximity_data, proximity_max);
  
  //DEL
  run();
  
  //OLED
  StartScreen();
}

void loop() {
  
  // Read the proximity value
  if ( !apds.readProximity(proximity_data) ) {
    Serial.println("Error reading proximity value");
  } else {
    Serial.print("Proximity: ");
    Serial.print(proximity_data);
    
    apds.readProximity(proximity_data);
    Serial.print(F("  Remapped: "));
    Serial.println(proximity_data);
    analogWrite(PWM_LED_PIN, proximity_data);
  }
  delay(10);
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  setBrightness();
  isCharging = true;
  AfficherInfo(proximity_data, 15);
  if (isCharging) {
    rouge(); // Charge active
  } else {
    jaune(); // Pas en charge
  }
  delay(1000);
  isCharging = false;
  if (isCharging) {
    rouge(); // Charge active
  } else {
    jaune(); // Pas en charge
  }
  AfficherImage(0, 0, MasterPiece_width, MasterPiece_height, MasterPiece_bits);
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  delay(1000);  
}
