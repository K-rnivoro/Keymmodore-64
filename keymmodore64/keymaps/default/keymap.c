/* Copyright 2020 K-rnivoro (www.keymmodore.com)
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

#define ____ KC_TRNS

#define PC           0   /* PC Compatible Mode */
#define LSHFT        1   /* Left SHIFT Key */
#define RSHFT        2   /* Right SHIFT Key */
#define CKEY         3   /* Commodore Key as a Function Key (like 60% style Keyboards) */
#define C64          4   /* Commodore-64, VIC-20 Plus/4, C-16 and C116 layer. (need custom .vkm for emulators) */
#define C128         5   /* Commodore 128 Keyboard mapping. */
#define C128_RSFT    6   /* Commodore 128 Keyboard with Right Shift pressed mapping (allow to access exclusive C-128 Keys). */
#define PETBUS       7   /* Commodore PET Business Keyboard mapping (upper case letters with SHIFT key). */
#define PETBUS_C     8   /* Commodore PET Business Keyboard mapping with C= Key. Allows access to NumPad keys. */
#define PETGRAPH     9   /* Commodore PET Graphics Keyboard mapping. Allows access right legend PETSCII with SHIFT key. */
#define PETGRAPH_C   10  /* Commodore PET Graphics Keyboard mapping with C= Key. Allow access left legend PETSCII codes with C= key. */
#define CBM          11  /* Commodore Key pressed in Emulation mode. Allows to go back to PC Mode pressing CONTROL. */

/*
 These layouts are compatible with Bare Metal Commodore, Combian, VICE and CCS64 Emulators
 You need to set "Keyboard Settings" in "Positional" Layout in Emulator.
 For Plus/4, C-128 and PET you need to set as "Positional (User)" and use custom .vkm files.
*/

static int current_keyb_mode = PC; // Will reflect the Keyboard mode when BMC64 is running

