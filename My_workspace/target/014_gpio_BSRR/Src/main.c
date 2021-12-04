# include "stm32f4xx.h"


# define GPIODEN  		(1U<<3)
# define LED_PIN 		(1U<<13)

int main(void)
{
	RCC->AHB1ENR |= GPIODEN;
		//2. Set LED_PIN as output pin
		GPIOD->MODER |= (1U << 26); // set bit 26 to 1
		GPIOD->MODER &=~(1U<<27); // set bit 27 to 0

		while(1)
		{
			GPIOD->BSRR = LED_PIN;
			for (int i =0; i<100000; i++);

			GPIOD->BSRR = (1U << 29);
			for (int i =0; i<100000; i++);
		}
}
