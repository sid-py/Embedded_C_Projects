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
	scanf("%f",&num1);

	printf("\nEnter the second number:");
	scanf("%f",&num2);

	printf("\nEnter the third number:");
	scanf("%f",&num3);

	avg = (num1 + num2 + num3)/3;
	printf("The average of three numbers is: %f", &avg);

}
