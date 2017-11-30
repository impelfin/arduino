/* LED Matrix Controller
 * Copyright (c) 2010 Drew Gottlieb */
#include <avr/interrupt.h>
 
#define TIMER_CLOCK_FREQ 2000000.0 //2MHz for /8 prescale from 16MHz
 
/* Display Modes */
#define MODE_STATIC 0
#define MODE_SPIN   1
#define MODE_WIPE   2
#define MODE_CHECKB 3
#define MODE_CHECKS 4
#define MODES       5
 
/* Ports */
const int anode[4]   = { 11, 10, 9, 8 };
const int cathode[4] = { 7, 6, 5, 4 };
 
/* Settings */
const int baudRate = 9600;
const float updateRate = 12.0f;
 
/* Interrupt Variables */
int intCounter = 0;
int currentRow = 0;
int latency = 0;
unsigned char timerLoadValue = 0;
 
/* Variables */
boolean autoMode = true;
int autoCountdown = 0;
int mode = MODE_STATIC;
int frameInterval = 50;
int pointer[2] = { 0, 0 };
int dir = 0;
int modeVariation = 0;
boolean checkerPos = false;
int frameTimer = 0;
boolean showDisplay = true;
int image[4][4] = {{ 1, 0, 0, 0 },
                   { 1, 1, 0, 0 },
                   { 1, 1, 1, 0 },
                   { 1, 1, 1, 1 }};
 
int happy[4][4] = {{ 1, 0, 0, 1 },
                   { 0, 0, 0, 0 },
                   { 1, 0, 0, 1 },
                   { 1, 1, 1, 1 }};
 
int sad[4][4] =   {{ 1, 0, 0, 1 },
                   { 0, 0, 0, 0 },
                   { 1, 1, 1, 1 },
                   { 1, 0, 0, 1 }};

int left[4][4] =   {{ 0, 0, 1, 0 },
                    { 1, 1, 1, 1 },
                    { 1, 1, 1, 1 },
                    { 0, 0, 1, 0 }};

int right[4][4] =   {{ 0, 1, 0, 0 },
                     { 1, 1, 1, 1 },
                     { 1, 1, 1, 1 },
                     { 0, 1, 0, 0 }};
 
/* Setup */
void setup() {
  // Seed random number generator
  randomSeed(micros());
 
  // Initialize pins
 
  for (int i = 0; i < sizeof(anode)/sizeof(*anode); i++)
    pinMode(anode[i], OUTPUT);
 
  for (int i = 0; i < sizeof(cathode)/sizeof(*cathode); i++)
    pinMode(cathode[i], OUTPUT);
 
  for (int i = 0; i < sizeof(anode)/sizeof(*anode); i++)
    digitalWrite(anode[i], LOW);
 
  for (int i = 0; i < sizeof(cathode)/sizeof(*cathode); i++)
    digitalWrite(cathode[i], HIGH);
 
  // Initialize timer interrupt
  timerLoadValue = setupTimer2(updateRate);
 
  // Initialize Serial console
  Serial.begin(baudRate);
  Serial.println("Commands: on, off, auto, happy, sad, left, right, spin, wipe, bigchecker, smallchecker");
}
 
