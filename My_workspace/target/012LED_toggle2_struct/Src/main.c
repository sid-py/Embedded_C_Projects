// Where is the LED connected?
//POrt:D
//Pin: 13

# include <stdint.h>

# define PERIPH_BASE 			(0x40000000UL)
# define AHB1PERIPH_OFFSET 		(0x00020C00UL)
# define AHB1PERIPH_BASE 		(PERIPH_BASE + AHB1PERIPH_OFFSET)
# define RCC_BASE		 		(0x40023800UL)
# define GPIOD_BASE 			(0x40020C00UL)
# define GPIODEN 				(1U<<3)

# define __IO volatile // Misra rule to define volatile as __IO

#define LED_PIN 				(1U<<12)


//(1U << 24) // set bit 24 to 1
//&=~(1U<<25) // set bit 25 to 0

typedef struct
{
	__IO uint32_t MODER; // GPIO port mode register
	__IO uint32_t DUMMY[4]; // GPIO O/P type register

	__IO uint32_t ODR; // GPIO output data register


} GPIO_TypeDef;

typedef struct
{
	__IO uint32_t DUMMY [12]; // Dummy register to hold 12 register places
	__IO uint32_t AHB1ENR // RCC AHB1 peripheral clock register
} RCC_TypeDef;

# define RCC 		((RCC_TypeDef*)RCC_BASE)
# define GPIOD 		((GPIO_TypeDef*)GPIOD_BASE)

int main(void)
{
	//1. Enable clock access to GPIOD
	RCC->AHB1ENR |= GPIODEN;
	//2. Set LED_PIN as output pin
	GPIOD->MODER |= (1U << 24); // set bit 24 to 1
	GPIOD->MODER &=~(1U<<25); // set bit 25 to 0

	while(1)
	{
		GPIOD->ODR ^= LED_PIN;
		for (int i =0; i<100000; i++);
	}
}
