/*
 * ProjectName: Lab9and10_Communications
 * FileName: USART0.h
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


#ifndef USART0_H_
#define USART0_H_

#define F_CPU 16000000UL
#define baud 9600UL

//include files
#include <avr/io.h>
#include <util/delay.h>
#include "main.h"

void init_UART(void);
void UART_out(uint8_t ch);
void UART_out_string(char *character);

#endif /* USART0_H_ */