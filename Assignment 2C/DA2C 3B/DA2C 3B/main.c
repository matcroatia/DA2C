/*
 * DA2C 3B.c
 *
 * Created: 3/23/2019 10:52:37 PM
 * Author : Mat Tomljenovic
 */ 

#include <avr/io.h>
#define F_CPU   16000000UL
#include <util/delay.h>
#include <avr/interrupt.h>

int main(void)
{

	DDRB |= (1 << PB2);				//set PB2 as output port
	PORTC = (1 << PINC2);		    //set PINC as input
	TCNT0 = 0;					    //initiate timer
	TCCR0A |= (1 << WGM01);			//initiate CTC mode
	TCCR0B |= 0x05;					//set pre-scaler to 1024
	TIMSK0 |= (1 << OCIE0A);		//enable Overflow compare
	sei ();							//enable interrupt
	
	while (1)
	{
		
	}
	
}

ISR(TIMER0_COMPA_vect)					//compare interrupt loop
{
	uint8_t OVFCount=0;					//initiate overflow count
	TCNT0=0x00;							//reset the timer to zero
	OVFCount++;							//increment overflow count
	
	DDRB = 0x02;						//sets PB2 as output
	while(1)							//loop for while LED on
	{
		if ((PINC & (1 << PC2)) == (1<<PC2)) //if to light up LED when button is pressed
		{
			PORTB = 0xFF;				//Turns ON LED
			_delay_ms(600);				//1.2 second delay
			PORTB = 0;					//Turns OFF LED
		}
	}
	
}

