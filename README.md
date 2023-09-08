# Simon-Arduino
A simple simon game setup to run on an Arduino Uno


By @TheCaptain

This can probably run on any arduino, but I only tried it on the UNO

Arduino IDE is suggested for compiling and uploading code to the arduino board

to download Arduino IDE go to https://www.arduino.cc/en/software


NECESSITIES
     
     -1 Arduino Uno
  
     -1 SPDT OR SPST switch
  
     -4 SPST push-button switches
  
     -4 LED's preferably of different colors
  
     -2 100 ohm resistors
  
     -1 10K ohm resistor
  
     -1 five volt power regulator
  
     -2 4026B seven-segment drives (optional)
  
     -2 seven-segment displays (optional)
  
     -? hookup wire
  
     -1 USB cable


while seven-segment displays for score keeping aren't necessary, I really suggest it

all power is routed through a SPDT switch and a 100 ohm resistor and than through a five volt power regulator (it doesn't matter what kind)

leds are hooked up to arduino outputs 2, 3, 4 and 5 on long leg and short leg to ground

buttons are hooked up to arduino inputs A0, A1, A2 and A3 and power through a 10K ohm resistor

output 12 goes to pin 1 on a 4026B seven-segment drive chip, which is than carried to another 4026B and than to two seven-segment displays

4026B's are powered through a 100 ohm resistor
