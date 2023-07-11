// 3개의 센서
// 정면 초음파 센서 A 핀 정의
#define Echo_A 22 // 초음파 수신 핀
#define Trig_A 24 // 초음파 제어 핀
// 왼쪽 정면 초음파 센서 B 핀 정의
#define Echo_B 47 // 초음파 수신 핀
#define Trig_B 48 // 초음파 제어 핀
// 오른쪽 정면 초음파 센서 C 핀 정의
#define Echo_C 28 // 초음파 수신 핀
#define Trig_C 25 // 초음파 제어 핀

// 모터 핀 정의
#define PWMA 12 // A모터 속도
#define DIRA1 34
#define DIRA2 35 // A모터 방향
#define PWMB 8 // B모터 속도
#define DIRB1 37
#define DIRB2 36 // B모터 방향
#define PWMC 9 // C모터 속도
#define DIRC1 43
#define DIRC2 42 // C모터 방향
#define PWMD 5 // D모터 속도
#define DIRD1 A4
#define DIRD2 A5 // D모터 방향

// 모터 제어, 전진, 후진, 정지
// 왼쪽 앞 바퀴
#define MOTORA_FORWARD(pwm) do { digitalWrite(DIRA1, LOW); digitalWrite(DIRA2, HIGH); analogWrite(PWMA, pwm); } while (0)
#define MOTORA_STOP(x) do { digitalWrite(DIRA1, LOW); digitalWrite(DIRA2, LOW); analogWrite(PWMA, 0); } while (0)
#define MOTORA_BACKOFF(pwm) do { digitalWrite(DIRA1, HIGH); digitalWrite(DIRA2, LOW); analogWrite(PWMA, pwm); } while (0)
// 오른쪽 앞 바퀴
#define MOTORB_FORWARD(pwm) do { digitalWrite(DIRB1, HIGH); digitalWrite(DIRB2, LOW); analogWrite(PWMB, pwm); } while (0)
#define MOTORB_STOP(x) do { digitalWrite(DIRB1, LOW); digitalWrite(DIRB2, LOW); analogWrite(PWMB, 0); } while (0)
#define MOTORB_BACKOFF(pwm) do { digitalWrite(DIRB1, LOW); digitalWrite(DIRB2, HIGH); analogWrite(PWMB, pwm); } while (0)
// 왼쪽 뒷 바퀴
#define MOTORC_FORWARD(pwm) do { digitalWrite(DIRC1, LOW); digitalWrite(DIRC2, HIGH); analogWrite(PWMC, pwm); } while (0)
#define MOTORC_STOP(x) do { digitalWrite(DIRC1, LOW); digitalWrite(DIRC2, LOW); analogWrite(PWMC, 0); } while (0)
#define MOTORC_BACKOFF(pwm) do { digitalWrite(DIRC1, HIGH); digitalWrite(DIRC2, LOW); analogWrite(PWMC, pwm); } while (0)
// 오른쪽 뒷 바퀴
#define MOTORD_FORWARD(pwm) do { digitalWrite(DIRD1, HIGH); digitalWrite(DIRD2, LOW); analogWrite(PWMD, pwm); } while (0)
#define MOTORD_STOP(x) do { digitalWrite(DIRD1, LOW); digitalWrite(DIRD2, LOW); analogWrite(PWMD, 0); } while (0)
#define MOTORD_BACKOFF(pwm) do { digitalWrite(DIRD1, LOW); digitalWrite(DIRD2, HIGH); analogWrite(PWMD, pwm); } while (0)

#define SERIAL Serial

// PWM 매개변수 정의
#define MAX_PWM 200
#define MIN_PWM 130

int Motor_PWM = 80;
int Motor_PWM_LOW = 70;
int Motor_PWM_HIGH = 100;

// 모터 제어, 전진, 후진, 좌회전, 우회전, 정지 함수

