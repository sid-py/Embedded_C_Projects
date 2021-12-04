# include "stm32f4xx.h"


# define GPIODEN  		(1U<<3)
# define LED_PIN 		(1U<<12)

int main(void)
{
	RCC->AHB1ENR |= GPIODEN;
		//2. Set LED_PIN as output pin
		GPIOD->MODER |= (1U << 24); // set bit 24 to 1
		GPIOD->MODER &=~(1U<<25); // set bit 25 to 0

		while(1)
		{
			GPIOD->ODR ^= LED_PIN;
			for (int i =0; i<10; i++);
		}
}
