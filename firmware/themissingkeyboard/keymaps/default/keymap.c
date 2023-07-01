/*
 * Copyright 2022 GEIST @geigeigeist
 * Copyright 2023 Tom Cowland
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
#include <stdio.h>
#include <string.h>
#include "themissingkeyboard.h"

#include "bit-c_led.h"


enum themissingkeyboard_layers {
    _QWERTY,
    _COLEMAK,
    _LOWER,
    _UPPER,
    _ADJUST,
};

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
	COLEMAK,
};


// Mods on keys

#define CTL_ESC MT(MOD_LCTL, KC_ESC)
#define SFT_TAB MT(OSM(MOD_LSFT), KC_TAB)
#define GUI_SPC MT(OSM(MOD_LGUI), KC_SPC)
#define GUI_GRV MT(OSM(MOD_LGUI), KC_GRV)

//
// Home row mods
//

// qwerty

#define CTL_A LCTL_T(KC_A)
#define GUI_S LGUI_T(KC_S)
#define ALT_D LALT_T(KC_D)
#define SFT_F LSFT_T(KC_F)

#define SFT_J   RSFT_T(KC_J)
#define ALT_K   RALT_T(KC_K)
#define GUI_L   RGUI_T(KC_L)
#define CTL_QUO RCTL_T(KC_QUOT)


// colemak

#define GUI_R LGUI_T(KC_R)
#define ALT_S LALT_T(KC_S)
#define SHFT_T LSFT_T(KC_T)

#define SFT_N RSFT_T(KC_N)
#define ALT_E RALT_T(KC_E)
#define GUI_I RGUI_T(KC_I)
#define CTL_O RCTL_T(KC_O)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 /*
  * QWERTY
  *
             ┌─────────┬─────────┬─────────┬─────────┬─────────┐                    ┌─────────┬─────────┬─────────┬─────────┬─────────┐
             │    Q    │    W    │    E    │    R    │    T    │                    │    Y    │    U    │    I    │    O    │    P    │
   ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                    ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
   │ GUI/ESC │    A    │    S    │    D    │    F    │    G    │                    │    H    │    J    │    K    │    L    │    '    │    \    │
   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                    ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
   │ SHIF/TA │    Z    │    X    │    C    │    V    │    B    │                    │    N    │    M    │    ,    │    .    │    ;    │    /    │
   └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┼─────────┐┌─────────┼─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                 │    `    │   SPC   │ RAISE   │ BKSP    ││  LOWER  │    -    │  enter  │    3    │
                                 └─────────┴─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┴─────────┘
   */

   [_QWERTY] = LAYOUT(
              KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                          KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,
    CTL_ESC,  CTL_A,    GUI_S,    ALT_D,    SFT_F,    KC_G,                          KC_H,     SFT_J,    ALT_K,    GUI_L,    CTL_QUO,  KC_BSLS,
    SFT_TAB,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,                          KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SCLN,  KC_SLSH,
                                  GUI_GRV,  KC_SPC,   TL_UPPR,  KC_BSPC,      TL_LOWR,  KC_MINS,  KC_ENT,   KC_3
 ),

