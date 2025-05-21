#include "Proximite.h"

void StartProx(APDS9930 apds, uint16_t proximity_data, int proximity_max){
    //Proximite
    Serial.println();
    Serial.println(F("------------------------"));
    Serial.println(F("APDS-9930 - ProximityLED"));
    Serial.println(F("------------------------"));
    
    // Initialize APDS-9930 (configure I2C and initial values)
    if ( apds.init() ) {
        Serial.println(F("APDS-9930 initialization complete"));
    } else {
        Serial.println(F("Something went wrong during APDS-9930 init!"));
    }
    
    // Adjust the Proximity sensor gain
    if ( !apds.setProximityGain(PGAIN_1X) ) {
        Serial.println(F("Something went wrong trying to set PGAIN"));
    }
    
    // Start running the APDS-9930 proximity sensor (no interrupts)
    if ( apds.enableProximitySensor(false) ) {
        Serial.println(F("Proximity sensor is now running"));
    } else {
        Serial.println(F("Something went wrong during sensor init!"));
        apds.enableProximitySensor(true);
        //apds.enableLightSensor(true);
    }
    if (apds.enableLightSensor(false) ) {
    Serial.println(F("Light sensor is now running"));
  }
  else{
    Serial.println(F("Something went wrong during sensor init!"));
    apds.enableLightSensor(true);
  } 

    #ifdef DUMP_REGS
        /* Register dump */
        uint8_t reg;
        uint8_t val;

        for(reg = 0x00; reg <= 0x19; reg++) {
        if( (reg != 0x10) && \
            (reg != 0x11) )
        {
            apds.wireReadDataByte(reg, val);
            Serial.print(reg, HEX);
            Serial.print(": 0x");
            Serial.println(val, HEX);
        }
        }
        apds.wireReadDataByte(0x1E, val);
        Serial.print(0x1E, HEX);
        Serial.print(": 0x");
        Serial.println(val, HEX);
    #endif
}