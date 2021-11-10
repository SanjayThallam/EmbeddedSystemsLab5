#include <msp430.h> 
#define GREENLED BIT0 //create enums for Red and Green LEDs
#define REDLED BIT6

/**
 * main.c
 */
int main(void)
{
    P1DIR = GREENLED|REDLED; //set red and green led's to output
    P1OUT = GREENLED; //start with green led on, red led off

    BCSCTL2 |= DIVS_3; //clock divider by 8
    WDTCTL = WDT_MDLY_32; //set the WDT timer interval
	IE1 = WDTIE; //enable WDT interrupts

	_enable_interrupts(); // enable interrupts to occur

	return 0;
}

#pragma vector=WDT_VECTOR //create interrupt vector for WDT
__interrupt void WDT(void)
{
    P1OUT ^= GREENLED|REDLED; //toggle the red and green LEDS
}


