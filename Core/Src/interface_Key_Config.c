/*
 * interface_Key_Config.c
 *
 *  Created on: May 25, 2025
 *      Author: thomaslajoie
 */

#include "main.h"
#include "interface_Key_Config.h"

static uint8_t (*current_keycodes_map)[KEYBOARD_LAYERS][NUM_KEYS] = NULL;

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
					KC_TAB,
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
						KC_CAPSLOCK,
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
						KC_ENTER,
							KC_LSHIFT,
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
				KC_LCTRL,
				KC_LSUPER,
				KC_LALT,
				KC_NONE,
				KC_NONE,
				KC_NONE,
				KC_NONE,
				KC_NONE,
				KC_NONE
		},
		{
				KC_NONE,
				KC_BRIGHT_DOWN,
				KC_BRIGHT_UP,
				KC_NONE,
				KC_NONE,
				KC_NONE,
				KC_NONE,
				KC_PREVIOUS,
				KC_PLAY_PAUSE,
				KC_NEXT,
				KC_MUTE,
				KC_VOL_DOWN,
				KC_VOL_UP,
				KC_NONE,
					KC_TAB,
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
						KC_CAPSLOCK,
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
						KC_ENTER,
							KC_LSHIFT,
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
				KC_LCTRL,
				KC_LSUPER,
				KC_LALT,
				KC_NONE,
				KC_NONE,
				KC_NONE,
				KC_NONE,
				KC_NONE,
				KC_NONE
		}
};

uint8_t config2_keycodes_map[KEYBOARD_LAYERS][NUM_KEYS] = {
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

				},
				{

				}
};

uint8_t config3_keycodes_map[KEYBOARD_LAYERS][NUM_KEYS] = {
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

				},
				{

				}
};

void Write_KeyConfig_To_Flash(void)
{

}

void Read_KeyConfig_From_Flash(void)
{

}

void ParseFullBuffer(uint8_t *buffer)
{



}


uint8_t Get_Active_Keycode(uint8_t layer, uint8_t key_index)
{
    if (current_keycodes_map == NULL)
    {
        return default_keycodes_map[layer][key_index];
    }
    return (*current_keycodes_map)[layer][key_index];
}


void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	switch(GPIO_Pin)
	{
	case OS1:
		current_keycodes_map = &default_keycodes_map;
		break;
	case OS2:
		current_keycodes_map = &config2_keycodes_map;
		break;
	case OS3:
		current_keycodes_map = &config3_keycodes_map;
		break;
	}
}


void Key_Config_Init(void)
{
	if(!HAL_GPIO_ReadPin(OS_PORT, OS1))
	{
		current_keycodes_map = &default_keycodes_map;
	}
	if(!HAL_GPIO_ReadPin(OS_PORT, OS2))
	{
		current_keycodes_map = &config2_keycodes_map;
	}
	if(!HAL_GPIO_ReadPin(OS_PORT, OS3))
	{
		current_keycodes_map = &config3_keycodes_map;
	}
}
