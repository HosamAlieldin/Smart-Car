/*
 * TIMER_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Eng Mohamed Hamdy
 */


#include "TIMER_interface.h"
#include "TIMER_private.h"
//#include <avr/io.h>

void Timer2_init_CTC_Mode()
{
	TCNT2 =0;
	SET_BIT(TCCR2,7);
	SET_BIT(TCCR2,3);
}

void Timer2_delay(uint16 delay)
{
	OCR2 = 124;
	SET_BIT(TCCR2,2);
	CLEAR_BIT(TCCR2,1);
	SET_BIT(TCCR2,0);

	while (delay > 0)
	{
		if (GET_BIT(TIFR,7)==1)
		{
			SET_BIT(TIFR,7);
			delay--;
		}
	}
}

void Timer1_PWM_Mode_init()
{
	//DIO_vidSetPinDirection(DIO_PD4, HIGH_PIN);
	DIO_vidSetPinDirection(DIO_PD5, HIGH_PIN);

	TCNT1H= 0;
	TCNT1L= 0 ;
	ICR1H= 0x04 ;
	ICR1L= 0xE2;

	SET_BIT(TCCR1A, 1);
	//SET_BIT(TCCR1B, 3);
	SET_BIT(TCCR1B, 4);
	SET_BIT(TCCR1A, 7);

}
void Timer1_PWM_Mode_Start(uint16 set_duty_cycleH, uint16 set_duty_cycleL)
{
	OCR1AH= set_duty_cycleH;
	OCR1AL= set_duty_cycleL;

	//OCR1BH= set_duty_cycleH;
	//OCR1BL= set_duty_cycleL;

	SET_BIT(TCCR1B, 0);
	SET_BIT(TCCR1B, 1);
}


void TIMER_1ms_vidInit(void)
{
	CLEAR_BIT(TCCR0,7);

	CLEAR_BIT(TCCR0,6); // normal mode
	CLEAR_BIT(TCCR0,3);

	CLEAR_BIT(TCCR0,5); //Normal port operation, OC0 disconnected.
	CLEAR_BIT(TCCR0,4);

	CLEAR_BIT(TCCR0,2); //clk I/O (No prescaling)
	CLEAR_BIT(TCCR0,1);
	SET_BIT(TCCR0,0);

	TCNT0=192;

	SET_BIT(TIMSK,0);

	SET_BIT(SREG,7);

}
