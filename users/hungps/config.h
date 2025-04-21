#pragma once

// #define USE_MATRIX_I2C

// #define QUICK_TAP_TERM 0
// #define TAPPING_TERM 100

#ifdef RGB_MATRIX_ENABLE
#    define RGB_MATRIX_KEYPRESSES // reacts to keypresses
#    define RGB_MATRIX_SLEEP      // turn off effects when suspended
#    define RGB_MATRIX_FRAMEBUFFER_EFFECTS
// #    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 150 // limits maximum brightness of LEDs to 150 out of 255. Higher may cause the controller to crash.
#    define RGB_MATRIX_HUE_STEP 8
#    define RGB_MATRIX_SAT_STEP 8
#    define RGB_MATRIX_VAL_STEP 8
#    define RGB_MATRIX_SPD_STEP 10

#    define ENABLE_RGB_MATRIX_ALPHAS_MODS
#    define ENABLE_RGB_MATRIX_BREATHING
#    define ENABLE_RGB_MATRIX_TYPING_HEATMAP
#endif
