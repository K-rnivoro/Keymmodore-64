/* Copyright 2023 K-rnivoro
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
#include "quantum.h"

#define ____ KC_TRNS


/*
RGB LED (Replacement of original C-64 Power LED) showing current layout:
 
  - PC Mode: LED Green
  - Any SHIFT pressed (in PC Mode):  LED Cyan (Green+Blue)
  - Commodore Key (C=) pressed (in PC Mode): LED Yellow (Green+Red)
  - Commodore-64 Emulator Mode: LED Red
  - Commodore-16 and Plus/4  Emulator Mode: LED Blue
  - Commodore PET Emulator Mode: LED Purple (Blue+Red) 
  - Spectrum Emulator: LED Yellow.
*/
//R-Pi Pico PCB LED as Power LED
#define power_led GP25

//R-Pi Pico GPIO Output for RGB LED
#define red_led GP28
#define green_led GP27
#define blue_led GP26

//#define red_led GP18
//#define green_led GP19
//#define blue_led GP20

//Flags from BMC64 emulator running on Raspberry Pi 3B or 3B+ to auto-change Keyboard Layout
#define bmc64_p0    GP19 // Connected to Rarpberry Pi 3B GPIO 9
#define bmc64_p1    GP20 // Connected to Rarpberry Pi 3B GPIO 10
#define bmc64_p2    GP18 // Connected to Rarpberry Pi 3B GPIO 11

//#define bmc64_p0    GP26 // Connected to Rarpberry Pi 3B GPIO 9
//#define bmc64_p1    GP27 // Connected to Rarpberry Pi 3B GPIO 10
//#define bmc64_p2    GP28 // Connected to Rarpberry Pi 3B GPIO 11


                                                                                  

// Comment or uncomment one of these defines, accordingly with the type of RGB LED being used: Common Anode or Common Cathode 
//#define LED_COMMON_CATHODE
#define LED_COMMON_ANODE

#if defined(LED_COMMON_ANODE)
#define setLedOn( led )       writePinLow( led )
#define setLedOff( led )      writePinHigh( led )
#endif

#if defined(LED_COMMON_CATHODE)
#define setLedOn( led )       writePinHigh( led )
#define setLedOff( led )      writePinLow( led )
#endif



// Pimmodore keyboard modes

#define BMC64_PIMMODORE_MODE_PC   0
#define BMC64_PIMMODORE_MODE_C64  1
#define BMC64_PIMMODORE_MODE_C128 2
#define BMC64_PIMMODORE_MODE_PETB 3
#define BMC64_PIMMODORE_MODE_PETG 4 

 
#define LAYOUT( \
	k00, k01, k02, k03, k04, k05, k06, k07, 	\
    k10, k11, k12, k13, k14, k15, k16, k17,     \
    k20, k21, k22, k23, k24, k25, k26, k27, 	\
    k30, k31, k32, k33, k34, k35, k36, k37, k38,\
    k40, k41, k42, k43, k44, k45, k46, k47, k48,\
    k50, k51, k52, k53, k54, k55, k56, k57, k58,\
    k60, k61, k62, k63, k64, k65, k66, k67, k68,\
    k70, k71, k72, k73, k74, k75, k76, k77, k78,\
    k80, k81, k82, k83, k84,                k88	\
) { \
    { k00,   k01,   k02,   k03,   k04,   k05,   k06,   k07,   KC_NO }, \
    { k10,   k11,   k12,   k13,   k14,   k15,   k16,   k17,   KC_NO }, \
    { k20,   k21,   k22,   k23,   k24,   k25,   k26,   k27,   KC_NO }, \
    { k30,   k31,   k32,   k33,   k34,   k35,   k36,   k37,   k38   }, \
    { k40,   k41,   k42,   k43,   k44,   k45,   k46,   k47,   k48   }, \
    { k50,   k51,   k52,   k53,   k54,   k55,   k56,   k57,   k58   }, \
    { k60,   k61,   k62,   k63,   k64,   k65,   k66,   k67,   k68   }, \
    { k70,   k71,   k72,   k73,   k74,   k75,   k76,   k77,   k78   }, \
    { k80,   k81,   k82,   k83,   k84,   KC_NO, KC_NO, KC_NO, k88   }  \
}
