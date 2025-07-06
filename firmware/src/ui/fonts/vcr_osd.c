/*******************************************************************************
 * Size: 16 px
 * Bpp: 1
 * Opts: --bpp 1 --size 16 --no-compress --font VCR_OSD_MONO_1.001.ttf --symbols ABCDEFGHIJKLMNOPQRSTUVWXWZ1234567890abcdefghijklmnopqrstuvwxyz --format lvgl -o vcr_osd.c
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include <lvgl.h>
#endif

#ifndef VCR_OSD
#define VCR_OSD 1
#endif

#if VCR_OSD

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0030 "0" */
    0x3c, 0x66, 0x42, 0xc3, 0xc7, 0xcb, 0xd3, 0xe3,
    0xc3, 0xc3, 0x66, 0x3c,

    /* U+0031 "1" */
    0x67, 0x38, 0xc6, 0x31, 0x8c, 0x63, 0x19, 0xf0,

    /* U+0032 "2" */
    0x3c, 0x66, 0xc3, 0x3, 0x3, 0x6, 0x7c, 0xe0,
    0xc0, 0xc0, 0xc0, 0xff,

    /* U+0033 "3" */
    0x7c, 0x46, 0xc3, 0x3, 0x3, 0x6, 0x1e, 0x7,
    0x3, 0xc3, 0x46, 0x7c,

    /* U+0034 "4" */
    0x6, 0x6, 0xe, 0x16, 0xe6, 0xc6, 0xc6, 0xff,
    0x6, 0x6, 0x6, 0x6,

    /* U+0035 "5" */
    0xff, 0xc0, 0xc0, 0xc0, 0xfc, 0x7, 0x3, 0x3,
    0x3, 0xc3, 0x66, 0x3c,

    /* U+0036 "6" */
    0x3c, 0x66, 0xc3, 0xc0, 0xc0, 0xc0, 0xfe, 0xc7,
    0xc3, 0xc3, 0x66, 0x3c,

    /* U+0037 "7" */
    0xff, 0x3, 0x3, 0x3, 0x7, 0xc, 0x18, 0x18,
    0x18, 0x18, 0x18, 0x18,

    /* U+0038 "8" */
    0x3c, 0x66, 0xc3, 0xc3, 0xc3, 0x66, 0x7e, 0xe7,
    0xc3, 0xc3, 0x66, 0x3c,

    /* U+0039 "9" */
    0x3c, 0x66, 0xc3, 0xc3, 0xc3, 0x63, 0x3f, 0x3,
    0x3, 0xc3, 0x66, 0x3c,

    /* U+0041 "A" */
    0x18, 0x28, 0x28, 0x66, 0x42, 0xc3, 0xc3, 0xff,
    0xc3, 0xc3, 0xc3, 0xc3,

    /* U+0042 "B" */
    0xfc, 0xc6, 0xc3, 0xc3, 0xc3, 0xc6, 0xfe, 0xc7,
    0xc3, 0xc3, 0xc6, 0xfc,

    /* U+0043 "C" */
    0x3e, 0x62, 0xc3, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0,
    0xc0, 0xc3, 0x62, 0x3e,

    /* U+0044 "D" */
    0xfc, 0xc6, 0xc2, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0xc3, 0xc3, 0xc6, 0xfc,

    /* U+0045 "E" */
    0xff, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xfe, 0xc0,
    0xc0, 0xc0, 0xc0, 0xff,

    /* U+0046 "F" */
    0xff, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xfe, 0xc0,
    0xc0, 0xc0, 0xc0, 0xc0,

    /* U+0047 "G" */
    0x3c, 0x66, 0x42, 0xc3, 0xc0, 0xc0, 0xcf, 0xc3,
    0xc3, 0xc3, 0x66, 0x3c,

    /* U+0048 "H" */
    0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xff, 0xc3,
    0xc3, 0xc3, 0xc3, 0xc3,

    /* U+0049 "I" */
    0xfb, 0x18, 0xc6, 0x31, 0x8c, 0x63, 0x19, 0xf0,

    /* U+004A "J" */
    0x1f, 0xc, 0xc, 0xc, 0xc, 0xc, 0xc, 0xc,
    0xc, 0xcc, 0x58, 0x70,

    /* U+004B "K" */
    0xc3, 0xc2, 0xc4, 0xcc, 0xd0, 0xd0, 0xf0, 0xd0,
    0xd8, 0xc4, 0xc2, 0xc3,

    /* U+004C "L" */
    0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0,
    0xc0, 0xc0, 0xc0, 0xff,

    /* U+004D "M" */
    0xc3, 0xc3, 0xc3, 0xe7, 0xdb, 0xdb, 0xdb, 0xc3,
    0xc3, 0xc3, 0xc3, 0xc3,

    /* U+004E "N" */
    0xc3, 0xc3, 0xc3, 0xe3, 0xe3, 0xd3, 0xcb, 0xcb,
    0xc7, 0xc3, 0xc3, 0xc3,

    /* U+004F "O" */
    0x3c, 0x66, 0x42, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0xc3, 0xc3, 0x66, 0x3c,

    /* U+0050 "P" */
    0xfc, 0xc6, 0xc3, 0xc3, 0xc3, 0xc6, 0xfc, 0xc0,
    0xc0, 0xc0, 0xc0, 0xc0,

    /* U+0051 "Q" */
    0x7e, 0x66, 0x42, 0xc3, 0xc3, 0xc3, 0xc3, 0xdb,
    0xcb, 0xcf, 0x2a, 0x3b,

    /* U+0052 "R" */
    0xfc, 0xc6, 0xc3, 0xc3, 0xc3, 0xc6, 0xfc, 0xd8,
    0xd8, 0xcc, 0xc2, 0xc3,

    /* U+0053 "S" */
    0x3c, 0x66, 0xc3, 0xc0, 0xc0, 0x60, 0x3e, 0x7,
    0x3, 0xc3, 0x66, 0x3c,

    /* U+0054 "T" */
    0xff, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
    0x18, 0x18, 0x18, 0x18,

    /* U+0055 "U" */
    0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0xc3, 0xc3, 0x66, 0x3c,

    /* U+0056 "V" */
    0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0x42,
    0x44, 0x24, 0x28, 0x18,

    /* U+0057 "W" */
    0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xdb, 0xdb, 0xdb,
    0xdb, 0xdb, 0x5a, 0x24,

    /* U+0058 "X" */
    0xc3, 0xc3, 0xc3, 0x46, 0x28, 0x38, 0x38, 0x38,
    0x6e, 0xc3, 0xc3, 0xc3,

    /* U+005A "Z" */
    0xff, 0x3, 0x3, 0x3, 0x6, 0x8, 0x10, 0x60,
    0xc0, 0xc0, 0xc0, 0xff,

    /* U+0061 "a" */
    0x3c, 0x6, 0x2, 0x3, 0x7f, 0xc3, 0xc3, 0xc3,
    0x67, 0x3b,

    /* U+0062 "b" */
    0xc0, 0xc0, 0xc0, 0xd8, 0xf6, 0xe3, 0xe3, 0xe3,
    0xe3, 0xe6, 0xd8, 0xd8,

    /* U+0063 "c" */
    0x3e, 0x62, 0xc3, 0xc0, 0xc0, 0xc0, 0xc3, 0x62,
    0x3e,

    /* U+0064 "d" */
    0x3, 0x3, 0x3, 0x1b, 0x6f, 0xc7, 0xc7, 0xc7,
    0xc7, 0x67, 0x2b, 0x1b,

    /* U+0065 "e" */
    0x3e, 0x62, 0xc3, 0xfe, 0xc0, 0xc0, 0xe3, 0x62,
    0x3e,

    /* U+0066 "f" */
    0x1c, 0xc3, 0x3f, 0x30, 0xc3, 0xc, 0x30, 0xc3,
    0xc,

    /* U+0067 "g" */
    0x7c, 0x46, 0xc3, 0x47, 0x7f, 0x3, 0x3, 0x3,
    0x46, 0x7c,

    /* U+0068 "h" */
    0xc0, 0xc0, 0xc0, 0xd8, 0xd4, 0xe2, 0xc3, 0xc3,
    0xc3, 0xc3, 0xc3, 0xc3,

    /* U+0069 "i" */
    0x30, 0x0, 0xf, 0x18, 0xc6, 0x31, 0xc6,

    /* U+006A "j" */
    0x18, 0x0, 0xf1, 0x8c, 0x63, 0x18, 0xcf, 0xe0,

    /* U+006B "k" */
    0xc0, 0xc0, 0xc0, 0xc3, 0xc2, 0xcc, 0xc8, 0xd8,
    0xd8, 0xe6, 0xc2, 0xc3,

    /* U+006C "l" */
    0xff, 0xff, 0xff,

    /* U+006D "m" */
    0xfc, 0xfe, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb,
    0xdb,

    /* U+006E "n" */
    0xdc, 0xe6, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0xc3,

    /* U+006F "o" */
    0x3c, 0xe7, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0x66,
    0x3c,

    /* U+0070 "p" */
    0xdc, 0xe6, 0xe3, 0xe3, 0xe3, 0xe7, 0xfe, 0xc0,
    0xc0, 0xc0,

    /* U+0071 "q" */
    0x3b, 0x67, 0xc7, 0xc7, 0xc7, 0xc7, 0x7f, 0x3,
    0x3, 0x3,

    /* U+0072 "r" */
    0xde, 0xd2, 0xf3, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0,
    0xc0,

    /* U+0073 "s" */
    0x7e, 0x42, 0xc1, 0x78, 0xe, 0x2, 0x83, 0x42,
    0x7e,

    /* U+0074 "t" */
    0x63, 0x19, 0xf6, 0x31, 0x8c, 0x63, 0xc, 0x30,

    /* U+0075 "u" */
    0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0x66,
    0x3c,

    /* U+0076 "v" */
    0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0x66, 0x28,
    0x18,

    /* U+0077 "w" */
    0xc3, 0xc3, 0xc3, 0xdb, 0xdb, 0xdb, 0xdb, 0x7e,
    0x24,

    /* U+0078 "x" */
    0xc3, 0x42, 0x3c, 0x18, 0x18, 0x18, 0x24, 0x42,
    0xc3,

    /* U+0079 "y" */
    0xc3, 0xc7, 0xc7, 0xef, 0x3b, 0x3, 0x3, 0x6,
    0x3c,

    /* U+007A "z" */
    0xff, 0x3, 0x2, 0x6, 0x2c, 0x30, 0x20, 0x60,
    0xff
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 150, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 12, .adv_w = 150, .box_w = 5, .box_h = 12, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 20, .adv_w = 150, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 32, .adv_w = 150, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 44, .adv_w = 150, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 56, .adv_w = 150, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 68, .adv_w = 150, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 80, .adv_w = 150, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 92, .adv_w = 150, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 104, .adv_w = 150, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 116, .adv_w = 150, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 128, .adv_w = 150, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 140, .adv_w = 150, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 152, .adv_w = 150, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 164, .adv_w = 150, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 176, .adv_w = 150, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 188, .adv_w = 150, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 200, .adv_w = 150, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 212, .adv_w = 150, .box_w = 5, .box_h = 12, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 220, .adv_w = 150, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 232, .adv_w = 150, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 244, .adv_w = 150, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 256, .adv_w = 150, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 268, .adv_w = 150, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 280, .adv_w = 150, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 292, .adv_w = 150, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 304, .adv_w = 150, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 316, .adv_w = 150, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 328, .adv_w = 150, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 340, .adv_w = 150, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 352, .adv_w = 150, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 364, .adv_w = 150, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 376, .adv_w = 150, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 388, .adv_w = 150, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 400, .adv_w = 150, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 412, .adv_w = 150, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 422, .adv_w = 150, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 434, .adv_w = 150, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 443, .adv_w = 150, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 455, .adv_w = 150, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 464, .adv_w = 150, .box_w = 6, .box_h = 12, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 473, .adv_w = 150, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 483, .adv_w = 150, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 495, .adv_w = 150, .box_w = 5, .box_h = 11, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 502, .adv_w = 150, .box_w = 5, .box_h = 12, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 510, .adv_w = 150, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 522, .adv_w = 150, .box_w = 2, .box_h = 12, .ofs_x = 4, .ofs_y = 1},
    {.bitmap_index = 525, .adv_w = 150, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 534, .adv_w = 150, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 543, .adv_w = 150, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 552, .adv_w = 150, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 562, .adv_w = 150, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 572, .adv_w = 150, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 581, .adv_w = 150, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 590, .adv_w = 150, .box_w = 5, .box_h = 12, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 598, .adv_w = 150, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 607, .adv_w = 150, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 616, .adv_w = 150, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 625, .adv_w = 150, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 634, .adv_w = 150, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 643, .adv_w = 150, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 1}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 48, .range_length = 10, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 65, .range_length = 24, .glyph_id_start = 11,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 90, .range_length = 1, .glyph_id_start = 35,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 97, .range_length = 26, .glyph_id_start = 36,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 4,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif
};



/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t vcr_osd = {
#else
lv_font_t vcr_osd = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 12,          /*The maximum line height required by the font*/
    .base_line = -1,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -2,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if VCR_OSD*/

