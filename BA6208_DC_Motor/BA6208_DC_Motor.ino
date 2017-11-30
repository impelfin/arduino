int input_1 = 10;
int input_2 = 11; 
// 아두이노 디지털 2, 3번 핀을 선택

void setup() {
  Serial.begin(9600);
  
  pinMode(input_1, OUTPUT);
  pinMode(input_2, OUTPUT);
// 핀 모드를 출력으로 설정.
}
void loop() {
  
  
  digitalWrite(input_1, HIGH);
  digitalWrite(input_2, LOW);
  delay(500);
  // 아두이노 2번 핀과, 모터 드라이브 3 번 핀 A 입력을 연결
  // 아두이노 3번 핀과, 모터 드라이브 2 번 핀 B 입력을 연결 
  // 출력을 통해 모터 드라이브 3 번 핀 A 입력 핀에 신호를 주고
  // 출력을 통해 모터 드라이브 2 번 핀 B 입력 핀에는 신호를 주지 않는다.
  // 모터 드라이브 8번 핀으로 A 출력으로 신호가 나가고 모터는 정회전 동작을 한다.

  digitalWrite(input_1, LOW);
  digitalWrite(input_2, HIGH);
  delay(500);
  // 위와는 반대의 동작

  digitalWrite(input_1, LOW);
  digitalWrite(input_2, LOW);
  delay(500);
  // 모터 정지
}

