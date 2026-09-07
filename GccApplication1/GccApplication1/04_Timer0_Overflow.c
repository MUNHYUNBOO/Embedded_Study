#define F_CPU 14745600UL
#include <avr/io.h>
#include <avr/interrupt.h>

static volatile unsigned char count = 0;

ISR(TIMER0_OVF_vect){
	count++;
	
	if(count >= 30){
		PORTB ^= (1 << PB0);
		count =0;
	}
}

int main(void){
	DDRB |= (1 << PB0);
	PORTB |= (1 << PB0);
	
	TCCR0 |= (1 << CS02) | (1 << CS00);
	
	TIMSK |= (1 << TOIE0);
	
	sei();
	
	while(1){
		
	}
}