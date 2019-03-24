/*
 * Assignment 2C.c
 *
 * Created: 3/16/2019 11:28:38 PM
 * Author : tomljeno
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL


int main(void)
{
	uint8_t OVFCount = 0;    //initiates unit overflow counter
	DDRB |= (1 << PB2);      //sets PB2 as output
	TCCR0B = 0x05;           //initiates timer0
	TCNT0 = 0x00;			 //initiates counter
	
	while(1)
	{
		while((TIFR0 & 0x01) == 1) //loop while overflow flag is set
		{
			TCNT0 = 0x00;		   //initiate counter to 0
			TIFR0 = 0x01;		   //set timer overflow count to 1
			OVFCount++;			   //increment overflow counter
			if (OVFCount == 13)	   //set overflow count limit
			{
				PORTB ^= (1 << PB2);  //turns on LED
				OVFCount = 0;		  //resets over flow count to 0
				while((TIFR0 & 0x01) == 1) //loop while overflow flag is set
				{
					TCNT0 = 0x68;			//counter initiated at 0x68
					TIFR0 = 0x01;			//set timer overflow count to 1
					OVFCount++;				//increment overflow counter
					if (OVFCount == 9)		//set overflow count limit
					{
						PORTB &= ~(1<<PB2); //turn off LED
						OVFCount = 0;		//reset overflow counter to 0
					}
				}
			}
		}
	}
	
}
