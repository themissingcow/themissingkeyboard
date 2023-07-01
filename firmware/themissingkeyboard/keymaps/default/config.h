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

#pragma once

#define MASTER_LEFT

#define TAPPING_TERM 125
#define TAPPING_TERM_PER_KEY

#ifdef RGBLIGHT_ENABLE
#define RGBLIGHT_LAYERS
#define RGBLIGHT_LAYERS_RETAIN_VAL
#define RGB_DEFAULT_MODE RGBLIGHT_MODE_STATIC_LIGHT
#define RGBLIGHT_DEFAULT_HUE 0
#define RGBLIGHT_DEFAULT_SAT 0
#define RGBLIGHT_DEFAULT_VAL 64
#endif

// RGB matrix
#ifdef RGB_MATRIX_ENABLE
#define RGB_MATRIX_KEYPRESSES
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define ENABLE_RGB_MATRIX_TYPING_HEATMAP
#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_TYPING_HEATMAP
#endif

// Tri-layer numbers
#define TRI_LAYER_LOWER_LAYER 2
#define TRI_LAYER_UPPER_LAYER 3
#define TRI_LAYER_ADJUST_LAYER 4


