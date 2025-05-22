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

//Fonctions privees
void Process_KEYS(void);

void ProcessusKeys_Init(void)
{
	serviceBaseDeTemps_execute[PROCESSUS_KEYS_PHASE] = Process_KEYS;
}

void Process_KEYS(void)
{
	static bool wasActionDone = false;
	static uint8_t i = 0;
	static uint8_t last_row;
	static uint8_t last_col;

	for(int row = 0; row < NUM_ROWS; row++)
	{
		for (int col = 0; col < NUM_COLS; col++)
		{
			if(matriceDebouncing[row][col].state == PRESSED && wasActionDone == false)
			{
				i++;
				if(i > 2) { i = 0; }

				leds.phase = i;

				wasActionDone = true;
				last_row = row;
				last_col = col;
			}
		}
	}
	if(matriceDebouncing[last_row][last_col].state == IDLE && wasActionDone == true)
	{
		wasActionDone = false;
	}

}
