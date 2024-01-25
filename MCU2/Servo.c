/*
 * Servo.c
 *
 * Created: 8/31/2023 10:03:06 PM
 *  Author: galal
 */ 

#include "Servo.h"

void servo_init(void)
{
	SERVO_DDR |= (1<<SERVO_PIN);
}

void rotate_servo_90(void)
{
	// emulates a 2ms pulse which results in a 90 deg rotation
	SERVO_PORT |= (1<<SERVO_PIN);
	_delay_us(2000);
	SERVO_PORT &= ~(1<<SERVO_PIN);
}

void reset_servo(void)
{
	// emulates a 1.5ms pulse which resets servo to 0 deg
	SERVO_PORT |= (1<<SERVO_PIN);
	_delay_us(1500);
	SERVO_PORT &= ~(1<<SERVO_PIN);
}