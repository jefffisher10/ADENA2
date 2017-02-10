#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_LSM303_U.h>
#include <Adafruit_BMP085_U.h>

/* Assign a unique ID to this sensor at the same time */
Adafruit_LSM303_Mag_Unified mag = Adafruit_LSM303_Mag_Unified(12345);
Adafruit_BMP085_Unified bmp = Adafruit_BMP085_Unified(10085);

/* SETUP */
void setup(void) 
{
	Serial.begin(9600);
	/* Initialise the sensor */
	if(!bmp.begin()) {}
	if(!mag.begin()) {}
}

/* MAIN LOOP */
void loop(void) 
{
	/* VARIABLES */
	float pres = 0;
	float temperature = 0;
	float temp = 0;
	float alt = 0;
	float seaLevelPressure = SENSORS_PRESSURE_SEALEVELHPA;
	float basealt = 0;
	float curalt = 0;
	float Pi = 3.14159;
	char ch = 0;

	sensors_event_t event;
	bmp.getEvent(&event);

	pres = event.pressure;
	bmp.getTemperature(&temperature);
	temp = temperature;
	alt = bmp.pressureToAltitude(seaLevelPressure,event.pressure,temperature);
	basealt = alt;

	while(true)
	{
		ch = Serial.read();

		if (ch == 'n')	/* Will return a reading when "n" is received */
	    {
			sensors_event_t event;
			mag.getEvent(&event);

			/* Calculate the angle of the vector y,x */
			float heading = (atan2(event.magnetic.y,event.magnetic.x) * 180) / Pi;
			/* Normalize to 0-360 */
			if (heading < 0)
			{
				heading = 360 + heading;
			}

			/* Send reading */
			Serial.println(heading);
			ch = 0;
	    }
		if (ch == 'r')	/* Will return a reading when "r" is received */
	    {
			sensors_event_t event;
			bmp.getEvent(&event);

			pres = event.pressure;
			bmp.getTemperature(&temperature);
			temp = temperature;
			alt = bmp.pressureToAltitude(seaLevelPressure,event.pressure,temperature);
			curalt = alt - basealt;

			/* Send readings */
			Serial.print(pres);
			Serial.print(", ");
			Serial.print(temp);
			Serial.print(", ");
			Serial.println(alt);
			ch = 0;
	    }
	}
}
