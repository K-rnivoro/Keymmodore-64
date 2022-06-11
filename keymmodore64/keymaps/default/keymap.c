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

//Definition of non standard keys in the C-64 Keyboard.
enum my_keycodes {
	TECLA_7 = SAFE_RANGE,
	TECLA_ACOR,
    TECLA_CCOR,
};

  
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[PC] = LAYOUT(
        KC_1,				KC_GESC,				CTL_T(KC_TAB),				KC_LALT,				KC_SPC,					MO(CKEY),				KC_Q,				KC_2,						 									\
        KC_3,				KC_W,   	            KC_A,  				        LM(LSHFT,MOD_LSFT),		KC_Z,               	KC_S,                   KC_E,               KC_4,						 									\
        KC_5,     			KC_R,       			KC_D,         				KC_X,              		KC_C,               	KC_F,                   KC_T,    			KC_6, 						 									\
		KC_7,     			KC_Y,         			KC_G,          				KC_V,              		KC_B,               	KC_H,       	        KC_U,    			KC_8,				 		 									\
		KC_9,     			KC_I,       	        KC_J,          				KC_N,              		KC_M,              		KC_K,                	KC_O,    			KC_0,      				  	 									\
		KC_PLUS,  			KC_P,                	KC_L,          				KC_COMM,           		KC_DOT,            		KC_COLON,            	KC_AT,   			KC_MINS,   					 									\
		KC_BSLS,  			KC_ASTR,             	KC_SCLN,       				KC_SLSH,           		MO(RSHFT),         		KC_EQL,              	KC_UP,   			KC_HOME,   			 		 									\
		KC_DEL,   			KC_ENT,              	KC_RGHT,       				KC_DOWN,           		KC_F1,              	KC_F3,               	KC_F5,   			KC_F7,     					 									\
																																														   KC_BSPC,      									\
																																																	KC_P0,  KC_P8, KC_P2,  KC_P4,  KC_P6,	\
																																																	KC_PDOT,KC_P7, KC_P3,  KC_P1,  KC_P9),

[LSHFT] = LAYOUT(
        ____,     			____,                	____,          				____,             		____,              		KC_NO,               	____,    			KC_DQUO,                     									\
        ____,     			____,                	____,          				____,              		____,              		____,                	____,   		 	____,         				 									\
        ____,     			____,                	____,          				____,             	 	____,              		____,                	____,    			KC_AMPR,        			 									\
		TECLA_7,  			____,                	____,          				____,              		____,              		____,                	____,    			KC_9,      			     	 									\
		KC_0,     			____,                	____,          				____,              		____,              		____,                	____,    			KC_CIRC,   			      	 									\
		____,     			____,                	____,          				____,              		____,              		TECLA_ACOR,          	____,    			____,      			    	 									\
		____,     			____,                	TECLA_CCOR,    				____,              		____,              		____,                	____,    			____,      			    	 									\
		____,     			____,                	____,          				____,              		____,            		____,             		____,				____,					   	 									\
																																															____,        									\
																																																	____,  ____,  ____,  ____,  ____,  		\
																																																	____,  ____,  ____,  ____,  ____),

									
[RSHFT] = LAYOUT(
        KC_EXLM,  			KC_TILD,             	____,          				____,              		S(KC_SPC),         		KC_NO,               	S(KC_Q),            KC_DQUO,														\
        KC_HASH,  			S(KC_W),             	S(KC_A),       				____,              		S(KC_Z),           		S(KC_S),             	S(KC_E),   			KC_DLR,															\
        KC_PERC,  			S(KC_R),             	S(KC_D),       				S(KC_X),           		S(KC_C),           		S(KC_F),             	S(KC_T),   			KC_AMPR,                  										\
		KC_QUOT,  			S(KC_Y),             	S(KC_G),       				S(KC_V),           		S(KC_B),           		S(KC_H),             	S(KC_U),   			KC_LPRN,   					 									\
		KC_RPRN,  			S(KC_I),             	S(KC_J),       				S(KC_N),           		S(KC_M),           		S(KC_K),             	S(KC_O),   			KC_CIRC,   														\
		____,     			S(KC_P),             	S(KC_L),       				KC_LABK,           		KC_RABK,           		KC_LBRC,             	____,      			KC_UNDS,   														\
	    KC_PIPE,  			____,                	KC_RBRC,      				KC_QUES,           		____,              		____,                	S(KC_UP),			S(KC_HOME),														\
		S(KC_DEL),			S(KC_ENT),           	KC_LEFT,       				KC_UP,             		KC_F2,            		KC_F4,	             	KC_F6,				KC_F8,      													\
																																															S(KC_BSPC),									    \
																																																	____,  ____,  ____,  ____,  ____,  		\
																																																	____,  ____,  ____,  ____,  ____),
																																				          
