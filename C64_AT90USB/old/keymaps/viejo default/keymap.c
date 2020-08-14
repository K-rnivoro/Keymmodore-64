/* Copyright 2018 K-rnivoro
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


#define PC 0   /* PC Compatible Mode */
#define VICE 1 /* VICE and CCS64 Emulators Default Positional Layout */
#define RST  2 /* Right SHIFT Key (actually a Layer for the non PC standard C-64 Keycaps) */
#define RSLG 3 /* Right SHIFT + LGUI (Commodore Logo Key as LGUI) */
#define MODS_SHIFT_MASK  (MOD_BIT(KC_LCTRL)|MOD_BIT(KC_RSHIFT))
static uint16_t key_timer;

//Enable next line for one (blinking) LED only. Disable for RGB LED. See "void matrix_scan_user" below
static bool enable_led = false;

//Definition of non standard keys in the C-64 Keyboard	
enum my_keycodes {
	TECLA_2 = SAFE_RANGE,
	TECLA_6,
	TECLA_7, 
	TECLA_8,
	TECLA_9,
	TECLA_0,
	TECLA_ACOR,
    TECLA_CCOR,
};

/* The following is a way to switch modes without a physical button. Enable TAPPING_TERM in config.h and rules.mk
   Works keeping C= and RSHIFT keys pressed, and tapping F1 key twice.
   In the [VICE] KEYMAP replace KC_F1 for TD(TO_VICE)
   In the [RSLG] KEYMAP replace KC_F9 for TD(TO_PC)
   (Look at the KEYMAPs of the No-Joystick Option)
*/

/*
// Definition in KEYMAP for the TAP Dance for switching modes by keyboard macro (instead of physical button)
enum {
  TO_VICE = 5,
  TO_PC = 6
};

//Tap F9 twice (RSHIFT + C= + F1) for Change Mode to Emulator Mode
void cambia_vice_fin (qk_tap_dance_state_t *state, void *user_data) {
 	if (state->count == 1)
	{
      register_code (KC_F9);
	}
	else
	{
	  layer_on(VICE); 
    }
}
  
void cambia_vice_reset (qk_tap_dance_state_t *state, void *user_data) {
	if (state->count == 1)
	{
    unregister_code (KC_F9);
	}
}	

//Tap (RSHIFT + C= + F1) twice for Change Mode back to PC
void cambia_pc_fin (qk_tap_dance_state_t *state, void *user_data) {
 	if (state->count == 1)
	{
    register_code (KC_F1);
	}
	else
	{
  if  (get_mods() & MODS_SHIFT_MASK) {
	  layer_off(VICE);
	  unregister_code(KC_RSHIFT);
	  unregister_code(KC_LCTRL);
      }
	}
}	
  
void cambia_pc_reset (qk_tap_dance_state_t *state, void *user_data) {
	
	if (state->count == 1)
	{
    unregister_code (KC_F1);
	}
}	

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [TO_VICE]  = ACTION_TAP_DANCE_FN_ADVANCED (NULL, cambia_vice_fin, cambia_vice_reset)
 ,[TO_PC]  = ACTION_TAP_DANCE_FN_ADVANCED (NULL, cambia_pc_fin, cambia_pc_reset)
  };
  
*/
  
// Enable this for two Joysticks Option and button only mode switch (using Teensy 2++)
 
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 // PC Mode (Default Layer)
[PC] = KEYMAP(
        KC_1,    KC_ESC,   CTL_T(KC_TAB), KC_LALT, KC_SPC,  KC_LGUI,    KC_Q,    TECLA_2,                                                                                                 \
        KC_3,    KC_W,     KC_A,          KC_LSFT, KC_Z,    KC_S,       KC_E,    KC_4,                                                                                                    \
        KC_5,    KC_R,     KC_D,          KC_X,    KC_C,    KC_F,       KC_T,    TECLA_6,                                                                                                 \
		TECLA_7, KC_Y,     KC_G,          KC_V,    KC_B,    KC_H,       KC_U,    TECLA_8,                                                                                                 \
		TECLA_9, KC_I,     KC_J,          KC_N,    KC_M,    KC_K,       KC_O,    TECLA_0,                                                                                                 \
		KC_PLUS, KC_P,     KC_L,          KC_COMM, KC_DOT,  TECLA_ACOR, KC_AT,   KC_MINS,                                                                                                 \
		KC_BSLS, KC_ASTR,  TECLA_CCOR,    KC_SLSH, MO(RST), KC_EQL,     KC_UP,   KC_HOME,                                                                                                 \
		KC_DEL,  KC_ENT,   KC_RGHT,       KC_DOWN, KC_F1,   KC_F3,      KC_F5,   KC_F7,                                                                                                   \
		                                                                                   KC_BSPC,                                                                                       \
																					                TO(VICE),                                                                              \
																					                            KC_P0,  KC_P8,  KC_P2,  KC_P4, KC_P6,                                     \
																										        KC_PDOT,  KC_P7,  KC_P3,  KC_P1,  KC_P9),	
