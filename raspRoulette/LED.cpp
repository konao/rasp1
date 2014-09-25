#include "LED.h"
#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>

#define LED_OUT_A 2
#define LED_OUT_B 3
#define LED_OUT_C 4

#define LED_OUT_1 22
#define LED_OUT_2 23
#define LED_OUT_3 24
#define LED_OUT_4 25

LED::LED() {
  _bInitOk = init();
  if (!_bInitOk) {
    fprintf(stderr, "[ERROR] LED init failed.\n");
    exit(1);
  }
}

LED::~LED() {
}

bool LED::init() {
  // GPIO setup
  if (wiringPiSetupGpio() == -1) {
    fprintf(stderr, "[ERROR] wiringPiSetupGpio() failed\n");
    return false;
  }

  // setup pin mode
  pinMode(LED_OUT_A, OUTPUT);
  pinMode(LED_OUT_B, OUTPUT);
  pinMode(LED_OUT_C, OUTPUT);
  pinMode(LED_OUT_1, OUTPUT);
  pinMode(LED_OUT_2, OUTPUT);
  pinMode(LED_OUT_3, OUTPUT);
  pinMode(LED_OUT_4, OUTPUT);

  // clear all bit
  digitalWrite(LED_OUT_A, 0);
  digitalWrite(LED_OUT_B, 0);
  digitalWrite(LED_OUT_C, 0);
  digitalWrite(LED_OUT_1, 1);
  digitalWrite(LED_OUT_2, 1);
  digitalWrite(LED_OUT_3, 1);
  digitalWrite(LED_OUT_4, 1);

  return true;
}

void LED::select1(int x) {
  int a = x & 1;
  int b = x & 2;
  int c = x & 4;
  digitalWrite(LED_OUT_A, a);
  digitalWrite(LED_OUT_B, b);
  digitalWrite(LED_OUT_C, c);
}

void LED::select2(int x) {
  int a = x & 1;
  int b = x & 2;
  int c = x & 4;
  int d = x & 8;
  digitalWrite(LED_OUT_1, a);
  digitalWrite(LED_OUT_2, b);
  digitalWrite(LED_OUT_3, c);  
  digitalWrite(LED_OUT_4, d);
}

void LED::on(int i) {
  static int _map1[] = {3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 6, 6, 6, 6, 7, 7, 7, 7, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2};
  static int _map2[] = {0x0e, 0x07, 0x0b, 0x0d, 0x0e, 0x07, 0x0b, 0x0d, 0x0e, 0x07, 0x0b, 0x0d, 0x0e, 0x07, 0x0b, 0x0d, 0x0e, 0x07, 0x0b, 0x0d, 0x0e, 0x07, 0x0b, 0x0d, 0x0e, 0x07, 0x0b, 0x0d, 0x0e, 0x07, 0x0b, 0x0d, };

  if (!_bInitOk) return;
  if (i<0 || i>31) return;

  select1(_map1[i]);
  select2(_map2[i]);
}
