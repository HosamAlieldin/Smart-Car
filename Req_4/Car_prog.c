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
	ICU_Init();
	LCD_init();
	DIO_vidSetPinDirection(DIO_PB0, OUTPUT_PIN);
	
	
}

void Car_Move(void)
{
	uint16 volatile Distance=0;
	
	DIO_vidWritePinValue(DIO_PB0, HIGH_PIN);
	_delay_us(30);
	DIO_vidWritePinValue(DIO_PB0, LOW_PIN);
	Distance = (uint16)(17000*T_on);
	if((Distance >= 3)&&(Distance < 400))
	{
		LCD_goToRowColumn(0,0);
		LCD_displayString("Distance= ");
		LCD_displayCharacter(((uint8)(Distance/100))+'0');
		LCD_displayCharacter(((uint8)((Distance%100)/10))+'0');
		LCD_displayCharacter(((uint8)((Distance%100)%10))+'0');
		LCD_displayString(" CM");
	}
	else
	{
		LCD_goToRowColumn(0,0);
		LCD_displayString("Distance= ");
		LCD_displayCharacter('0');
		LCD_displayCharacter('0');
		LCD_displayCharacter('0');
		LCD_displayString(" CM");
	}

	if (Distance < 3)
	{
	}

	if( Distance > 50  )
	{
		carForward(Duty_H_80, Duty_L_80);
	}else if (Distance > 40 && Distance <= 50)
	{
		carForward(Duty_H_30, Duty_L_30);
	}else if(Distance <= 40 && Distance >= 30)
	{
		carTurnRight();
	}else
	{
		carBackWard();
	}

	Timer2_delay (60);

}

void carTurnRight()
{
	Timer1_PWM_Mode_Start(0,0);
		Timer2_delay(250);
	DIO_vidWritePinValue(DIO_PD2, LOW_PIN); 		//M1 rotate right
	DIO_vidWritePinValue(DIO_PD3, HIGH_PIN);

	Timer1_PWM_Mode_Start(Duty_H_25,Duty_L_25);
	Timer2_delay(1000);
	Timer1_PWM_Mode_Start(Duty_H_0,Duty_L_0);

	DIO_vidWritePinValue(DIO_PD2, HIGH_PIN); 		//M1
	DIO_vidWritePinValue(DIO_PD3, LOW_PIN);
}

void carBackWard ()
{
	DIO_vidWritePinValue(DIO_PD3, LOW_PIN); 		//M1 rotate right
	DIO_vidWritePinValue(DIO_PD2, HIGH_PIN);
	DIO_vidWritePinValue(DIO_PD7, LOW_PIN); 		//M1
	DIO_vidWritePinValue(DIO_PD6, HIGH_PIN);
	Timer1_PWM_Mode_Start(Duty_H_25,Duty_L_25);
}

void carForward (uint8 high, uint8 low)
{
	DIO_vidWritePinValue(DIO_PD2, LOW_PIN); 		//M1 rotate right
	DIO_vidWritePinValue(DIO_PD3, HIGH_PIN);
	DIO_vidWritePinValue(DIO_PD6, LOW_PIN); 		//M1
	DIO_vidWritePinValue(DIO_PD7, HIGH_PIN);
	Timer1_PWM_Mode_Start(high,low);
}
