#include "Proximite.h"



SparkFun_APDS9960 adps = SparkFun_APDS9960();









void intproxi (){
   // Wire.begin(SDA, SCL, APDS9960_I2C_ADDR); // join l'adresse du  slave au bus i2c
  //  Wire.onRequest(requestEvent);
  //Initialise le capteur de proximité  
 adps.init();
    adps.setProximityGain(PGAIN_2X);
    adps.enableProximitySensor(true);
    adps.enableLightSensor(true);
    

}
 

 