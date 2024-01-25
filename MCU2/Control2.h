/*
 * Control2.h
 *
 * Created: 8/31/2023 8:57:18 PM
 *  Author: galal
 */ 


#ifndef CONTROL2_H_
#define CONTROL2_H_

#ifndef F_CPU
#define F_CPU 8000000
#endif

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include <ctype.h>
#include "UART.h"
#include "Servo.h"
#include "Buzzer.h"
#include "LED.h"
#include "Potentiometer.h"
#include "Motor.h"

#define MSG_LENGTH 4
#define LED_R_PIN 1
#define LED_Y_PIN 2
#define LED_G_PIN 3
#define AB_TIMER_PERIOD 1	// emergency timer period in seconds
#define AB_TIMER_PRESCALER 256

char msg[MSG_LENGTH];
volatile uint8_t ch_index;
volatile uint8_t shut_down_code;	// 0 when no shutdown is order, 1 when shutdown is ordered
uint8_t temp_val;
volatile uint16_t overflow_count;	// emergency timer overflow count
volatile uint8_t ab_timer_initialized; // abnormal timer is not initialized at first
unsigned long timer1_max;	// max count for timer 1
unsigned long ab_timer_count;	// abnormal timer counter compare value

// initialize peripherals
void init_all(void);
// control peripherals
void control_all(void);
// read UART message (temperature value)
void read_msg(void);
// clear msg string
void clear_str(void);
// control motor
void set_motor(void);
// shutdown routine
void shut_down(void);
// initialize abnormal timer, uses timer 1
void AB_timer_init(void);




#endif /* CONTROL2_H_ */