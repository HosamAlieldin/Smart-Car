/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Eng Mohamed Hamdy
 */

#include "Main_interface.h"
#include <stdio.h>

uint32 volatile ovf_counter=0;
uint8  volatile Duty;
float32 volatile T_tot;


int main(void)
{
	
	Car_Init();
	while (1)
	{
		Car_Move();
	}

	return 0;
}


ISR(TIMER0_OVF_vect)
{
	cli();
	ovf_counter++;
	sei();
}

ISR(INT2_vect)
{
	cli();
	ICU_Read();
	sei();
}

