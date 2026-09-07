/*
 * GccApplication1.c
 *
 * Created: 2026-08-31 오전 11:27:18
 * Author : User
 */ 

#define F_CPU 1475600UL

#include <avr/io.h>
#include <util/delay.h>

int main(void){
	DDRB = 0xFF;
	
	while(1){
		PORTB = 0x00;
		_delay_ms(1000);
		
		PORTB = 0xFF;
		_delay_ms(1000);
	}
}