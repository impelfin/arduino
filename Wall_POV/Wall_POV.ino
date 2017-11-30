// http://cafe.naver.com/arduinostory/32216

// Serial Header
#include <SoftwareSerial.h>


// Serial pin set ( Rx = digital pin 0 , Tx = digital pin 1
SoftwareSerial mySerial(0, 1);


// 2D Matrix alphabet Upper case
int A[5][8] = {{0,0,0,1,1,1,1,0},{0,1,1,0,1,0,0,0},{1,0,0,0,1,0,0,0},{0,1,1,0,1,0,0,0},{0,0,0,1,1,1,1,0}};
int B[5][8] = {{1,1,1,1,1,1,1,0},{1,0,0,1,0,0,1,0},{1,0,0,1,0,0,1,0},{1,0,0,1,0,0,1,0},{0,1,1,0,1,1,0,0}};
int C[5][8] = {{0,1,1,1,1,1,0,0},{1,0,0,0,0,0,1,0},{1,0,0,0,0,0,1,0},{1,0,0,0,0,0,1,0},{0,1,0,0,0,1,0,0}};
int D[5][8] = {{1,1,1,1,1,1,1,0},{1,0,0,0,0,0,1,0},{1,0,0,0,0,0,1,0},{1,0,0,0,0,0,1,0},{0,1,1,1,1,1,0,0}};
int E[5][8] = {{1,1,1,1,1,1,1,0},{1,0,0,1,0,0,1,0},{1,0,0,1,0,0,1,0},{1,0,0,1,0,0,1,0},{1,0,0,1,0,0,1,0}};
int F[5][8] = {{1,1,1,1,1,1,1,0},{1,0,0,1,0,0,0,0},{1,0,0,1,0,0,0,0},{1,0,0,1,0,0,0,0},{1,0,0,0,0,0,0,0}};
int G[5][8] = {{0,1,1,1,1,1,0,0},{1,0,0,0,0,0,1,0},{1,0,0,0,0,0,1,0},{1,0,0,1,0,0,1,0},{0,1,0,1,1,1,0,0}};
int H[5][8] = {{1,1,1,1,1,1,1,0},{0,0,0,1,0,0,0,0},{0,0,0,1,0,0,0,0},{0,0,0,1,0,0,0,0},{1,1,1,1,1,1,1,0}};
int I[5][8] = {{0,0,0,0,0,0,0,0},{1,0,0,0,0,0,1,0},{1,1,1,1,1,1,1,0},{1,0,0,0,0,0,1,0},{0,0,0,0,0,0,0,0}};
int J[5][8] = {{1,0,0,0,0,1,0,0},{1,0,0,0,0,0,1,0},{1,0,0,0,0,0,1,0},{1,1,1,1,1,1,0,0},{1,0,0,0,0,0,0,0}};
int K[5][8] = {{1,1,1,1,1,1,1,0},{0,0,0,1,0,0,0,0},{0,0,1,0,1,0,0,0},{0,1,0,0,0,1,0,0},{1,0,0,0,0,0,1,0}};
int L[5][8] = {{1,1,1,1,1,1,1,0},{0,0,0,0,0,0,1,0},{0,0,0,0,0,0,1,0},{0,0,0,0,0,0,1,0},{0,0,0,0,0,0,1,0}};
int M[5][8] = {{1,1,1,1,1,1,1,0},{0,0,1,0,0,0,0,0},{0,0,0,1,1,0,0,0},{0,0,1,0,0,0,0,0},{1,1,1,1,1,1,1,0}};
int N[5][8] = {{1,1,1,1,1,1,1,0},{0,0,1,0,0,0,0,0},{0,0,0,1,0,0,0,0},{0,0,0,0,1,0,0,0},{1,1,1,1,1,1,1,0}};
int O[5][8] = {{0,1,1,1,1,1,0,0},{1,0,0,0,0,0,1,0},{1,0,0,0,0,0,1,0},{1,0,0,0,0,0,1,0},{0,1,1,1,1,1,0,0}};
int P[5][8] = {{1,1,1,1,1,1,1,0},{1,0,0,1,0,0,0,0},{1,0,0,1,0,0,0,0},{1,0,0,1,0,0,0,0},{0,1,1,0,0,0,0,0}};
int Q[5][8] = {{0,1,1,1,1,1,0,0},{1,0,0,0,0,0,1,0},{1,0,0,0,1,0,1,0},{1,0,0,0,0,1,0,0},{0,1,1,1,1,0,1,0}};
int R[5][8] = {{1,1,1,1,1,1,1,0},{1,0,0,1,0,0,0,0},{1,0,0,1,0,0,0,0},{1,0,0,1,0,0,0,0},{0,1,1,0,1,1,1,0}};
int S[5][8] = {{0,1,1,0,0,1,0,0},{1,0,0,1,0,0,1,0},{1,0,0,1,0,0,1,0},{1,0,0,1,0,0,1,0},{0,1,0,0,1,1,0,0}};
int T[5][8] = {{1,0,0,0,0,0,0,0},{1,0,0,0,0,0,0,0},{1,1,1,1,1,1,1,0},{1,0,0,0,0,0,0,0},{1,0,0,0,0,0,0,0}};
int U[5][8] = {{1,1,1,1,1,1,0,0},{0,0,0,0,0,0,1,0},{0,0,0,0,0,0,1,0},{0,0,0,0,0,0,1,0},{1,1,1,1,1,1,0,0}};
int V[5][8] = {{1,1,1,0,0,0,0,0},{0,0,0,1,1,0,0,0},{0,0,0,0,0,1,1,0},{0,0,0,1,1,0,0,0},{1,1,1,0,0,0,0,0}};
int W[5][8] = {{1,1,1,1,0,0,0,0},{0,0,0,0,0,1,1,0},{0,0,0,1,1,0,0,0},{0,0,0,0,0,1,1,0},{1,1,1,1,1,0,0,0}};
int X[5][8] = {{1,1,0,0,0,1,1,0},{0,0,1,0,1,0,0,0},{0,0,0,1,0,0,0,0},{0,0,1,0,1,0,0,0},{1,1,0,0,0,1,1,0}};
int Y[5][8] = {{1,1,0,0,0,0,0,0},{0,0,1,0,0,0,0,0},{0,0,0,1,1,1,1,0},{0,0,1,0,0,0,0,0},{1,1,0,0,0,0,0,0}};
int Z[5][8] = {{1,0,0,0,0,1,1,0},{1,0,0,0,1,0,1,0},{1,0,0,1,0,0,1,0},{1,0,1,0,0,0,1,0},{1,1,0,0,0,0,1,0}};


