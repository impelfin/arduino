#include <DS1302.h>
#include <Herkulex.h>
char* Read_Time;
int N0, N1, N3, N4, N6, N7;

DS1302 rtc(2, 3, 4);

void setup()
{
  rtc.halt(false);
  rtc.writeProtect(false);
  Serial.begin(115200);
  rtc.setDOW(THURSDAY);        // Set Day-of-Week to FRIDAY
  rtc.setTime(19, 34, 50);     // Set the time to 12:00:00 (24hr format)
  rtc.setDate(11, 22, 2019);   // Set the date to August 6th, 2010
  Herkulex.beginSerial1(115200);
  Herkulex.reboot(1);
  Herkulex.reboot(2);
  Herkulex.reboot(253);
  Herkulex.reboot(4);
  delay(500); 
  Herkulex.initialize();
  delay(200);
  pinMode(52, OUTPUT);
  pinMode(50, OUTPUT);
  pinMode(48, OUTPUT);
  pinMode(46, OUTPUT);
  pinMode(44, OUTPUT);
  pinMode(42, OUTPUT);
  pinMode(40, OUTPUT);
  pinMode(38, OUTPUT);
  pinMode(36, OUTPUT);
  pinMode(34, OUTPUT);
  pinMode(32, OUTPUT);
  pinMode(30, OUTPUT);
  pinMode(28, OUTPUT);
  pinMode(26, OUTPUT);
}

