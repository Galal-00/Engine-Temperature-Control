/*
 * UART.h
 *
 * Created: 8/24/2023
 * Author : galal
 */ 

#ifndef UART_H_
#define UART_H_

#include <avr/io.h>

#ifndef F_CPU
#define F_CPU 8000000
#endif
#define BAUD 9600
#define BAUD_PRESCALE ((F_CPU/16/BAUD) - 1)

// Initialize UART
void UART_Init(void);
// Send character
void UART_TxChar(char ch);
// Receive character
char UART_RxChar(void);
// Send string
void UART_SendString(char *str);
// UART Interrupt Enable
void UART_RX_Interrupt_Enable(void);
#endif	/* UART_H_ */