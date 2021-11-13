/*
 * main.c
 *
 *  Created on: 6 Nov 2021
 *      Author: siddh
 */

# include <stdio.h>
# include <stdint.h>


int main(void)

{

	uint8_t someData[10] = {0xFF,0xFF,0xFF,0xFF,0xFFFF,0xFFFF,0xFF,0xFF,0xFF,0xFF};

	printf("%#x\t", someData[5-8]);

	/*for(uint32_t i = 0; i<10; i++)
	{
		printf("%d\t", someData[i]);
	}*/


	return 0;
}
