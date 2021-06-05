#include <Servo.h>
Servo s;
int p=0;
float duration;
float distance;
void setup() {
Serial.begin(9600);
s.attach(6);
pinMode(3, OUTPUT);
pinMode(2, INPUT);
pinMode(11,OUTPUT);
s.write(120);
}

void loop() {
  if(Serial.available()>0)
  {
    char data=Serial.read();
    switch(data)
    {
      case 'a': s.write(120);p=0;break;
      case 'd': s.write(30);p=1;break;
      default:break;
    }
    Serial.println(data);
  }
  digitalWrite(3, LOW);
  delayMicroseconds(2);
  digitalWrite(3, HIGH);
  delayMicroseconds(10);
  digitalWrite(3, LOW);
  duration = pulseIn(2, HIGH);
  distance = duration * 0.034 / 2;
  if(distance>50 && p==1)
  {
    tone(11,1);
    delay(500);
    noTone(11);
    delay(2000);
  }
  // put your main code here, to run repeatedly:
  delay(50);
}
