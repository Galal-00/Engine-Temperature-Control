/*
 * Temp_Sensor.c
 *
 * Created: 8/30/2023 3:26:51 PM
 *  Author: galal
 */ 

#include "Temp_Sensor.h"

void temp_sensor_init(void)
{
	TEMP_DDR &= ~(1<<TEMP_SENS_PIN);	// make temperature sensor pin input pin
	ADCSRA = (1<<ADEN) | (1<<ADPS2) | (1<<ADPS1); // enable ADC, /64 prescaler (125KHz)
	ADMUX = (1<<REFS0) | (1<<REFS1);	// use internal 2.56V as reference, right-justified result, use ADC0 pin
}

uint16_t read_temp(void)
{
	float val;
	ADCSRA |= (1<<ADSC);	// start conversion
	while(ADCSRA & (1<<ADSC));	// wait for conversion
	_delay_us(10);
	val = ADC;
	// map ADC value range (0 -> 602) to the range 0 -> 150 (temperature range)
	val = val * 150 / 602;
	return val;
}