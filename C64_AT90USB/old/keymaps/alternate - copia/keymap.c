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
#include "Commodore64.h"
#include "action_layer.h"
#define ____ KC_TRNS

#define PC        0   /* PC Compatible Mode */
#define LSHFT     1   /* Left SHIFT Key */
#define RSHFT     2   /* Right SHIFT Key  */
#define CKEY      3   /* Commodore Key */
#define RSHFTCKEY 4   /* Right SHIFT Key and (after) Commodore Key */
#define C64       5   /* Bare Metal Commodore 64, VICE or CCS64 Emulators. Remember to set "Keyboard Settings" in Default Positional Layout for VICE */


#define MODS_SHIFT_MASK  (MOD_BIT(KC_LCTRL)|MOD_BIT(KC_RSHIFT))
//static uint16_t key_timer;

//Enable next line for one (blinking) LED only. Disable for RGB LED. See "void matrix_scan_user" below
//static bool enable_led = false;

//Definition of non standard keys in the C-64 Keyboard	
enum my_keycodes {
	TECLA_7 = SAFE_RANGE,
	TECLA_ACOR,
    TECLA_CCOR,
};

  
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 // PC Mode (Default Layer)
[PC] = KEYMAP(
        KC_1,    KC_GESC,             CTL_T(KC_TAB), KC_LALT,           KC_SPC,            MO(CKEY),            KC_Q,    KC_2,                                                           \
        KC_3,    KC_W,                KC_A,          LM(LSHFT,MOD_LSFT),KC_Z,              KC_S,                KC_E,    KC_4,                                                           \
        KC_5,    KC_R,                KC_D,          KC_X,              KC_C,              KC_F,                KC_T,    KC_6,                                                           \
		KC_7,    KC_Y,                KC_G,          KC_V,              KC_B,              KC_H,                KC_U,    KC_8,                                                           \
		KC_9,    KC_I,                KC_J,          KC_N,              KC_M,              KC_K,                KC_O,    KC_0,                                                           \
		KC_PLUS, KC_P,                KC_L,          KC_COMM,           KC_DOT,            KC_COLON,            KC_AT,   KC_MINS,                                                        \
		KC_BSLS, KC_ASTR,             KC_SCLN,       KC_SLSH,           MO(RSHFT),         KC_EQL,              KC_UP,   KC_HOME,                                                        \
		KC_DEL,  KC_ENT,              KC_RGHT,       KC_DOWN,           KC_F1,             KC_F3,               KC_F5,   KC_F7,                                                          \
		                                                                                                                          KC_BSPC,                                               \
																					                                                      KC_NO,                                         \
																					                                                            KC_P0,   KC_P8, KC_P2, KC_P4, KC_P6,     \
																										                                        KC_PDOT, KC_P7, KC_P3, KC_P1, KC_P9),	

// PC Mode with Left SHIFT Key Pressed 
[LSHFT] = KEYMAP(
        ____,    ____,                ____,          ____,              ____,              ____,                ____,    KC_DQUO,                                                        \
        ____,    ____,                ____,          ____,              ____,              ____,                ____,    ____,                                                           \
        ____,    ____,                ____,          ____,              ____,              ____,                ____,    KC_AMPR,                                                        \
		TECLA_7, ____,                ____,          ____,              ____,              ____,                ____,    KC_LPRN,                                                        \
		KC_RPRN, ____,                ____,          ____,              ____,              ____,                ____,    KC_CIRC,                                                        \
		____,    ____,                ____,          ____,              ____,              TECLA_ACOR,          ____,    KC_UNDS,                                                        \
		____,    ____,                TECLA_CCOR,    ____,              ____,              ____,                ____,    ____,                                                           \
		____,    ____,                ____,          ____,              ____,              ____,                ____,    ____,                                                           \
                                                                                                                                  ____,                                                  \
																														                  KC_NO,                                         \
																					                                                            ____,    ____,  ____,  ____,  ____,      \
																										                                        ____,    ____,  ____,  ____,  ____),	
                
