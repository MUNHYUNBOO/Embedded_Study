#define F_CPU 14745600UL
#include <avr/io.h>
#include <util/delay.h>

int main(void) {

	DDRB |= (1 << PB4);

	TCCR0 = (1 << WGM01) | (1 << WGM00) | (1 << COM01) | (1 << COM00) | (1 << CS02);
	

	OCR0 = 0;
	
	while (1) {
		for(int duty = 0; duty <= 255; duty++) {
			OCR0 = duty;       
			_delay_ms(10);
		}
		
		for(int duty = 255; duty >= 0; duty--) {
			OCR0 = duty;
			_delay_ms(10);
		}
	}
}