/*
 * Fan.h
 *
 * Created: 8/30/2023 5:57:30 PM
 *  Author: galal
 */ 


#ifndef FAN_H_
#define FAN_H_

#include <avr/io.h>

#define FAN_DDR DDRB
#define FAN_PIN PB3
#define FAN_PWM_PIN OCR0

// initialize fan
void fan_init(void);
// control fan speed
void set_fan_speed(uint8_t temp);




#endif /* FAN_H_ */