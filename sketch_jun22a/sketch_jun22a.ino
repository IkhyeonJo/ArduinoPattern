/*
int latchPin = 3;
int clockPin = 4;
int dataPin = 2;
int z,temp,count,counter;
char received=0;
int i;
int wut=4;


void FloorControl(int z);

int num[10]={0x6996,0x6666,0xF696,0xF77F,0x2FAA,0xE1EF,0x69E8,0x119F,0x77EE,0x1796}; //0~9
void setup() {
  Serial.begin(9600);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  digitalWrite(5, HIGH); // 4
  digitalWrite(6, LOW); // 3
  digitalWrite(7, LOW); // 2
  digitalWrite(8, LOW); // 1
  digitalWrite(9, LOW); // 0
}

void loop() {
  
for(i=0; i<10; i++){ 
   for(z=0; z<5; z++){
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, (        (((num[i]&0x000F)>>z)&0x000F)  + (((num[i]&0x00F0)>>z)&0x00F0) + (((num[i]&0x0F00)>>z)&0x0F00)   +    (( (num[i]&0xF000)>>z)&0xF000)                       )>>8);
    shiftOut(dataPin, clockPin, MSBFIRST, (        (((num[i]&0x000F)>>z)&0x000F)  + (((num[i]&0x00F0)>>z)&0x00F0) + (((num[i]&0x0F00)>>z)&0x0F00)   +    (( (num[i]&0xF000)>>z)&0xF000)                       )); 
    FloorControl(4-z);
    digitalWrite(latchPin, HIGH);
    delay(1000);
   }
}

}

void FloorControl(int z){
  int temp, count;
  if(z>=0 && z<=4){
    temp=9-z;
    digitalWrite(temp, HIGH);
    for(count=0; count<4; count++){
      if(--temp==4)
      temp+=5;
      digitalWrite(temp, LOW);
    }
  }
}*/



int latchPin = 3;
int clockPin = 4;
int dataPin = 2;
int enable = 10;
int count;
int i, z;
int num[10]={0x6996,0x6666,0xF696,0xF77F,0x2FAA,0xE1EF,0x69E8,0x119F,0x77EE,0x1796}; //0~9


void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(enable, OUTPUT);
  digitalWrite(5, HIGH); // 4
  digitalWrite(6, LOW); // 3
  digitalWrite(7, LOW); // 2
  digitalWrite(8, LOW); // 1
  digitalWrite(9, LOW); // 0
  digitalWrite(enable, LOW); // enable
}

void loop() {
    FloorControl(0);
    for(count=0; count<1000; count++){
    digitalWrite(latchPin, LOW);
    digitalWrite(enable, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, 1>>8);
    shiftOut(dataPin, clockPin, MSBFIRST, 1);
    digitalWrite(latchPin, HIGH);
    delay(1);
    digitalWrite(enable, HIGH);
    }
    
    FloorControl(1);
    for(count=0; count<1000; count++){
    digitalWrite(latchPin, LOW);
    digitalWrite(enable, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, (1+2 + 16+32)>>8);
    shiftOut(dataPin, clockPin, MSBFIRST, (1+2 + 16+32)); 
    digitalWrite(latchPin, HIGH);
    delay(1);
    digitalWrite(enable, HIGH);
    }


    FloorControl(2);
    for(count=0; count<1000; count++){
    digitalWrite(latchPin, LOW);
    digitalWrite(enable, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, (1+2+4 + 16+32+64 + 256+512+1024)>>8);
    shiftOut(dataPin, clockPin, MSBFIRST, (1+2+4 + 16+32+64 + 256+512+1024)); 
    digitalWrite(latchPin, HIGH);
    delay(1);
    digitalWrite(enable, HIGH);
    }

  
    FloorControl(3);
    for(count=0; count<1000; count++){
    digitalWrite(latchPin, LOW);
    digitalWrite(enable, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, (1+2+4+8 + 16+32+64+128 + 256+512+1024+2048)>>8);
    shiftOut(dataPin, clockPin, MSBFIRST, (1+2+4+8 + 16+32+64+128 + 256+512+1024+2048)); 
    digitalWrite(latchPin, HIGH);
    delay(1);
    digitalWrite(enable, HIGH);
    }
    
    FloorControl(4);
    for(count=0; count<1000; count++){
    digitalWrite(latchPin, LOW);
    digitalWrite(enable, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, (1+2+4+8 + 16+32+64+128 + 256+512+1024+2048 + 256*16+512*16+1024*16+2048*16)>>8);
    shiftOut(dataPin, clockPin, MSBFIRST, (1+2+4+8 + 16+32+64+128 + 256+512+1024+2048 + 256*16+512*16+1024*16+2048*16)); 
    digitalWrite(latchPin, HIGH);
    delay(1);
    digitalWrite(enable, HIGH);
    }

    for(i=0; i<10; i++){ 
    digitalWrite(latchPin, LOW);
    digitalWrite(enable, LOW); // ?
    shiftOut(dataPin, clockPin, MSBFIRST, (        (((num[i]&0x000F)>>z)&0x000F)  + (((num[i]&0x00F0)>>z)&0x00F0) + (((num[i]&0x0F00)>>z)&0x0F00)   +    (( (num[i]&0xF000)>>z)&0xF000)                       )>>8);
    shiftOut(dataPin, clockPin, MSBFIRST, (        (((num[i]&0x000F)>>z)&0x000F)  + (((num[i]&0x00F0)>>z)&0x00F0) + (((num[i]&0x0F00)>>z)&0x0F00)   +    (( (num[i]&0xF000)>>z)&0xF000)                       )); 
    digitalWrite(latchPin, HIGH);
    delay(1000);
    digitalWrite(enable, HIGH); // ?
   }


}

void FloorControl(int z){
  int temp, count;
  if(z>=0 && z<=4){
    temp=9-z;
    digitalWrite(temp, HIGH);
    for(count=0; count<4; count++){
      if(--temp==4)
      temp+=5;
      digitalWrite(temp, LOW);
    }
  }
}
