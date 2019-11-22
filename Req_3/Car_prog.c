/*
 * Car.c
 *
 *  Created on: Nov 21, 2019
 *      Author: MO._.Hamdy
 */

#include "Car_interface.h"



void Car_Init(void)
{
	DIO_vidSetPinDirection(DIO_PD2, OUTPUT_PIN);
	DIO_vidSetPinDirection(DIO_PD3, OUTPUT_PIN);
	DIO_vidSetPinDirection(DIO_PD4, OUTPUT_PIN);
	DIO_vidSetPinDirection(DIO_PD5, OUTPUT_PIN);
	DIO_vidSetPinDirection(DIO_PD6, OUTPUT_PIN);
	DIO_vidSetPinDirection(DIO_PD7, OUTPUT_PIN);

	DIO_vidWritePinValue(DIO_PD2, HIGH_PIN); 		//M1
	DIO_vidWritePinValue(DIO_PD3, LOW_PIN);

	DIO_vidWritePinValue(DIO_PD6, HIGH_PIN); 		//M2
	DIO_vidWritePinValue(DIO_PD7, LOW_PIN);

	Timer1_PWM_Mode_init();
	Timer2_init_CTC_Mode();
}

void Car_Move(void)
{
	uint16 modes_H[5]={Duty_H_0, Duty_H_25, Duty_H_50, Duty_H_75, Duty_H_100};
	uint16 modes_L[5]={Duty_L_0, Duty_L_25, Duty_L_50, Duty_L_75, Duty_L_100};
	sint8 count=0;
	for(count=0; count<4; count++)
	{
		Timer1_PWM_Mode_Start(modes_H[count],modes_L[count]);
		Timer2_delay(1000);
	}

	for(count=4; count>=0; count--)
	{
		Timer1_PWM_Mode_Start(modes_H[count],modes_L[count]);
		Timer2_delay(1000);
	}


	DIO_vidWritePinValue(DIO_PD2, LOW_PIN); 		//M1 rotate right
	DIO_vidWritePinValue(DIO_PD3, HIGH_PIN);

	Timer1_PWM_Mode_Start(Duty_H_25,Duty_L_25);
	Timer2_delay(1400);
	Timer1_PWM_Mode_Start(Duty_H_0,Duty_L_0);

	DIO_vidWritePinValue(DIO_PD2, HIGH_PIN); 		//M1
	DIO_vidWritePinValue(DIO_PD3, LOW_PIN);

}
