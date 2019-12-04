#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include <ArduinoJson.h>


SoftwareSerial GPS_SoftSerial(4, 3);/* (Rx, Tx) */
TinyGPSPlus gps;      
StaticJsonDocument<200> doc;

volatile float minutes, seconds;
volatile int degree, secs, mins;

void setup() {
  Serial.begin(9600); 
  GPS_SoftSerial.begin(9600); 
}

void loop() {
        smartDelay(1000); /* Generate precise delay of 1ms */
        unsigned long start;
        double lat_val, lng_val, alt_m_val;
        uint8_t hr_val, min_val, sec_val;
        bool loc_valid, alt_valid, time_valid;
        lat_val = gps.location.lat(); /* Get latitude data */
        loc_valid = gps.location.isValid(); /* Check if valid location data is available */
        lng_val = gps.location.lng(); /* Get longtitude data */
        alt_m_val = gps.altitude.meters();  /* Get altitude data in meters */
        alt_valid = gps.altitude.isValid(); /* Check if valid altitude data is available */
        hr_val = gps.time.hour(); /* Get hour */
        min_val = gps.time.minute();  /* Get minutes */
        sec_val = gps.time.second();  /* Get seconds */
        time_valid = gps.time.isValid();  /* Check if valid time data is available */
        if (!loc_valid)
        {          
          Serial.print("Getting location, please chill!!");
   
        }
        else
        {
          
          Serial.print("Latitude in Decimal Degrees : ");
          Serial.println(lat_val, 6);
          Serial.print("Longitude in Decimal Degrees : ");
          Serial.println(lng_val, 6);
          Serial.print("Altitude : ");
          Serial.println(alt_m_val, 6);  
          Serial.println("Speed in Kmh");
          Serial.println(gps.speed.kmph());
         
        }
        if (!time_valid)
        {
          Serial.print("Time : ");
          Serial.println("***");
        }
        else
        {
          char time_string[32];
          sprintf(time_string, "Time : %02d/%02d/%02d \n", hr_val, min_val, sec_val);
          Serial.print(time_string);    
        }

}

static void smartDelay(unsigned long ms)
{
  unsigned long start = millis();
  do 
  {
    while (GPS_SoftSerial.available())  
      gps.encode(GPS_SoftSerial.read());
  } while (millis() - start < ms);
}
