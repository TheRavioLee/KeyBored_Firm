/*
 * interface_Key_Config.c
 *
 *  Created on: May 25, 2025
 *      Author: thomaslajoie
 */

#include "main.h"
#include "interface_Key_Config.h"

uint8_t default_keycodes_map[KEYBOARD_LAYERS][NUM_KEYS] = {
		{
				KC_ESC,
				KC_1,
				KC_2,
				KC_3,
				KC_4,
				KC_5,
				KC_6,
				KC_7,
				KC_8,
				KC_9,
				KC_0,
				KC_DASH,
				KC_EQUALS,
				KC_BACKSPACE,
				KC_TAB,
				KC_Q,
				KC_W,
				KC_E,
				KC_R,
				KC_T,
				KC_Y,
				KC_U,
				KC_I,
				KC_O,
				KC_P,
				KC_OPEN_BRACKET,
				KC_CLOSE_BRACKET,
				KC_BACKSLASH,
				KC_CAPSLOCK,
				KC_A,
				KC_S,
				KC_D,
				KC_F,
				KC_G,
				KC_H,
				KC_J,
				KC_K,
				KC_L,
				KC_SEMICOLON,
				KC_QUOTE,
				KC_ENTER,
				KC_LSHIFT,
				KC_Z,
				KC_X,
				KC_C,
				KC_V,
				KC_B,
				KC_N,
				KC_M,
				KC_COMMA,
				KC_DOT,
				KC_SLASH,
				KC_RSHIFT,
				KC_UP_ARROW,
				KC_DEL_FORWARD,
				KC_LCTRL,
				KC_LSUPER,
				KC_LALT,
				KC_SPACE,
				KC_RALT,
				KC_NONE,
				KC_LEFT_ARROW,
				KC_DOWN_ARROW,
				KC_RIGHT_ARROW
		},
		{
				KC_GRAVE_TILDE,
				KC_F1,
				KC_F2,
				KC_F3,
				KC_F4,
				KC_F5,
				KC_F6,
				KC_F7,
				KC_F8,
				KC_F9,
				KC_F10,
				KC_F11,
				KC_F12,
				KC_DEL_FORWARD,
				KC_NONE,
				KC_NONE,
				KC_NONE,
				KC_NONE,
				KC_NONE,
				KC_NONE,
				KC_NONE,
				KC_NONE,
				KC_NONE,
				KC_NONE,
				KC_NONE,
				KC_NONE,
				KC_NONE,
				KC_NONE,
				KC_NONE,
				KC_NONE,
				KC_NONE,
				KC_NONE,
				KC_NONE,
				KC_NONE,
				KC_NONE,
				KC_NONE,
				KC_NONE,
				KC_NONE,
				KC_NONE,
				KC_NONE,
				KC_NONE,
				KC_NONE,
				KC_NONE,
				KC_NONE,
				KC_NONE,
				KC_NONE,
				KC_NONE,
				KC_NONE,
				KC_NONE,
				KC_NONE,
				KC_NONE,
				KC_NONE,
				KC_NONE,
				KC_NONE,
				KC_NONE,
				KC_NONE,
				KC_NONE,
				KC_NONE,
				KC_NONE,
				KC_NONE,
				KC_NONE,
				KC_NONE,
				KC_NONE,
				KC_NONE
		},
		{}
};
//#define FLASH_KEYMAP_ADDR  ((uint32_t)0x0800F800) // Last 2KB sector of 64KB Flash
//
//void Write_New_Config(uint8_t key, uint8_t config, uint8_t page)
//{
//
//}
//
//
//bool Check_Existing_Config(uint8_t page)
//{
//	switch(page)
//	{
//	case 1:
//		break;
//	case 2:
//		break;
//	case 3:
//		break;
//	}
//}
//
//
//uint8_t Get_Config_Page(void)
//{
//
//}
//
//
//
//void Write_Keymap_To_Flash(uint8_t* data, uint16_t length) {
//    HAL_FLASH_Unlock();
//
//    // Erase the last page
//    FLASH_EraseInitTypeDef eraseInit;
//    uint32_t pageError;
//    eraseInit.TypeErase = FLASH_TYPEERASE_PAGES;
//    eraseInit.PageAddress = FLASH_KEYMAP_ADDR;
//    eraseInit.NbPages = 1;
//    if (HAL_FLASHEx_Erase(&eraseInit, &pageError) != HAL_OK) {
//        HAL_FLASH_Lock();
//        return;
//    }
//
//    // Write data
//    for (uint32_t i = 0; i < length; i += 2) {
//        uint16_t val = data[i] | (data[i+1] << 8);
//        HAL_FLASH_Program(FLASH_TYPEPROGRAM_HALFWORD, FLASH_KEYMAP_ADDR + i, val);
//    }
//
//    HAL_FLASH_Lock();
//}
//
//
//void Load_Keymap_From_Flash(void)
//{
//
//}
//
//
//void Interface_Key_Init(void)
//{
//	uint8_t keymap[KEYMAP_SIZE];
//	memcpy(keymap, (uint8_t*)FLASH_KEYMAP_ADDR, KEYMAP_SIZE);
//
//}