//Definition of non standard keys in the C-64 Keyboard.
enum my_keycodes { // Special keycodes
    SKC_7 = SAFE_RANGE,
    SKC_ACOR,
    SKC_CCOR,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[PC] = LAYOUT(
    KC_GESC,                        KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_PLUS,    KC_MINS,    KC_BSLS,    KC_HOME,    KC_DEL,     KC_F1,          KC_P7,  KC_P8,  KC_P9,   \
    CTL_T(KC_TAB),                  KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_AT,      KC_ASTR,    KC_UP,      KC_BSPC,                KC_F3,          KC_P4,  KC_P5,  KC_P6,   \
    KC_LALT,                        KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_COLON,   KC_SCLN,    KC_EQL,     KC_ENT,                             KC_F5,          KC_P1,  KC_P2,  KC_P3,   \
    MO(CKEY),   LM(LSHFT,MOD_LSFT), KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    MO(RSHFT),  KC_DOWN,    KC_RGHT,                            KC_F7,                  KC_P0,  KC_PDOT, \
                                                                                    KC_SPC
    ),
                                                                                                                                                                                                                                                                 \
[LSHFT] = LAYOUT(
    ____,                           ____,       KC_DQUO,    ____,       ____,       ____,       KC_AMPR,    SKC_7,      ____,       KC_9,       KC_0,       KC_CIRC,    ____,       ____,       ____,       ____,       ____,           ____,   ____,   ____,    \
    ____,                           ____,       ____,       ____,       ____,       ____,       ____,       ____,       ____,       ____,       ____,       ____,       ____,       ____,       ____,                   ____,           ____,   KC_P5,  ____,    \
    ____,                           ____,       ____,       ____,       ____,       ____,       ____,       ____,       ____,       ____,       SKC_ACOR,   SKC_CCOR,   ____,       ____,                               ____,           ____,   ____,   ____,    \
    KC_NO,      ____,               ____,       ____,       ____,       ____,       ____,       ____,       ____,       ____,       ____,       ____,       ____,       ____,       ____,                               ____,                   ____,   ____,    \
                                                                                    ____
    ),
                                                                                                                                                                                                                                                                 \
[RSHFT] = LAYOUT(
    KC_TILD,                        KC_EXLM,    KC_DQUO,    KC_HASH,    KC_DLR,     KC_PERC,    KC_AMPR,    KC_QUOT,    KC_LPRN,    KC_RPRN,    KC_CIRC,    ____,       KC_UNDS,    KC_PIPE,    S(KC_HOME), S(KC_DEL),  KC_F2,          ____,   ____,   ____,    \
    ____,                           S(KC_Q),    S(KC_W),    S(KC_E),    S(KC_R),    S(KC_T),    S(KC_Y),    S(KC_U),    S(KC_I),    S(KC_O),    S(KC_P),    ____,       ____,       S(KC_UP),   S(KC_BSPC),             KC_F4,          ____,   KC_P5,  ____,    \
    ____,                           S(KC_A),    S(KC_S),    S(KC_D),    S(KC_F),    S(KC_G),    S(KC_H),    S(KC_J),    S(KC_K),    S(KC_L),    KC_LBRC,    KC_RBRC,    ____,       S(KC_ENT),                          KC_F6,          ____,   ____,   ____,    \
    KC_NO,      ____,               S(KC_Z),    S(KC_X),    S(KC_C),    S(KC_V),    S(KC_B),    S(KC_N),    S(KC_M),    KC_LABK,    KC_RABK,    KC_QUES,    ____,       KC_UP,      KC_LEFT,                            KC_F8,                  ____,   ____,    \
                                                                                    S(KC_SPC)
    ),
                                                                                                                                                                                                                                                                 \
[CKEY] = LAYOUT(
    KC_GRV,                         KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,     ____,       KC_END,     KC_INS,     TO(C64),        ____,   ____,   ____,    \
    KC_LCTRL,                       KC_PGUP,    KC_UP,      KC_PGDN,    ____,       ____,       ____,       KC_PGUP,    KC_UP,      KC_PGDN,    KC_PSCR,    KC_SLCK,    KC_NLCK,    KC_PGUP,    KC_PGDN,                TO(C128),       ____,   KC_P5,  ____,    \
    ____,                           KC_LEFT,    KC_DOWN,    KC_RGHT,    ____,       ____,       ____,       KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_LCBR,    KC_RCBR,    ____,       ____,                               TO(PETGRAPH),   ____,   ____,   ____,    \
    ____,       ____,               ____,       ____,       KC_CALC,    ____,       ____,       ____,       ____,       KC_VOLD,    KC_VOLU,    KC_MUTE,    ____,       KC_UP,      KC_LEFT,                            ____,                   ____,   ____,    \
                                                                                    ____
    ),
                                                                                                                                                                                                                                                                 \
[C64] = LAYOUT(
    KC_GRV,                         KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,    KC_EQL,     KC_INS,     KC_HOME,    KC_BSPC,    KC_F1,          ____,   ____,   ____,    \
    KC_TAB,                         KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_LBRC,    KC_RBRC,    KC_DEL,     KC_PGUP,                KC_F3,          ____,   KC_P5,  ____,    \
    KC_ESC,                         KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,    KC_BSLS,    KC_ENT,                             KC_F5,          ____,   ____,   ____,    \
    LM(CBM,MOD_LCTL),   KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_RSFT,    KC_DOWN,    KC_RGHT,                            KC_F7,                  ____,   ____,    \
                                                                                    KC_SPC
    ),
                                                                                                                                                                                                                                                                 \
[C128] = LAYOUT(
    KC_GRV,                         KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,    KC_EQL,     KC_INS,     KC_HOME,    KC_BSPC,    KC_F1,          ____,   ____,   ____,    \
    KC_TAB,                         KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_LBRC,    KC_RBRC,    KC_DEL,     KC_PGUP,                KC_F3,          ____,   KC_P5,  ____,    \
    KC_ESC,                         KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,    KC_BSLS,    KC_ENT,                             KC_F5,          ____,   ____,   ____,    \
    LM(CBM,MOD_LCTL),   KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    MO(C128_RSFT),KC_DOWN,  KC_RGHT,                            KC_F7,                  ____,   ____,    \
                                                                                    KC_SPC
    ),
                                                                                                                                                                                                                                                                 \
[C128_RSFT] = LAYOUT(
    KC_PAST,                        KC_P1,      KC_P2,      KC_P3,      KC_P4,      KC_P5,      KC_P6,      KC_P7,      KC_P8,      KC_P9,      KC_P0,      KC_PPLS,    KC_PMNS,    S(KC_INS),  S(KC_HOME), S(KC_BSPC), KC_F2,          ____,   ____,   ____,    \
    KC_F11,                         S(KC_Q),    S(KC_W),    S(KC_E),    S(KC_R),    S(KC_T),    S(KC_Y),    S(KC_U),    S(KC_I),    S(KC_O),    S(KC_P),    KC_LCBR,    KC_RCBR,    KC_F10,     S(KC_PGUP),             KC_F4,          ____,   KC_P5,  ____,    \
    KC_F9,                          S(KC_A),    S(KC_S),    S(KC_D),    S(KC_F),    S(KC_G),    S(KC_H),    S(KC_J),    S(KC_K),    S(KC_L),    KC_COLON,   KC_DQUO,    KC_PIPE,    KC_PENT,                            KC_F6,          ____,   ____,   ____,    \
    ____,               ____,       S(KC_Z),    S(KC_X),    S(KC_C),    S(KC_V),    S(KC_B),    S(KC_N),    S(KC_M),    KC_LABK,    KC_PDOT,    KC_QUES,    ____,       KC_UP,      KC_LEFT,                            KC_PSLS,                ____,   ____,    \
                                                                                    S(KC_SPC)
    ),
                                                                                                                                                                                                                                                                 \
[PETGRAPH] = LAYOUT(
    KC_GRV,                         KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,    KC_EQL,     KC_TAB,     KC_HOME,    KC_BSPC,    KC_NO,          ____,   ____,   ____,    \
    KC_INS,                         KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_LBRC,    KC_RBRC,    KC_DEL,     KC_BSPC,                KC_NO,          ____,   KC_P5,  ____,    \
    KC_ESC,                         KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,    KC_BSLS,    KC_ENT,                             KC_NO,          ____,   ____,   ____,    \
    MO(PETGRAPH_C),     KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_RSFT,    KC_DOWN,    KC_RGHT,                            KC_NO,                  ____,   ____,    \
                                                                                    KC_SPC
),
                                                                                                                                                                                                                                                                 \
[PETGRAPH_C] = LAYOUT(
    ____,                           KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_UP,      KC_LEFT,    KC_F9,      ____,       S(KC_F6),   S(KC_PAST), S(KC_LEFT), ____,       ____,       ____,           ____,   ____,   ____,    \
    TO(PC),                         S(KC_F10),  S(KC_3),    S(KC_1),    S(KC_2),    S(KC_F3),   S(KC_7),    S(KC_8),    S(KC_F2),   S(KC_9),    KC_QUES,    S(KC_F4),   KC_TILD,    S(KC_DEL),  ____,                   ____,           ____,   KC_P5,  ____,    \
    ____,                           S(KC_0),    KC_RABK,    KC_LABK,    KC_DQUO,    S(KC_F5),   S(KC_4),    S(KC_5),    S(KC_F1),   S(KC_6),    KC_PMNS,    KC_PPLS,    ____,       ____,                               TO(PETBUS),     ____,   ____,   ____,    \
    ____,               ____,       S(KC_F11),  KC_PIPE,    S(KC_PGUP), S(KC_PGDN), S(KC_PSLS), KC_LALT,    S(KC_UP),   KC_PGUP,    KC_PGDN,    KC_PSLS,    ____,       ____,       ____,                               C(KC_F7),               ____,   ____,    \
                                                                                    ____
),
                                                                                                                                                                                                                                                                 \
[PETBUS] = LAYOUT(
    KC_GRV,                         KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,    KC_EQL,     KC_INS,     KC_HOME,    KC_BSPC,    KC_F1,          ____,   ____,   ____,    \
    KC_TAB,                         KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_LBRC,    KC_RBRC,    KC_DEL,     KC_BSPC,                KC_F3,          ____,   KC_P5,  ____,    \
    KC_ESC,                         KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,    KC_BSLS,    KC_ENT,                             KC_F5,          ____,   ____,   ____,    \
    MO(PETBUS_C),       KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_RSFT,    KC_DOWN,    KC_RGHT,                            KC_F7,                  ____,   ____,    \
                                                                                    KC_SPC
),
                                                                                                                                                                                                                                                                 \
[PETBUS_C] = LAYOUT(
    KC_NO,                          KC_P1,      KC_P2,      KC_P3,      KC_P4,      KC_P5,      KC_P6,      KC_P7,      KC_P8,      KC_P9,      KC_P0,      KC_NO,      KC_NO,      KC_NO,      ____,       KC_NO,      KC_NO,          ____,   ____,   ____,    \
    TO(PC),                         KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      ____,                   KC_NO,          ____,   KC_P5,  ____,    \
    KC_NO,                          KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_F10,     KC_F11,     KC_NO,      KC_NO,                              KC_NO,          ____,   ____,   ____,    \
    ____,               ____,       KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_PDOT,    KC_NO,      ____,       KC_NO,      KC_NO,                              C(KC_F7),               ____,   ____,    \
                                                                                    ____
),
                                                                                                                                                                                                                                                                 \
[CBM] = LAYOUT(
    ____,                           ____,       ____,       ____,       ____,       ____,       ____,       ____,       ____,       ____,       ____,       ____,       ____,       ____,       ____,       ____,       ____,           ____,   ____,   ____,    \
    TO(PC),                         ____,       ____,       ____,       ____,       ____,       ____,       ____,       ____,       ____,       ____,       ____,       ____,       ____,       ____,                   ____,           ____,   KC_P5,  ____,    \
    ____,                           ____,       ____,       ____,       ____,       ____,       ____,       ____,       ____,       ____,       ____,       ____,       ____,       ____,                               ____,           ____,   ____,   ____,    \
    ____,               ____,       ____,       ____,       ____,       ____,       ____,       ____,       ____,       ____,       ____,       ____,       ____,       ____,       ____,                               ____,                   ____,   ____,    \
                                                                                    ____
)
                                                                                                                                                                                                                                                                 \
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SKC_7:
            if (record->event.pressed) {
                unregister_code(KC_LSFT);
                register_code(KC_QUOT);
                register_code(KC_LSFT);
            } else {
                unregister_code(KC_QUOT);
            }
            return false;