[CKEY] = LAYOUT(
        KC_F1,  			KC_GRV,              	KC_LCTRL,      				____,              		____,		     		____,                	KC_PGUP,   			KC_F2,              											\
        KC_F3,   			KC_UP,     				KC_LEFT,       				____,              		____,              		KC_DOWN,             	KC_PGDN,   			KC_F4,        													\
        KC_F5,   			____,                	KC_RGHT,       				____,              		KC_CALC,           		____,                	____,      			KC_F6,     														\
		KC_F7,   			____,                	____,          				____,           		____,          			____,                	KC_PGUP,   			KC_F8,    				 										\
		KC_F9,   			KC_UP,               	KC_LEFT,       				____,           		____,           		KC_DOWN,             	KC_PGDN,   			KC_F10,   				   										\
		KC_F11,  			KC_PSCR,             	KC_RGHT,       				KC_VOLD,           		KC_VOLU,           		KC_LCBR,             	KC_SLCK,   			KC_F12,   			 											\
		____,    			KC_NLCK,             	KC_RCBR,       				KC_MUTE,           		____,              		____,                	KC_PGUP,   			KC_END,   				   										\
		KC_INS,  			____,                	KC_LEFT,       				KC_UP,             		TO(C64),            	TO(C128),             	TO(PETGRAPH),		____,		      					        					\
																																															KC_PGDN,										\
																																																	____,  ____,  ____,  ____,  ____,  		\
																																																	____,  ____,  ____,  ____,  ____),
[C64] = LAYOUT(
        KC_1,     			KC_GRV,             	KC_TAB,       				KC_ESC,             	KC_SPC,     	       	LM(CBM,MOD_LCTL),    	KC_Q,    			KC_2,                       									\
        KC_3,     			KC_W,               	KC_A,         				KC_LSFT,            	KC_Z,      	        	KC_S,                	KC_E,    			KC_4,                       									\
        KC_5,     			KC_R,               	KC_D,         				KC_X,               	KC_C,              		KC_F,                	KC_T,    			KC_6,                     										\
		KC_7,     			KC_Y,               	KC_G,         				KC_V,               	KC_B,              		KC_H,                	KC_U,    			KC_8,        			      									\
		KC_9,     			KC_I,               	KC_J,         				KC_N,               	KC_M,              		KC_K,                	KC_O,    			KC_0,        			    									\
		KC_MINS,  			KC_P,               	KC_L,         				KC_COMM,            	KC_DOT,            		KC_SCLN,             	KC_LBRC, 			KC_EQL,   				    									\
		KC_INS,   			KC_RBRC,            	KC_QUOT,      				KC_SLSH,            	KC_RSFT,           		KC_BSLS,             	KC_DEL,  			KC_HOME,     			      									\
		KC_BSPC,  			KC_ENT,             	KC_RGHT,      				KC_DOWN,            	KC_F1,             		KC_F3,               	KC_F5,   			KC_F7,       			    									\
																																															KC_PGUP,										\
																																																	____,  ____,  ____,  ____,  ____,  		\
																																																	____,  ____,  ____,  ____,  ____),

