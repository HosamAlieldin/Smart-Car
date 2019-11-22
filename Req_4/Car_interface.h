/*
 * Car.h
 *
 *  Created on: Nov 21, 2019
 *      Author: MO._.Hamdy
 */

#ifndef CAR_INTERFACE_H_
#define CAR_INTERFACE_H_

#include "TIMER_interface.h"
#include "DIO_interface.h"
#include "Type.h"
#include "ICU_interface.h"
#include "Macros.h"
#include <util/delay.h>
#include "LCD.h"

void Car_Init(void);
void Car_Move (void);
void carTurnRight(void);
void carBackWard(void);
void carForward (uint8, uint8);

#endif /* CAR_INTERFACE_H_ */
