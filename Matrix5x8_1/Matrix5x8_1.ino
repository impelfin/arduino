#include <font.h>
#include <string.h>

#define ROW_0   7
#define ROW_1   8
#define ROW_2   9
#define ROW_3   10
#define ROW_4   11
#define ROW_5   12
#define ROW_6   13
#define ROW_7   0

#define COL_0   2
#define COL_1   3
#define COL_2   4
#define COL_3   5
#define COL_4   6

#define ROWS    8
#define COLS    5

/*
 * 1 sec
 */
#define MAX_REPEAT  90

int rowPort[] = {ROW_0, ROW_1, ROW_2, ROW_3, ROW_4, ROW_5, ROW_6, ROW_7};
int colPort[] = {COL_0, COL_1, COL_2, COL_3, COL_4};

char message [] = "Arduino AVR Programming...";

int msgPos, msgLength;

void setup()
{            
  int col, row;
      
  for(col = 0; col < COLS; col++)
  {
      pinMode(colPort[col], OUTPUT);
  }
  
  for(row = 0; row < ROWS; row++)
  {
      pinMode(rowPort[row], OUTPUT);
  }
  
  msgPos = -1;
  msgLength = strlen(message);
}

void loop()
{
  int col, row, rcnt = 0;
  char *pData;
  char *pTmp;
  
  msgPos++;
  
  if ( msgPos >= msgLength )
    msgPos = 0;
  
  pData = METRIX_FONT[FONT_INDEX[message[msgPos]]];
   
  while(rcnt < MAX_REPEAT)
  {
      rcnt++;
      
      pTmp = pData;
      
      /* 5개 COLUMN 출력 */
      for(col = 0; col < COLS; col++)
      {
          /* 8개 ROW 출력 */
          for(row = 0; row < ROWS; row++)
          {
              /* 한 바이트의 각 비트값을 지정된 포트로 출력한다. */
              digitalWrite(rowPort[row], (*pTmp & (1<<(ROWS-row-1))) == (1<<(ROWS-row-1)) ? 1 : 0);
          }
  
          pTmp++;
          
          /* 이전 COLUMN OFF */
          digitalWrite(colPort[col-1 < 0 ? COLS-1 : col-1], 1);
              
          /* 현재 COLUMN ON */
          digitalWrite(colPort[col], 0);
      
          delayMicroseconds(2000);
      }
  }
}
