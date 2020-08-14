/* Copyright 2019 K-rnivoro
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
#ifndef COMMODORE64_H
#define COMMODORE64_H

#include "quantum.h"
#include "led.h"

/* RGB LED (Replacement of original Power LED.
 * Different Layouts and Modes will be indicated by colors of the RGB LED.   
 * Using a common anode RGB LED so is ACTIVE LOW (inverted logic)
  */
#define green_led B6
#define red_led B5
#define blue_led B4

/*
inline void green_mode_led_on(void)      { PORTB &= ~(1<<6); }
inline void red_mode_led_on(void)    	 { PORTB &= ~(1<<5); }
inline void blue_mode_led_on(void)    	 { PORTB &= ~(1<<4); }

inline void green_mode_led_off(void)     { PORTB |= (1<<6); }
inline void red_mode_led_off(void)       { PORTB |= (1<<5); }
inline void blue_mode_led_off(void)   	 { PORTB |= (1<<4); }
*/


#define KEYMAP( \
    K00, K01, K02, K03, K04, K05, K06, K07,                                                             \
    K10, K11, K12, K13, K14, K15, K16, K17,                                                             \
    K20, K21, K22, K23, K24, K25, K26, K27,                                                             \
    K30, K31, K32, K33, K34, K35, K36, K37,                                                             \
    K40, K41, K42, K43, K44, K45, K46, K47,                                                             \
    K50, K51, K52, K53, K54, K55, K56, K57,                                                             \
    K60, K61, K62, K63, K64, K65, K66, K67,                                                             \
    K70, K71, K72, K73, K74, K75, K76, K77,                                                             \
                                            K88,                                                        \
                                                 K99,                                                   \
	                                                  KAA, KAB, KAC, KAD, KAE,                          \
                                                                               KBA, KBB, KBC, KBD, KBE  \
) { \
    { K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO },   \
    { K10,   K11,   K12,   K13,   K14,   K15,   K16,   K17,   KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO },   \
    { K20,   K21,   K22,   K23,   K24,   K25,   K26,   K27,   KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO },   \
    { K30,   K31,   K32,   K33,   K34,   K35,   K36,   K37,   KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO },   \
    { K40,   K41,   K42,   K43,   K44,   K45,   K46,   K47,   KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO },   \
    { K50,   K51,   K52,   K53,   K54,   K55,   K56,   K57,   KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO },   \
    { K60,   K61,   K62,   K63,   K64,   K65,   K66,   K67,   KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO },   \
    { K70,   K71,   K72,   K73,   K74,   K75,   K76,   K77,   KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO },   \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, K88,   KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO },   \
	{ KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, K99,   KC_NO, KC_NO,  KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO },   \
	{ KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KAA,   KAB,    KAC,   KAD,    KAE,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO },   \
	{ KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO,  KC_NO, KBA,   KBB,   KBC,   KBD,   KBE   }    \
}

#endif
