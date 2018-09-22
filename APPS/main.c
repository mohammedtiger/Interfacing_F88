
#include "../MCAL/F88_UART.h"
#include "../MCAL/F88_SPI.h"
#include <util/delay.h>

//#define MASTER_SPI
#define SLAVE_SPI

int main()
{

#ifdef MASTER_SPI
	F88_void_SPI_init(MASTER);
#endif

#ifdef SLAVE_SPI
	F88_void_SPI_init(SLAVE);
#endif

	F88_void_UART_init(9600);

	while(1)
	{
#ifdef MASTER_SPI

		F88_void_SPI_Write('A');
		_delay_ms(1);
		F88_void_SPI_Write('B');
		_delay_ms(1);
		F88_void_SPI_Write('C');
		_delay_ms(1000);
#endif

#ifdef SLAVE_SPI

		unsigned char data = F88_unsigned_char_SPI_Read();
		F88_void_UART_Write(data);
#endif


	}
	return 0;
}