// ↑A-----B↑
// | ↑ |
// | | |
// ↑C-----D↑
void ADVANCE()
{
MOTORA_FORWARD(Motor_PWM_HIGH);
MOTORB_FORWARD(Motor_PWM_HIGH);
MOTORC_FORWARD(Motor_PWM_HIGH);
MOTORD_FORWARD(Motor_PWM_HIGH);
}

// ↓A-----B↓
// | | |
// | ↓ |
// ↓C-----D↓
void BACK()
{
MOTORA_BACKOFF(Motor_PWM);
MOTORB_BACKOFF(Motor_PWM);
MOTORC_BACKOFF(Motor_PWM);
MOTORD_BACKOFF(Motor_PWM);
}

// =A-----B↑
// | ↖ |
// | ↖ |
// ↑C-----D=
void LEFT_1()
{
MOTORA_FORWARD(Motor_PWM);
MOTORB_STOP(Motor_PWM);
MOTORC_STOP(Motor_PWM);
MOTORD_FORWARD(Motor_PWM);
}

// ↓A-----B↑
// | ← |
// | ← |
// ↑C-----D↓
void LEFT_2()
{
MOTORA_BACKOFF(Motor_PWM_LOW);
MOTORB_FORWARD(Motor_PWM_LOW);
MOTORC_FORWARD(Motor_PWM_LOW);
MOTORD_BACKOFF(Motor_PWM_LOW);
}

// ↓A-----B=
// | ↙ |
// | ↙ |
// =C-----D↓
void LEFT_3()
{
MOTORA_BACKOFF(Motor_PWM);
MOTORB_STOP(Motor_PWM);
MOTORC_STOP(Motor_PWM);
MOTORD_BACKOFF(Motor_PWM);
}

// ↑A-----B=
// | ↗ |
// | ↗ |
// =C-----D↑
void RIGHT_1()
{
MOTORA_FORWARD(Motor_PWM);
MOTORB_STOP(Motor_PWM);
MOTORC_STOP(Motor_PWM);
MOTORD_FORWARD(Motor_PWM);
}

// ↑A-----B↓
// | → |
// | → |
// ↓C-----D↑
void RIGHT_2()
{
MOTORA_FORWARD(Motor_PWM_LOW);
MOTORB_BACKOFF(Motor_PWM_LOW);
MOTORC_BACKOFF(Motor_PWM_LOW);
MOTORD_FORWARD(Motor_PWM_LOW);
}

// =A-----B↓
// | ↘ |
// | ↘ |
// ↓C-----D=
void RIGHT_3()
{
MOTORA_STOP(Motor_PWM);
MOTORB_BACKOFF(Motor_PWM);
MOTORC_BACKOFF(Motor_PWM);
MOTORD_STOP(Motor_PWM);
}

// ↑A-----B↓
// | ↗ ↘ |
// | ↖ ↙ |
// ↑C-----D↓
void rotate_1(uint8_t pwm_A, uint8_t// 테스트 거리 초기화
float echoDistance_A;
float echoDistance_B;
float echoDistance_C;
int leftDistance = 0;
int rightDistance = 0;
int forwardDistance = 0;

#define LOG_DEBUG

#ifdef LOG_DEBUG
#define M_LOG SERIAL.print
#else
#define M_LOG
#endif

void IO_init() // 핀 모드 설정
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
pinMode(Trig_A, OUTPUT);
pinMode(Echo_A, INPUT);
pinMode(Trig_B, OUTPUT);
pinMode(Echo_B, INPUT);
pinMode(Trig_C, OUTPUT);
pinMode(Echo_C, INPUT);
STOP();
}

int testDistance_A() { // 거리 측정 함수
// 초음파 모듈 활성화
digitalWrite(Trig_A, LOW);
delayMicroseconds(2);
digitalWrite(Trig_A, HIGH);
delayMicroseconds(20);
digitalWrite(Trig_A, LOW);
echoDistance_A = pulseIn(Echo_A, HIGH);
echoDistance_A /= 58; // echoDistance = echoDistance ÷ 58
return (int)echoDistance_A;
}

