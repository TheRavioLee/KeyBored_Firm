/*
 * pilote_ROW.c
 *
 *  Created on: May 6, 2025
 *      Author: Thomas Lajoie
 */

//INCLUDES
#include "main.h"
#include <stdbool.h>
#include "pilote_ROW.h"

uint16_t row_pin[NUM_ROWS] = { ROW1, ROW2, ROW3, ROW4, ROW5};

bool Read_Row(uint16_t row_index)
{
	return HAL_GPIO_ReadPin(ROW_PORT, row_index);
}
