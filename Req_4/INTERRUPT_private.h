/*
 * INTERRUPT_private.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Eng Mohamed Hamdy
 */

#ifndef INTERRUPT_PRIVATE_H_
#define INTERRUPT_PRIVATE_H_


#define SREG 		*((volatile uint8*)0x5F)
#define GICR 		*((volatile uint8*)0x5B)
#define GIFR 		*((volatile uint8*)0x5A)
#define MCUCR 		*((volatile uint8*)0x55)
#define MCUCSR 		*((volatile uint8*)0x54)


#endif /* INTERRUPT_PRIVATE_H_ */
