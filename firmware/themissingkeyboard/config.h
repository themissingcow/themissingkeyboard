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
// Key matrix configuration

#define DIODE_DIRECTION COL2ROW
#define MATRIX_ROW_PINS { C6, D7, E6, B4 }
#define MATRIX_COL_PINS { F6, F7, B1, B3, B2, B6 }
#define MATRIX_ROWS 8  // Split doubles rows
#define MATRIX_COLS 6
#define DEBOUNCE 5

// Split comms

#define USE_SERIAL
#define SOFT_SERIAL_PIN D2
#define SERIAL_USE_MULTI_TRANSACTION
#define SPLIT_TRANSPORT_MIRROR

// Key LEDs (RGB)

#define WS2812_DI_PIN D3
#define RGB_DISABLE_WHEN_USB_SUSPENDED

#ifdef RGBLIGHT_ENABLE
#define RGBLIGHT_SLEEP
#define RGBLIGHT_SPLIT
#define DRIVER_LED_TOTAL 42
#define RGBLED_NUM 42
#define RGBLED_SPLIT { 21, 21 }
#endif

#ifdef RGB_MATRIX_ENABLE
#define RGB_MATRIX_LED_COUNT 42
#define RGB_MATRIX_SPLIT { 21, 21 }
#endif
