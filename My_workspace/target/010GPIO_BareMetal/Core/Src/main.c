#include "stm32f4xx.h"

//PA5

//AHB1

//Set bit 0 RCC_AHB1ENR to 1

#define GPIOA_EN (1 << 0) // 0b 0000 0000 0000 0000 0000 0000 0000 0001

// set bit 10 to 1 and bit 11 to 0 in GPIOA_MODER

#define MODER_12_OUT (1<<10) // 0b 0000 0000 0000 0000 0000 0100 0000 0000

// write 1 to GPIOA_ODR bit 5 to set PA5 on an write zero to set it off.

#define ODR_12_SET (1<<5)
#define ODR_12_RESET (0<<5)
#define LED_PIN (1<<5)
int main(void)
{
	RCC->AHB1ENR |= GPIOA_EN;
	GPIOA->MODER |= MODER_12_OUT;

	while (1){
		for(int i = 0; i< 90000000; i++);
		GPIOA -> ODR ^= ODR_12_SET;

	}
}
