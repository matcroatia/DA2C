/*
 * DA2C 2B.c
 *
 * Created: 3/23/2019 9:27:39 PM
 * Author : Some guy
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
int main(void)
{
	
	DDRB |= (1 << PB2);      //sets PB2 as output
	TCCR0B = 0x05;           //initiates timer0
	TCNT0 = 0x00;			 //initiates counter
	TIMSK0 |= (1 << TOIE0);  //enable external interrupt 0
	sei();                   //enable interrupts
	while(1)
	{
		
	}
	
}
ISR (TIMER0_OVF_vect)          //ISR for external interrupt 0
{
	DDRB |= (1 << PB2); //Makes first pin of PORTB as Output
	
	DDRC &= ~(1<<PC2);//Makes first pin of PORTC as Input
	
	DDRB = 0xFF; //sets PB2 as output
	while(1)     //loop for while LED on
	{
		if (PINC & (1<<PC2) == 1) //if to light up LED when button is pressed
		{
			PORTB = 0xFF; //Turns ON LED
			_delay_ms(1200); //1.2 second delay
			PORTB = 0; //Turns OFF LED
		}
	}
}

