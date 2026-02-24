/* Copyright 2023 K-rnivoro (www.keymmodore.com)
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

/*
 The Commodore layouts are compatible with Bare Metal Commodore 64, Combian, VICE and CCS64 Emulators
 You need to set "Keyboard Settings" in "Positional" Layout in Emulator for C64.
 For Plus/4, C-128 and PET you need to set as "Positional (User)" and use custom .vkm files.
 The ZX layouts are compatible with ZXBaremulator with no custom configuration needed.
*/


#define PC           0   /* PC Compatible Mode */
#define LSHFT        1   /* Left SHIFT Key */
#define RSHFT        2   /* Right SHIFT Key */
#define CKEY         3   /* Commodore Key as a Function Key (like 60% style Keyboards) */
#define ZX           4   /* ZX Spectrum compatible layout with Cursor and QAOP-Space support for ZXBaremulator*/
#define RSFT_ZX      5   /* Right Shift Key pressed as a Function Key for ZXBaremulator*/
#define CKEY_ZX      6   /* Commodore Key pressed as a Function Key in ZX layer for ZXBaremulator*/
#define CKEY_SHFT_ZX 7   /* Commodore Key and Left Shift pressed as a Function Keys in ZX layer for ZXBaremulator*/
#define C64          8   /* Commodore-64, VIC-20 Plus/4, C-16 and C116 layer. (need custom .vkm for emulators) */
#define C128         9   /* Commodore 128 Keyboard mapping. (need custom .vkm for emulators) */
#define C128_RSFT    10  /* Commodore 128 Keyboard with Right Shift pressed mapping (allow to access exclusive C-128 Keys). */
#define PETBUS       11  /* Commodore PET Business Keyboard mapping (upper case letters with SHIFT key). */
#define PETBUS_C     12  /* Commodore PET Business Keyboard mapping with C= Key. Allows access to NumPad keys. */
#define PETGRAPH     13  /* Commodore PET Graphics Keyboard mapping. Allows access right legend PETSCII with SHIFT key. */
#define PETGRAPH_C   14  /* Commodore PET Graphics Keyboard mapping with C= Key. Allow access left legend PETSCII codes with C= key. */
#define CBM          15  /* Commodore Key pressed in Emulation mode. Allows to go back to PC Mode pressing CONTROL. */


static int current_keyb_mode = PC; // Will reflect the Keyboard mode when BMC64 is running

//Definition of non standard keys in the C-64 Keyboard.
enum my_keycodes {
	TECLA_7 = SAFE_RANGE,
	TECLA_ACOR,
    TECLA_CCOR,
	TECLA_ZXACOR,
	TECLA_ZXCCOR,
	BLK,
	WHT,
	RED,
	CYN,
	PUR,
	GRN,
	BLU,
	YEL,
	S_BLK,
	S_RED,
	S_PUR,
	S_BLU,
	S_WHT,
	S_CYN,
	S_GRN,
	S_YEL,
};

  
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[PC] = LAYOUT(
        KC_1,				QK_GESC,				CTL_T(KC_TAB),				KC_LALT,				KC_SPC,					MO(CKEY),				KC_Q,				KC_2,
        KC_3,				KC_W,   	            KC_A,  				        LM(LSHFT,MOD_LSFT),		KC_Z,               	KC_S,                   KC_E,               KC_4,
        KC_5,     			KC_R,       			KC_D,         				KC_X,              		KC_C,               	KC_F,                   KC_T,    			KC_6,
		KC_7,     			KC_Y,         			KC_G,          				KC_V,              		KC_B,               	KC_H,       	        KC_U,    			KC_8,			KC_P7,
		KC_9,     			KC_I,       	        KC_J,          				KC_N,              		KC_M,              		KC_K,                	KC_O,    			KC_0,      		KC_P3,
		KC_PLUS,  			KC_P,                	KC_L,          				KC_COMM,           		KC_DOT,            		KC_COLON,            	KC_AT,   			KC_MINS,   		KC_P1,
		KC_BSLS,  			KC_ASTR,             	KC_SCLN,       				KC_SLSH,           		MO(RSHFT),         		KC_EQL,              	KC_UP,   			KC_HOME,   		KC_P9,
		KC_DEL,   			KC_ENT,              	KC_RGHT,       				KC_DOWN,           		KC_F1,              	KC_F3,               	KC_F5,   			KC_F7,     		KC_PDOT,
		KC_P8,    			KC_P2,              	KC_P4,         				KC_P6,             		KC_P0,						   														KC_BSPC
		),

