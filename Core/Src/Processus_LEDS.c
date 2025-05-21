/*
 * Processus_LEDS.c
 *
 *  Created on: May 21, 2025
 *      Author: thomaslajoie
 */

#include "main.h"
#include "interface_RGB.h"
#include "Processus_LEDS.h"
#include "ServiceBaseTemps_1ms.h"

//Fonctions privees
void Process_LEDS(void);



void Process_LEDS_init(void)
{
  serviceBaseDeTemps_execute[PROCESSUS_LEDS_PHASE] = Process_LEDS;
}

void Process_LEDS(void)
{
	static uint8_t compteur_LEDS;

	compteur_LEDS++;

	if(compteur_LEDS > 30)
	{
		effet_Rainbow(10);
		compteur_LEDS = 0;
	}
}
