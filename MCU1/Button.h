/*
 * Button.h
 *
 * Created: 8/30/2023 7:40:01 PM
 *  Author: galal
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include <avr/io.h>

#define BUTTON_PORT PORTD
#define BUTTON_IN_PIN PIND
#define BUTTON_PIN_NO PD2

// initialize button
void button_init(void);




#endif /* BUTTON_H_ */