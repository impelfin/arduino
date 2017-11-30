int ON = LOW; // common anode 방식으로 LOW를 출력할 때 켜짐
int OFF = HIGH;
// 0에서 9까지 숫자 표시를 위한 세그먼트 a, b, c, d, e, f, g, dp의 점멸 패턴
byte digits_data[10]
= {0xFC, 0x60, 0xDA, 0xF2, 0x66, 0xB6, 0xBE, 0xE4, 0xFE, 0xE6};
int pins[] = {2, 3, 4, 5, 6, 7, 8, 9}; // 아두이노 연결 핀

void setup() {
  for(int i = 0; i < 8; i++) {
    pinMode(pins[i], OUTPUT);
  }
}

void loop() {
  for(int i = 0; i <= 9; i++) {
    for(int j = 0; j < 8; j++)  {
      byte segment_data = (digits_data[i] & (0x01 << j)) >> j;
      if(segment_data == 1)
          digitalWrite(pins[7 - j], ON);
      else
        digitalWrite(pins[7 - j], OFF);
     }
     delay(1000);
  }
}