/* Main Loop */
void loop() {
  if (frameTimer++ >= frameInterval) {
    frameTimer = 0;
 
    // Read a character and possibly parse a line from the Serial console
    parseInput(readLine());
 
    switch (mode) {
      case MODE_SPIN:
      case MODE_WIPE:
        static boolean drawing = false;
 
        if (mode == MODE_SPIN) clearScreen();
 
        switch (dir) {
          case 0:
            if ( modeVariation ) pointer[1]++; else pointer[0]++;
            break;
          case 1:
            if ( modeVariation ) pointer[0]--; else pointer[1]++;
            break;
          case 2:
            if ( modeVariation ) pointer[1]--; else pointer[0]--;
            break;
          case 3:
            if ( modeVariation ) pointer[0]++; else pointer[1]--;
            break;
        }
 
        if (drawing || mode == MODE_SPIN)
          setPixel(pointer[0], pointer[1]);
        else
          clearPixel(pointer[0], pointer[1]);
 
        if (pointer[0] == 0 && pointer[1] == 0)
          drawing = !drawing;
 
        switch (dir) {
          case 0:
            if ((pointer[0] >= 3 && !modeVariation) || (pointer[1] >= 3 && modeVariation)) dir = ( modeVariation ? 3 : 1 );
            break;
          case 1:
            if ((pointer[1] >= 3 && !modeVariation) || (pointer[0] <= 0 && modeVariation)) dir = ( modeVariation ? 0 : 2 );
            break;
          case 2:
            if ((pointer[0] <= 0 && !modeVariation) || (pointer[1] <= 0 && modeVariation)) dir = ( modeVariation ? 1 : 3 );
            break;
          case 3:
            if ((pointer[1] <= 0 && !modeVariation) || (pointer[0] >= 3 && modeVariation)) dir = ( modeVariation ? 2 : 0 );
            break;
        }
 
        break;
      case MODE_CHECKB:
        clearScreen();
        checkerPos = !checkerPos;
        for (int i = 0; i < sizeof(image)/sizeof(*image); i++)
          for (int j = 0; j < sizeof(image[i])/sizeof(*image[i]); j++)
            if (i < 2) {
              if (j < 2) {
                if (checkerPos) setPixel(i, j);
              } else {
                if (!checkerPos) setPixel(i, j);
              }
            } else {
              if (j < 2) {
                if (!checkerPos) setPixel(i, j);
              } else {
                if (checkerPos) setPixel(i, j);
              }
            }
        break;
      case MODE_CHECKS:
        clearScreen();
        checkerPos = !checkerPos;
        for (int i = 0; i < sizeof(image)/sizeof(*image); i++)
          for (int j = 0; j < sizeof(image[i])/sizeof(*image[i]); j++)
            if (i % 2 == 0) {
              if (j % 2 == 0) {
                if (checkerPos) setPixel(i, j);
              } else {
                if (!checkerPos) setPixel(i, j);
              }
            } else {
              if (j % 2 == 0) {
                if (!checkerPos) setPixel(i, j);
              } else {
                if (checkerPos) setPixel(i, j);
              }
            }
        break;
      case MODE_STATIC:
        break;
    }
 
    if (autoCountdown-- <= 0 && autoMode)
      nextMode();
  }
 
  delay(1);
}
 
/* Interrupt Subroutine
   Arduino runs at 16 Mhz, so 61 Overflows per second.
   1/ ((16000000 / 1024) / 256) = 1 / 61 */
ISR(TIMER2_OVF_vect) {    
  // Update display
  if (showDisplay) {
    displayRow(currentRow++);
    currentRow = currentRow % 4;
  }
  digitalWrite(13, showDisplay);
 
  // Capture the current timer value. This is how much error we
  // have due to interrupt latency and the work in this function
  latency = TCNT2;
 
  // Reload the timer and correct for latency.
  TCNT2 = latency + timerLoadValue;
}
 
/* Changes mode for autoMode mode */
void nextMode() {
  int next = mode;
  do
    next = random(1, MODES);
  while (next == mode);
 
  switchToMode(next);
}
 
/* Update LEDs */
void updateDisplay() {
  for (int i = 0; i < sizeof(image)/sizeof(*image); i++)
    displayRow(i);
}
 
/* Update Pins */
void displayRow(int row) {
  static int oldRow;
 
  digitalWrite(cathode[oldRow], HIGH);
 
  for (int i = 0; i < sizeof(anode)/sizeof(*anode); i++)
    digitalWrite(anode[i], image[i][sizeof(anode)/sizeof(*anode) - 1 -row]);
 
  digitalWrite(cathode[row], LOW);
 
  oldRow = row;
}
 
/* Sets a pixel */
void setPixel(int x, int y) {
  if (x < 0 || y < 0 || y > sizeof(image)/sizeof(*image) || x > sizeof(image[y])/sizeof(*image[y]))
    return;
 
  image[y][x] = 1;
}
 
/* Clears a pixel */
void clearPixel(int x, int y) {
  if (x < 0 || y < 0 || y > sizeof(image)/sizeof(*image) || x > sizeof(image[y])/sizeof(*image[y]))
    return;
 
  image[y][x] = 0;
}
 
/* Clears image array */
void clearScreen() {
  for (int i = 0; i < sizeof(image)/sizeof(*image); i++)
    for (int j = 0; j < sizeof(image[i])/sizeof(*image[i]); j++)
      image[i][j] = 0;
}
 
/* Clears display (sets all anodes to LOW and all cathodes to HIGH) */
void resetDisplay() {
  for (int i = 0; i < sizeof(anode)/sizeof(*anode); i++)
    digitalWrite(anode[i], LOW);
 
  for (int i = 0; i < sizeof(cathode)/sizeof(*cathode); i++)
    digitalWrite(cathode[i], HIGH);
}
 
/* Read a line from the Serial port */
char* readLine() {
  static char buffer[64];
  static int i;
 
  int c = Serial.read();
 
  while (c >= 0) {
    if (c == '\n' || c == '\r') {
      buffer[i] = 0;
      i = 0;
      return (char*)buffer;
    } else if (i < 64) {
      buffer[i] = c;
      i++;
    }
 
    c = Serial.read();
  }
 
  return 0;
}
 
