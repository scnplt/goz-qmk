// Copyright 2024 Sertan Canpolat (@scnplt)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Layers
enum layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _FN
};

#define MEH_LOWER LT(_LOWER, KC_F20)
#define GUI_RAISE LT(_RAISE, KC_F21)
#define DEL_FN LT(_FN, KC_DEL)

// Tap-hold
#define TAB_SFT LSFT_T(KC_TAB)
#define QUOT_SFT RSFT_T(KC_QUOT)

// Tap-dance
enum tapdance {
      TD_CPS_CTL
};

tap_dance_action_t tap_dance_actions[] = {
      [TD_CPS_CTL] = ACTION_TAP_DANCE_DOUBLE(KC_LCTL, KC_CAPS),
};

#define CPS_CTL TD(TD_CPS_CTL)

// Combos
const uint16_t PROGMEM c_undo_combo[] = {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM c_redo_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM c_clph_combo[] = {KC_F, KC_V, COMBO_END};

combo_t key_combos[] = {
      COMBO(c_undo_combo, LCTL(KC_Z)),
      COMBO(c_redo_combo, LCTL(LSFT(KC_Z))),
      COMBO(c_clph_combo, LGUI(KC_V)),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
      [_QWERTY] = LAYOUT_split_3x6_3(
            QK_GESC, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
            TAB_SFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                            KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, QUOT_SFT,
            CPS_CTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                            KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
                                                KC_LALT, GUI_RAISE,KC_SPC,       KC_ENT, MEH_LOWER,DEL_FN        
      ),

      [_LOWER] = LAYOUT_split_3x6_3(
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY, KC_MUTE,
            KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, KC_RSFT,
            KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX, XXXXXXX,
                                                _______, KC_LGUI, XXXXXXX,       XXXXXXX, _______, XXXXXXX            
      ),

      [_RAISE] = LAYOUT_split_3x6_3(
            KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX,
            KC_LSFT, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                         KC_CIRC, KC_AMPR, KC_ASTR, KC_PMNS, KC_EQL,  KC_RSFT,
            XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC,                         KC_LPRN, KC_RPRN, XXXXXXX, KC_UNDS, KC_PLUS, XXXXXXX,
                                                _______, _______, XXXXXXX,       XXXXXXX, XXXXXXX, KC_RALT            
      ),

      [_FN] = LAYOUT_split_3x6_3(
            XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                           KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  XXXXXXX,
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F11,  KC_F12,                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         XXXXXXX, KC_PSCR, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
                                                _______, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, _______            
      )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
      switch (keycode) {
            case MEH_LOWER:
                  if (record->tap.count > 0) {
                        if (record->event.pressed) { set_oneshot_mods(MOD_MEH); }
                        return false;
                  }
                  break;
            case GUI_RAISE:
                  if (record->tap.count > 0) {
                        if (record->event.pressed) { set_oneshot_mods(MOD_LGUI); }
                        return false;
                  }
                  break;
      }
      return true;
}
