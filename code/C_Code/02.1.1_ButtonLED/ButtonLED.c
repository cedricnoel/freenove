/**
 * \file main.c
 * \brief Turn a LED on with a button
 * \author Cédric Noël
 * \version 1.0.0
 * \date 27/09/2020
 */

#include <wiringPi.h> // WiringPi module
#include <stdio.h>    // Used for printf etc.

#define ledPin    0   // WiringPi number for GPIO17
#define buttonPin 1   // WiringPi number for GPIO18

int  ledState        = LOW;  //store the State of led
int  buttonState     = HIGH; //store the State of button
int  lastbuttonState = HIGH; //store the lastState of button
long lastChangeTime;         //store the change time of button state
long captureTime     = 50;   //set the stable time for button state (milliseconds)
int  reading;

/**
 * \fn void displayLEDMessage (int state)
 * \brief Display message depending on led state
 * 
 * \param int state Current LED state
 * 
 * \return void
 */
void displayLEDMessage(int state) {
	if (state) {
		printf("LED turn ON !\n");
	} else {
		printf("LED turn OFF ...\n");
	}
}

/**
 * \fn int handleLEDState (void)
 * \brief Handle LED state change
 * 
 * \return int
 */
int handleLEDState(void) {
	// If button state has changed, update the data
	if (reading == buttonState) {
		return ledState;
	}
	// Update button state
	buttonState = reading;
	
	// If the state is low, it means the action is pressing
	if (buttonState == LOW) {
		printf("Button is pressed !\n");
		ledState = !ledState; // Inverse LED state
		displayLEDMessage(ledState);
	}
	
	return ledState;
}

/**
 * \fn int main (void)
 * \brief Program main function
 * 
 * \return int
 */
int main(void) {
	printf("Program is starting ...\n");
	
	wiringPiSetup(); // Setup WiringPi
	
	pinMode(ledPin, OUTPUT);   // Set ledPin (GPIO17) mode to OUTPUT
	pinMode(buttonPin, INPUT); // Set buttonPin (GPIO18) mode to OUTPUT
	
	pullUpDnControl(buttonPin, PUD_UP); // ?????
	
	// Infinite loop
	while (1) {
		reading = digitalRead(buttonPin); // Read the current state of button
		if (reading != lastbuttonState) {
			// if the button state has changed, record the time point
			lastChangeTime = millis();
		}
		
		// if changing-state of the button last beyond the time we set, we consider that
		// the current button state is an effective change rather than a buffeting
		if (millis() - lastChangeTime > captureTime) { // If more than 50 milliseconds has passed
			// If button state has changed, update the data
			ledState = handleLEDState();
		}
		digitalWrite(ledPin,ledState);
		lastbuttonState = reading;
	}
	
	return 1;
}
