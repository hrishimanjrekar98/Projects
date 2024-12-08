import time
import RPi.GPIO as gpio
gpio.setmode(gpio.BOARD)
import os
import Mail as m
Trig=3
Echo=5
gpio.setup(Trig,gpio.OUT)
gpio.setup(Echo,gpio.IN)
gpio.output(Trig,False)
gpio.setwarnings(False)
while True:
	gpio.output(Trig,True)
	time.sleep(2)
	gpio.output(Trig,False)
	while gpio.input(Echo)==0:
		pulse_start = time.time()
	while gpio.input(Echo)==1:
		pulse_end=time.time()
	pulse_duration=pulse_end-pulse_start
	distance=pulse_duration*17150
	distance=round(distance+1.15,2)
	if distance > 10 and distance<50:
		print(distance)
		print("Motion detected")
	        os.system('sudo fswebcam capture.jpeg')
		time.sleep(1)
		m.sendmail()
		print("Mail Sent")
		from twilio.rest import Client
		account_sid ="AC0209ea0e9989b12e174f114c0d163686" # Put your Twilio account SID$
		auth_token ="12bfec36411f5f7843ed182a7f33f8ee" # Put your auth token here
		client = Client(account_sid, auth_token)
		message = client.api.account.messages.create(
		to="+917738178054", # Put your cellphone number here
		from_="+17573491127", # Put your Twilio number here
		body="Some Object is detected at outside of your home")
		print("Mail Sent")
		print("Mail Sent")
	else:
		print("Motion Not detected")
		print(distance)
