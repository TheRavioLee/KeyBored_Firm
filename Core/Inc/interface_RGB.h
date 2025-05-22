/*
 * interface_RGB.h
 *
 *  Created on: May 10, 2025
 *      Author: thomaslajoie
 */

#ifndef INC_INTERFACE_RGB_H_
#define INC_INTERFACE_RGB_H_

#define MAX_BRIGHTNESS 120
#define MIN_BRIGHTNESS 0
#define RED_HUE 0
#define ORANGE_HUE 20
#define YELLOW_HUE 40
#define LIME_HUE 60
#define GREEN_HUE 80
#define TEAL_HUE 100
#define CYAN_HUE 120
#define AZURE_HUE 140
#define BLUE_HUE 160
#define VIOLET_HUE 180
#define MAGENTA_HUE 200
#define ROSE_HUE 220

//Fonctions publiques
uint32_t hsl_to_rgb(uint8_t h, uint8_t s, uint8_t l);

void effet_Rainbow(uint8_t hue, uint8_t brightness);
void effet_StaticColor(uint8_t hue, uint8_t brightness);
void effet_Breathing(uint8_t hue, uint8_t brightness);

#endif /* INC_INTERFACE_RGB_H_ */
