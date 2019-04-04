#include <Servo.h>

#define servomax 170
#define servomin 10

//  const int input1 = 2;   //unused
//  const int input2 = 4;   //unused
const int solenoidi = 9;    //pinninumerot
//const int servo = 10;
const int button1 = 16;
const int led1 = 14;
const int button2 = 15;
const int led2 = A0;

int i = 1;
int j = 1;
int s = 0;

Servo myservo;

void setup()
{
  pinMode(solenoidi, OUTPUT);     // inputit ja outputit
  myservo.attach(10);
  pinMode(button1, INPUT_PULLUP);
  pinMode(led1, OUTPUT);
  pinMode(button2, INPUT_PULLUP);
  pinMode(led2, OUTPUT);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  myservo.write(servomin);
}

void loop()
{
  i = digitalRead(button1);
  j = digitalRead(button2);
  if(i == 0)
  {
  i = 1;
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  myservo.write(servomax);
  delay(1500);
  myservo.write(servomin);
  delay(250);
  digitalWrite(solenoidi, HIGH);
  delay(2250);
  digitalWrite(solenoidi, LOW);
  delay(2250);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  }
    if(j == 0)
  {
  j = 1;
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  while(s<3)
  {
  s++;
  myservo.write(servomax);
  delay(1500);
  myservo.write(servomin);
  delay(250);
  digitalWrite(solenoidi, HIGH);
  delay(2250);
  digitalWrite(solenoidi, LOW);
  delay(2250);
  }
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  s = 0;
  }
}