[LSHFT] = LAYOUT(
        ____,     			____,                	____,          				____,             		____,              		KC_NO,               	____,    			KC_DQUO,
        ____,     			____,                	____,          				____,              		____,              		____,                	____,   		 	____,
        ____,     			____,                	____,          				____,             	 	____,              		____,                	____,    			KC_AMPR,
		TECLA_7,  			____,                	____,          				____,              		____,              		____,                	____,    			KC_9,      		____,
		KC_0,     			____,                	____,          				____,              		____,              		____,                	____,    			KC_CIRC,   		____,
		____,     			____,                	____,          				____,              		____,              		TECLA_ACOR,          	____,    			____,      		____,
		____,     			____,                	TECLA_CCOR,    				____,              		____,              		____,                	____,    			____,      		____,
		____,     			____,                	____,          				____,              		____,            		____,             		____,				____,			____,
		____,     			____,                	____,          				____,              		____,            																	____
		),

[RSHFT] = LAYOUT(
        KC_EXLM,  			KC_TILD,             	____,          				____,              		S(KC_SPC),         		KC_NO,               	S(KC_Q),            KC_DQUO,
        KC_HASH,  			S(KC_W),             	S(KC_A),       				____,              		S(KC_Z),           		S(KC_S),             	S(KC_E),   			KC_DLR,
        KC_PERC,  			S(KC_R),             	S(KC_D),       				S(KC_X),           		S(KC_C),           		S(KC_F),             	S(KC_T),   			KC_AMPR,
		KC_QUOT,  			S(KC_Y),             	S(KC_G),       				S(KC_V),           		S(KC_B),           		S(KC_H),             	S(KC_U),   			KC_LPRN,   		____,
		KC_RPRN,  			S(KC_I),             	S(KC_J),       				S(KC_N),           		S(KC_M),           		S(KC_K),             	S(KC_O),   			KC_CIRC,   		____,
		____,     			S(KC_P),             	S(KC_L),       				KC_LABK,           		KC_RABK,           		KC_LBRC,             	____,      			KC_UNDS,   		____,
	    KC_PIPE,  			____,                	KC_RBRC,      				KC_QUES,           		____,              		____,                	S(KC_UP),			S(KC_HOME),		____,
		S(KC_DEL),			S(KC_ENT),           	KC_LEFT,       				KC_UP,             		KC_F2,            		KC_F4,    	     	    KC_F6,    			KC_F8,      	____,
		____, 				____,            		____,      					____,    	      		____,																				S(KC_BSPC)
		),

[CKEY] = LAYOUT(
        KC_F1,  			KC_GRV,              	KC_LCTL,      				____,              		____,		     		____,                	KC_PGUP,   			KC_F2,
        KC_F3,   			KC_UP,     				KC_LEFT,       				____,              		TO(ZX),           		KC_DOWN,             	KC_PGDN,   			KC_F4,
        KC_F5,   			____,                	KC_RGHT,       				____,              		KC_CALC,           		____,                	____,      			KC_F6,
		KC_F7,   			____,                	____,          				____,           		____,          			____,                	KC_PGUP,   			KC_F8,    		____,
		KC_F9,   			KC_UP,               	KC_LEFT,       				____,           		____,           		KC_DOWN,             	KC_PGDN,   			KC_F10,   		____,
		KC_F11,  			KC_PSCR,             	KC_RGHT,       				KC_VOLD,           		KC_VOLU,           		KC_LCBR,             	KC_LSCR,   			KC_F12,   		____,
		____,    			KC_LNUM,             	KC_RCBR,       				KC_MUTE,           		____,              		____,                	KC_PGUP,   			KC_END,   		____,
		KC_INS,  			____,                	KC_LEFT,       				KC_UP,             		TO(C64),            	TO(C128),             	TO(PETGRAPH),		____,       	____,
		____,     			____,                	____,          				____,              		____, 																				KC_PGDN
		),