        case SKC_ACOR:
            if (record->event.pressed) {
                unregister_code(KC_LSFT);
                register_code(KC_LBRC);
                register_code(KC_LSFT);
            } else {
                unregister_code(KC_LBRC);
            }
            return false;

        case SKC_CCOR:
            if (record->event.pressed) {
                unregister_code(KC_LSFT);
                register_code(KC_RBRC);
                register_code(KC_LSFT);
            } else {
                unregister_code(KC_RBRC);
            }
            return false;
    }
    return true;
}

void keyboard_pre_init_user(void) {
    
    setPinOutput(red_led);
    setPinOutput(green_led);
    setPinOutput(blue_led);
    setPinOutput(common_led);
    
    setLedOff(red_led);
    setLedOn(green_led);
    setLedOff(blue_led);
    setPinCommon(common_led);

    setPinInputHigh(bmc64_p0);
    setPinInputHigh(bmc64_p1);
    setPinInputHigh(bmc64_p2);

}


layer_state_t layer_state_set_user(layer_state_t state) {
//Inverted Logic so PinLow is LED On and PinHigh is LED Off.
switch (get_highest_layer(state)) {
case PC:
    setLedOff(red_led);
    setLedOn(green_led);
    setLedOff(blue_led);
    break;
case RSHFT:
    setLedOff(red_led);
    setLedOn(green_led);
    setLedOn(blue_led);
    break;
case CKEY:
    setLedOn(red_led);
    setLedOn(green_led);
    setLedOn(blue_led);
    break;
case C64:
    setLedOn(red_led);
    setLedOff(green_led);
    setLedOff(blue_led);
    break;
case C128:
    setLedOff(red_led);
    setLedOff(green_led);
    setLedOn(blue_led);
    break;
case C128_RSFT:
    setLedOff(red_led);
    setLedOn(green_led);
    setLedOn(blue_led);
    break;
case PETGRAPH:
    setLedOn(red_led);
    setLedOn(green_led);
    setLedOff(blue_led);
    break;
case PETGRAPH_C:
    setLedOn(red_led);
    setLedOn(green_led);
    setLedOn(blue_led);
    break;
case PETBUS:
    setLedOn(red_led);
    setLedOff(green_led);
    setLedOn(blue_led);
    break;
case PETBUS_C:
    setLedOn(red_led);
    setLedOn(green_led);
    setLedOn(blue_led);
    break;
case CBM:
    setLedOn(red_led);
    setLedOn(green_led);
    setLedOn(blue_led);
    break;
}
return state;
}


void matrix_init_user(void) 
{

}

void matrix_scan_user(void) {

    // Read the machine class being executed
    int read_keyb_mode = 0;
    read_keyb_mode += readPin(bmc64_p2) << 2;
    read_keyb_mode += readPin(bmc64_p1) << 1;
    read_keyb_mode += readPin(bmc64_p0) << 0;

    // Is there a relevant change in the keyboard mode?
    if ( current_keyb_mode != read_keyb_mode ) {

        current_keyb_mode = read_keyb_mode;      
        layer_clear();
  
        switch (current_keyb_mode) {
            case BMC64_PIMMODORE_MODE_C64: // C64; VIC20; Plus 4
                layer_move(C64);
                break;

            case BMC64_PIMMODORE_MODE_C128: // Commodore 128
                layer_move(C128);
                break;
            
            case BMC64_PIMMODORE_MODE_PETB:  // PET Business
                layer_move(PETBUS);
                break;

            case BMC64_PIMMODORE_MODE_PETG:  // PET Graph
                layer_move(PETGRAPH);
                break;

            default:
                layer_move(PC);
        }
    }

}
 
