#!/usr/bin/env python3
########################################################################
# Filename    : Doorbell.py
# Description : Make doorbell with buzzer and button
# auther      : www.freenove.com
# modification: 2019/12/28
########################################################################

import RPi.GPIO as GPIO # importing GPIO library

# define some variables here

ledPin    = 11  # define buzzerPin (physical number for GPIO17)
buttonPin = 12  # define buttonPin (physical number for GPIO18)

def setup():
    GPIO.setmode(GPIO.BOARD)          # use PHYSICAL GPIO Numbering
    GPIO.setup(buzzerPin, GPIO.OUT)   # set buzzerPin to OUTPUT mode
    GPIO.setup(buttonPin, GPIO.IN, pull_up_down=GPIO.PUD_UP)    # set buttonPin to PULL UP INPUT mode

def loop():
    while True:
        # some code here ...

def destroy():
    GPIO.cleanup() # Release all GPIO

if __name__ == '__main__':     # Program entrance
    print ('Program is starting...')
    setup()
    try:
        loop()
    except KeyboardInterrupt:  # Press ctrl-c to end the program.
        destroy()
