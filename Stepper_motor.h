/*
 * Stepper_motor.h
 *
 * Created: 1/31/2023 6:00:51 PM
 * Author: saura
 */ 


#ifndef STEPPER_MOTOR_H_
#define STEPPER_MOTOR_H_

#define F_CPU 16000000UL

//include files
#include <avr/io.h>
#include <util/delay.h>

#define Angle 90

// Define function prototypes
void Stepper_Drive(char mode, uint8_t revolutions);

void Stepper_init(void);

void Stepper_movement(char mode);

// Define

#define Wave_Step 0x01
#define Full_Step 0x02
#define Half_Step 0x04
#define Position 0x08

#define Stepper_output PORTC

//global variables
extern uint8_t Wave[4];
extern uint8_t Full[4];
extern uint8_t Half[8];

#endif /* STEPPER_MOTOR_H_ */