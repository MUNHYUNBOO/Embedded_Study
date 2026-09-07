#define F_CPU 14745600UL
#include <avr/io.h>
#include <avr/interrupt.h>

#define BAUD 9600
#define UBRR_VALUE ((F_CPU / (16UL * BAUD)) -1)

ISR(USART1_RX_vect){
	unsigned char data = UDR1;
	
	while (!(UCSR1A & (1 << UDRE1)));
	UDR1 = data;
	
	if(data == '1'){
		PORTB &= ~(1 << PB0);
	}
	else if(data == '0'){
		PORTB |= (1 << PB0);
	}
}


void UART1_Init(void){
	UBRR1H = (unsigned char)(UBRR_VALUE >> 8);
	UBRR1L = (unsigned char)UBRR_VALUE;
	
	UCSR1B = (1 << RXEN1) | (1 << TXEN1) | (1 << RXCIE1);
	
	UCSR1C = (1 << UCSZ11) | (1 << UCSZ10);
}

void UART1_Transmit(char data) {
	while (!(UCSR1A & (1 << UDRE1)));
		
	UDR1 = data;
}


void UART1_Print(const char* str) {
	while (*str) {
		UART1_Transmit(*str++);
	}
}

int main(void) {
	DDRB |= (1 << PB0);
	PORTB |= (1 << PB0); 

	UART1_Init(); 
	sei();        

	
	UART1_Print("\r\n=== ATmega128 UART Command System ===\r\n");
	UART1_Print("Press '1' to LED ON, '0' to LED OFF\r\n");

	while (1) {
		
	}
}