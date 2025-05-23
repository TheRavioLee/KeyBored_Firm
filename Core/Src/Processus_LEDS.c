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

	if(compteur_LEDS > 30)//update 30ms = ~30fps
	{
		Processus_LEDS_execute[leds.phase](leds);
		compteur_LEDS = 0;
	}
}

//Variables publiques
void (*Processus_LEDS_execute[PROCESSUS_LEDS_NB_PHASE])(LEDS led_param);

LEDS leds;

//Fonctions publiques
void ProcessusLEDS_init(void)
{
  serviceBaseDeTemps_execute[PROCESSUS_LEDS_PHASE] = Process_LEDS;
  Processus_LEDS_execute[LEDS_RAINBOW_PHASE] = effet_Rainbow;
  Processus_LEDS_execute[LEDS_BREATHING_PHASE] = effet_Breathing;
  Processus_LEDS_execute[LEDS_STATIC_PHASE] = effet_StaticColor;
  Processus_LEDS_execute[LEDS_RAINBOW_BREATHING_PHASE] = effet_Rainbow_Breathing;
  Processus_LEDS_execute[LEDS_KEY_RESPONSE_PHASE] = effet_Key_Responsive;
  leds.hue = RED_HUE;
  leds.phase = LEDS_KEY_RESPONSE_PHASE;
  leds.brightness = MAX_BRIGHTNESS;
  leds.position = 65;
}




