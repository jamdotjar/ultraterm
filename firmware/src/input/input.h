#ifndef INPUT_H
#define INPUT_H

#include <Arduino.h>

typedef enum {
    BUTTON_LEFT = 0,
    BUTTON_RIGHT = 1,   
    BUTTON_SEL = 2,
} input_button_t;

typedef enum { // all (currently) possible input types
    INPUT_BUTTON,
    INPUT_TOUCH //might need to move to UI, rn handling here
} input_type_t;

typedef union {
    input_button_t button;
    struct {
        uint16_t x;
        uint16_t y;
    } touch;
} input_data_t;

typedef struct {
    input_type_t type; //type of input event
    input_data_t data; //data for the event, either button state or touch coordinates
} input_event_t;

typedef void (*input_callback_t)(const input_event_t event); //create s a type for callbacks, includes the envent type/struct 

void input_init();
void input_set_callback(input_callback_t callback);

#endif // INPUT_H

