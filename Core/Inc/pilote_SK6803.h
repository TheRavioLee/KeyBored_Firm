/*
 * SK6803.h
 *
 *  Created on: May 10, 2025
 *      Author: thomaslajoie
 */

#ifndef INC_PILOTE_SK6803_H_
#define INC_PILOTE_SK6803_H_

#include <stdint.h>

extern TIM_HandleTypeDef htim2;
extern DMA_HandleTypeDef hdma_tim2_ch1;

//Definitions publiques
#define PWM_HI 38
#define PWM_LO 19

//Parametres LED
#define BYTES_PER_LED 3
#define LED_CNT 64
#define TOTAL_BYTES (BYTES_PER_LED * LED_CNT)

#define WR_BUF_LEN (BYTES_PER_LED * 8 * 2)


//Fonctions publiques
void led_set_RGB(uint8_t index, uint8_t r, uint8_t g, uint8_t b);
void led_set_all_RGB(uint8_t r, uint8_t g, uint8_t b);
void led_render();

#endif /* INC_PILOTE_SK6803_H_ */
