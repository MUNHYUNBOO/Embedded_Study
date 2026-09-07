#define F_CPU 14745600UL
#include <avr/io.h>

int main(void){
	DDRB = 0xFF;
	PORTB = 0xFF;
	
	DDRF &= ~(1 <<PF1);
	
	ADMUX = (1 << REFS0) | (1 << MUX0);
	
	ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
	
	while (1)
	{
		ADCSRA |= (1 << ADSC);
		
		while (ADCSRA & (1 << ADSC));
		
		unsigned char n = (ADC*9UL) / 1024;
		
		unsigned char led_pattern = (1 << n) -1;
		
		PORTB = ~led_pattern;
	}
}