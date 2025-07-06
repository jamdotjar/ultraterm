#ifndef UI_H
#define UI_H

#include <lvgl.h>

extern lv_obj_t *g_screen;
extern lv_obj_t *g_playback_label;

void ui_init(void);
void ui_update_playback(bool playing);

#endif // UI_H