[ZX] = LAYOUT(
		KC_1,				KC_ESC,					KC_LCTL,					KC_LALT,				KC_SPC,					MO(CKEY_ZX),			KC_Q,				KC_2,
        KC_3,				KC_W,   	            KC_A,  				        KC_LSFT,				KC_Z,               	KC_S,                   KC_E,               KC_4,
        KC_5,     			KC_R,       			KC_D,         				KC_X,              		KC_C,               	KC_F,                   KC_T,    			KC_6,
		KC_7,     			KC_Y,         			KC_G,          				KC_V,              		KC_B,               	KC_H,       	        KC_U,    			KC_8,			KC_P7,
		KC_9,     			KC_I,       	        KC_J,          				KC_N,              		KC_M,              		KC_K,                	KC_O,    			KC_0,      		KC_P3,
		RCTL(KC_K),			KC_P,                	KC_L,          				RCTL(KC_N),        		RCTL(KC_M),        		RCTL(KC_Z),            	RCTL(KC_2),			RCTL(KC_J),   	KC_P1,
		RCTL(KC_X),  		RCTL(KC_B),            	RCTL(KC_O),    				RCTL(KC_V),           	MO(RSFT_ZX),		 	RCTL(KC_L),            	RCTL(KC_H),			KC_PAUSE,   	KC_P9,
		KC_DEL,   			KC_ENT,              	LSFT(KC_8),       			LSFT(KC_6),        		KC_F1,              	LALT(KC_K),             KC_F8,   			LALT(KC_F8),    KC_PDOT,
		KC_P8,    			KC_P2,              	KC_P4,         				KC_P6,             		KC_P0,  					   														KC_BSPC
		),

[RSFT_ZX] = LAYOUT(
		RCTL(KC_1),			KC_ESC,					KC_NO,						KC_LALT,				KC_SPC,					KC_NO,					LSFT(KC_Q),			RCTL(KC_P),
        RCTL(KC_3),			LSFT(KC_W),   	        LSFT(KC_A),  				____,					LSFT(KC_Z),             LSFT(KC_S),             LSFT(KC_E),         RCTL(KC_4),
        RCTL(KC_5), 		LSFT(KC_R),       		LSFT(KC_D),         		LSFT(KC_X),             LSFT(KC_C),             LSFT(KC_F),             LSFT(KC_T),    		RCTL(KC_6),
		RCTL(KC_7),			LSFT(KC_Y),         	LSFT(KC_G),          		LSFT(KC_V),             LSFT(KC_B),             LSFT(KC_H),       	    LSFT(KC_U),    		RCTL(KC_8),		____,
		RCTL(KC_9),			LSFT(KC_I),       	    LSFT(KC_J),          		LSFT(KC_N),             LSFT(KC_M),             LSFT(KC_K),             LSFT(KC_O),  		RCTL(KC_0), 	____,
		RCTL(KC_K),			LSFT(KC_P),             LSFT(KC_L),          		RCTL(KC_R),        		RCTL(KC_T),        		TECLA_ZXACOR,          	RCTL(KC_2),			RCTL(KC_J),   	____,
		RCTL(KC_X),  		RCTL(KC_B),            	TECLA_ZXCCOR,  				RCTL(KC_C),           	____,		 			RCTL(KC_L),            	RCTL(KC_H),			KC_PAUSE,   	____,
		KC_DEL,   			KC_ENT,              	LSFT(KC_5),       			LSFT(KC_7),        		KC_F1,              	LALT(KC_K),             KC_F8,   			LALT(KC_F8),    ____,
		____,     			____,                	____,          				____,              		____,																			    KC_BSPC
		),   

[CKEY_ZX] = LAYOUT(
		BLK,				____,					TO(PC),						____,					____,					____,					____,				WHT,
        RED,				____,   	            ____,  				        MO(CKEY_SHFT_ZX),	    ____,        			____,             		____,       		CYN,
        PUR,     			____,       			____,         				____,       			____,        			____,            		____,				GRN,
		BLU,     			____,         			____,          				____,       			____,        			____, 	        		____,				YEL,		 	____,
		LSFT(KC_4), 		____,       	        ____,          				____,       			____,       			____,          			____,				LSFT(KC_3),		____,
		____,				____,                	____,          				KC_PGUP,       			KC_PGDN,       			____,            		____,				____,  			____,
		____,  				____,            		____,    					____,          			____,      				____,            		KC_UP,				KC_HOME,   		____,
		KC_END,				____,              		KC_RIGHT,      				KC_DOWN,   				LALT(KC_F2),          	LALT(KC_F3),       		LALT(KC_F4),		KC_F9,     		____,
		____,     			____,                	____,          				____,              		____,																			    KC_LEFT
		),   

