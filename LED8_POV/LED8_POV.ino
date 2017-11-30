/*
 * 목  적 : POV (Persistence Of Vision)
 *
 */
#include <font.h>
#include <string.h>
#define ROW_0   12
#define ROW_1   13
#define ROW_2   6
#define ROW_3   7
#define ROW_4   5
#define ROW_5   4
#define ROW_6   3
#define ROW_7   2
#define ROWS    8
#define COLS    5
int rowPort[] = {ROW_0, ROW_1, ROW_2, ROW_3, ROW_4, ROW_5, ROW_6, ROW_7};
char message [] = "CHOI ES";
int msgLength;
int dataPos;
void setup()
{            
  for(int row = 0; row < ROWS; row++)
  {
      pinMode(rowPort[row], OUTPUT);
   // LED 끄기
      digitalWrite(rowPort[row], 1); // + Common LED를 사용하여서 1이 OFF, - Common LED는 0이 OFF
  }
  
  // 출력 메시지의 길이
  msgLength = strlen(message);
  dataPos = -1;
}
void loop()
{
  int col, row;
  // 출력 문자의 위치를 결정
  dataPos++;
  if ( dataPos >= msgLength )
    dataPos = 0;
  char * pTmp = METRIX_FONT[FONT_INDEX[message[dataPos]]];
  
  /* 5개 COLUMN 출력 */
  for(col = 0; col < COLS; col++)
  {
      /* 8개 ROW 출력 */
      for(row = 0; row < ROWS; row++)
      {
          /* 한 바이트의 각 비트값을 지정된 포트로 출력한다. */
          digitalWrite(rowPort[row], bitRead(*pTmp, (ROWS-row-1)) == 1 ? 0 : 1);  // + Common LED를 사용하여서 1이 OFF, - Common LED는 0이 OFF
      }
      
      pTmp++;
   // 손으로 흔들어서 출력하려고 길게 줌
   // 모터로 회전하는 경우에는 짧게 조정 필요
      delayMicroseconds(3000);
  }
  
  // SPACE COLUMN
  for(row = 0; row < ROWS; row++)
  {
    digitalWrite(rowPort[row], 1);
  }
  delayMicroseconds(3000);
}