int testDistance_B() { // 거리 측정 함수
// 초음파 모듈 활성화
digitalWrite(Trig_B, LOW);
delayMicroseconds(2);
digitalWrite(Trig_B, HIGH);
delayMicroseconds(20);
digitalWrite(Trig_B, LOW);
echoDistance_B = pulseIn(Echo_B, HIGH);
echoDistance_B /= 58; // echoDistance = echoDistance ÷ 58
return (int)echoDistance_B;
}

int testDistance_C() { // 거리 측정 함수
// 초음파 모듈 활성화
digitalWrite(Trig_C, LOW);
delayMicroseconds(2);
digitalWrite(Trig_C, HIGH);
delayMicroseconds(20);
digitalWrite(Trig_C, LOW);
echoDistance_C = pulseIn(Echo_C, HIGH);
echoDistance_C /= 58; // echoDistance = echoDistance ÷ 58
return (int)echoDistance_C;
}

void setup() {
SERIAL.begin(9600);
IO_init();
}

void loop() {
forwardDistance = testDistance_A(); // 전방 거리 데이터 저장
leftDistance = testDistance_B(); // 왼쪽 거리 데이터 저장
rightDistance = testDistance_C(); // 오른쪽 거리 데이터 저장

if (forwardDistance <= 30) {
if (leftDistance <= 30) {
RIGHT_2();

swift
Copy code
  M_LOG("왼쪽, 전방에 장애물이 있어서 오른쪽으로 이동합니다.\r\n");
}
else {
  LEFT_2();
  M_LOG("오른쪽, 전방에 장애물이 있어서 왼쪽으로 이동합니다.\r\n");
}
}
else if (leftDistance <= 30) {
RIGHT_2();
M_LOG("왼쪽에 장애물이 있어서 오른쪽으로 이동합니다.\r\n");
}
else if (rightDistance <= 30) {
LEFT_2();
M_LOG("오른쪽에 장애물이 있어서 왼쪽으로 이동합니다!\r\n");
}
else {
ADVANCE();
M_LOG("전진합니다.\r\n");
}
}// 3개의 센서
// 정면 초음파 센서 A 핀 정의
#define Echo_A 22 // 초음파 수신 핀
#define Trig_A 24 // 초음파 제어 핀
// 왼쪽 정면 초음파 센서 B 핀 정의
#define Echo_B 47 // 초음파 수신 핀
#define Trig_B 48 // 초음파 제어 핀
// 오른쪽 정면 초음파 센서 C 핀 정의
#define Echo_C 28 // 초음파 수신 핀
#define Trig_C 25 // 초음파 제어 핀

// 모터 핀 정의
#define PWMA 12 // A모터 속도
#define DIRA1 34
#define DIRA2 35 // A모터 방향
#define PWMB 8 // B모터 속도
#define DIRB1 37
#define DIRB2 36 // B모터 방향
#define PWMC 9 // C모터 속도
#define DIRC1 43
#define DIRC2 42 // C모터 방향
#define PWMD 5 // D모터 속도
#define DIRD1 A4
#define DIRD2 A5 // D모터 방향

