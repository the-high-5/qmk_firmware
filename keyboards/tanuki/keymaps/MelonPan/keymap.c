#include QMK_KEYBOARD_H

// custom type to store stuff in EEPROM
typedef union {
    uint32_t raw;
    struct {
        bool layer_rgb :1;
    };
} user_config_t;

user_config_t user_config;

// Layer definitions
#define _L0 0
#define _L1 1
#define _L2 2
#define _L3 3


// Custom keycode to toggle normal RGB or per-layer RGB
enum custom_keycodes {
    CUSTRGB = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Base layer (0)
     * ,------------------------------------------------------------------------.
     * | Esc |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  | Bksp |
     * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+------|
     * |  Cnt |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  cm  | Ent |
     * `------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----'
     *   | Shift |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,	 |  .  |Shift |
     *   `-------+-----+-----+-----+-----+-----+-----+-----+-----+-----+------'
     *        | GUI | LAlt |MO 2 |   MO 1     |  SpaceUp  | /   | MO3 |
     *        `--------------------------------------------------------'
     */


[_L0] = LAYOUT(
    KC_ESC,            KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,     KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
    LCTL_T(KC_TAB),    KC_A,     KC_S,     KC_D,    KC_F,    KC_G,     KC_H,   KC_J,    KC_K,    KC_L,    KC_QUOT, KC_ENT, \
    KC_LSFT,           KC_Z,     KC_X,     KC_C,    KC_V,    KC_B,     KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_LSFT, \
    KC_LGUI,           KC_LALT,  MO(_L2),  MO(_L1),                    KC_SPC, KC_SLSH, KC_SCLN),


    /* LAYER 1
	 * arrows and numbers
     * ,------------------------------------------------------------------------.
     * |     |     |     | UP  |     |     |  7  |  8  |  9  |  /  |  *  | DEL  |
     * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+------|
     * | CAPS |     | LFT | DWN | RHT |     |  4  |  5  |  6  |  -  |     | ENT |
     * `------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----'
     *   |       |     |     |     |     |     |  1  |  2  |  3	 |  +  |      |
     *   `-------+-----+-----+-----+-----+-----+-----+-----+-----+-----+------'
     *        |      | ALT |     |            |     0     |  .  | LCTL |
     *        `--------------------------------------------------------'
     */

[_L1] = LAYOUT(
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_UP,    KC_TRNS,   KC_TRNS,  KC_P7,   KC_P8,   KC_P9,    KC_PSLS,  KC_PAST,  KC_DEL,\
    KC_CAPS,  KC_TRNS,  KC_LEFT,  KC_DOWN,  KC_RIGHT,  KC_TRNS,  KC_P4,   KC_P5,   KC_P6,    KC_PMNS,  KC_TRNS,  KC_ENT,\
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_P1,   KC_P2,   KC_P3,    KC_PPLS,  KC_TRNS,\
    KC_TRNS,  KC_LALT,  KC_TRNS,  KC_TRNS,                       KC_P0,   KC_PDOT, KC_LCTL),


    	/* LAYER 2
	 * F-Row and symbols
     * ,------------------------------------------------------------------------.
     * | F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10  | F11 | F12 |
     * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+------|
     * |  !   |  @  |  #  |  $  |  %  |  ^  |  &  |  *  |  (  |  )  | -_  | =+  |
     * `------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----'
     *   | LSHFT |     |     |     |     |     |     |  ~  |  [	 |  ]  | LSHFT|
     *   `-------+-----+-----+-----+-----+-----+-----+-----+-----+-----+------'
     *        |      |     |     |     MO(3)     |           |     |      |
     *        `--------------------------------------------------------'
     */
	 
[_L2] = LAYOUT(
    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,  KC_F12,\
    KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_MINS, KC_EQL, \
    KC_LSFT,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_GRV,   KC_LBRC,   KC_RBRC,  KC_LSFT, \
    KC_TRNS,  KC_TRNS,  KC_TRNS,  MO(_L3),                      KC_TRNS,  KC_TRNS,  KC_TRNS),


    /* LAYER 3
	 * RGB CONTROL
     * ,------------------------------------------------------------------------.
     * |CRGB |     |     |     |     |     |     |     | VAI | VAD | SPI | SPD  |
     * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+------|
     * |      |     |     |     |     |     |     |     | HUI | HUD | SAI | SAD |
     * `------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----'
     *   |       |     |     |     |     |     |     |     |RGB+ | RGB- | RGBt |
     *   `-------+-----+-----+-----+-----+-----+-----+-----+-----+-----+------'
     *        |      |     |     |            |           |     |      |
     *        `--------------------------------------------------------'
     */

[_L3] = LAYOUT(
    CUSTRGB,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  RGB_VAI,  RGB_VAD,  RGB_SPI,    RGB_SPD, \
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  RGB_HUI,  RGB_HUD,  RGB_SAI,  RGB_SAD, \
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  RGB_MOD,  RGB_RMOD, RGB_TOG,  \
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                      KC_TRNS,  KC_TRNS,  KC_TRNS),
  
};

void keyboard_post_init_user(void) {
    user_config.raw = eeconfig_read_user();
    if(user_config.layer_rgb) {
        rgblight_enable_noeeprom();
        rgblight_mode_noeeprom(1);
        rgblight_sethsv_noeeprom(0,10,255);
    }
}

uint32_t layer_state_set_user(uint32_t state) {
    // This code switches underglow color by active layer, if the user has enabled the feature
    if(user_config.layer_rgb) {
        switch (biton32(state)) {
            case _L0:
                rgblight_sethsv_noeeprom(0,10,255);
                rgblight_mode_noeeprom(1);
                break;
            case _L1:
                rgblight_sethsv_noeeprom(130,200,255);
                rgblight_mode_noeeprom(1);
                break;
            case _L2:
                rgblight_sethsv_noeeprom(170,200,255);
                rgblight_mode_noeeprom(1);
                break;
            case _L3:
                rgblight_sethsv_noeeprom(0,180,255);
                rgblight_mode_noeeprom(1);
                break;
        }
    }
    return state;
}

bool process_record_user (uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CUSTRGB: // if the user toggled per-layer RGB, update the config and refresh the RGB color
            if(record->event.pressed) {
                user_config.layer_rgb ^= 1;
                eeconfig_update_user(user_config.raw);
                if (user_config.layer_rgb) {
                    layer_state_set(layer_state);
                }
            }
            return false;
            break;
        case RGB_MOD:
        case RGB_SAD:
        case RGB_SAI:
        case RGB_HUI:
        case RGB_VAD:
        case RGB_VAI:
            if(user_config.layer_rgb && record->event.pressed) {
                return false; // if layer RGB is on, ignore attempts to change RGB settings
            }
            break;
    }
    return true;
}

void eeconfig_init_user(void) { // in case EEPROM is reset, set up our custom config
    user_config.raw = 0;
    user_config.layer_rgb = true; // enable per-layer RGB by default
    eeconfig_update_user(user_config.raw);
    rgblight_enable();
    rgblight_sethsv(0,10,255);
    rgblight_mode(1);
}