[C128] = LAYOUT(
        KC_1,     			KC_GRV,             	KC_TAB,   		      		KC_ESC,             	KC_SPC,     	       	LM(CBM,MOD_LCTL),    	KC_Q,    			KC_2,                       									\
        KC_3,     			KC_W,               	KC_A,         				KC_LSFT,            	KC_Z,      	        	KC_S,                	KC_E,    			KC_4,                       									\
        KC_5,     			KC_R,               	KC_D,         				KC_X,               	KC_C,              		KC_F,                	KC_T,    			KC_6,                     										\
		KC_7,     			KC_Y,               	KC_G,         				KC_V,               	KC_B,              		KC_H,                	KC_U,    			KC_8,        			      									\
		KC_9,     			KC_I,               	KC_J,         				KC_N,               	KC_M,              		KC_K,                	KC_O,    			KC_0,        			    									\
		KC_MINS,  			KC_P,               	KC_L,         				KC_COMM,            	KC_DOT,            		KC_SCLN,             	KC_LBRC, 			KC_EQL,   				    									\
		KC_INS,   			KC_RBRC,            	KC_QUOT,      				KC_SLSH,            	MO(C128_RSFT),       	KC_BSLS,             	KC_DEL,  			KC_HOME,     			      									\
		KC_BSPC,  			KC_ENT,             	KC_RGHT,      				KC_DOWN,            	KC_F1,             		KC_F3,               	KC_F5,   			KC_F7,       			    									\
																																															KC_PGUP,										\
																																																	____,  ____,  ____,  ____,  ____,  		\
																																																	____,  ____,  ____,  ____,  ____),
																																																	
[C128_RSFT] = LAYOUT(
        KC_P1,    			KC_PAST,              	KC_F11, 					KC_F9,            		S(KC_SPC),              ____,               	S(KC_Q),      		KC_P2,               											\
        KC_P3,    			S(KC_W),               	S(KC_A),             		____,		    		S(KC_Z),                S(KC_S),               	S(KC_E),      		KC_P4,                       									\
        KC_P5,    			S(KC_R),               	S(KC_D),             		S(KC_X),           		S(KC_C),                S(KC_F),                S(KC_T),      		KC_P6,                       									\
		KC_P7,    			S(KC_Y),               	S(KC_G),             		S(KC_V),           		S(KC_B),                S(KC_H),                S(KC_U),      		KC_P8,    				      									\
		KC_P9,    			S(KC_I),               	S(KC_J),             		S(KC_N),           		S(KC_M),                S(KC_K),                S(KC_O),      		KC_P0,    		     											\
		KC_PPLS,   			S(KC_P),               	S(KC_L),             		KC_LABK,           		KC_PDOT,           		KC_COLON,               KC_LCBR,   			KC_PMNS,   		       											\
		S(KC_INS),     		KC_RCBR,               	KC_DQUO,          			KC_QUES,              	____,              		KC_PIPE,                KC_F10,    			S(KC_HOME),    		       										\
		S(KC_BSPC),    		KC_PENT,               	KC_LEFT,       				KC_UP,            		KC_F2,            		KC_F4,    	     	    KC_F6,    			KC_PSLS,                                                        \
																																															S(KC_PGUP),										\
																																																	____,  ____,  ____,  ____,  ____,  		\
																																																	____,  ____,  ____,  ____,  ____),

[PETGRAPH] = LAYOUT(
        KC_1,     			KC_GRV,             	KC_INS,       				KC_ESC,               	KC_SPC,            		MO(PETGRAPH_C),			KC_Q,    			KC_2,                    										\
        KC_3,     			KC_W,               	KC_A,         				KC_LSFT,			 	KC_Z,             		KC_S,           		KC_E,    			KC_4,   														\
        KC_5,     			KC_R,               	KC_D,         				KC_X,                 	KC_C,        			KC_F,           		KC_T,    			KC_6,     														\
		KC_7,     			KC_Y,               	KC_G,         				KC_V,                 	KC_B,               	KC_H,           		KC_U,    			KC_8,        		  										    \
		KC_9,     			KC_I,               	KC_J,        				KC_N,                 	KC_M,               	KC_K,           		KC_O,    			KC_0,        		 									     	\
		KC_MINS,  			KC_P,               	KC_L,         				KC_COMM,              	KC_DOT,             	KC_SCLN,        		KC_LBRC, 			KC_EQL,  										    		    \
		KC_TAB,   			KC_RBRC,            	KC_QUOT,      				KC_SLSH,              	KC_RSFT,			 	KC_BSLS,        		KC_DEL,  			KC_HOME,     		     										\
		KC_BSPC,  			KC_ENT,             	KC_RGHT,      	    		KC_DOWN,              	KC_NO,                	KC_NO,          		KC_NO,   			KC_NO,       		    										\
																																															KC_BSPC,										\
																																																	____,  ____,  ____,  ____,  ____,  		\
																																																	____,  ____,  ____,  ____,  ____),