// 1D Matrix alphabet Upper case
byte A_5[7] = {0b00011110,0b01101000,0b10001000,0b01101000,0b00011110,0b00000000,0b00000000};
byte B_5[7] = {0b11111110,0b10010010,0b10010010,0b10010010,0b01101100,0b00000000,0b00000000};
byte C_5[7] = {0b01111100,0b10000010,0b10000010,0b10000010,0b01000100,0b00000000,0b00000000};
byte D_5[7] = {0b11111110,0b10000010,0b10000010,0b10000010,0b01111100,0b00000000,0b00000000};
byte E_5[7] = {0b11111110,0b10010010,0b10010010,0b10010010,0b10010010,0b00000000,0b00000000};
byte F_5[7] = {0b11111110,0b10010000,0b10010000,0b10010000,0b10000000,0b00000000,0b00000000};
byte G_5[7] = {0b01111100,0b10000010,0b10000010,0b10010010,0b01011100,0b00000000,0b00000000};
byte H_5[7] = {0b11111110,0b00010000,0b00010000,0b00010000,0b11111110,0b00000000,0b00000000};
byte I_5[7] = {0b00000000,0b10000010,0b11111110,0b10000010,0b00000000,0b00000000,0b00000000};
byte J_5[7] = {0b10000100,0b10000010,0b10000010,0b11111100,0b10000000,0b00000000,0b00000000};
byte K_5[7] = {0b11111110,0b00010000,0b00101000,0b01000100,0b10000010,0b00000000,0b00000000};
byte L_5[7] = {0b11111110,0b00000010,0b00000010,0b00000010,0b00000010,0b00000000,0b00000000};
byte M_5[7] = {0b11111110,0b00100000,0b00011000,0b00100000,0b11111110,0b00000000,0b00000000};
byte N_5[7] = {0b11111110,0b00100000,0b00010000,0b00001000,0b11111110,0b00000000,0b00000000};
byte O_5[7] = {0b01111100,0b10000010,0b10000010,0b10000010,0b01111100,0b00000000,0b00000000};
byte P_5[7] = {0b11111110,0b10010000,0b10010000,0b10010000,0b01100000,0b00000000,0b00000000};
byte Q_5[7] = {0b01111100,0b10000010,0b10001010,0b10000100,0b01111010,0b00000000,0b00000000};
byte R_5[7] = {0b11111110,0b10010000,0b10010000,0b10010000,0b01101110,0b00000000,0b00000000};
byte S_5[7] = {0b01100100,0b10010010,0b10010010,0b10010010,0b01001100,0b00000000,0b00000000};
byte T_5[7] = {0b10000000,0b10000000,0b11111110,0b10000000,0b10000000,0b00000000,0b00000000};
byte U_5[7] = {0b11111100,0b00000010,0b00000010,0b00000010,0b11111100,0b00000000,0b00000000};
byte V_5[7] = {0b11100000,0b00011000,0b00000110,0b00011000,0b11100000,0b00000000,0b00000000};
byte W_5[7] = {0b11110000,0b00000110,0b00011000,0b00000110,0b11111000,0b00000000,0b00000000};
byte X_5[7] = {0b11000110,0b00101000,0b00010000,0b00101000,0b11000110,0b00000000,0b00000000};
byte Y_5[7] = {0b11000000,0b00100000,0b00011110,0b00100000,0b11000000,0b00000000,0b00000000};
byte Z_5[7] = {0b10000110,0b10001010,0b10010010,0b10100010,0b11000010,0b00000000,0b00000000};


