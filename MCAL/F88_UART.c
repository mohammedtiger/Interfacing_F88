

#include <avr/io.h>
#include "F88_UART.h"
#include <avr/interrupt.h>
#include "../Service_Layer/CircularBuffer/CircularBuffer.h"


CircularBuffer queue;


void  F88_void_UART_init(unsigned long baud)
{

	unsigned long baud_rate = (F_CPU / (16 * baud))-1;

	UBRRH = (unsigned char )(baud_rate >> 8);
	UBRRL = (unsigned char )baud_rate;
	UCSRB = (1 << RXEN) | (1 << TXEN) | (1 << RXCIE);
	UCSRC = (1 << URSEL) | (1 <<UCSZ1) | (1 <<UCSZ0);
	sei();
	CircularBuffer_ctor(&queue);
}

void F88_void_UART_Write(unsigned char data)
{
	while(!(UCSRA & (1 << UDRE)));
	UDR = data;

}


//void F88_void_UART_Read(unsigned char *data)
//{
//	while((UCSRA & (1 << RXC)) == 0);
//	*data = UDR;
//}

unsigned char F88_unsigned_char_UART_Read_Queue()
{
	unsigned char data = 0;
	if(!(queue.isEmpty(&queue)))
	{
		queue.dequeue(&queue , &data);
	}
	return data;
}

ISR(USART_RXC_vect)
{

	if(!(queue.isFull(&queue)))
	{
		queue.enqueue(&queue , UDR);
	}
}
