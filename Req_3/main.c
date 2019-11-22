/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Eng Mohamed Hamdy
 */

#include "main.h"


int main(void)
{

	Car_Init();

	while (1)
	{
		Car_Move();
	}

	return 0;
}
