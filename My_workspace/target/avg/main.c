/*
 * main.c
 *
 *  Created on: 28 Oct 2021
 *      Author: siddh
 */

#include <stdio.h>

int main(void)
{
	float num1, num2, num3;
	float avg;

	printf("Enter the first number:");
	fflush(stdout);
	scanf("%f",&num1);
	fflush(stdout);
	printf("\nEnter the second number:");
	scanf("%f",&num2);
	fflush(stdout);
	printf("\nEnter the third number:");
	scanf("%f",&num3);
	fflush(stdout);
	avg = ((num1 + num2 + num3)/3);
	printf("\nThe average of three numbers is: %f", avg);
	fflush(stdout);
	printf("\nPress any key to exit.");
	getchar();
	getchar();
}
