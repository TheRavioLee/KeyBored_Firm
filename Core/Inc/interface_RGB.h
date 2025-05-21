/*
 * interface_RGB.h
 *
 *  Created on: May 10, 2025
 *      Author: thomaslajoie
 */

#ifndef INC_INTERFACE_RGB_H_
#define INC_INTERFACE_RGB_H_

//Fonctions publiques
uint32_t hsl_to_rgb(uint8_t h, uint8_t s, uint8_t l);
void effet_Rainbow(uint8_t l);
void staticColor(uint8_t hue, uint8_t sat, uint8_t brightness);
void staticColorRGB(uint8_t red, uint8_t green, uint8_t blue);
void effet_Touche_reactif(uint8_t hue, uint8_t sat, uint8_t brightness, uint8_t led_index);

void effet_Breathing();
void effet_RainbowSwirl(uint8_t brightness);

#endif /* INC_INTERFACE_RGB_H_ */
