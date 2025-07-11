/*
 * Processus_LEDS.h
 *
 *  Created on: May 21, 2025
 *      Author: thomaslajoie
 */

#ifndef INC_PROCESSUS_LEDS_H_
#define INC_PROCESSUS_LEDS_H_
#include <stdbool.h>

#define PROCESSUS_LEDS_NB_PHASE 5
#define LEDS_RAINBOW_PHASE 0
#define LEDS_BREATHING_PHASE 1
#define LEDS_STATIC_PHASE 2
#define LEDS_RAINBOW_BREATHING_PHASE 3
#define LEDS_KEY_RESPONSE_PHASE 4

void LEDS_Increase_Brightness(void);
void LEDS_Decrease_Brightness(void);
void LEDS_Cycle_Hue(void);
void LEDS_Cycle_Effect(void);
void ProcessusLEDS_init(void);

typedef struct
{
	uint8_t hue;
	uint8_t brightness;
	uint8_t phase;
	bool position[64];
} LEDS;

extern LEDS leds;


extern void (*Processus_LEDS_execute[PROCESSUS_LEDS_NB_PHASE])(LEDS led_param);


#endif /* INC_PROCESSUS_LEDS_H_ */