// Emulator Mode. VICE (Using Positional layout) or CCS64
[VICE] = KEYMAP(
        KC_1,     KC_GRV,   KC_TAB,       KC_ESC,  KC_SPC,  KC_LCTRL,   KC_Q,    KC_2,                                   \
        KC_3,     KC_W,     KC_A,         KC_LSFT, KC_Z,    KC_S,       KC_E,    KC_4,                                   \
        KC_5,     KC_R,     KC_D,         KC_X,    KC_C,    KC_F,       KC_T,    KC_6,                                   \
		KC_7,     KC_Y,     KC_G,         KC_V,    KC_B,    KC_H,       KC_U,    KC_8,                                   \
		KC_9,     KC_I,     KC_J,         KC_N,    KC_M,    KC_K,       KC_O,    KC_0,                                   \
		KC_MINS,  KC_P,     KC_L,         KC_COMM, KC_DOT,  KC_SCLN,    KC_LBRC, KC_EQL,                                 \
		KC_LEFT,  KC_RBRC,  KC_QUOT,      KC_SLSH, KC_RSFT, KC_BSLS,    KC_DEL,  KC_HOME,                                \
		KC_BSPC,  KC_ENT,   KC_RGHT,      KC_DOWN, KC_F1,   KC_F3,      KC_F5,   KC_F7,                                  \
                                                                                           KC_PGUP,                      \
													                                                 TO(PC),            \
                                                                                                                 KC_P0,  KC_P8,  KC_P2,  KC_P4, KC_P6,	\
                                                                                                                 KC_PDOT,  KC_P7,  KC_P3,  KC_P1,  KC_P9),		                                                            
																						  
// PC Mode with Right SHIFT Key Pressed 
[RST] = KEYMAP(
        KC_EXLM,       KC_GRV,       ____,        ____,           RSFT(KC_SPC),   MO(RSLG),    RSFT(KC_Q),    KC_DQUO,                                \
        KC_HASH,       RSFT(KC_W),   RSFT(KC_A),  ____,           RSFT(KC_Z),     RSFT(KC_S),  RSFT(KC_E),    KC_DLR,                                 \
        KC_PERC,       RSFT(KC_R),   RSFT(KC_D),  RSFT(KC_X),     RSFT(KC_C),     RSFT(KC_F),  RSFT(KC_T),    KC_AMPR,                                \
		KC_QUOT,       RSFT(KC_Y),   RSFT(KC_G),  RSFT(KC_V),     RSFT(KC_B),     RSFT(KC_H),  RSFT(KC_U),    KC_LPRN,                                \
		KC_RPRN,       RSFT(KC_I),   RSFT(KC_J),  RSFT(KC_N),     RSFT(KC_M),     RSFT(KC_K),  RSFT(KC_O),    KC_CIRC,                                \
		KC_PLUS,       RSFT(KC_P),   RSFT(KC_L),  KC_LABK,        KC_RABK,        KC_LBRC,     KC_AT,         KC_UNDS,                                \
		RSFT(KC_BSLS), ____,         KC_RBRC,     RSFT(KC_SLSH),  MO(RST),        KC_EQL,      KC_PGUP,       KC_END,                                 \
		KC_INS,        RSFT(KC_ENT), KC_LEFT,     KC_UP,          KC_F2,          KC_F4,       KC_F6,         KC_F8,                                  \
                                                                                                                          KC_PGDN,                    \
																														            KC_NO,            \
																					                             RSFT(KC_P0), RSFT(KC_P8), RSFT(KC_P2), RSFT(KC_P4), RSFT(KC_P6),         \
																										         RSFT(KC_PDOT), RSFT(KC_P7), RSFT(KC_P3), RSFT(KC_P1),  RSFT(KC_P9)),	
                                  
