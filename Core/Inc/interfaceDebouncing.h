/*
 * interfaceDeboucing.h
 *
 *  Created on: May 6, 2025
 *      Author: Thomas
 */

#ifndef INC_INTERFACEDEBOUCING_H_
#define INC_INTERFACEDEBOUCING_H_

#include "main.h"

//Definition publique
typedef enum {
    IDLE,
    BOUNCE_PRESS,
    PRESSED,
    BOUNCE_RELEASE
} DebounceState;

typedef struct {
    DebounceState state;
    uint8_t debounce_counter;
} KeyState;

void InterfaceDebouncing_Init(void);
//Fonctions publiques
void Debounce_Switch_Matrix(void);

//Variables publiques
extern KeyState matriceDebouncing[NUM_ROWS][NUM_COLS];

#endif /* INC_INTERFACEDEBOUCING_H_ */