// 모터 제어, 전진, 후진, 정지
// 왼쪽 앞 바퀴
#define MOTORA_FORWARD(pwm) do { digitalWrite(DIRA1, LOW); digitalWrite(DIRA2, HIGH); analogWrite(PWMA, pwm); } while (0)
#define MOTORA_STOP(x) do { digitalWrite(DIRA1, LOW); digitalWrite(DIRA2, LOW); analogWrite(PWMA, 0); } while (0)
#define MOTORA_BACKOFF(pwm) do { digitalWrite(DIRA1, HIGH); digitalWrite(DIRA2, LOW); analogWrite(PWMA, pwm); } while (0)
// 오른쪽 앞 바퀴
#define MOTORB_FORWARD(pwm) do { digitalWrite(DIRB1, HIGH); digitalWrite(DIRB2, LOW); analogWrite(PWMB, pwm); } while (0)
#define MOTORB_STOP(x) do { digitalWrite(DIRB1, LOW); digitalWrite(DIRB2, LOW); analogWrite(PWMB, 0); } while (0)
#define MOTORB_BACKOFF(pwm) do { digitalWrite(DIRB1, LOW); digitalWrite(DIRB2, HIGH); analogWrite(PWMB, pwm); } while (0)
// 왼쪽 뒷 바퀴
#define MOTORC_FORWARD(pwm) do { digitalWrite(DIRC1, LOW); digitalWrite(DIRC2, HIGH); analogWrite(PWMC, pwm); } while (0)
#define MOTORC_STOP(x) do { digitalWrite(DIRC1, LOW); digitalWrite(DIRC2, LOW); analogWrite(PWMC, 0); } while (0)
#define MOTORC_BACKOFF(pwm) do { digitalWrite(DIRC1, HIGH); digitalWrite(DIRC2, LOW); analogWrite(PWMC, pwm); } while (0)
// 오른쪽 뒷 바퀴
#define MOTORD_FORWARD(pwm) do { digitalWrite(DIRD1, HIGH); digitalWrite(DIRD2, LOW); analogWrite(PWMD, pwm); } while (0)
#define MOTORD_STOP(x) do { digitalWrite(DIRD1, LOW); digitalWrite(DIRD2, LOW); analogWrite(PWMD, 0); } while (0)
#define MOTORD_BACKOFF(pwm) do { digitalWrite(DIRD1, LOW); digitalWrite(DIRD2, HIGH); analogWrite(PWMD, pwm); } while (0)

#define SERIAL Serial

// PWM 매개변수 정의
#define MAX_PWM 200
#define MIN_PWM 130

int Motor_PWM = 80;
int Motor_PWM_LOW = 70;
int Motor_PWM_HIGH = 100;

// 모터 제어, 전진, 후진, 좌회전, 우회전, 정지 함수

// ↑A-----B↑
// | ↑ |
// | | |
// ↑C-----D↑
void ADVANCE()
{
MOTORA_FORWARD(Motor_PWM_HIGH);
MOTORB_FORWARD(Motor_PWM_HIGH);
MOTORC_FORWARD(Motor_PWM_HIGH);
MOTORD_FORWARD(Motor_PWM_HIGH);
}

// ↓A-----B↓
// | | |
// | ↓ |
// ↓C-----D↓
void BACK()
{
MOTORA_BACKOFF(Motor_PWM);
MOTORB_BACKOFF(Motor_PWM);
MOTORC_BACKOFF(Motor_PWM);
MOTORD_BACKOFF(Motor_PWM);
}

// =A-----B↑
// | ↖ |
// | ↖ |
// ↑C-----D=
void LEFT_1()
{
MOTORA_FORWARD(Motor_PWM);
MOTORB_STOP(Motor_PWM);
MOTORC_STOP(Motor_PWM);
MOTORD_FORWARD(Motor_PWM);
}

// ↓A-----B↑
// | ← |
// | ← |
// ↑C-----D↓
void LEFT_2()
{
MOTORA_BACKOFF(Motor_PWM_LOW);
MOTORB_FORWARD(Motor_PWM_LOW);
MOTORC_FORWARD(Motor_PWM_LOW);
MOTORD_BACKOFF(Motor_PWM_LOW);
}

// ↓A-----B=
// | ↙ |
// | ↙ |
// =C-----D↓
void LEFT_3()
{
MOTORA_BACKOFF(Motor_PWM);
MOTORB_STOP(Motor_PWM);
MOTORC_STOP(Motor_PWM);
MOTORD_BACKOFF(Motor_PWM);
}

// ↑A-----B=
// | ↗ |
// | ↗ |
// =C-----D↑
void RIGHT_1()
{
MOTORA_FORWARD(Motor_PWM);
MOTORB_STOP(Motor_PWM);
MOTORC_STOP(Motor_PWM);
MOTORD_FORWARD(Motor_PWM);
}

