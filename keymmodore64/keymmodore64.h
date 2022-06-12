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

// Pins in same order as in a tipical RGB Led
#define red_led     A0
#define common_led  A1  // Common Cathode or Anode 
#define green_led   A2
#define blue_led    A3

// Comment or uncomment one of these defines, accordingly with the type of LED being used 
#define LED_COMMON_CATHODE
//#define LED_COMMON_ANODE

#if defined(LED_COMMON_ANODE)
#define setPinCommon( led )   writePinHigh( led )  
#define setLedOn( led )       writePinLow( led )
#define setLedOff( led )      writePinHigh( led )
#endif

#if defined(LED_COMMON_CATHODE)
#define setPinCommon( led )   writePinLow( led )
#define setLedOn( led )       writePinHigh( led )
#define setLedOff( led )      writePinLow( led )
#endif

#define bmc64_p0    B4  // RPI GPIO 26
#define bmc64_p1    B5  // RPI GPIO 20
#define bmc64_p2    B6  // RPI GPIO 21

// PImmodore keyboard modes
#define BMC64_PIMMODORE_MODE_PC   0
#define BMC64_PIMMODORE_MODE_C64  1
#define BMC64_PIMMODORE_MODE_C128 2
#define BMC64_PIMMODORE_MODE_PETB 3
#define BMC64_PIMMODORE_MODE_PETG 4


#define LAYOUT( \
  K_LARR, K_1, K_2, K_3, K_4, K_5, K_6, K_7, K_8, K_9, K_0, K_PLUS, K_MINS, K_BSLS, K_HOME, K_DEL,      K_F1,   K_P7, K_P8, K_P9,       \
  K_CTRL, K_Q, K_W, K_E, K_R, K_T, K_Y, K_U, K_I, K_O, K_P, K_AT, K_ASTR, K_UP, K_RSTR,                 K_F3,   K_P4, K_P5, K_P6,       \
  K_RSTOP, K_A, K_S, K_D, K_F, K_G, K_H, K_J, K_K, K_L, K_COLON, K_SCLN, K_EQL, K_RTRN,                 K_F5,   K_P1, K_P2, K_P3,       \
  K_CKEY, K_LSHFT, K_Z, K_X, K_C, K_V, K_B, K_N, K_M, K_COMM, K_DOT, K_SLSH, K_RSHFT, K_DOWN, K_RGHT,   K_F7,         K_P0, K_PDOT,     \
                                       K_SPACE                                                                                          \
) { \
    { K_1,    K_LARR,   K_CTRL, K_RSTOP,K_SPACE,K_CKEY, K_Q,    K_2,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO, },   \
    { K_3,    K_W,      K_A,    K_LSHFT,K_Z,    K_S,    K_E,    K_4,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO, },   \
    { K_5,    K_R,      K_D,    K_X,    K_C,    K_F,    K_T,    K_6,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO, },   \
    { K_7,    K_Y,      K_G,    K_V,    K_B,    K_H,    K_U,    K_8,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO, },   \
    { K_9,    K_I,      K_J,    K_N,    K_M,    K_K,    K_O,    K_0,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO, },   \
    { K_PLUS, K_P,      K_L,    K_COMM, K_DOT,  K_COLON,K_AT,   K_MINS, KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO, },   \
    { K_BSLS, K_ASTR,   K_SCLN, K_SLSH, K_RSHFT,K_EQL,  K_UP,   K_HOME, KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO, },   \
    { K_DEL,  K_RTRN,   K_RGHT, K_DOWN, K_F1,   K_F3,   K_F5,   K_F7,   KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO, },   \
    { KC_NO,  KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  K_RSTR, KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO, },   \
    { KC_NO,  KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  K_P0,   K_P8,   K_P2,   K_P4,   K_P6,   KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO, },   \
    { KC_NO,  KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  K_PDOT, K_P7,   K_P3,   K_P1,   K_P9,  }    \
}


#endif
