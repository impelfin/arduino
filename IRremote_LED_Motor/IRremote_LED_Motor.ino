////IR Remote control code  
//// IR receiver : TSOP1238
//// NEC format remote control
//// TSOP1238 pin1 - Arduino digital pin 2 (external interrupt 0)
//// TSOP1238 pin2 - VCC(5V)
//// TSOP1238 pin3 - GND
//인터럽트 서비스 루틴에 사용되는 변수인 경우 volatile 선언을 해준다.
volatile unsigned long time,new_time,old_time;  
volatile unsigned char ir_check=1, IR_start=0; 
volatile unsigned long mask=0x00000001, IR_rx_data=0x00000000, IR_code; 
int ledPin = 13;                 // LED connected to digital pin 13
int speedPin = 3;
int motor1APin = 6;  // 1A
int motor2APin = 7;  // 2A
int SPEED=100;

void setup(){
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);      // sets the digital pin as output
  pinMode(motor1APin, OUTPUT);
  pinMode(motor2APin, OUTPUT);
  attachInterrupt(0, IR_remote, FALLING);
}

void loop(){
  while(ir_check);
  ir_check=1;
  if(IR_code == 0xBF40FB04) digitalWrite(ledPin, HIGH);   // LED on
  else if (IR_code == 0xBE41FB04) digitalWrite(ledPin, LOW);   // LED off
  else if (IR_code == 0xF807FB04) Motor_go();
  else if (IR_code == 0xF906FB04) Motor_stop();   
}

void Motor_go()
{
  digitalWrite(motor1APin, LOW);
  digitalWrite(motor2APin, HIGH); 
  analogWrite(speedPin, SPEED);
}

void Motor_stop()
{
  digitalWrite(motor1APin, HIGH);
  digitalWrite(motor2APin, LOW);  
  analogWrite(speedPin, SPEED);
}

void IR_remote()  
{
  new_time = micros();          // 현재시간 저장
  time=new_time - old_time;   // 엣지 사이의 시간 계산
  old_time=new_time;            // 이전시간을 현재시간으로 갱신
  if(time > 13000 && time <14000) IR_start=1;   // lead code  13.5ms의 리드코드를 확인합니다. 
  else if(time > 9000 && time <12000)   // repeat code 일때는 무시 입력은 1번만
  {
    Serial.println("R");      // repeat code 가 들어오면 LCD에 'R' 을 출력합니다.
    IR_start=0;               // 변수 초기화
    mask=0x00000001;
    IR_rx_data=0x00000000;
  } 
  else if(IR_start==1)         // 리드코드가 들어 왔다면... 
  {
    if(time > 1025 && time < 1225)          // 1.125ms   0을 받습니다.   
    {
      IR_rx_data &= ~mask;
      mask=mask<<1;       // mask를 1비트씩 시프트 하면서 데이터를 쌓습니다. 
    }
    else if(time > 2125 && time < 2325)     // 2.25ms   1을 받습니다. 
    {     
      IR_rx_data |= mask;
      mask=mask<<1;       // mask를 1비트씩 시프트 하면서 데이터를 쌓습니다.
    }    
                
    if(mask==0)        // mask가 모두 시프트되어 0이되면(32bit data를 모두 받으면.. )
    {       
      IR_code=IR_rx_data;
      Serial.print(IR_code, HEX);  // IR code 값 시리얼로 전송
      Serial.print(" : ");
      Serial.print(IR_code, BIN);
      Serial.println(" ");
      // 변수 초기화                                                                        
      IR_start=0; 
      mask=0x00000001;
      IR_rx_data=0x00000000;     
      
      ir_check=0;
    }  
  }
}

