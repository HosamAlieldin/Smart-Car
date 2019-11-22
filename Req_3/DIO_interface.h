/*
 * DIO_interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Eng Mohamed Hamdy
 */

#ifndef DIO_H_
#define DIO_H_

//Ports Name
#define DIO_PORTA		0
#define DIO_PORTB 		1
#define DIO_PORTC 		2
#define DIO_PORTD 		3

//Pins Name
#define DIO_PA0 	0
#define DIO_PA1 	1
#define DIO_PA2 	2
#define DIO_PA3 	3
#define DIO_PA4		4
#define DIO_PA5 	5
#define DIO_PA6 	6
#define DIO_PA7 	7

#define DIO_PB0		8
#define DIO_PB1		9
#define DIO_PB2		10
#define DIO_PB3		11
#define DIO_PB4		12
#define DIO_PB5		13
#define DIO_PB6		14
#define DIO_PB7		15

#define DIO_PC0		16
#define DIO_PC1 	17
#define DIO_PC2 	18
#define DIO_PC3 	19
#define DIO_PC4		20
#define DIO_PC5 	21
#define DIO_PC6 	22
#define DIO_PC7 	23

#define DIO_PD0		24
#define DIO_PD1 	25
#define DIO_PD2 	26
#define DIO_PD3 	27
#define DIO_PD4		28
#define DIO_PD5 	29
#define DIO_PD6 	30
#define DIO_PD7 	31

#define HIGH_PIN		0x01
#define LOW_PIN  		0x00
#define HIGH_PORT		0xFF
#define LOW_PORT		0x00

#define OUTPUT_PIN 		0x01
#define INPUT_PIN 		0x00
#define OUTPUT_PORT		0xFF
#define INPUT_PORT		0x00

//Set the value of output pin in port
void DIO_vidWritePinValue(uint8 uint8PinNumberCpy,uint8 uint8ValueCpy);

//Get the value of input pin in port
uint8 DIO_uint8ReadPinValue(uint8 uint8PinNumberCpy);

//Set the direction of pin in port
void DIO_vidSetPinDirection(uint8 uint8PinNumberCpy,uint8 uint8DirectionCpy);

//Set port direction
void DIO_vidSetPortDirection(uint8 uint8PortNumberCpy,uint8 uint8ValueCpy);

//Set the output value of port
void DIO_vidWritePortValue(uint8 uint8PortNumberCpy,uint8 uint8ValueCpy);

//Get the input value on port
uint8 DIO_uint8ReadPortValue(uint8 uint8PortNumberCpy);




#endif /* DIO_H_ */
