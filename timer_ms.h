/*
 * ProjectName: Lab 6 - 7 PWM ADC
 * FileName: timer_ms.h
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


#ifndef INCFILE1_H_
#define INCFILE1_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include "main.h"

void init_timer1(void);
void init_timer3(void);

#endif /* INCFILE1_H_ */