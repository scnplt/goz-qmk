// Copyright 2024 Sertan Canpolat (@scnplt)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
      [0] = LAYOUT_split_3x6_3(
            QK_GESC, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
            KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                            KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
            KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                            KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
                                                KC_LALT, MO(2),   KC_SPC,        KC_ENT,  MO(1),   LT(3, KC_DEL)        
      ),

      [1] = LAYOUT_split_3x6_3(
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY, KC_MUTE,
            KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, KC_RSFT,
            KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX, XXXXXXX,
                                                _______, KC_LGUI, XXXXXXX,       XXXXXXX, _______, XXXXXXX            
      ),

      [2] = LAYOUT_split_3x6_3(
            KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX,
            KC_LSFT, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                         KC_CIRC, KC_AMPR, KC_ASTR, KC_PMNS, KC_EQL,  KC_RSFT,
            XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC,                         KC_LPRN, KC_RPRN, XXXXXXX, KC_UNDS, KC_PLUS, XXXXXXX,
                                                _______, _______, XXXXXXX,       XXXXXXX, XXXXXXX, KC_RALT            
      ),

      [3] = LAYOUT_split_3x6_3(
            XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                           KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  XXXXXXX,
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F11,  KC_F12,                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         XXXXXXX, KC_PSCR, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
                                                _______, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, _______            
      )
};