// ↑A-----B↓
// | → |
// | → |
// ↓C-----D↑
void RIGHT_2()
{
MOTORA_FORWARD(Motor_PWM_LOW);
MOTORB_BACKOFF(Motor_PWM_LOW);
MOTORC_BACKOFF(Motor_PWM_LOW);
MOTORD_FORWARD(Motor_PWM_LOW);
}

// =A-----B↓
// | ↘ |
// | ↘ |
// ↓C-----D=
void RIGHT_3()
{
MOTORA_STOP(Motor_PWM);
MOTORB_BACKOFF(Motor_PWM);
MOTORC_BACKOFF(Motor_PWM);
MOTORD_STOP(Motor_PWM);
}

// ↑A-----B↓
// | ↗ ↘ |
// | ↖ ↙ |
// ↑C-----D↓
void rotate_1(uint8_t pwm_A, uint8_t// 테스트 거리 초기화
float echoDistance_A;
float echoDistance_B;
float echoDistance_C;
int leftDistance = 0;
int rightDistance = 0;
int forwardDistance = 0;

#define LOG_DEBUG

#ifdef LOG_DEBUG
#define M_LOG SERIAL.print
#else
#define M_LOG
#endif

void IO_init() // 핀 모드 설정
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
pinMode(Trig_A, OUTPUT);
pinMode(Echo_A, INPUT);
pinMode(Trig_B, OUTPUT);
pinMode(Echo_B, INPUT);
pinMode(Trig_C, OUTPUT);
pinMode(Echo_C, INPUT);
STOP();
}

int testDistance_A() { // 거리 측정 함수
// 초음파 모듈 활성화
digitalWrite(Trig_A, LOW);
delayMicroseconds(2);
digitalWrite(Trig_A, HIGH);
delayMicroseconds(20);
digitalWrite(Trig_A, LOW);
echoDistance_A = pulseIn(Echo_A, HIGH);
echoDistance_A /= 58; // echoDistance = echoDistance ÷ 58
return (int)echoDistance_A;
}

int testDistance_B() { // 거리 측정 함수
// 초음파 모듈 활성화
digitalWrite(Trig_B, LOW);
delayMicroseconds(2);
digitalWrite(Trig_B, HIGH);
delayMicroseconds(20);
digitalWrite(Trig_B, LOW);
echoDistance_B = pulseIn(Echo_B, HIGH);
echoDistance_B /= 58; // echoDistance = echoDistance ÷ 58
return (int)echoDistance_B;
}

int testDistance_C() { // 거리 측정 함수
// 초음파 모듈 활성화
digitalWrite(Trig_C, LOW);
delayMicroseconds(2);
digitalWrite(Trig_C, HIGH);
delayMicroseconds(20);
digitalWrite(Trig_C, LOW);
echoDistance_C = pulseIn(Echo_C, HIGH);
echoDistance_C /= 58; // echoDistance = echoDistance ÷ 58
return (int)echoDistance_C;
}

void setup() {
SERIAL.begin(9600);
IO_init();
}

void loop() {
forwardDistance = testDistance_A(); // 전방 거리 데이터 저장
leftDistance = testDistance_B(); // 왼쪽 거리 데이터 저장
rightDistance = testDistance_C(); // 오른쪽 거리 데이터 저장

if (forwardDistance <= 30) {
if (leftDistance <= 30) {
RIGHT_2();

swift
Copy code
  M_LOG("왼쪽, 전방에 장애물이 있어서 오른쪽으로 이동합니다.\r\n");
}
else {
  LEFT_2();
  M_LOG("오른쪽, 전방에 장애물이 있어서 왼쪽으로 이동합니다.\r\n");
}
}
else if (leftDistance <= 30) {
RIGHT_2();
M_LOG("왼쪽에 장애물이 있어서 오른쪽으로 이동합니다.\r\n");
}
else if (rightDistance <= 30) {
LEFT_2();
M_LOG("오른쪽에 장애물이 있어서 왼쪽으로 이동합니다!\r\n");
}
else {
ADVANCE();
M_LOG("전진합니다.\r\n");
}
}
