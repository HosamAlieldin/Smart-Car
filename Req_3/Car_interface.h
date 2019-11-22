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
#include "Macros.h"
#include <util/delay.h>

void Car_Init(void);
void Car_Move (void);

#endif /* CAR_INTERFACE_H_ */
