
#include "../MCAL/F88_UART.h"
#include "../HAL/F88_RTC.h"
#include <util/delay.h>
#include <stdio.h>


int main()
{
	F88_void_UART_init(9600);
	F88_void_RTC_Init();


	unsigned char ss , mm ,hh;
	unsigned char data[100];
	while(1)
	{

		F88_void_RTC_GetTime(&ss , &mm ,&hh);

		int size = sprintf((char *)data , "Time : %d:%d:%d \n" , hh , mm ,ss);

		for (int index = 0 ; index < size ; index++)
			F88_void_UART_Write(data[index]);

		_delay_ms(1000);





	}
	return 0;
}
