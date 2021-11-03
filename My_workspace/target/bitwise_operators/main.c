/*
 * main.c
 *
 *  Created on: 2 Nov 2021
 *      Author: siddh
 */

# include <stdio.h>

int main(void)
{
	int num1, num2;
	printf("Enter two numbers (Give space between the 2 nos):");
	scanf("%d %d", &num1, &num2);

	printf("Bitwise AND (&) : %d\n", (num1 & num2));

	getchar();
	getchar();
	return 0;
}
