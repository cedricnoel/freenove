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

#define buzzerPin 0 // wiringPi GPIO17 number
#define buttonPin 1 // wiringPi GPIO18 number

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
	pinMode(buzzerPin, OUTPUT); 
	pinMode(buttonPin, INPUT);
	pullUpDnControl(buttonPin, PUD_UP);  // pull up to HIGH level
}

/**
 * \fn void tunrOnBuzzer (void)
 * \brief Function will turn on buzzer
 * 
 * \return void
 */
void turnOnBuzzer(void)
{
	digitalWrite(buzzerPin, HIGH); // Turn on buzzer
	printf("Buzzer turn on !! \n");
}

/**
 * \fn void tunrOffBuzzer (void)
 * \brief Function will turn off buzzer
 * 
 * \return void
 */
void turnOffBuzzer(void)
{
	digitalWrite(buzzerPin, LOW); // Turn off buzzer
	printf("Buzzer turn off ... \n");
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
		// Button is pressed
		if (digitalRead(buttonPin) == LOW) {
			turnOnBuzzer();
		} else { // Button is released
			turnOffBuzzer();
		}
	}
	
	return 1;
}
