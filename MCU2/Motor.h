/*
 * Motor.h
 *
 * Created: 9/1/2023 8:01:36 PM
 *  Author: galal
 */ 


#ifndef MOTOR_H_
#define MOTOR_H_

#include <avr/io.h>

#define MOTOR_DDR DDRD
#define MOTOR_PIN PD7
#define MOTOR_PWM_PIN OCR2

// initialize motor
void motor_init(void);
// set speed, input range: 0 -> 100
void set_motor_speed(uint8_t speed);


#endif /* MOTOR_H_ */