// 1D Matrix alphabet Lower case
byte a_7[7] = {0b00000100,0b00101010,0b00101010,0b00011100,0b00000010,0b00000000,0b00000000};
byte b_7[7] = {0b00000100,0b01111110,0b00001010,0b00001010,0b00000100,0b00000000,0b00000100};
byte c_7[7] = {0b00000100,0b00011100,0b00100010,0b00100010,0b00010100,0b00000100,0b00000100};
byte d_7[7] = {0b00000100,0b00000100,0b00001010,0b00001010,0b01111110,0b00000100,0b00000100};
byte e_7[7] = {0b00000100,0b00011100,0b00101010,0b00101010,0b00111010,0b00000100,0b00000100};
byte f_7[7] = {0b00000100,0b00001000,0b00111110,0b01001000,0b01001000,0b00000100,0b00000100};
byte g_7[7] = {0b00000100,0b00010100,0b00101010,0b00101010,0b01111100,0b00000100,0b00000100};
byte h_7[7] = {0b00000100,0b01111110,0b00001000,0b00010000,0b00001110,0b00000100,0b00000100};
byte i_7[7] = {0b00000100,0b00000100,0b01000010,0b01011110,0b00000010,0b00000100,0b00000100};
byte j_7[7] = {0b00000100,0b01000100,0b01000010,0b01111100,0b01000000,0b00000100,0b00000100};
byte k_7[7] = {0b00000100,0b01111110,0b00001000,0b00010100,0b00100010,0b00000100,0b00000100};
byte l_7[7] = {0b00000100,0b00111010,0b01000100,0b00111010,0b00000010,0b00000100,0b00000100};
byte m_7[7] = {0b00111110,0b00010000,0b00001110,0b00010000,0b00001110,0b00000100,0b00000100};
byte n_7[7] = {0b00000100,0b00011110,0b00001000,0b00010000,0b00001110,0b00000100,0b00000100};
byte o_7[7] = {0b00000100,0b00001100,0b00010010,0b00010010,0b00001100,0b00000100,0b00000100};
byte p_7[7] = {0b00000100,0b00111110,0b00101000,0b00101000,0b00010000,0b00000100,0b00000100};
byte q_7[7] = {0b00000100,0b00111110,0b00101000,0b00101000,0b00010000,0b00000100,0b00000100};
byte r_7[7] = {0b00000000,0b00111110,0b00001000,0b00010000,0b00001000,0b00000000,0b00000000};
byte s_7[7] = {0b00000000,0b00100100,0b01010010,0b01001010,0b00100100,0b00000000,0b00000000};
byte t_7[7] = {0b00000000,0b00100000,0b01111100,0b00100010,0b00100100,0b00000000,0b00000000};
byte u_7[7] = {0b00000000,0b00111100,0b00000010,0b00000100,0b00111110,0b00000000,0b00000000};
byte v_7[7] = {0b00000000,0b00011000,0b00000100,0b00000010,0b00000100,0b00011000,0b00000000};
byte w_7[7] = {0b00000000,0b00011000,0b00000110,0b00001000,0b00000110,0b00011000,0b00000000};
byte x_7[7] = {0b00000000,0b00100010,0b00010100,0b00001000,0b00010100,0b00100010,0b00000000};
byte y_7[7] = {0b00000000,0b00100010,0b00010100,0b00001000,0b00110000,0b00000000,0b00000000};
byte z_7[7] = {0b00000000,0b00100010,0b00100110,0b00101010,0b00110010,0b00000000,0b00000000};


