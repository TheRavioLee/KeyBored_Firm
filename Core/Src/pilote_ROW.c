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

void Set_Row(uint16_t row_index)
{
	HAL_GPIO_WritePin(ROW_PORT, row_pin[row_index], GPIO_PIN_SET);
}

void Reset_Row(uint16_t row_index)
{
	HAL_GPIO_WritePin(ROW_PORT, row_pin[row_index], GPIO_PIN_RESET);
}

void Set_All_Rows(void)
{
	for(int i = 0; i < NUM_ROWS; i++)
	{
		Set_Row(i);
	}
}

