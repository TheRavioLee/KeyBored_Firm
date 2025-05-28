/*
 * interface_HID_Report.c
 *
 *  Created on: May 25, 2025
 *      Author: thomaslajoie
 */

#include "main.h"
#include "interface_HID_Report.h"
#include "usbd_hid.h"

extern USBD_HandleTypeDef hUsbDeviceFS;

keyboardReportDes HIDkeyboard = {0, 0, 0, 0, 0, 0, 0, 0};

void Reset_HID_Report(void)
{
	HIDkeyboard.MODIFIER = 0;
	HIDkeyboard.KEYCODE1 = 0;
	HIDkeyboard.KEYCODE2 = 0;
	HIDkeyboard.KEYCODE3 = 0;
	HIDkeyboard.KEYCODE4 = 0;
	HIDkeyboard.KEYCODE5 = 0;
	HIDkeyboard.KEYCODE6 = 0;
}

bool Check_HID_Report(keyboardReportDes lastReport)
{
	if(lastReport.MODIFIER == HIDkeyboard.MODIFIER && lastReport.KEYCODE1 == HIDkeyboard.KEYCODE1 && lastReport.KEYCODE2 == HIDkeyboard.KEYCODE2
			&& lastReport.KEYCODE3 == HIDkeyboard.KEYCODE3 && lastReport.KEYCODE4 == HIDkeyboard.KEYCODE4 && lastReport.KEYCODE5 == HIDkeyboard.KEYCODE5
			&& lastReport.KEYCODE6 == HIDkeyboard.KEYCODE6)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Make_HID_Report(uint8_t keycode, uint8_t position)
{

	if(keycode >= 0xE0 && keycode <= 0xE7)
	{
		switch(keycode)
		{
		case 0xE0:
			HIDkeyboard.MODIFIER |= 0x01;
			break;
		case 0xE1:
			HIDkeyboard.MODIFIER |= 0x02;
			break;
		case 0xE2:
			HIDkeyboard.MODIFIER |= 0x04;
			break;
		case 0xE3:
			HIDkeyboard.MODIFIER |= 0x08;
			break;
		case 0xE4:
			HIDkeyboard.MODIFIER |= 0x10;
			break;
		case 0xE5:
			HIDkeyboard.MODIFIER |= 0x20;
			break;
		case 0xE6:
			HIDkeyboard.MODIFIER |= 0x40;
			break;
		case 0xE7:
			HIDkeyboard.MODIFIER |= 0x80;
			break;
		}
	}
	else
	{
		switch(position)
		{
		case 1:
			HIDkeyboard.KEYCODE1 = keycode;
			break;
		case 2:
			HIDkeyboard.KEYCODE2 = keycode;
			break;
		case 3:
			HIDkeyboard.KEYCODE3 = keycode;
			break;
		case 4:
			HIDkeyboard.KEYCODE4 = keycode;
			break;
		case 5:
			HIDkeyboard.KEYCODE5 = keycode;
			break;
		case 6:
			HIDkeyboard.KEYCODE6 = keycode;
			break;

		}
	}
}


void Send_HID_Report(void)
{
	USBD_HID_SendReport(&hUsbDeviceFS, &HIDkeyboard, sizeof(HIDkeyboard));

}
