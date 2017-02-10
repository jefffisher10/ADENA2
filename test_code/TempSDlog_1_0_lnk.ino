#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP085.h>
#include <SD.h>

Adafruit_BMP085 bmp = Adafruit_BMP085(10085);

// set up variables using the SD utility library functions:
Sd2Card card;
SdVolume volume;
SdFile root;

const int chipSelect = 10;  

/**************************************************************************/
/*
    Arduino setup function (automatically called at startup)
*/
/**************************************************************************/
void setup(void) 
{
  pinMode(10, OUTPUT);
  
  /* Initialise the sensor & card */
  if(!bmp.begin()) {}
  if(!SD.begin(chipSelect)) {}
}

/**************************************************************************/
/*
    Arduino loop function, called once 'setup' is complete (your own code
    should go here)
*/
/**************************************************************************/
void loop(void) 
{
  delay(1000);
  
  /* VARIABLES */
  float pres = 0;
  float temperature = 0;
  float temp = 0;
  float alt = 0;
  float seaLevelPressure = SENSORS_PRESSURE_SEALEVELHPA;
  float basealt = 0;
  float curalt = 0;
  
  sensors_event_t event;
  bmp.getEvent(&event);
  
  pres = event.pressure;
  bmp.getTemperature(&temperature);
  temp = temperature;
  alt = bmp.pressureToAltitude(seaLevelPressure,event.pressure,temperature);
  
  basealt = alt;
  
  while(true){
    sensors_event_t event;
    bmp.getEvent(&event);
    
    pres = event.pressure;
    bmp.getTemperature(&temperature);
    temp = temperature;
    alt = bmp.pressureToAltitude(seaLevelPressure,event.pressure,temperature);
    curalt = alt - basealt;

    // open the file. note that only one file can be open at a time,
    // so you have to close this one before opening another.
    File dataFile = SD.open("datalog.txt", FILE_WRITE);
    dataFile.print(pres);
    dataFile.print(",");
    dataFile.print(temp);
    dataFile.print(",");
    dataFile.println(curalt);
    dataFile.close(); 
  
    delay(1000);
    }
}
