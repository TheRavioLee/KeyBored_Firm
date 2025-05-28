/*
 * interface_HID_Report.h
 *
 *  Created on: May 25, 2025
 *      Author: thomaslajoie
 */

#ifndef INC_INTERFACE_HID_REPORT_H_
#define INC_INTERFACE_HID_REPORT_H_

#include <stdbool.h>

typedef struct {
	uint8_t MODIFIER;
	uint8_t RESERVED;
	uint8_t KEYCODE1;
	uint8_t KEYCODE2;
	uint8_t KEYCODE3;
	uint8_t KEYCODE4;
	uint8_t KEYCODE5;
	uint8_t KEYCODE6;
}keyboardReportDes;

extern keyboardReportDes HIDkeyboard;

bool Check_HID_Report(keyboardReportDes lastReport);
void Make_HID_Report(uint8_t keycode, uint8_t position);
void Reset_HID_Report(void);
void Send_HID_Report(void);


#endif /* INC_INTERFACE_HID_REPORT_H_ */
