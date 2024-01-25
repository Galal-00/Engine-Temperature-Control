/*
 * Buzzer.c
 *
 * Created: 9/1/2023 12:53:44 AM
 *  Author: galal
 */ 

#include "Buzzer.h"

void buzzer_init(void)
{
	BUZZER_DDR |= (1<<BUZZER_PIN);
}

void buzzer_on(void)
{
	BUZZER_PORT |= (1<<BUZZER_PIN);
}

void buzzer_off(void)
{
	BUZZER_PORT &= ~(1<<BUZZER_PIN);
}