// just test image
//  at magnet hall sensor
byte Start_Line[7] ={0b00100000,0b00110000,0b01111000,0b11111100,0b01111000,0b00110000,0b00100000};


// Cursor arrow image
byte arrow[8] = {0b00100100,0b00100100,0b01000010,0b10000001,0b01000010,0b00100100,0b00100100,0b00000000};


// Spining squrebox image ( now,  not use)
byte image_8_SqureBox[4][8] = {
{0b11000001,0b00000001,0b00000000,0b00000000,0b00000000,0b00000000,0b10000000,0b10000011},
{0b00110000,0b00000000,0b00000001,0b00000001,0b10000000,0b10000000,0b00000000,0b00001100},
{0b00001100,0b00000000,0b10000000,0b10000000,0b00000001,0b00000001,0b00000000,0b00110000},
{0b10000011,0b10000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000001,0b11000001}};


// Spining squre box image ( use )
// 8 frame image
byte image_8_SqureBox2[8][8] = {
{0b10000001,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b10000001},
{0b01000000,0b00000001,0b00000000,0b00000000,0b00000000,0b00000000,0b10000000,0b00000010},
{0b00100000,0b00000000,0b00000001,0b00000000,0b00000000,0b10000000,0b00000000,0b00000100},
{0b00010000,0b00000000,0b00000000,0b00000001,0b10000000,0b00000000,0b00000000,0b00001000},
{0b00001000,0b00000000,0b00000000,0b10000000,0b00000001,0b00000000,0b00000000,0b00010000},
{0b00000100,0b00000000,0b10000000,0b00000000,0b00000000,0b00000001,0b00000000,0b00100000},
{0b00000010,0b10000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000001,0b01000000},
{0b10000001,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b10000001}};


int revo = 0;          		// number check revolutionary
int Real_Pont[5][8];   		// truely display image 2D matrix
int Turn_String = 1;   		// Position of Cursor, starting point is [1]  ( 0 => hall sensor, end = 40)
byte Font_String[50][7];	// not use now.
byte Blank_String = 0b00000000;  // byte data of blank
char c = 'Z';                    //bluetooth Serial charactor , a~z , A~Z , 