[CKEY_SHFT_ZX] = LAYOUT(
		S_BLK,				____,					KC_NO,						____,					____,					____,					____,				S_WHT,
        S_RED,				____,   	            ____,  				        ____,				    KC_NO,       			____,             		____,       		S_CYN,
        S_PUR,     			____,       			____,         				KC_NO,       			____,        			____,            		____,				S_GRN,
		S_BLU,     			____,         			____,          				____,       			____,        			____, 	        		____,				S_YEL,		 	____,
		____,				____,       	        ____,          				____,       			____,       			____,          			____,				____,			____,
		____,				____,                	____,          				____,       			____,       			____,            		____,				____,  			____,
		____,  				____,            		____,    					____,          			____,      				____,            		____,				____,   		____,
		____,				____,              		____,      					____,   				____,          			____,       			____,				____,     		____,
		____,     			____,                	____,          				____,              		____,																				____
		),      

[C64] = LAYOUT(
        KC_1,     			KC_GRV,             	KC_TAB,       				KC_ESC,             	KC_SPC,     	       	LM(CBM,MOD_LCTL),    	KC_Q,    			KC_2,
        KC_3,     			KC_W,               	KC_A,         				KC_LSFT,            	KC_Z,      	        	KC_S,                	KC_E,    			KC_4,
        KC_5,     			KC_R,               	KC_D,         				KC_X,               	KC_C,              		KC_F,                	KC_T,    			KC_6,
		KC_7,     			KC_Y,               	KC_G,         				KC_V,               	KC_B,              		KC_H,                	KC_U,    			KC_8,        	KC_P7,
		KC_9,     			KC_I,               	KC_J,         				KC_N,               	KC_M,              		KC_K,                	KC_O,    			KC_0,        	KC_P3,
		KC_MINS,  			KC_P,               	KC_L,         				KC_COMM,            	KC_DOT,            		KC_SCLN,             	KC_LBRC, 			KC_EQL,   		KC_P1,
		KC_INS,   			KC_RBRC,            	KC_QUOT,      				KC_SLSH,            	KC_RSFT,           		KC_BSLS,             	KC_DEL,  			KC_HOME,     	KC_P9,
		KC_BSPC,  			KC_ENT,             	KC_RGHT,      				KC_DOWN,            	KC_F1,             		KC_F3,               	KC_F5,   			KC_F7,       	KC_PDOT,
		KC_P8,    			KC_P2,              	KC_P4,        				KC_P6,              	KC_P0,																				KC_PGUP
		),

[C128] = LAYOUT(
        KC_1,     			KC_GRV,             	KC_TAB,   		      		KC_ESC,             	KC_SPC,     	       	LM(CBM,MOD_LCTL),    	KC_Q,    			KC_2,
        KC_3,     			KC_W,               	KC_A,         				KC_LSFT,            	KC_Z,      	        	KC_S,                	KC_E,    			KC_4,
        KC_5,     			KC_R,               	KC_D,         				KC_X,               	KC_C,              		KC_F,                	KC_T,    			KC_6,
		KC_7,     			KC_Y,               	KC_G,         				KC_V,               	KC_B,              		KC_H,                	KC_U,    			KC_8,        	KC_P7,
		KC_9,     			KC_I,               	KC_J,         				KC_N,               	KC_M,              		KC_K,                	KC_O,    			KC_0,        	KC_P3,
		KC_MINS,  			KC_P,               	KC_L,         				KC_COMM,            	KC_DOT,            		KC_SCLN,             	KC_LBRC, 			KC_EQL,   		KC_P1,
		KC_INS,   			KC_RBRC,            	KC_QUOT,      				KC_SLSH,            	MO(C128_RSFT),       	KC_BSLS,             	KC_DEL,  			KC_HOME,     	KC_P9,
		KC_BSPC,  			KC_ENT,             	KC_RGHT,      				KC_DOWN,            	KC_F1,             		KC_F3,               	KC_F5,   			KC_F7,       	KC_PDOT,
		KC_P8,    			KC_P2,              	KC_P4,        				KC_P6,              	KC_P0,																				KC_PGUP
		),

