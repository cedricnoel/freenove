/**
 * \file Starter.c
 * \brief Some description here
 * \author Cédric Noël
 * \version 1.0.0
 * \date 22/05/2021
 */
 
#include <wiringPi.h> // WiringPi module
#include <stdio.h>    // Used for printf etc.
#include <softPwm.h>  // PWM library
#include <stdlib.h>

// Define some const here

#define ledPinRed   0   // wiringPi GPIO18 number
#define ledPinGreen 1   // wiringPi GPIO18 number
#define ledPinBlue  2   // wiringPi GPIO27 number

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
	softPwmCreate(ledPinRed, 0, 100);  // Create SoftPWM pin for red
	softPwmCreate(ledPinGreen,0, 100); // Create SoftPWM pin for green
	softPwmCreate(ledPinBlue, 0, 100); // Create SoftPWM pin for blue
}

/**
 * \fn void setLedColor (int red, int green, int blue)
 * \brief Set color for RGB LED using red, green, and blud value
 * 
 * \param int red   Red color value
 * \param int green Green color value
 * \param int blue  Blue color value
 * 
 * \return int
 */
void setLedColor(int red, int green, int blue)
{
	softPwmWrite(ledPinRed, red);     // Set the duty cycle
	softPwmWrite(ledPinGreen, green); // Set the duty cycle
	softPwmWrite(ledPinBlue, blue);   // Set the duty cycle
}

/**
 * \fn int main (void)
 * \brief Program main function, will start endless loop
 * 
 * \return int
 */
int main(void) {
	printf("Program is starting ...\n");
	
	wiringPiSetup(); // Setup WiringPi
	
	int red, green, blue;
	
	setup(); // Launch our custom setup
	while (1) {
		red = random() % 100;
		green = random() % 100;
		blue = random() % 100;
		
		setLedColor(red, green, blue);
		
		delay(1000);
	}
	
	return 1;
}
