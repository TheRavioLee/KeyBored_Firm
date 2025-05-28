/*
 * interface_RGB.c
 *
 *  Created on: May 10, 2025
 *      Author: thomaslajoie
 */

//INCLUDES
#include "main.h"

#include <math.h>
#include <stdlib.h>

#include "pilote_SK6803.h"
#include "interface_RGB.h"

const uint8_t led_map[64] = {
  // Row 1: 0-13
  0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
  // Row 2: 27-14 (reversed)
  27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14,
  // Row 3: 28-40
  28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
  // Row 4: 54-41 (reversed)
  54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41,
  // Row 5: 55-63
  55, 56, 57, 58, 59, 60, 61, 62, 63
};


uint32_t hsl_to_rgb(uint8_t h, uint8_t s, uint8_t l)
{
	if(l == 0) return 0;

	volatile uint8_t  r, g, b, lo, c, x, m;
	volatile uint16_t h1, l1, H;
	l1 = l + 1;
	if (l < 128)    c = ((l1 << 1) * s) >> 8;
	else            c = (512 - (l1 << 1)) * s >> 8;

	H = h * 6;              // 0 to 1535 (actually 1530)
	lo = H & 255;           // Low byte  = primary/secondary color mix
	h1 = lo + 1;

	if ((H & 256) == 0)   x = h1 * c >> 8;          // even sextant, like red to yellow
	else                  x = (256 - h1) * c >> 8;  // odd sextant, like yellow to green

	m = l - (c >> 1);
	switch(H >> 8) {       // High byte = sextant of colorwheel
	 case 0 : r = c; g = x; b = 0; break; // R to Y
	 case 1 : r = x; g = c; b = 0; break; // Y to G
	 case 2 : r = 0; g = c; b = x; break; // G to C
	 case 3 : r = 0; g = x; b = c; break; // C to B
	 case 4 : r = x; g = 0; b = c; break; // B to M
	 default: r = c; g = 0; b = x; break; // M to R
	}

	return (((uint32_t)r + m) << 16) | (((uint32_t)g + m) << 8) | ((uint32_t)b + m);
}


void effet_Rainbow(LEDS led_param)
{
	static int8_t angle = 0;
	const uint8_t angle_difference = 18;


	for(uint8_t i = 0; i < LED_CNT; i++)
	{
		// Set correct LED position
		uint8_t led_index = led_map[i];
		// Calculate color
		uint32_t rgb_color = hsl_to_rgb(angle + ((LED_CNT - 1 - i) * angle_difference), 255, led_param.brightness);
		// Set color
		led_set_RGB(led_index, (rgb_color >> 16) & 0xFF, (rgb_color >> 8) & 0xFF, rgb_color & 0xFF);
	}

	// Write to LED
	++angle;
	led_render();
}


void effet_Breathing(LEDS led_param)
{
    static uint8_t current_brightness = 0;
    static int8_t direction = 1;

    // Adjust brightness
    current_brightness += direction;
    if (current_brightness == MIN_BRIGHTNESS || current_brightness == /*MAX*/led_param.brightness) direction = -direction;

    // Set all LEDs to the same color with fading
    uint32_t rgb = hsl_to_rgb(led_param.hue, 255, current_brightness); // Static hue
    uint8_t r = (rgb >> 16) & 0xFF;
    uint8_t g = (rgb >> 8) & 0xFF;
    uint8_t b = rgb & 0xFF;

    led_set_all_RGB(r, g, b);
    led_render();
}


void effet_Rainbow_Breathing(LEDS led_param)
{
	static int8_t angle = 0;
	const uint8_t angle_difference = 18;

	static uint8_t current_brightness = 0;
	static int8_t direction = 1;

	// Adjust brightness
	current_brightness += direction;
	if (current_brightness == MIN_BRIGHTNESS || current_brightness == /*MAX*/led_param.brightness) direction = -direction;


	for(uint8_t i = 0; i < LED_CNT; i++)
	{
		// Set correct LED position
		uint8_t led_index = led_map[i];
		// Calculate color
		uint32_t rgb_color = hsl_to_rgb(angle + ((LED_CNT - 1 - i) * angle_difference), 255, current_brightness);
		// Set color
		led_set_RGB(led_index, (rgb_color >> 16) & 0xFF, (rgb_color >> 8) & 0xFF, rgb_color & 0xFF);
	}

	// Write to LED
	++angle;
	led_render();
}


void effet_Key_Responsive(LEDS led_param)
{
	static uint8_t current_brightness = 0;
	static int8_t direction = 1;

	// Adjust brightness
	current_brightness += direction;
	if (current_brightness == MIN_BRIGHTNESS || current_brightness == /*MAX*/led_param.brightness) direction = -direction;

	// Set all LEDs to the same color with fading
	uint32_t rgb = hsl_to_rgb(led_param.hue, 255, led_param.brightness); // Static hue
	uint8_t r = (rgb >> 16) & 0xFF;
	uint8_t g = (rgb >> 8) & 0xFF;
	uint8_t b = rgb & 0xFF;

	for(uint8_t i = 0; i < LED_CNT; i++)
	{
		uint8_t led_index = led_map[i];

		switch(leds.position[i])
		{
		case true:
			led_set_RGB(led_index, r, g, b);
			break;
		case false:
			led_set_RGB(led_index, 0, 0, 0);
			break;
		}
	}

	led_render();
}


void effet_StaticColor(LEDS led_param)
{
	uint32_t rgb_color = hsl_to_rgb(led_param.hue, 255, led_param.brightness);
	led_set_all_RGB((rgb_color >> 16) & 0xFF, (rgb_color >> 8) & 0xFF, rgb_color & 0xFF);
	led_render();
}