[C128_RSFT] = LAYOUT(
        KC_P1,    			KC_PAST,              	KC_F11, 					KC_F9,            		S(KC_SPC),              ____,               	S(KC_Q),      		KC_P2,
        KC_P3,    			S(KC_W),               	S(KC_A),             		____,		    		S(KC_Z),                S(KC_S),               	S(KC_E),      		KC_P4,
        KC_P5,    			S(KC_R),               	S(KC_D),             		S(KC_X),           		S(KC_C),                S(KC_F),                S(KC_T),      		KC_P6,
		KC_P7,    			S(KC_Y),               	S(KC_G),             		S(KC_V),           		S(KC_B),                S(KC_H),                S(KC_U),      		KC_P8,			____,
		KC_P9,    			S(KC_I),               	S(KC_J),             		S(KC_N),           		S(KC_M),                S(KC_K),                S(KC_O),      		KC_P0,    		____,
		KC_PPLS,   			S(KC_P),               	S(KC_L),             		KC_LABK,           		KC_PDOT,           		KC_COLON,               KC_LCBR,   			KC_PMNS,   		____,
		S(KC_INS),     		KC_RCBR,               	KC_DQUO,          			KC_QUES,              	____,              		KC_PIPE,                KC_F10,    			S(KC_HOME), 	____,
		S(KC_BSPC),    		KC_PENT,               	KC_LEFT,       				KC_UP,            		KC_F2,            		KC_F4,    	     	    KC_F6,    			KC_PSLS,        ____,
		____,				____,                	____,          				____,              		____, 																				S(KC_PGUP)
		),

[PETGRAPH] = LAYOUT(
        KC_1,     			KC_GRV,             	KC_INS,       				KC_ESC,               	KC_SPC,            		MO(PETGRAPH_C),			KC_Q,    			KC_2,
        KC_3,     			KC_W,               	KC_A,         				KC_LSFT,			 	KC_Z,             		KC_S,           		KC_E,    			KC_4,
        KC_5,     			KC_R,               	KC_D,         				KC_X,                 	KC_C,        			KC_F,           		KC_T,    			KC_6,
		KC_7,     			KC_Y,               	KC_G,         				KC_V,                 	KC_B,               	KC_H,           		KC_U,    			KC_8,           ____,
		KC_9,     			KC_I,               	KC_J,        				KC_N,                 	KC_M,               	KC_K,           		KC_O,    			KC_0,         	____,
		KC_MINS,  			KC_P,               	KC_L,         				KC_COMM,              	KC_DOT,             	KC_SCLN,        		KC_LBRC, 			KC_EQL,         ____,
		KC_TAB,   			KC_RBRC,            	KC_QUOT,      				KC_SLSH,              	KC_RSFT,			 	KC_BSLS,        		KC_DEL,  			KC_HOME,        ____,
		KC_BSPC,  			KC_ENT,             	KC_RGHT,      	    		KC_DOWN,              	KC_NO,                	KC_NO,          		KC_NO,   			KC_NO,          ____,
		____,				____,                	____,          				____,              		____,																				KC_BSPC
		),

