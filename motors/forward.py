#!/usr/bin/python
from Adafruit_MotorHAT import Adafruit_MotorHAT, Adafruit_DCMotor

import time
import atexit

# create a default object, no changes to I2C address or frequency
mh = Adafruit_MotorHAT(addr=0x60)

# recommended for auto-disabling motors on shutdown!
def turnOffMotors():
	mh.getMotor(1).run(Adafruit_MotorHAT.RELEASE)
	mh.getMotor(2).run(Adafruit_MotorHAT.RELEASE)
	mh.getMotor(3).run(Adafruit_MotorHAT.RELEASE)
	mh.getMotor(4).run(Adafruit_MotorHAT.RELEASE)

atexit.register(turnOffMotors)

#	MOTOR MAP:
#	(4)FL	(1)FR
#	(3)BL	(2)BR

MotorFR = mh.getMotor(1)
MotorBR = mh.getMotor(2)
MotorBL = mh.getMotor(3)
MotorFL = mh.getMotor(4)

# set the speed to start, from 0 (off) to 255 (max speed)
MotorFR.setSpeed(200)
MotorBR.setSpeed(200)
MotorBL.setSpeed(200)
MotorFL.setSpeed(200)

# print "Forward! "
MotorFR.run(Adafruit_MotorHAT.FORWARD)
MotorBR.run(Adafruit_MotorHAT.FORWARD)
MotorBL.run(Adafruit_MotorHAT.FORWARD)
MotorFL.run(Adafruit_MotorHAT.FORWARD)
# Forward for 3 seconds
time.sleep(3.0)


# print "Release"
MotorFR.run(Adafruit_MotorHAT.RELEASE)
MotorBR.run(Adafruit_MotorHAT.RELEASE)
MotorBL.run(Adafruit_MotorHAT.RELEASE)
MotorFL.run(Adafruit_MotorHAT.RELEASE)
time.sleep(1.0)
