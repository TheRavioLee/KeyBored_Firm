/*
 * interface_Key_Config.h
 *
 *  Created on: May 25, 2025
 *      Author: thomaslajoie
 */

#ifndef INC_INTERFACE_KEY_CONFIG_H_
#define INC_INTERFACE_KEY_CONFIG_H_

#include "HID_Keycodes.h"

#define KEYBOARD_LAYERS 3
#define BASE_LAYER 0
#define FN_LAYER 1
#define FN_RALT_LAYER 2


extern uint8_t default_keycodes_map[KEYBOARD_LAYERS][NUM_KEYS];


#endif /* INC_INTERFACE_KEY_CONFIG_H_ */
