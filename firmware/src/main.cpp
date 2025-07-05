#include <Arduino.h>

#include "system/system_init.h"
#include "ui/ui_init.h"
#include "input/input.h"
#include "audio/audio.h"
#include "storage/storage.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

TaskHandle_t ioTaskHandle = NULL;
TaskHandle_t audioTaskHandle = NULL;
QueueHandle_t audioCommandQueue = NULL;

void setup() {
    Serial.begin(115200);
    Serial.println("Starting ULTRATERM core system");
    
    system_init();


    Serial.println("ULTRATERM core system initialized");

    Serial.println("Starting core tasks");

    audioCommandQueue = xQueueCreate(10, sizeof(audio_command_t));
    if (audioCommandQueue == NULL) {
        Serial.println("Error Creating cmd queue");
    }

    xTaskCreatePinnedToCore(ioTask, "Input/UI task", 4069, NULL, 1, &ioTaskHandle, 0);
    xTaskCreatePinnedToCore(audioTask, "Audio task", 4096, NULL, 1, &audioTaskHandle, 1);

    Serial.println("Core tasks started");
    Serial.println("ULTRATERM fully initialzed")
}

void ioTask() {
    ui_init();
    set_input_callback(handle_input);

    while(true) {
        input_update();
        vTaskDelay(1);
        // UI GOES HERE
        
  }
}

void audioTask() {

    audio_command_t cmd;

    while (true) {
        // Handle audio processing here
        vTaskDelay(1);

        if (xQueueReceive(audioCommandQueue, &cmd, 0) == pdTRUE) {
            switch (cmd) {
                case CMD_PLAY:
                    Serial.println("PLAYING");
                    audio_play();
                    break;
                case CMD_PAUSE:
                    Serial.println("PAUSED");
                    audio_pause();
                    break;
                case CMD_RESUME:
                    Serial.println("RESUMING"); //might be able to cut
                    audio_resume();
                    break;
                case CMD_NEXT:
                    Serial.println("NEXT");
                    audio_next_track();
                    break;
                case CMD_STOP: 
                    Serial.println("STOPPING");
                    audio_stop();
                    break;
            }
        }
    }
}





