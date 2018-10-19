
#include <IRremote.h>

IRsend irsend;

#define a 4
#define b 5
#define c 6
#define d 7

void setup() {
  Serial.begin(9600);
  pinMode(a, INPUT);
  pinMode(b, INPUT);
  pinMode(c, INPUT);
  pinMode(d, INPUT);
}

void loop() {
  if (digitalRead(a) == HIGH) {
    irsend.sendNEC(0x57E3E817, 32); //Power Code
    Serial.println("TV");
    delay(500);
  }
  if (digitalRead(b) == HIGH) {
    irsend.sendNEC(0x57E354AB, 32); //Enter Key
    delay(2000);
    irsend.sendNEC(0x57E39867, 32); //Up Key
    delay(1000);
    irsend.sendNEC(0x57E39867, 32); //Up Key
    delay(1000);
    irsend.sendNEC(0x57E39867, 32); //Up Key
    delay(1000);
    irsend.sendNEC(0x57E3B44B, 32); //Right Key
    delay(1000);
    irsend.sendNEC(0x57E354AB, 32); //Enter
    delay(2000);
    irsend.sendNEC(0x57E354AB, 32); //Enter 
    Serial.println("The Office");
    delay(500);
  }
  if (digitalRead(c) == HIGH) {
    irsend.sendNEC(0x57E38679, 32); //Options Button
    delay(1500);
    irsend.sendNEC(0x57E3CC33, 32); //Down key
    delay(700);
    irsend.sendNEC(0x57E3CC33, 32); //Down key
    delay(700);
    irsend.sendNEC(0x57E3CC33, 32); //Down key
    delay(700);
    irsend.sendNEC(0x57E3CC33, 32); //Down key
    delay(700);
    irsend.sendNEC(0x57E3B44B, 32); //Right Key
    delay(700);
    irsend.sendNEC(0x57E3B44B, 32); //Right Key
    delay(900);
    irsend.sendNEC(0x57E38679, 32); //Options Button    
    Serial.println("Sleep Timer");
    delay(500);
  }
  if (digitalRead(d) == HIGH) {
    irsend.sendNEC(0x57E34AB5, 32); //Netflix Code
    Serial.println("Greg's Netflix");
    delay(500);
  }
}

