/*
 * interfaceMatrice.c
 *
 *  Created on: May 6, 2025
 *      Author: Thomas
 */

//INCLUDES
#include "main.h"
#include <stdbool.h>
#include "interfaceMatrice.h"
#include "pilote_ROW.h"
#include "pilote_COL.h"

bool matrice[NUM_ROWS][NUM_COLS];

//Definition fonctions publiques
void ScanMatrice(void)
{
	for(int col = 0; col < NUM_COLS; col++)
	{
		Set_Column(col);

		for(int row = 0; row < NUM_ROWS; row++)
		{
			matrice[row][col] = Read_Row(row);
		}

		Reset_Column(col);
	}
}
