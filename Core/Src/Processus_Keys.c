/*
 * Processus_Keys.c
 *
 *  Created on: May 6, 2025
 *      Author: Thomas
 */

//INCLUDES
#include "main.h"
#include <stdbool.h>
#include "interface_RGB.h"
#include "interfaceMatrice.h"
#include <interfaceDebouncing.h>
#include "ServiceBaseTemps_1ms.h"
#include "Processus_LEDS.h"
#include "interface_HID_Report.h"
#include "interface_Key_Config.h"

uint8_t hue_table[12] = { RED_HUE, ORANGE_HUE, YELLOW_HUE, LIME_HUE, GREEN_HUE, TEAL_HUE,
						CYAN_HUE, AZURE_HUE, BLUE_HUE, VIOLET_HUE, MAGENTA_HUE, ROSE_HUE };

uint8_t brightness_table[12] = { MIN_BRIGHTNESS, BRIGHTNESS1, BRIGHTNESS2, BRIGHTNESS3, BRIGHTNESS4, BRIGHTNESS5,
								BRIGHTNESS6, BRIGHTNESS7, BRIGHTNESS8, BRIGHTNESS9, BRIGHTNESS10, MAX_BRIGHTNESS};

uint8_t phase_table[5] = { LEDS_RAINBOW_PHASE, LEDS_BREATHING_PHASE, LEDS_STATIC_PHASE, LEDS_RAINBOW_BREATHING_PHASE,
							LEDS_KEY_RESPONSE_PHASE };

KeyState *key_map[64] = { &matriceDebouncing[0][0],
						&matriceDebouncing[0][1],
						&matriceDebouncing[0][2],
						&matriceDebouncing[0][3],
						&matriceDebouncing[0][4],
						&matriceDebouncing[0][5],
						&matriceDebouncing[0][6],
						&matriceDebouncing[0][7],
						&matriceDebouncing[0][8],
						&matriceDebouncing[0][9],
						&matriceDebouncing[0][10],
						&matriceDebouncing[0][11],
						&matriceDebouncing[0][12],
						&matriceDebouncing[0][13],
						&matriceDebouncing[1][0],
						&matriceDebouncing[1][1],
						&matriceDebouncing[1][2],
						&matriceDebouncing[1][3],
						&matriceDebouncing[1][4],
						&matriceDebouncing[1][5],
						&matriceDebouncing[1][6],
						&matriceDebouncing[1][7],
						&matriceDebouncing[1][8],
						&matriceDebouncing[1][9],
						&matriceDebouncing[1][10],
						&matriceDebouncing[1][11],
						&matriceDebouncing[1][12],
						&matriceDebouncing[1][13],
						&matriceDebouncing[2][0],
						&matriceDebouncing[2][1],
						&matriceDebouncing[2][2],
						&matriceDebouncing[2][3],
						&matriceDebouncing[2][4],
						&matriceDebouncing[2][5],
						&matriceDebouncing[2][6],
						&matriceDebouncing[2][7],
						&matriceDebouncing[2][8],
						&matriceDebouncing[2][9],
						&matriceDebouncing[2][10],
						&matriceDebouncing[2][11],
						&matriceDebouncing[2][13],
						&matriceDebouncing[3][0],
						&matriceDebouncing[3][1],
						&matriceDebouncing[3][2],
						&matriceDebouncing[3][3],
						&matriceDebouncing[3][4],
						&matriceDebouncing[3][5],
						&matriceDebouncing[3][6],
						&matriceDebouncing[3][7],
						&matriceDebouncing[3][8],
						&matriceDebouncing[3][9],
						&matriceDebouncing[3][10],
						&matriceDebouncing[3][11],
						&matriceDebouncing[3][12],
						&matriceDebouncing[3][13],
						&matriceDebouncing[4][0],
						&matriceDebouncing[4][1],
						&matriceDebouncing[4][2],
						&matriceDebouncing[4][5],
						&matriceDebouncing[4][9],
						&matriceDebouncing[4][10],
						&matriceDebouncing[4][11],
						&matriceDebouncing[4][12],
						&matriceDebouncing[4][13]
};

extern

//Fonctions privees
void Process_KEYS(void);

void ProcessusKeys_Init(void)
{
	serviceBaseDeTemps_execute[PROCESSUS_KEYS_PHASE] = Process_KEYS;
}

void Process_KEYS(void)
{
//	static bool wasActionDone = false;
//	static uint8_t i = 0;
//	static uint8_t last_key;

	for(int key_index = 0; key_index < NUM_KEYS; key_index++)
	{
		if(key_map[key_index]->state == PRESSED && key_index != 61/*&& wasActionDone == false*/)
		{
//			i++;
//			if(i > 11) { i = 0; }
//			leds.position = key_index;
////			leds.phase = phase_table[i];
////			leds.hue = hue_table[i];
			uint8_t keycode_press;
//
//			if(key_map[61]->state == PRESSED)
//			{
//				keycode_press = default_keycodes_map[FN_LAYER][key_index];
//			}
//			else
//			{
				keycode_press = default_keycodes_map[BASE_LAYER][key_index];
//			}
			Press_Key(keycode_press);

//			wasActionDone = true;
//			last_key = key_index;
		}
		else if(key_map[key_index]->state == IDLE && key_index != 61/*&& wasActionDone == true*/)
		{
			uint8_t keycode_release;
//
			keycode_release = default_keycodes_map[BASE_LAYER][key_index];
//
			Release_Key(keycode_release);
//
//			keycode_release = default_keycodes_map[FN_LAYER][key_index];
//
//			Release_Key(keycode_release);

//			wasActionDone = false;
//			leds.position = 65; //release LED
//			wasActionDone = true;
		}
	}

	Send_HID_NKRO_Report();

}
