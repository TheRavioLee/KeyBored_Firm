/*
 * interface_RGB.h
 *
 *  Created on: May 10, 2025
 *      Author: thomaslajoie
 */

#ifndef INC_INTERFACE_RGB_H_
#define INC_INTERFACE_RGB_H_

#include "Processus_LEDS.h" // pour inclusion LEDS struct

#define MAX_BRIGHTNESS 120
#define MIN_BRIGHTNESS 0
#define BRIGHTNESS1 10
#define BRIGHTNESS2 20
#define BRIGHTNESS3 30
#define BRIGHTNESS4 40
#define BRIGHTNESS5 50
#define BRIGHTNESS6 60
#define BRIGHTNESS7 70
#define BRIGHTNESS8 80
#define BRIGHTNESS9 90
#define BRIGHTNESS10 100

#define RED_HUE 0
#define ORANGE_HUE 15
#define YELLOW_HUE 30
#define LIME_HUE 50
#define GREEN_HUE 85
#define TEAL_HUE 100
#define CYAN_HUE 120
#define AZURE_HUE 140
#define BLUE_HUE 160
#define VIOLET_HUE 190
#define MAGENTA_HUE 200
#define ROSE_HUE 220

//Fonctions publiques
uint32_t hsl_to_rgb(uint8_t h, uint8_t s, uint8_t l);

void effet_Rainbow(LEDS led_param);
void effet_StaticColor(LEDS led_param);
void effet_Breathing(LEDS led_param);
void effet_Rainbow_Breathing(LEDS led_param);
void effet_Key_Responsive(LEDS led_param);

#endif /* INC_INTERFACE_RGB_H_ */
