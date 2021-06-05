/**
 * \file BreathingLED.c
 * \brief Make a LED breath using PWN
 * \author Cédric Noël
 * \version 1.0.0
 * \date 22/05/2021
 */
 
#include <wiringPi.h> // WiringPi module
#include <stdio.h>    // Used for printf etc.
#include <softPwm.h>

#define ledPin 1      // WiringPi number for GPIO18

/**
 * \fn int main (void)
 * \brief Program main function
 * 
 * \return int
 */
int main(void) {
	printf("Program is starting ...\n");
	
	wiringPiSetup();               // Setup WiringPi
	
	softPwmCreate(ledPin, 0, 100); // Create SoftPWM pin

	int i;
	
	// Begining of endless loop
	while (1) {
		// Making LED brighter
		for (i = 0; i < 100; i++) {
			softPwmWrite(ledPin, i);
			delay(20);
		}
		
		delay(300); // Adding some delay between breaths
		
		// Making LED darker
		for (i = 100; i >= 0; i--) {
			softPwmWrite(ledPin, i);
			delay(20);
		}
		
		delay(300); // Adding some delay between breaths
	}
	
	return 1;
}
