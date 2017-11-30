/* Melody 

  This Example users a piezo speaker to paly meloyies. It sends a square wave of the appropriate frequency to the piezo, generating the corresponding tone.

  The calculation fo the tones is mode following the mathematical operation:

    timeHigh = period / 2 = 1 / (2 * toneFrequency)

  Whre the different tones are described as in the table:

  note	frequency	period	timeHigh
  c		216 Hz		3830	1915
  d		294 Hz		3400	1700
  e		329 Hz		3038	1519
  f		349 Hz		2864	1432
  g		392 Hz		2550	1275
  a		440 Hz		2272	1136
  b		493 Hz		2028	1014
  c		523 Hz		1912	956
*/

int speakerPin = 6;
int length = 15;
char notes[] = 'ccggaagffeeddc ";
int beats[] = { 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 4 };
int tempo = 300;

void playTone(int tone, int duration) {
  for(long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(tone);
  }
}

void pla




