# LGT8F328P Arduino Clone Chip ATMega328P
An improved ATMega328P with this cheap clone Logic Green LGT8F328P

$8 off your first order at LCSC Electronics with https://lcsc.com/?href=ralphsbacon&source=referral  

See https://www.youtube.com/ralphbacon video #156
(Direct link to video: )

So we're looking at the 32MHz Nano-sized drop-in replacement but I'm using a different sized development board just for ease of use in the video. My device looks like this (and well worth it for experimenting with)  
<img src="images/LGT8F328P%20Development%20Board.JPG" width="25%">

But the final device is Nano sized, and a drop-in pin replacement  
<img src="images/Nano-sized%20LGTf8328P.JPG" width="25%">

Or you can have a Pro-Micro sized device that will require a USB-to-Serial adapter to program.  
<img src="images/proMicro sized%20LGT8F328P.JPG" width="25%">

The 5 simple steps to get a LGT8F328P-based board running at 32MHz are listed on my GitHub.
https://github.com/RalphBacon/LGT8F328P-Arduino-Clone-Chip-ATMega328P

## 5 Simple Steps to get a LGT8F328P-based board it running at 32MHz

Download the LogicGreen zipped resources here:  
https://github.com/LGTMCU/Larduino_HSP  

Extract the download (unzip it) amd move the hardware/LGT/avr folder to the *hardware* folder in your Arduino sketch folder. This means you should have the original Arduino folder PLUS this new LGT folder too. If you do not have a _hardware_ folder in your Arduino Sketches folder, just create one.

Your structure should look like this:  
<img src="images/FolderStructure.JPG">

In the Hardware -> LGT -> AVR folder delete the boards.txt.

Copy the boards.txt in this GitHub there in place of the one you just deleted.

Fire up the Arduino IDE (or restart it if already running).

Go to Tools, Board and scroll down until you see the next set of LGT8F boards, one of which will be 32MHz variant you just added. The original LGT8F328P board will now be described as (16MHz)


In your sketch, always add in the #include for the <avr/power.h> as shown in the video.

Finally, and most importantly, add in the the clock_prescale_set(clock_div_1) statement before anything else, in the setup().





You can prove the speed is correctly set by setting the Serial baud rate to 9600, Serial.begin(9600) and then send something via the USB to your PC, Serial.println("This should be visible."). If you get ???? on the Serial Monitor (and you have set it to 9600) then something is not right. Go back and check each step.

And to prove you are running at 32MHz, run a simple sketch (eg the Prime Number sketch, in this GitHub repository) using the new 32MHz board description and then using the default one (above it in the list) which runs at 16MHz. You must not have the clock_prescale_set present in the default board sketch (your Serial Monitor speed will be wrong, for starters).











LINKS     LINKS     LINKS     LINKS

KEYES Open Source LGT8F328P Control Module Development Board
https://www.banggood.com/KEYES-Open-Source-LGT8F328P-Control-Module-Development-Board-For-Arduino-p-1400916.html?p=FQ040729393382015118&utm_campaign=25129675&utm_content=3897  

AliExpress Nano/pro Micro replacements  
LGT8F328P LQFP32 replaces NANO V3.0 HT42B534 chip  
http://s.click.aliexpress.com/e/cEAUGf6s  
This seller has both variants (SOP16 & LQFP32)  

Logic Green's GitHub for the support files (also on my GitHub)  
https://github.com/LGTMCU/Larduino_HSP


LGT8F328P Schematic (also copy on my GitHub)  
https://www.electrodragon.com/w/images/a/ac/SN0124_LARDUINO_UNO_V2_20140613.jpg  

Chinese Documentation for what it's worth  
http://www.logicgreen.io/upload/lgt8fx8p/LGT8FX8P_databook_v1.0.4.pdf
English version of similar family of chips on my website

Top 10,000 Prime Numbers  
https://www.di-mgt.com.au/primes10000.txt

Just testing image placement.

![Boards.txt image shot][BoardsTextEntry]

[BoardsTextEntry]: https://github.com/RalphBacon/LGT8F328P-Arduino-Clone-Chip-ATMega328P/blob/master/Documentation%20Images/Boards.txt%20entry.JPG



That was it.