[PETGRAPH_C] = LAYOUT(
		KC_F1,     			____,               	TO(PC),         			____,                 	____,                 	____,           		S(KC_F10),			KC_F2,                       									\
        KC_F3,     			S(KC_3),           		S(KC_0),       				____,                 	S(KC_F11),             	KC_RABK,       			S(KC_1),   			KC_F4,     														\
        KC_F5,     			S(KC_2),           		KC_LABK,       				KC_PIPE,               	S(KC_PGUP),        		KC_DQUO,      			S(KC_F3),  			KC_F6,                       									\
		KC_UP,     			S(KC_7),             	S(KC_F5),       			S(KC_PGDN),        		S(KC_PSLS),            	S(KC_4),         		S(KC_8),   			KC_LEFT,        	     										\
		KC_F9, 				S(KC_F2),          		S(KC_5),       				KC_LALT,            	S(KC_UP),          		S(KC_F1),        		S(KC_9),   			____, 	   														\
		S(KC_F6),			KC_QUES,          		S(KC_6),      				KC_PGUP,               	KC_PGDN,               	KC_PMNS,       			S(KC_F4),  			S(KC_PAST),           											\
		S(KC_LEFT),			KC_TILD,        		KC_PPLS,       				KC_PSLS,               	____,                 	____, 	          		S(KC_DEL), 			____,        	       											\
		____,     			____,               	____,         				____,                 	____,                 	____,           		TO(PETBUS), 		C(KC_F7),      	      											\
																																															____,											\
																																																	____,  ____,  ____,  ____,  ____,  		\
																																																	____,  ____,  ____,  ____,  ____),
[PETBUS] = LAYOUT(
        KC_1,     			KC_GRV,             	KC_TAB,       				KC_ESC,               	KC_SPC,            		MO(PETBUS_C),			KC_Q,    			KC_2,                    										\
        KC_3,     			KC_W,               	KC_A,         				KC_LSFT,			 	KC_Z,             		KC_S,           		KC_E,    			KC_4,   														\
        KC_5,     			KC_R,               	KC_D,         				KC_X,                 	KC_C,        			KC_F,           		KC_T,    			KC_6,     														\
		KC_7,     			KC_Y,               	KC_G,         				KC_V,                 	KC_B,               	KC_H,           		KC_U,    			KC_8,        		  										    \
		KC_9,     			KC_I,               	KC_J,        				KC_N,                 	KC_M,               	KC_K,           		KC_O,    			KC_0,        		 									     	\
		KC_MINS,  			KC_P,               	KC_L,         				KC_COMM,              	KC_DOT,             	KC_SCLN,        		KC_LBRC, 			KC_EQL,  										    		    \
		KC_INS,   			KC_RBRC,            	KC_QUOT,      				KC_SLSH,              	KC_RSFT,			 	KC_BSLS,        		KC_DEL,  			KC_HOME,     		     										\
		KC_BSPC,  			KC_ENT,             	KC_RGHT,      				KC_DOWN,              	KC_F1,                	KC_F3,          		KC_F5,   			KC_F7,       		    										\
																																															KC_BSPC,										\
																																																	____,  ____,  ____,  ____,  ____,  		\
																																																	____,  ____,  ____,  ____,  ____),
