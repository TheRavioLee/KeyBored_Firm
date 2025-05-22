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
#include "ServiceBaseTemps_1ms.h"

bool matrice[NUM_ROWS][NUM_COLS];

void ScanMatrice(void)
{
	Set_All_Rows();

	for (int row = 0; row < NUM_ROWS; row++)
	{
		Reset_Row(row);

		for(int col = 0; col < NUM_COLS; col++)
		{
			matrice[row][col] = (Read_Col(col) == 0) ? 1 : 0;
		}

		Set_Row(row);
	}
}

void InterfaceMatrice_Init(void)
{
	serviceBaseDeTemps_execute[SCAN_MATRICE_PHASE] = ScanMatrice;
}
