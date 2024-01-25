/*
 * Potentiometer.c
 *
 * Created: 9/1/2023 8:18:36 PM
 *  Author: galal
 */ 

#include "Potentiometer.h"

void pot_init(void)
{
	POT_DDR &= ~(1<<POT_PIN);	// make potentiometer pin an input pin
	ADCSRA = (1<<ADEN) | (1<<ADPS2) | (1<<ADPS1);	// enable ADC, /64 prescaler (125KHz)
	ADMUX = 0x00;	// use AREF as reference, right-justified result, use ADC0 pin
}

uint16_t read_pot(void)
{
	ADCSRA |= (1<<ADSC);	// start conversion
	while(ADCSRA & (1<<ADSC));	// wait until conversion is complete
	_delay_us(10);
	return ADC;	// returns percentage of ADC
}