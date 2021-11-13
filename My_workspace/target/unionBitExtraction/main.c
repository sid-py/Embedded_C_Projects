/*
 * main.c
 *
 *  Created on: 5 Nov 2021
 *      Author: siddh
 */

# include<stdio.h>
# include<stdint.h>

union Packet
{
	uint32_t packetVal;
	struct{

		uint32_t crc 		:2;
		uint32_t status 	:1;
		uint32_t payload 	:12;
		uint32_t bat 		:3;
		uint32_t sensor 	:3;
		uint32_t longAddr	:8;
		uint32_t shortAddr	:2;
		uint32_t addrMode	:1;
	}packetFields;


};

int main(void)
{
	union Packet packet;
	printf("Enter the 32-bit packet value:");
	scanf("%X", &packet.packetVal);

	printf("crc: 		%#x\n", packet.packetFields.crc);
	printf("status: 	%#x\n", packet.packetFields.status);
	printf("payload: 	%#x\n", packet.packetFields.payload);
	printf("bat: 		%#x\n", packet.packetFields.bat);
	printf("sensor: 	%#x\n", packet.packetFields.sensor);
	printf("longaddr: 	%#x\n", packet.packetFields.longAddr);
	printf("shortaddr: 	%#x\n", packet.packetFields.shortAddr);
	printf("addrmode: 	%#x\n", packet.packetFields.addrMode);

	printf("Size of struct is : %d\n", sizeof(packet));

	getchar();
	getchar();

	return 0;
}
