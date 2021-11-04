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
	uint8_t crc;
	uint8_t status;
	uint16_t payload;
	uint8_t bat;
	uint8_t sensor;
	uint8_t longAddr;
	uint8_t shortAddr;
	uint8_t addrMode;

};

int main(void)
{
	uint32_t packetVal;

	printf("Enter the 32-bit packet value:");
	scanf("%x", &packetVal);

	struct Packet packet;

	packet.crc 			= 	(uint8_t)(packetVal & 0x3);
	packet.status 		= 	(uint8_t)((packetVal >> 2) & 0x1);
	packet.payload 		= 	(uint16_t)((packetVal >> 3) & 0xFFF);
	packet.bat 			= 	(uint8_t)((packetVal >> 15) & 0x7);
	packet.sensor 		= 	(uint8_t)((packetVal >> 18) & 0x7);
	packet.longAddr 	= 	(uint8_t)((packetVal >> 21) & 0xFF);
	packet.shortAddr 	= 	(uint8_t)((packetVal >> 29) & 0x3);
	packet.addrMode 	= 	(uint8_t)((packetVal >> 31) & 0x1);


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
