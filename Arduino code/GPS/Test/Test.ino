#include <SoftwareSerial.h>

static const int RXPin = 4, TXPin = 3;
static const uint32_t GPSBaud = 9600;

// The serial connection to the GPS device
SoftwareSerial ss(RXPin, TXPin);

void setup()
{
  Serial.begin(9600);
  ss.begin(GPSBaud);
}

void loop()
{
  // Output raw GPS data to the serial monitor
  while (ss.available() > 0){
    Serial.write(ss.read());
  }
}
