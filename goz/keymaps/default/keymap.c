// Copyright 2024 Sertan Canpolat (@scnplt)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Layers
enum layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _FN,
    _MOUSE
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define DEL_FN LT(_FN, KC_DEL)
#define MOUSE TG(_MOUSE)

// Tap - Hold
#define TAB_SFT SFT_T(KC_TAB)
#define QUOT_SFT RSFT_T(KC_QUOT)
#define MEH_SLSH MEH_T(KC_SLSH)

// Combos
const uint16_t PROGMEM c_undo_combo[] = {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM c_redo_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM c_lgui_combo[] = {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM c_rgui_combo[] = {KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM c_chis_combo[] = {KC_F, KC_V, COMBO_END};

combo_t key_combos[] = {
    COMBO(c_undo_combo, C(KC_Z)),
    COMBO(c_redo_combo, C(S(KC_Z))),
    COMBO(c_lgui_combo, KC_LGUI),
    COMBO(c_rgui_combo, KC_RGUI),
    COMBO(c_chis_combo, G(KC_V)),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_split_3x6_3(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                           KC_Y,     KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        TAB_SFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                           KC_H,     KC_J,    KC_K,    KC_L,    KC_SCLN, QUOT_SFT,
        KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                           KC_N,     KC_M,    KC_COMM, KC_DOT,  MEH_SLSH,KC_BSLS,
                                            KC_LALT, LOWER,   KC_SPC,        KC_ENT, RAISE,    DEL_FN
    ),

    [_LOWER] = LAYOUT_split_3x6_3(
        XXXXXXX, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                         KC_CIRC, KC_AMPR, KC_ASTR, KC_PMNS, KC_EQL,  KC_TILD,
        XXXXXXX, XXXXXXX, XXXXXXX, KC_LCBR, KC_LBRC, KC_LPRN,                         XXXXXXX, XXXXXXX, XXXXXXX, KC_UNDS, KC_PLUS, KC_GRV,
        KC_CAPS, XXXXXXX, XXXXXXX, KC_RCBR, KC_RBRC, KC_RPRN,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                            XXXXXXX, _______, XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX            
    ),

    [_RAISE] = LAYOUT_split_3x6_3(
        XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX,
        KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, KC_RSFT,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX, XXXXXXX,
                                            KC_LALT, XXXXXXX, KC_SPC,        XXXXXXX, _______, XXXXXXX            
    ),

    [_FN] = LAYOUT_split_3x6_3(
        XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                           KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  MOUSE,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F11,  KC_F12,                          KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, XXXXXXX, XXXXXXX,
        QK_BOOT, QK_RBT,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         KC_MPLY, KC_MUTE, KC_PSCR, XXXXXXX, XXXXXXX, XXXXXXX,
                                            KC_LALT, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, _______            
    ),

    [_MOUSE] = LAYOUT_split_3x6_3(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         KC_WH_U, KC_WH_L, KC_MS_U, KC_WH_R, XXXXXXX, MOUSE,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                            XXXXXXX, XXXXXXX, XXXXXXX,       KC_BTN1, KC_BTN3, KC_BTN2            
    )
};