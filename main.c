/*
 * main.c
 *
 *  Created on: Dec 5, 2013
 *      Author: C15Craig.ODaniel
 */
// TI example code

#include <msp430g2553.h>
#include "sensor.h"

int main(void)
{
	  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
	  P1DIR |= BIT0|BIT6;                           // Set P1.0 to output direction

	  initSensors();

	while(1){

	    if (left_Sensor() < 0x250)
	      P1OUT &=~ BIT0;                       // Clear P1.0 LED off
	    else
	      P1OUT |= BIT0;
	    if (right_Sensor() < 0x250)
	      P1OUT &=~ BIT6;                       // Clear P1.6 LED off
	    else
	      P1OUT |= BIT6;                        // Set P1.6 LED on
	}

}