// PC Mode with Right SHIFT Key Pressed 
[RSHFT] = KEYMAP(
        KC_EXLM, KC_GRV,              S(KC_TAB),     ____,              S(KC_SPC),         LM(RSHFTCKEY,MOD_LGUI),   S(KC_Q), KC_DQUO,                               \
        KC_HASH, S(KC_W),             S(KC_A),       ____,              S(KC_Z),           S(KC_S),                  S(KC_E), KC_DLR,                                \
        KC_PERC, S(KC_R),             S(KC_D),       S(KC_X),           S(KC_C),           S(KC_F),                  S(KC_T), KC_AMPR,                               \
		KC_QUOT, S(KC_Y),             S(KC_G),       S(KC_V),           S(KC_B),           S(KC_H),                  S(KC_U), KC_LPRN,                               \
		KC_RPRN, S(KC_I),             S(KC_J),       S(KC_N),           S(KC_M),           S(KC_K),                  S(KC_O), KC_CIRC,                               \
		____,    S(KC_P),             S(KC_L),       KC_LABK,           KC_RABK,           KC_LBRC,                  ____,    KC_UNDS,                               \
	    KC_PIPE, ____,                KC_RBRC,       KC_QUES,           ____,              KC_EQL,                   KC_PGUP, KC_END,                                \
		KC_INS,  S(KC_ENT),           KC_LEFT,       KC_UP,             KC_F2,             KC_F4,                    KC_F6,   KC_F8,                                 \
                                                                                                                                      KC_PGDN,                       \
																														                        KC_NO,               \
																					                                                      S(KC_P0),  S(KC_P8), S(KC_P2), S(KC_P4), S(KC_P6),  \
																										                                  S(KC_PDOT),S(KC_P7), S(KC_P3), S(KC_P1), S(KC_P9)),	
	                                                          
// PC Mode with Commodore Key (C=) pressed 
[CKEY] = KEYMAP(
        ____,    ____,                ____,          ____,              ____,              ____,       ____,    ____,                                                           \
        ____,    ____,                ____,          ____,              ____,              ____,       ____,    ____,                                                           \
        ____,    ____,                ____,          ____,              KC_CALC,           ____,       ____,    ____,                                                           \
		____,    ____,                ____,          ____,              ____,              ____,       ____,    ____,                                                           \
		____,    ____,                ____,          ____,              ____,              ____,       ____,    ____,                                                           \
		____,    KC_PSCR,             ____,          KC_VOLD,           KC_VOLU,           KC_LCBR,    ____,    ____,                                                           \
		____,    ____,                KC_RCBR,       KC_MUTE,           ____,              ____,       ____,    ____,                                                           \
		____,    ____,                ____,          ____,              KC_F9,             KC_F10,     KC_F11,  KC_F12,                                                         \
                                                                                                                         ____,                                                  \
																														           TO(C64),                                     \
																					                                                      ____,    ____,  ____,  ____,  ____,   \
																										                                  ____,    ____,  ____,  ____,  ____),	
// PC Mode with Right SHIFT Key and (after) Commodore Key Pressed 
[RSHFTCKEY] = KEYMAP(
        KC_1,    KC_GRV,              CTL_T(KC_TAB), KC_LALT,           KC_SPC,            ____,                KC_Q,    KC_2,                                                            \
        KC_3,    KC_W,                KC_A,          KC_LSFT,           KC_Z,              KC_S,                KC_E,    KC_4,                                                           \
        KC_5,    KC_R,                KC_D,          KC_X,              KC_C,              KC_F,                KC_T,    KC_6,                                                           \
		KC_7,    KC_Y,                KC_G,          KC_V,              KC_B,              KC_H,                KC_U,    KC_8,                                                           \
		KC_9,    KC_I,                KC_J,          KC_N,              KC_M,              KC_K,                KC_O,    KC_0,                                                           \
		KC_PLUS, KC_P,                KC_L,          KC_COMM,           KC_DOT,            KC_COLON,            KC_AT,   KC_MINS,                                                        \
		KC_BSLS, KC_ASTR,             KC_SCLN,       KC_SLSH,           KC_RSFT,           KC_EQL,              KC_UP,   KC_HOME,                                                        \
		KC_DEL,  KC_ENT,              KC_RGHT,       KC_DOWN,           KC_F1,             KC_F3,               KC_F5,   KC_F7,                                                          \
		                                                                                                                          KC_BSPC,                                               \
																					                                                      KC_NO,                                         \
																					                                                            KC_P0,   KC_P8, KC_P2, KC_P4, KC_P6,     \
																										                                        KC_PDOT, KC_P7, KC_P3, KC_P1, KC_P9),	

																														  
