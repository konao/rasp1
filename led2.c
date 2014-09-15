/*
 * [how to compile and run]
 *
 * $ cc -o led2 led2.c -lwiringPi
 * $ sudo ./led2
 */
#include <wiringPi.h>

#define LED_IN_A 2
#define LED_IN_B 3
#define LED_IN_C 4

#define LED_OUT_1 22
#define LED_OUT_2 23

#define DELAY_TIME 300
void select(int x) {
  int a = x & 1;
  int b = x & 2;
  int c = x & 4;
  digitalWrite(LED_IN_A, a);
  digitalWrite(LED_IN_B, b);
  digitalWrite(LED_IN_C, c);
}

int main(int argc, char *argv[]) {
  int i;

  if (wiringPiSetupGpio() == -1) return 1;

  pinMode(LED_IN_A, OUTPUT);
  pinMode(LED_IN_B, OUTPUT);
  pinMode(LED_IN_C, OUTPUT);
  pinMode(LED_OUT_1, OUTPUT);
  pinMode(LED_OUT_2, OUTPUT);

  for (i=0; i<10; i++) {
    digitalWrite(LED_OUT_1, 0);
    digitalWrite(LED_OUT_2, 1);

    // turn on 1st LED
    select(0);
    delay(DELAY_TIME);

    // turn on 2nd LED
    select(1);
    delay(DELAY_TIME);

    // turn on 3rd LED
    select(2);
    delay(DELAY_TIME);

    // turn on 4th LED
    select(3);
    delay(DELAY_TIME);

    digitalWrite(LED_OUT_1, 0);
    digitalWrite(LED_OUT_2, 0);

    // turn on 5th LED
    select(0);
    delay(DELAY_TIME);

    // turn on 6th LED
    select(1);
    delay(DELAY_TIME);

    // turn on 7th LED
    select(2);
    delay(DELAY_TIME);

    // turn on 8th LED
    select(3);
    delay(DELAY_TIME);

    digitalWrite(LED_OUT_1, 1);
    digitalWrite(LED_OUT_2, 0);

    // turn on 1st LED
    select(0);
    delay(DELAY_TIME);

    // turn on 2nd LED
    select(1);
    delay(DELAY_TIME);

    // turn on 3rd LED
    select(2);
    delay(DELAY_TIME);

    // turn on 4th LED
    select(3);
    delay(DELAY_TIME);
  }

  return 0;
}
