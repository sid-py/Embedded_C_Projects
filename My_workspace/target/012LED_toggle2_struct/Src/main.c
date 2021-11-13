// Where is the LED connected?
//POrt:D
//Pin: 13

# include <stdint.h>

# define PERIPH_BASE 			(0x40000000UL)
# define AHB1PERIPH_OFFSET 		(0x00020C00UL)
# define AHB1PERIPH_BASE 		(PERIPH_BASE + AHB1PERIPH_OFFSET)
# define RCC_BASE		 		(0x40023800UL)
# define GPIOD_BASE 			(0x40020C00UL)
# define AHB1EN_R_OFFSET 		(0x30UL)
# define RCC_AHB1EN_R 			(*(volatile unsigned int *)(RCC_BASE + AHB1EN_R_OFFSET))
# define MODE_R_OFFSET 			(0x00UL)
#define GPIOD_MODE_R 			(*(volatile unsigned int *)(GPIOD_BASE + MODE_R_OFFSET))

#define OD_R_OFFSET 			(0x14UL)
# define GPIOD_OD_R 			(*(volatile unsigned int *)(GPIOD_BASE + OD_R_OFFSET))
# define GPIODEN 				(1U<<3)


#define LED_PIN 				(1U<<12)


//(1U << 24) // set bit 24 to 1
//&=~(1U<<25) // set bit 25 to 0


int main(void)
{
	//1. Enable clock access to GPIOD
	RCC_AHB1EN_R |= GPIODEN;

	//2. Set LED_PIN as output pin
	GPIOD_MODE_R |= (1U << 24); // set bit 24 to 1
	GPIOD_MODE_R &=~(1U<<25); // set bit 25 to 0

	while(1)
	{
		//3. Set LED_PIN high
		//GPIOD_OD_R |= LED_PIN;

		//4. Toggle LED Pin
		GPIOD_OD_R ^= LED_PIN;

		for (int i =0; i<100000; i++);


	}
}
