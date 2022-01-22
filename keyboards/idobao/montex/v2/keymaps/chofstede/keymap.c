/* Copyright 2021 NachoxMacho
*  Copyright 2022 peepeetee
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
* along with this program.  If not, see &lt;http://www.gnu.org/licenses/&gt;.
*/

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┌───┬───┬───┬───┐
     * │ ` │Esc│Tab│MO1│Bsp│
     * ├───┼───┼───┼───┼───┤
     * │ , │Num│ / │ * │ - │
     * ├───┼───┼───┼───┼───┤
     * │Gui│ 7 │ 8 │ 9 │   │
     * ├───┼───┼───┼───┤ + │
     * │Alt│ 4 │ 5 │ 6 │   │
     * ├───┼───┼───┼───┼───┤
     * │Shi│ 1 │ 2 │ 3 │   │
     * ├───┼───┴───┼───┤Ent│
     * │Ctr│ 0     │ . │   │
     * └───┴───────┴───┴───┘
     */
    [0] = LAYOUT_numpad_6x5(
        KC_PSCR,   KC_SCRL, KC_PAUS, MO(1),   KC_INS,
        KC_NLCK,   KC_PAST, KC_PSLS, KC_PEQL, KC_PMNS,
        _______,   KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
        _______,   KC_P4,   KC_P5,   KC_P6,
        _______,   KC_P1,   KC_P2,   KC_P3,   KC_PENT,
        _______,   KC_P0,            KC_PDOT
    ),

    /*
     * ┌───┌───┐───┬───┬───┐
     * │Rst│ ` │Tab│MO1│Bsp│
     * ├───┼───┘───┼───┼───┤
     * │ , │Num│ / │ * │ - │
     * ├───┼───┼───┼───┼───┤
     * │Gui│Hom│ ↑ │PgU│   │
     * ├───┼───┼───┼───┤ + │
     * │Alt│ ← │   │ → │   │
     * ├───┼───┼───┼───┤───┤
     * │Shi│End│ ↓ │PgD│   │
     * ├───┼───┴───┼───┤Ent│
     * │Ctr│Insert │Del│   │
     * └───┴───────┴───┘───┘
     */
    [1] = LAYOUT_numpad_6x5(
        RESET,   RGB_TOG, RGB_MOD, _______, _______,
        _______, _______, _______, _______, _______,
        RGB_SPI, RGB_HUI, RGB_SAI, RGB_VAI, _______,
        RGB_SPD, RGB_HUD, RGB_SAD, RGB_VAD,
        _______, _______, _______, _______, _______,
        _______, _______,           _______
    )

};

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {


    static uint8_t l2_functions[11] = {4, 5, 6, 15, 16, 17, 18, 20, 21, 22, 23};
    switch(get_highest_layer(layer_state)){  // special handling per layer
       case 2:  //layer one
          break;
       case 1:
	  for (uint8_t i = 0; i < sizeof(l2_functions) / sizeof(l2_functions[0]); i++) {
             RGB_MATRIX_INDICATOR_SET_COLOR(l2_functions[i], 255, 0, 0);
	  }
          break;
       default:
          break;
       break;
    }
}
