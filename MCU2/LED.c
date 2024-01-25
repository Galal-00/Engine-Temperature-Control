/*
 * LED.c
 *
 * Created: 9/1/2023 1:56:34 AM
 *  Author: galal
 */ 

#include "LED.h"

void led_init(void)
{
	LED_DDR |= (1<<LED_R) | (1<<LED_Y) | (1<<LED_G);
}

void led_on(uint8_t pin_no)
{
	if(LED_PORT & (1<<pin_no)) return;
	LED_PORT &= ~((1<<LED_R) | (1<<LED_Y) | (1<<LED_G));
	LED_PORT |= (1<<pin_no);
}
