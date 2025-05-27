/*
 * interface_HID_Report.c
 *
 *  Created on: May 25, 2025
 *      Author: thomaslajoie
 */

#include "main.h"
#include "interface_HID_Report.h"
#include "usbd_custom_hid_if.h"

extern USBD_HandleTypeDef hUsbDeviceFS;

uint8_t nkro_report[REPORT_BYTES] = {0};

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


keyboardReportDes HIDkeyboard = {0, 0, 0, 0, 0, 0, 0, 0};



void Press_Key(uint8_t keycode)
{
//	if (keycode < 232)
//	{
//		uint8_t byte_index = keycode / 8;
//		uint8_t bit_mask = 1 << (keycode % 8);
//		nkro_report[byte_index] |= bit_mask;
//	}
	if(keycode >= 0xE0 && keycode <= 0xE7)
	{
		HIDkeyboard.MODIFIER |= keycode;
	}
	else
	{
		HIDkeyboard.KEYCODE1 = keycode;
	}
}


void Release_Key(uint8_t keycode)
{
//	if (keycode < 232)
//	{
//		uint8_t byte_index = keycode / 8;
//		uint8_t bit_mask = 1 << (keycode % 8);
//		nkro_report[byte_index] &= ~bit_mask;
//	}
	if(keycode >= 0xE0 && keycode <= 0xE7)
	{
		HIDkeyboard.MODIFIER &= ~keycode;
	}
	else
	{
		HIDkeyboard.KEYCODE1 = 0x00;
	}
}


void Send_HID_NKRO_Report(void)
{
	USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, &HIDkeyboard, sizeof(HIDkeyboard));
//	USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, nkro_report, REPORT_BYTES);

}
