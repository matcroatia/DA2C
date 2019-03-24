/*
 * DA2C 3A.c
 *
 * Created: 3/23/2019 10:38:50 PM
 * Author : Mat Tomljenovic
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int main(void)
{
	
	
	DDRB |= (1 << PB2);		  //sets POTRB as output
	TIMSK0 |= (1 << OCIE0A);  //enable overflow compare register
	TCNT0 = 0;				  //initiate timer 
	TCCR0A |= (1 << WGM01);	  //enable CTC mode
	TCCR0B |= 0x05;			  //enable timer 0
	sei();					  //enable interrupt
	while (1)
	{
		
	}
}
uint8_t OVFCount=0;				//intialize overflo counter

ISR (TIMER0_COMPA_vect)		    //timer0 overflow interrupt
{
	TCNT0=0x00;				    //resets the timer
	OVFCount++;				    //increment overflow count
	
	if (OVFCount == 12)		    //overflow for delay off
	{
		PORTB= ~(1 << PORTB2);	//turn LED off
	}
	if(OVFCount == 22)			//overflow delay on
	{
		
		PORTB = (1 << PORTB2);	//turns LED on
		OVFCount = 0;			//reset overflow counter
	}


}


