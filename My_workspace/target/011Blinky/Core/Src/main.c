//PD12
//AHB1
//RCC->AHB1ENR
//GPIOx_MODER
//GPIOx_ODR

# include "stm32f4xx.h"

int main(void)

{
	RCC -> AHB1ENR |= 1; // Enabling GPIOD Clock
	GPIOD -> MODER |= (1<<24);

	while(1)
	{
		GPIOD -> ODR |= (1<<12);
	}
}
