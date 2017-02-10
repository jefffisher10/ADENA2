#!/usr/bin/python

import time
import serial

ser = serial.Serial('/dev/ttyACM0', 9600)
time.sleep(2)

with open('/ADENA2/sensors/tap/tap_readings.txt', 'w') as outf:
	ser.write('r')
	x = ser.readline()
	outf.write(x)
	outf.flush()
#	outf.close()
