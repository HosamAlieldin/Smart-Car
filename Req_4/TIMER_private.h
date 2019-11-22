/*
 * TIMER_private.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Eng Mohamed Hamdy
 */

#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_


#define SREG 	 *((volatile uint8*)0x5F)
#define TIMSK 	 *((volatile uint8*)0x59)
#define TIFR 	 *((volatile uint8*)0x58)

#define TCCR1A	 *((volatile uint8*)0x4F)
#define TCCR1B	 *((volatile uint8*)0x4E)

#define TCNT1H 	 *((volatile uint8*)0x4D)
#define TCNT1L 	 *((volatile uint8*)0x4C)

#define OCR1AH 	 *((volatile uint8*)0x4B)
#define OCR1AL 	 *((volatile uint8*)0x4A)
#define OCR1BH 	 *((volatile uint8*)0x49)
#define OCR1BL 	 *((volatile uint8*)0x48)

#define ICR1H 	 *((volatile uint8*)0x47)
#define ICR1L 	 *((volatile uint8*)0x46)

#define TCNT0 	 *((volatile uint8*)0x52)
#define TCCR0	 *((volatile uint8*)0x53)

#define TCCR2	 *((volatile uint8*)0x45)
#define TCNT2	 *((volatile uint8*)0x44)
#define OCR2	 *((volatile uint8*)0x43)

#endif /* TIMER_PRIVATE_H_ */
