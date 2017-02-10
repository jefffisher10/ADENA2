#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP085.h>

   
Adafruit_BMP085 bmp = Adafruit_BMP085(10085);

/**************************************************************************/
   /* Arduino setup function (automatically called at startup)*/
/**************************************************************************/
void setup(void) 
{
  Serial.begin(9600);
  /* Initialise the sensor */
  if(!bmp.begin())
  {
    /* There was a problem detecting the BMP085 ... check your connections */
    Serial.print("Ooops, no BMP085 detected ... Check your wiring or I2C ADDR!");
    while(1);
  }
}

/**************************************************************************/
    /* Arduino loop function, called once 'setup' is complete */ 
/**************************************************************************/
void loop(void) 
{
  /* Get a new sensor event */ 
  sensors_event_t event;
  bmp.getEvent(&event);
  char ch = 0;
  ch = Serial.read();
 
  while(ch == 'r')	/* Will return a reading when "r" is received */
  {
    Serial.print("time");
    Serial.print(",");
    Serial.print(event.pressure);
    float temperature;
    bmp.getTemperature(&temperature);
    Serial.print(",");
    Serial.println(temperature);
    ch = 0;
  }
}