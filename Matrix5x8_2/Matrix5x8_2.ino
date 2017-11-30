#include <font.h>
#include <string.h>
#include <alloca.h> 

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
#define MAX_REPEAT  12

int rowPort[] = {ROW_0, ROW_1, ROW_2, ROW_3, ROW_4, ROW_5, ROW_6, ROW_7};
int colPort[] = {COL_0, COL_1, COL_2, COL_3, COL_4};

char message [] = "Arduino AVR Programming...";

int totalCount;
int dataPos;

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

  totalCount = strlen(message) * COLS;
  
  dataPos = 0;
}

void loop()
{
  int col, row, rcnt = 0;
  char data[COLS];
  int index = 0;
  int pos = dataPos / COLS;
  int off = dataPos % COLS;
  char * tmp = METRIX_FONT[FONT_INDEX[message[pos]]];
    
  for(col = off; col < COLS; col++)
  {
    data[index++] = tmp[col];
  }
  
  if ( index < COLS )
  {
    tmp = METRIX_FONT[FONT_INDEX[message[pos+1]]];
    int n = (COLS-index);
    
    for(col = 0; col < n; col++)
    {
      data[index++] = tmp[col];
    }
  }
  
  while(rcnt < MAX_REPEAT)
  {
      rcnt++;
      
      char * pTmp = data;
      
      /* 5개 COLUMN 출력 */
      for(col = 0; col < COLS; col++)
      {
          /* 8개 ROW 출력 */
          for(row = 0; row < ROWS; row++)
          {
              /* 한 바이트의 각 비트값을 지정된 포트로 출력한다. */
//              digitalWrite(rowPort[row], (*pTmp & (1<<(ROWS-row-1))) == (1<<(ROWS-row-1)) ? 1 : 0);
              digitalWrite(rowPort[row], bitRead(*pTmp, (ROWS-row-1)));
          }
          
          pTmp++;
          
          /* 이전 COLUMN OFF */
          //digitalWrite(colPort[col-1 < 0 ? COLS-1 : col-1], 1);
              
          /* 현재 COLUMN ON */
          digitalWrite(colPort[col], 0);
      
          delayMicroseconds(4000);
          
          digitalWrite(colPort[col], 1);
      }
  }
  
  dataPos++;
  
  if ( dataPos >= totalCount - COLS )
    dataPos = 0;
}

