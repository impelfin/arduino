int ON = LOW; // common anode 방식으로 LOW를 출력할 때 켜짐
int OFF = HIGH;
// 0에서 9까지 숫자 표시를 위한 세그먼트 a, b, c, d, e, f, g, dp의 점멸 패턴
int digits[10][8] = {
{ON, ON, ON, ON, ON, ON, OFF, OFF},
{OFF, ON, ON, OFF, OFF, OFF, OFF, OFF},
{ON, ON, OFF, ON, ON, OFF, ON, OFF},
{ON, ON, ON, ON, OFF, OFF, ON, OFF},
{OFF, ON, ON, OFF, OFF, ON, ON, OFF},
{ON, OFF, ON, ON, OFF, ON, ON, OFF},
{ON, OFF, ON, ON, ON, ON, ON, OFF},
{ON, ON, ON, OFF, OFF, ON, OFF, OFF},
{ON, ON, ON, ON, ON, ON, ON, OFF},
{ON, ON, ON, OFF, OFF, ON, ON, OFF}};
int pins[] = {2, 3, 4, 5, 6, 7, 8, 9}; // 아두이노 연결 핀 번호

void setup() {
  for(int i = 0; i < 8; i++) {
    pinMode(pins[i], OUTPUT); // 연결 핀을 출력으로 설정
  }
}

void loop() {
  for(int i = 0; i <= 9; i++) { // 0에서 9까지 반복
    for(int j = 0; j < 8; j++) { // 8개 세그먼트를 점멸
      digitalWrite(pins[j], digits[i][j]);
    }
    delay(1000);
  }
}
