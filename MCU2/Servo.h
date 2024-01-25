/*
 * Servo.h
 *
 * Created: 8/31/2023 10:03:12 PM
 *  Author: galal
 */ 


#ifndef SERVO_H_
#define SERVO_H_

#ifndef F_CPU
#define F_CPU 8000000
#endif

#include <avr/io.h>
#include <util/delay.h>

#define SERVO_DDR DDRB
#define SERVO_PORT PORTB
#define SERVO_PIN PB0

// Initialize servo
void servo_init(void);
// rotate servo by 90 deg
void rotate_servo_90(void);
// reset servo to 0 deg
void reset_servo(void);



#endif /* SERVO_H_ */