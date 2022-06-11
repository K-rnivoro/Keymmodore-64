/* Copyright 2020 K-rnivoro
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
#ifndef KEYMMODORE64_H
#define KEYMMODORE64_H

#include "quantum.h"
#include "led.h"


/* 
Option RGB LED (Replacement of original C-64 Power LED):
  Use a common anode RGB LED, so is ACTIVE LOW (inverted logic)
  Only  with Arduino Leonardo and Teensy 2.0
  - PC Mode: LED Green
  - Any SHIFT pressed (in PC Mode):  LED Cyan (Green+Blue)
  - Commodore Key (C=) pressed (in PC Mode): LED Yellow (Green+Red)
  - Commodore-64 Emulator Mode: LED Red
  - Commodore-16 and Plus/4  Emulator Mode: LED Blue
  - Commodore PET Emulator Mode: LED Purple (Blue+Red) 


Option TX and RX LEDs of Leonardo and ProMicro boards:
  (RGB LED not available in ProMicro due to not having enough pins) 
  Catode connected to chip, so is ACTIVE LOW (inverted logic)
  - PC Mode: Rx On, Tx Off.
  - Any SHIFT pressed (in PC Mode): Rx Off, Tx Off.
  - Commodore Key Pressed (in PC Mode): Rx On, Tx On.
  - Any Emulator Mode: Rx Off, Tx On.
*/

#define green_led B6
#define red_led B5
#define blue_led B4
 

#define LAYOUT( \
    K00, K01, K02, K03, K04, K05, K06, K07,                                                             \
    K10, K11, K12, K13, K14, K15, K16, K17,                                                             \
    K20, K21, K22, K23, K24, K25, K26, K27,                                                             \
    K30, K31, K32, K33, K34, K35, K36, K37,                                                             \
    K40, K41, K42, K43, K44, K45, K46, K47,                                                             \
    K50, K51, K52, K53, K54, K55, K56, K57,                                                             \
    K60, K61, K62, K63, K64, K65, K66, K67,                                                             \
    K70, K71, K72, K73, K74, K75, K76, K77,                                                             \
                                            K80,                                                        \
												 K90, K91, K92, K93, K94,                               \
                                                                          KA0, KA1, KA2, KA3, KA4       \
) { \
    { K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, },   \
    { K10,   K11,   K12,   K13,   K14,   K15,   K16,   K17,   KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, },   \
    { K20,   K21,   K22,   K23,   K24,   K25,   K26,   K27,   KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, },   \
    { K30,   K31,   K32,   K33,   K34,   K35,   K36,   K37,   KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, },   \
    { K40,   K41,   K42,   K43,   K44,   K45,   K46,   K47,   KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, },   \
    { K50,   K51,   K52,   K53,   K54,   K55,   K56,   K57,   KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, },   \
    { K60,   K61,   K62,   K63,   K64,   K65,   K66,   K67,   KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, },   \
    { K70,   K71,   K72,   K73,   K74,   K75,   K76,   K77,   KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, },   \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, K80,   KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, },   \
	{ KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, K90,   K91,   K92,    K93,   K94,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, },   \
	{ KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO,  KA0,   KA1,   KA2,   KA3,   KA4,   }    \
}
#endif
