/*
 * FinalProject.c
 *
 * Created: 4/7/2023 5:50:02 PM
 * Author : Saurabh Singhal
 *
 * Hardware Connections:
 *	Outputs:
 *		PORTC - Stepper Motor
 *	Inputs:
 *		PORTK.0 - Move stepper motor clockwise
 *		PORTK.1 - Move stepper motor counter-clockwise
 *		PORTK.2 - Home the stepper motor
 *
 */ 

#include "main.h"

int main(void)
{
    IO_init();
	initDebug();
	init_UART();
	init_timer1();
	init_timer3();
	init_ADC();
	sei();
	char ack[30] = {"enter configuration mode\n"};
	while(1)
	{
		UART_out_string(rx_buffer);
		if (passwordCheck() == 1)
		{
			UART_out_string("Password matched\n");
			//for(uint8_t i = 0; i < 25; i++)
			//{
				//rx_buffer[i] = "";
			//}
			mode = 'C';
			UART_out_string(ack);
			while (homePosition != 0)
			{
				Stepper_movement('A');
			}
			//while (1)
			//{
				//if (stepperClkPB)
				//{
					//Stepper_movement('C');
				//}
				//else if (stepperCounterClkPB)
				//{
					//Stepper_movement('A');
				//}
				//else
				//{
					//call_ADC1();	//stepper motor 1 with potentiometer
					//call_ADC3();	//stepper motor 2 with potentiometer
					//Stepper_output = 0x00;
				//}
			//}
		}
		else
		{
			continue;
		}
	}
}

void IO_init(void)
{
	DDRC = 0xFF; // PORTF as outputs
	PORTC = 0x00; // turn off PORTF initially
	
	DDRK = 0x00; // PORTK as inputs
	PORTK = 0xFF; // turn on pull-up resistors
}

uint8_t passwordCheck(void)
{
	char password[25] = {"Config"};
	uint8_t i = 0;
	uint8_t c = 0;
	while (rx_buffer[i] != '\0')
	{
		if (rx_buffer[i] == password[i])
		{
			c++;
		}
	}
	if (c >= 5)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

