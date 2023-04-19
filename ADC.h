/*
 * ProjectName: Lab 6 - 7 PWM ADC
 * FileName: ADC.h
 *  version: 1
 *
 * Author: Colette Aguilar
 * Created: March, 2023 - 7:30 am
 * 
 * Operations: 
 *		This program will create an ADC conversion
 *
 * Hardware Connection:
 *	Atmega2560			Hardware
 */ 


#ifndef INCFILE1_H_
#define INCFILE1_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include "main.h"

void init_ADC(void);
//int16_t ADC_read(uint16_t channel);
int16_t ADC_10bit(uint8_t channel);
void call_ADC1();
void call_ADC3();

#endif /* INCFILE1_H_ */