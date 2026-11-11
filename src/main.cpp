#include <Arduino.h>

#define LED1 2
#define LED2 3
#define LED3 4
#define LED4 5
#define LED5 6
#define LED6 7
#define LED7 8
#define LED8 9
#define LED9 10
#define LED10 11
#define LED11 12
#define LED12 13
#define LED13 A0

const int AllPin[] = {LED1,LED2,LED3,LED4,LED5,LED6,LED7,LED8,LED9,LED10,LED11,LED12,LED13};
const int TotalPins = sizeof(AllPin) / sizeof(AllPin[0]);


//alternating
const int Set1[] = {LED1,LED3,LED5,LED7,LED9,LED11,LED13};
const int Set1_Pins = sizeof(Set1) / sizeof(Set1[0]);
const int Set2[] = {LED2,LED4,LED6,LED8,LED10,LED12};
const int Set2_Pins = sizeof(Set2) / sizeof(Set2[0]);

//delays vars
const int Alt1_Delay = 500;
const int Meeting_Delay = 500;
const int flowing_delay = 500;
void all_off() {
  for (int i = 0; i < TotalPins; i++)
  {
    digitalWrite(AllPin[i], LOW);
  }
}

void all_on() {
  for (int i = 0; i < TotalPins; i++)
  {
    digitalWrite(AllPin[i], HIGH);
  }
}

void flowing() {
  for (int i = 0; i < TotalPins; i++)
  {
    digitalWrite(AllPin[i], HIGH);
    delay(flowing_delay);
    digitalWrite(AllPin[i], LOW);
  }
  
}

void alternating() {
  for (int i = 0; i < Set1_Pins; i++)
  {
    digitalWrite(Set1[i], HIGH);
  }
  delay(Alt1_Delay);
  all_off();
  for (int i = 0; i < Set2_Pins; i++)
  {
    digitalWrite(Set2[i], HIGH);
  }
  delay(Alt1_Delay);
  all_off();
}

void meeting_2() {
  digitalWrite(LED1, HIGH);
  digitalWrite(LED13, HIGH);
  delay(Meeting_Delay);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED12, HIGH);
  delay(Meeting_Delay);
  digitalWrite(LED3, HIGH);
  digitalWrite(LED11, HIGH);
  delay(Meeting_Delay);
  digitalWrite(LED4, HIGH);
  digitalWrite(LED10, HIGH);
  delay(Meeting_Delay);
  digitalWrite(LED5, HIGH);
  digitalWrite(LED9, HIGH);
  delay(Meeting_Delay);
  digitalWrite(LED6, HIGH);
  digitalWrite(LED8, HIGH);
  delay(Meeting_Delay);
  digitalWrite(LED7, HIGH);
  delay(Meeting_Delay);
  all_off();
}

void setup() {
  //Serial.begin(9600);
  
  for (int i = 0; i < TotalPins; i++)
  {
    pinMode(AllPin[i], OUTPUT);
  }
  all_off();
}

void loop() {
  for (int i = 0; i < 10; i++)
  {
    alternating();
  }
  flowing();
}