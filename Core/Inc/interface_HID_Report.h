/*
 * interface_HID_Report.h
 *
 *  Created on: May 25, 2025
 *      Author: thomaslajoie
 */

#ifndef INC_INTERFACE_HID_REPORT_H_
#define INC_INTERFACE_HID_REPORT_H_

#define REPORT_BYTES 29

void Press_Key(uint8_t keycode);
void Release_Key(uint8_t keycode);
void Send_HID_NKRO_Report(void);

extern uint8_t nkro_report[REPORT_BYTES];

#endif /* INC_INTERFACE_HID_REPORT_H_ */
