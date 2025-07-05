#ifndef AUDIO_H
#define AUDIO_H


#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"

typedef enum {
    CMD_PLAY,
    CMD_PAUSE,
    CMD_RESUME,
    CMD_NEXT,
    CMD_STOP,
} audio_command_t;

extern QueueHandle_t audioCommandQueue;

void audio_init();
void audio_play();
void audio_pause();
void audio_resume();
void audio_stop();
void audio_next_track();


#endif // AUDIO_H
