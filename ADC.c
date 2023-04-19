/*
 * ProjectName: Lab 6 - 7 PWM ADC
 * FileName: ADC.c
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
#include "ADC.h"

void call_ADC1()	//might not be used
{
	DDRB = 0xFF;
	PORTB = 0x00;
	TCCR1A = (1 << COM1A1) | (1 << WGM11);
	TCCR1B = (1 << WGM12) | (1 << CS01);
	
	//OCR1A = (ADC_read(0)) * 512UL / 1024UL;
	OCR1A = (ADC_10bit(0) * 5);
}

void call_ADC3()	//might not be used
{
	DDRB = 0xFF;
	PORTB = 0x00;
	TCCR3A = (1 << COM3A1) | (1 << WGM31);
	TCCR3B = (1 << WGM32) | (1 << CS31);
	
	//OCR3A = (ADC_read(1)) * 512UL / 1024UL;
	OCR3A = (ADC_10bit(1) * 5);
}

void init_ADC(void)
{
	DDRF = 0x00;
	PORTF = 0x00;
	ADMUX = (1 << REFS0);	//no ADLAR = 10 bit
	
	ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);	//enable register + prescaler = 128
	
	ADCSRB = 0x00;
}

/*int16_t ADC_read(uint16_t channel)	//won't be used
{
	int16_t adc_readout = 0;
	
	ADMUX = (ADMUX & 0xE0) | channel;	//select channel
	ADCSRA |= (1 << ADSC);		//start conversion
	
	while((ADCSRA & (1 << ADIF)) == 0);	//wait for ADSC
	ADCSRA |= (1 << ADIF);
	
	adc_readout = ADCL;
	adc_readout |= (ADCH << 8);	//shift ADCH number to MS 8bit + ADCL
	
	return adc_readout;
}*/

int16_t ADC_10bit(uint8_t channel)
{
	int16_t adc_readout = 0;
	
	ADMUX = (ADMUX & 0xE0) | channel;	//select channel
	ADCSRA |= (1 << ADSC);		//start conversion
	
	while((ADCSRA & (1 << ADIF)) == 0);	//wait for ADSC
	ADCSRA = 0;	//ADCSRA |= (1 << ADIF);

	adc_readout = ADCL;
	
	if(channel >= 8)
	{
		channel -= 8;
		ADCSRB = ADCSRB << MUX5;
	}
	
	adc_readout |= (ADCH << 8);	//shift ADCH number to MS 8bit + ADCL
	
	return adc_readout;
}