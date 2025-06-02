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
#define R_ALT_KEY 59

#define ID_CONFIG_2_FN 0x03
#define ID_CONFIG_2_ALT 0x04
#define ID_CONFIG_3_FN 0x05
#define ID_CONFIG_3_ALT 0x06

#define CONFIG_2_FN_FLASH_ADDRESS 0x0801E000U
#define CONFIG_2_ALT_FLASH_ADDRESS 0x0801E800U
#define CONFIG_3_FN_FLASH_ADDRESS 0x0801F000U
#define CONFIG_3_ALT_FLASH_ADDRESS 0x0801F800U

#define FLASH_ARRAY_SIZE 64U // config = 64 bytes


extern uint8_t config2_keycodes_map[KEYBOARD_LAYERS][NUM_KEYS];
extern uint8_t config3_keycodes_map[KEYBOARD_LAYERS][NUM_KEYS];


void Write_KeyConfig_To_Flash(uint32_t flash_address, uint8_t *buffer);
void Read_KeyConfig_From_Flash(uint32_t flash_address, uint8_t config_id);
uint8_t Get_Active_Keycode(uint8_t layer, uint8_t key_index);
void Key_Config_Init(void);


#endif /* INC_INTERFACE_KEY_CONFIG_H_ */
