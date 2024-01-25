/*
 * Motor.c
 *
 * Created: 9/1/2023 8:01:42 PM
 *  Author: galal
 */ 

#include "Motor.h"

void motor_init(void)
{
	TCCR2 |= (1<<WGM21) | (1<<WGM20) | (1<<COM21) | (1<<CS20);	// Fast PWM, 8-bit, non-inverted, no prescaling
	MOTOR_DDR |= (1<<MOTOR_PIN);	// set pin as output
	MOTOR_PWM_PIN = 0;	// start at zero motor speed
}

void set_motor_speed(uint8_t speed)
{
	unsigned int duty_cycle = speed * 255 / 100;
	MOTOR_PWM_PIN = (uint8_t)duty_cycle;
}
