#include "msp430G2553.h"
void main(void)
{
 WDTCTL = WDTPW + WDTHOLD;  // Stop WDT
 TA0CTL = TASSEL_2 + MC_1+ID_3;//+TACLR;
 TA0CCR0 = 31249; // Set maximum count value (PWM Period)
 TA0CCR1 = 6250; // initialise counter compare value
//TA0CCTL1 |= OUTMOD_7;        // PWM set to reset
 P1DIR |= BIT6; //set red led to the output
 TA0CCTL0 |= CCIE; //enable interrupt for timer 0
 TA0CCTL1 |= CCIE; //enable interrupt for timer 1
 TA0CCTL0 &=~CCIFG; //clear interrupt flags for timer 0
 TA0CCTL1 &=~CCIFG; //clear interrupt flags for timer 1

 _enable_interrupts(); // Enter LPM0
}
#pragma vector = TIMER0_A0_VECTOR       //define the interrupt service vector
__interrupt void TA0_ISR (void)    // interrupt service routine
{
    P1OUT |=BIT6; //enable red led
    TA0CCTL0 &=~CCIFG; //clear the interrupt flags
}
#pragma vector = TIMER0_A1_VECTOR       //define the interrupt service vector
__interrupt void TA1_ISR (void)    // interrupt service routine
{
    P1OUT &=~BIT6; //enable red led
    TA0CCTL1 &=~CCIFG; //clear the interrupt flags
}