// PC Mode with Right SHIFT and LGUI (C= Key) Keys Pressed
[RSLG] = KEYMAP(
        ____,          ____,         ____,        ____,           ____,           MO(RSLG),    ____,          ____,                                  \
		____,          ____,         ____,        ____,           ____,           ____,        ____,          ____,                                  \
        ____,          ____,         ____,        ____,           KC_CALC,        ____,        ____,          ____,                                  \
		____,          ____,         ____,        ____,           ____,           ____,        ____,          ____,                                  \
		____,          ____,         ____,        ____,           KC_MUTE,        ____,        ____,          ____,                                  \
        ____,          ____,         ____,        KC_VOLD,        KC_VOLU,        KC_LCBR,     ____,          ____,                                  \
		____,          ____,         KC_RCBR,     ____,           ____,           ____,        ____,          KC_PSCR,                               \
        ____,          ____,         ____,        ____,           KC_F9,    KC_F10,      KC_F11,        KC_F12,                                      \
                                                                                                                            ____,                    \
                                        				                                                                            KC_NO,           \
																																	____,  ____,  ____,  ____, ____,         \
																										                            ____,  ____,  ____,  ____,  ____),	
};						
  
  
// Enable this for No-Joysticks Option and soft mode switch (using Teensy 2++ or ATmega32u4).
/*

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 // PC Mode (Default Layer)
[PC] = KEYMAP(
        KC_1,    KC_ESC,   CTL_T(KC_TAB),   KC_RALT, KC_SPC,  KC_LGUI,    KC_Q,    TECLA_2,                         \
        KC_3,    KC_W,     KC_A,            KC_LSFT, KC_Z,    KC_S,       KC_E,    KC_4,                            \
        KC_5,    KC_R,     KC_D,            KC_X,    KC_C,    KC_F,       KC_T,    TECLA_6,                         \
		TECLA_7, KC_Y,     KC_G,            KC_V,    KC_B,    KC_H,       KC_U,    TECLA_8,                         \
		TECLA_9, KC_I,     KC_J,            KC_N,    KC_M,    KC_K,       KC_O,    TECLA_0,                         \
		KC_PLUS, KC_P,     KC_L,            KC_COMM, KC_DOT,  TECLA_ACOR, KC_AT,   KC_MINS,                         \
		KC_BSLS, KC_ASTR,  TECLA_CCOR,      KC_SLSH, MO(RST), KC_EQL,     KC_UP,   KC_HOME,                         \
		KC_DEL,  KC_ENT,   KC_RGHT,         KC_DOWN, KC_F1,   KC_F3,      KC_F5,   KC_F7,                           \
		                                                                                     KC_BSPC,               \
																							          TD(TO_VICE)),
// Emulator Mode. VICE (Using Positional layout) or CCS64
[VICE] = KEYMAP(
        KC_1,    KC_GRV,   KC_TAB,  KC_ESC,  KC_SPC,     KC_LCTRL, KC_Q,    KC_2,                                   \
        KC_3,    KC_W,     KC_A,    KC_LSFT, KC_Z,       KC_S,     KC_E,    KC_4,                                   \
        KC_5,    KC_R,     KC_D,    KC_X,    KC_C,       KC_F,     KC_T,    KC_6,                                   \
		KC_7,    KC_Y,     KC_G,    KC_V,    KC_B,       KC_H,     KC_U,    KC_8,                                   \
		KC_9,    KC_I,     KC_J,    KC_N,    KC_M,       KC_K,     KC_O,    KC_0,                                   \
		KC_MINS, KC_P,     KC_L,    KC_COMM, KC_DOT,     KC_SCLN,  KC_LBRC, KC_EQL,                                 \
		KC_INS,  KC_RBRC,  KC_QUOT, KC_SLSH, KC_RSFT,    KC_BSLS,  KC_DEL,  KC_HOME,                                \
		KC_BSPC, KC_ENT,   KC_RGHT, KC_DOWN, TD(TO_PC),  KC_F3,    KC_F5,   KC_F7,                                  \
                                                                                             KC_PGUP,               \
													                                                  TD(TO_PC)),
// PC Mode with Right SHIFT Key Pressed 
[RST] = KEYMAP(
        KC_EXLM,       KC_GRV,      CTL_T(KC_TAB), KC_RALT,       RSFT(KC_SPC),   MO(RSLG),    RSFT(KC_Q),    KC_DQUO,                                \
        KC_HASH,       RSFT(KC_W),   RSFT(KC_A),  ____,           RSFT(KC_Z),     RSFT(KC_S),  RSFT(KC_E),    KC_DLR,                                 \
        KC_PERC,       RSFT(KC_R),   RSFT(KC_D),  RSFT(KC_X),     RSFT(KC_C),     RSFT(KC_F),  RSFT(KC_T),    KC_AMPR,                                \
		KC_QUOT,       RSFT(KC_Y),   RSFT(KC_G),  RSFT(KC_V),     RSFT(KC_B),     RSFT(KC_H),  RSFT(KC_U),    KC_LPRN,                                \
		KC_RPRN,       RSFT(KC_I),   RSFT(KC_J),  RSFT(KC_N),     RSFT(KC_M),     RSFT(KC_K),  RSFT(KC_O),    KC_CIRC,                                \
		KC_PLUS,       RSFT(KC_P),   RSFT(KC_L),  KC_LABK,        KC_RABK,        KC_LBRC,     KC_AT,         KC_UNDS,                                \
		RSFT(KC_BSLS), KC_ASTR,      KC_RBRC,     RSFT(KC_SLSH),  MO(RST),        KC_EQL,      KC_PGUP,       KC_END,                                 \
		KC_INS,        KC_ENT,       KC_LEFT,     KC_UP,          KC_F2,          KC_F4,       KC_F6,         KC_F8,                                  \
                                                                                                                          KC_PGDN,                    \
																														             KC_NO),
// PC Mode with Right SHIFT and LGUI (C= Key) Keys Pressed
[RSLG] = KEYMAP(
        ____,          ____,         ____,        ____,           ____,           MO(RSLG),    ____,          ____,                                  \
		____,          ____,         ____,        ____,           ____,           ____,        ____,          ____,                                  \
        ____,          ____,         ____,        ____,           KC_CALC,        ____,        ____,          ____,                                  \
		____,          ____,         ____,        ____,           ____,           ____,        ____,          ____,                                  \
		____,          ____,         ____,        ____,           KC_MUTE,        ____,        ____,          ____,                                  \
        ____,          ____,         ____,        KC_VOLD,        KC_VOLU,        KC_LCBR,     ____,          ____,                                  \
		____,          ____,         KC_RCBR,     ____,           ____,           ____,        ____,          KC_PSCR,                               \
        ____,          ____,         ____,        ____,           TD(TO_VICE),    KC_F10,      KC_F11,        KC_F12,                                \
                                                                                                                            ____,                    \
                                        				                                                                              KC_NO),
};																														  

*/

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
	case TECLA_2:
	 if  (record->event.pressed) 
	 { 
	    if  (get_mods() & MOD_BIT(KC_LSFT))
	       {
      	    lshift = 1;
		    register_code(KC_QUOT);
	       }  
		 else
		   {
            lshift = 0;
		    register_code(KC_2);
		   }
     }
	 else
          {
      	if (lshift == 1)
	      {
      	   unregister_code(KC_QUOT);
	      }  
		else
		  {
		   unregister_code(KC_2);
		  }
	 	 }
	 return false;

