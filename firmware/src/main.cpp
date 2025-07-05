#include <Arduino.h>

#include "system/system_init.h"
#include "ui/ui_init.h"


void setup() {
    Serial.begin(115200);
    Serial.println("Starting Ultraterm firmware");
    
    system_init();
    ui_init();

    Serial.println("Ultraterm firmware initialized");
}