[PETGRAPH_C] = LAYOUT(
		KC_F1,     			____,               	TO(PC),         			____,                 	____,                 	____,           		S(KC_F10),			KC_F2,
        KC_F3,     			S(KC_3),           		S(KC_0),       				____,                 	S(KC_F11),             	KC_RABK,       			S(KC_1),   			KC_F4,
        KC_F5,     			S(KC_2),           		KC_LABK,       				KC_PIPE,               	S(KC_PGUP),        		KC_DQUO,      			S(KC_F3),  			KC_F6,
		KC_UP,     			S(KC_7),             	S(KC_F5),       			S(KC_PGDN),        		S(KC_PSLS),            	S(KC_4),         		S(KC_8),   			KC_LEFT,        ____,
		KC_F9, 				S(KC_F2),          		S(KC_5),       				KC_LALT,            	S(KC_UP),          		S(KC_F1),        		S(KC_9),   			____, 	   	    ____,
		S(KC_F6),			KC_QUES,          		S(KC_6),      				KC_PGUP,               	KC_PGDN,               	KC_PMNS,       			S(KC_F4),  			S(KC_PAST),     ____,
		S(KC_LEFT),			KC_TILD,        		KC_PPLS,       				KC_PSLS,               	____,                 	____, 	          		S(KC_DEL), 			____,           ____,
		____,     			____,               	____,         				____,                 	____,                 	____,           		TO(PETBUS),     	C(KC_F7),       ____,
		____,				____,                	____,          				____,              		____,																				____
		),

[PETBUS] = LAYOUT(
        KC_1,     			KC_GRV,             	KC_TAB,       				KC_ESC,               	KC_SPC,            		MO(PETBUS_C),			KC_Q,    			KC_2,
        KC_3,     			KC_W,               	KC_A,         				KC_LSFT,			 	KC_Z,             		KC_S,           		KC_E,    			KC_4,
        KC_5,     			KC_R,               	KC_D,         				KC_X,                 	KC_C,        			KC_F,           		KC_T,    			KC_6,
		KC_7,     			KC_Y,               	KC_G,         				KC_V,                 	KC_B,               	KC_H,           		KC_U,    			KC_8,       	KC_P7,
		KC_9,     			KC_I,               	KC_J,        				KC_N,                 	KC_M,               	KC_K,           		KC_O,    			KC_0,       	KC_P3,
		KC_MINS,  			KC_P,               	KC_L,         				KC_COMM,              	KC_DOT,             	KC_SCLN,        		KC_LBRC, 			KC_EQL, 		KC_P1,
		KC_INS,   			KC_RBRC,            	KC_QUOT,      				KC_SLSH,              	KC_RSFT,			 	KC_BSLS,        		KC_DEL,  			KC_HOME,    	KC_P9,
		KC_BSPC,  			KC_ENT,             	KC_RGHT,      				KC_DOWN,              	KC_F1,                	KC_F3,          		KC_F5,   			KC_F7,      	KC_PDOT,
		KC_P8,    			KC_P2,              	KC_P4,        				KC_P6,              	KC_P0,																				KC_BSPC
		),

[PETBUS_C] = LAYOUT(
		KC_P1,     			KC_NO,               	TO(PC),        				KC_NO,                 	____,                 	____,           		KC_NO,				KC_P2,
        KC_P3,     			KC_NO,              	KC_NO,       				____,                 	KC_NO,                	KC_NO,         			KC_NO,     			KC_P4,
        KC_P5,     			KC_NO,             		KC_NO,       				KC_NO,              	KC_NO,           		KC_NO,         			KC_NO,    			KC_P6,
		KC_P7,     			KC_NO,	             	KC_NO, 						KC_NO,           		KC_NO,               	KC_NO,         			KC_NO,   			KC_P8,         	____,
		KC_P9,  			KC_NO,             		KC_NO,       				KC_NO,              	KC_NO,             		KC_NO,        			KC_NO,   			KC_P0,         	____,
		KC_NO,   			KC_NO,            		KC_NO,      				KC_NO,                 	KC_PDOT,               	KC_F10,           		KC_NO,     			KC_NO,        	____,
		KC_NO,   			KC_NO,              	KC_F11,        				KC_NO,                 	____,                 	KC_NO, 	          		KC_NO,      		____,         	____,
		KC_NO,     			KC_NO,               	KC_NO,         				KC_NO,                 	KC_NO,                 	KC_NO,           		KC_NO,     			C(KC_F7),		____,
		____,				____,                	____,          				____,              		____,																				____
		),

