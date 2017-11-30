int switchPin = 7; //定义数字口7为大按钮接口

void setup() {
  Serial.begin(9600); //设置波特率为9600
  pinMode(switchPin, INPUT);  //设置数字口7为输入模式
}

void loop() {
  if (LOW == digitalRead(switchPin)){
    Serial.print("$CLEAR\r\n");
    Serial.print("$GO 1 4\r\n");
    Serial.print("$PRINT Welcome to\r\n");
    Serial.print("$GO 2 0\r\n");
    Serial.print("$PRINT www.robotbase.cn\r\n");
    Serial.print("$CURSOR 1 1\r\n");
  }
}

