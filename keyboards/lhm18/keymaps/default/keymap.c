/* Copyright 2019 MelonPan
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// Tap Dance Declerations
enum {
  TD_M_D = 0,
  TD_P_M = 0
};

// Tap Dance Definition
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for minus, tap twice for divide
  [TD_M_D] = ACTION_TAP_DANCE_DOUBLE(KC_PMNS, KC_PSLS),
  //Tap once for plus, tap twice for multiplu
  [TD_P_M] = ACTION_TAP_DANCE_DOUBLE(KC_PPLS, KC_PAST)
}

// Keymap Renaming
#define ______ KC_TRNS            //Renaming for keymap readibility


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT( /* Base */

    KC_KP_7, KC_KP_8, KC_KP_9,    TD(TD_M_D),    KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC \
    KC_KP_4, KC_KP_5, KC_KP_6,    TD(TD_P_M),    CTL_T(KC_TAB), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_ENT \
    KC_KP_1, KC_KP_2, KC_KP_3,    KC_UP,         KC_LSFT,  KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_RSFT \
    KC_KP_0, KC_KP_DOT,  KC_LEFT, KC_DOWN, KC_RIGHT,  KC_GUI, KC_ALT, LT(1, KC_SPC), LT(2, KC_SPC), KC_ALT, KC_SLSH, KC_BSLS \
    
  ),

  [1] = LAYOUT( /* Layer 1 */
      ______, ______, ______,   ______,     KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL \
      ______, ______, ______,   ______,     KC_CAPS, ______, ______, ______, ______, ______, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, ______ \
      ______, ______, ______,   ______,     KC_LSFT, ______, ______, ______, ______, ______, ______, ______, KC_SCLN, KC_QUOT, KC_RSFT \
      ______, ______,   ______, ______,   ______,    ______, ______,      ______,          ______,             ______, ______, ______ \

  ),

  [2] = LAYOUT( /* Layer 2 */
      ______, ______, ______,   KC_VOLU,     KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_10, KC_F11, KC_F12 \
      ______, ______, ______,   KC_VOLD,     ______,  ______, ______, ______, ______, ______, ______, ______, ______, ______, ______ \
      ______, ______, ______,   ______,      ______,  ______, ______, ______, ______, ______, ______, ______, ______, ______, ______ \
      ______, ______,   ______, ______,   ______,    ______,  ______,      ______,          ______,      ______, ______, LCA(KC_DEL) \
  
  )
};
