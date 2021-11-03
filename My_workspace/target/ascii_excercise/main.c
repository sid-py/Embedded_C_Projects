/*
 * main.c
 *
 *  Created on: 28 Oct 2021
 *      Author: siddh
 */

#include <stdio.h>

int main(void)
{
	char c1, c2, c3,c4,c5,c6;

	printf("Enter the 6 characters/number:");
	fflush(stdout);
	scanf("%c %c %c %c %c %c",&c1,&c2,&c3,&c4,&c5,&c6);

	printf("\nThe ASCII equivalents are: %u, %u, %u, %u, %u, %u ", c1, c2,c3,c4,c5,c6);
	fflush(stdout);
	printf("\nPress any key to exit.");


	getchar();
	getchar();
}
