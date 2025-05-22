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

	if(matriceDebouncing[4][5].state == PRESSED && wasActionDone == false)
	{
		i++;
		if(i > 2) { i = 0; }

		leds.phase = i;

		wasActionDone = true;
	}
	if(matriceDebouncing[4][5].state == IDLE && wasActionDone == true)
	{
		wasActionDone = false;
	}

}