/*
 * COLEMAK
 *
             ┌─────────┬─────────┬─────────┬─────────┬─────────┐                    ┌─────────┬─────────┬─────────┬─────────┬─────────┐
             │    Q    │    W    │    F    │    P    │    G    │                    │    J    │    L    │    U    │    Y    │    '    │
   ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                    ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
   │         │    A    │    R    │    S    │    T    │    D    │                    │    H    │    N    │    E    │    I    │    O    │    \    │
   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                    ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
   │         │    Z    │    X    │    C    │    V    │    B    │                    │    K    │    M    │    ,    │    .    │    ;    │    /    │
   └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┼─────────┐┌─────────┼─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                 │         │         │         │         ││         │         │         │         │
                                 └─────────┴─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┴─────────┘
 */

   [_COLEMAK] = LAYOUT(
              KC_Q,     KC_W,     KC_F,     KC_P,     KC_G,                          KC_J,     KC_L,     KC_U,     KC_Y,     KC_QUOT,
    CTL_ESC,  CTL_A,    GUI_R,    ALT_S,    SHFT_T,   KC_D,                          KC_H,     SFT_N,    ALT_E,    GUI_I,    CTL_O,    KC_BSLS,
    SFT_TAB,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,                          KC_K,     KC_M,     KC_COMM,  KC_DOT,   KC_SCLN,  KC_SLSH,
                                  GUI_GRV,  KC_SPC,   TL_UPPR,  KC_BSPC,      TL_LOWR,  KC_MINS,  KC_ENT,   KC_3
),

 /*
  * LOWER
  *
             ┌─────────┬─────────┬─────────┬─────────┬─────────┐                    ┌─────────┬─────────┬─────────┬─────────┬─────────┐
             │         │         │         │    (    │    )    │                    │    7    │    8    │    9    │    +    │         │
   ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                    ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
   │         │         │         │         │    {    │    }    │                    │    4    │    5    │    6    │    -    │    =    │         │
   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                    ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
   │         │         │         │         │    [    │    ]    │                    │    1    │    2    │    3    │         │         │         │
   └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┼─────────┐┌─────────┼─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                 │         │         │         │         ││         │         │    0    │         │
                                 └─────────┴─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┴─────────┘
  */

   [_LOWER] = LAYOUT(
              XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_LPRN,  KC_RPRN,                       KC_7,   KC_8,    KC_9,    KC_PPLS,    _______,
    _______,  KC_LCTL,  KC_LGUI,  KC_LALT,  KC_LCBR,  KC_RCBR,                       KC_4,   KC_5,    KC_6,    KC_PMNS,    KC_PEQL,  _______,
    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_LBRC,  KC_RBRC,                       KC_1,   KC_2,    KC_3,    _______,    _______,  _______,
                                  _______,  _______,  _______,  _______,   _______,  _______,   KC_0, _______
 ),

 /*
  * UPPER
  *
             ┌─────────┬─────────┬─────────┬─────────┬─────────┐                    ┌─────────┬─────────┬─────────┬─────────┬─────────┐
             │    !    │    @    │    #    │    $    │    %    │                    │    ^    │    &    │    *    │    (    │    )    │
   ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                    ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
   │         │         │         │         │         │    *    │                    │  left   │ down    │   up    │ right   │    :    │    +    │
   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                    ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
   │         │   [     │    ]    │    (    │    )    │         │                    │  home   │ pgdn    │ pgup    │ end     │         │    =    │
   └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┼─────────┐┌─────────┼─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                 │         │         │         │   DEL   ││         │    {    │    }    │         │
                                 └─────────┴─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┴─────────┘
  */

   [_UPPER] = LAYOUT(
              LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_4), LSFT(KC_5),            LSFT(KC_6), LSFT(KC_7), LSFT(KC_8), KC_LPRN, KC_RPRN,
    _______,  KC_LCTL,  KC_LGUI,  KC_LALT,  KC_LSFT,  LSFT(KC_8),                    KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT, LSFT(KC_SCLN),  KC_PLUS,
    _______,  KC_LBRC,  KC_RBRC,  KC_LPRN,  KC_RPRN,  _______,                       KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   _______,  KC_EQL,
                                  _______,  _______,  _______,  KC_DEL,    _______,  KC_LCBR,   KC_RCBR,  _______
 ),
 /*
  * ADJUST
  *
             ┌─────────┬─────────┬─────────┬─────────┬─────────┐                    ┌─────────┬─────────┬─────────┬─────────┬─────────┐
             │ QWERTY  │         │         │  ee clr │         │                    │         │         │         │ rgb vi  │         │
   ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                    ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
   │         │         │         │         │         │         │                    │         │         │         │ rgb tog │         │         │
   ├─────────┼─────────┼──────── ┼─────────┼─────────┼─────────┤                    ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
   │         │         │         │ COLEMAK │         │         │                    │         │         │         │ rgb vd  │         │         │
   └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┼─────────┐┌─────────┼─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                 │    ▼    │    ▼    │    ▼    │    ▼    ││    ▼    │    ▼    │    ▼    │    ▼    │
                                 └─────────┴─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┴─────────┘
  */

   [_ADJUST] = LAYOUT(
              QWERTY,   XXXXXXX,  XXXXXXX,  EE_CLR,   XXXXXXX,                       XXXXXXX,  XXXXXXX,  XXXXXXX,  RGB_VAI,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                       XXXXXXX,  XXXXXXX,  XXXXXXX,  RGB_TOG,  XXXXXXX,   XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  COLEMAK,  XXXXXXX,  XXXXXXX,                       XXXXXXX,  XXXXXXX,  XXXXXXX,  RGB_VAD,  XXXXXXX,   XXXXXXX,
                                  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______
 )

};


// RGBLIGHT layers

const rgblight_segment_t PROGMEM rgblight_layer_lower[] = RGBLIGHT_LAYER_SEGMENTS(
    {24, 6, HSV_GREEN}, {31, 3, HSV_GREEN}, {23, 1, HSV_GREEN},
    {6, 3, HSV_BLUE}, {3, 3, HSV_BLUE} // Brackets
);

const rgblight_segment_t PROGMEM rgblight_layer_upper[] = RGBLIGHT_LAYER_SEGMENTS(
    {25, 1, HSV_RED}, {28, 1, HSV_RED}, {32, 1, HSV_RED}, {35, 1, HSV_RED}, // arrow keys
    {15, 2, HSV_BLUE}, {10, 1, HSV_BLUE}, {8, 1, HSV_BLUE}, {4, 1, HSV_BLUE}, {22, 2, HSV_BLUE}, {34, 1, HSV_BLUE}, {39, 1, HSV_BLUE}, // Brackets
    {38, 1, HSV_GOLD} // Colon
);

const rgblight_segment_t PROGMEM rgblight_layer_adj[] = RGBLIGHT_LAYER_SEGMENTS(
    {18, 1, HSV_GOLD}, {10, 1, HSV_GOLD}, {35, 1, HSV_GOLD}
);

const rgblight_segment_t* const PROGMEM tmk_rgblight_layers[] = RGBLIGHT_LAYERS_LIST(
	rgblight_layer_lower,
    rgblight_layer_upper,
	rgblight_layer_adj
);

void keyboard_post_init_user(void) {
	rgblight_layers = tmk_rgblight_layers;
	set_bit_c_LED(LED_OFF);
}

layer_state_t layer_state_set_user(layer_state_t state) {
	const int adjust_active = layer_state_cmp(state, _ADJUST);
	rgblight_set_layer_state(2, adjust_active);
	rgblight_set_layer_state(0, layer_state_cmp(state, _LOWER) && !adjust_active);
	rgblight_set_layer_state(1, layer_state_cmp(state, _UPPER) && !adjust_active);
    return state;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
		case SFT_F:
        case SFT_J:
            return TAPPING_TERM;
        default:
            return TAPPING_TERM + 150;
    }
}

// Custom Keycode handling

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
    }
    return true;
}
