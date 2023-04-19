/*
 * ProjectName: Lab9and10_Communications
 * FileName: USART0.c
 * version: 1
 *
 * Author: Saurabh Singhal
 * Created: 3/27/2023 10:27:02 PM
 *
 * Operations:
 * This module has functions necessary to
 * initialize USART and communicate
 *
 */

#define F_CPU 16000000UL

#include "main.h"

void init_UART(void)
{
	uint16_t myubr;
	UCSR0A = 0x00;
	UCSR0B = (1 << RXCIE0) | (1 << RXEN0) | (1 << TXEN0); // receive complete interrupt flag, receive enable, transmitter enable
	UCSR0C = (1 << UCSZ00) | (1 << UCSZ01); // 8-bit data mode
	myubr = (F_CPU / (16UL * (uint16_t) baud)) - 1; // calculate the UBRR low and high
	UBRR0L = myubr; // load UBBR low
	UBRR0H = 0x00; // load UBRR high
	arrayIndex = 0;
}

void UART_out(uint8_t ch)
{
	while ((UCSR0A & (1 << UDRE0)) == 0)
	{
		//wait to complete transmission and UDR is empty
	}
	UDR0 = ch;
}

void UART_out_string(char *character)
{
	while(*character != '\0')
	{
		UART_out(*character);
		character++;
	}
}

ISR(USART0_RX_vect)
{
	uint8_t rx_char = UDR0;
	if (rx_char == 0x0D)
	{
		rx_buffer[arrayIndex] = '\0';
		arrayIndex = 0;
	}
	else
	{
		rx_buffer[arrayIndex] = rx_char;
		arrayIndex++;
	}
}