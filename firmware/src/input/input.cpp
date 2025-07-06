#include <Arduino.h>
#include "input.h"
#include "audio/audio.h"
#define BUTTON_1_PIN 15
#define BUTTON_2_PIN 17
#define BUTTON_3_PIN 4

#define TOUCH_CS_PIN 5
#define TOUCH_IRQ_PIN 23

static input_callback_t event_callback = nullptr; //initialize the callback as null

bool last_state[4] = {false, false, false, false};

void input_init() {
    Serial.println("Initializing buttons");

    // Initialize GPIO pins for buttons
    pinMode(BUTTON_1_PIN, INPUT_PULLUP);
    pinMode(BUTTON_2_PIN, INPUT_PULLUP);
    pinMode(BUTTON_3_PIN, INPUT_PULLUP);

    Serial.println("Initalizing touchscreen");

    pinMode(TOUCH_IRQ_PIN, INPUT_PULLUP);
}

void input_set_callback(input_callback_t callback) {
    event_callback = callback; 
}

void input_update() {

    bool current_state[4] = {
        digitalRead(BUTTON_1_PIN) == LOW,
        digitalRead(BUTTON_2_PIN) == LOW,
        digitalRead(BUTTON_3_PIN) == LOW,
        digitalRead(TOUCH_IRQ_PIN) == HIGH
    };
   
    // Check for button state changes
    for (int i = 0; i < 3; i++) {
        if (current_state[i] != last_state[i]) {
            input_event_t event;
            event.type = INPUT_BUTTON;
            event.data.button = static_cast<input_button_t>(i); // plz fit enum;

            if (event_callback) {
                event_callback(event);
            }
        }
        last_state[i] = current_state[i];
    }

    // Check for touch state change
    if (current_state[3] != last_state[3]) {
        // would poll for touch coords.
        input_event_t event;
        event.type = INPUT_TOUCH;
        event.data.touch.x = 3; 
        event.data.touch.y = 3;
        if (event_callback) {
            event_callback(event);
        }
        last_state[3] = current_state[3];
    }

}

void handle_input(const input_event_t event) { // handles the event callback for input
    switch (event.type) {
        case INPUT_BUTTON:
            switch (event.data.button) {
                case BUTTON_LEFT:
                    if (audioCommandQueue != NULL) {
                        audio_command_t cmd = CMD_STOP;
                        xQueueSend(audioCommandQueue, &cmd, 0);
                    }
                    break;
                case BUTTON_RIGHT:
                    if (audioCommandQueue != NULL) {
                        audio_command_t cmd = CMD_NEXT;
                        xQueueSend(audioCommandQueue, &cmd, 0);
                    }
                    break;
                case BUTTON_SEL:
                    if (audioCommandQueue != NULL) {
                        audio_command_t cmd = CMD_PLAY;
                        xQueueSend(audioCommandQueue, &cmd, 0);
                    }
                    break;
            }
            break;
        case INPUT_TOUCH:
            Serial.printf("Touch at (%d, %d)\n", event.data.touch.x, event.data.touch.y);
            if (audioCommandQueue != NULL) { 
                audio_command_t cmd = CMD_NEXT;
                xQueueSend(audioCommandQueue, &cmd, 0);
            break;
            }
        }   
    }
