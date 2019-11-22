/*
 * ICU_interface.h
 *
 *  Created on: Nov 19, 2019
 *      Author: MO._.Hamdy
 */

#ifndef ICU_INTERFACE_H_
#define ICU_INTERFACE_H_

#include "Type.h"
#include "Macros.h"
#include "INTERRUPT_interface.h"
#include "INTERRUPT_private.h"
#include "TIMER_interface.h"
#include "TIMER_private.h"

extern float32 volatile T_on;
extern float32 volatile T_off;

void ICU_Init(void);
void ICU_Read(void);


#endif /* ICU_INTERFACE_H_ */