[PETBUS_C] = LAYOUT(
		KC_P1,     			KC_NO,               	TO(PC),        				KC_NO,                 	____,                 	____,           		KC_NO,				KC_P2,                       									\
        KC_P3,     			KC_NO,              	KC_NO,       				____,                 	KC_NO,                	KC_NO,         			KC_NO,     			KC_P4,     														\
        KC_P5,     			KC_NO,             		KC_NO,       				KC_NO,              	KC_NO,           		KC_NO,         			KC_NO,    			KC_P6,                       									\
		KC_P7,     			KC_NO,	             	KC_NO, 						KC_NO,           		KC_NO,               	KC_NO,         			KC_NO,   			KC_P8,        	     											\
		KC_P9,  			KC_NO,             		KC_NO,       				KC_NO,              	KC_NO,             		KC_NO,        			KC_NO,   			KC_P0,     	   													\
		KC_NO,   			KC_NO,            		KC_NO,      				KC_NO,                 	KC_PDOT,               	KC_F10,           		KC_NO,     			KC_NO,       	       											\
		KC_NO,   			KC_NO,              	KC_F11,        				KC_NO,                 	____,                 	KC_NO, 	          		KC_NO,      		____,        	       											\
		KC_NO,     			KC_NO,               	KC_NO,         				KC_NO,                 	KC_NO,                 	KC_NO,           		KC_NO,     			C(KC_F7),        	      										\
																																															____,											\
																																																	____,  ____,  ____,  ____,  ____,  		\
																																																	____,  ____,  ____,  ____,  ____),
[CBM] = LAYOUT(
        ____,    			____,                	TO(PC),        				____,              		____,              		____,               	____,    			____,               											\
        ____,    			____,                	____,          				____,              		____,              		____,                 	____,    			____,                       									\
        ____,    			____,                	____,          				____,              		____,              		____,                   ____,    			____,                       									\
		____,    			____,                	____,          				____,              		____,              		____,                   ____,    			____,    				      									\
		____,    			____,                	____,          				____,              		____,              		____,                   ____,    			____,    		     											\
		____,    			____,                	____,          				____,              		____,              		____,                   ____,    			____,    		       											\
		____,    			____,                	____,          				____,              		____,              		____,                   ____,    			____,    		       											\
		____,    			____,                	____,          				____,              		____,              		____,                   ____,    			____,                                                           \
																																															____,											\
																																																	____,  ____,  ____,  ____,  ____,  		\
																																																	____,  ____,  ____,  ____,  ____),

};	
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

void keyboard_pre_init_user(void) {
	
	setPinOutput(red_led);
    setPinOutput(green_led);
    setPinOutput(blue_led);
	writePinHigh(red_led);
    writePinLow(green_led);
    writePinHigh(blue_led);
}


layer_state_t layer_state_set_user(layer_state_t state) {
//Inverted Logic so PinLow is LED On and PinHigh is LED Off.
switch (get_highest_layer(state)) {
case PC:
	writePinHigh(red_led);
    writePinLow(green_led);
    writePinHigh(blue_led);
	break;
case RSHFT:
	writePinHigh(red_led);
    writePinLow(green_led);
    writePinLow(blue_led);
    break;
case CKEY:
	writePinLow(red_led);
    writePinLow(green_led);
    writePinLow(blue_led);
    break;
case C64:
	writePinLow(red_led);
    writePinHigh(green_led);
    writePinHigh(blue_led);
    break;
case C128:
	writePinHigh(red_led);
    writePinHigh(green_led);
    writePinLow(blue_led);
    break;
case C128_RSFT:
	writePinHigh(red_led);
    writePinLow(green_led);
    writePinLow(blue_led);
    break;
case PETGRAPH:
	writePinLow(red_led);
    writePinLow(green_led);
    writePinHigh(blue_led);
    break;
case PETGRAPH_C:
	writePinLow(red_led);
    writePinLow(green_led);
    writePinLow(blue_led);
    break;
case PETBUS:
	writePinLow(red_led);
    writePinHigh(green_led);
    writePinLow(blue_led);
    break;
case PETBUS_C:
	writePinLow(red_led);
    writePinLow(green_led);
    writePinLow(blue_led);
    break;
case CBM:
	writePinLow(red_led);
    writePinLow(green_led);
    writePinLow(blue_led);
    break;
}
return state;
}


void matrix_init_user(void) 
{

}

void matrix_scan_user(void)
{

}
