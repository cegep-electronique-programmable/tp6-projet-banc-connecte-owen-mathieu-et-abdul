#include "Proximite.h"



APDS9930 apds = APDS9930();









void intproxi (){
   // Wire.begin(SDA, SCL, APDS9960_I2C_ADDR); // join l'adresse du  slave au bus i2c
  //  Wire.onRequest(requestEvent);
  //Initialise le capteur de proximité  
 apds.init();
    apds.setProximityGain(PGAIN_2X);
    apds.enableProximitySensor(true);
    apds.enableLightSensor(true);
    
}
 

 