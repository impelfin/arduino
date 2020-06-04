const byte number[10] = {
  B11000000, // 0
  B11111001, // 1
  B10100100, // 2
  B10110000, // 3
  B10011001, // 4
  B10010010, // 5
  B10000010, // 6
  B11111000, // 7
  B10000000, // 8
  B10010000, // 9
};

#define DEBOUNCE_MS 100
unsigned char o_sw, n_sw; 
int k=0;

void setup() {
  for(int i=2; i<=9; ++i) {
    pinMode(i, OUTPUT);
  };
  o_sw = digitalRead(10);
}

void loop() {
  if(k == 10) k=0;
  n_sw = digitalRead(10);
 
  if(o_sw == HIGH && n_sw == LOW) ++k; 
  fndDisplay(k);
  o_sw = n_sw;
  delay(DEBOUNCE_MS);
  
  /*
  for(int k=0; k<=9; ++k) {
    fndDisplay(k);
    delay(DEBOUNCE_MS);
  };
  */
}

void fndDisplay(int displayValue) {
  boolean bitValue;
  for(int i=2; i<=9; i++) {
    digitalWrite(i, LOW);
  };
  for(int i=0;i<=7;++i) {
    bitValue = bitRead(number[displayValue], i);
    digitalWrite(i+2, bitValue);
  };
}
