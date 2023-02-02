/*
 * OccupancyDetector.c
 *
 *  Created on: Feb 2, 2023
 *      Author: Joseff Santiago
 */

#include <msp430.h>

int main() {
    void gpioInit();

}


void gpioInit()
{
   // Setting Directions of Pins

       P1DIR |= BIT0;              // Configure P1.0 to an Output
       P6DIR |= BIT6;              // Configure P6.6 to an Output
       P2DIR &= ~BIT3;             // Configure P2.3 to an Input
       P4DIR &= ~BIT1;             // Configure P4.1 to an Input
       P2REN |= BIT3;              // Enable Resistor on P2.3
       P2OUT |= BIT3;              // Configure Resistor on P2.3 to be Pullup
       P4REN |= BIT1;              // Enable Resistor on P4.1
       P4OUT |= BIT1;              // Configure Resistor on P4.1 to be Pullup
}