case TECLA_6:
	 if  (record->event.pressed) 
	 {
	    if  (get_mods() & MOD_BIT(KC_LSFT))
	      {
      	   lshift = 1;
		   register_code(KC_7);
		  }
	     else
		  {
           lshift = 0;
		   register_code(KC_6);
		  }
	 }
      else
	      {
		 if  (lshift == 1)
	        {
      	      unregister_code(KC_7);
	        }
	        else
		      {
               unregister_code(KC_6);
              }
		  }
			return false;	 	
			
case TECLA_7:
	 if  (get_mods() & MOD_BIT(KC_LSFT))
	   {
	    if  (record->event.pressed) 
	      {
		   unregister_code(KC_LSFT);
		   register_code(KC_QUOT);
		   register_code(KC_LSFT);
	      }
	     else
		  {
		   unregister_code(KC_QUOT);
		   register_code(KC_LSFT);
		  }
          return false;	 
	 } 
	  else
		 {
		if (record->event.pressed) 
		  {
      	   register_code(KC_7);
		  }
	     else
		  {
           unregister_code(KC_7);
          }
          return false;	 
	 }

			
case TECLA_8:
	 if  (record->event.pressed) 
	 {
	    if  (get_mods() & MOD_BIT(KC_LSFT))
	      {
      	   lshift = 1;
		   register_code(KC_9);
	      }
	     else
		  {
           lshift = 0;
		   register_code(KC_8);
		  }
	 }
      else
	      {
		 if  (lshift == 1)
	        {
      	      unregister_code(KC_9);
			}
	        else
		      {
               unregister_code(KC_8);
              }
		  }
			return false;	 

