/*
   This simple utility will scan the I2C bus and report back on any devices it finds.

   How to use:

   Connect up your I2C device via the SDA (Serial Data) and SCk (Serial Clock) pins on
   both your device and the Arduino (normally clearly labelled near digital pin 13). Don't
   forget the power lines VCC and GND too or nothing will work!

   Upload this code to your Arduino and open the serial monitor window.

   This will report the hexadecimal hexAddress of any devices it finds. If you have a module
   which contains TWO (or more!) devices on the same board it will report both but then
   you will have to narrow down which hexAddress belongs to which device by trial and response.

   This has saved me countless times wondering why my device was not responding! The code 
   can be found in several different permuatations on the Internet - probably where I got
   my first version or idea from. 

   www.youtube.co.uk/c/RalphBacon my YouTube channel contains many Arduino and electronics
   videos for beginners.
*/
#include <Wire.h>

// -------------------------------------------------------------
// SET~UP    SET~UP    SET~UP    SET~UP    SET~UP    SET~UP
// -------------------------------------------------------------
void setup()
{
  Wire.begin();
  Serial.begin(9600);
  Serial.println("--------------------------");
  Serial.println("I2C Hex hexAddress Scanner");
  Serial.println("--------------------------");
}

// -------------------------------------------------------------
// LOOP   LOOP   LOOP   LOOP   LOOP   LOOP   LOOP   LOOP   LOOP
// -------------------------------------------------------------
void loop()
{
  byte response, hexAddress;
  int deviceCnt = 0;
    
  Serial.println("Scanning...");
  for (hexAddress = 1; hexAddress < 127; hexAddress++ )
  {
    // Start transmitting on every known hex hexAddress
    Wire.beginTransmission(hexAddress);

    // See if something acknowledged the transmission
    response = Wire.endTransmission();
    if (response == 0)
    {
      Serial.print("I2C device found at hexAddress 0x");
      if (hexAddress < 16)
        Serial.print("0");
      Serial.println(hexAddress, HEX);
            deviceCnt++;
    }
    else if (response == 4) // unknown error
    {
      Serial.print("Unknown response at hexAddress 0x");
      if (hexAddress < 16)
        Serial.print("0");
      Serial.println(hexAddress, HEX);
    }
  }

  // Nothing found at any of the hexAddresses, boo
  if (deviceCnt == 0)
    Serial.println("No I2C devices found\n");
  else
    Serial.println("Scan completed.\n");

  // Delay 5 seconds and repeat scan
  delay(5000);
}
