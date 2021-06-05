import RPi.GPIO as GPIO

ledPin = 11       # define ledPin, using physical number
buttonPin = 12    # define buttonPin, using physical number
ledState = False

def setup():
	GPIO.setmode(GPIO.BOARD)     # use PHYSICAL GPIO Numbering
	GPIO.setup(ledPin, GPIO.OUT) 
	GPIO.setup(buttonPin, GPIO.IN, pull_up_down=GPIO.PUD_UP) # set buttonPin to PULL UP INPUT mode

def buttonEvent(channel):
	global ledState
	ledState = not ledState
	print ('buttonEvent GPIO%d' %channel)
	if ledState:
		print("LED tun on >>>>")
	else:
		print("LED turn off >>>>")
	GPIO.output(ledPin,ledState)

def loop():
	# Button detect 
	GPIO.add_event_detect(buttonPin, GPIO.FALLING, callback = buttonEvent, bouncetime = 300)
	while True:
		pass

def destroy():
	GPIO.cleanup() # Release GPIO resource

##############################
### PROGRAM EXECUTION PART ###
##############################

if __name__ == '__main__':     # Program entrance
	print ('Program is starting...')
	setup()
	try:
		loop()
	except KeyboardInterrupt:  # Press ctrl-c to end the program.
		destroy()
