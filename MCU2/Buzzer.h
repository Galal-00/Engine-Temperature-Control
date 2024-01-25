/*
 * Buzzer.h
 *
 * Created: 9/1/2023 12:53:37 AM
 *  Author: galal
 */ 


#ifndef BUZZER_H_
#define BUZZER_H_

#include <avr/io.h>

#define BUZZER_DDR DDRD
#define BUZZER_PORT PORTD
#define BUZZER_PIN PD3

// Initialize buzzer
void buzzer_init(void);
// Turn buzzer on
void buzzer_on(void);
// Turn buzzer off
void buzzer_off(void);



#endif /* BUZZER_H_ */