int TS_next_s = 0;      	// check c present        (not use now)
int TS_next_l = 0;      	// check c before         (not use now)
int go_zerostart_s = 0; 	//                        (not use now) 
int go_zerostart_l = 0;		//                        (not use now)
int xx = 0; int i; int j; 	// variable for FOR STATEMENT 

char dummy_c = '.';			// variable c's dummy


// I/O Port set //-----------------------------------------------------------------------
const int magnet = 2;	//magnet hall sensor
const int clk = 9;		// shift register's clock
const int data = 11;	// shift register's Serial data input
const int latch = 10;	// shift register's Latch ( Display Off at LOW, Display On at HIGH )
//---------------------------------------------------------------------------------------


//Magnet Hall sensor
int sbt = HIGH;      // DigitalRead value of magnet hall sensor (present value)
int lbt = HIGH;      // DigitalRead value of magnet hall sensor (last value)

int stat_c = 0;      

int ct = 0;         // smallest counter , increase at one loop
int cct = 0;        // increase at 
int ccct = 0;


//POV Display Function//-----------------------------------------------------------------

void disp()
{
  // Font_String Display is Top line
    digitalWrite(latch,LOW);
    if(ct <=4 )
    {
      shiftOut(data,clk,MSBFIRST,Font_String[cct][ct]);
    }
    else
    {
      shiftOut(data,clk,MSBFIRST,Blank_String);
    }
    
    
  // Insert Cursor Location arrow is Middle line
    if(cct == Turn_String )
    {
      shiftOut(data,clk,MSBFIRST,arrow[ct]);
    }
    else
    {
      shiftOut(data,clk,MSBFIRST,Blank_String);
    }
  
  // Image is Bottom Line
  if ( cct == 8 || cct == 10)
  {
    shiftOut(data,clk,MSBFIRST,image_8_SqureBox2[ccct/2][ct]);
  }
  else
  {
      shiftOut(data,clk,MSBFIRST,Blank_String);
  }

    
  digitalWrite(latch,HIGH);

}

//---------------------------------------------------------------------------------------


