/*
 * ICU_prog.c
 *
 *  Created on: Nov 19, 2019
 *      Author: MO._.Hamdy
 */

#include "ICU_interface.h"

extern uint32 volatile ovf_counter;

uint8  volatile first_riding=0;
uint8  volatile state;
float32 volatile T_on;
float32 volatile T_off;

void ICU_Init(void)
{
	INTERRUPT_VidInit();
	TIMER_vidInit();
}

void ICU_Read(void)
{
	if(first_riding==0)
	{
		TCNT0=0;
		ovf_counter=0;
		first_riding=1;
		state=1;
		CLEAR_BIT(MCUCSR,6); 	//falling
	}

	else
	{
		if(state==1)
		{
			T_on=(float32)((TCNT0+(ovf_counter*256))*(float32)((float32)1/16000000));
			state=0;
			ovf_counter=0;
			TCNT0=0;
			SET_BIT(MCUCSR,6); 	//rising
		}
		else
		{
			T_off=(float32)((TCNT0+(ovf_counter*256))*(float32)((float32)1/16000000));
			state=1;
			ovf_counter=0;
			TCNT0=0;
			CLEAR_BIT(MCUCSR,6); 	//falling
		}
	}
}
