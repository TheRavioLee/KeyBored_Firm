/*
 * interfaceDeboucing.c
 *
 *  Created on: May 6, 2025
 *      Author: Thomas
 */

//INCLUDES
#include "main.h"
#include <stdbool.h>
#include "interfaceMatrice.h"
#include "interfaceDebouncing.h"


KeyState matriceDebouncing[NUM_ROWS][NUM_COLS];

//Definitions fonctions publiques
void debounce_switch_matrix(void) {
    for (int row = 0; row < NUM_ROWS; row++) {
        for (int col = 0; col < NUM_COLS; col++) {
            bool physicalState = matrice[row][col];
            KeyState *key = &matriceDebouncing[row][col];

            switch (key->state) {
                case IDLE:
                    if (physicalState) {
                        key->state = BOUNCE_PRESS;
                        key->debounce_counter = 0;
                    }
                    break;
                case BOUNCE_PRESS:
                    if (physicalState) {
                        if (++key->debounce_counter >= DEBOUNCE_TIME_MS) {
                            key->state = PRESSED;
                        }
                    } else {
                        key->state = IDLE;
                    }
                    break;
                case PRESSED:
                    if (!physicalState) {
                        key->state = BOUNCE_RELEASE;
                        key->debounce_counter = 0;
                    }
                    break;
                case BOUNCE_RELEASE:
                    if (!physicalState) {
                        if (++key->debounce_counter >= DEBOUNCE_TIME_MS) {
                            key->state = IDLE;
                        }
                    } else {
                        key->state = PRESSED;
                    }
                    break;
            }
        }
    }
}
