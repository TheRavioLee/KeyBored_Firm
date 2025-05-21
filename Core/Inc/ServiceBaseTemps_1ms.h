/*
 * ServiceBaseTemps_1ms.h
 *
 *  Created on: May 21, 2025
 *      Author: thomaslajoie
 */

#ifndef INC_SERVICEBASETEMPS_1MS_H_
#define INC_SERVICEBASETEMPS_1MS_H_


void serviceBaseDeTemps_initialise(void);

//Variables publiques:
extern void (*serviceBaseDeTemps_execute[SERVICEBASEDETEMPS_NOMBRE_DE_PHASES])(void);

#endif /* INC_SERVICEBASETEMPS_1MS_H_ */