void set_Font()
{  
  if ( c == 'A') {  for(i=0;i<=6;i++) { Font_String[Turn_String][i] = A_5[i]; }  }
  if ( c == 'B') {  for(i=0;i<=6;i++) { Font_String[Turn_String][i] = B_5[i]; }  }
  if ( c == 'C') {  for(i=0;i<=6;i++) { Font_String[Turn_String][i] = C_5[i]; }  }
  if ( c == 'D') {  for(i=0;i<=6;i++) { Font_String[Turn_String][i] = D_5[i]; }  }
  if ( c == 'E') {  for(i=0;i<=6;i++) { Font_String[Turn_String][i] = E_5[i]; }  }
  if ( c == 'F') {  for(i=0;i<=6;i++) { Font_String[Turn_String][i] = F_5[i]; }  }
  if ( c == 'G') {  for(i=0;i<=6;i++) { Font_String[Turn_String][i] = G_5[i]; }  }
  if ( c == 'H') {  for(i=0;i<=6;i++) { Font_String[Turn_String][i] = H_5[i]; }  }
  if ( c == 'I') {  for(i=0;i<=6;i++) { Font_String[Turn_String][i] = I_5[i]; }  }
  if ( c == 'J') {  for(i=0;i<=6;i++) { Font_String[Turn_String][i] = J_5[i]; }  }
  if ( c == 'K') {  for(i=0;i<=6;i++) { Font_String[Turn_String][i] = K_5[i]; }  }
  if ( c == 'L') {  for(i=0;i<=6;i++) { Font_String[Turn_String][i] = L_5[i]; }  }
  if ( c == 'M') {  for(i=0;i<=6;i++) { Font_String[Turn_String][i] = M_5[i]; }  }
  if ( c == 'N') {  for(i=0;i<=6;i++) { Font_String[Turn_String][i] = N_5[i]; }  }
  if ( c == 'O') {  for(i=0;i<=6;i++) { Font_String[Turn_String][i] = O_5[i]; }  }
  if ( c == 'P') {  for(i=0;i<=6;i++) { Font_String[Turn_String][i] = P_5[i]; }  }
  if ( c == 'Q') {  for(i=0;i<=6;i++) { Font_String[Turn_String][i] = Q_5[i]; }  }
  if ( c == 'R') {  for(i=0;i<=6;i++) { Font_String[Turn_String][i] = R_5[i]; }  }
  if ( c == 'S') {  for(i=0;i<=6;i++) { Font_String[Turn_String][i] = S_5[i]; }  }
  if ( c == 'T') {  for(i=0;i<=6;i++) { Font_String[Turn_String][i] = T_5[i]; }  }
  if ( c == 'U') {  for(i=0;i<=6;i++) { Font_String[Turn_String][i] = U_5[i]; }  }
  if ( c == 'V') {  for(i=0;i<=6;i++) { Font_String[Turn_String][i] = V_5[i]; }  }
  if ( c == 'W') {  for(i=0;i<=6;i++) { Font_String[Turn_String][i] = W_5[i]; }  }
  if ( c == 'X') {  for(i=0;i<=6;i++) { Font_String[Turn_String][i] = X_5[i]; }  }
  if ( c == 'Y') {  for(i=0;i<=6;i++) { Font_String[Turn_String][i] = Y_5[i]; }  }
  if ( c == 'Z') {  for(i=0;i<=6;i++) { Font_String[Turn_String][i] = Z_5[i]; }  }
  
  if ( c == 'a') {  for(i=0;i<=6;i++) { Font_String[Turn_String][i] = a_7[i]; }  }
  if ( c == 'b') {  for(i=0;i<=6;i++) { Font_String[Turn_String][i] = b_7[i]; }  }
  if ( c == 'c') {  for(i=0;i<=6;i++) { Font_String[Turn_String][i] = c_7[i]; }  }
  if ( c == 'd') {  for(i=0;i<=6;i++) { Font_String[Turn_String][i] = d_7[i]; }  }
  if ( c == 'e') {  for(i=0;i<=6;i++) { Font_String[Turn_String][i] = e_7[i]; }  }
  if ( c == 'f') {  for(i=0;i<=6;i++) { Font_String[Turn_String][i] = f_7[i]; }  }
  if ( c == 'g') {  for(i=0;i<=6;i++) { Font_String[Turn_String][i] = g_7[i]; }  }
  if ( c == 'h') {  for(i=0;i<=6;i++) { Font_String[Turn_String][i] = h_7[i]; }  }
  if ( c == 'i') {  for(i=0;i<=6;i++) { Font_String[Turn_String][i] = i_7[i]; }  }
  if ( c == 'j') {  for(i=0;i<=6;i++) { Font_String[Turn_String][i] = j_7[i]; }  }
  if ( c == 'k') {  for(i=0;i<=6;i++) { Font_String[Turn_String][i] = k_7[i]; }  }
  if ( c == 'l') {  for(i=0;i<=6;i++) { Font_String[Turn_String][i] = l_7[i]; }  }
  if ( c == 'm') {  for(i=0;i<=6;i++) { Font_String[Turn_String][i] = m_7[i]; }  }
  if ( c == 'n') {  for(i=0;i<=6;i++) { Font_String[Turn_String][i] = n_7[i]; }  }
  if ( c == 'o') {  for(i=0;i<=6;i++) { Font_String[Turn_String][i] = o_7[i]; }  }
  if ( c == 'p') {  for(i=0;i<=6;i++) { Font_String[Turn_String][i] = p_7[i]; }  }
  if ( c == 'q') {  for(i=0;i<=6;i++) { Font_String[Turn_String][i] = q_7[i]; }  }
  if ( c == 'r') {  for(i=0;i<=6;i++) { Font_String[Turn_String][i] = r_7[i]; }  }
  if ( c == 's') {  for(i=0;i<=6;i++) { Font_String[Turn_String][i] = s_7[i]; }  }
  if ( c == 't') {  for(i=0;i<=6;i++) { Font_String[Turn_String][i] = t_7[i]; }  }
  if ( c == 'u') {  for(i=0;i<=6;i++) { Font_String[Turn_String][i] = u_7[i]; }  }
  if ( c == 'v') {  for(i=0;i<=6;i++) { Font_String[Turn_String][i] = v_7[i]; }  }
  if ( c == 'w') {  for(i=0;i<=6;i++) { Font_String[Turn_String][i] = w_7[i]; }  }
  if ( c == 'x') {  for(i=0;i<=6;i++) { Font_String[Turn_String][i] = x_7[i]; }  }
  if ( c == 'y') {  for(i=0;i<=6;i++) { Font_String[Turn_String][i] = y_7[i]; }  }
  if ( c == 'z') {  for(i=0;i<=6;i++) { Font_String[Turn_String][i] = z_7[i]; }  }
  
  
  if ( c != dummy_c)
  {
    if( c == '.' ) { if (Turn_String <= 39) { Turn_String++; } }
    if( c == '#' ) { Turn_String = 1; }
    if( c == ' ' ) {  for(i=0;i<=6;i++) { Font_String[Turn_String][i] = Blank_String; }  }
    if( c == '!' ) {  stat_c = 1; }
    if( c == '@' ) {  stat_c = 0; }
  }
  dummy_c = c;  
}


