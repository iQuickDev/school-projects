// 1)
int Byte = 0;
void setup() {
 Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    incomingByte = Serial.read();
    Serial.print("Numero ricevuto: ");
    Serial.println(Byte, DEC);
  }
}

// 2)
int btn = 7, btnState= LOW, count = 0;

void setup(){
pinMode(btn, INPUT);
 Serial.begin(9600);
}

void loop(){
 int readValue = digitalRead(btn);
 if(readValue != btnState and readValue == HIGH)
 {
   count++;
   Serial.println("CONTEGGIO: ");
   Serial.println(count);
 }
 btnState=readValue;
}
