/*
 * Stepper_motor.c
 *
 * Created: 1/31/2023 6:00:07 PM
 * Author: saura
 */
#define F_CPU 16000000UL
#include <util/delay.h>
#include "Stepper_motor.h"

#define PushButton (PINK & 0x0F)

uint8_t Wave[4] = {0x01, 0x02, 0x04, 0x08};
uint8_t Full[4] = {0x03, 0x06, 0x0C, 0x09};
uint8_t Half[8] = {0x09, 0x01, 0x03, 0x02, 0x06, 0x04, 0x0C, 0x08};

void Stepper_Drive(char mode, uint8_t revolutions)
{
	uint16_t steps;
	
	switch(mode)
	{
		case 'W':
		steps = 512 * revolutions;
		for (uint16_t i = 0; i < steps; i++)
		{
			for (uint16_t j = 0; j < 4; j++)
			{
				Stepper_output = Wave[j];
				_delay_ms(3);
			}
		}
		break;
		case 'F':
		steps = 512 * revolutions;
		for (uint16_t i = 0; i < steps; i++)
		{
			for (uint16_t j = 0; j < 4; j++)
			{
				Stepper_output = Full[j];
				_delay_ms(3);
			}
		}
		break;
		case 'H':
		steps = 512 * revolutions;
		for (uint16_t i = 0; i < steps; i++)
		{
			for (uint16_t j = 0; j < 8; j++)
			{
				Stepper_output = Half[j];
				_delay_ms(3);
			}
		}
		break;
	}
}

void Stepper_movement(char mode)
{
	switch (mode)
	{
		case 'C':
		for (uint16_t j = 0; j < 8; j++)
		{
			Stepper_output = Half[j];
			_delay_ms(3);
		}
		break;
		case 'A':
		for (int16_t j = 7; j >= 0; j--)
		{
			Stepper_output = Half[j];
			_delay_ms(3);
		}
		break;
	}
}
