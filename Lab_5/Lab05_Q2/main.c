#include <msp430.h> 
#define LED BIT6


/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	P1DIR = LED; // set LED pin as output
	P1SEL = LED; //connect LED to the PWM Signal
	TA0CTL = TASSEL_2 + MC_1; // configure timer to use 1 MHz clock and to count up mode
	BCSCTL2 |= DIVS_3; //divide clock signal by 8
	TA0CCR0 = 62499; //set TA0CCR0 to count upto 62499
	TA0CCR1 = 6250; //set TA0CCR1 to count upto 6250
	TA0CCTL1 = OUTMOD_7; //Set the outmode to count up mode


	return 0;
}
