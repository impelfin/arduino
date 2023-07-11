#include <PS2X_lib.h>
// 모터 핀
#define PWMA 12    // A 모터 속도
#define DIRA1 34
#define DIRA2 35  // A 모터 방향
#define PWMB 8    // B 모터 속도
#define DIRB1 37
#define DIRB2 36  // B 모터 방향
#define PWMC 6   // C 모터 속도 9를 6으로 변경
#define DIRC1 43
#define DIRC2 42  // C 모터 방향
#define PWMD 5    // D 모터 속도
#define DIRD1 A4  // 26
#define DIRD2 A5 // 27  // D 모터 방향

// PS2
#define PS2_DAT        52  // 14
#define PS2_CMD        51  // 15
#define PS2_SEL        53  // 16
#define PS2_CLK        50  // 17

char speed;
// #define pressures   true
#define pressures   false
// #define rumble      true
#define rumble      false
PS2X ps2x; // PS2 컨트롤러 클래스 생성

int error = 0;
byte type = 0;
byte vibrate = 0;

void (* resetFunc) (void) = 0;

#define MOTORA_FORWARD(pwm)    do{digitalWrite(DIRA1,LOW); digitalWrite(DIRA2,HIGH);analogWrite(PWMA,pwm);}while(0)
#define MOTORA_STOP(x)         do{digitalWrite(DIRA1,LOW); digitalWrite(DIRA2,LOW); analogWrite(PWMA,0);}while(0)
#define MOTORA_BACKOFF(pwm)    do{digitalWrite(DIRA1,HIGH);digitalWrite(DIRA2,LOW); analogWrite(PWMA,pwm);}while(0)

#define MOTORB_FORWARD(pwm)    do{digitalWrite(DIRB1,HIGH); digitalWrite(DIRB2,LOW);analogWrite(PWMB,pwm);}while(0)
#define MOTORB_STOP(x)         do{digitalWrite(DIRB1,LOW); digitalWrite(DIRB2,LOW); analogWrite(PWMB,0);}while(0)
#define MOTORB_BACKOFF(pwm)    do{digitalWrite(DIRB1,LOW);digitalWrite(DIRB2,HIGH); analogWrite(PWMB,pwm);}while(0)

#define MOTORC_FORWARD(pwm)    do{digitalWrite(DIRC1,LOW); digitalWrite(DIRC2,HIGH);analogWrite(PWMC,pwm);}while(0)
#define MOTORC_STOP(x)         do{digitalWrite(DIRC1,LOW); digitalWrite(DIRC2,LOW); analogWrite(PWMC,0);}while(0)
#define MOTORC_BACKOFF(pwm)    do{digitalWrite(DIRC1,HIGH);digitalWrite(DIRC2,LOW); analogWrite(PWMC,pwm);}while(0)

#define MOTORD_FORWARD(pwm)    do{digitalWrite(DIRD1,HIGH); digitalWrite(DIRD2,LOW);analogWrite(PWMD,pwm);}while(0)
#define MOTORD_STOP(x)         do{digitalWrite(DIRD1,LOW); digitalWrite(DIRD2,LOW); analogWrite(PWMD,0);}while(0)
#define MOTORD_BACKOFF(pwm)    do{digitalWrite(DIRD1,LOW);digitalWrite(DIRD2,HIGH); analogWrite(PWMD,pwm);}while(0)

#define SERIAL  Serial

#define LOG_DEBUG

#ifdef LOG_DEBUG
#define M_LOG SERIAL.print
#else
#define M_LOG 
#endif

#define MAX_PWM   200
#define MIN_PWM   130
int Motor_PWM = 130;

// 모터 제어 매크로
//    ↑A-----B↑   
//     |  ↑  |
//     |  |  |
//    ↑C-----D↑
void ADVANCE()
{
  MOTORA_FORWARD(Motor_PWM); MOTORB_FORWARD(Motor_PWM);
  MOTORC_FORWARD(Motor_PWM); MOTORD_FORWARD(Motor_PWM);
}

