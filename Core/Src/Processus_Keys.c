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
#include "Processus_Keys.h"
#include "Processus_LEDS.h"
#include "interface_HID_Report.h"
#include "interface_Key_Config.h"

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

keyboardReportDes lastHIDkeyboard = {0, 0, 0, 0, 0, 0, 0, 0};

//Fonctions privees
void Process_KEYS(void);

void ProcessusKeys_Init(void)
{
	serviceBaseDeTemps_execute[PROCESSUS_KEYS_PHASE] = Process_KEYS;
}

void Process_KEYS(void)
{
	static uint8_t howManyKeysPressed = 0;
	static bool lastActionDone[64];

	Reset_HID_Report();

	for(int key_index = 0; key_index < NUM_KEYS; key_index++)
	{
		if(key_map[key_index]->state == PRESSED)
		{
			howManyKeysPressed++;
			if(howManyKeysPressed > 6)
			{
				//DO NOTHING
			}
			else
			{
				switch(key_map[60]->state)
				{
				case PRESSED:
					switch(key_index)
					{
					case UP_KEY:
						if(lastActionDone[UP_KEY] == false)
						{ LEDS_Increase_Brightness(); }
						break;
					case DOWN_KEY:
						if(lastActionDone[DOWN_KEY] == false)
						{ LEDS_Decrease_Brightness(); }
						break;
					case LEFT_KEY:
						if(lastActionDone[LEFT_KEY] == false)
						{ LEDS_Cycle_Hue(); }
						break;
					case RIGHT_KEY:
						if(lastActionDone[RIGHT_KEY] == false)
						{ LEDS_Cycle_Effect(); }
					default:
						Make_HID_Report(default_keycodes_map[FN_LAYER][key_index], howManyKeysPressed);
						break;
					}
					break;
				case IDLE:
					Make_HID_Report(default_keycodes_map[BASE_LAYER][key_index], howManyKeysPressed);
					break;
				default:
					//DO NOTHING IF FN_KEY BOUNCING
					break;
				}
			}
			lastActionDone[key_index] = true;
			leds.position[key_index] = true;
		}
		else
		{
			lastActionDone[key_index] = false;
			leds.position[key_index] = false;
		}
	}

	if(!Check_HID_Report(lastHIDkeyboard))
	{
		Send_HID_Report();
	}

	lastHIDkeyboard = HIDkeyboard;
	howManyKeysPressed = 0;
}
