#pragma once
#include <lvgl.h>

/* ================= EVENTS ================= */

typedef enum
{
    DEVNAME_EVT_SAVE = 1
} devname_event_t;

/* ================= API ================= */

void device_name_screen_create(lv_obj_t *parent);

/* callback gives entered text */
void device_name_screen_register_callback(
    void (*cb)(int evt, const char *name)
);

/* helpers */
void device_name_screen_set_title(const char *txt);
void device_name_screen_focus(void);
