/*
 * main.c
 *
 *  Created on: 29 Oct 2021
 *      Author: siddh
 */



# include<stdio.h>

int main(void)
{
	double charge, chargeE = -1.602e-19;
	double electrons;
	printf("Enter the charge:");
	scanf("%lf", &charge);

	printf("\nThe charge of an electron is -1.602 x e-19");
	electrons = (charge/chargeE) *-1;
	printf("\nThe number of electrons in the charge are: %lf", electrons);
	printf("\nThe number of electrons in the charge are: %le", electrons);

	getchar();
	getchar();
}