void setup()
{  
  mySerial.begin(115200);   // baud late setting 
  Serial.begin(9600); 
  pinMode(magnet,INPUT);
  pinMode(clk,OUTPUT);
  pinMode(latch,OUTPUT);
  pinMode(data,OUTPUT);  
    
  for(i=0;i<=6;i++)
  {
    Font_String[Turn_String][i] = Z_5[i];
  }
  
  for(i=0;i<=6;i++)
  {
    Font_String[3][i] = H_5[i];
  }
  
  for(i=0;i<=6;i++)
  {
    Font_String[4][i] = E_5[i];
  }
  
  for(i=0;i<=6;i++)
  {
    Font_String[5][i] = L_5[i];
  }
  
  for(i=0;i<=6;i++)
  {
    Font_String[6][i] = L_5[i];
  }
  for(i=0;i<=6;i++)
  {
    Font_String[7][i] = O_5[i];
  }
  
  for(i=0;i<=6;i++)
  {
    Font_String[9][i] = W_5[i];
  }
  for(i=0;i<=6;i++)
  {
    Font_String[10][i] = O_5[i];
  }
  for(i=0;i<=6;i++)
  {
    Font_String[11][i] = R_5[i];
  }
  for(i=0;i<=6;i++)
  {
    Font_String[12][i] = L_5[i];
  }
  for(i=0;i<=6;i++)
  {
    Font_String[13][i] = D_5[i];
  }

}


void loop()
{
 // serial printed by bluetooth

  if ( mySerial.available() )  
  {
    c = mySerial.read();
    mySerial.write(c);
    Serial.print(c);
  }
  
  // Read magnet hall sensor
  sbt = digitalRead(magnet);
  if(sbt != lbt)
  {
    if(sbt == LOW)
    {
      set_Font();
      
      if(ccct >= 16)
      {
        ccct = 0;
      }
      else
      {
        ccct++;
      }
      digitalWrite(latch,LOW);
      shiftOut(data,clk,MSBFIRST,Start_Line[ct]);
      digitalWrite(latch,HIGH);
      ct = 0;
      cct = 0;
      revo = 0;
      lbt = LOW;      
    }
    else
    {
      lbt = HIGH;
    }
  }
  
// Font counter and String Counter set
  if ( ct >= 7)  
  {
    ct = 0;
    if(cct >= 90) 
    {
      cct = 0; 
    } 
    else 
    { 
      cct++;
    }
  }  
  else 
  { 
    ct++;
  }
  revo++;

//---------------------------------------------------------------------------------------

  //display function action
  disp();
  
  //insert string
    
}
