#define F_CPU 14745600UL
#include <avr/io.h>

int main(void){
	DDRB |= (1 << PB0);
	PORTB |= (1 << PB0);
	
	DDRE &= ~(1 << PE4);
	PORTE |= (1 << PE4);	
	
	while (1)
	{
		if (!(PINE & (1 << PE4))){
			PORTB &= ~(1 << PB0);
		}
		else{
			PORTB |= (1 << PB0);
		}
	}
}