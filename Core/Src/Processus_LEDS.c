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

void Process_LEDS(void)
{
	static uint8_t compteur_LEDS;

	compteur_LEDS++;

	if(compteur_LEDS > 30)
	{
		Processus_LEDS_execute[leds.phase](leds.hue, leds.brightness);
		compteur_LEDS = 0;
	}
}

//Variables publiques
void (*Processus_LEDS_execute[PROCESSUS_LEDS_NB_PHASE])(uint8_t hue, uint8_t brightness);

LEDS leds;

//Fonctions publiques
void ProcessusLEDS_init(void)
{
  serviceBaseDeTemps_execute[PROCESSUS_LEDS_PHASE] = Process_LEDS;
  Processus_LEDS_execute[LEDS_RAINBOW_PHASE] = effet_Rainbow;
  Processus_LEDS_execute[LEDS_BREATHING_PHASE] = effet_Breathing;
  Processus_LEDS_execute[LEDS_STATIC_PHASE] = effet_StaticColor;
  leds.hue = ORANGE_HUE;
  leds.phase = LEDS_STATIC_PHASE;
  leds.brightness = 20;
}




