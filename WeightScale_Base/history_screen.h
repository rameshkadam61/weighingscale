#pragma once
#include <lvgl.h>

void history_screen_create(lv_obj_t *parent);
void history_screen_refresh(void);
void history_screen_register_back(void (*cb)(void));
