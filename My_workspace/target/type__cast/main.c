/*
 * main.c
 *
 *  Created on: 24 Oct 2021
 *      Author: 2KJPH5
 */

# include <stdio.h>

int main(void)
{
	unsigned char data = 0x1FFFFFFA0B0 + 0x1245;

	float result = (float) 80/ 3;

	printf("Data = %u result = %f\n", data, result);

	return 0;
}
