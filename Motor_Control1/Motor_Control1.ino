int in1 = 5;
int in2 = 6;
int in3 = 9;
int in4 = 10;

void setup() {

  Serial.begin(9600);

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop() {
    byte data;
    data = Serial.read();
    if(data=='R'){     // R
      analogWrite(in1, 200); 
      analogWrite(in2, 0);
    }
    if(data=='L'){     // L
      analogWrite(in1, 0); 
      analogWrite(in2, 200);
    }
    if(data=='F'){     // F
      analogWrite(in3, 200); 
      analogWrite(in4, 0);
    }
    if(data=='B'){     // B
      analogWrite(in3, 0); 
      analogWrite(in4, 100);
    }
    if(data=='S'){    //  S
      analogWrite(in1, 0); 
      analogWrite(in2, 0);
      analogWrite(in3, 0); 
      analogWrite(in4, 0);      
    }
    if(data=='I'){    //  F,R
      analogWrite(in1, 200); 
      analogWrite(in2, 0);
      analogWrite(in3, 200); 
      analogWrite(in4, 0);      
    }
    if(data=='G'){    //  F,L
      analogWrite(in1, 0); 
      analogWrite(in2, 200);
      analogWrite(in3, 200); 
      analogWrite(in4, 0);      
    }
    if(data=='H'){    //  B,R
      analogWrite(in1, 0); 
      analogWrite(in2, 200);
      analogWrite(in3, 0); 
      analogWrite(in4, 100);      
    }
    if(data=='J'){    //  B,L
      analogWrite(in1, 200); 
      analogWrite(in2, 0);
      analogWrite(in3, 0); 
      analogWrite(in4, 100);      
    }    
}