// Commodore-64 Emulator Mode: BMC64, VICE (Using Positional layout) or CCS64
[C64] = KEYMAP(
        KC_1,     KC_GRV,             KC_TAB,       KC_ESC,             KC_SPC,            KC_LCTL,             KC_Q,    KC_2,                                                           \
        KC_3,     KC_W,               KC_A,         KC_LSFT,            KC_Z,              KC_S,                KC_E,    KC_4,                                                           \
        KC_5,     KC_R,               KC_D,         KC_X,               KC_C,              KC_F,                KC_T,    KC_6,                                                           \
		KC_7,     KC_Y,               KC_G,         KC_V,               KC_B,              KC_H,                KC_U,    KC_8,                                                           \
		KC_9,     KC_I,               KC_J,         KC_N,               KC_M,              KC_K,                KC_O,    KC_0,                                                           \
		KC_MINS,  KC_P,               KC_L,         KC_COMM,            KC_DOT,            KC_SCLN,             KC_LBRC, KC_EQL,                                                         \
		KC_INS,   KC_RBRC,            KC_QUOT,      KC_SLSH,            KC_RSFT,           KC_BSLS,             KC_DEL,  KC_HOME,                                                        \
		KC_BSPC,  KC_ENT,             KC_RGHT,      KC_DOWN,            KC_F1,             KC_F3,               KC_F5,   KC_F7,                                                          \
                                                                                                                                 KC_PGUP,                                                \
													                                                                                      TO(PC),                                        \
                                                                                                                                               KC_P0,  KC_P8,  KC_P2,  KC_P4, KC_P6,	 \
                                                                                                                                               KC_PDOT,  KC_P7,  KC_P3,  KC_P1,  KC_P9),	                                  

};						
  
  

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
 
 switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};





int lshift = 0;
bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
	switch (keycode)
	{		
case TECLA_7:
		   if (record->event.pressed)
		   {
		   unregister_code(KC_LSFT);
		   register_code(KC_QUOT);
		   register_code(KC_LSFT);
		   }
		   else
		   {
		   unregister_code(KC_QUOT);
		   }		   
		return false;	 

case TECLA_ACOR:
	 if (record->event.pressed)
		{
	     unregister_code(KC_LSFT);
		 register_code(KC_LBRC);
		 register_code(KC_LSFT);
	    }
	  else
	    {
		unregister_code(KC_LBRC);
        }
		return false;
	  
	
case TECLA_CCOR:
	     if (record->event.pressed)
		{
	     unregister_code(KC_LSFT);
		 register_code(KC_RBRC);
		 register_code(KC_LSFT);
	    }
	  else
	    {
		unregister_code(KC_RBRC);
        }
		return false;
	}
	return true; 
}	 

void matrix_init_user(void) 
{
	// For Arduino use the following line:
	//DDRB |= (1 << 1) | (1 << 2) | (1 << 3);
	// For Teensy 2++ use the following line:
	DDRB |= (1 << 4) | (1 << 5) | (1 << 6);
	
	red_mode_led_off();
	green_mode_led_off();
	blue_mode_led_off();
	//key_timer = timer_read();
}

void matrix_scan_user(void)
{
	uint8_t layer = biton32(layer_state);
	red_mode_led_off();
	green_mode_led_off();
	blue_mode_led_off();

	
// One (blinking) LED only Option. (Originally red although some C64 had green LED). 	
/*
switch (layer) {
        case PC:
            // PC Mode -> LED Always on.
         c64_power_led_on();
            break;
        case VICE:
            // Emulator Mode -> LED BLinking slow
        if (timer_elapsed(key_timer) > 500)
           {
            key_timer = timer_read();
            enable_led = !enable_led;
           }
        enable_led ? c64_power_led_on() : c64_power_led_off();
            break;
		case RST:
            // Right Shift pressed Mode -> LED BLinking Fast
            if (timer_elapsed(key_timer) > 200)
           {
            key_timer = timer_read();
            enable_led = !enable_led;
           }
        enable_led ? c64_power_led_on() : c64_power_led_off();
			break;
        case RSLG:
            // Right Shift & Left GUI Pressed Mode -> LED Blinking Faster
           	if (timer_elapsed(key_timer) > 100)
           {
            key_timer = timer_read();
            enable_led = !enable_led;
           }
        enable_led ? c64_power_led_on() : c64_power_led_off();
			break;
        default:
            // none
			break;
                }             	
             
*/


// RGB LED Option	


switch (layer) {
        case PC:
            // PC Compatible Layout Mode
            green_mode_led_on();
            break;
        case CKEY:
            // Commodore Key pressed
			blue_mode_led_on();
			break;
		case LSHFT:
            // Left Shift key pressed
            green_mode_led_on();
			blue_mode_led_on();
            break;
        case RSHFT:
            // Right Shift pressed
           	green_mode_led_on();
			red_mode_led_on();
            break;
	    case RSHFTCKEY:
            // Right Shift and Commodore Key pressed
           	red_mode_led_on();
			green_mode_led_on();
			red_mode_led_on();
            break;
        case C64:
            // C64 emulator Mode
           	red_mode_led_on();
        	break;     
		default:
   			break;
              }

			  
}


//Set Num_Lock On in order to joysticks work properly as numpad keys mapping. (Not sure if required but just in case)
void led_set_keymap(uint8_t usb_led) {
  if (!(usb_led & (1<<USB_LED_NUM_LOCK))) {
    register_code(KC_NUMLOCK);
    unregister_code(KC_NUMLOCK);
  }
}

void led_set_user(uint8_t usb_led) {

}

