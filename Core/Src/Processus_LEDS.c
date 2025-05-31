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

uint8_t hue_table[12] = { RED_HUE, ORANGE_HUE, YELLOW_HUE, LIME_HUE, GREEN_HUE, TEAL_HUE,
						CYAN_HUE, AZURE_HUE, BLUE_HUE, VIOLET_HUE, MAGENTA_HUE, ROSE_HUE };

uint8_t brightness_table[12] = { MIN_BRIGHTNESS, BRIGHTNESS1, BRIGHTNESS2, BRIGHTNESS3, BRIGHTNESS4, BRIGHTNESS5,
								BRIGHTNESS6, BRIGHTNESS7, BRIGHTNESS8, BRIGHTNESS9, BRIGHTNESS10, MAX_BRIGHTNESS};

uint8_t phase_table[5] = { LEDS_RAINBOW_PHASE, LEDS_BREATHING_PHASE, LEDS_STATIC_PHASE, LEDS_RAINBOW_BREATHING_PHASE,
							LEDS_KEY_RESPONSE_PHASE };

uint8_t brightness_index = 11; //MAX_BRIGHTNESS default
uint8_t hue_index = 0;	//RED_HUE default
uint8_t phase_index = 0;	//RAINBOW_PHASE default

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
void LEDS_Increase_Brightness(void)
{
	if(brightness_index < 11)
	{ brightness_index++; }
	leds.brightness = brightness_table[brightness_index];
}

void LEDS_Decrease_Brightness(void)
{
	if(brightness_index > 0)
	{ brightness_index--; }
	leds.brightness = brightness_table[brightness_index];
}

void LEDS_Cycle_Hue(void)
{
	hue_index++;
	if(hue_index > 11)
	{ hue_index = 0; }
	leds.hue = hue_table[hue_index];
}

void LEDS_Cycle_Effect(void)
{
	phase_index++;
	if(phase_index > 4)
	{ phase_index = 0; }
	leds.phase = phase_table[phase_index];
}


void ProcessusLEDS_init(void)
{
  serviceBaseDeTemps_execute[PROCESSUS_LEDS_PHASE] = Process_LEDS;
  Processus_LEDS_execute[LEDS_RAINBOW_PHASE] = effet_Rainbow;
  Processus_LEDS_execute[LEDS_BREATHING_PHASE] = effet_Breathing;
  Processus_LEDS_execute[LEDS_STATIC_PHASE] = effet_StaticColor;
  Processus_LEDS_execute[LEDS_RAINBOW_BREATHING_PHASE] = effet_Rainbow_Breathing;
  Processus_LEDS_execute[LEDS_KEY_RESPONSE_PHASE] = effet_Key_Responsive;

  leds.hue = hue_table[hue_index];
  leds.phase = phase_table[phase_index];
  leds.brightness = brightness_table[brightness_index];
  for(int i = 0; i < 64; i++)
  { leds.position[i] = false; }
}




