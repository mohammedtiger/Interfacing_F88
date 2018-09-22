


#include "../MCAL/F88_UART.h"
#include "F88_USBASP.h"


void F88_void_Usbasp_init(unsigned long baud)
{
	F88_void_UART_init(baud);
}

void F88_void_Usbasp_Write(unsigned char data )
{
	F88_void_UART_Write(data );
}
unsigned char F88_unsigned_char_Usbasp_Read(unsigned char data )
{
	return F88_unsigned_char_UART_Read_Queue();


}
