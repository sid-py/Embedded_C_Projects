
# include "uart.h"

# include "stm32f4xx.h"
# include <stdint.h>


int main(void)
{

		uar2_tx_init();
		while(1)
		{

			uart2_write('Y');

		}
}
