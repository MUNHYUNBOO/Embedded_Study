#define F_CPU 14745600UL
#include <avr/io.h>
#include <avr/interrupt.h>

ISR(TIMER1_COMPA_vect){
	PORTB ^= (1 << PB0);
}

int main(void){
	DDRB |= (1 << PB0);
	PORTB |= (1 << PB0);
	
	OCR1A = 57599;
	
	TCCR1B |= (1 << WGM12) | (1 << CS12);
	
	TIMSK |= (1 << OCIE1A);
	
	sei();
	
	while (1){
		
	}
}