[CBM] = LAYOUT(
        ____,    			____,                	TO(PC),        				____,              		____,              		____,               	____,    			____,
        ____,    			____,                	____,          				____,              		____,              		____,                 	____,    			____,
        ____,    			____,                	____,          				____,              		____,              		____,                   ____,    			____,
		____,    			____,                	____,          				____,              		____,              		____,                   ____,    			____,    		____,
		____,    			____,                	____,          				____,              		____,              		____,                   ____,    			____,    		____,
		____,    			____,                	____,          				____,              		____,              		____,                   ____,    			____,    		____,
		____,    			____,                	____,          				____,              		____,              		____,                   ____,    			____,    		____,
		____,    			____,                	____,          				____,              		____,              		____,                   ____,    			____,           ____,
		____,				____,                	____,          				____,              		____,																				____
		)
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
case TECLA_ZXACOR:
	     if (record->event.pressed)
		{
	     register_code(KC_RCTL);
		 register_code(KC_LSFT);
		 wait_ms(25);
		 unregister_code(KC_RCTL);
		 register_code(KC_Y);

	    }
	  else
	    {
		unregister_code(KC_Y);
		unregister_code(KC_LSFT);
        }
		return false;

case TECLA_ZXCCOR:
	     if (record->event.pressed)
		{
	     register_code(KC_LSFT);
		 register_code(KC_RCTL);
		 wait_ms(25);
		 unregister_code(KC_LSFT);
		 register_code(KC_U);

	    }
	  else
	    {
		unregister_code(KC_U);
		unregister_code(KC_RCTL);
        }
		return false;

case BLK:
	     if (record->event.pressed)
		{
	     register_code(KC_LSFT);
		 register_code(KC_RCTL);
		 wait_ms(25);
		 register_code(KC_0);
		 unregister_code(KC_RCTL);
	    }
	  else
	    {
		unregister_code(KC_0);
		unregister_code(KC_LSFT);
        }
		return false;
case WHT:
	     if (record->event.pressed)
		{
	     register_code(KC_LSFT);
		 register_code(KC_RCTL);
		 wait_ms(25);
		 register_code(KC_7);
		 unregister_code(KC_RCTL);
	    }
	  else
	    {
		unregister_code(KC_7);
		unregister_code(KC_LSFT);
        }
		return false;
case RED:
	     if (record->event.pressed)
		{
	     register_code(KC_LSFT);
		 register_code(KC_RCTL);
		 wait_ms(25);
		 register_code(KC_2);
		 unregister_code(KC_RCTL);
	    }
	  else
	    {
		unregister_code(KC_2);
		unregister_code(KC_LSFT);
        }
		return false;
case CYN:
	     if (record->event.pressed)
		{
	     register_code(KC_LSFT);
		 register_code(KC_RCTL);
		 wait_ms(25);
		 register_code(KC_5);
		 unregister_code(KC_RCTL);
	    }
	  else
	    {
		unregister_code(KC_5);
		unregister_code(KC_LSFT);
        }
		return false;
case PUR:
	     if (record->event.pressed)
		{
	     register_code(KC_LSFT);
		 register_code(KC_RCTL);
		 wait_ms(25);
		 register_code(KC_3);
		 unregister_code(KC_RCTL);
	    }
	  else
	    {
		unregister_code(KC_3);
		unregister_code(KC_LSFT);
        }
		return false;
case GRN:
	     if (record->event.pressed)
		{
	     register_code(KC_LSFT);
		 register_code(KC_RCTL);
		 wait_ms(25);
		 register_code(KC_4);
		 unregister_code(KC_RCTL);
	    }
	  else
	    {
		unregister_code(KC_4);
		unregister_code(KC_LSFT);
        }
		return false;
case BLU:
	     if (record->event.pressed)
		{
	     register_code(KC_LSFT);
		 register_code(KC_RCTL);
		 wait_ms(25);
		 register_code(KC_1);
		 unregister_code(KC_RCTL);
	    }
	  else
	    {
		unregister_code(KC_1);
		unregister_code(KC_LSFT);
        }
		return false;
case YEL:
	     if (record->event.pressed)
		{
	     register_code(KC_LSFT);
		 register_code(KC_RCTL);
		 wait_ms(25);
		 register_code(KC_6);
		 unregister_code(KC_RCTL);
	    }
	  else
	    {
		unregister_code(KC_6);
		unregister_code(KC_LSFT);
        }
		return false;
case S_BLK:
	     if (record->event.pressed)
		{
	     register_code(KC_LSFT);
		 register_code(KC_RCTL);
		 wait_ms(25);
		 unregister_code(KC_LSFT); 
		 unregister_code(KC_RCTL);
		 wait_ms(25);	
		 register_code(KC_0);
	    }
	  else
	    {
		unregister_code(KC_0);
		}
		return false;
