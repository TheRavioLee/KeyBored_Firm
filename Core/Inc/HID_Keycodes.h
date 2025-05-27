/*
 * HID_Keycodes.h
 *
 *  Created on: May 26, 2025
 *      Author: thomaslajoie
 */

#ifndef INC_HID_KEYCODES_H_
#define INC_HID_KEYCODES_H_


#define KC_NONE 0x00
//LETTERS
#define KC_A 0x04 //aA
#define KC_B 0x05 //bB
#define KC_C 0x06 //cC
#define KC_D 0x07 //dD
#define KC_E 0x08 //eE
#define KC_F 0x09 //fF
#define KC_G 0x0A //gG
#define KC_H 0x0B //hH
#define KC_I 0x0C //iI
#define KC_J 0x0D //jJ
#define KC_K 0x0E //kK
#define KC_L 0x0F //lL
#define KC_M 0x10 //mM
#define KC_N 0x11 //nN
#define KC_O 0x12 //oO
#define KC_P 0x13 //pP
#define KC_Q 0x14 //qQ
#define KC_R 0x15 //rR
#define KC_S 0x16 //sS
#define KC_T 0x17 //tT
#define KC_U 0x18 //uU
#define KC_V 0x19 //vV
#define KC_W 0x1A //wW
#define KC_X 0x1B //xX
#define KC_Y 0x1C //yY
#define KC_Z 0x1D //zZ

//NUMBERS / SYMBOLS / F1-F12 / MISC
#define KC_1 0x1E //1!
#define KC_2 0x1F //2@
#define KC_3 0x20 //3#
#define KC_4 0x21 //4$
#define KC_5 0x22 //5%
#define KC_6 0x23 //6^
#define KC_7 0x24 //7&
#define KC_8 0x25 //8*
#define KC_9 0x26 //9(
#define KC_0 0x27 //0)

#define KC_ENTER 0x28
#define KC_ESC 0x29
#define KC_BACKSPACE 0x2A
#define KC_TAB 0x2B
#define KC_SPACE 0x2C
#define KC_DASH 0x2D //-_
#define KC_EQUALS 0x2E // =+
#define KC_OPEN_BRACKET 0x2F //[{
#define KC_CLOSE_BRACKET 0x30 //]}
#define KC_BACKSLASH 0x31 //\|
#define KC_NON_US_HASTAG 0x32 //for NON US keyboard #~ remapped in host OS, DO NOT USE
#define KC_SEMICOLON 0x33 //;:
#define KC_QUOTE 0x34 //' "
#define KC_GRAVE_TILDE 0x35 // `~  REMAPPED ON NON-US LANGUAGE
#define KC_COMMA 0x36 // ,<
#define KC_DOT 0x37 //.>
#define KC_SLASH 0x38 // /?
#define KC_CAPSLOCK 0x39 // CAPSLOCK
#define KC_F1 0x3A //F1
#define KC_F2 0x3B //F2
#define KC_F3 0x3C //F3
#define KC_F4 0x3D //F4
#define KC_F5 0x3E //F5
#define KC_F6 0x3F //F6
#define KC_F7 0x40 //F7
#define KC_F8 0x41 //F8
#define KC_F9 0x42 //F9
#define KC_F10 0x43 //F10
#define KC_F11 0x44 //F11
#define KC_F12 0x45 //F12
#define KC_PRNTSCRN 0x46 //PrintScreen
#define KC_SCROLL_LOCK 0x47 //Scroll lock
#define KC_PAUSE 0x48 //PAUSE
#define KC_INSERT 0x49 //INS
#define KC_HOME 0x4A // HOME
#define KC_PAGEUP 0x4B //PAGEUP
#define KC_DEL_FORWARD 0x4C //Delete forward
#define KC_END 0x4D // END
#define KC_PAGEDOWN 0x4E //PAGEDOWN
#define KC_RIGHT_ARROW 0x4F //
#define KC_LEFT_ARROW 0x50 //
#define KC_DOWN_ARROW 0x51 //
#define KC_UP_ARROW 0x52 //

/*
 * SKIPPED KEYPAD CODES
 */

//MODIFIERS
#define KC_LCTRL 0xE0 // LEFT CTRL
#define KC_LSHIFT 0xE1 // LEFT SHIFT
#define KC_LALT 0xE2 // LEFT ALT
#define KC_LSUPER 0xE3 //LEFT SUPER/WIN
#define KC_RCTRL 0xE4 // RIGHT CTRL
#define KC_RSHIFT 0xE5	// RIGHT SHIFT
#define KC_RALT 0xE6 // RIGHT ALT
#define KC_RSUPER 0xE7 // RIGHT SUPER/WIN

#endif /* INC_HID_KEYCODES_H_ */
