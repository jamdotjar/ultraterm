#include <Arduino.h>

void system_init() {
    Serial.println("System initializing");
    
    // Note: Arduino framework with ESP32-A2DP library handles Bluetooth initialization
    // No manual NVS or Bluetooth stack initialization needed
    
    Serial.println("System initialization complete");
}