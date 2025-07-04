#include "BluetoothA2DPSource.h"
#include <Arduino.h>
#include <math.h>
#include <string.h>

#define c3_frequency  130.81

BluetoothA2DPSource a2dp_source;

// The supported audio codec in ESP32 A2DP is SBC. SBC audio stream is encoded

int32_t get_data(uint8_t *data, int32_t bytes) {
    memset(data, 0, bytes);
    return bytes;
}

// Return true to connect, false will continue scanning: You can use this
// callback to build a list.
bool isValid(const char* ssid, esp_bd_addr_t address, int rssi){
   Serial.printf("Available device: %s (RSSI: %d)\n", ssid, rssi);
   return true;
}

void audio_init() {
    Serial.println("Initializing A2DP audio source");
    
    a2dp_source.set_ssid_callback(isValid);
    a2dp_source.set_auto_reconnect(false);
    a2dp_source.set_data_callback(get_data);
    a2dp_source.set_volume(30);
    a2dp_source.start();
    
    Serial.println("A2DP audio source started");
}

void audio_play() {
    Serial.println("playing");
    
}