/*
 * F88_SPI.h
 *
 *  Created on: Sep 22, 2018
 *      Author: root
 */

#ifndef F88_SPI_H_
#define F88_SPI_H_

#include <avr/io.h>

enum
{
	MASTER,
	SLAVE
};

#define SPI_DIR				DDRB
#define SPI_PORT			PORTB
#define SPI_MOSI			PB5
#define SPI_MISO			PB6
#define SPI_SCK				PB7
#define SPI_SS				PB4

#define SPI_CONTROL_PORT		SPCR
#define SPI_ENABLE_PIN			SPE
#define SPI_MASTER_PIN			MSTR
#define SPI_PRESCALER_PIN		SPR0


void F88_void_SPI_init(char mode);
void F88_void_SPI_Write(unsigned char data );
unsigned char F88_unsigned_char_SPI_Read();


#endif /* F88_SPI_H_ */
