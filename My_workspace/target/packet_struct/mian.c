/*
 * mian.c
 *
 *  Created on: 4 Nov 2021
 *      Author: siddh
 */

# include<stdio.h>
# include<stdint.h>

struct Packet
{
	uint32_t crc 		:2;
	uint32_t status 	:1;
	uint32_t payload 	:12;
	uint32_t bat 		:3;
	uint32_t sensor 	:3;
	uint32_t longAddr	:8;
	uint32_t shortAddr	:2;
	uint32_t addrMode	:1;

};

int main(void)
{
	uint32_t packetVal;

	printf("Enter the 32-bit packet value:");
	scanf("%x", &packetVal);

	struct Packet packet;

	packet.crc 			= 	(uint32_t)(packetVal & 0x3);
	packet.status 		= 	(uint32_t)((packetVal >> 2) & 0x1);
	packet.payload 		= 	(uint32_t)((packetVal >> 3) & 0xFFF);
	packet.bat 			= 	(uint32_t)((packetVal >> 15) & 0x7);
	packet.sensor 		= 	(uint32_t)((packetVal >> 18) & 0x7);
	packet.longAddr 	= 	(uint32_t)((packetVal >> 21) & 0xFF);
	packet.shortAddr 	= 	(uint32_t)((packetVal >> 29) & 0x3);
	packet.addrMode 	= 	(uint32_t)((packetVal >> 31) & 0x1);


	printf("crc: 		%#x\n", packet.crc);
	printf("status: 	%#x\n", packet.status);
	printf("payload: 	%#x\n", packet.payload);
	printf("bat: 		%#x\n", packet.bat);
	printf("sensor: 	%#x\n", packet.sensor);
	printf("longaddr: 	%#x\n", packet.longAddr);
	printf("shortaddr: 	%#x\n", packet.shortAddr);
	printf("addrmode: 	%#x\n", packet.addrMode);

	printf("Size of struct is : %d\n", sizeof(packet));

	getchar();
	getchar();

	return 0;
}
