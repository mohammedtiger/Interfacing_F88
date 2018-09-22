
#include <avr/io.h>
#include "F88_SPI.h"

void F88_void_SPI_init(char mode)
{
	switch(mode)
	{
	case MASTER:
		SPI_DIR = (1 << SPI_MOSI) | (1 << SPI_SS) | (1 <<SPI_SCK);
		SPI_CONTROL_PORT = (1 << SPI_ENABLE_PIN) | (1 << SPI_MASTER_PIN) | (1 << SPI_PRESCALER_PIN);
		break;
	case SLAVE:
		SPI_DIR = (1 << SPI_MISO);
		SPI_CONTROL_PORT = (1 << SPI_ENABLE_PIN);
		break;
	}

}

void F88_void_SPI_Write(unsigned char data )
{
	SPI_PORT &= ~(1 << SPI_SS);
	SPDR = data;
	while(!(SPSR & (1 << SPIF)));
}


unsigned char F88_unsigned_char_SPI_Read()
{
	while(!(SPSR & (1 << SPIF)));
	return SPDR ;

}
