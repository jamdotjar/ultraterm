#include <Arduino.h>
#include <TFT_eSPI.h>
#include <lvgl.h>
#include "fonts/vcr_osd.h"

lv_obj_t *g_screen = NULL;
lv_obj_t *g_playback_label = NULL;

#define TFT_HOR_RES   320
#define TFT_VER_RES   240
#define TFT_ROTATION  LV_DISPLAY_ROTATION_0
#define DRAW_BUF_SIZE (TFT_HOR_RES * TFT_VER_RES / 10 * (LV_COLOR_DEPTH / 8))
#if defined(BOARD_HAS_PSRAM) && defined(CONFIG_SPIRAM_SUPPORT)
    #define USE_PSRAM
    static uint32_t *draw_buf = (uint32_t*)ps_malloc(DRAW_BUF_SIZE);
#else
    static uint32_t draw_buf[DRAW_BUF_SIZE / 4];
#endif

static uint32_t my_tick(void)
{
    return millis();
}

void ui_init() {
    Serial.println("UI initialization started");

    String LVGL_Arduino = "LVGL initialized,";
    LVGL_Arduino += String('V') + lv_version_major() + "." + lv_version_minor() + "." + lv_version_patch();
    Serial.println( LVGL_Arduino );

    lv_init();
//set tick callback
    lv_tick_set_cb(my_tick);

    // initialize display proper w/ tft_espi
    lv_display_t * disp;
    
    disp = lv_tft_espi_create(TFT_HOR_RES, TFT_VER_RES, draw_buf, sizeof(draw_buf));
    lv_display_set_rotation(disp, TFT_ROTATION);

    lv_display_set_flush_cb(disp, [](lv_display_t *disp, const lv_area_t *area, uint8_t *px_map) {
        // Your TFT_eSPI flush code here
        // This is a placeholder - you'll need to adapt it for your TFT_eSPI setup
        static TFT_eSPI tft = TFT_eSPI();
        
        uint32_t w = (area->x2 - area->x1 + 1);
        uint32_t h = (area->y2 - area->y1 + 1);
        
        tft.setAddrWindow(area->x1, area->y1, w, h);
        tft.pushColors((uint16_t*)px_map, w * h, true);
        
        lv_display_flush_ready(disp);
    });
    lv_display_set_buffers(disp, draw_buf, NULL, sizeof(draw_buf), LV_DISPLAY_RENDER_MODE_PARTIAL);

    g_screen = lv_obj_create(NULL);
    lv_obj_set_style_bg_color(g_screen, lv_color_hex(0x000000), 0); // Black background
    lv_display_set_default(disp);

    lv_obj_t *label = lv_label_create( lv_screen_active() );
    lv_label_set_text( label, "ULTRATERM" );
    lv_obj_align( label, LV_ALIGN_CENTER, 0, 0 );

    lv_obj_set_style_text_font(label, &vcr_osd_32, 0);
    
    g_playback_label = lv_label_create(g_screen);
    lv_obj_set_style_text_font(g_playback_label, &vcr_osd, 0);
    lv_obj_align(g_playback_label, LV_ALIGN_CENTER, 0, 0);
    lv_label_set_text(g_playback_label, "Paused");

    lv_obj_set_style_text_font(g_playback_label, &vcr_osd, 0);
    
    Serial.println("UI initialization complete");
}

void ui_update_playback(bool playing) {
    // Update UI elements based on playback state
    if (playing) {
        lv_label_set_text(g_playback_label, "Playing");
    } else {
        lv_label_set_text(g_playback_label, "Paused");
    }

    lv_refr_now(NULL);
}