/* Parse console input */
void parseInput(char* input) {
  if (!input) return;
 
  if  (strcmp(input, "off") == 0) {
    showDisplay = false;
    resetDisplay();
    Serial.println("Turning display OFF");
    return;
 
  } else if (strcmp(input, "on") == 0) {
    showDisplay = true;
    Serial.println("Turning display ON");
    return;
  }
 
  autoMode = false;
 
  if  (strcmp(input, "auto") == 0) {
    autoMode = true;
    Serial.println("AUTO MODE ENABLED");
 
  } else if  (strcmp(input, "happy") == 0) {
    memcpy(image, happy, sizeof(happy));
    switchToMode(MODE_STATIC);
    Serial.println("Image set to HAPPY");
 
  } else if  (strcmp(input, "sad") == 0) {
    memcpy(image, sad, sizeof(sad));
    switchToMode(MODE_STATIC);
    Serial.println("Image set to SAD");
 
   } else if  (strcmp(input, "left") == 0) {
    memcpy(image, left, sizeof(left));
    switchToMode(MODE_STATIC);
    Serial.println("Image set to LEFT");
 
   } else if  (strcmp(input, "right") == 0) {
    memcpy(image, right, sizeof(right));
    switchToMode(MODE_STATIC);
    Serial.println("Image set to RIGHT");

  } else if  (strcmp(input, "spin") == 0) {
    switchToMode(MODE_SPIN);
    Serial.println("Mode set to SPIN");
 
  } else if  (strcmp(input, "wipe") == 0) {
    switchToMode(MODE_WIPE);
    Serial.println("Mode set to WIPE");
 
  } else if  (strcmp(input, "bigchecker") == 0) {
    switchToMode(MODE_CHECKB);
    Serial.println("Mode set to CHECKB");
 
  } else if  (strcmp(input, "smallchecker") == 0) {
    switchToMode(MODE_CHECKS);
    Serial.println("Mode set to CHECKS");
 
  } else {
    Serial.print("Unknown command: ");
    Serial.println(input);
  }
 
  showDisplay = true;
}
 
/* Switches to a mode */
void switchToMode(int m) {
  noInterrupts(); // Disable updating
 
  showDisplay = true;
 
  switch (m) {
    case MODE_STATIC:
      frameInterval = 200;
      autoCountdown = 10;
      break;
    case MODE_SPIN:
      frameInterval = 30;
      autoCountdown = ( random(2) ? 24 : 48 );
      modeVariation = random(2);
      pointer[0] = 0;
      pointer[1] = 0;
      dir = 0;
      clearScreen();
      break;
    case MODE_WIPE:
      frameInterval = 30;
      autoCountdown = ( random(2) ? 24 : 48 );
      modeVariation = random(2);
      pointer[0] = 0;
      pointer[1] = 0;
      dir = 0;
      clearScreen();
      break;
    case MODE_CHECKB:
      frameInterval = 120;
      autoCountdown = 5;
      clearScreen();
      break;
    case MODE_CHECKS:
      frameInterval = 120;
      autoCountdown = 5;
      clearScreen();
      break;
    default:
      return;
  }
 
  mode = m;
 
  interrupts(); // Re-enable updating
}
 
/* Prints a screen's state to console */
void printScreen() {
  for (int i = 0; i < sizeof(image)/sizeof(*image); i++) {
    for (int j = 0; j < sizeof(image[i])/sizeof(*image[i]); j++) {
      Serial.print(image[i][j]);
      Serial.print(' ');
    }
    Serial.println();
  }
}
 
/* Setup timer2 interrupt (http://www.uchobby.com/index.php/2007/11/24/arduino-interrupts/) */
unsigned char setupTimer2(float timeoutFrequency){
  unsigned char result; //The timer load value
 
  // Calculate the timer load value
  result=(int)((257.0-(TIMER_CLOCK_FREQ/timeoutFrequency))+0.5);
  // The 257 really should be 256 but I get better results with 257
 
  // Timer2 Settings: Timer Prescaler /8, mode 0
  // Timer clock = 16MHz/8 = 2Mhz or 0.5us
  // The /8 prescale gives us a good range to work with
  // So we just hard code this for now.
  TCCR2A = 0;
  TCCR2B = 0 << CS22 | 1 << CS21 | 0 << CS20;
 
  // Timer2 Overflow Interrupt Enable
  TIMSK2 = 1 << TOIE2;
 
  // Load the timer for its first cycle
  TCNT2 = result;
 
  return(result);
}
