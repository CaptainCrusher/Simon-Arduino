/*
 ______   ________               ______    _    _
/  ____  |__    __| | \    / |  /  __  \  | \  | |
\ \___       ||     |  \  /  | |  /  \  | |  \ | |
 \___ \      ||     |   \/   | | |    | | | |  | |
___ / /   __ || __  | |\__/| | |  \__/  | | | \  |
_____/   |________| |_|    |_|  \______/  |_|  \_|

By @TheCaptain

*/
//This can probably run on any arduino, but I only tried it on the UNO

/**
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
*/

//all power is routed through a SPDT switch and a 100 ohm resistor and than through a five volt power regulator (it doesn't matter what kind)

//leds are hooked up to arduino outputs 2, 3, 4 and 5 on long leg and short leg to ground

//buttons are hooked up to arduino inputs A0, A1, A2 and A3 and power through a 10K ohm resistor

//output 12 goes to pin 1 on a 4026B seven-segment drive chip, which is than carried to another 4026B and than to two seven-segment displays

//4026B's are powered through a 100 ohm resistor





//setup outputs
int outputs[] = {2,3,4,5};
int inputs[] = {0,1,2,3};
int inputPorts[] = {A0,A1,A2,A3};
int sevenSegmentPulseOutput = 12;

//make an array 100 long for storing the press sequence
int correct[100] = {};

//an integer for indexing the press sequence
int colorOn = 0;

//keep track of score
int score = 0;

// whether you are actively pressing buttons or watching the replay
boolean replay = true;

void ledOn(int num) {
  for (int i = 0; i < 4; i += 1) {
    if (outputs[i] == num) {
      //turn led on if it matches the input
      digitalWrite(outputs[i], HIGH);
    }
    else {
      //turn led off if it doesn't match the input
      digitalWrite(outputs[i], LOW);
    }
  }
}
void allOn() {
  for (int i = 0; i < 4; i += 1) {
    //turn all the leds on
    digitalWrite(outputs[i], HIGH);
  }
}
void allOff() {
  for (int i = 0; i < 4; i += 1) {
    //turn all the leds off
    digitalWrite(outputs[i], LOW);
  }
}



void setup() {
  for (int i = 0; i < 4; i += 1) {
    //initialize outputs
    pinMode(outputs[i], OUTPUT);
  }
  
  //setup random based off of unconnected inputs
  randomSeed(analogRead(A6)*analogRead(A7));

  //choose first press
  correct[0] = floor(random(0,4));

  //game loop
  while (true) {
    for (int i = 0; i < 4; i+=1) {
      //if button pressed or playing back sequence
      if (analogRead(inputPorts[i]) > 1000 || replay) {
        
        if (inputs[i] == correct[colorOn]) {
          //if correct press, blink light and go to the next press
          colorOn += 1;
          ledOn(outputs[i]);
          delay(500);
          allOff();
          delay(200);
          if (colorOn > score) {
            if (!replay) {
              //if not just playing back the sequence, then increase score and add to sequence
              score += 1;
              correct[score] = floor(random(0,4));

              //increase display counter
              digitalWrite(sevenSegmentPulseOutput, HIGH);
              delay(20);
              digitalWrite(sevenSegmentPulseOutput, LOW);
            }
            
            //if done with sequence restart the sequence
            colorOn = 0;

            //add a delay before the replay
            replay = !replay;
            if (replay) {
              delay(480);
            }
          }
          break;
        }
        else if (!replay) {
          //if incorrect button is pressed, blink the correct led until program is restarted
          allOff();
          while (!replay) {
            ledOn(outputs[correct[colorOn]]);
            delay(100);
            allOff();
            delay(100);
          }
        }
      }
    }
    //wait a millisecond before going through loop again
    delay(1);
  }
}




void loop() {
  // I didn't use this loop because breaking out of a while loop is easier
  
}
