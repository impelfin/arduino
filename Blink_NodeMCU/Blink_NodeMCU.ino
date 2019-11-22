
#define LED1 2

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
  
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED1, HIGH);   
  digitalWrite(LED_BUILTIN, LOW);   
  delay(1000);                      
  digitalWrite(LED1, LOW);
  digitalWrite(LED_BUILTIN, HIGH);  
  delay(1000);                      
}
