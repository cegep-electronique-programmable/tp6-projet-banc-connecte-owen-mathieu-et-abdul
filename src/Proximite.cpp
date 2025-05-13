#include "Proximite.h"



APDS9930 apds = APDS9930();
uint16_t proximity_data = 0;








void intproxi (){
   // Wire.begin(SDA, SCL, APDS9960_I2C_ADDR); // join l'adresse du  slave au bus i2c
  //  Wire.onRequest(requestEvent);
  //Initialise le capteur de proximité  
 apds.init();
    apds.setProximityGain(PGAIN_2X);
    apds.enableProximitySensor(true);
    apds.enableLightSensor(true);
    
}

void loop2(void){
    apds.readProximity(proximity_data);
    
}
 

 