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

#define FN_KEY 60

#define CONFIG_2_FLASH_ADDRESS
#define CONFIG_3_FLASH_ADDRESS


extern uint8_t config2_keycodes_map[KEYBOARD_LAYERS][NUM_KEYS];
extern uint8_t config3_keycodes_map[KEYBOARD_LAYERS][NUM_KEYS];


void Write_KeyConfig_To_Flash(void);
void Read_KeyConfig_From_Flash(void);
void ParseFullBuffer(uint8_t *buffer);
uint8_t Get_Active_Keycode(uint8_t layer, uint8_t key_index);
void Key_Config_Init(void);


#endif /* INC_INTERFACE_KEY_CONFIG_H_ */
