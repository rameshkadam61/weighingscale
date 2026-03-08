#pragma once
#include <lvgl.h>

void wifi_list_screen_create(lv_obj_t *parent);
void wifi_list_screen_show(void);
void wifi_list_screen_refresh(void);
void wifi_list_screen_register_back(void (*cb)(void));
void wifi_list_screen_register_select(void (*cb)(const char *ssid));
