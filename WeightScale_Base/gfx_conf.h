#pragma once

#include <Arduino.h>
#include <driver/i2c.h>

#ifdef pinMode
#undef pinMode
#endif

#define LGFX_USE_V1
#include <LovyanGFX.hpp>
#include <lgfx/v1/platforms/esp32s3/Panel_RGB.hpp>
#include <lgfx/v1/platforms/esp32s3/Bus_RGB.hpp>



#define screenWidth   800
#define screenHeight  480

class LGFX : public lgfx::LGFX_Device
{
public:
    lgfx::Bus_RGB     bus;
    lgfx::Panel_RGB   panel;
    lgfx::Light_PWM   backlight;
    lgfx::Touch_GT911 touch;

    LGFX()
    {
        // Panel
        {
            auto cfg = panel.config();
            cfg.memory_width  = screenWidth;
            cfg.memory_height = screenHeight;
            cfg.panel_width   = screenWidth;
            cfg.panel_height  = screenHeight;
            cfg.offset_x = 0;
            cfg.offset_y = 0;
            panel.config(cfg);
        }

        // RGB Bus
        {
            auto cfg = bus.config();
            cfg.panel = &panel;

            cfg.pin_d0  = GPIO_NUM_15;
            cfg.pin_d1  = GPIO_NUM_7;
            cfg.pin_d2  = GPIO_NUM_6;
            cfg.pin_d3  = GPIO_NUM_5;
            cfg.pin_d4  = GPIO_NUM_4;

            cfg.pin_d5  = GPIO_NUM_9;
            cfg.pin_d6  = GPIO_NUM_46;
            cfg.pin_d7  = GPIO_NUM_3;
            cfg.pin_d8  = GPIO_NUM_8;
            cfg.pin_d9  = GPIO_NUM_16;
            cfg.pin_d10 = GPIO_NUM_1;

            cfg.pin_d11 = GPIO_NUM_14;
            cfg.pin_d12 = GPIO_NUM_21;
            cfg.pin_d13 = GPIO_NUM_47;
            cfg.pin_d14 = GPIO_NUM_48;
            cfg.pin_d15 = GPIO_NUM_45;

            cfg.pin_henable = GPIO_NUM_41;
            cfg.pin_vsync   = GPIO_NUM_40;
            cfg.pin_hsync   = GPIO_NUM_39;
            cfg.pin_pclk    = GPIO_NUM_0;

            cfg.freq_write = 12000000;

            cfg.hsync_front_porch = 40;
            cfg.hsync_pulse_width = 48;
            cfg.hsync_back_porch  = 40;

            cfg.vsync_front_porch = 1;
            cfg.vsync_pulse_width = 31;
            cfg.vsync_back_porch  = 13;

            cfg.pclk_active_neg = 1;
            cfg.de_idle_high = 0;
            cfg.pclk_idle_high = 0;


            bus.config(cfg);
            panel.setBus(&bus);
        }

        // Backlight
        {
            auto cfg = backlight.config();
            cfg.pin_bl = GPIO_NUM_2;
            backlight.config(cfg);
            panel.light(&backlight);
        }

        // Touch
        {
        auto cfg = touch.config();
        cfg.x_min = 0;
        cfg.x_max = 799;
        cfg.y_min = 0;
        cfg.y_max = 479;
        cfg.i2c_port = I2C_NUM_1;
        cfg.pin_sda = GPIO_NUM_19;
        cfg.pin_scl = GPIO_NUM_20;
        cfg.i2c_addr = 0x14;
        cfg.freq = 400000;
        cfg.bus_shared = true;
        cfg.pin_int = -1;
        cfg.pin_rst = -1;
        cfg.offset_rotation = 0;
        touch.config(cfg);
        panel.setTouch(&touch);

        }

        setPanel(&panel);
    }
};

extern LGFX tft;
