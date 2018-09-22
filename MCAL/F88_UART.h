/*
 * F88_UART.h
 *
 *  Created on: Sep 21, 2018
 *      Author: root
 */

#ifndef F88_UART_H_
#define F88_UART_H_

void  F88_void_UART_init(unsigned long baud);
void F88_void_UART_Write(unsigned char data);
//void F88_void_UART_Read(unsigned char *data);
unsigned char F88_unsigned_char_UART_Read_Queue();


#endif /* F88_UART_H_ */
