/*
 * Button.c
 *
 * Created: 8/30/2023 7:44:11 PM
 *  Author: galal
 */ 

#include "Button.h"

void button_init(void)
{
	BUTTON_PORT = (1<<BUTTON_PIN_NO);	// activate pull-up mode
	GICR |= (1<<INT0);	// enable external interrupt 0
	MCUSR |= (1<<ISC01);	// enable interrupt on falling edge
}