case S_WHT:
	     if (record->event.pressed)
		{
	     register_code(KC_LSFT);
		 register_code(KC_RCTL);
		 wait_ms(25);
		 unregister_code(KC_LSFT); 
		 unregister_code(KC_RCTL);
		 wait_ms(25);	
		 register_code(KC_7);
	    }
	  else
	    {
		unregister_code(KC_7);
		}
		return false;
case S_RED:
	     if (record->event.pressed)
		{
	     register_code(KC_LSFT);
		 register_code(KC_RCTL);
		 wait_ms(25);
		 unregister_code(KC_LSFT); 
		 unregister_code(KC_RCTL);
		 wait_ms(25);	
		 register_code(KC_2);
	    }
	  else
	    {
		unregister_code(KC_2);
		}
		return false;
case S_CYN:
	     if (record->event.pressed)
		{
	     register_code(KC_LSFT);
		 register_code(KC_RCTL);
		 wait_ms(25);
		 unregister_code(KC_LSFT); 
		 unregister_code(KC_RCTL);
		 wait_ms(25);	
		 register_code(KC_5);
	    }
	  else
	    {
		unregister_code(KC_5);
		}
		return false;
case S_PUR:
	     if (record->event.pressed)
		{
	     register_code(KC_LSFT);
		 register_code(KC_RCTL);
		 wait_ms(25);
		 unregister_code(KC_LSFT); 
		 unregister_code(KC_RCTL);
		 wait_ms(25);	
		register_code(KC_3);
	    }
	  else
	    {
		unregister_code(KC_3);
		}
		return false;
case S_GRN:
	     if (record->event.pressed)
		{
	     register_code(KC_LSFT);
		 register_code(KC_RCTL);
		 wait_ms(25);
		 unregister_code(KC_LSFT); 
		 unregister_code(KC_RCTL);
		 wait_ms(25);	
		register_code(KC_4);
	    }
	  else
	    {
		unregister_code(KC_4);
		}
		return false;
case S_BLU:
	     if (record->event.pressed)
		{
	     register_code(KC_LSFT);
		 register_code(KC_RCTL);
		 wait_ms(25);
		 unregister_code(KC_LSFT); 
		 unregister_code(KC_RCTL);
		 wait_ms(25);	
		register_code(KC_1);
	    }
	  else
	    {
		unregister_code(KC_1);
		}
		return false;
case S_YEL:
	     if (record->event.pressed)
		{
	     register_code(KC_LSFT);
		 register_code(KC_RCTL);
		 wait_ms(25);
		 unregister_code(KC_LSFT); 
		 unregister_code(KC_RCTL);
		 wait_ms(25);	
		register_code(KC_6);
	    }
	  else
	    {
		unregister_code(KC_6);
		}
		return false;
	}
	return true; 
}
	 
//Enable red, green and blue LEDS.
//Turn On internal Power LED.
// Set BMC64 Pins as Inputs

void keyboard_pre_init_user(void) {

	setPinOutput(red_led);
    setPinOutput(green_led);
    setPinOutput(blue_led);
	setPinOutput(power_led);
        
    setLedOff(red_led);
    setLedOn(green_led);
    setLedOff(blue_led);
	writePinHigh(power_led);

 
    setPinInput(bmc64_p0);
    setPinInput(bmc64_p1);
    setPinInput(bmc64_p2);

}

//Change RGB LED according which Layer is On.

layer_state_t layer_state_set_user(layer_state_t state) {

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
case ZX: //yellow
    setLedOn(red_led);
    setLedOn(green_led);
    setLedOff(blue_led);
    break;
case CKEY_ZX: //white
    setLedOn(red_led);
    setLedOn(green_led);
    setLedOn(blue_led);
    break;
case RSFT_ZX: //red
    setLedOn(red_led);
    setLedOff(green_led);
    setLedOff(blue_led);
    break;
case CKEY_SHFT_ZX: //OFF
    setLedOff(red_led);
    setLedOff(green_led);
    setLedOff(blue_led);
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


void matrix_scan_user(void)
{
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
