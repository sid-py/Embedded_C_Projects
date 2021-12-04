# include "stm32f4xx.h"


# define GPIODEN  		(1U<<3)
# define GPIOAEN  		(1U<<0)

# define LED_PIN 		(1U<<13)

# define BTN_PIN13 			(1U<<0)

int main(void)
{
	// Enable clock access to GPIO A

	RCC->AHB1ENR |= GPIODEN;
	RCC->AHB1ENR |= GPIOAEN;
		//2. Set LED_PIN as output pin
		GPIOD->MODER |= (1U << 26); // set bit 26 to 1
		GPIOD->MODER &=~(1U<<27); // set bit 27 to 0

		//Set pin1 as input pin
		GPIOA-> MODER &=~(1U<<0);
		GPIOA-> MODER &=~(1U<<1);

		while(1)
		{
			//Check if BTN is pressed

			if(GPIOA->IDR & BTN_PIN13)
			{
			GPIOD->BSRR = LED_PIN;

			}
			else{
			GPIOD->BSRR = (1U << 29);

			}
		}
}
