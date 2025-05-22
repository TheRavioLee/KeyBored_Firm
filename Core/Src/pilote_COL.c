/*
 * pilote_COL.c
 *
 *  Created on: May 6, 2025
 *      Author: Thomas Lajoie
 */

//INCLUDES
#include "main.h"
#include <stdbool.h>
#include "pilote_COL.h"


uint16_t col_pin[NUM_COLS] = { COL1, COL2, COL3, COL4, COL5, COL6, COL7, COL8, COL9,
							COL10, COL11, COL12, COL13, COL14 };

bool Read_Col(uint16_t col_index)
{
	return HAL_GPIO_ReadPin(COL_PORT, col_pin[col_index]);
}
