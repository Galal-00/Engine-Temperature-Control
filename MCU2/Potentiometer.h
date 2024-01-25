/*
 * Potentiometer.h
 *
 * Created: 9/1/2023 8:19:22 PM
 *  Author: galal
 */ 


#ifndef POTENTIOMETER_H_
#define POTENTIOMETER_H_

#ifndef F_CPU
#define F_CPU 8000000
#endif

#include <avr/io.h>
#include <util/delay.h>
#define POT_DDR DDRA
#define POT_PIN PA0

// initialize potentiometer
void pot_init(void);
// read potentiometer value
uint16_t read_pot(void);




#endif /* POTENTIOMETER_H_ */