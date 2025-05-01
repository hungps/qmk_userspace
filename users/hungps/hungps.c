#include QMK_KEYBOARD_H

#include "layers.h"

#define SPACE_L C(KC_LEFT)
#define SPACE_R C(KC_RGHT)
#define SPTLGHT G(KC_SPC)
#define LT_NAV_ESC LT(NAV, KC_ESC)
#define LT_NUM_SPC LT(NUM, KC_SPC)
#define LT_SYM_BSPC LT(SYM, KC_BSPC)
#define LT_SYS_DEL LT(SYS, KC_DEL)
#define RECORD G(S(KC_5))
#define PRNSCR G(S(KC_4))

#define HOME_A LCTL_T(KC_A)
#define HOME_R LALT_T(KC_R)
#define HOME_S LGUI_T(KC_S)
#define HOME_T LSFT_T(KC_T)
#define HYPR_G HYPR_T(KC_G)
#define MEH_V MEH_T(KC_V)

#define HOME_N RSFT_T(KC_N)
#define HOME_E RGUI_T(KC_E)
#define HOME_I RALT_T(KC_I)
#define HOME_O RCTL_T(KC_O)
#define HYPR_M HYPR_T(KC_M)
#define MEH_K MEH_T(KC_K)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [DEF] = LAYOUT_split_3x5_3(
        KC_Q,    KC_W,    KC_F,    KC_P,        KC_B,                                   KC_J,       KC_L,      KC_U,    KC_Y,    KC_QUOT,
        HOME_A,  HOME_R,  HOME_S,  HOME_T,      HYPR_G,                                 HYPR_M,     HOME_N,    HOME_E,  HOME_I,  HOME_O,
        KC_Z,    KC_X,    KC_C,    KC_D,        MEH_V,                                  MEH_K,      KC_H,      KC_COMM, KC_DOT,  KC_SLSH,
                                   LT_NAV_ESC,  LT_NUM_SPC, KC_TAB,         KC_ENTER,   LT_SYM_BSPC,LT_SYS_DEL
    ),

    [NAV] = LAYOUT_split_3x5_3(
        PRNSCR,  RECORD,  KC_VOLD, KC_VOLU,     KC_MUTE,                                MS_WHLL,    MS_WHLD, MS_WHLU, MS_WHLR, KC_LPAD,
        KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT,     XXXXXXX,                                KC_LEFT,    KC_DOWN, KC_UP,   KC_RGHT, KC_MCTL,
        SPACE_L, SPACE_R, KC_MPRV, KC_MNXT,     KC_MPLY,                                MS_LEFT,    MS_DOWN, MS_UP,   MS_RGHT, SPTLGHT,
                                   XXXXXXX,     _______,    _______,        MS_BTN1,    MS_BTN2,    MS_BTN3
    ),

    [NUM] = LAYOUT_split_3x5_3(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX,                                KC_PLUS,    KC_7,    KC_8,    KC_9,    KC_ASTR,
        KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT,     XXXXXXX,                                KC_MINS,    KC_4,    KC_5,    KC_6,    KC_SLSH,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX,                                KC_COMM,    KC_1,    KC_2,    KC_3,    KC_PERC,
                                   _______,     XXXXXXX,    _______,        KC_PEQL,    KC_DOT,     KC_0
    ),

    [SYM] = LAYOUT_split_3x5_3(
        KC_LABK, KC_LCBR, KC_LBRC, KC_LPRN,     KC_CIRC,                                KC_DLR,     KC_RPRN, KC_RBRC, KC_RCBR, KC_RABK,
        KC_AMPR, KC_PIPE, KC_EXLM, KC_QUES,     KC_COLN,                                KC_TILD,    KC_RSFT, KC_RGUI, KC_RALT, KC_RCTL,
        KC_PLUS, KC_MINS, KC_ASTR, KC_SLSH,     KC_PERC,                                KC_GRV,     KC_UNDS, KC_AT,   KC_HASH, KC_BSLS,
                                   _______,     _______,    _______,        _______,    XXXXXXX,    _______
    ),

    [SYS] = LAYOUT_split_3x5_3(
        KC_SLEP, RM_SATU, RM_VALU, RM_NEXT,     RM_TOGG,                                XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, RM_HUEU, RM_SPDU, XXXXXXX,     XXXXXXX,                                XXXXXXX,    KC_RSFT, KC_RGUI, KC_RALT, KC_RCTL,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX,                                XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                   _______,     _______,    _______,        _______,    _______,    XXXXXXX
    ),
};

const uint16_t PROGMEM ar_combo[] = {KC_A, KC_R, COMBO_END};
const uint16_t PROGMEM zx_combo[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM xc_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM cd_combo[] = {KC_C, KC_D, COMBO_END};
const uint16_t PROGMEM xd_combo[] = {KC_X, KC_D, COMBO_END};

combo_t key_combos[] = {
    COMBO(ar_combo, G(KC_A)),
    COMBO(zx_combo, G(KC_Z)),
    COMBO(xc_combo, G(KC_C)),
    COMBO(cd_combo, G(KC_V)),
    COMBO(xd_combo, G(KC_X)),
};


const key_override_t rm_next_key_override = ko_make_basic(MOD_MASK_SHIFT, RM_NEXT, RM_PREV);
const key_override_t rm_hueu_key_override = ko_make_basic(MOD_MASK_SHIFT, RM_HUEU, RM_HUED);
const key_override_t rm_satu_key_override = ko_make_basic(MOD_MASK_SHIFT, RM_SATU, RM_SATD);
const key_override_t rm_valu_key_override = ko_make_basic(MOD_MASK_SHIFT, RM_VALU, RM_VALD);
const key_override_t rm_spdu_key_override = ko_make_basic(MOD_MASK_SHIFT, RM_SPDU, RM_SPDD);

const key_override_t *key_overrides[] = {
    &rm_next_key_override,
    &rm_hueu_key_override,
    &rm_satu_key_override,
    &rm_valu_key_override,
    &rm_spdu_key_override
};
