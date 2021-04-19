//Res-TrackR
//Algo: Trigger-Fetch-Respond

#include <SoftwareSerial.h>
#include <TinyGPS.h>

int state = 0;
const int pin = 7;
float gpslat, gpslon;

TinyGPS gps;
SoftwareSerial sgps(2, 3);
SoftwareSerial sgsm(9, 10);

void setup()
{
  sgsm.begin(9600);
  sgps.begin(9600);
}

void loop()
{
  sgps.listen();
  while (sgps.available())
  {
    int c = sgps.read();
    if (gps.encode(c))
    {
      gps.f_get_position(&gpslat, &gpslon);
    }
  }
    if (digitalRead(pin) == HIGH && state == 0) {
      sgsm.listen();
      sgsm.print("\r");
      delay(1000);
      sgsm.print("AT+CMGF=1\r");
      delay(1000);
      /*Replace XXXXXXXXXX to 10 digit mobile number &
        ZZ to 2 digit country code*/
      sgsm.print("AT+CMGS=\"+91XXXXXXXXXX\"\r");
      delay(1000);
      //The text of the message to be sent.
      sgsm.print("https://www.google.com/maps/?q=");
      sgsm.print(gpslat, 6);
      sgsm.print(",");
      sgsm.print(gpslon, 6);
      delay(1000);
      sgsm.write(0x1A);
      delay(1000);
      state = 1;
    }
  if (digitalRead(pin) == LOW) {
      state = 0;
    }
  }
