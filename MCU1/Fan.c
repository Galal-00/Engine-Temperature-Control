/*
 * Fan.c
 *
 * Created: 8/30/2023 5:57:41 PM
 *  Author: galal
 */ 

#include "Fan.h"

void fan_init(void)
{
	TCCR0 |= (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS00);	// Fast PWM, 8-bit, non-inverted, no prescaling
	FAN_DDR |= (1<<FAN_PIN);	// Set pin as output
}

void set_fan_speed(uint8_t temp)
{
	// the value in FAN_PWM_PIN is the duty cycle of the output signal
	// it ranges from 0 to 255 (0% to 100% duty cycle)
	if (temp < 20)
	{
		FAN_PWM_PIN = 0;
	}
	else if (temp >= 20 && temp <= 40)
	{
		FAN_PWM_PIN = (temp - 20) * 255 / 20; // maps [20, 40] to [0, 255]
	}
	else
	{
		FAN_PWM_PIN = 255;
	}
}