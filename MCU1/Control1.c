/*
 * Control1.c
 *
 * Created: 8/30/2023 2:57:54 PM
 *  Author: galal
 */ 

#include "Control1.h"

void init_all(void)
{
	// Initialize UART
	UART_Init();
	// Initialize temperature sensor
	temp_sensor_init();
	// Initialize fan
	fan_init();
	// Initialize button
	button_init();
	// Initialize state as normal in EEPROM
	write_eeprom_byte(STATE_EEPROM_ADDR, 0);
	// Initialize global variables
	temp_val = 0;
	overflow_count = 0;
	timer_initialized = 0;
	timer1_max = 65536;
	em_timer_count = timer1_max - (F_CPU * EM_TIMER_PERIOD / EM_TIMER_PRESCALER);	// 500ms period
	// Enable interrupts
	sei();
}

void control_all(void)
{
	// read state
	MCU_state state = read_eeprom_byte(STATE_EEPROM_ADDR);
	if (state == EMERGENCY)
	{
		// emergency state
		if(timer_initialized == 0)
		{
			EM_timer_init();	// Initialize emergency timer
			set_fan_speed(temp_val);
		}
	}
	else if(state == NORMAL)
	{
		// normal state
		timer_initialized = 0;
		control_temp();
		send_temp();
		set_fan_speed(temp_val);
	}
}

void EM_timer_init(void)
{
	TCNT1 = em_timer_count;
	TCCR1A = 0x00;	// OC1A/OC1B disconnected
	TCCR1B = (1<<CS11) | (1<<CS10);	// Normal mode, /64 prescaler
	TIMSK |= (1<<TOIE1);	// enable timer 1 overflow interrupt
	timer_initialized = 1;
}

void control_temp(void)
{
	temp_val = read_temp();
	if (temp_val > 50) 
	{
		write_eeprom_byte(STATE_EEPROM_ADDR, 1);	// emergency state
	}
}

void send_temp(void)
{
	char msg[MSG_LENGTH] = {temp_val/100 + 48, (temp_val%100)/10 + 48, temp_val%10 + 48, '\r', 0};	// the +48 is to convert the numeric values into characters
	UART_SendString(msg);
}

// ISR for push button
ISR(INT0_vect)
{
	if(temp_val > 40 && temp_val <= 50)
	{
		UART_SendString(TRM_MSG);	// send shut-down code to MCU2
	}
}

// ISR for emergency timer
ISR(TIMER1_OVF_vect)
{
	cli();
	overflow_count++;
	if(overflow_count >= 14)
	{
		// abnormal state
		TCCR1B = 0;	// turn off emergency timer
		overflow_count = 0;	// reset overflow count
		write_eeprom_byte(STATE_EEPROM_ADDR, 2);
		UART_SendString(TRM_MSG);	// send shut-down code to MCU2
		// WDT RESET
		WDT_enable();
	}
	else
	{
		TCNT1 = em_timer_count;
		temp_val = read_temp();
		send_temp();
		if (temp_val <= 50)
		{
			// return to normal state
			TCCR1B = 0;	// turn off emergency timer
			write_eeprom_byte(STATE_EEPROM_ADDR, 0);
			overflow_count = 0;	// reset overflow count
			timer_initialized = 0;	// timer is off
		}
	}
	sei();
}