//    ↓A-----B↓   
//     |  |  |
//     |  ↓  |
//    ↓C-----D↓
void BACK()
{
  MOTORA_BACKOFF(Motor_PWM); MOTORB_BACKOFF(Motor_PWM);
  MOTORC_BACKOFF(Motor_PWM); MOTORD_BACKOFF(Motor_PWM);
}
//    =A-----B↑   
//     |   ↖ |
//     | ↖   |
//    ↑C-----D=
void LEFT_1()
{
  MOTORA_STOP(Motor_PWM); MOTORB_FORWARD(Motor_PWM);
  MOTORC_FORWARD(Motor_PWM); MOTORD_STOP(Motor_PWM);
}

//    ↓A-----B↑   
//     |  ←  |
//     |  ←  |
//    ↑C-----D↓
void LEFT_2()
{
  MOTORA_BACKOFF(Motor_PWM); MOTORB_FORWARD(Motor_PWM);
  MOTORC_FORWARD(Motor_PWM); MOTORD_BACKOFF(Motor_PWM);
}
//    ↓A-----B=   
//     | ↙   |
//     |   ↙ |
//    =C-----D↓
void LEFT_3()
{
  MOTORA_BACKOFF(Motor_PWM); MOTORB_STOP(Motor_PWM);
  MOTORC_STOP(Motor_PWM); MOTORD_BACKOFF(Motor_PWM);
}
//    ↑A-----B=   
//     | ↗   |
//     |   ↗ |
//    =C-----D↑
void RIGHT_1()
{
  MOTORA_FORWARD(Motor_PWM); MOTORB_STOP(Motor_PWM);
  MOTORC_STOP(Motor_PWM); MOTORD_FORWARD(Motor_PWM);
}
//    ↑A-----B↓   
//     |  →  |
//     |  →  |
//    ↓C-----D↑
void RIGHT_2()
{
  MOTORA_FORWARD(Motor_PWM); MOTORB_BACKOFF(Motor_PWM);
  MOTORC_BACKOFF(Motor_PWM); MOTORD_FORWARD(Motor_PWM);
}
//    =A-----B↓   
//     |   ↘ |
//     | ↘   |
//    ↓C-----D=
void RIGHT_3()
{
  MOTORA_STOP(Motor_PWM); MOTORB_BACKOFF(Motor_PWM);
  MOTORC_BACKOFF(Motor_PWM); MOTORD_STOP(Motor_PWM);
}
// ↓A-----B↑
//  |     |
//  |     |
// ↓C-----D↑
void TURN_LEFT()
{
  MOTORA_BACKOFF(Motor_PWM); MOTORB_FORWARD(Motor_PWM);
  MOTORC_BACKOFF(Motor_PWM); MOTORD_FORWARD(Motor_PWM);
}
// ↑A-----B↓
//  |     |
//  |     |
// ↑C-----D↓
void TURN_RIGHT()
{
  MOTORA_FORWARD(Motor_PWM); MOTORB_BACKOFF(Motor_PWM);
  MOTORC_FORWARD(Motor_PWM); MOTORD_BACKOFF(Motor_PWM);
}
//    =A-----B=  
//     |  =  |
//     |  =  |
//    =C-----D=
void STOP()
{
  MOTORA_STOP(Motor_PWM);MOTORB_STOP(Motor_PWM);
  MOTORC_STOP(Motor_PWM);MOTORD_STOP(Motor_PWM);
}
void UART_Control()
{
  char Uart_Date = 0;
  if (SERIAL.available())
  {
    Uart_Date = SERIAL.read();
  }
  switch (Uart_Date)
  {
    case 'A':  ADVANCE(); M_LOG("전진!\r\n");        break;
    case 'B':  RIGHT_1();  M_LOG("우상향!\r\n");     break;
    case 'C':  RIGHT_2();  M_LOG("우회전!\r\n");        break;
    case 'D':  RIGHT_3();  M_LOG("우하향!\r\n");   break;
    case 'E':  BACK();     M_LOG("후진!\r\n");        break;
    case 'F':  LEFT_3();   M_LOG("좌하향!\r\n");    break;
    case 'G':  LEFT_2();   M_LOG("좌회전!\r\n");       break;
    case 'H':  LEFT_1();   M_LOG("좌상향!\r\n");  break;
    case 'Z':  STOP();     M_LOG("정지!\r\n");       break;
    case 'L':  Motor_PWM = 240;                      break;
    case 'M':  Motor_PWM = 130;                       break;
  }
}

