/*
 * main.c
 *
 * Created: 8/29/2023
 * Author : galal
 */ 

#include <avr/io.h>
#include "Control1.h"

int main(void)
{
    // Initialize peripherals
	init_all();
    while (1) 
    {
		control_all();
		_delay_ms(500);
    }
}

