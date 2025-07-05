#include <Arduino.h>
#include <SPI.h> 
#include "storage/storage.h"
#include "audio/audio.h"
#include "input/input.h"
void system_init() {
    Serial.println("System initializing");

    const int CS_PIN = 5;
    const int MOSI_PIN = 23;
    const int MISO_PIN = 19;
    const int SCK_PIN = 18;
    SPI.begin(SCK_PIN, MISO_PIN, MOSI_PIN, CS_PIN);
    
    // Initialize SPI for SD card, finds music files
    storage_init(CS_PIN);

    // connect to Bluetooth and set up A2DP audio source
    audio_init();

    input_init();



    
    // Note: Arduino framework with ESP32-A2DP library handles Bluetooth initialization
    // No manual NVS or Bluetooth stack initialization needed
    
    Serial.println("System initialization complete");
}