case TECLA_9:
	 if  (record->event.pressed) 
	 {
	    if  (get_mods() & MOD_BIT(KC_LSFT))
	      {
      	   lshift = 1;
		   register_code(KC_0);
	      }
	     else
		  {
           lshift = 0;
		   register_code(KC_9);
		  }
	 }
      else
	      {
		 if  (lshift == 1)
	        {
      	      unregister_code(KC_0);
			}
	        else
		      {
               unregister_code(KC_9);
              }
		  }
			return false;				

case TECLA_0:
	 if  (record->event.pressed) 
	 {
	    if  (get_mods() & MOD_BIT(KC_LSFT))
	      {
      	   lshift = 1;
		   register_code(KC_6);
	      }
	     else
		  {
           lshift = 0;
		   register_code(KC_0);
		  }
	 }
      else
	      {
		 if  (lshift == 1)
	        {
      	      unregister_code(KC_6);
			}
	        else
		      {
               unregister_code(KC_0);
              }
		  }
			return false;

case TECLA_ACOR:
	 if (record->event.pressed)
	 {
	 if  (get_mods() & MOD_BIT(KC_LSHIFT))
	    {
         unregister_code(KC_LSFT);
		 SEND_STRING("[");
		 register_code(KC_LSFT);
		 return false;
	    }
	  else
	    {
        register_code(KC_LSFT);
		SEND_STRING(";");
		unregister_code(KC_LSFT);
        }
	return true;
	 } 
	
case TECLA_CCOR:
	 if  (get_mods() & MOD_BIT(KC_LSFT))
	   {
	    if  (record->event.pressed) 
	      {
		   unregister_code(KC_LSFT);
		   register_code(KC_RBRC);
		   register_code(KC_LSFT);
	      }
	     else
		  {
		   unregister_code(KC_RBRC);
		   register_code(KC_LSFT);
		  }
          return false;	 
	   }
      else
	   {
		if (record->event.pressed) 
	      {
		   register_code(KC_SCLN);
		  }
	     else
		  {
           unregister_code(KC_SCLN);
          }
          return false;	 
	   }						
			
    }
return true; 	
}	 

void matrix_init_user(void) 
{
	// For Arduino use the following line:
	//DDRB |= (1 << 1) | (1 << 2) | (1 << 3);
	// For Teensy 2++ use the following line:
	DDRB |= (1 << 4) | (1 << 5) | (1 << 6);
	
	c64_power_led_off();
	c64_vice_led_off();
	c64_rshift_led_off();
	key_timer = timer_read();
}

void matrix_scan_user(void)
{
	uint8_t layer = biton32(layer_state);
	c64_power_led_off();
	c64_rshift_led_off();
	c64_vice_led_off();

	
// One (blinking) LED only Option. (Originally red although some C64 had green LED). 	

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
             



// RGB LED Option	

/*
switch (layer) {
        case PC:
            // PC Mode
            c64_power_led_on();
            break;
        case VICE:
            // Emulator Mode
            c64_vice_led_on();
            break;
			case RST:
            // Right Shift pressed Mode
            c64_rshift_led_on();
            break;
        case RSLG:
            // Right Shift & Left GUI Pressed Mode
           	c64_power_led_on();
        	c64_rshift_led_on();
            break;
        default:
            // none
			break;
              }

*/

			  
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

