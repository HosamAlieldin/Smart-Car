/*
 * ADC_interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Eng Mohamed Hamdy
 */

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

#include "Type.h"
#include "Macros.h"
#include "DIO_interface.h"

#define Duty_H_0		0x00
#define Duty_H_25		0x01
#define Duty_H_50		0x02
#define Duty_H_75		0x03
#define Duty_H_100		0x04

#define Duty_L_0		0x00
#define Duty_L_25		0x39
#define Duty_L_50		0x71
#define Duty_L_75		0xAA
#define Duty_L_100		0xE2
#define NUMBER_OF_OVERFLOWS_PER_SECOND 62
void Timer1_PWM_Mode_init();
void Timer1_PWM_Mode_Start(uint16 set_duty_cycleH, uint16 set_Duty_cycleL);

void Timer2_init_CTC_Mode();
void Timer2_delay(uint16 delay);



#endif /* TIMER_INTERFACE_H_ */