void IO_init()
{
  pinMode(PWMA, OUTPUT);
  pinMode(DIRA1, OUTPUT);
  pinMode(DIRA2, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(DIRB1, OUTPUT);
  pinMode(DIRB2, OUTPUT);
  pinMode(PWMC, OUTPUT);
  pinMode(DIRC1, OUTPUT);
  pinMode(DIRC2, OUTPUT);
  pinMode(PWMD, OUTPUT);
  pinMode(DIRD1, OUTPUT);
  pinMode(DIRD2, OUTPUT);
  STOP();
}

void setup()
{
  Serial.begin(9600);
  delay(300); // 무선 PS2 모듈이 시작될 시간을 주기 위한 지연 추가
  // v1.6 변경 사항 **************주의*************

  // 핀 및 설정 설정: 게임패드(클락, 커맨드, 어텐션, 데이터, 압력?, 진동?) 오류 확인
  error = ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT, pressures, rumble);

  if (error == 0) {
    Serial.print("컨트롤러 찾음, 구성 성공 ");
    Serial.print("압력 = ");
    if (pressures)
      Serial.println("true ");
    else
      Serial.println("false");
    Serial.print("진동 = ");
    if (rumble)
      Serial.println("true)");
    else
      Serial.println("false");
    Serial.println("모든 버튼을 시험해보세요. X 버튼은 압력에 따라 진동이 발생하며 압력이 강할수록 진동이 더 빨라집니다.");
    Serial.println("L1 또는 R1 버튼을 누르면 아날로그 스틱의 값을 출력합니다.");
    Serial.println("참고: 업데이트 및 버그 보고는 www.billporter.info에서 확인할 수 있습니다.");
  }
  else if (error == 1)
  {
    Serial.println("컨트롤러를 찾을 수 없습니다. 배선을 확인하고, 디버그를 사용하려면 readme.txt를 참조하세요. 문제 해결 팁은 www.billporter.info를 방문하세요.");
    resetFunc();

  }

  else if (error == 2)
    Serial.println("컨트롤러를 찾았지만 명령을 수락하지 않습니다. 디버그를 사용하려면 readme.txt를 참조하세요. 문제 해결 팁은 www.billporter.info를 방문하세요.");

  else if (error == 3)
    Serial.println("컨트롤러가 압력 모드 진입을 거부했습니다. 지원하지 않을 수 있습니다.");


//  Serial.print(ps2x.Analog(1), HEX);

  type = ps2x.readType();
  switch (type) {
    case 0:
      Serial.print("알 수 없는 컨트롤러 타입이 감지되었습니다. ");
      break;
    case 1:
      Serial.print("DualShock 컨트롤러가 감지되었습니다. ");
      break;
    case 2:
      Serial.print("GuitarHero 컨트롤러가 감지되었습니다. ");
      break;
    case 3:
      Serial.print("무선 소니 DualShock 컨트롤러가 감지되었습니다. ");
      break;
  }
  IO_init();

//  SERIAL.print("시작");
}


