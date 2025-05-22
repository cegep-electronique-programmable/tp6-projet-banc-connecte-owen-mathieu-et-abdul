#include "DEL.h" // inclure le fichier d'en-tête DEL.h

// définition des constantes
#define PIN         1         // Broche dedonnée pour la DEL
#define NUMPIXELS   10        // Nombre de pixels dans la bande LED
#define BRIGHTNESS  50        // Luminosité de la DEL

#define LIGHT_SENSOR_PIN 10   // Broche pour le capteur de lumière

// Initialisation de la bande LED
Adafruit_NeoPixel strip(64, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

//#define DELAYVAL 1            // Temps d'attente entre les changements de couleur

// Fonctoin d'initialisation ds DELs
void run() {
  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
    clock_prescale_set(clock_div_1);
  #endif
    pixels.begin();           // Initialisation de la bande LED
    strip.show();             // Initialisation de la bande LED
    strip.setBrightness(BRIGHTNESS);  // Réglage de la luminosité
}

// Fonction pour changer la couleur a rouge
void rouge() {
  pixels.clear(); 
  for (int i = 0; i < NUMPIXELS; i++) { 
    pixels.setPixelColor(i, pixels.Color(255, 0, 0)); // Rouge
    pixels.show();  
  //  delay(DELAYVAL); 
  }  
}

// Fonction pour changer la couleur a jaune
void jaune() {
  pixels.clear();   // Effacer la bande LED
  for (int i = 0; i < NUMPIXELS; i++) { 
    pixels.setPixelColor(i, pixels.Color(255, 255, 0)); // Jaune
    pixels.show();  
   // delay(DELAYVAL); 
  }  
}
 // Fonction pour lire le niveau de luminosité
float adjustBrightness(){
  float lightLevel = analogRead(LIGHT_SENSOR_PIN); // lire la valeur du capteur de lumière
  float brightness = lightLevel;
  return brightness;
}
  // Fonction pour changer la luminosité
void setBrightness(float Light_Data) {
  strip.setBrightness(Light_Data);  
  pixels.setBrightness(Light_Data);
}