/*
 * This sketch is for the 32MHz version of the LGT8F328P (ATMEGA328P upgrade) 
 * 
 * It should calculate 10,000 prime numbers in 59 seconds. If it takes longer the setup for
 * the board is not correct. 
 * 
 * See https://github.com/RalphBacon/LGT8F328P-Arduino-Clone-Chip-ATMega328P
 */

// Must include this to be able change the prescaler frequency
#include <avr/power.h>

long start       = 0;
long max_primes = 10000;
long i           = 2; // Start at 2
long found       = 0; // Number of primes we've found
long lastPrime   = 0;
long lastfound = found;

//#define DISPLAY_OUTPUT 1

void setup() {
  // This runs MCU at full speed. See comment below.
  clock_prescale_set(clock_div_1);

  // Wait for serial to initialise
  Serial.begin(9600);
  while (!Serial) { }

  // In case the serial output is corrupt let's beep the start
  pinMode(PE5, OUTPUT);
  beep(2);

  // the MCU Frequency is described in ~\Arduino Sketches\hardware\LGT\avr\boards.txt
  // on this line: lardu_328x.build.f_cpu=32000000L
  Serial.print("F_CPU value: "); Serial.println(F_CPU);
  Serial.print("Clock cycles per µsecond: "); Serial.println(clockCyclesPerMicrosecond());

  uint32_t guid = *(uint32_t*)&GUID0 ;
  Serial.print("GUID of this device: "); Serial.println(guid, HEX);

  // Go!
  Serial.println("Prime calculation starting.");

#ifdef DISPLAY_OUTPUT
  Serial.print("0: ");
#endif
  start = millis();
}

void loop() {
  int prime = is_prime(i); // Check if the number we're on is prime

  if (prime == 1) {
#ifdef DISPLAY_OUTPUT
    Serial.print(i); Serial.print(" ");
#endif
    lastPrime = i;
    found++;
  }

  int running_seconds = (millis() - start) / 1000;

  if (found >= max_primes) {
    Serial.print("\nFound ");
    Serial.print(found);
    Serial.print(" primes in ");
    Serial.print(running_seconds);
    Serial.println(" seconds");
    Serial.print("Highest prime found was: ");
    Serial.println(lastPrime);
    //beep(3);
    delay(60000);

    i     = 2;
    found = 0;
    lastPrime = 0;
    Serial.println("Prime calculation starting (again)");
    start = millis();
  }
  else {
    i++;
#ifdef DISPLAY_OUTPUT
    if (found != lastfound && found % 10 == 0) {
      Serial.println(""); Serial.print(found); Serial.print(": ");
      lastfound = found;
    }
#endif
  }
}

int is_prime(long num) {
  // Only have to check for divisible for the sqrt(number)
  int upper = sqrt(num);

  // Check if the number is evenly divisible (start at 2 going up)
  for (long cnum = 2; cnum <= upper; cnum++) {
    long mod = num % cnum; // Remainder

    if (mod == 0) {
      return 0;
    } // If the remainder is 0 it's evenly divisible
  }

  return 1; // If you get this far it's prime
}

void beep(int count) {
  for (auto cnt = 0; cnt < count; cnt++) {
    digitalWrite(D5, HIGH);
    delay(200);
    digitalWrite(D5, LOW);
    delay(200);
  }
}

// Delay: count 1000 milliseconds and decrement amount of time (in ms) to wait
//void delay(double ms)
//{
//  uint32_t start = micros();
//
//  while (ms > 0) {
//    yield();
//    while ( ms > 0 && (micros() - start) >= 1000) {
//      ms--;
//      start += 1000;
//    }
//  }
//}
