#include<avr/io.h>
#include<util/delay.h>
 
int Q0, Q1, Q2; //inputs
int D0, D1, D2, CLK; //output
 
int main(void){
    DDRD = 0b11100011;
    DDRB = 0b00100111;

    while(1){
	    PORTB |= (1<<PB5);
	    _delay_ms(1000);

	    Q0 = (PIND & (1 << PD2)) >> PD2;
	    Q1 = (PIND & (1 << PD3)) >> PD3;
	    Q2 = (PIND & (1 << PD4)) >> PD4;
	    D2 = (Q2 && !Q0) || (Q0 && !Q2);
	    D1 = (Q2);
	    D0 = (Q1);

	    PORTB &= ~(1 << PB5);

	    PORTB = (D0 << PB0) | (D1 << PB1) | (D2 << PB2);
    }
}
