int latchPin=3;
int clockPin=4;
int dataPin=2;
int enable=10;

void setup() {
pinMode(latchPin, OUTPUT);
pinMode(clockPin, OUTPUT);
pinMode(dataPin, OUTPUT);
pinMode(enable, OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
digitalWrite(5, HIGH);
digitalWrite(6, HIGH);
digitalWrite(7, HIGH);
digitalWrite(8, HIGH);
digitalWrite(9, HIGH);
digitalWrite(10,LOW);
}

void loop() {
digitalWrite(latchPin, LOW);
shiftOut(dataPin, clockPin, MSBFIRST, 255);
shiftOut(dataPin, clockPin, MSBFIRST, 255);
digitalWrite(latchPin, HIGH);
}


