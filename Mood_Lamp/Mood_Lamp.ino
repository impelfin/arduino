// Project 8 - Mood Lamp

float RGB1[3];
float RGB2[3];
float INC[3];
int red, green, blue;
int RedPin = 11;
int GreenPin = 10;
int BluePin = 9;

void setup()
{
  Serial.begin(9600);
  randomSeed(analogRead(0));
  RGB1[0] = 0;
  RGB1[1] = 0;
  RGB1[2] = 0;
  RGB2[0] = random(256);
  RGB2[1] = random(256);
  RGB2[2] = random(256);
}
void loop
