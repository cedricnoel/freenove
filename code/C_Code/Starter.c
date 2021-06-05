/**
 * \file Starter.c
 * \brief Some description here
 * \author Cédric Noël
 * \version 1.0.0
 * \date 22/05/2021
 */
 
#include <wiringPi.h> // WiringPi module
#include <stdio.h>    // Used for printf etc.

// Define some const here

#define ledPin 1 // wiringPi GPIO17 number

/**
 * \fn void setup (void)
 * \brief Program setup function, used to make some setup before loop
 * to avoid doing it in the main function, adding more program 
 * complexity
 * 
 * \return void
 */
void setup(void)
{
	// Some code here
}

/**
 * \fn int main (void)
 * \brief Program main function, will start endless loop
 * 
 * \return int
 */
int main(void)
{
	printf("Program is starting ...\n");
	
	wiringPiSetup(); // Setup WiringPi
	
	setup(); // Launch our custom setup
	while (1) {
		// Some code here
	}
	
	return 1;
}
