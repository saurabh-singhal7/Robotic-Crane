/*
 * ProjectName: Lab 6 - 7 PWM ADC
 * FileName: timer_ms.c
 *  version: 1
 *
 * Author: Colette Aguilar
 * Created: February 15, 2023 - 7:30 am
 * 
 * Operations: 
 *		This program will be a dyi timer
 *
 * Hardware Connection:
 *	Atmega2560			Hardware
 */ 
#include "timer_ms.h"

void init_timer1(void)
{
	TCNT1 = 0;
	TCCR1A = 0;
	TCCR1B = 0;		//set to 0x05 when timer starts
	OCR1A = 62;		//calculated val
}

void init_timer3(void)
{
	TCNT3 = 0;
	TCCR3A = 0;
	TCCR3B = 0;		//set to 0x05 when timer starts
	OCR3A = 62;		//calculated val
}

