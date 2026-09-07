#define F_CPU 14745600UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

ISR(INT4_vect){
	PORTB ^= (1 << PB0);
}

int main(void){
	DDRB |= (1<<PB0) | (1 << PB1);
	PORTB |= (1 << PB0) | (1 << PB1);
	
	DDRE &= ~(1 << PE4);
	PORTE |= (1 << PE4);
	
	EICRB |= (1 << ISC41);
	EICRB &= ~(1 << ISC40);
	
	EIMSK |= (1 << INT4);
	
	sei();
	
	while (1){
		PORTB ^= (1 << PB0);
		_delay_ms(1000);
	}
}