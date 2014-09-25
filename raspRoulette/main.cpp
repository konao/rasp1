/*
 * [how to compile and run]
 *
 * $ make
 * $ sudo ./rou
 */
#include <stdio.h>
#include <wiringPi.h>
#include "LED.h"

int main() {
  LED led;

  for (int i=0; i<32; i++) {
    led.on(i);
    delay(100);
  }

  return 0;
}
