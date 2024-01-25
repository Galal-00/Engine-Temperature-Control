/*
 * main.c
 *
 * Created: 8/29/2023
 * Author : Galal
 */

#include <avr/io.h>
#include "Control2.h"


int main(void)
{
    // Initialize peripherals
	init_all();
    while (1) 
    {
		control_all();
    }
}

