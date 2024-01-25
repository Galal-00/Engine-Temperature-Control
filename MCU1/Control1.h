/*
 * Control1.h
 *
 * Created: 8/30/2023 2:57:21 PM
 *  Author: galal
 */ 


#ifndef CONTROL1_H_
#define CONTROL1_H_

#ifndef F_CPU
#define F_CPU 8000000
#endif

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "UART.h"
#include "temp_sensor.h"
#include "Custom_EEPROM.h"
#include "Fan.h"
#include "Button.h"
#include "WDT.h"

#define MSG_LENGTH 5
#define TRM_MSG "XXX\r"	// termination message
#define STATE_EEPROM_ADDR 0x5F	// address in EEPROM to state value
#define EM_TIMER_PERIOD 0.5	// emergency timer period in seconds
#define EM_TIMER_PRESCALER 64

typedef enum{NORMAL, EMERGENCY, ABNORMAL}MCU_state;
volatile uint8_t temp_val;
volatile uint16_t overflow_count;	// emergency timer overflow count
volatile uint8_t timer_initialized; // emergency timer is not initialized at first
unsigned long timer1_max;	//max count for timer 1
unsigned long em_timer_count;	// emergency timer counter compare value

// initialize peripherals
void init_all(void);
// control peripherals
void control_all(void);
// initialize emergency timer, uses timer 1
void EM_timer_init(void);
// temperature sensor control, returns current temperature
void control_temp(void);
// send temperature value to MCU2
void send_temp(void);


#endif /* CONTROL1_H_ */