/*
 * UART.c
 *
 * Created: 8/24/2023
 * Author : galal
 */ 

#include "UART.h"

void UART_Init(void)
{
	/* Set baud rate */
	UBRRH = (unsigned char)(BAUD_PRESCALE>>8);
	UBRRL = (unsigned char)BAUD_PRESCALE;
	/* Enable receiver, transmitter*/
	UCSRB = (1<<RXEN)|(1<<TXEN);
	/* Set frame format: 8 data bit */
	UCSRC = (1<<URSEL)|(1<<UCSZ1)|(3<<UCSZ0);
}

void UART_TxChar(char ch)
{
	while(!(UCSRA & (1<<UDRE)));	// wait for empty transmit buffer
	UDR = ch;
}

char UART_RxChar(void)
{
	while(!(UCSRA & (1<<RXC)));		// wait until data is received
	return UDR;
}

void UART_SendString(char *str)
{
	uint8_t j=0;
	
	while (str[j]!=0)		/* Send string till null */
	{
		UART_TxChar(str[j]);
		j++;
	}
}

void UART_RX_Interrupt_Enable(void)
{
	UCSRB |= (1<<RXCIE);
}