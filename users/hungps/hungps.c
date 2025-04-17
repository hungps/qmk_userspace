#include QMK_KEYBOARD_H

#include "oneshot.h"
#include "layers.h"

#define SPACE_L C(KC_LEFT)
#define SPACE_R C(KC_RGHT)
#define LA_SYM MO(SYM)
#define LA_NAV MO(NAV)
#define DF_DEF DF(DEF)
#define DF_GAM DF(GAM)
#define MT_LSFT_TAB LSFT_T(KC_TAB)
#define RECORD G(S(KC_5))
#define PRNSCR G(S(KC_4))

enum keycodes {
    // Custom oneshot mod implementation with no timers.
    OS_SHFT = SAFE_RANGE,
    OS_CTRL,
    OS_ALT,
    OS_CMD,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [DEF] = LAYOUT_hungps(
        KC_Q,    KC_W,    KC_F,    KC_P,        KC_B,                                   KC_J,    KC_L,      KC_U,    KC_Y,    KC_QUOT,
        KC_A,    KC_R,    KC_S,    KC_T,        KC_G,                                   KC_M,    KC_N,      KC_E,    KC_I,    KC_O,
        KC_Z,    KC_X,    KC_C,    KC_D,        KC_V,       KC_MUTE,        KC_MPLY,    KC_K,    KC_H,      KC_COMM, KC_DOT,  KC_SCLN,
                                   LA_NAV,      KC_SPC,     MT_LSFT_TAB,    KC_ENTER,   KC_BSPC, LA_SYM
    ),

    [SYM] = LAYOUT_hungps(
        KC_LABK, KC_LCBR, KC_LBRC, KC_LPRN,     KC_TILD,                                KC_CIRC, KC_RPRN, KC_RBRC, KC_RCBR, KC_RABK,
        KC_AMPR, KC_PIPE, KC_EXLM, KC_QUES,     KC_COLN,                                KC_DLR,  OS_SHFT, OS_CMD,  OS_ALT,  OS_CTRL,
        KC_PLUS, KC_MINS, KC_ASTR, KC_SLSH,     KC_PERC,    _______,        _______,    KC_QUOT, KC_UNDS, KC_AT,   KC_HASH, KC_BSLS,
                                   _______,     _______,    _______,        QK_BOOT,    _______, XXXXXXX
    ),

    [NAV] = LAYOUT_hungps(
        DF_GAM,  RECORD,  PRNSCR,  KC_MSEL,     KC_VOLU,                                KC_HOME, KC_PGDN, KC_PGUP, KC_END,  DF_DEF,
        OS_CTRL, OS_ALT,  OS_CMD,  OS_SHFT,     KC_VOLD,                                KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_DEL,
        SPACE_L, SPACE_R, KC_MPRV, KC_MNXT,     KC_MPLY,    _______,        _______,    MS_LEFT, MS_DOWN, MS_UP,   MS_RGHT, QK_REP,
                                   XXXXXXX,     _______,    QK_BOOT,        MS_BTN1,    MS_BTN2, MS_BTN3
    ),

    [NUM] = LAYOUT_hungps(
        KC_1,    KC_2,    KC_3,    KC_4,        KC_5,                                   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        OS_CTRL, OS_ALT,  OS_CMD,  OS_SHFT,     KC_F11,                                 KC_F12,  OS_SHFT, OS_CMD,  OS_ALT,  OS_CTRL,
        KC_F1,   KC_F2,   KC_F3,   KC_F4,       KC_F5,      _______,        _______,    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
                                   XXXXXXX,     _______,    _______,        _______,    _______, XXXXXXX
    ),

    [GAM] = LAYOUT_hungps(
        KC_Q,    KC_W,    KC_E,    KC_R,        KC_T,                                   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,        KC_G,                                   KC_H,    KC_J,    KC_K,    KC_L,    KC_BSLS,
        KC_Z,    KC_X,    KC_C,    KC_V,        KC_B,       _______,        _______,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SCLN,
                                   LA_NAV,      KC_SPC,     MT_LSFT_TAB,    KC_ENTER,   KC_BSPC, LA_SYM
    ),
};

const uint16_t PROGMEM qw_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM ar_combo[] = {KC_A, KC_R, COMBO_END};
const uint16_t PROGMEM zx_combo[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM xc_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM cd_combo[] = {KC_C, KC_D, COMBO_END};

combo_t key_combos[] = {
    COMBO(qw_combo, KC_ESC),
    COMBO(ar_combo, G(KC_A)),
    COMBO(zx_combo, G(KC_X)),
    COMBO(xc_combo, G(KC_C)),
    COMBO(cd_combo, G(KC_V)),
};


bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case LA_SYM:
    case LA_NAV:
        return true;
    default:
        return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    case LA_SYM:
    case LA_NAV:
    case KC_LSFT:
    case OS_SHFT:
    case OS_CTRL:
    case OS_ALT:
    case OS_CMD:
        return true;
    default:
        return false;
    }
}

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_oneshot(
        &os_shft_state, KC_LSFT, OS_SHFT,
        keycode, record
    );
    update_oneshot(
        &os_ctrl_state, KC_LCTL, OS_CTRL,
        keycode, record
    );
    update_oneshot(
        &os_alt_state, KC_LALT, OS_ALT,
        keycode, record
    );
    update_oneshot(
        &os_cmd_state, KC_LCMD, OS_CMD,
        keycode, record
    );

    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, SYM, NAV, NUM);
}