void loop()
{
  Read_Time = rtc.getTimeStr();
  N0 = (Read_Time[0]-48);
  N1 = (Read_Time[1]-48);
  N3 = (Read_Time[3]-48);
  N4 = (Read_Time[4]-48);
  N6 = (Read_Time[6]-48);
  N7 = (Read_Time[7]-48);
  Serial.print("and the time is: ");
  Serial.println(rtc.getTimeStr());
  if (N0 == 0 && N1 == 0) {
    Herkulex.moveOneAngle(1, -90, 1000, LED_GREEN);
    Herkulex.moveOneAngle(2, -90, 1000, LED_GREEN);
    if (N3 == 0 && N4 == 0) {
      Herkulex.moveOneAngle(253, -108, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if(N3>=0 && N3<6 && N4/5==1) {
      Herkulex.moveOneAngle(4, -90, 1000, LED_GREEN);
    }
    else if (N3 == 1 && N4 == 0) {
      Herkulex.moveOneAngle(253, -144, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_BLUE);
    }
    else if (N3 == 2 && N4 == 0) {
      Herkulex.moveOneAngle(253, -72, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_BLUE);
    }
    else if (N3 == 3 && N4 == 0) {
      Herkulex.moveOneAngle(253, 0, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if (N3 == 4 && N4 == 0) {
      Herkulex.moveOneAngle(253, 72, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if (N3 == 5 && N4 == 0) {
      Herkulex.moveOneAngle(253, 144, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
  }
  else if (N0 == 0 && N1 == 1) {
    Herkulex.moveOneAngle(1, -90, 1000, LED_GREEN);
    Herkulex.moveOneAngle(2, -135, 1000, LED_GREEN);
    if (N3 == 0 && N4 == 0) {
      Herkulex.moveOneAngle(253, -108, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if(N3>=0&&N3<6&&N4/5==1) {
      Herkulex.moveOneAngle(4, -90, 1000, LED_GREEN);
    }
    else if (N3 == 1 && N4 == 0) {
      Herkulex.moveOneAngle(253, -144, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_BLUE);
    }
    else if (N3 == 2 && N4 == 0) {
      Herkulex.moveOneAngle(253, -72, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_BLUE);
    }
    else if (N3 == 3 && N4 == 0) {
      Herkulex.moveOneAngle(253, 0, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if (N3 == 4 && N4 == 0) {
      Herkulex.moveOneAngle(253, 72, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if (N3 == 5 && N4 == 0) {
      Herkulex.moveOneAngle(253, 144, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
  }
  else if (N0 == 0 && N1 == 2) {
    Herkulex.moveOneAngle(1, -90, 1000, LED_GREEN);
    Herkulex.moveOneAngle(2, -45, 1000, LED_GREEN);
    if (N3 == 0 && N4 == 0) {
      Herkulex.moveOneAngle(253, -108, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if(N3>=0&&N3<6&&N4/5==1) {
      Herkulex.moveOneAngle(4, -90, 1000, LED_GREEN);
    }
    else if (N3 == 1 && N4 == 0) {
      Herkulex.moveOneAngle(253, -144, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_BLUE);
    }
    else if (N3 == 2 && N4 == 0) {
      Herkulex.moveOneAngle(253, -72, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_BLUE);
    }
    else if (N3 == 3 && N4 == 0) {
      Herkulex.moveOneAngle(253, 0, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if (N3 == 4 && N4 == 0) {
      Herkulex.moveOneAngle(253, 72, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if (N3 == 5 && N4 == 0) {
      Herkulex.moveOneAngle(253, 144, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
  }
  else if (N0 == 0 && N1 == 3) {
    Herkulex.moveOneAngle(1, -90, 1000, LED_GREEN);
    Herkulex.moveOneAngle(2, 45, 1000, LED_GREEN);
    if (N3 == 0 && N4 == 0) {
      Herkulex.moveOneAngle(253, -108, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if(N3>=0&&N3<6&&N4/5==1) {
      Herkulex.moveOneAngle(4, -90, 1000, LED_GREEN);
    }
    else if (N3 == 1 && N4 == 0) {
      Herkulex.moveOneAngle(253, -144, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_BLUE);
    }
    else if (N3 == 2 && N4 == 0) {
      Herkulex.moveOneAngle(253, -72, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_BLUE);
    }
    else if (N3 == 3 && N4 == 0) {
      Herkulex.moveOneAngle(253, 0, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if (N3 == 4 && N4 == 0) {
      Herkulex.moveOneAngle(253, 72, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if (N3 == 5 && N4 == 0) {
      Herkulex.moveOneAngle(253, 144, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
  }
  else if (N0 == 0 && N1 == 4) {
    Herkulex.moveOneAngle(1, -90, 1000, LED_GREEN);
    Herkulex.moveOneAngle(2, 135, 1000, LED_GREEN);
    if (N3 == 0 && N4 == 0) {
      Herkulex.moveOneAngle(253, -108, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if(N3>=0&&N3<6&&N4/5==1) {
      Herkulex.moveOneAngle(4, -90, 1000, LED_GREEN);
    }
    else if (N3 == 1 && N4 == 0) {
      Herkulex.moveOneAngle(253, -144, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_BLUE);
    }
    else if (N3 == 2 && N4 == 0) {
      Herkulex.moveOneAngle(253, -72, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_BLUE);
    }
    else if (N3 == 3 && N4 == 0) {
      Herkulex.moveOneAngle(253, 0, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if (N3 == 4 && N4 == 0) {
      Herkulex.moveOneAngle(253, 72, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if (N3 == 5 && N4 == 0) {
      Herkulex.moveOneAngle(253, 144, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
  }
  else if (N0 == 0 && N1 == 5) {
    Herkulex.moveOneAngle(1, -135, 1000, LED_GREEN);
    Herkulex.moveOneAngle(2, -90, 1000, LED_GREEN);
    if (N3 == 0 && N4 == 0) {
      Herkulex.moveOneAngle(253, -108, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if(N3>=0&&N3<6&&N4/5==1) {
      Herkulex.moveOneAngle(4, -90, 1000, LED_GREEN);
    }
    else if (N3 == 1 && N4 == 0) {
      Herkulex.moveOneAngle(253, -144, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_BLUE);
    }
    else if (N3 == 2 && N4 == 0) {
      Herkulex.moveOneAngle(253, -72, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_BLUE);
    }
    else if (N3 == 3 && N4 == 0) {
      Herkulex.moveOneAngle(253, 0, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if (N3 == 4 && N4 == 0) {
      Herkulex.moveOneAngle(253, 72, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if (N3 == 5 && N4 == 0) {
      Herkulex.moveOneAngle(253, 144, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
  }
  else if (N0 == 0 && N1 == 6) {
    Herkulex.moveOneAngle(1, -135, 1000, LED_GREEN);
    Herkulex.moveOneAngle(2, -135, 1000, LED_GREEN);
    if (N3 == 0 && N4 == 0) {
      Herkulex.moveOneAngle(253, -108, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if(N3>=0&&N3<6&&N4/5==1) {
      Herkulex.moveOneAngle(4, -90, 1000, LED_GREEN);
    }
    else if (N3 == 1 && N4 == 0) {
      Herkulex.moveOneAngle(253, -144, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_BLUE);
    }
    else if (N3 == 2 && N4 == 0) {
      Herkulex.moveOneAngle(253, -72, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_BLUE);
    }
    else if (N3 == 3 && N4 == 0) {
      Herkulex.moveOneAngle(253, 0, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if (N3 == 4 && N4 == 0) {
      Herkulex.moveOneAngle(253, 72, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if (N3 == 5 && N4 == 0) {
      Herkulex.moveOneAngle(253, 144, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
  }
  else if (N0 == 0 && N1 == 7) {
    Herkulex.moveOneAngle(1, -135, 1000, LED_GREEN);
    Herkulex.moveOneAngle(2, -45, 1000, LED_GREEN);
    if (N3 == 0 && N4 == 0) {
      Herkulex.moveOneAngle(253, -108, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if(N3>=0&&N3<6&&N4/5==1) {
      Herkulex.moveOneAngle(4, -90, 1000, LED_GREEN);
    }
    else if (N3 == 1 && N4 == 0) {
      Herkulex.moveOneAngle(253, -144, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_BLUE);
    }
    else if (N3 == 2 && N4 == 0) {
      Herkulex.moveOneAngle(253, -72, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_BLUE);
    }
    else if (N3 == 3 && N4 == 0) {
      Herkulex.moveOneAngle(253, 0, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if (N3 == 4 && N4 == 0) {
      Herkulex.moveOneAngle(253, 72, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if (N3 == 5 && N4 == 0) {
      Herkulex.moveOneAngle(253, 144, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
  }
  else if (N0 == 0 && N1 == 8) {
    Herkulex.moveOneAngle(1, -135, 1000, LED_GREEN);
    Herkulex.moveOneAngle(2, 45, 1000, LED_GREEN);
    if (N3 == 0 && N4 == 0) {
      Herkulex.moveOneAngle(253, -108, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if(N3>=0&&N3<6&&N4/5==1) {
      Herkulex.moveOneAngle(4, -90, 1000, LED_GREEN);
    }
    else if (N3 == 1 && N4 == 0) {
      Herkulex.moveOneAngle(253, -144, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_BLUE);
    }
    else if (N3 == 2 && N4 == 0) {
      Herkulex.moveOneAngle(253, -72, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_BLUE);
    }
    else if (N3 == 3 && N4 == 0) {
      Herkulex.moveOneAngle(253, 0, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if (N3 == 4 && N4 == 0) {
      Herkulex.moveOneAngle(253, 72, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if (N3 == 5 && N4 == 0) {
      Herkulex.moveOneAngle(253, 144, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
  }
  else if (N0 == 0 && N1 == 9) {
    Herkulex.moveOneAngle(1, -135, 1000, LED_GREEN);
    Herkulex.moveOneAngle(2, 135, 1000, LED_GREEN);
    if (N3 == 0 && N4 == 0) {
      Herkulex.moveOneAngle(3, -108, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if(N3>=0&&N3<6&&N4/5==1) {
      Herkulex.moveOneAngle(4, -90, 1000, LED_GREEN);
    }
    else if (N3 == 1 && N4 == 0) {
      Herkulex.moveOneAngle(3, -144, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_BLUE);
    }
    else if (N3 == 2 && N4 == 0) {
      Herkulex.moveOneAngle(3, -72, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_BLUE);
    }
    else if (N3 == 3 && N4 == 0) {
      Herkulex.moveOneAngle(3, 0, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if (N3 == 4 && N4 == 0) {
      Herkulex.moveOneAngle(3, 72, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if (N3 == 5 && N4 == 0) {
      Herkulex.moveOneAngle(3, 144, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
  }
  else if (N0 == 1 && N1 == 0) {
    Herkulex.moveOneAngle(1, -45, 1000, LED_GREEN);
    Herkulex.moveOneAngle(2, -90, 1000, LED_GREEN);
    if (N3 == 0 && N4 == 0) {
      Herkulex.moveOneAngle(253, -108, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if(N3>=0&&N3<6&&N4/5==1) {
      Herkulex.moveOneAngle(4, -90, 1000, LED_GREEN);
    }
    else if (N3 == 1 && N4 == 0) {
      Herkulex.moveOneAngle(253, -144, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_BLUE);
    }
    else if (N3 == 2 && N4 == 0) {
      Herkulex.moveOneAngle(253, -72, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_BLUE);
    }
    else if (N3 == 3 && N4 == 0) {
      Herkulex.moveOneAngle(253, 0, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if (N3 == 4 && N4 == 0) {
      Herkulex.moveOneAngle(253, 72, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if (N3 == 5 && N4 == 0) {
      Herkulex.moveOneAngle(253, 144, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
  }
  else if (N0 == 1 && N1 == 1) {
    Herkulex.moveOneAngle(1, -45, 1000, LED_GREEN);
    Herkulex.moveOneAngle(2, -135, 1000, LED_GREEN);
    if (N3 == 0 && N4 == 0) {
      Herkulex.moveOneAngle(253, -108, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if(N3>=0&&N3<6&&N4/5==1) {
      Herkulex.moveOneAngle(4, -90, 1000, LED_GREEN);
    }
    else if (N3 == 1 && N4 == 0) {
      Herkulex.moveOneAngle(253, -144, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_BLUE);
    }
    else if (N3 == 2 && N4 == 0) {
      Herkulex.moveOneAngle(253, -72, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_BLUE);
    }
    else if (N3 == 3 && N4 == 0) {
      Herkulex.moveOneAngle(253, 0, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if (N3 == 4 && N4 == 0) {
      Herkulex.moveOneAngle(253, 72, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if (N3 == 5 && N4 == 0) {
      Herkulex.moveOneAngle(253, 144, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
  }
  else if (N0 == 1 && N1 == 2) {
    Herkulex.moveOneAngle(1, -45, 1000, LED_GREEN);
    Herkulex.moveOneAngle(2, -45, 1000, LED_GREEN);
    if (N3 == 0 && N4 == 0) {
      Herkulex.moveOneAngle(253, -108, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if(N3>=0&&N3<6&&N4/5==1) {
      Herkulex.moveOneAngle(4, -90, 1000, LED_GREEN);
    }
    else if (N3 == 1 && N4 == 0) {
      Herkulex.moveOneAngle(253, -144, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_BLUE);
    }
    else if (N3 == 2 && N4 == 0) {
      Herkulex.moveOneAngle(253, -72, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_BLUE);
    }
    else if (N3 == 3 && N4 == 0) {
      Herkulex.moveOneAngle(253, 0, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if (N3 == 4 && N4 == 0) {
      Herkulex.moveOneAngle(253, 72, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if (N3 == 5 && N4 == 0) {
      Herkulex.moveOneAngle(253, 144, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
  }
  else if (N0 == 1 && N1 == 3) {
    Herkulex.moveOneAngle(1, -45, 1000, LED_GREEN);
    Herkulex.moveOneAngle(2, 45, 1000, LED_GREEN);
    if (N3 == 0 && N4 == 0) {
      Herkulex.moveOneAngle(253, -108, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if(N3>=0&&N3<6&&N4/5==1) {
      Herkulex.moveOneAngle(4, -90, 1000, LED_GREEN);
    }
    else if (N3 == 1 && N4 == 0) {
      Herkulex.moveOneAngle(253, -144, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_BLUE);
    }
    else if (N3 == 2 && N4 == 0) {
      Herkulex.moveOneAngle(253, -72, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_BLUE);
    }
    else if (N3 == 3 && N4 == 0) {
      Herkulex.moveOneAngle(253, 0, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if (N3 == 4 && N4 == 0) {
      Herkulex.moveOneAngle(253, 72, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if (N3 == 5 && N4 == 0) {
      Herkulex.moveOneAngle(253, 144, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
  }
  else if (N0 == 1 && N1 == 4) {
    Herkulex.moveOneAngle(1, -45, 1000, LED_GREEN);
    Herkulex.moveOneAngle(2, 135, 1000, LED_GREEN);
    if (N3 == 0 && N4 == 0) {
      Herkulex.moveOneAngle(253, -108, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if(N3>=0&&N3<6&&N4/5==1) {
      Herkulex.moveOneAngle(4, -90, 1000, LED_GREEN);
    }
    else if (N3 == 1 && N4 == 0) {
      Herkulex.moveOneAngle(253, -144, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_BLUE);
    }
    else if (N3 == 2 && N4 == 0) {
      Herkulex.moveOneAngle(253, -72, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_BLUE);
    }
    else if (N3 == 3 && N4 == 0) {
      Herkulex.moveOneAngle(253, 0, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if (N3 == 4 && N4 == 0) {
      Herkulex.moveOneAngle(253, 72, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if (N3 == 5 && N4 == 0) {
      Herkulex.moveOneAngle(253, 144, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
  }
  else if (N0 == 1 && N1 == 5) {
    Herkulex.moveOneAngle(1, 45, 1000, LED_GREEN);
    Herkulex.moveOneAngle(2, -90, 1000, LED_GREEN);
    if (N3 == 0 && N4 == 0) {
      Herkulex.moveOneAngle(253, -108, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if(N3>=0&&N3<6&&N4/5==1) {
      Herkulex.moveOneAngle(4, -90, 1000, LED_GREEN);
    }
    else if (N3 == 1 && N4 == 0) {
      Herkulex.moveOneAngle(253, -144, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_BLUE);
    }
    else if (N3 == 2 && N4 == 0) {
      Herkulex.moveOneAngle(253, -72, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_BLUE);
    }
    else if (N3 == 3 && N4 == 0) {
      Herkulex.moveOneAngle(253, 0, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if (N3 == 4 && N4 == 0) {
      Herkulex.moveOneAngle(253, 72, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if (N3 == 5 && N4 == 0) {
      Herkulex.moveOneAngle(253, 144, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
  }
  else if (N0 == 1 && N1 == 6) {
    Herkulex.moveOneAngle(1, 45, 1000, LED_GREEN);
    Herkulex.moveOneAngle(2, -135, 1000, LED_GREEN);
    if (N3 == 0 && N4 == 0) {
      Herkulex.moveOneAngle(253, -108, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if(N3>=0&&N3<6&&N4/5==1) {
      Herkulex.moveOneAngle(4, -90, 1000, LED_GREEN);
    }
    else if (N3 == 1 && N4 == 0) {
      Herkulex.moveOneAngle(253, -144, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_BLUE);
    }
    else if (N3 == 2 && N4 == 0) {
      Herkulex.moveOneAngle(253, -72, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_BLUE);
    }
    else if (N3 == 3 && N4 == 0) {
      Herkulex.moveOneAngle(253, 0, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if (N3 == 4 && N4 == 0) {
      Herkulex.moveOneAngle(253, 72, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if (N3 == 5 && N4 == 0) {
      Herkulex.moveOneAngle(253, 144, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
  }
  else if (N0 == 1 && N1 == 7) {
    Herkulex.moveOneAngle(1, 45, 1000, LED_GREEN);
    Herkulex.moveOneAngle(2, -45, 1000, LED_GREEN);
    if (N3 == 0 && N4 == 0) {
      Herkulex.moveOneAngle(253, -108, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if(N3>=0&&N3<6&&N4/5==1) {
      Herkulex.moveOneAngle(4, -90, 1000, LED_GREEN);
    }
    else if (N3 == 1 && N4 == 0) {
      Herkulex.moveOneAngle(253, -144, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_BLUE);
    }
    else if (N3 == 2 && N4 == 0) {
      Herkulex.moveOneAngle(253, -72, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_BLUE);
    }
    else if (N3 == 3 && N4 == 0) {
      Herkulex.moveOneAngle(253, 0, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if (N3 == 4 && N4 == 0) {
      Herkulex.moveOneAngle(253, 72, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if (N3 == 5 && N4 == 0) {
      Herkulex.moveOneAngle(253, 144, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
  }
  else if (N0 == 1 && N1 == 8) {
    Herkulex.moveOneAngle(1, 45, 1000, LED_GREEN);
    Herkulex.moveOneAngle(2, 45, 1000, LED_GREEN);
    if (N3 == 0 && N4 == 0) {
      Herkulex.moveOneAngle(253, -108, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if(N3>=0&&N3<6&&N4/5==1) {
      Herkulex.moveOneAngle(4, -90, 1000, LED_GREEN);
    }
    else if (N3 == 1 && N4 == 0) {
      Herkulex.moveOneAngle(253, -144, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_BLUE);
    }
    else if (N3 == 2 && N4 == 0) {
      Herkulex.moveOneAngle(253, -72, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_BLUE);
    }
    else if (N3 == 3 && N4 == 0) {
      Herkulex.moveOneAngle(253, 0, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if (N3 == 4 && N4 == 0) {
      Herkulex.moveOneAngle(253, 72, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if (N3 == 5 && N4 == 0) {
      Herkulex.moveOneAngle(253, 144, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
  }
  else if (N0 == 1 && N1 == 9) {
    Herkulex.moveOneAngle(1, 45, 1000, LED_GREEN);
    Herkulex.moveOneAngle(2, 135, 1000, LED_GREEN);
    if (N3 == 0 && N4 == 0) {
      Herkulex.moveOneAngle(253, -108, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if(N4/5==1) {
      Herkulex.moveOneAngle(4, -90, 1000, LED_GREEN);
    }
    else if (N3 == 1 && N4 == 0) {
      Herkulex.moveOneAngle(253, -144, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_BLUE);
    }
    else if (N3 == 2 && N4 == 0) {
      Herkulex.moveOneAngle(253, -72, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_BLUE);
    }
    else if (N3 == 3 && N4 == 0) {
      Herkulex.moveOneAngle(253, 0, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if (N3 == 4 && N4 == 0) {
      Herkulex.moveOneAngle(253, 72, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if (N3 == 5 && N4 == 0) {
      Herkulex.moveOneAngle(253, 144, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
  }
  else if (N0 == 2 && N1 == 0) {
    Herkulex.moveOneAngle(1, 135, 1000, LED_GREEN);
    Herkulex.moveOneAngle(2, -90, 1000, LED_GREEN);
    if (N3 == 0 && N4 == 0) {
      Herkulex.moveOneAngle(253, -108, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if(N3>=0&&N3<6&&N4/5==1) {
      Herkulex.moveOneAngle(4, -90, 1000, LED_GREEN);
    }
    else if (N3 == 1 && N4 == 0) {
      Herkulex.moveOneAngle(253, -144, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_BLUE);
    }
    else if (N3 == 2 && N4 == 0) {
      Herkulex.moveOneAngle(253, -72, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_BLUE);
    }
    else if (N3 == 3 && N4 == 0) {
      Herkulex.moveOneAngle(253, 0, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if (N3 == 4 && N4 == 0) {
      Herkulex.moveOneAngle(253, 72, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if (N3 == 5 && N4 == 0) {
      Herkulex.moveOneAngle(253, 144, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
  }
  else if (N0 == 2 && N1 == 1) {
    Herkulex.moveOneAngle(1, 135, 1000, LED_GREEN);
    Herkulex.moveOneAngle(2, -135, 1000, LED_GREEN);
    if (N3 == 0 && N4 == 0) {
      Herkulex.moveOneAngle(253, -108, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if(N3>=0&&N3<6&&N4/5==1) {
      Herkulex.moveOneAngle(4, -90, 1000, LED_GREEN);
    }
    else if (N3 == 1 && N4 == 0) {
      Herkulex.moveOneAngle(253, -144, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_BLUE);
    }
    else if (N3 == 2 && N4 == 0) {
      Herkulex.moveOneAngle(253, -72, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_BLUE);
    }
    else if (N3 == 3 && N4 == 0) {
      Herkulex.moveOneAngle(253, 0, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if (N3 == 4 && N4 == 0) {
      Herkulex.moveOneAngle(253, 72, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if (N3 == 5 && N4 == 0) {
      Herkulex.moveOneAngle(253, 144, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
  }
  else if (N0 == 2 && N1 == 2) {
    Herkulex.moveOneAngle(1, 135, 1000, LED_GREEN);
    Herkulex.moveOneAngle(2, -45, 1000, LED_GREEN);
    if (N3 == 0 && N4 == 0) {
      Herkulex.moveOneAngle(253, -108, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if(N3>=0&&N3<6&&N4/5==1) {
      Herkulex.moveOneAngle(4, -90, 1000, LED_GREEN);
    }
    else if (N3 == 1 && N4 == 0) {
      Herkulex.moveOneAngle(253, -144, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_BLUE);
    }
    else if (N3 == 2 && N4 == 0) {
      Herkulex.moveOneAngle(253, -72, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_BLUE);
    }
    else if (N3 == 3 && N4 == 0) {
      Herkulex.moveOneAngle(253, 0, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if (N3 == 4 && N4 == 0) {
      Herkulex.moveOneAngle(253, 72, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if (N3 == 5 && N4 == 0) {
      Herkulex.moveOneAngle(253, 144, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
  }
  else if (N0 == 2 && N1 == 3) {
    Herkulex.moveOneAngle(1, 135, 1000, LED_GREEN);
    Herkulex.moveOneAngle(2, 45, 1000, LED_GREEN);
    if (N3 == 0 && N4 == 0) {
      Herkulex.moveOneAngle(253, -108, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if(N3>=0&&N3<6&&N4/5==1) {
      Herkulex.moveOneAngle(4, -90, 1000, LED_GREEN);
    }
    else if (N3 == 1 && N4 == 0) {
      Herkulex.moveOneAngle(253, -144, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_BLUE);
    }
    else if (N3 == 2 && N4 == 0) {
      Herkulex.moveOneAngle(253, -72, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_BLUE);
    }
    else if (N3 == 3 && N4 == 0) {
      Herkulex.moveOneAngle(253, 0, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if (N3 == 4 && N4 == 0) {
      Herkulex.moveOneAngle(253, 72, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if (N3 == 5 && N4 == 0) {
      Herkulex.moveOneAngle(253, 144, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
  }
  else if (N0 == 2 && N1 == 4) {
    Herkulex.moveOneAngle(1, 135, 1000, LED_GREEN);
    Herkulex.moveOneAngle(2, 135, 1000, LED_GREEN);
    if (N3 == 0 && N4 == 0) {
      Herkulex.moveOneAngle(253, -108, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if(N3>=0&&N3<6&&N4/5==1) {
      Herkulex.moveOneAngle(4, -90, 1000, LED_GREEN);
    }
    else if (N3 == 1 && N4 == 0) {
      Herkulex.moveOneAngle(253, -144, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_BLUE);
    }
    else if (N3 == 2 && N4 == 0) {
      Herkulex.moveOneAngle(253, -72, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_BLUE);
    }
    else if (N3 == 3 && N4 == 0) {
      Herkulex.moveOneAngle(253, 0, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if (N3 == 4 && N4 == 0) {
      Herkulex.moveOneAngle(253, 72, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
    else if (N3 == 5 && N4 == 0) {
      Herkulex.moveOneAngle(253, 144, 1000, LED_BLUE);
      Herkulex.moveOneAngle(4, 90, 1000, LED_GREEN);
    }
  }
  delay (10000);
}
