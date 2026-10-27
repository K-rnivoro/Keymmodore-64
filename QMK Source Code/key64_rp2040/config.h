/*
Copyright 2023 K-rnivoro

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#define LAYER_STATE_16BIT


/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* define if matrix has ghost (lacks anti-ghosting diodes) */
#define MATRIX_HAS_GHOST


/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#undef LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* Define Mod-Tap behavior */
#define HOLD_ON_OTHER_KEY_PRESS


// Joystick Configuration
// Min 0, max 32
// #define JOYSTICK_BUTTON_COUNT 4
// Min 0, max 6: X, Y, Z, Rx, Ry, Rz
// #define JOYSTICK_AXIS_COUNT 4
// Min 8, max 16
// #define JOYSTICK_AXIS_RESOLUTION 8

