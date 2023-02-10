/*
 * OccupancyDetector.c
 *
 *  Created on: Feb 2, 2023
 *      Author: Joseff Santiago
 */

#include <msp430.h>

void gpioInit();

int main() {
    int i=0;                    //register used to track the time the system is in warning state
    int state;                  //register used to track what state the system is currently in
    gpioInit();                 //calls the function to initialize the pins and ports and doodads
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;       //not sure what this does but it was in every other thing so i put it here

    while(1){
            if((P4IN&BIT1)&(i<=9)){
                state=2;                  //state=2, self explanatory
                i++;                      //increments this register. when it hits 10, it will activate the special sauce
                __delay_cycles(1000000);  //probably a better way to tack that 10 seconds have passed but this one works i guess.
            }
            else if((P4IN&BIT1)&(i>=10)){ //the aforementioned special sauce
                state=3;                  //state=3
            }
            else {state=1;}               //if button not pressed defaults to a specific state
      switch(state){
      case 1: P1OUT ^= BIT0; P6OUT &=~BIT6; __delay_cycles(500000); break;  //blinks green led on a half second cycle, armed cycle but nothing detected
      case 2: P1OUT &=~BIT0; P6OUT ^= BIT6; __delay_cycles(250000); break;  //turns green off and blinks red on a quarter second cycle, warning state
      case 3: P1OUT &=~BIT0; P6OUT |= BIT6; break;}                         //keeps red on and turns red off, ALARM state
    }
}
void gpioInit()                    //using a function to set my ins instead of cluttering my main function
{
       P1DIR |= BIT0;              // Configure P1.0 to an Output
       P6DIR |= BIT6;              // Configure P6.6 to an Output
       P2DIR &= ~BIT3;             // Configure P2.3 to an Input
       P4DIR &= ~BIT1;             // Configure P4.1 to an Input
       P2REN |= BIT3;              // Enable Resistor on P2.3
       P2OUT |= BIT3;              // Configure Resistor on P2.3 to be Pullup
       P4REN |= BIT1;              // Enable Resistor on P4.1
       P4OUT |= BIT1;              // Configure Resistor on P4.1 to be Pullup
}
