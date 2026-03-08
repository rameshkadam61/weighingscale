#pragma once
#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    lv_style_t screen;
    lv_style_t card;
    lv_style_t title;
    lv_style_t value_big;
    lv_style_t value;
    lv_style_t btn_primary;
    lv_style_t btn_secondary;
    lv_style_t btn_danger;
} ui_styles_t;

extern ui_styles_t g_styles;

void ui_styles_init(void);

#ifdef __cplusplus
}
#endif
