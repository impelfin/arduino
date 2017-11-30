
 /*
 Serial FND Array Test Program 2
 
표시가능한 FND의 개수를 #define MAX_FND 에서 지정합니다.

serial_fnd() 함수는 long int (32비트 정수 데이터)를 처리할 수 있읍니다.
32 비트 정수는 최대 양정수가 2,147,483,647 이며 최소 음정수는
-2,147,483,648 가 됩니다. 
long int 형 수를 표시하려면 minus부호 표시를 하기 위하여 11 개의 FND가 
연결되어 있어야 합니다.


음수표현시 좌측 FND에 “-“ 표시가 됩니다. FND의 사용 개수가 정해지면
수의 표현 범위가 결정됩니다. 예를들어 FND 개수가 4 으로 지정하면
표시가능한 최대 양정수는 9999 가 됩니다. 그러나 음 정수는 “-“ 를
포함하여야 하므로 -999 가 됩니다. (양수는 4 자리, 음수는 3 자리)
좌측으로의 0 은 블랭크 처리됩니다. 


serial_fnd() 는 long int 변수를 받을수 있도록 되어있습니다.
호출하는 곳에서 넘겨주는 데이터형이 long int  가 아니어도
컴파일시 자동 형변환이 되므로 char, int, long int 형 모두 사용가능합니다.
 SAMPLE Elecronics co.
 
 www.ArduinoPLUS.cc


 */
 
 
#define  MAX_FND 4
 
#define  FND_0   0b00111111         //                    a                //
#define  FND_1   0b00000110         //              ****************       //
#define  FND_2   0b01011011         //             *              *        //
#define  FND_3   0b01001111         //         f  *              * b       //
#define  FND_4   0b01100110         //           *              *          //
#define  FND_5   0b01101101         //          *     g        *           //
#define  FND_6   0b01111101         //         ****************            //
#define  FND_7   0b00100111         //        *              *             //
#define  FND_8   0b01111111         //    e  *              * c            //
#define  FND_9   0b01100111         //      *              *               //
#define  FND_p   0b10000000         //     *              *                //
#define  FND_b   0b00000000         //    ****************    * h          //
#define  FND_m   0b01000000         //          d                          //


 
// HC595 Pin
int hc595_RCLK = 8;
int hc595_SRCLK = 9;
int hc595_SER = 10;


// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(hc595_RCLK, OUTPUT);     
  pinMode(hc595_SRCLK, OUTPUT);     
  pinMode(hc595_SER, OUTPUT);     
}


void ser_out(char a) {
 int i;
 
 digitalWrite(hc595_RCLK, LOW);
 for( i = 0; i<8; i++) {
    digitalWrite(hc595_SRCLK, LOW);
    if(a & 0x80) { digitalWrite(hc595_SER, LOW); 
    } else { 
    digitalWrite(hc595_SER, HIGH);
    }
    digitalWrite(hc595_SRCLK, HIGH);
    a = a<<1;  
 }   
// digitalWrite(hc595_RCLK, HIGH);
}




void conv_dec(long int n) {
  
    int i; 
    unsigned char m =0;
    unsigned char a[10] = {FND_0, FND_1, FND_2, FND_3, FND_4, \
                          FND_5, FND_6, FND_7, FND_8, FND_9 };
    unsigned char b[MAX_FND];  // BCD 데이터 버퍼
    unsigned char c[MAX_FND];  // 세그먼트 패턴 데이터 버퍼
  
    if(n<0) { n = -n; m = FND_m;} // 음수 처리 “-“ 패턴 데이터 저장
    
    i = 0;  //  십진수 변환
    while(1) { b[i] = n%10; n = n/10; i++; if (MAX_FND < i) break; }
    
    for (i = 0; i<MAX_FND; i++) { c[i] = a[b[i]];} // 패턴 데이터 저장


    i = MAX_FND; // 왼쪽 FND의 “0” 패턴 제거
    while(i>1) { if(c[--i] == FND_0) { c[i] = FND_b; } else { break; } }


    if (m) { c[MAX_FND-1] = m; }  // 음수 처리
    
    i = MAX_FND; 
    while(i) { ser_out(c[--i]); } // 패턴 데이터 출력
    digitalWrite(hc595_RCLK, HIGH); // 데이터 래치


}




void loop() {
  
  for (int i = 0; i<101; i++) {
    conv_dec(i);
    delay(100);  
  }
  delay(1000);
  
  for (int i = 0; i>-101; --i) {
    conv_dec(i);
    delay(100);  
  }
  delay(1000);
  
}


////////////////////  End of FILE //////////////////////



