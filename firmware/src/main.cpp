#include <Arduino.h>

#include "system/system_init.h"
#include "ui/ui_init.h"
#include "audio/a2dp_init.h"


void setup() {
    Serial.begin(115200);
    Serial.println("Starting Ultraterm firmware");
    
    system_init();
    ui_init();
    audio_init();
}

void loop() {
    // Main loop - Arduino handles task scheduling
    delay(1000);
}