void loop() {
  /* 새로운 값을 받고 진동 값을 설정하기 위해 게임패드를 읽어야 합니다.
     ps2x.read_gamepad(작은 모터 온/오프, 큰 모터 강도 0-255)
     진동을 사용하지 않을 경우, ps2x.read_gamepad()을 값 없이 호출하세요.
     최소한 1초에 한 번은 호출해야 합니다.
  */

  UART_Control(); // 시리얼 통신으로 입력 처리
  if (error == 1) // 컨트롤러를 찾을 수 없으면 루프를 건너뜁니다.
    return;

  if (type == 2) { // Guitar Hero 컨트롤러
    return;
  }
  else  { // DualShock 컨트롤러
    ps2x.read_gamepad(false, vibrate); // 컨트롤러를 읽고 큰 모터를 '진동' 속도로 회전하도록 설정합니다.


    // 시작 버튼을 누를 경우, 모터 초기 PWM이 120입니다.
    if (ps2x.Button(PSB_START))  {
      Serial.println("시작 버튼이 눌렸습니다.");
      Motor_PWM = 90;
      ADVANCE();
    }

    // 모터 정방향 회전
    if (ps2x.Button(PSB_PAD_UP)) {
      Serial.println("위 버튼이 눌렸습니다.");
      Motor_PWM = 120;
      ADVANCE();
    }

    // 모터 역방향 회전
    if (ps2x.Button(PSB_PAD_DOWN)) {
      Serial.println("아래 버튼이 눌렸습니다.");
      Motor_PWM = 120;
      BACK();
    }

    // 왼쪽 회전
    if (ps2x.Button(PSB_PAD_LEFT)) {
      Serial.println("왼쪽으로 회전합니다.");
      Motor_PWM = 120; // 200
      LEFT_1();
    }

    // 오른쪽 회전
    if (ps2x.Button(PSB_PAD_RIGHT)) {
      Serial.println("오른쪽으로 회전합니다.");
      Motor_PWM = 120; // 200
      RIGHT_1();
    }

   // 정지
    if (ps2x.Button(PSB_SELECT)) {
      Serial.println("정지합니다.");
      STOP();
    }

    // 왼쪽 이동
    if (ps2x.Button(PSB_PINK)) {
      Serial.println("왼쪽으로 이동합니다.");
      LEFT_2();
    }

    // 오른쪽 이동
    if (ps2x.Button(PSB_RED)) {
      Serial.println("오른쪽으로 이동합니다.");
      RIGHT_2();
    }

    // 왼쪽으로 회전
    if (ps2x.Button(PSB_GREEN)) {
      Serial.println("왼쪽으로 회전합니다.");
      TURN_LEFT();
    }

    // 오른쪽으로 회전
    if (ps2x.Button(PSB_BLUE)) {
      Serial.println("오른쪽으로 회전합니다.");
      TURN_RIGHT();
    }
    delay(20);

  }
  if (ps2x.Button(PSB_L1) || ps2x.Button(PSB_R1)) { // TRUE인 경우 스틱 값을 출력합니다.
    Serial.print("스틱 값:");
    Serial.print(ps2x.Analog(PSS_LY), DEC); // 왼쪽 스틱, Y축. 다른 옵션: LX, RY, RX
    Serial.print(",");
    Serial.print(ps2x.Analog(PSS_LX), DEC);
    Serial.print(",");
    Serial.print(ps2x.Analog(PSS_RY), DEC);
    Serial.print(",");
    Serial.println(ps2x.Analog(PSS_RX), DEC);

    int LY = ps2x.Analog(PSS_LY);
    int LX = ps2x.Analog(PSS_LX);
    int RY = ps2x.Analog(PSS_RY);
    int RX = ps2x.Analog(PSS_RX);

    // 전진
    if (LY < 127)
    {
      Motor_PWM = 1.5 * (127 - LY);
      ADVANCE();
      delay(20);
    }
    // 후진
    if (LY > 127)
    {
      Motor_PWM = 1.5 * (LY - 128);
      BACK();
      delay(20);
    }
    // 왼쪽 회전
    if (LX < 128)
    {
      Motor_PWM = 1.5 * (127 - LX);
      LEFT_1();
      delay(20);
    }
    // 오른쪽 회전
    if (LX > 128)
    {
      Motor_PWM = 1.5 * (LX - 128);
      RIGHT_3();
      delay(20);
    }
    // 조이스틱이 중앙에 있는 경우
    if (LY >= 128 && LY <= 128 && LX >= 128 && LX <= 128)
    {
      STOP();
      delay(20);
    }
  }
}
