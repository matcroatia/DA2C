/*
 * DA2C 1B.c
 *
 * Created: 3/23/2019 6:36:03 PM
 * Author : Mat Tomljenovic
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL

int main(void)
{
	uint8_t OVFCount = 0;    //initiates unit overflow counter
	TCCR0B = 0x05;           //initiates timer0
	TCNT0 = 0x00;			 //initiates counter
	DDRB = 0xFF;             //sets PB2 as output
	while(1)                 //loop for while LED on
	{
		
			//while((TIFR0 & 0x01) == 1) //loop while overflow flag is set
			//{
				if ((PINC & (1 << PC2)) == (1<<PC2)) //if to light up LED when button is pressed
				{
					PORTB = 0xFF; //Turns ON LED
					TCNT0 = 0x00;		   //initiate counter to 0
					TIFR0 = 0x01;		   //set timer overflow count to 1
					OVFCount++;			   //increment overflow counter
					if (OVFCount == 39)	   //set overflow count limit
					{
						PORTB = 0; 
						OVFCount = 0;            //Turns OFF LED
					}
				}
			//}
	
	}
}

