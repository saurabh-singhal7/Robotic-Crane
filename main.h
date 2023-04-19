/*
 * main.h
 *
 * Created: 4/7/2023 5:50:23 PM
 *  Author: saura
 */ 


#ifndef MAIN_H_
#define MAIN_H_

#define F_CPU 16000000UL

#define homePosition (PINK & 0x04)
#define stepperClkPB (PINK & 0x01)
#define stepperCounterClkPB (PINK & 0x02)

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "Debugger.h"
#include "Stepper_motor.h"
#include "USART0.h"
#include "timer_ms.h"
#include "ADC.h"

void IO_init(void);
uint8_t passwordCheck(void);

char mode;
volatile char rx_buffer[25];
volatile uint8_t arrayIndex;

#endif /* MAIN_H_ */