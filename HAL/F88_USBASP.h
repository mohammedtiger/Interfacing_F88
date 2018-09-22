/*
 * F88_USBASP.h
 *
 *  Created on: Sep 22, 2018
 *      Author: root
 */

#ifndef F88_USBASP_H_
#define F88_USBASP_H_

void F88_void_Usbasp_init(unsigned long baud);
void F88_void_Usbasp_Write(unsigned char data );
unsigned char F88_unsigned_char_Usbasp_Read(unsigned char data);


#endif /* F88_USBASP_H_ */
