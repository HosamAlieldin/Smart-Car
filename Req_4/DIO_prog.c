/*
 * DIO_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Eng Mohamed Hamdy
 */
#include "Type.h"
#include "Macros.h"
#include "DIO_private.h"
#include "DIO_interface.h"


/***************************************************************************************/
/* Description! Interface to set the Output value of the pin                           */
/* Input      ! Pin number , Value to set                                			   */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void DIO_vidWritePinValue(uint8 uint8PinNumberCpy,uint8 uint8ValueCpy)
{
	uint8 uint8PortNumberCpy = (uint8PinNumberCpy / 8);
	uint8PinNumberCpy %= 8;

	switch(uint8PortNumberCpy)
	{
		case DIO_PORTA:
			if(uint8ValueCpy==HIGH_PIN)
			{
				SET_BIT(PORTA,uint8PinNumberCpy);
			}
			else
			{
				CLEAR_BIT(PORTA,uint8PinNumberCpy);
			}
		break;
		case DIO_PORTB:
			if(uint8ValueCpy==HIGH_PIN)
			{
				SET_BIT(PORTB,uint8PinNumberCpy);
			}
			else
			{
				CLEAR_BIT(PORTB,uint8PinNumberCpy);
			}
		break;
		case DIO_PORTC:
			if(uint8ValueCpy==HIGH_PIN)
			{
				SET_BIT(PORTC,uint8PinNumberCpy);
			}
			else
			{
				CLEAR_BIT(PORTC,uint8PinNumberCpy);
			}
		break;
		case DIO_PORTD:
			if(uint8ValueCpy==HIGH_PIN)
			{
				SET_BIT(PORTD,uint8PinNumberCpy);
			}
			else
			{
				CLEAR_BIT(PORTD,uint8PinNumberCpy);
			}
		break;
	}
}

/***************************************************************************************/
/* Description! Interface to read an input digital pin                                 */
/* Input      ! Pin number                                               			   */
/* Output     ! uint8 contains the Pin value                                           */
/***************************************************************************************/
uint8 DIO_uint8ReadPinValue(uint8 uint8PinNumberCpy)
{
	uint8 Loc_uint8PinValue=0;
	uint8 uint8PortNumberCpy = (uint8PinNumberCpy / 8);
	uint8PinNumberCpy %= 8;

	switch(uint8PortNumberCpy)
	{
		case DIO_PORTA:

			Loc_uint8PinValue=GET_BIT(PINA,uint8PinNumberCpy);
		break;
		case DIO_PORTB:

			Loc_uint8PinValue=GET_BIT(PINB,uint8PinNumberCpy);
			break;
		case DIO_PORTC:

			Loc_uint8PinValue=GET_BIT(PINC,uint8PinNumberCpy);
		break;
		case DIO_PORTD:

			Loc_uint8PinValue=GET_BIT(PIND,uint8PinNumberCpy);
		break;
	}
	return Loc_uint8PinValue;
}

/***************************************************************************************/
/* Description! Interface to Set the direction of PIN                                  */
/* Input      ! Pin number, Desired Direction                            			   */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void DIO_vidSetPinDirection(uint8 uint8PinNumberCpy,uint8 uint8DirectionCpy)
{
	uint8 uint8PortNumberCpy = (uint8PinNumberCpy / 8);
	uint8PinNumberCpy %= 8;

	switch(uint8PortNumberCpy)
	{
		case DIO_PORTA:
			if(uint8DirectionCpy==OUTPUT_PIN)
			{
				SET_BIT(DDRA,uint8PinNumberCpy);
			}
			else
			{
				CLEAR_BIT(DDRA,uint8PinNumberCpy);
			}
		break;

		case DIO_PORTB:
			if(uint8DirectionCpy==OUTPUT_PIN)
			{
				SET_BIT(DDRB,uint8PinNumberCpy);
			}
			else
			{
				CLEAR_BIT(DDRB,uint8PinNumberCpy);
			}
		break;

		case DIO_PORTC:
			if(uint8DirectionCpy==OUTPUT_PIN)
			{
				SET_BIT(DDRC,uint8PinNumberCpy);
			}
			else
			{
				CLEAR_BIT(DDRC,uint8PinNumberCpy);
			}
		break;

		case DIO_PORTD:
			if(uint8DirectionCpy==OUTPUT_PIN)
			{
				SET_BIT(DDRD,uint8PinNumberCpy);
			}
			else
			{
				CLEAR_BIT(DDRD,uint8PinNumberCpy);
			}
		break;
	}
}

/***************************************************************************************/
/* Description! Interface to set port direction                                        */
/* Input      ! Port number , Desired Direction                                        */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void DIO_vidSetPortDirection(uint8 uint8PortNumberCpy,uint8 uint8ValueCpy)
{
	switch(uint8PortNumberCpy)
	{
		case DIO_PORTA:

			DDRA = uint8ValueCpy;
		break;

		case DIO_PORTB:

			DDRB = uint8ValueCpy;
		break;

		case DIO_PORTC:

			DDRC = uint8ValueCpy;
		break;

		case DIO_PORTD:

			DDRD = uint8ValueCpy;
		break;
	}
}

/***************************************************************************************/
/* Description! Interface to set the output value of port                              */
/* Input      ! Port number , Desired output value                                     */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void DIO_vidWritePortValue(uint8 uint8PortNumberCpy,uint8 uint8ValueCpy)
{
	switch(uint8PortNumberCpy)
	{
		case DIO_PORTA:

			PORTA=uint8ValueCpy; // 3shan ana bn2l data msh bs 0 aw 1
		break;

		case DIO_PORTB:

			PORTB=uint8ValueCpy;
		break;

		case DIO_PORTC:

			PORTC=uint8ValueCpy;
		break;

		case DIO_PORTD:

			PORTD=uint8ValueCpy;
		break;
	}
}

/***************************************************************************************/
/* Description! Interface to get the input value on Port                               */
/* Input      ! Port number                                                            */
/* Output     ! Port Value                                                             */
/***************************************************************************************/
uint8 DIO_uint8ReadPortValue(uint8 uint8PortNumberCpy)
{
	uint8 LOC_uint8Return = 0x00;
	switch(uint8PortNumberCpy)
	{
		case DIO_PORTA:

			LOC_uint8Return = PINA;
		break;
		case DIO_PORTB:
			LOC_uint8Return = PINB;
		break;
		case DIO_PORTC:
			LOC_uint8Return = PINC;
		break;
		case DIO_PORTD:
			LOC_uint8Return = PIND;
		break;
	}
	return LOC_uint8Return;
}
