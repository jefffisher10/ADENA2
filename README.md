# ADENA2
A small (soon to be) autonomous robot developed by Jeff Fisher

ADENA II

These are the parts I'm using...

Raspberry Pi 2 model B (I think?) running Raspbian Jesse
Miniature WiFi module (USB)
Pi camera
DC Motor HAT (interfaces w/ Pi via I2C using python)
Arduino Uno (sensor interface)
Adafruit 10-DOF IMU Breakout - L3GD20H + LSM303 + BMP180 (sensors)


So right now, I configured an ad-hoc wireless network on the PI. (I think I used this tutorial):
https://spin.atomicobject.com/2013/04/22/raspberry-pi-wireless-communication/

I just SSH into the Pi (apache is running). I wrote a simple bash script that takes a picture, names it the date and puts it into /var/www/html/ so you can view it with a web browser.

Here's the sample code for the DC motors. I ran it and verified it worked... haven't done anything else yet. I have four motors and was thinking simple: turn right, right 2 motors go back, left 2 go forward... that type of stuff.
https://learn.adafruit.com/adafruit-dc-and-stepper-motor-hat-for-raspberry-pi/using-dc-motors
But what's an easy way to 'invoke' those commands? Small python programs? Then use aliases?

I haven't done anything with the code for the sensors yet either. I have the code I wrote for the rocket and weather station, but I'm not sure they'd be easily ported to this - just depends on how we decide to send the commands to get and report the sensor readings. (Again... bash scripts + aliases?) 
Here's the sample code for them:
What I actually have: https://www.adafruit.com/products/1604
(That's a combination of the three below)
BMP085 (altitude, pres, temp): https://learn.adafruit.com/bmp085/using-the-bmp085-api-v2
LSM303 (accelerometer + magnetometer): https://github.com/adafruit/Adafruit_LSM303
L3GD20H (triple-axis gyro): https://github.com/adafruit/Adafruit_L3GD20


Test of my remote git repo - Andy
