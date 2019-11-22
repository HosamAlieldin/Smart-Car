/*
 * INTERRUPT_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Eng Mohamed Hamdy
 */

#include "INTERRUPT_interface.h"
#include "INTERRUPT_private.h"



void INTERRUPT_VidInit(void)
{
	SET_BIT(SREG,7);        //set global interrupt enable

	SET_BIT(MCUCSR,6); 	   //set INT2 as rising edge

	SET_BIT(GICR,5); 		//set INT2 enable

	DIO_vidSetPinDirection(DIO_PB2,INPUT_PIN);
}
