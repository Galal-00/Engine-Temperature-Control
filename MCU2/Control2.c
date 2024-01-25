/*
 * Control2.c
 *
 * Created: 8/31/2023 8:57:26 PM
 *  Author: galal
 */ 

#include "Control2.h"

void init_all(void)
{
	// Initialize UART
	UART_Init();
	UART_RX_Interrupt_Enable();	// RX Complete interrupt Enable
	// Initialize servo motor
	servo_init();
	// Initialize buzzer
	buzzer_init();
	// Initialize LEDs
	led_init();
	// Initialize Potentiometer
	pot_init();
	// Initialize Motor
	motor_init();
	// Initialize global variables
	clear_str();	// sets msg characters to NULL
	ch_index = 0;
	shut_down_code = 0;
	temp_val = 0;
	overflow_count = 0;
	ab_timer_initialized = 0;
	timer1_max = 65536;
	ab_timer_count = timer1_max - (F_CPU * AB_TIMER_PERIOD / AB_TIMER_PRESCALER);	// 1s period
	// Enable interrupts
	sei();
}

void control_all(void)
{
	if (shut_down_code == 0)
	{
		if (temp_val < 20) led_on(LED_G);
		else if (temp_val >= 20 && temp_val <= 40) led_on(LED_Y);
		else if (temp_val > 40 && temp_val <= 50) led_on(LED_R);
		else
		{
			led_on(LED_R);
			buzzer_on();
		}
		set_motor();
	}
	else if (shut_down_code == 1 && ab_timer_initialized == 0)
	{
		shut_down();
	}
}

void read_msg(void)
{
	if(msg[MSG_LENGTH - 1] == '\r')
	{
		// note that these checks aren't all necessary but might be useful later on
		if (isdigit(msg[0]) && isdigit(msg[1]) && isdigit(msg[2]))	
		{
			// temperature value was sent
			char msg_2[4] = {msg[0], msg[1], msg[2], 0};
			temp_val = atoi(msg_2);
		}
		else if(msg[0] == msg[1] && msg[1] == msg[2] && msg[2] == 'X')
		{
			// shut-down code was sent
			shut_down_code = 1;
		}
	}
	clear_str();
}

void clear_str(void)
{
	for (int i = 0; i < MSG_LENGTH; i++)
	{
		msg[i] = 0;
	}
	ch_index = 0;
}

void set_motor()
{
	float pot_val = read_pot();
	// map pot_val to the range 0 -> 100
	pot_val = (pot_val * 100) / 1023;
	set_motor_speed((uint8_t)pot_val);
}

void shut_down(void)
{
	led_on(LED_R);
	buzzer_on();
	set_motor_speed(0);
	rotate_servo_90();
	AB_timer_init();
}

void AB_timer_init(void)
{
	TCNT1 = 34285;
	TCCR1A = 0x00;	// OC1A/OC1B disconnected
	TCCR1B = (1<<CS12);	// Normal mode, /256 prescaler
	TIMSK |= (1<<TOIE1);	// enable timer 1 overflow interrupt
	ab_timer_initialized = 1;
}

// ISR for received message
ISR(USART_RXC_vect)
{
	while(!(UCSRA & (1<<RXC)));	// wait until data is received
	if (ch_index < MSG_LENGTH  && shut_down_code != 1)
	{
		msg[ch_index++] = (char)UDR;	// add character to message string
	}
	else if(shut_down_code != 1)
	{
		read_msg();
	}
}

// ISR for abnormal timer
ISR(TIMER1_OVF_vect)
{
	cli();
	overflow_count++;
	if(overflow_count >= 5)
	{
		// reset
		TCCR1B = 0;	// turn off emergency timer
		overflow_count = 0;
		shut_down_code = 0;
		ab_timer_initialized = 0;
		reset_servo();
		buzzer_off();
		clear_str();
	}
	else
	{
		TCNT1 = 34285;
	}
	sei();
}