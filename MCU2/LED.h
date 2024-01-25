/*
 * LED.h
 *
 * Created: 9/1/2023 1:56:44 AM
 *  Author: galal
 */ 


#ifndef LED_H_
#define LED_H_

#include <avr/io.h>

#define LED_DDR DDRA
#define LED_PORT PORTA
#define LED_R PA1
#define LED_Y PA2
#define LED_G PA3

// Initialize LEDs
void led_init(void);
// Turn on selected LED, turn off all others
void led_on(uint8_t);


#endif /* LED_H_ */